//Use the class 'TestScore' in a program that averages a set of student scores on quizzes

#include <iostream>

using namespace std;

class TestScore {              //TestScore class
    private:
        string name;
        int num;
        double *pquiz;
        double average;
    public:
        TestScore (string, int);
        ~TestScore ();
        double averagegrade ();
        string getName ();
        void setGrades(int, double);
};

TestScore::TestScore (string who, int a) {
    name=who;
    num=a;
    pquiz = new double[a];                      //dynamically allocate memory for the array of quiz grades
    average=0;
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

string TestScore::getName () {
    return name;
}


int main()
{
    string name;
    int numGrades;
    double grade;

    cout << "Enter student name:" << endl;
    getline(cin,name);

    cout << "Enter the number of quiz grade(s) for " << name << ":" << endl;
    cin >> numGrades;

    TestScore student (name, numGrades);

    for (int i = 0; i <numGrades; i ++) {
        cout << "Please input grade " << (i+1) << ":" << endl;
        cin >> grade;
            if (grade >= 0) {
                student.setGrades(i,grade);
            }
            else {
                while (grade < 0) {
                cout << "Invalid grade, please enter a valid grade!" << endl;
                cin >> grade;
                }
                student.setGrades(i,grade);
            }
    }

    cout << "\nThe average of the grades for " << student.getName() << " is: " << student.averagegrade() << endl;


    return 0;
}
