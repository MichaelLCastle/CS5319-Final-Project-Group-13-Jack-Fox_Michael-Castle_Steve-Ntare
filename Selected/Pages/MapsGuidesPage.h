//
// Created by Michael Ramenofsky on 3/30/24.
//

#ifndef SEMESTERPROJECT_MAPSGUIDESPAGE_H
#define SEMESTERPROJECT_MAPSGUIDESPAGE_H
#include <iostream>
#include <iomanip>
#include "print.h"
#include <vector>


std::vector<std::string> generateOSMUrls(double baseLat, double baseLon, int zoom, double latIncrement, double lonIncrement, int steps);
std::string constructOSMUrl(double lat, double lon, int zoom);
std::string MapsGuidesPage();

#endif //SEMESTERPROJECT_MAPSGUIDESPAGE_H
