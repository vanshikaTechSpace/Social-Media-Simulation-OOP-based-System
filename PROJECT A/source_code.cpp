//header file that includes necessary classes and libraries
#include "classes.h"
// Function to display the front page menu and get user choice
int front_page()
{
    int choice;
    cout << "\n______CHATTER______";
    cout << "\n1.Sign UP";
    cout << "\n2.Log In";
    cout << "\n3.Exit";
    cout << "\n\nEnter your choice : ";
    cin >> (choice);
    return (choice);
}

int main()
{
    social_media ver1;
    char c;
    bool Account_flag = 0;

      // Label for returning to the front page
    front_p:

    while (1)
    {
        system("clear");

        //To show current time on screen
auto start = chrono::system_clock::now();
    // Some computation here
    auto end = chrono::system_clock::now();
     time_t end_time = chrono::system_clock::to_time_t(end);
 
 //Use of Manipulators to display Time
    cout << setw(90) << ctime(&end_time) ;
        switch (front_page())
        {
        case 1:
            system("clear");
            ver1.set_account();
            ver1.set_account(0);
            break;
        case 2:
            system("clear");
            if (ver1.check_account())
                goto user_call;
            break;
        case 3:
            system("clear");
            cout << "THANKS!!! For Your Visit.";
            cout << "\nPlease press any key to exit.";
            getchar();
            getchar();
            exit(0);
            break;
        default:
            break;
        }
    }

// Label for returning to the front page after user interactions
 user_call:
User u1;
    while (1)
    {
        system("clear");
        // Switch statement for user menu options
        switch (user_menu())
        {
        case 1:
            system("clear");
            u1.add_friend();
            break;
        case 2:
            system("clear");
            u1.check_friend();
            break;
        case 3:
            system("clear");
            u1.post_friend();
            break;
        case 4:
            system("clear");
            u1.check_inbox();
            break;
        case 5:
            system("clear");
            u1.check_post();
            break;
        case 6:
            system("clear");
            cout << "THANKS!!! For Your Visit.";
            cout << "\nPlease press any key to exit.";
            getchar();
            getchar();
            goto front_p;
            break;

        default:
            break;
        }
    }
    return 0;
}