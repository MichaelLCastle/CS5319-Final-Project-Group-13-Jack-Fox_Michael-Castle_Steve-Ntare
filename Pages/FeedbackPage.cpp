//
// Created by Michael Ramenofsky on 3/30/24.
//

#include "FeedbackPage.h"


string FeedbackPage(database& db){
    string response;
    string Feedback;
    const int LINELENGTH = 100;
    string header(LINELENGTH, '=');
    cout << header << '\n';
    print( CENTER , "Red Rock Feedback Page!" , LINELENGTH );
    cout << endl;
    print( CENTER , "Provide your feedback below!" , LINELENGTH );
    cout << endl;

    string rating;
    cout << "Please give your experience a rating on a scale from 1-5:";
    cin >> rating;
    string comment;
    cout << "Please leave a brief comment about your experience:";
    cin >> comment;
    cout << endl;

    db.add_feedback(rating, comment);

    // add code to connect Feedback database here

    if(response != "X" && response != "0"){
        // add code to connect Feedback database here
        cout << "Thank you for your feedback" << endl;
        response = "0";
    }
    cout << header << '\n';
    return response;
}