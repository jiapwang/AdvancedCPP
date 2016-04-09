/*
The program obtain a filename from the user and will analyze the
contents of the file using a function called searchstring().
The program also prints the matching lines and a total count of
the number of matching lines.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;
int searchstring(fstream &, string );

int main()
{
    fstream file;
    string filename, S_str;

    cout << "Enter name of file including the .extension: ";
    getline(cin, filename);
    cout << "\n";
    file.open(filename.c_str());

    if (!file) {
        cout << "File could not be found. The program will now exit.\n";
        exit(1);
    }

    cout << "File Opening Successful! \n\nEnter search word: ";
    cin >> S_str;
    cout << "\n";
    cout << "\n" << S_str << " occurred in " << searchstring(file, S_str) << " lines within the file. ";

    file.close();

    return 0;
}

/*
searchstring function accepts the file as reference and a string.
The function goes through the entire file and find the number
of occurence(s) of the passed in string. It prints out the line that
contains the string and returns the total number of lines that contain
the string.
*/

int searchstring (fstream &file, string sstr) {
    string line;
    int countline = 0;

    while (!file.eof()) {
        getline(file, line);
        if (line.find(sstr)!=string::npos)
            cout << line << "\n";
            countline++;
    }

return countline;
}
