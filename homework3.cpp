/* Implement a class named Message that models an email message. The data that the class
needs is a sender, a recipient, a subject, a time stamp and a message text. Instead of
a single string a vector of strings is used to create the message.Use the class in a
source code that asks the user for sender and recipient e-mail addresses. The code creates
the Message object using the constructor. The code then asks for the subject and assigns it
using a mutator function. The body of the e-mail is created using the append() function, one
line at a time. Have the user indicate the end of input by typing a '.' as the first character
on a new line. When the message is complete, print it out to standard output using the member
print function. */


#include <iostream>
#include <vector>
#include <ctime>
#include <string>

using namespace std;

class Message {                                 //message class

public:
    Message (string, string, time_t);
    void changeSubject (string);
    void addMessage (string);
    void append();
    string getSender ();
    string getRecipient ();
    string getSubject ();
    string getMessage ();
    char* geTime ();
    void printEverything ();

private:
    string sender;
    string recipient;
    char* tstamp;
    string subject;
    vector <string> message;
};


Message::Message (string sendee, string receivee, time_t now){               //3 parameter constructor

	if (sendee.find("@") <= sendee.length() && (sendee.find(".com") || sendee.find(".edu") <= sendee.length())) {
    		sender = sendee;
}
	else {
    		cout << "Invalid sender email address." << endl;
    		sender = "Unknown";
}

	if (receivee.find("@") <= receivee.length() && ((receivee.find(".com") || receivee.find(".edu")) <= receivee.length())) {
    		recipient = receivee;
}
	else {
    		cout << "Invalid recipient email address. " << endl;
    		recipient = "Unknown";
}

	tstamp = ctime(&now);
}

void Message::changeSubject (string subjecto) {                     //mutator function that changes the subject
	subject = subjecto;
}

void Message::addMessage (string messageo) {                        //mutator function that adds to the message vector
	message.push_back(messageo);
}

string Message::getSender () {                                //accessor function that returns sender
	return sender;
}

string Message::getRecipient () {                             //accessor function that returns recipient
	return recipient;
}

string Message::getSubject () {                               //accessor function that 	returns subject
	return subject;
}

char* Message::geTime () {                                    //accessor function that returns the date and time
	return tstamp;
}

void Message::append () {                                     //function that cycles through the vector and prints out the message
    for (int j = 0; j < message.size(); j++) {
        cout << message[j];
    }
return;
}

void Message::printEverything () {                            //function that prints everything
    cout << "Date: " << tstamp << endl;
    cout << "To: " << recipient << endl;
    cout << "Subject: " << subject << endl;
    cout << "From: " << sender << endl;
    for (int z = 0; z < message.size(); z++) {
        cout << message[z] << " ";
    }
return;
}



int main()
{
    string whoareyou, whothisfor, aboutwhat, whatyouwant;

    cout << "Enter sender email address: " << endl;
    getline(cin, whoareyou);                                           //user input sender email address

    cout << "Enter recipient email address: " << endl;
    getline(cin, whothisfor);                                          //user input recipient email address


    Message person = Message(whoareyou, whothisfor, time(0));          //create class object and pass string variables and time

    if (person.getRecipient() != "Unknown" && person.getSender() != "Unknown") {   //run program only if valid sender and recipient info is given

    cout << "Enter subject: " << endl;
    getline(cin, aboutwhat);                                   //user input subject
    person.changeSubject(aboutwhat);

    cout << "Enter message: " << endl;
    getline(cin,whatyouwant);                              //user input message
    while ( whatyouwant != ".") {
        person.addMessage(whatyouwant);                    //don't stop collecting inputs until a lone period has been entered
        getline(cin,whatyouwant);
    }

    person.printEverything();

    }

    else {
        cout << "Unable to run program due to invalid input. Please rerun the program.";
    }


return 0;
}
