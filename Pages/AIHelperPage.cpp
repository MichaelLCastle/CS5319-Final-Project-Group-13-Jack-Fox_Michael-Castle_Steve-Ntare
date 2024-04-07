//
// Created by Michael Ramenofsky on 3/30/24.
//

#include "AIHelperPage.h"



string AIHelperPage(){
    string response;
    const int LINELENGTH = 100;
    string header(LINELENGTH, '=');
    cout << header << '\n';
    print( CENTER  , "Red Rock AI Helper!"  , LINELENGTH );
    cout << endl;
    print( CENTER  , "Ask a Question Below"  , LINELENGTH );
    cout << endl;
    cout << "0) Return to Homepage" << endl << "X) To End Program" << endl << "Or Enter your Question Here!:";
    cin >> response;

    if(response != "X" && response != "0"){
        // add code to connect CHATGPT API here database here
        cout << "Thank you for your Question" << endl;
        response = "0";
    }

    cout << header << '\n';
    return response;
}
