//
// Created by Michael Ramenofsky on 4/9/24.
//

#include "UpdateNewsFilter.h"

void UpdateNewsFilter(database db){
    string news;

    cout << "Input new news here: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, news);  // This replaces cin >> response;
    db.add_news(news);

    Admin_Pipe(db);

}