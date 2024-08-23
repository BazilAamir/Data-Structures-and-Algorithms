#include<iostream>
using namespace std;
template<typename T>
struct node
{
    int data;
    node<T>* next;

    node()
    {
        next = NULL;
        data = 0;
    }
};


template<typename T>
class stack {
private:
    int  front;
    static const int size=5;
    T arr[size] = {};
   
public:
    stack() {
        front = 0;
        
    }
    void push(char x) {
        if (front!= size) {
            arr[front] = x;
            front++;

            

        }
        else cout << "full";


    }
   void  pop() {
        if(front != 0) {
            arr[front-1] = NULL;
            front--;

        }
        else cout << "empty";
    }

    void gettop() {
        if (front != 0) {
            cout << "top element is " << arr[front-1] << endl;
        }
    }
    int isempty() {
        if (front == 0) {
            return 1;
        }
        return 0;
    }
    void display() {
        for (int i = size-1;i >=0;i--)
        {
            cout << arr[i] << endl;
        }
    }

};
void main() {
    stack<char> x;
    x.push('a');
    x.push('b');
    x.push('c');
    x.display();
    x.pop();
    x.pop();
    cout << "stack after two elemnts popped" << endl;
    x.display();
    cout << "is stack empty" << endl;
    cout<<x.isempty()<<endl;
   
    x.gettop();

}

template<typename T>
struct node
{
    T data;
    node<T>* next;

    node()
    {
        next = NULL;
        data = 0;
    }
};

template<typename T>
class stack {
private:
    node<T>* top;
public:
    stack() {
        top = NULL;
    }

   void push(int x) {
        node<T>* temp = new node<T>;
        temp->data = x;
        if (top == NULL) {
            top = temp;
       }
        else {
            temp->next = top;
            top = temp;

        }
    }
    void pop() {
        if (top != NULL) {
            node<T>* temp = top;
            top = top->next;
            delete temp;

        }
       
    }
    void display() {
        node<T>* temp = top;
        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;

        }
    }
    int isempty() {
        if (top != NULL) {
            return 0;
        }
        return 1;
    }
    void gettop() {
        if (top != NULL) {
            cout << "top of stack is " << top->data << endl;
        }
    }
    stack(stack& x) {

        top = new node<T>;
        top->data = x.top->data;
        node<T>* temp = top;
        node<T>* temp2 = x.top->next;
        while (temp2 != NULL) {
            node<T>* tempx = new node<T>;
            tempx->data = temp2->data;
            tempx->next = top->next;
            top->next = tempx;
            temp2 = temp2->next;


        }

    }
    ~stack() {
        while (top != NULL) {
            node<T>* temp = top;
            top = top->next;
            delete temp;

        }
        top = NULL;
    }


};
void main() {
    stack<int> x;
    x.push(4);
    x.push(3);
    x.push(5);
    x.display();


    x.pop();
    cout << "stack ater pop" << endl;
    x.display();
    stack<int> y = x;
    cout << "copied stack" << endl;
    y.display();

}

template<typename T>
struct node {
    T content;
    node<T>* next;
    node() {
        content = 0;
        next = NULL;
    }
};
template<typename T>
class Linkedlist {
    protected:
    node<T>* head;

public:
    Linkedlist() {
        head = nullptr;
    }

    Linkedlist(const Linkedlist& other) {
        head = nullptr;
        node<T>* temp = other.head;
        while (temp != nullptr) {
            insertend(temp->content);
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
    void returns() {
        if (head != NULL) {
            cout << head->content;
        }
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
    int isempty() {
        return (head == NULL);
    }
   
};


template<typename T>
class stack {
private:
    Linkedlist<T> x;

public:
    stack() {

    }
    void push(int k) {
        x.insertstart(k);
    }
    void pop() {
        x.delstartnode();
    }
    void returntop() {
        x.returns();
    }
    int empty() {
        return x.isempty();
    }
    void dis() {
        x.traverse();

    }
    

    
    

};
void main() {
    stack<int> x;
    x.push(3);
    x.push(4);
    x.push(5);
    x.push(6);
    x.dis();
    cout << "top after pop is" << endl;
    x.returntop();
    cout << endl;
    cout << "is stack empty" << endl;
    cout << x.empty() << endl;
    x.dis();
    stack<int> y = x;
    cout << "copied stack is " << endl;
    y.dis();

}
