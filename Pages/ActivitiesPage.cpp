//
// Created by Michael Ramenofsky on 3/30/24.
//

#include "ActivitiesPage.h"


string ActivitiesPage(database db){

    vector<string> activity= db.get_newest_activity();

    string response;
    const int LINELENGTH = 100;
    string header(LINELENGTH, '=');
    cout << header << '\n';
    print( CENTER  , "Red Rock Activities Page!"  , LINELENGTH );
    cout << endl;
    print( CENTER  , "Look at some recommended activities below"  , LINELENGTH );
    cout << endl;
    //print( LEFT  , "Connect activities Database here and display them in a list"  , LINELENGTH );

    cout << "Activity: " << activity[0] << endl;
    cout << "Date: " << activity[1] << endl;
    cout << "Time: " << activity[2] << endl;
    cout << "Description: " << activity[3] << endl;

    cout << endl;
    cout << "0) Return to Homepage" << endl << "X) End Program" << endl;
    cout << "Type Answer Here:" ;
    cin >> response;
    cout << header << '\n';
    return response;
}