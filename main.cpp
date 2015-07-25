/*
Pl2 Semester Project.
Course Teacher: MOHAMMAD SAMAWAT ULLAH
Team Members:

Name: Shadman Sakib
ID: 15-28368-1

Name: Kazi Ahmedul Huque
ID: 15-28875-1

Acknowledgement: I've written all the codes by myself but I've got help from the Internet to clear my concepts.
Also I'd like to give credit to: http://www.cplusplus.com/ and http://www.tutorialspoint.com/
This project has been uploaded to gitHub.*/

#include <iostream> //Any explanation needed? :O
#include <stdlib.h> //Used for clear the screen
#include <ctime>    //Used for time and date
#include <vector>   //For contacts, call logs and phone records. I used vector and learned about it as it is easy and better than array in some cases like this
#include <iostream>
#include <istream>
#include <string>
#include <fstream>

using namespace std;
/*Device is an OOP class to represent a phone which includes:
A way to create a new phone record
Methods to find and change the phone number
Methods to add credit to the phone and to find the current available credit
A method to add a call to the call history, including updating the credit*/


//Time and Date



/*PhoneBook*/

int const MAX_NUM_CONTACTS = 100;


struct Contacts
{
	string firstName[MAX_NUM_CONTACTS];
	string lastName[MAX_NUM_CONTACTS];
	string phoneNumber[MAX_NUM_CONTACTS];
};

void addContact(Contacts &Contact, int &numContacts);
void searchContact(Contacts &Contact, int &numContacts);
void saveContact(Contacts &Contact, int &numContacts);

void addContact(Contacts &Contact, int &numContacts)
{
	//entering contact info
	cout << "Enter contact's first and last name: ";
	cin >> Contact.firstName[numContacts] >> Contact.lastName[numContacts];

	cout << "Enter contact's phone number: ";
	cin >> Contact.phoneNumber[numContacts];


	numContacts++; //incrementing number of contacts
}
void searchContact(Contacts &Contact, int &numContacts)
{
	string searchFirst, searchLast;

	cout << "Enter first and last name of contact you wish to show: ";

	cin >> searchFirst >> searchLast; //getting search parameters for first and last name

	cout << endl;

	for (int i = 0; i < numContacts; i++) //incrementing through each contact and....
	{
		if (searchFirst == Contact.firstName[i] && searchLast == Contact.lastName[i]) // ...checking to see if first and last names match the entered query
		{
			cout << "Contact Found!\n\n";
			cout << "Name: " << Contact.firstName[i] << " " << Contact.lastName[i] << endl;
			cout << "Phone Number: " << Contact.phoneNumber[i] << endl;
		}
		else if ((searchFirst != Contact.firstName[i] && searchLast != Contact.lastName[i]))
		{
			cout << "No contact found, please try again\n";
			searchContact(Contact, numContacts);
		}
	}

}
void saveContact(Contacts &Contact, int &numContacts)
{
	ofstream file;
	string contactList;

	cout << "Please enter a file name including the extension to write to: ";

	cin >> contactList; //inputting name of file

	file.open(contactList.c_str()); //opening file

	if (file.is_open()) //checking if file is open
	{
		for (int i = 0; i < numContacts; i++)
		{
			//writing to file
			file << "Name: " << Contact.firstName[i] << " " << Contact.lastName[i] << endl;
			file << "Phone Number: " << Contact.phoneNumber[i] << endl;
		}
		file << endl;
	}
	else
	{
		cout << "File could not be opened...\n";
	}

}

/*PhoneBook Ends Here */

class Device{
    public:
    int i = 0; //For loop
    int ndevice ; //Number of devices
    string dname[5]; //Device Name, one can have max. 5 phones.
    string *x; //Pointer for array
    int dnum;
    void optdevice(){
    ndevice = 1;
    x = dname;
    dname[0]={"Default Number"};
    cout <<"Enter how many device you have"<<endl;
    cin >> ndevice ;
    if (ndevice == 1) {
        cout << "You have only one device" <<endl;
    } else {
    cout << "Please enter the names/numbers if you have more than one default device/number" << endl;
    for (int j=1;j<ndevice;j++) {

            cin >> *(x+j);

        }
        cout << "Your devices are:"<<endl;
        for (int i=0;i<ndevice;i++) {

            cout << (1+i) <<". " << *(x+i) <<endl;

        }
    }
        if  (ndevice > 1) {
        cout << "Please select the number of device you want to use" <<endl;
        cin  >> dnum;
        dnum = dnum-1;
        system("cls");}
        else {
            dnum = 0;
            system("cls");
        }
    }
};

/*A class which defines name, number and call cost*/
class PhoneRecord {
    public:



    //phone book
    string number_record[100];
    string name_record[100];
    string *name;
    string *number;
    void contactname(){
    name = name_record;
    }
    void contactnumber(){
    name = number_record;
    }

    //for call
    string numcalling;
    void call(){
        cout << "Enter the number you want to call"<<endl;
        cin >> numcalling;
        getCallcost();
        cout<<"Call Record Created on"<<endl;
        tnd();
        cout << "Press 5 to return"<<endl;
        phonenumb.push_back(numcalling);
    }
     //for sms
     string sms;
    void sendSms(){
        cout << "Enter the number you want to send sms"<<endl;
        cin >> numcalling;
        cout << "Enter The Message" <<endl;
        cin >> sms;
        cin.ignore();
        cin.ignore();
        smscost();


        cout<<"SMS Sent on: "<<endl;
        tnd();
        cin.ignore();
        cout << "Press 5 to return"<<endl;
        cin.ignore();
        phonenumb.push_back(numcalling);
        smslog.push_back(sms);
    }

    //for account credit
    double cost_record=10.0; // variable for credit
    void setCost_record (double cost) {
        cost_record = cost;
    }
    double getCost_record() {
        return cost_record;
    }
    //Call duration and call calculator
    double callcost=0.25;

    double getCallcost(){
    unsigned int start = clock();
    cout << "Call Received."<<endl
     << "Press ENTER to end call"<<endl;
    cin.ignore();
    cin.ignore();
    float dur = (clock()-start)/1000 ;
    calltime.push_back(dur);
    cout << "Call Duration: " << dur <<" Seconds"<<endl;
    cin.ignore();
    float cc = (((clock()-start)/1000) * callcost)-callcost;
    cost.push_back(cc);
    cout<<"Call Cost: BDT "<< cc <<endl;;
    cost_record = cost_record - ((((clock()-start)/1000) * callcost)-callcost);
    cout<<"Your current available balance:"<<cost_record<<" taka"<<endl;
    }
    void tnd(){
    time_t rawtime;
    time (&rawtime);
    struct tm * timeinfo;
    timeinfo = localtime (&rawtime);
    cout<<asctime(timeinfo)<<endl;
    }
    //smscost

    void smscost(){
    cout << "SMS BDT 1" <<endl;
    cost_record = cost_record-1;
    cout << "Available Balance: " << cost_record << endl;
    }
    //callrecord
    vector<string>phonenumb;
    vector<double>cost;
    vector<float>calltime;
    vector<string>smslog;

    void CallLog(){

    for (int ci = 0; ci < phonenumb.size(); ci++){
            cout << "\n"<<"Record #"<<ci+1 <<endl;
            cout << "Phone Number: "<<phonenumb[ci] <<endl;
            cout << "Call Duration: "<<calltime[ci]<<endl;
            cout << "Call Cost: "<<cost[ci]<<endl;

            }
    }
     void SMSLog(){

    for (int ci = 0; ci < phonenumb.size(); ci++){
            cout << "\n"<<"Record #"<<ci+1 <<endl;
            cout << "Phone Number: "<<phonenumb[ci] <<endl;
            cout << "SMS: \n" << smslog[ci];
            }
    }
};


int main()
{


    PhoneRecord Phone;
    Device d;
    Contacts Contact;
	char option;
	bool keepGoing = true;
	int numContacts = 0;
    int menu = 6;   //Number of menu items to show.
    int sec_menu = 0;
    int sec_menu2 = 0;
    double input_cost;
    d.optdevice();
    while (menu !=0){
    cout << "You're using " << d.dname[d.dnum]<<endl;
    cout << "\tMenu" << endl
         << "1. Account Details"<<endl
         << "2. Make a Call"<<endl
         << "3. Contacts"<<endl
         << "4. Call Log"<<endl
         << "5. SMS"<<endl
         << "6. Change Phone"<<endl
         << "0. Turn off phone"<<endl;
    cin >> menu;
        if (menu == 1) {
            system("cls");
            cout << "1. Add Credit" << endl
                 << "2. View Credit" << endl
                 << "5. Return" <<endl;
            cin >> sec_menu;
                 if (sec_menu == 1) {
                     system("cls");
                     cout << "Please enter the amount you want to recharge: ";
                     cin >> input_cost;
                     Phone.setCost_record(input_cost);
                     cout <<  Phone.getCost_record() <<" taka has been credited to your account." <<endl;
                     cin.ignore();
                     cout << "Press 5 to return to the main menu."<<endl;
                     cin >> menu;
                 } else
                 if (sec_menu == 2) {
                    cout << "Your current account balance is " << Phone.getCost_record() <<endl;
                    cout << "Press 5 to return to the main menu."<<endl;
                    cin >> menu;
                 }
                }
        else if (menu==6){
            system("cls");
            cout << "Your devices are:"<<endl;
            for ( d.i;d.i<d.ndevice;d.i++) {

            cout << (1+d.i) <<". " << *(d.x+d.i) <<endl;

            }

        cout << "Please select the number of device you want to use" <<endl;
        cin  >> d.dnum;
        d.dnum = d.dnum-1;
        system("cls");
        } else if (menu == 3) {
            system("cls");
          do
	{
		cout << "\n \n1. Add a contact\n";
		cout << "2. Search Contact\n";
		cout << "3. Save all contacts to file\n";
		cout << "4. Show all the contacts \n";
		cout << "5. Return\n";
		cin >> option;
		//switch statement menu
		switch (option)
		{
			case '1':
                system("cls");
				if (numContacts <= MAX_NUM_CONTACTS)
				{
					addContact(Contact, numContacts);
				}
				else if (numContacts > MAX_NUM_CONTACTS)
				{
					cout << "You have reached the maximum number of contacts.";
				}

				break;
			case '2':
			    system("cls");
				searchContact(Contact, numContacts);
				;
				break;
			case '3':
			    system("cls");
				saveContact(Contact, numContacts);
				break;
            case '4':
                system("cls");
                cout << "Saved Contacts" <<endl;
                for (int i = 0; i < numContacts; i++)
                {
			//showing contacts
			cout<< "\n#"<< i+1 <<endl;
			cout << "Name: " << Contact.firstName[i] << " " << Contact.lastName[i] << endl;
			cout << "Phone Number: " << Contact.phoneNumber[i] << endl;
                }

                break;
			case '5': // quit option
			keepGoing = false;
			break;
	default:
		cout << "Please pick a valid option.\n\n";
		break;
		}
	} while (keepGoing == true);
	cin.get();
	system("cls");
        } else if (menu == 4) {
            system("cls");
            if (Phone.phonenumb.size() == 0) {
                cout << "No call records to show" <<endl;
                cout <<"Enter 5 To Return"<<endl;
                cin >> menu;
            } else {
            Phone.CallLog();
            cout <<"Enter 5 To Return"<<endl;
            cin >> menu;
            }

        } else if (menu == 2) {
             system("cls");
            cout <<"1. Dial a number"<<endl;
            cout <<"2. Choose from existing contacts"<<endl;
            cin >> sec_menu;

            if (sec_menu == 1){
            system("cls");

            Phone.call();
            cin.ignore();
        } else if (sec_menu==2) {
            system("cls");
        for (int i = 0; i < numContacts; i++)
                {
			//showing contacts
			cout<< "\n#"<< i+1 <<endl;
			cout << "Name: " << Contact.firstName[i] << " " << Contact.lastName[i] << endl;
			cout << "Phone Number: " << Contact.phoneNumber[i] << endl;
                }
                Phone.call();
        }
        } else if (menu==5){
            system("cls");
            cout << "1. Send SMS" << endl;
            cout << "2. SMS Log" <<endl;
            cin >> sec_menu;
         if (sec_menu == 1) {
                 system("cls");
        Phone.sendSms();
        } else if (sec_menu == 2) {
             system("cls");
            Phone.SMSLog();
            cout << "\n \nPress 5 To Return" <<endl;
            cin >> menu;
        }
        }
        system("cls");
    }
    return 0;
}
