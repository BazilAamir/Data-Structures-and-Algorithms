#include<iostream>
using namespace std;



template<typename T>
class Linkedlist {
    node<T>* head;

public:
    Linkedlist() {
        head = nullptr;
    }

    Linkedlist(const Linkedlist& other) {
        head = nullptr;
        node<T>* temp = other.head;
        while (temp != nullptr) {
            insertstart(temp->content);
            temp = temp->next;
        }
    }

    void insertstart(const T& cont) {
        node<T>* temp = new node<T>();
        temp->content = cont;
        if (head == nullptr) {
            head = temp;
        }
        else {
            temp->next = head;
            head = temp;
        }
    }

    void delstartnode() {
        if (head != nullptr) {
            node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void traverse() {
        cout << "the linkedlist is " << endl;
        node<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->content << endl;
            temp = temp->next;
        }
    }

    void insertend(const T& x) {
        if (head == nullptr) {
            insertstart(x);
            return;
        }

        node<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        node<T>* newNode = new node<T>();
        newNode->content = x;
        temp->next = newNode;
    }

    void delend() {
        if (head == nullptr)
            return;
        node<T>* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    void DAAP(int pos) {
        if (head == nullptr || pos <= 0)
            return;

        if (pos == 1) {
            delstartnode();
            return;
        }

        int c = 1;
        node<T>* temp = head;
        while (temp != nullptr) {
            if (c == pos - 1) {
                node<T>* temp2 = temp->next;
                temp->next = temp->next->next;
                delete temp2;
                return;
            }
            c++;
            temp = temp->next;
        }
    }

    void IAAP(const T& val, int pos) {
        if (pos <= 0)
            return;

        if (pos == 1) {
            insertstart(val);
            return;
        }

        int c = 1;
        node<T>* temp = head;
        while (temp != nullptr) {
            if (c == pos - 1) {
                node<T>* temp2 = new node<T>();
                temp2->content = val;
                temp2->next = temp->next;
                temp->next = temp2;
                return;
            }
            c++;
            temp = temp->next;
        }
    }

    ~Linkedlist() {
        node<T>* current = head;
        while (current != nullptr) {
            node<T>* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }
};

int main() {
    Linkedlist<int> a;
    a.insertstart(2);
    a.insertstart(3);
    a.delstartnode();
    a.insertend(4);
    a.traverse();
    a.delend();
    a.traverse();
    Linkedlist<int> b = a;
    b.insertstart(3);
    b.insertstart(4);
    b.insertstart(5);
    b.traverse();
    b.IAAP(4, 2);
    b.traverse();
    b.DAAP(1);
    b.traverse();

    return 0;
}








template<typename T>
struct node {
    T content;
    node<T>* next;

    node() {
        next = nullptr;
    }
};

template<typename T>
class cll {
	node<T>* last;

public:

	cll() {
		last=NULL;
	}
	bool isempty() {
		return last == NULL ? true : false;
	}
    cll(cll& a) {
        if (last = NULL) {
            cout << "empy list cant be copied";

        }

        else {
            last= a.last;
            node<T>* tempcopy = a.last->next;
            node<T>* temp = last->next;
            do {
                temp->content = tempcopy->content;
                temp = temp->next;
                tempcopy = tempcopy->next;

            } while (temp != a.last->next);
        }
    }
    ~cll() {
        node<T>* temp = last->next;
        
        node<T>* temp2;
        while (temp != last) {
            temp2 = temp->next;
            delete temp;
            temp = temp2;

        } 
        delete last;
        last = NULL;
    }


	void IAS(int d) {
		node<T>* n = new node<T>;
		n->content = d;

		if (isempty()) {
			last = n;
			last->next = n;
			

		}
		else{
			n->next = last->next;
			last->next = n;
		}

	}
    void IAE(int d) {
        node<T>* n = new node<T>;
        n->content = d;

        if (isempty()) {
            last = n;
            last->next = n;


        }
        else {
            n->next = last->next;
            last->next = n;
            last = n;
        }

    }
	void DAS() {
		node<T>* temp = new node<T>;
		temp = last->next;
		last->next = temp->next;
		delete temp;
	}
	void traverse() {
		node<T>* temp = last->next;
		do {
			cout << temp->content;
			temp = temp->next;
		} while (temp != last->next);
	}
    void IAAP(T a, int pos) {
        int c = 1;
        node<T>* temp = last->next;
        do {
            if (c == pos - 1) {
                node<T>* temp2 = new node<T>;
                temp2->content = a;
                temp2->next = temp->next;
                temp->next = temp2;
                break;
            }
            else {
                temp = temp->next;
                c++;
            }
        } while (temp != last->next);

    }
    void delAAP(int pos) {
        if (!isempty()) {
            int c = 1;
            node<T>* temp = last->next;
            do {
                if (c == pos - 1) {
                    node<T>* replace = temp->next;
                    temp->next = replace->next;
                    delete replace;
                    break;
                }
                else {
                    temp = temp->next;
                    c++;
                }
            } while (temp != last->next);
        }
    }

    void DAE() {
        if (isempty()) {

        }
        else if (last->next = last) {
            last = NULL;
        }
        else{
          node* temp = last->next;
            do {
                temp = temp->next;
            } while (temp->next != last);
            temp->next = last->next;

            delete last;
            last = temp;
        }


    }
    template<typename T>
    friend ostream& operator<<(ostream& c, cll<T> a);
}; 
template< typename T>
ostream& operator<<(ostream& c, cll<T> a) {
    a.traverse();
    return c;
}
int  main() {
	cll<int> a;
	a.IAS(5);
	a.IAS(4);
    a.IAS(3);
    a.IAS(2);
    a.IAS(1);
	a.DAS();
    a.IAE(4);
	a.traverse();
    cout << endl;
    a.IAAP(5, 3);
    cout << a << endl;
    a.delAAP(2);
    cout << a;
	return 0;
}