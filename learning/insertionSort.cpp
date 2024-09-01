#include <algorithm>
#include <iostream>
using namespace std;

static void insertionSort(int a[], int n);

int main(int argc, char const *argv[]) {
    int a[] = {5, 3, 2, 8, 1, 7, 4};
    int size = sizeof(a) / sizeof(a[0]);
    
    insertionSort(a, size);

    for (int i = 0; i < size; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

static void insertionSort(int a[], int n) {
    if (n > 1) {
        insertionSort(a, n - 1);
        for (int i = n - 1; i > 0; i--) {
            if (a[i - 1] > a[i]) {
                swap(a[i - 1], a[i]);
                // Print the array after each swap
                for (int j = 0; j < n; j++) {
                    cout << a[j] << " ";
                }
                cout << endl;
            }
            else
                break;
        }
    }
}
