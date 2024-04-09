//
// Created by Michael Ramenofsky on 4/9/24.
//

#include "AuthenticationFilter.h"

int AuthenticationPipe(database db){
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

