//
// Created by Michael Ramenofsky on 3/30/24.
//

#ifndef SEMESTERPROJECT_AIHELPERPAGE_H
#define SEMESTERPROJECT_AIHELPERPAGE_H
#include <iostream>
#include <iomanip>
#include "print.h"
#include <curl/curl.h>
#include <string>
#include <nlohmann/json.hpp>
#include "User_Pipe.h"


using namespace std;


static size_t WriteCallbackAI(void *contents, size_t size, size_t nmemb, void *userp);

string callChatGPTAPI(const std::string& prompt);

string AIHelperPage(database);



#endif //SEMESTERPROJECT_AIHELPERPAGE_H
