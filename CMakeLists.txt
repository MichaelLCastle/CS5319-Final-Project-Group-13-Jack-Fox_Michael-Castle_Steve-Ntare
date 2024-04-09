cmake_minimum_required(VERSION 3.21)
project(Final_NationalPark)

set(CMAKE_CXX_STANDARD 14)





# Find package for libcurl
find_package(CURL REQUIRED)

# Include nlohmann/json via FetchContent
include(FetchContent)
FetchContent_Declare(
        json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.10.5 # Specify the version you want
)
FetchContent_MakeAvailable(json)


add_executable(Final_NationalPark Selected/main.cpp Selected/Pages/HomeScreen.h Selected/Pages/print.h Selected/Pages/HomeScreen.cpp Selected/Pages/print.cpp Selected/Pages/BasicParkInformationPage.cpp
        Selected/Pages/BasicParkInformationPage.h Selected/Pages/WeatherPage.cpp Selected/Pages/WeatherPage.h Selected/Pages/MapsGuidesPage.cpp Selected/Pages/MapsGuidesPage.h Selected/Pages/ActivitiesPage.cpp Selected/Pages/ActivitiesPage.h
        Selected/Pages/AIHelperPage.cpp Selected/Pages/AIHelperPage.h Selected/Pages/FeedbackPage.cpp Selected/Pages/FeedbackPage.h Selected/Pages/AdminPage.cpp Selected/Pages/AdminPage.h
        Selected/database.h Selected/database.cpp activities.csv feedback.csv info.csv login.csv news.csv )


include(FetchContent)
FetchContent_Declare(
        json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.10.5 # Specify the version you want
)

FetchContent_MakeAvailable(json)


# Find the CURL library (requires FindCURL.cmake which is usually included with CMake)
find_package(CURL REQUIRED)


target_link_libraries(Final_NationalPark PRIVATE ${CURL_LIBRARIES} nlohmann_json::nlohmann_json)
# Include CURL include directories
include_directories(${CURL_INCLUDE_DIRS})

# Link libcurl
target_link_libraries(${PROJECT_NAME} PRIVATE ${CURL_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CURL_INCLUDE_DIRS})

# Link nlohmann/json
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)

