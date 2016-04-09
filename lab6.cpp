#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

// Declaration of the function maxArr()
int *maxArr(int *, const int);

// Another function used to print out an error message
void problem(string str) {
    cout << str << endl;
    exit(1);
    return;
}

const int Size = 10;

int main()
{
        int a[Size] = {23, 45, 12, 76, 9, 131, 10, 8, 23, 4};

        string error1("Problem with maxArr(), wrong subscript");
        string error2("Problem with maxArr(), output should be NULL");

// Call the function multiple times with different input
// Note the use of pointer arithmetic
        if (maxArr(a,Size)!= a+5)
                problem(error1);
        if (maxArr(a,Size-5)!= a+3)
                problem(error1);
        if (maxArr(a+6,4)!= a+8)
                problem(error1);
        if (maxArr(a,0) != NULL)
                problem(error2);
// The function passed all the tests

        cout << "The function passed all the tests in this program\n" << endl;
        exit(0);
}

int *maxArr(int *arr, const int size){
   int max = 0;
   int index = 0;

   if ( size <= 0) {
        return NULL;
   }

    else {
        for (int i = 0; i < size; i++) {
            if (arr[i] > max )
            {
            max = arr[i];
            index = i;
            }
        }
        return arr+index;
    }
}


/*
In the maxArr function, the passed-in array parameter needed to be a pointer. In addition, we needed an else
statement to enclose the 'for' loop and the return statement needed to be after the closing of the 'for' loop.
The return statement needs to be: return arr + index.

The first three 'if' statements are positive tests.
The last 'if' statement is a negative test.
*/



