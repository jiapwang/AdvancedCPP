/* This program will return the address of the element that is the maximum value in an int array*/

#include <iostream>

int *maxval (int *, int);

using namespace std;

int main()
{
    int *w;
    const int n = 20;
    int array[n];
    for (int i = 0; i < n; i ++) {
        cin >> array[i];
    }

    w = maxval(array, 20);

    if (w == NULL) {
        cout << "Invalid Array Size!";
    }
    else {
    cout << "The address to the maximum value in the array is: " << w << endl;
    cout << "The maximum value is: " << *w << endl;
    }

    return 0;
}


//This function finds the largest value in the array and passes back the memory address of that value
int *maxval (int *arr, int size) {
    int *maxad;
    int *arrptr;
    int big=0;

    arrptr = arr;

    if (size > 0) {
        arrptr = arr;
        for (int l = 0; l < size; l++) {
            if (arr[l] > big) {
                big = arr[l];
                maxad = &arr[l];
            }
        }

        return maxad;
    }

    else {
        return NULL;
    }

}
