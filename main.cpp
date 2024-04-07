//
// Created by Michael Ramenofsky on 3/3/24.
//

#include "Pages/HomeScreen.h"
#include "Pages/print.h"
#include "Pages/BasicParkInformationPage.h"
#include "Pages/WeatherPage.h"
#include "Pages/MapsGuidesPage.h"
#include "Pages/ActivitiesPage.h"
#include "Pages/AIHelperPage.h"
#include "Pages/FeedbackPage.h"
#include "Pages/AdminPage.h"

//#include <iostream>
#include <iomanip>
//#include "ostream"
#include <chrono>
#include <thread>
#include "database.h"



int main(){

    string FirstResponse;

    database db;

    db.load_tables();

    int AdminUser = Authentication(db);
    if (AdminUser == 0){
        FirstResponse = HomeScreen(db);
    }else if(AdminUser == 1){
        AdminPage(db);
        FirstResponse= "X";
    }


    while (FirstResponse != "X") {
        if (FirstResponse == "1") {
            FirstResponse = BasicParkInformationPage(db);
        } else if (FirstResponse == "2") {
            FirstResponse = WeatherPage();
        } else if (FirstResponse == "3") {
            FirstResponse = MapsGuidesPage();
        } else if (FirstResponse == "4") {
            FirstResponse = ActivitiesPage(db);
        } else if (FirstResponse == "5") {
            FirstResponse = AIHelperPage();
        } else if (FirstResponse == "6") {
            FirstResponse = FeedbackPage(db);
        } else if (FirstResponse == "0") {
            FirstResponse = HomeScreen(db);
        } else {
            cout << "Not Valid Response. Please Try again" << endl;
            this_thread::sleep_for(std::chrono::seconds(10));
            FirstResponse = HomeScreen(db);
        }
    }

    db.save_tables();

}