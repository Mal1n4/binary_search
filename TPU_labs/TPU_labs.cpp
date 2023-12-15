#include <iostream>
using namespace std;

int& selection_sort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) { //go through array n-1 times
        int min = i; //set left border
        for (int j = i + 1; j < size; j++) {
            if (array[j] < array[min]) { //seeking minimum in rest part of array
                min = j;
            }
        }
        if (min != i) { //moving minimum to the left border
            swap(array[i], array[min]);
        }
    }
    return *array;
}


void binary_search(int array[], int size, int x) {
    int count = 0; //counter of accordances
    int m = size / 2; //current middle element index
    int l = 0; int r = size;
    cout << "X indices: ";
    int i;
    while (l <= r) {
        if (x == array[m]) {
            int tmp_m = m - 1;
            while ((x == array[m]) && (m < size)) { //searching accordances in the right part
                cout << m << " "; //output indices
                m++;
                count += 1;
            }
            while ((x == array[tmp_m]) && (tmp_m > 0)) { // searching accordances in the left part
                cout << tmp_m << " "; // output indices
                tmp_m--;
                count += 1;
            }
            break;
        }
        if (x < array[m]) { //shift right border and change middle
            r = m - 1;
            m = (r - l) / 2 + l;
        }
        else {
            if (x > array[m]) { //shift left border and change middle
                l = m + 1;
                m = (r - l) / 2 + l;
            }
        }
    }
    cout << endl << "Number of accordances: " << count << endl;
    if (count == 0) {
        cout << "There aren't any accordances\n";
    }
}

int main() {
    srand(time(NULL));
    int n; //size of input array
    int x; //number to seek in array S
    cout << "Enter integer N>=3 - size of array: "; cin >> n;
    int* s = new int[n]; //allocation memory 
    for (int i = 0; i < n; i++) { //filling array
        s[i] = rand() % 21; //RAND_MAX value is at least 32767
    }
    cout << "Original array: ";
    for (int i = 0; i < n; i++) { //output
        cout << s[i] << " ";
    }cout << endl;

    selection_sort(s, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) { //output
        cout << s[i] << " ";
    }cout << endl;

    cout << "Enter integer X to seek in sorted array: ";  cin >> x;
    binary_search(s, n, x);

    delete[]s;
    return 0;
}
