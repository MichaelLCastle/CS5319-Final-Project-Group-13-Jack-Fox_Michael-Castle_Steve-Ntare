//
// Created by Michael Ramenofsky on 4/9/24.
//

#include "ReviewFeebackFilter.h"


void ReviewFeedbackFilter(database db){

    vector<vector<string>> feedback= db.get_feedback();

    cout << endl;
    for(int i=0; i<feedback.size(); i++){
        cout << "Rating: " << feedback[i][0] << endl;

        cout << "Comment: " << feedback[i][1] << endl << endl;
    }

    Admin_Pipe(db);

}