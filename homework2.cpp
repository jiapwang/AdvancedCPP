/*Implement a class named Country that stores information about a country,
such as its name, its population and its area. Use the class to create an
array of Country objects. The code reads in the values from an external file,
myCountrydata.txt. Then it uses the mutator function to assign the values to
the member variables. The code then gets passed to function called calcCountry ()
that calculates which country has the largest area, population, and density
(people/square unit).*/


#include <iostream>
#include <fstream>

using namespace std;

class Country {                                             //class Country
public:                                                     //public variables
    Country();
    void setStuff (string, long int, double);
    string getName ();
    long int getPop ();
    double getArea ();

private:                                                    //private variables
    string name;
    long int population;
    double area;

};

void calcCountry (Country [], int);							//function prototype for calcCountry

Country::Country () {                                       //constuctor that assigns the initial values for the name, population, and area
name = "Name of Country";
population = area = 0;
}

void Country::setStuff (string nam, long int pop, double are) {      //mutator function that sets all the member variables
name = nam;

if (pop>0) {
    population = pop;
}
    else {
        cout << nam << " has an invalid population, setting population to 0." << endl;
        population = 0;}

if (are > 0) {
    area = are;
}

    else {cout << nam << " has an invalid area, setting area to 0." << endl;
    area = 0;}
};

string Country::getName () {                                //accessor function that returns the name of the country
    return name;
    }
long int Country::getPop () {                               //accessor function that returns population count of the country
    return population;
    }
double Country::getArea () {                           //accessor function that returns the total area of the country
    return area;
    }



int main()
{
    int cnt=12;
    string n;
    long int x;
    double a;

    ifstream datatext;
    datatext.open ("myCountrydata.txt");                    //open external file

    Country array[12];                                      //create a 12 element array


    for (int looper = 0; looper <cnt; looper ++) {
    datatext >> n >> x >> a;
    array[looper].setStuff(n, x, a);                        //set name, population, and area of each variable array
    }

    cout << endl;

    datatext.close();                                       //close external file

    calcCountry (array,cnt);                                //calls the calcCountry function and passes in the array and the size of the array

    return 0;
}

void calcCountry (Country c[], int many) {                  //this function goes through the array and keeps tracks of the country that has the largest population and area, and later prints it out
    int largestarea = 0, largestpopulation = 0, largestdensitynumber =0; double largestdensity=0;
    for (int looper2 = 0; looper2 < many; looper2 ++) {
        if (c[looper2].getArea() > c[largestarea].getArea()) {
            largestarea = looper2;
        }

        if (c[looper2].getPop() > c[largestpopulation].getPop()) {
            largestpopulation = looper2;
        }

        if ( c[looper2].getPop() > 0 && c[looper2].getArea() > 0 && c[looper2].getPop()/c[looper2].getArea() > largestdensity) {        //makes sure that population and area are greater than zero, and that population/area is greater than largestdensity
            largestdensity=c[looper2].getPop()/c[looper2].getArea();
            largestdensitynumber=looper2;
        }
    }

    cout << "The country with the largest area is " << c[largestarea].getName() << " with " << c[largestarea].getArea() << " square miles." << endl;
    cout << "The country with the largest population is " << c[largestpopulation].getName() << " with " << c[largestpopulation].getPop() << " people." << endl;
    cout << "The country with the largest density is " << c[largestdensitynumber].getName() << " with " << largestdensity << " people per square mile." << endl;
    return;
}
