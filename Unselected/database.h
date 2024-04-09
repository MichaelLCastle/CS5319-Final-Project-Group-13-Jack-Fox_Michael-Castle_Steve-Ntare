//
// Created by Jack Fox on 4/4/24.
//

#include <string>
#include <vector>

#ifndef SEMESTERPROJECT_DATABASE_H
#define SEMESTERPROJECT_DATABASE_H

using namespace std;


class database {
private:
    // File Paths
    string login_file_path= "login.csv";
    string activities_file_path= "activities.csv";
    string feedback_file_path= "feedback.csv";
    string info_file_path= "info.csv";
    string news_file_path= "news.csv";

    // Table Data
    vector<vector<string>> login_table;
    vector<vector<string>> activities_table;
    vector<vector<string>> feedback_table;
    vector<string> info_table;
    vector<string> news_table;

public:
    // Loading Functions
    void load_tables();
    void load_login_table();
    void load_activities_table();
    void load_feedback_table();
    void load_info_table();
    void load_news_table();

    // Saving Functions
    void save_tables();
    void save_login_table();
    void save_activities_table();
    void save_feedback_table();
    void save_info_table();
    void save_news_table();

    // Login Functions
    void add_user(string, string);
    bool login_attempt(const string, const string);

    // Activities Functions
    vector<string> get_newest_activity();
    void add_activity(string, string, string, string);

    // Feedback Functions
    vector<vector<string>> get_feedback();
    void add_feedback(string, string);

    // Info Functions
    vector<string> get_info();
    void update_info(string, string, string);

    // News Functions
    vector<string> get_news();
    void add_news(string);

};


#endif //SEMESTERPROJECT_DATABASE_H
