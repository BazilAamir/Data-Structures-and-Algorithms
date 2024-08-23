#include<iostream>
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
    }



    void inorder( node<T>* node) {
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
    void  search(node<T>* node,int x) {
        if (node == NULL) {
            return;
        }
        if (node->data == x) {
            cout << " number exists in tree" << endl;
        }
        search(node->left,x);
        search(node->right,x);


    }
    node<T>* removeNode(node<T>* root, int x) {
        if (root == NULL)
            return root;

        if (x < root->data)
            root->left = removeNode(root->left, x);
        else if (x > root->data)
            root->right = removeNode(root->right, x);
        else {
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }
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
                                 6
    a.insert(a.root, 6);      //3    9
    a.insert(a.root, 3);   //1   4  8  10
    a.insert(a.root, 9);
    a.insert(a.root, 1);
    a.insert(a.root, 4);
    a.insert(a.root, 8);
    a.insert(a.root, 10);

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

#include <iostream>
using namespace std;

template<typename T>
class heap {
private:
    T arr[100];
    int size = -1;
public:
    heap() {}

    bool isempty() {
        return size == -1;
    }

    T gettop() {
        return arr[0];
    }

    void insert(T val) {
        size = size + 1;
        int index = size;
        arr[index] = val;
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
                return;
        }
    }
   

    void deleter() {
        if (size == 0) {
            cout << "nothing to delete " << endl;
            return;
        }
        arr[0] = arr[size];
        size--;
        int i = 0;
        while (i < size) {
            int leftIndex = 2 * i + 1;
            int rightIndex = 2 * i + 2;
            if (leftIndex < size && arr[i] < arr[leftIndex]) {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[i] < arr[rightIndex]) {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else {
                return;
            }
        }
    }

    void display() {
        for (int i = 0; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    heap<int> a;
    a.insert(50);
    a.insert(55);
    a.insert(53);
    a.insert(52);
    a.insert(54);
    a.display();
    a.deleter();
    a.display();
    return 0;
}

