/*
Implement a class EncryptString that inherits from the STL string class. The base
class access should be public. The class has two member functions: void encrypt()
and void decrypt(). Use the simple encryption algorithm called Caesar Cipher, it is
a type of substitution cipher in which each letter in the plain text is replaced
by a letter some fixed number of positions down the alphabet.
*/

#include <iostream>
#include <string>

using namespace std;

class EncryptString: public string
{
    public:
        void encrypt ();
        void decrypt ();
} ;

void EncryptString::encrypt () {                    //encrypt function
    for (int i = 0; i <this->length(); i++)
    	(*this)[i] += 3;
}

void EncryptString::decrypt () {                    //decrypt function
	 for (int i = 0; i <this->length(); i++)
    	(*this)[i] -= 3;
}

int main()
{
    EncryptString message;

    cout << "Please input your message for encryption: ";
    getline(cin,message);

    message.encrypt();
    cout << "The encrypted message is: ";
    cout << message << endl;

    message.decrypt();
    cout << "The original message is: ";
    cout << message << endl;

    return 0;
}
