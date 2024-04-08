//
// Created by Michael Ramenofsky on 3/30/24.
//

#include "ActivitiesPage.h"


string ActivitiesPage(database db){

    vector<vector<string>> activities= db.get_activities();


    string response;
    const int LINELENGTH = 100;
    string header(LINELENGTH, '=');
    cout << header << '\n';
    print( CENTER  , "Red Rock Activities Page!"  , LINELENGTH );
    cout << endl;
    print( CENTER  , "Look at some recommended activities below"  , LINELENGTH );
    cout << endl;
    //print( LEFT  , "Connect activities Database here and display them in a list"  , LINELENGTH );

    for(int i=0; i<activities.size(); i++){
        vector<string> activity= activities[i];
        cout << "Activity: " << activity[0] << endl;
        cout << "Date: " << activity[1] << endl;
        cout << "Time: " << activity[2] << endl;
        cout << "Description: " << activity[3] << endl << endl;
    }


    cout << "0) Return to Homepage" << endl << "X) End Program" << endl;
    cout << "Type Answer Here:" ;
    cin >> response;
    cout << header << '\n';
    return response;
}