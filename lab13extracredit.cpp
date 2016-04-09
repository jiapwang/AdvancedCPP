#include <iostream>

using namespace std;
int Ackerman (int, int);

int main()
{
    int m;
    int n;

    cin >> m;
    cin >> n;

    cout << Ackerman(m,n);

    return 0;
}

int Ackerman ( int m, int n) {
    if (m == 0)
        return n+1;
    else if (n == 0)
        return Ackerman(m-1,1);
    else return Ackerman(m-1, Ackerman(m,n-1));
}
