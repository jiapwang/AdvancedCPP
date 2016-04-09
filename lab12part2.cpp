/*
Write a function template that calculates the minimum of its passed in
parameters. The MIN() function accepts two parameters and returns the
smaller of the two parameters.
*/


#include <iostream>

using namespace std;

template <class T>          //function template
T MIN ( T a, T b) {
    if (a < b)
        return a;
    return b;
}

int main()
{
    int  a=5, b=3;
    cout << "The smaller of the two integers is: " << MIN(a,b);

    double  c=4.53, d=7.65;
    cout << "\nThe smaller of the two doubles is: " << MIN(c,d);

    char  e='c', f='d';
    cout << "\nThe smaller of the two characters is: " << MIN(e,f);

    string g="There", h="Hello";
    cout << "\nThe smaller of the two is: " << MIN(g,h) << "\n";

    return 0;
}
