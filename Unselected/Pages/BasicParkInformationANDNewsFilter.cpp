//
// Created by Michael Ramenofsky on 3/30/24.
//

#include "BasicParkInformationANDNewsFilter.h"

string BasicParkInformationANDNewsFilter(database& db){
    //added news here
    vector<string> news= db.get_news();
    vector<string> info= db.get_info();
    string response;

    const int LINELENGTH = 100;
    string header(LINELENGTH, '=');
    cout << header << '\n';
    print( CENTER  , "Red Rock Basic Information!"  , LINELENGTH );
    cout << endl;
    print( CENTER  , "The Visitor Center is open daily from: "+info[0]  , LINELENGTH );
    cout << endl;
    print( LEFT  , "The Scenic Drive is open every day of the year with hours changing slightly according to the season:"  , LINELENGTH );
    print( LEFT  , "Nov – Feb – 6:00 AM to 5:00 PM"  , LINELENGTH );
    print( LEFT  , "March – 6:00 AM to 7:00 PM"  , LINELENGTH );
    print( LEFT  , "Apr – Sep – 6:00 AM to 8:00 PM"  , LINELENGTH );
    print( LEFT  , "Oct – 6:00 AM to 7:00 PM"  , LINELENGTH );
    cout << endl;
    print( LEFT  , "Phone: "+info[1]  , LINELENGTH );
    cout << endl;
    print( LEFT  , "Address: "+info[2]  , LINELENGTH );
    cout << endl;

    //addition of news
    print( CENTER  , "TODAY'S NEWS:"  , LINELENGTH );

    for(int i=0; i<news.size(); i++){
        cout << news[i] << "... ";
    }
    cout << endl << endl;

    User_Pipe(db);

//    cout << "0) Return to Homepage" << endl << "X) End Program" << endl;
//    cout << "Type Answer Here:" ;
//    cin >> response;
//    cout << header << '\n';
//
//    return response;
}
