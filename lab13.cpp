/*
Write a recursive function, powr(), that raises an int to a power. The function
accept two int parameters, the number to be raised to a power and the exponent.
*/

#include <iostream>

using namespace std;

int sumFact (int);
int powr (int, int);


int main() {

	int n;
	int p;

	cout << "Please enter an integer: ";
	cin >> n;
	cout << "\n";

	cout << "Please enter an exponent to raise the previously entered integer: ";
	cin >> p;

	cout << "\n";
    cout << "Sum of " << n << " to 1: " << sumFact (n);
    cout << "\n";
    cout << n << "^" << p << ": " << powr (n, p);
    cout << "\n";

	return 0;
}


int powr ( int b, int e) {		//recursive powr function
	if (e == 0)
        return 1;

	if ( e == 1 )
        return b;

    return b*powr(b, e-1);
}

int sumFact (int n) {
    if (n == 1)
        return 1;
    else if (n <= 0)
        return 0;
    else
        return n+sumFact(n-1);
}
