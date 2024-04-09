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


add_executable(Final_NationalPark main.cpp Pages/User_Pipe.h Pages/print.h Pages/User_Pipe.cpp Pages/print.cpp Pages/BasicParkInformationPage.cpp
        Pages/BasicParkInformationPage.h Pages/WeatherPage.cpp Pages/WeatherPage.h Pages/MapsGuidesPage.cpp Pages/MapsGuidesPage.h Pages/ActivitiesPage.cpp Pages/ActivitiesPage.h
        Pages/AIHelperPage.cpp Pages/AIHelperPage.h Pages/FeedbackPage.cpp Pages/FeedbackPage.h Pages/Admin_Pipe.cpp Pages/Admin_Pipe.h
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


target_link_libraries(Final_NationalPark PRIVATE ${CURL_LIBRARIES} nlohmann_json::nlohmann_json)
# Include CURL include directories
include_directories(${CURL_INCLUDE_DIRS})

# Link libcurl
target_link_libraries(${PROJECT_NAME} PRIVATE ${CURL_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CURL_INCLUDE_DIRS})

# Link nlohmann/json
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)

