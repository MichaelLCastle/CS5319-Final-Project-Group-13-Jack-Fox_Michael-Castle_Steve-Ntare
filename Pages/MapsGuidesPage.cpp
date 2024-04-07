//
// Created by Michael Ramenofsky on 3/30/24.
//

#include "MapsGuidesPage.h"

string MapsGuidesPage(){
    string response;
    const int LINELENGTH = 100;
    string header(LINELENGTH, '=');
    cout << header << '\n';
    print( CENTER  , "Red Rock Trail Maps and Guides!"  , LINELENGTH );
    cout << endl;
    print( CENTER  , "Red Rock Scenic Loop Map"  , LINELENGTH );
    cout << endl;
    print( LEFT  , "Connect API and Map server here to display map"  , LINELENGTH );
    cout << endl;
    cout << "0) Return to Homepage" << endl << "X) End Program" << endl;
    cout << "Type Answer Here:" ;
    cin >> response;
    cout << header << '\n';
    return response;
}
