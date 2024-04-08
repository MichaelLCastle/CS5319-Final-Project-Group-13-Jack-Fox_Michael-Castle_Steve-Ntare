#include "MapsGuidesPage.h"
#include <cmath>
#include <vector>
#include <string>
#include <iostream>

std::string constructOSMUrl(double lat, double lon, int zoom) {
    double n = std::pow(2, zoom);
    int x = static_cast<int>((lon + 180.0) / 360.0 * n);
    int y = static_cast<int>((1.0 - std::log(std::tan(lat * M_PI / 180.0) + 1.0 / std::cos(lat * M_PI / 180.0)) / M_PI) / 2.0 * n);
    return "https://tile.openstreetmap.org/" + std::to_string(zoom) + "/" + std::to_string(x) + "/" + std::to_string(y) + ".png";
}

// Adjusted function to improve map variation
std::vector<std::string> generateOSMUrls(double baseLat, double baseLon, int zoom, double latIncrement, double lonIncrement, int numberOfMaps) {
    std::vector<std::string> urls;
    int sqrtNumMaps = std::ceil(std::sqrt(numberOfMaps)); // Calculate the size of the grid
    int mapCount = 0;

    for (int i = 0; i < sqrtNumMaps && mapCount < numberOfMaps; i++) {
        for (int j = 0; j < sqrtNumMaps && mapCount < numberOfMaps; j++) {
            // Calculate new latitude and longitude
            double currentLat = baseLat + (i - sqrtNumMaps / 2) * latIncrement;
            double currentLon = baseLon + (j - sqrtNumMaps / 2) * lonIncrement;

            urls.push_back(constructOSMUrl(currentLat, currentLon, zoom));
            mapCount++;
        }
    }

    return urls;
}

std::string MapsGuidesPage() {
    std::cout << "Enter the number of maps you would like (1-50): ";
    int numOfMaps;
    std::cin >> numOfMaps;

    if(numOfMaps < 1 || numOfMaps > 50) {
        std::cout << "Invalid number of maps. Please enter a number between 1 and 50." << std::endl;
        return "3"; // Return back to the MapsGuidesPage
    }

    double baseLatitude = 36.1314325;
    double baseLongitude = -115.4215038;
    int zoom = 15;
    double latIncrement = 0.005; // Adjusted for more variation
    double lonIncrement = 0.005; // Adjusted for more variation

    std::vector<std::string> urls = generateOSMUrls(baseLatitude, baseLongitude, zoom, latIncrement, lonIncrement, numOfMaps);

    for (const auto& url : urls) {
        std::cout << url << std::endl;
    }

    //return "0"; // Return to home screen
    string header(100, '=');
    cout << "0) Return to Homepage" << endl << "X) End Program" << endl;
    string response;
    cout << "Type Answer Here: ";
    cin >> response;
    cout << header << '\n';
    return response;
}
