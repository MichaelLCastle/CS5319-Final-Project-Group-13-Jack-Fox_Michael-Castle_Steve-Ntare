//
// Created by Michael Ramenofsky on 3/3/24.
//

#include "Pages/User_Pipe.h"
#include "Pages/Admin_Pipe.h"
#include "Pages/AuthenticationFilter.h"

//#include <iostream>
#include <iomanip>
//#include "ostream"
#include "database.h"



int main(){

    string FirstResponse;

    database db;

    db.load_tables();

    int AdminUser = AuthenticationPipe(db);
    if (AdminUser == 0){
        FirstResponse = User_Pipe(db);
    }else if(AdminUser == 1){
        Admin_Pipe(db);
        FirstResponse= "X";
    }

}