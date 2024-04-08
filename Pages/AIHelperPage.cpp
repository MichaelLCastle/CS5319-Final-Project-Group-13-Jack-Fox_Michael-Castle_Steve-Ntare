//
// Created by Michael Ramenofsky on 3/30/24.
//

#include "AIHelperPage.h"



// Function to handle the response
static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

string callChatGPTAPI(const std::string& prompt) {
    CURL *curl;
    CURLcode res;
    std::string readBuffer;
    std::string postFields = "{\"model\": \"gpt-3.5-turbo\", \"messages\": [{\"role\": \"user\", \"content\": \"" + prompt + "\"}]}";

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if(curl) {
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        headers = curl_slist_append(headers, "Authorization: Bearer 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");  // Replace with your actual API key

        curl_easy_setopt(curl, CURLOPT_URL, "https://api.openai.com/v1/chat/completions");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postFields.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
    }
    curl_global_cleanup();

    return readBuffer;
}


string AIHelperPage(){

    string userQuestion;
    string response;

    const int LINELENGTH = 100;
    string header(LINELENGTH, '=');
    cout << header << '\n';
    print(CENTER, "Red Rock AI Helper!", LINELENGTH);
    cout << endl;
    print(CENTER, "Ask a Question Below", LINELENGTH);
    cout << endl;
    cout << "0) Return to Homepage" << endl << "X) To End Program" << endl << "Or Enter your Question Here!: ";

    // Use getline to read the full line of input
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    getline(cin, userQuestion);  // This replaces cin >> response;

    if(userQuestion != "X" && userQuestion != "0") {
        response = '0';
        string prompt = "Answer the following question in relation to Red Rock National Conservatory in Las Vegas Nevada: " + userQuestion;
        string GPTresponse = callChatGPTAPI(prompt);
        nlohmann::json jsonResponse = nlohmann::json::parse(GPTresponse);
        std::string textResponse = jsonResponse["choices"][0]["message"]["content"];
        cout << "Response from ChatGPT: " << textResponse << endl;
    }else{
        return userQuestion;
    }

    return response;
}
