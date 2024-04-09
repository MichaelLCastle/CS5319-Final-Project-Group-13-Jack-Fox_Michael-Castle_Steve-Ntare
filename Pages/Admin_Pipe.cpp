//
// Created by Michael Ramenofsky on 3/30/24.
//

#include "Admin_Pipe.h"


void Admin_Pipe(database& db){
    db.save_tables();

    const int LINELENGTH = 100;
    string header( LINELENGTH, '=' );


    string FirstResponse;
    cout << header << '\n';
//    print( CENTER  , "Red Rock Admin Page"  , LINELENGTH );
//    cout << endl;
//    print( CENTER  , "Admin changes can occur below:"  , LINELENGTH );
//    cout << endl;
    print( LEFT  , "What would you like to do? Please type one of the following numbers"  , LINELENGTH );
    cout << "1) Update Daily News" << endl << "2) View Guest Feedback " << endl << "3) Add Activities "  << endl << "X) End Program" << endl;
    cout << "Type Answer Here:" ;
    cin >> FirstResponse;

    while (FirstResponse != "X") {
        if (FirstResponse == "1") {
            UpdateNewsFilter(db);
        } else if (FirstResponse == "2") {
            ReviewFeedbackFilter(db);
        } else if (FirstResponse == "3") {
            AddActivityFilter(db);
        } else {
            cout << "Not Valid Response. Please Try again" << endl;
            this_thread::sleep_for(std::chrono::seconds(10));
            Admin_Pipe(db);
        }
    }
    std::exit(0);
}

