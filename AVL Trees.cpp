#include<iostream>
#include<list>
using namespace std;


template<typename T>
struct node
{
    int data;
    node<T>* right;
    node<T>* left;


    node()
    {
        right = NULL;
        left = NULL;
        data = 0;
    }
};


template <typename T>
class BST {

public:
    node<T>* root;
    BST() {
        root = NULL;

    }
    node<T>* rooter() {
        return root;
    }
    BST(const BST& other) {
        root = copyNode(other.root);
    }
    node<T>* copyNode(node<T>* root) {
        if (root == nullptr)
            return nullptr;

        node<T>* newNode = new node<T>();
        newNode->data = root->data;
        newNode->left = copyNode(root->left);
        newNode->right = copyNode(root->right);

        return newNode;
    }

    bool isempty() {
        if (root == NULL) {
            return true;
        }
        return false;
    }



    void insert(node<T>*& r, int n) {
        if (r == NULL) {
            r = new node<T>();
            r->data = n;
            return; 
        }

        if (n < r->data) {
            insert(r->left, n);
        }
        else if (n > r->data) {
            insert(r->right, n);
        }

        
        balancer(root);
    }

    void balancer(node<T>*& r) {
        if (r == NULL) {
            return;
        }

        balancer(r->left);
        balancer(r->right);

        int balanceFactor = getBalanceFactor(r);

       
        if (balanceFactor > 1) {
            if (getBalanceFactor(r->left) < 0) {
                
                rotateLeft(r->left);
            }
            
            rotateRight(r);
        }
        else if (balanceFactor < -1) {
            if (getBalanceFactor(r->right) > 0) {
               
                rotateRight(r->right);
            }
            
            rotateLeft(r);
        }
    }

    void rotateRight(node<T>*& r) {
        node<T>* newRoot = r->left;
        r->left = newRoot->right;
        newRoot->right = r;
        r = newRoot;
    } 

    void rotateLeft(node<T>*& r) {
        node<T>* newRoot = r->right;
        r->right = newRoot->left;
        newRoot->left = r;
        r = newRoot;
    }

    int getBalanceFactor(node<T>* r) {
        if (r == NULL) {
            return 0;
        }
        return getHeight(r->left) - getHeight(r->right);
    }

    int getHeight(node<T>* r) {
        if (r == NULL) {
            return 0;
        }
        return 1 + max(getHeight(r->left), getHeight(r->right));
    }



    void inorder(node<T>* node) {
        if (node == NULL) {
            return;
        }
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);


    }
    void postorder(node<T>* node) {
        if (node == NULL) {
            return;
        }
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    void preorder(node<T>* node) {
        if (node == NULL) {
            return;
        }
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
    void  search(node<T>* node, int x) {
        if (node == NULL) {
            return;
        }
        if (node->data == x) {
            cout << " number exists in tree" << endl;
        }
        search(node->left, x);
        search(node->right, x);


    }
    node<T>* removeNode(node<T>* root, int x) {
        if (root == NULL)
            return root;

        if (x < root->data)
            root->left = removeNode(root->left, x);
        else if (x > root->data)
            root->right = removeNode(root->right, x);
        else {
            if (root->left == NULL) {
                node<T>* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                node<T>* temp = root->left;
                delete root;
                return temp;
            }
            else {
                node<T>* temp = minValueNode(root->right);
                root->data = temp->data;
                root->right = removeNode(root->right, temp->data);
            }
        }
        balancer(root);
        return root;
    }


    node<T>* minValueNode(node<T>* root) {
        node<T>* current = root;
        while (current && current->left != NULL)
            current = current->left;
        return current;
    }

    void remove(int x) {
        root = removeNode(root, x);
    }

};




void main() {
    BST<int> a;
                                 //6
    a.insert(a.root, 6);      //3    9
    a.insert(a.root, 3);   //1   4  8  10
    a.insert(a.root, 2);
    a.insert(a.root, 1);
   
    cout << "inorder traversal: ";
    a.inorder(a.root);
    cout << endl;
    cout << "preorder traversal: ";
    a.preorder(a.root);
    cout << endl;
    cout << "postorder traversal: ";
    a.postorder(a.root);
    cout << endl;
    a.search(a.root, 3);
    a.remove(6);
    cout << "inorder traversal after 6 removed: ";
    a.inorder(a.root);
    cout << endl;
    BST<int> b = a;
    cout << "copied tree is: ";
    b.inorder(b.root);
}

