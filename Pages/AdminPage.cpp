//
// Created by Michael Ramenofsky on 3/30/24.
//

#include "AdminPage.h"


void AdminPage(database& db){

    const int LINELENGTH = 100;
    string header( LINELENGTH, '=' );


    string FirstResponse;
    cout << header << '\n';
    print( CENTER  , "Red Rock Admin Page"  , LINELENGTH );
    cout << endl;
    print( CENTER  , "Admin changes can occur below:"  , LINELENGTH );
    cout << endl;
    print( LEFT  , "What would you like to do? Please type one of the following numbers"  , LINELENGTH );
    cout << "1) Update Daily News" << endl << "2) View Guest Feedback " << endl << "3) Add Activities "  << endl << "X) End Program" << endl;
    cout << "Type Answer Here:" ;
    cin >> FirstResponse;
    while(FirstResponse!= "X" && FirstResponse!= "x"){

        int response = stoi(FirstResponse);
        vector<vector<string>> feedback = db.get_feedback();
        string name;
        string date;
        string time;
        string description;
        string news;
        switch (response) {
            case 1:
                cout << "Input new news here: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin,news);
                db.add_news(news);
                break;
            case 2:
                cout << endl;
                for (int i = 0; i < feedback.size(); i++) {
                    cout << "Rating: " << feedback[i][0] << endl;

                    cout << "Comment: " << feedback[i][1] << endl << endl;
                }
                break;
            case 3:
                cout << "Activity name: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin,name);
                cout << "Activity date: ";
                //cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin,date);
                cout << "Activity time: ";
                //cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin,time);
                cout << "Activity description: ";
                //cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin,description);

                db.add_activity(name, date, time, description);
                break;
        }
        cout << header << '\n';
        print( LEFT  , "What would you like to do? Please type one of the following numbers"  , LINELENGTH );
        cout << "1) Update Daily News" << endl << "2) View Guest Feedback " << endl << "3) Add Activities "  << endl << "X) End Program" << endl;
        cout << "Type Answer Here:" ;
        cin >> FirstResponse;
    }
    cout << header << '\n';

}

int Authentication(database db){
    const int LINELENGTH = 100;
    string header( LINELENGTH, '=' );
    string auth;
    int Home = 0;
    int Admin = 1;

    print( CENTER  , "Red Rock Authentication Page"  , LINELENGTH );
    cout << endl;
    cout <<  "Please Type (Admin) or (User):";
    cin >> auth;
    // add authtication code for admin and user
    if(auth == "User" || auth == "user"){
        return Home;
    }else if(auth == "Admin" || auth == "admin"){
        bool is_admin= false;
        while(!is_admin){
            string username;
            cout << "Please enter your username here:";
            cin >> username;
            string password;
            cout << "Please enter your password here:";
            cin >> password;

            if(db.login_attempt(username, password)){
                is_admin= true;
            }else{
                cout << "Incorrect username or password. Please try again" << endl;
            }
        }
        return Admin;
    }

}