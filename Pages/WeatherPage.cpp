#include "WeatherPage.h"
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <iostream>
#include <string>

using json = nlohmann::json;
using namespace std;

// Helper function for libcurl to append fetched data into a string
static size_t WriteCallback(void *contents, size_t size, size_t nmemb, std::string *data) {
    data->append((char*)contents, size * nmemb);
    return size * nmemb;
}

// Function to make API call to OpenWeather and fetch weather data using geographic coordinates
std::string fetchWeatherData() {
    CURL *curl;
    std::string readBuffer;
    curl = curl_easy_init();

    if(curl) {
        std::string apiKey = "ff5f6d7b905e9321db8a331db0681221";
        // Using coordinates for Red Rock Canyon National Park
        std::string requestURL = "http://api.openweathermap.org/data/2.5/weather?lat=36.1324&lon=-115.4275&appid=" + apiKey + "&units=imperial";

        curl_easy_setopt(curl, CURLOPT_URL, requestURL.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        CURLcode res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if(res != CURLE_OK) {
            cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
            return "{}"; // Return empty JSON on error
        }
    }
    return readBuffer;
}

// WeatherPage function to display weather using OpenWeather API
string WeatherPage() {
    const int LINELENGTH = 100;
    string header(LINELENGTH, '=');
    cout << header << '\n';
    print(CENTER, "Red Rock Weather Today!", LINELENGTH);
    cout << endl;

    // Fetch and parse weather data using geographic coordinates
    string weatherDataJson = fetchWeatherData();
    auto weatherData = json::parse(weatherDataJson, nullptr, false); // Use nothrow parse

    if (weatherData.is_discarded()) {
        cout << "Failed to parse weather data." << endl;
    } else {
        // Extracting temperature (in Fahrenheit) and weather condition from the response
        double temp = weatherData["main"]["temp"];
        string description = weatherData["weather"][0]["description"];

        cout << "Temperature: " << temp << "°F" << endl;
        cout << "Condition: " << description << endl;
    }

    cout << "0) Return to Homepage" << endl << "X) End Program" << endl;
    string response;
    cout << "Type Answer Here: ";
    cin >> response;
    cout << header << '\n';
    return response;
}
