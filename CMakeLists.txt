cmake_minimum_required(VERSION 3.21)
project(Final_NationalPark)

set(CMAKE_CXX_STANDARD 14)



add_executable(Final_NationalPark main.cpp nlohmann/json.hpp Pages/HomeScreen.h Pages/print.h Pages/HomeScreen.cpp Pages/print.cpp Pages/BasicParkInformationPage.cpp Pages/BasicParkInformationPage.h
        Pages/WeatherPage.cpp Pages/WeatherPage.h Pages/MapsGuidesPage.cpp Pages/MapsGuidesPage.h Pages/ActivitiesPage.cpp Pages/ActivitiesPage.h
        Pages/AIHelperPage.cpp Pages/AIHelperPage.h Pages/FeedbackPage.cpp Pages/FeedbackPage.h Pages/AdminPage.cpp Pages/AdminPage.h
        database.h database.cpp activities.csv feedback.csv info.csv login.csv news.csv )

include(FetchContent)
FetchContent_Declare(
        json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.10.5 # Specify the version you want
)

FetchContent_MakeAvailable(json)


# Find the CURL library (requires FindCURL.cmake which is usually included with CMake)
find_package(CURL REQUIRED)

# Link against the CURL library
#target_link_libraries(Final_NationalPark ${CURL_LIBRARIES} ${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(Final_NationalPark PRIVATE ${CURL_LIBRARIES} nlohmann_json::nlohmann_json)
# Include CURL include directories
include_directories(${CURL_INCLUDE_DIRS})