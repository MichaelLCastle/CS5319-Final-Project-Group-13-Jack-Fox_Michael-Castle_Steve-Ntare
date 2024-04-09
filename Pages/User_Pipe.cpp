//
// Created by Michael Ramenofsky on 3/30/24.
//

#include "User_Pipe.h"


string User_Pipe(database db){
    db.save_tables();
    vector<string> news= db.get_news();
    int LENGTH = 0;
//    if(NEWS.length() > 100){
//        LENGTH = NEWS.length();
//    }
//    else{
//        LENGTH = 100;
//    }

    LENGTH= 100;

    const int LINELENGTH = LENGTH;
    string header( LINELENGTH, '=' );


    string FirstResponse;
//    cout << header << '\n';
//    print( CENTER  , "Welcome to Red Rock Canyon National Conservation Area!"  , LINELENGTH );
//    cout << endl;
//    print( CENTER  , "TODAY'S NEWS:"  , LINELENGTH );


//make news display page for all of this code
//    for(int i=0; i<news.size(); i++){
//        cout << news[i] << "... ";
//    }
//    cout << endl;

    cout << endl;
    print( LEFT  , "What can I help you with? Please type one of the following numbers"  , LINELENGTH );
    cout << "1) Basic Park Information" << endl << "2) Weather" << endl << "3) Trail Maps and Guides " << endl << "4) Activities" << endl << "5) AI Helper" << endl << "6) Feedback for us" << endl << "X) End Program" << endl;
    cout << "Type Answer Here:" ;
    cin >> FirstResponse;

    db.save_tables();

    while (FirstResponse != "X" && FirstResponse != "x") {
        if (FirstResponse == "1") {
            FirstResponse = BasicParkInformationANDNewsPipe(db);
        } else if (FirstResponse == "2") {
            FirstResponse = WeatherPipe(db);
        } else if (FirstResponse == "3") {
            FirstResponse = MapsGuidesPipe(db);
        } else if (FirstResponse == "4") {
            FirstResponse = ActivitiesPipe(db);
        } else if (FirstResponse == "5") {
            FirstResponse = AIHelperPipe(db);
        } else if (FirstResponse == "6") {
            FirstResponse = FeedbackPipe(db);
        }else {
            cout << "Not Valid Response. Please Try again" << endl;
            //this_thread::sleep_for(std::chrono::seconds(10));
            FirstResponse = User_Pipe(db);
        }
    }
    std::exit(0);

}
