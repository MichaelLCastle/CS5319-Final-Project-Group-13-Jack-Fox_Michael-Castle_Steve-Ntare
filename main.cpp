//
// Created by Michael Ramenofsky on 3/3/24.
//

#include "Pages/User_Pipe.h"
#include "Pages/Admin_Pipe.h"

//#include <iostream>
#include <iomanip>
//#include "ostream"
#include "database.h"



int main(){

    string FirstResponse;

    database db;

    db.load_tables();

    int AdminUser = Authentication(db);
    if (AdminUser == 0){
        FirstResponse = User_Pipe(db);
    }else if(AdminUser == 1){
        Admin_Pipe(db);
        FirstResponse= "X";
    }


//    while (FirstResponse != "X") {
//        if (FirstResponse == "1") {
//            FirstResponse = BasicParkInformationPage(db);
//        } else if (FirstResponse == "2") {
//            FirstResponse = WeatherPage(db);
//        } else if (FirstResponse == "3") {
//            FirstResponse = MapsGuidesPage(db);
//        } else if (FirstResponse == "4") {
//            FirstResponse = ActivitiesPage(db);
//        } else if (FirstResponse == "5") {
//            FirstResponse = AIHelperPage(db);
//        } else if (FirstResponse == "6") {
//            FirstResponse = FeedbackPage(db);
//        } else if (FirstResponse == "0") {
//            FirstResponse = User_Pipe(db);
//        } else {
//            cout << "Not Valid Response. Please Try again" << endl;
//            this_thread::sleep_for(std::chrono::seconds(10));
//            FirstResponse = User_Pipe(db);
//        }
//    }

//    db.save_tables();

}