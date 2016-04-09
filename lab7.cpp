//Use the class 'TestScore' in a program that calculates the average quiz grade for each student of an array of 3 students

#include <iostream>

using namespace std;

class TestScore {              //TestScore class
    private:
        static int num;
        string name;
        double *pquiz;
        double average;
    public:
        TestScore ();
        TestScore (TestScore &);
        ~TestScore ();
        double averagegrade ();
        void setName(string);
        string getName ();
        void setGrades(int, double);
        static void stuGrades(int);
        int getNum();
};

TestScore::TestScore () {
    pquiz = new double[num];                      //dynamically allocate memory for the array of quiz grades
    average=0;
}

TestScore::TestScore (TestScore &obj) {           //copy constructor
    name = obj.name;
    pquiz = new double [num];
    for (int c = 0; c<num; c++) {pquiz[c] = obj.pquiz[c];}
    average = obj.average;
}

TestScore::~TestScore () {
delete [] pquiz;
pquiz = 0;                                 //delete dynamically allocated memory
}

double TestScore::averagegrade () {             //class function that calculates the average quiz grade
    double sum = 0;
        for (int i=0; i<num; i++) {
            sum += pquiz[i];
        }
    average=(sum/num);
return average;
}

void TestScore::setGrades (int n, double grd) {
    pquiz[n] = grd;
}

void TestScore::setName(string nam) {
name=nam;
}

string TestScore::getName () {
    return name;
}

void TestScore::stuGrades(int number) {        //static member function
num += number;
}

int TestScore::getNum () {
return num;
}

int TestScore::num = 0;                        //static variable value assignment

void readData (TestScore &,int);               //function prototypes
void printData (TestScore);

int main()
{
    const int n=3;
    int numGrades;

    cout << "This program calculates the average quiz grades for 3 individual students." << endl << endl;
    cout << "Enter the number of quizzes given" << ":" << endl;
    cin >> numGrades;

    TestScore::stuGrades(numGrades);            //calls static member function and pass in numGrades

    TestScore Student[3];
    for (int i=0; i<n; i++) {
    readData(Student[i],i);
    printData(Student[i]);
    }

    return 0;
}

void readData (TestScore &obj,int s) {         //function that reads in all the quiz grades for all the students
    string name;
    int numGrades=obj.getNum();
    double grade;

        cout << "Enter name for Student " << s+1 << ":";

        cin.ignore();
        getline(cin,name);

        obj.setName(name);

        for (int i = 0; i <numGrades; i ++) {
            cout << "Please input grade " << (i+1) << ":" << endl;
            cin >> grade;
                if (grade >= 0) {
                    obj.setGrades(i,grade);
                }
                else {
                    while (grade < 0) {
                    cout << "Invalid grade, please enter a valid grade!" << endl;
                    cin >> grade;
                    }
                    obj.setGrades(i,grade);
                }
        }
    return;
}

void printData (TestScore arr) {             //function that prints the student name and average quiz grade of each student
    cout << arr.getName() << "'s average quiz grade is " << arr.averagegrade() << endl << endl;
    return;
}
