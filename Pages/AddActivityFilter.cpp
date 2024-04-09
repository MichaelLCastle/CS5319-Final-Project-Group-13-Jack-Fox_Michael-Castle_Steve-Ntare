//
// Created by Michael Ramenofsky on 4/9/24.
//

#include "AddActivityFilter.h"


void AddActivityFilter(database db){
    string name;
    string date;
    string time;
    string description;

    cout << "Activity name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);  // This replaces cin >> response;
    cout << "Activity date: ";
    getline(cin, date);
    cout << "Activity time: ";
    getline(cin, time);
    cout << "Activity description: ";
    getline(cin, description);

    db.add_activity(name, date, time, description);

    Admin_Pipe(db);
}