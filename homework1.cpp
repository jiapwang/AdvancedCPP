//Sort up to 20 double values read from an external file

#include <iostream>
#include <fstream>

using namespace std;

void bubblesort(double [], int);
void printer (double [], int);

int main()
{
    int n;

    ifstream outputfile;
    outputfile.open("data.txt");                //open external file

    if (!outputfile){                           //if file does not exist, display error message
        cout << "File can not be found!" << endl;
    }

    cout << "How many values are there in the file? (Input a number between 0 and 20) " << endl;
    cin >> n;

    while (n > 20 || n < 0) {                   //checks that n is not greater than 20 or less than 0
        cout << "This program was not made for such request, enter another value between 0 and 20.";
        cin >>n;
        }

    cout << endl;

    double array[n], numb;                      //declaration of array and numb


    for (int cnt = 0; cnt < n; cnt ++) {            //loop for setting the values of the array
        outputfile >> numb;
        array[cnt] = numb;
    }

    cout << "This is the initial table: " << endl;
    printer(array,n);
    cout << endl;

    bubblesort(array, n);                       //call array sorting function
    cout << "This is the sorted table: " << endl;
    printer(array,n);                           //print sorted array

    return 0;

}



void bubblesort(double a[], int b)              //function that sorts the array from largest to smallest
{
    double temp;
    for (int loop=0;loop<b-1;loop++) {
        for ( int i=0;i<b-1;i++) {
            if (a[i] < a[i+1]) {
                temp = a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }
    }
    return;
}


void printer (double array[], int b)
{
    for (int cnt = 0; cnt < b; cnt++){          //print initial array
        cout << cnt+1 << "\t" << array[cnt] << endl;
    }
return;
}

