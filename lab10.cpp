/* Write a function countWords () that acccepts a C-string
as its parameter and returns an int. The return value is
the number of words contained in the C-string. */

#include <iostream>
#include <string.h>

using namespace std;
int countWords(char *);

int main()
{
    int n;
    const int S_length = 270;
    char sentence[S_length];

    cin.getline(sentence,S_length);

    n = countWords(sentence);

    cout << "There are " << n << " words.";

    return 0;
}


/*countWords function, accepts one parameter, calculates
the numbers of letters of each word and the numbers of words.
returns the numbers of words.*/

int countWords (char *Sentence)
{
    int pos=0,cnt=0, sum=0;
    double average;

    for (int a=0; a <= strlen(Sentence); a++)
        {
            cout << Sentence[a];

            if (Sentence[a] == ' ' || Sentence[a] == '\t') {
                cout << " " << a-pos << endl;
                sum+=a-pos;
                pos = a+1;
                cnt++;
            }

            if (a == strlen(Sentence)) {
                cout << " " << a-pos << endl;
                sum +=a-pos;
                cnt++;
                }
        }

        average = static_cast<double>(sum)/static_cast<double>(cnt);
        cout << "Average number of characters = " << average << endl;

    return cnt;

}

