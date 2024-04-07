//
// Created by Michael Ramenofsky on 3/30/24.
//

#include "WeatherPage.h"

string WeatherPage(){
    string response;
    const int LINELENGTH = 100;
    string header(LINELENGTH, '=');
    cout << header << '\n';
    print( CENTER  , "Red Rock Weather Today!"  , LINELENGTH );
    cout << endl;
    print( CENTER  , "Today's Weather!"  , LINELENGTH );
    cout << endl;
    print( LEFT  , "Connect API here to Display weather"  , LINELENGTH );
    cout << endl;
    cout << "0) Return to Homepage" << endl << "X) End Program" << endl;
    cout << "Type Answer Here:" ;
    cin >> response;
    cout << header << '\n';
    return response;
}
