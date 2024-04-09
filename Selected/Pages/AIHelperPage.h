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
#include "nlohmann/json.hpp"


using namespace std;

string AIHelperPage();

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);

string callChatGPTAPI(const std::string& prompt);



#endif //SEMESTERPROJECT_AIHELPERPAGE_H
