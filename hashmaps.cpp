#include<iostream>
#include<list>
#include<string>

using namespace std;



struct hasher {

	string user, password;
	hasher() {
		user = "";
		password = "";
	}

};

template<typename T>
class hashtable {
private:

	list<hasher> arr[11];



public:
	hashtable() {


	}
	void insert(string us, string pass) {
		typename list<hasher>::iterator it;
		int i = hashfunction(us);
		it = arr[i].begin();
		for (it = arr[i].begin();it != arr[i].end();it++) {
			if (us == it->user)
			{
				cout << "the user already exists"<<endl;
				return;
			}
		}
		T temp;
		temp.user = us;
		temp.password = pass;
		arr[i].push_back(temp);
		cout << "user and pass registered succesfully" << endl;



	}
	void search(string us, string pass) {
		typename list<hasher>::iterator it;
		int i = hashfunction(us);
		it = arr[i].begin();
		for (it = arr[i].begin();it != arr[i].end();it++) {
			if (us == it->user) {
				if (pass == it->password) {
					cout << "u have succesfully logged in" << endl;
					return;
				}
			}
		}
		cout << "enter correct username and password" << endl;

	}
	
	void display() {
		typename list<hasher>::iterator it;
		cout << "all registered users: " << endl;
		for (int i = 0;i < 11;i++) {
			it = arr[i].begin();
			for (it = arr[i].begin();it != arr[i].end();it++) {
				cout << "user " << it->user << endl;
			}
		}
	}
	int hashfunction(string data) {
		int size = data.size();
		char x;
		int algo = 0;
		for (int i = 0;i < size;i++) {
			x = data[i];
			algo = algo + (static_cast<int>(x) * i);
		}
		algo = algo % 11;
		return algo;
	}


};





void main() {
	string username, password;
	hashtable <hasher> q;
	q.insert("bazil", "1234");
	cout << "enter details of user to register :" << endl;
	cout << " username: "<<endl;
	cin >> username;
	cout << "password :"<<endl;
	cin >> password;
	
	q.insert(username,password);
	cout << " enter details to login " << endl;
	cout << "username: ";
	cin >> username;
	cout << "password: " << endl;
	cin >> password;
	q.search(username, password);
	q.display();

}


