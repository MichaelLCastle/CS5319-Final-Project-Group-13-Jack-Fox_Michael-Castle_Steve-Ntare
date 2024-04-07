cmake_minimum_required(VERSION 3.21)
project(SemesterProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(SemesterProject main.cpp Pages/HomeScreen.h Pages/print.h Pages/HomeScreen.cpp Pages/print.cpp Pages/BasicParkInformationPage.cpp Pages/BasicParkInformationPage.h
        Pages/WeatherPage.cpp Pages/WeatherPage.h Pages/MapsGuidesPage.cpp Pages/MapsGuidesPage.h Pages/ActivitiesPage.cpp Pages/ActivitiesPage.h
        Pages/AIHelperPage.cpp Pages/AIHelperPage.h Pages/FeedbackPage.cpp Pages/FeedbackPage.h Pages/AdminPage.cpp Pages/AdminPage.h
        database.h database.cpp activities.csv feedback.csv info.csv login.csv news.csv )
