#include<iostream>
#include<queue>
#include<list>


using namespace std;

template <typename T>
class mylist :public list<T> {
public:
	void display() {
		list<int>::iterator it;
		for (it = this->begin();it != this->end();it++) {
			cout << *it;

		}
		cout << endl;

	}
	bool compare(list <T> x) {
		if (this->size() == x.size()) {
			list<int>::iterator it = this->begin();
			list<int>::iterator it2 = x.begin();
			while (it != this->end()) {
				if (*it != *it2) {
					return false;
				}
				it++;
				it2++;
			}
			return true;

		}
		return false;

	}

	void reverselist(int a, int b) {
		list<int>::iterator it;
		list<int>::iterator alpha;
		list<int>::iterator beta;
		int count = 0;
		int temp;
		for (it = this->begin();it != this->end();it++) {
			if (*it == a) {
				alpha = it;
			}
			else if (*it == b) {
				beta = it;
			}
		}
		for (it = alpha;it != beta;it++) {
			
			count++;
		}
		
		count++;
		if (count % 2 == 1) {
			for (int i = 0;i < (count - 1) / 2;i++) {
				temp = *alpha;
				*alpha = *beta;
				*beta = temp;
				alpha++;
				beta--;
			}
		}
		else {
			for (int i = 0;i < (count) / 2;i++) {
				temp = *alpha;
				*alpha = *beta;
				*beta = temp;
				alpha++;
				beta--;
			}

		}



	}
	void deletedup() {
		typename list<T>::iterator it, temp;
		for (it = this->begin(); it != this->end(); ) {
			T x = *it;
			bool erased = false;
			for (temp = next(it); temp != this->end(); ) {
				if (*temp == x) {
					temp = this->erase(temp);
					erased = true;
				}
				else {
					temp++;
				}
			}
			if (erased) {
				it = this->erase(it);
			}
			else {
				it++;
			}
		}
		this->sort();
	}

	void swapper() {
		list<int>::iterator it;
		
		int temp;
		int count = 0;
		for (it = this->begin();it != this->end();it++) {
			count++;
		}
		it = this->begin();
		if (count % 2 == 0){
			for (int i = 0;i < count;i=i+2) {
				temp = *it;
				*it = *(next(it));
				*(next(it)) = temp;
				it++;
				it++;

			}
		}
		else
		{
			for (int i = 0;i < count-2;i=i + 2) {
				temp = *it;
				*it = *(next(it));
				*(next(it)) = temp;
				it++;
				it++;

			}

		}
		
		
		
		
	}

	
};

void main() {
	mylist<int> list1;
	list<int>::iterator iter =list1.begin();
	list1.push_back(1);
	list1.push_back(2);
	list1.push_back(3);
	list1.push_back(4);
	list1.push_back(5);
	list1.push_back(6);
	list<int>::iterator it;
	it = list1.begin();
	
	mylist<int> list2;
	list2.push_back(4);
	list2.push_back(3);
	list2.push_back(4);
	list2.push_back(6);
	list2.push_front(2);
	cout << endl;

	list1.display();
	list1.reverselist(2, 5);
	cout << "reversing the list between 2 and 5:" << endl;
	list1.display();

	list1.deletedup();
	cout << "deleting duplicates and sorting the list:" << endl;
	list1.display();
	list1.push_back(3);
	list1.push_back(4);
	list1.display();
	cout << "adding 3 and 4 into the list and swapping" << endl;
	list1.swapper();
	list1.display();
	



}


template <typename T>
class greycode :public list<T> {
private:
	list<T> lister;
public:
	void display() {
		list<int>::iterator it;
		cout << " The greycode  is :";
		cout << "( ";
		for (it = lister.begin();it != lister.end();it++) {
			cout << *it;
			if (it != prev(lister.end())) {
				cout << ",";
			}
			else cout << ")";

		}
		cout << endl;

	}
	void createlist(int x) {
		int temp;
		int count=0;
		int counter = -1;
		for (int i =0;i <=(pow(2,x)) - 1;i++) {
			lister.push_back(i);

		}
		list<int>::iterator it;
		it = lister.begin();
		it++;
		it++;
		temp = *it;
		*it = *(next(it));
		*(next(it)) = temp;
		list<int>::iterator iter;
		it++;
		for (iter = it;iter != lister.end();iter++) {
			if (count == 3) {
				temp = *iter;
				*iter = *(next(iter));
				*(next(iter)) = temp;
				count = 0;
			}
			else count++;

		}



	}




};
void main() {
	greycode<int> a;
	a.createlist(4);
	a.display();
}

template<typename T>
class palindrome :public list<T> {
private: list<T> lister;
	   string x;
public:

	void display() {
		list<string>::iterator it;
		cout << " The palindrome set is :";
		cout << "( ";
		for (it = lister.begin();it != lister.end();it++) {
			cout << *it;
			if (it != prev(lister.end())) {
				cout << ",";
			}
			else cout << ")";

		}
		cout << endl;
	}

	void pal(string x) {
		string str="";
		int left = 0;
		int right = 0;
		for (int i = 0;i < x.size();i++) {
			left = i;
			right = i;
			while (x[left] == x[right]) {
				for (int i = left;i <= right;i++) {
					str = str + x[i];
				}
				lister.push_back(str);
				str = "";
				if (left != 0 && right != x.size() - 1) {
					left--;
					right++;
				}
				else break;
			}
		}
		for (int i = 0;i < x.size();i++) {
			left = i;
			right = i+1;
			while (x[left] == x[right]) {
				for (int i = left;i <= right;i++) {
					str = str + x[i];
				}
				lister.push_back(str);
				str = "";
				if (left != 0 && right != x.size() - 1) {
					left--;
					right++;
				}
				else break;
			}
		}

	}


};
void main() {
	palindrome<string> x;
	x.pal("abaa");
	x.display();
}






