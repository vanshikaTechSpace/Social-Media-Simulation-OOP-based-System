#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include <sys/stat.h>
#include <sys/types.h>
#include <sysdir.h>
#include <ctime>
#include <chrono>

using namespace std;

fstream myfile;
fstream newfile;
string admin_NAME;

//Abstract class to store protocol details which is not necessary to show user
class protocol_detail
{
    private:
    //Pure virtual function in Abstract class
    virtual void show()=0;
    void protocol()
    {
        cout<<"POST :: FTP";
        cout<<"IP :: DHCP";
        cout<<"Server :: SMTP";
        cout<<"Sending :: TCP";
    }
};

// Definition of the social_media class
class social_media
{
    // Private members for admin details
    string admin;
    string password;
    // Profile details: name, dob, gender, country, phone, email
    string name;
    int dob[3];
    char gender;
    string country;
    string phone_number;
    string email;

public:
    social_media() {}
    ~social_media() {}
    // Function prototypes for setting and checking account/profile
    //The word “polymorphism” means having many forms. In simple words, we can define polymorphism as the ability of a message to be displayed in more than one form.
    //Types of Polymorphism
//        Compile-time Polymorphism                               Runtime Polymorphism
//A. Function Overloading     B. Operator Overloading  ||  A. Function Overriding     B. Virtual Function

    //Function set_account overloaded
    //This is example of compile type polymorphism of function overloading type.
    void set_account();
    void set_account(int);

    bool check_account();
};

// Definition of the User class 
//The capability of a class to derive properties and characteristics from another class is called Inheritance.
//Modes of Inheritance: There are 3 modes of inheritance.
// PUBLIC         PRIVATE         PROTECTED
// Types Of Inheritance:-
//                  Single inheritance
//                  Multilevel inheritance
//                  Multiple inheritance
//                  Hierarchical inheritance
//                  Hybrid inheritance
// Class Social_media is Inherited in public mode using single inheritence
class User : public social_media
{
public:
// Function prototypes for user actions
    void add_friend();
    void check_friend();
    void post_friend();
    void check_inbox();
    void check_post();
};

// Function to check if a given email is a valid Gmail address
bool isValidGmailAddress(const string &email)
{
    // Check if the email ends with "@gmail.com"
    size_t pos = email.find("@gmail.com");
    return pos != string::npos && pos == email.length() - 10;
}

// Function to check if a given country is valid (exists in the country.txt file)
bool isValidcountry(const string &country)
{
    myfile.open("country.txt");
    string word;
    while (myfile >> word)
    {
        if (word == country)
        {
            myfile.close();
            return true;
        }
    }
    myfile.close();
    return false;
}

// Function to check if a given keyword exists in the file
bool check_names(string keyword)
{
    string word;
    while (myfile >> word)
    {
        if (word == keyword)
        {
            return true;
        }
    }
    return false;
}

// Function to set the profile details for the social_media class
void social_media ::set_account(int empty_val)
{
    cout << "\nEnter name : ";
    cin.ignore();
    getline(cin, name);
    cout << "\nEnter Date of birth 'date month year' use spaces only no special char  :: ";
    cin >> dob[0] >> dob[1] >> dob[2];
    cout << "\nEnter gender \nM : MALE\nF : FEMALE \nO : OTHERS\n---->>>>";
    cin >> gender;
    cout << "Enter Phone Number : ";
    cin >> phone_number;
    int i = 0;
    do
    {
        if (i != 0)
            cout << "\nInvalid country. Rewrite it!!!";
        cout << "Enter country  (First alphabet Capitalise only ) : ";
        cin>>country;
        i = 1;
    } while (!isValidcountry(country));
    i = 0;
    do
    {
        if (i != 0)
            cout << "\nInvalid email. Rewrite it!!!";
        cout << "\nEnter email ('@gmail.com is necessary') : ";
        cin >> email;
        i = 1;
    } while (!isValidGmailAddress(email));
    string file = "profile.txt";
    string file_path =  admin + "/";
    file_path += file;
    myfile.open(file_path, ios::app);
    myfile << "ID name :: " << admin;
    myfile << "\nName :: " << name;
    myfile << "\nDOB :: " << dob[0] << "|" << dob[1] << "|" << dob[2];
    myfile << "\nGender :: " << gender;
    myfile << "\nPhone number :: " << phone_number;
    myfile << "\nCountry :: " << country;
    myfile << "\nEmail :: " << email;
    myfile.close();
    return;
}

// Function to set the account details for the social_media class
void social_media ::set_account()
{
    bool decision;
    do
    {
    myfile.open("record.txt");
    if (!myfile)
        cout << "No records exist till now.\n";
        
        cout << "Enter ADMIN name : ";
        cin >> admin;

        decision=check_names(admin);
    myfile.close();
        if (decision)
            cout << "ADMIN name already exist, Rechoose it!!\n";
    } while (decision);
    cout << "Enter password: ";
    cin >> password;
    myfile.open("record.txt", ios::app);
    myfile << admin << "\t" << password << endl;
    myfile.close();
    string folder =  admin;
    string directories = folder;
    mkdir(directories.c_str(), 0777);
    cout << "\nYOUR ACCOUNT HAS BEEN REGISTERD.";
}

// Function to check the account details for the social_media class
bool social_media ::check_account()
{
    myfile.open("record.txt");
    if (!myfile)
        cout << "No record exist till now.\n";
    char c, d;
    cout << "Enter ADMIN name : ";
    cin >> admin;
    cout << "Enter password: ";
    cin >> password;
    if (check_names(admin) && check_names(password))
    {
        myfile.close();
        cout << "Welcome " << admin << endl;
        string file = "friend.txt";
        string file_path( admin + "/");
        file_path += file;
        myfile.open(file_path, ios::app);
        myfile.close();
        file = "inbox.txt";
        file_path =  admin + "/";
        file_path += file;
        myfile.open(file_path, ios::app);
        myfile.close();
        file = "post.txt";
        file_path =  admin + "/";
        file_path += file;
        myfile.open(file_path, ios::app);
        myfile.close();
        admin_NAME = admin;
        this_thread::sleep_for(chrono::seconds(1));
        return true;
    }
    else
    {
        myfile.close();
        cout << "WRONG ADMIN NAME OR PASSWORD!!\n";
        this_thread::sleep_for(chrono::seconds(1));
        return false;
    }
}

// Function to display user menu and get user choice
int user_menu()
{
    int choice;
    cout << "\n______CHATTER_______";
    cout << "\n1.Add friends";
    cout << "\n2.Check friend list";
    cout << "\n3.Post Message";
    cout << "\n4.Check Inbox";
    cout << "\n5.Check your Posts";
    cout << "\n6.Exit";
    cout << "\n\nEnter your choice : ";
    cin >> (choice);
    return (choice);
}

// Function to add a friend for the User class
void User ::add_friend()
{
    string friend_name;
    cout << "\nEnter friend's ADMIN name : ";
    cin >> friend_name;
    myfile.open("record.txt");
    if (check_names(friend_name) && friend_name!=admin_NAME)
    {
        myfile.close();
        string file_path =  admin_NAME + "/" + "friend.txt";
        myfile.open(file_path);
        if (!check_names(friend_name))
        {
            myfile.close();
            string file_path =  admin_NAME + "/" + "friend.txt";
            myfile.open(file_path, ios::app);
            myfile << friend_name << endl;
            myfile.close();
            cout << "\nFriend name has been added to your list.\n";
            this_thread::sleep_for(chrono::seconds(1));
        }
        else
        {
            myfile.close();
            cout << "\nFriend name already exist!!!\n";
            this_thread::sleep_for(chrono::seconds(1));
        }
    }
    else
    {
        myfile.close();
        cout << "\nFriend name donot exist!!!\n";
        this_thread::sleep_for(chrono::seconds(1));
    }
    return;
}

// Function to check and display the friend list for the User class
void User ::check_friend()
{
    string file_path =  admin_NAME + "/" + "friend.txt";
    myfile.open(file_path);
    string word;
    while (myfile >> word)
    { // take word and print
        cout << word << endl;
    }
    myfile.close();
    this_thread::sleep_for(chrono::seconds(1));
}

void User ::post_friend()
{
    string recipient;
    cout << "Enter name of friend that you want to send : ";
    cin >> recipient;
    string file_path =  admin_NAME + "/" + "friend.txt";
    myfile.open(file_path);
    string word;
    int flag=0;
    while (myfile >> word)
    {
        if (word == recipient)
        flag =1;
    }
    if(flag==1)
        {
            myfile.close();
            string file_path =  recipient + "/" + "inbox.txt";
            string new_path =  admin_NAME + "/" + "post.txt";
            myfile.open(file_path, ios ::app);
            newfile.open(new_path, ios ::app);
            string word;
            cout << "\nEnter your message (to exit write '//end*' ): ";
            myfile << endl
                   << "Sender : " << admin_NAME << " ->" << endl;
            newfile << endl
                    << "Reciever : " << recipient << " ->" << endl;
            while (word != "//end*")
            {
                cin >> word;
                myfile << word << " ";
                newfile << word << " ";
            }
            myfile << endl;
            newfile << endl;
            myfile.close();
            newfile.close();
        }
        else
            cout << "\nRecipient is not your friend";
    getchar();
    getchar();
}

// Function to post a message for the User class
void User ::check_inbox()
{
    string file_path =  admin_NAME + "/" + "inbox.txt";
    myfile.open(file_path);
    string word;
    while (myfile >> word)
    { // take word and print
        cout << word << " ";
        if (word == "//end*")
        {
            cout << endl
                 << endl;
        }
        if (word == "->")
        {
            cout << endl;
        }
    }
    myfile.close();
    getchar();
    getchar();
}

// Function to check and display the inbox for the User class
void User ::check_post()
{
    string file_path =  admin_NAME + "/" + "post.txt";
    myfile.open(file_path);
    string word;
    while (myfile >> word)
    { // take word and print
        cout << word << " ";
        if (word == "//end*")
        {
            cout << endl
                 << endl;
        }
        if (word == "->")
        {
            cout << endl;
        }
    }
    myfile.close();
    getchar();
    getchar();
}
