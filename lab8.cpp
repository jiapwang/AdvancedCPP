/*Design a class NumDays that has two integer member variables representing
the number of hours and days that a person has worked. A day is defined to
be 8 hours. The class has one private member function that checks
that the number of hours is not over 8. If it is, the function should convert
the hours to days and hours. If the number of days and hours worked is entered
as 2 days and 12 hours, the private member function should convert this to
3 days and 4 hours. In addition, the class has an addition operator +, prefix
and postfix increment and decrement operators (++,--).*/

#include <iostream>

using namespace std;

class NumDays {                //class NumDays
    private:
        int numhr;
        int numdays;
        void simplify () {
            if (numhr > 8) {
                numdays += numhr/8;
                numhr = numhr % 8;
            }
            };

    public:
        NumDays(){
        numhr = 0;
        numdays = 0;
        };
        NumDays(int a, int b){
        numdays = a;
        numhr = b;
        simplify();
        };
        void changeHr(int);
        void changeDay(int);
        int getHr ();
        int getDay ();
        NumDays operator+ (const NumDays &) const;
        NumDays operator++ ();
        NumDays operator++ (int);
        NumDays operator-- ();
        NumDays operator-- (int);
        friend ostream &operator << (ostream &, NumDays &);

};

void NumDays::changeHr (int hr) {           //mutator function to change the numhr variable
    numhr = hr;
    simplify();
}

void NumDays::changeDay (int day) {         //mutator function to change the numdays variable
    numdays = day;
}

int NumDays::getHr() {          //accessor function that returns numhr (numbers of hours worked)
    return numhr;
}

int NumDays::getDay() {         //accessor function that returns numdays (days worked)
    return numdays;
}

NumDays NumDays::operator+ (const NumDays &obj) const {         //overloaded + operator
    NumDays temp;
    temp.numhr = numhr + obj.numhr;
    temp.numdays = numdays + obj.numdays;
    return temp;
}

NumDays NumDays::operator++() {             //overloaded prefix ++ operator
    ++numhr;
    simplify();
    return *this;
}

NumDays NumDays::operator++(int) {          //overloaded postfix ++ operator
    NumDays temp(numdays,numhr);

    numhr++;
    simplify();
    return temp;
}

NumDays NumDays::operator--() {         //overloaded prefix -- operator
    --numhr;
    simplify();
    return *this;
}

NumDays NumDays::operator--(int) {          //overloaded postfix -- operator
    NumDays temp (numdays, numhr);

    numhr--;
    simplify();
    return temp;
}

int main()
{
    NumDays a;
    NumDays b(5,2);
    NumDays c;

    a.changeDay(3);
    a.changeHr(9);

    cout << "a has worked " << a.getDay() << " days and " << a.getHr() << " hours." << endl;
    cout << "b has worked " << b.getDay() << " days and " << b.getHr() << " hours." << endl;

    c = a+b;
    cout << "c is currently a+b, c has worked " << c.getDay() << " days and " << c.getHr() << " hours." << endl;

    c = ++a;
    cout << "c = ++a, c has worked " << c.getDay() << " days and " << c.getHr() << " hours." << endl;

    c=a--;
    cout << "c = a--, c has worked " << c.getDay() << " days and " << c.getHr() << " hours." << endl;

    c = a++;
    cout << "c= a++, c has worked " << c.getDay() << " days and " << c.getHr() << " hours." << endl;

    c=--a;
    cout << "c = --a, c has worked " << c.getDay() << " days and " << c.getHr() << " hours." << endl;


    return 0;
}
