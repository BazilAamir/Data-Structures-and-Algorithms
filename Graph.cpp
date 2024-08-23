#include<iostream>

using namespace std;

class graph {
    private:
    	int matrix[5][5];
    	char vertice[5];
    	static int count;
    
    public:
    	graph() {
    		matrix[5][5] = {};
    		vertice[5] = {};
    	}
    	void initialm() {
    		for (int i = 0;i < 5;i++) {
    			for (int j = 0;j < 5;i++) {
    				matrix[i][j] = 0;
    			}
    
    		}
    	}
    	void insertv (char v) {
    		if (count < 5) {
    			vertice[count] = v;
    			count++;
    		}
    	}
    	void insertedge(char x,char y) {
    		int xindex, yindex;
    		for (int i = 0;i < 5;i++) {
    			if (vertice[i] == x) {
    				xindex = i;
    			}
    			if (vertice[i] == y) {
    				yindex = i;
    			}
    		}
    
    		matrix[xindex][yindex] = 1;
    		matrix[yindex][xindex] = 1;
    
    	}
    	void delv(char x) {
    		int deli=0;
    		for (int i = 0;i < 5;i++) {
    			if (vertice[i] == x) {
    				vertice[i] = vertice[count - 1];
    				count--;
    				 deli = i;
    			}
    
    			for(int i = 0;i < 5;i++){
    				matrix[deli][i] = 0;
    
    			}
    			for (int i = 0;i < 5;i++) {
    				matrix[i][deli] = 0;
    
    			}
    			for (int i = 0;i < 5;i++) {
    				matrix[deli][i] = matrix[count-1][i];
    
    			}
    			for (int i = 0;i < 5;i++) {
    				matrix[i][deli] = matrix[count-1][i];
    
    			}
    
    			for (int i = 0;i < 5;i++) {
    				 matrix[count - 1][i]=0;
    
    			}
    			for (int i = 0;i < 5;i++) {
    				 matrix[count - 1][i]=0;
    
    			}
    
    
    		}
    
    	}
    	void deledge(char x, char y) {
    		int xindex, yindex;
    		for (int i = 0;i < 5;i++) {
    			if (vertice[i] == x) {
    				xindex = i;
    			}
    			if (vertice[i] == y) {
    				yindex = i;
    			}
    		}
    		matrix[xindex][yindex] = 0;
    		matrix[yindex][xindex] = 0;
    
    	}
    	void verticer() {
    		cout << "vertices are " << count<<endl;
    	}
    	void edges() {
    		int edge=0;
    		for (int i = 0;i < 5;i++) {
    			for (int j = 0;j <i ;j++) {
    				if (matrix[i][j] == 1) {
    					edge++;
    				}
    			}
    
    		}
    		cout << "edges are " << edge<<endl;
    	}
    	void ifedge(char x, char y) {
    		int xindex, yindex;
    		for (int i = 0;i < 5;i++) {
    			if (vertice[i] == x) {
    				xindex = i;
    			}
    			if (vertice[i] == y) {
    				yindex = i;
    			}
    		}
    		if (matrix[xindex][yindex] == 1)
    		{
    			cout << "edge exists" << endl;
    		}
    		else cout << "edge does not exist" << endl;
    	}
    	bool ifvert(char x) {
    		for (int i = 0;i < 5;i++) {
    			if (vertice[i] == x) {
    				return true;
    
    			}
    		}
    		return false;
    
    	}
    
    
    
    
    };
    
    int graph::count = 0;
    void main() {
    	graph a;
    	a.insertv('A');
    	a.insertv('B');
    	a.insertv('C');
    	a.insertv('D');
    	a.insertv('E');
    	a.insertedge('A', 'B');
    	a.insertedge('C', 'D');
    	a.edges();
    	a.ifedge('C', 'D');
    	a.deledge('A', 'B');
    	a.ifedge('A', 'B');
    	a.edges();
    	cout << "does vertice A exist or not (1=yes, 0=NO)" << endl;
    	cout << a.ifvert('A') << endl;
    }
    
    
    
    
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

    using namespace std;

    struct Edge {
        char dest;
        int weight;
    };

    struct node {
        char data;
        vector<Edge> adj;  // adjacency list with weights
        bool visit;

        node() {
            data = ' ';
            visit = false;
        }
    };

    class listedgraph {
    private:
        vector<node> vertices;
    public:
        void insertv(char x) {
            node newer;
            newer.data = x;
            vertices.push_back(newer);
        }

        void insertedge(char a, char b, int weight) {
            for (int i = 0; i < vertices.size(); i++) {
                if (vertices[i].data == a) {
                    Edge edge = { b, weight };
                    vertices[i].adj.push_back(edge);
                }
                else if (vertices[i].data == b) {
                    Edge edge = { a, weight };
                    vertices[i].adj.push_back(edge);
                }
            }
        }

        void deledge(char a, char b) {
            for (int i = 0; i < vertices.size(); i++) {
                if (vertices[i].data == a) {
                    for (int j = 0; j < vertices[i].adj.size(); j++) {
                        if (vertices[i].adj[j].dest == b) {
                            vertices[i].adj.erase(vertices[i].adj.begin() + j);
                            break;
                        }
                    }
                }
                else if (vertices[i].data == b) {
                    for (int j = 0; j < vertices[i].adj.size(); j++) {
                        if (vertices[i].adj[j].dest == a) {
                            vertices[i].adj.erase(vertices[i].adj.begin() + j);
                            break;
                        }
                    }
                }
            }
        }

        void delvertice(char a) {
            for (int i = 0; i < vertices.size(); i++) {
                if (vertices[i].data == a) {
                    vertices.erase(vertices.begin() + i);
                    break;
                }
            }
            for (int i = 0; i < vertices.size(); i++) {
                deledge(a, vertices[i].data);
            }
        }

        void ifedge(char a, char b) {
            for (int i = 0; i < vertices.size(); i++) {
                if (vertices[i].data == a || vertices[i].data == b) {
                    for (int j = 0; j < vertices[i].adj.size(); j++) {
                        if ((vertices[i].adj[j].dest == b && vertices[i].data == a) ||
                            (vertices[i].adj[j].dest == a && vertices[i].data == b)) {
                            cout << "Edge exists between " << a << " and " << b << endl;
                            return;
                        }
                    }
                }
            }
            cout << "There exists no edge between " << a << " and " << b << endl;
        }

        void ifvertice(char a) {
            for (int i = 0; i < vertices.size(); i++) {
                if (vertices[i].data == a) {
                    cout << "Vertice " << a << " exists" << endl;
                    return;
                }
            }
            cout << "Vertice " << a << " does not exist" << endl;
        }

        int countVertices() {
            return vertices.size();
        }

        int countEdges() {
            int edgeCount = 0;
            for (int i = 0; i < vertices.size(); i++) {
                edgeCount += vertices[i].adj.size();
            }
            return edgeCount / 2;
        }

        void dfsUtil(char v) {
            for (int i = 0; i < vertices.size(); i++) {
                if (vertices[i].data == v && !vertices[i].visit) {
                    cout << v << " ";
                    vertices[i].visit = true;
                    for (int j = 0; j < vertices[i].adj.size(); j++) {
                        dfsUtil(vertices[i].adj[j].dest);
                    }
                }
            }
        }

        void dfs(char start) {
            for (int i = 0; i < vertices.size(); i++) {
                vertices[i].visit = false;
            }

            cout << "DFS traversal starting from vertex " << start << ": ";
            dfsUtil(start);
            cout << endl;
        }

        void bfs(char start) {
            for (int i = 0; i < vertices.size(); i++) {
                vertices[i].visit = false;
            }

            cout << "BFS traversal starting from vertex " << start << ": ";
            queue<char> q;
            q.push(start);
            for (int i = 0; i < vertices.size(); i++) {
                if (vertices[i].data == start) {
                    vertices[i].visit = true;
                    break;
                }
            }

            while (!q.empty()) {
                char v = q.front();
                cout << v << " ";
                q.pop();
                for (int i = 0; i < vertices.size(); i++) {
                    if (vertices[i].data == v) {
                        for (int j = 0; j < vertices[i].adj.size(); j++) {
                            char u = vertices[i].adj[j].dest;
                            for (int k = 0; k < vertices.size(); k++) {
                                if (vertices[k].data == u && !vertices[k].visit) {
                                    q.push(u);
                                    vertices[k].visit = true;
                                    break;
                                }
                            }
                        }
                        break;
                    }
                }
            }
            cout << endl;
        }

        void dijkstra(char start) {
            int n = vertices.size();
            vector<int> distances(n, INT_MAX);
            vector<bool> visited(n, false);
            vector<char> previous(n, ' ');

            int startIndex = -1;
            for (int i = 0; i < n; i++) {
                if (vertices[i].data == start) {
                    startIndex = i;
                    break;
                }
            }
            if (startIndex == -1) return;

            distances[startIndex] = 0;

            for (int i = 0; i < n; i++) {
                int minDistance = INT_MAX;
                int u = -1;
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && distances[j] < minDistance) {
                        minDistance = distances[j];
                        u = j;
                    }
                }

                if (u == -1) break;

                visited[u] = true;

                for (int k = 0; k < vertices[u].adj.size(); k++) {
                    char neighbor = vertices[u].adj[k].dest;
                    int weight = vertices[u].adj[k].weight;
                    int v = -1;
                    for (int j = 0; j < n; j++) {
                        if (vertices[j].data == neighbor) {
                            v = j;
                            break;
                        }
                    }

                    if (!visited[v] && distances[u] + weight < distances[v]) {
                        distances[v] = distances[u] + weight;
                        previous[v] = vertices[u].data;
                    }
                }
            }

            cout << "Shortest distances from vertex " << start << ":\n";
            for (int i = 0; i < n; i++) {
                cout << vertices[i].data << " : " << distances[i] << endl;
            }
        }
    };
   
    int main() {
        listedgraph c;
        c.insertv('a');
        c.insertv('b');
        c.insertv('c');
        c.insertv('d');
        c.insertv('e');
        c.insertedge('a', 'b', 1);
        c.insertedge('a', 'e', 4);
        c.insertedge('b', 'e', 2);
        c.insertedge('b', 'c', 3);
        c.insertedge('c', 'd', 1);
        c.insertedge('d', 'e', 5);
        c.bfs('a');
        c.dfs('a');
    
        cout << "Vertices count: " << c.countVertices() << endl;
        cout << "Edges count: " << c.countEdges() << endl;
    
        c.deledge('a', 'b');
        c.deledge('c', 'd');
        c.ifedge('a', 'b');
        cout << "Vertices count: " << c.countVertices() << endl;
        cout << "Edges count: " << c.countEdges() << endl;
    
        c.dijkstra('a');
    
        return 0;
    }