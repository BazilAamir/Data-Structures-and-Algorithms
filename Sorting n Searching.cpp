#include<iostream>
#include<list>
#include<string>
#include<queue>
using namespace std;






#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int l, int mid, int r) {
    int ls = mid - l + 1;
    int rs = r - mid;

    
    int* left = new int[ls];
    int* right = new int[rs];

    
    for (int i = 0; i < ls; ++i)
        left[i] = arr[l + i];
    for (int i = 0; i < rs; ++i)
        right[i] = arr[mid + 1 + i];

    int lc = 0, rc = 0, k = l;
    while (lc < ls && rc< rs) {
        if (left[lc] <= right[rc]) {
            arr[k] = left[lc];
            lc++;
        }
        else {
            arr[k] = right[rc];
            rc++;
        }
        k++;
    }

   
    while (lc < ls) {
        arr[k] = left[lc];
        lc++;
        k++;
    }

    
    while (rc < rs) {
        arr[k] = right[rc];
        rc++;
        k++;
    }

    
    delete[] left;
    delete[] right;
}

void mergesort(int arr[], int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;

       
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);

       
        merge(arr, l, mid, r);
    }
}

int main() {

    int arr[6] = { 5, 2, 3, 4, 1, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    mergesort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}


#include <iostream>
#include <vector>
using namespace std;

class sorting{

public:

    void quicksort(vector<int>& x) {
        int size=x.size();
        int last = size - 1;
        if (size < 2) {
            return;
        }
        int pointer = -1;
        for (int i = 0;i < size;i++) {
            if (x.at(i) < x.at(last)) {

                pointer++;
                swap(x.at(i), x.at(pointer));

                

            }
            else if (x.at(i) == x.at(last)) {
                pointer++;
                swap(x.at(pointer),x.at(last));
            }
        }
        vector<int> p1;
        vector<int> p2;
        int c = 0;
        while (c < pointer) {
            p1.push_back(x.at(c));
            c++;
        }
        int j = pointer+1;
        while (j < size) {
            p2.push_back(x.at(j));
            j++;
        }
        quicksort(p1);
        quicksort(p2);

        copy(p1.begin(), p1.end(), x.begin());
        x.at(pointer) = x.at(pointer);
           copy(p2.begin(), p2.end(), x.begin() + pointer + 1);
    }
    void display(const vector<int>& x) {
        for (int i : x) {
            cout << i << " ";
        }
        cout << endl;
    }
    
      
   
};




#include <iostream>
#include <vector>
using namespace std;

class sorting {
public:
    void bubblesort(vector<int>& x) {
        int size = x.size();
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (x[j] > x[j + 1]) {
                    swap(x[j], x[j + 1]);
                }
            }
        }
    }

    void insertionsort(vector<int>& x) {
        int size = x.size();
        for (int index = 1; index < size; ++index) {
            int key = x[index];
            int i = index - 1;
            while (i >= 0 && x[i] > key) {
                x[i + 1] = x[i];
                --i;
            }
            x[i + 1] = key;
        }
    }

    void selectionsort(vector<int>& x) {
        int size = x.size();
        for (int j = 0; j < size - 1; ++j) {
            int largestIndex = 0;
            for (int i = 1; i < size - j; ++i) {
                if (x[i] > x[largestIndex]) {
                    largestIndex = i;
                }
            }
            swap(x[largestIndex], x[size - 1 - j]);
        }
    }

    int linearsearch( vector<int>& x, int key) {
        for (int i = 0; i < x.size(); ++i) {
            if (x[i] == key) {
                return i;
            }
        }
        return -1; 
    }

   
    


    int binarysearch( vector<int>& x, int key, int left, int right) {
        if (left <= right) {
            int mid = left + (right - left) / 2;
            if (x[mid] == key) {
                return mid;
            }
            else if (x[mid] < key) {
                return binarysearch(x, key, mid + 1, right);
            }
            else {
                return binarysearch(x, key, left, mid - 1);
            }
        }
        return -1; // Element not found
    }

public:
    void display(const vector<int>& x) const {
        for (int i : x) {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main() {
    vector<int> a = { 5, 3, 1, 4, 6 };
    vector<int> b = { 5, 3, 1, 4, 6 };
    vector<int> c = { 5, 3, 1, 4, 6 };
    sorting x;

    cout << "Original array: ";
    x.display(a);

    x.insertionsort(a);
    x.bubblesort(b);
    x.selectionsort(c);

    cout << "Insertion sorted: ";
    x.display(a);

    cout << "Bubble sorted: ";
    x.display(b);

    cout << "Selection sorted: ";
    x.display(c);

    // Linear search
    int linearSearchKey = 4;
    int linearSearchResult = x.linearsearch(a, linearSearchKey);
    cout << "Linear search for " << linearSearchKey << " in insertion sorted array: ";
    if (linearSearchResult != -1) {
        cout << "Found at index " << linearSearchResult << endl;
    }
    else {
        cout << "Not found" << endl;
    }

    // Binary search
    int binarySearchKey = 4;
    int binarySearchResult = x.binarysearch(a, binarySearchKey,0,a.size());
    cout << "Binary search for " << binarySearchKey << " in insertion sorted array: ";
    if (binarySearchResult != -1) {
        cout << "Found at index " << binarySearchResult << endl;
    }
    else {
        cout << "Not found" << endl;
    }

  
}





class quicksort {


public:
    quicksort() {

    }

    void quicksorter(int arr[], int left, int right) {
        if (left < right) {
            int orange = -1;
            int pivot = arr[right];
            int pass=0;
            for (int i = 0;i <= right;i++) {
                if (arr[i] <= pivot)
                {
                    orange++;
                    if (i > orange) {
                        swap(arr[i], arr[orange]);
                    }
                    pass = i;

                }

            }
            quicksorter(arr, left, pass);
            quicksorter(arr, pass + 1, right);
        };

        for (int i = 0;i < right;i++) {
            cout << arr[i] << endl;

        }


    }
};

void main() {
    quicksort a;
    int arr[10] = { 10,34,54,2,3,1,4,23,66,5};
    a.quicksorter(arr, 0, 9);
}


