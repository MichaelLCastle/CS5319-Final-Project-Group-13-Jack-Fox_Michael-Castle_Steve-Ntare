//
// Created by Jack Fox on 4/4/24.
//

#include "database.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>


// ---------- Loading Functions ----------
void database::load_tables() {
    load_login_table();
    load_activities_table();
    load_feedback_table();
    load_info_table();
    load_news_table();
}
void database::load_login_table(){
    ifstream file(login_file_path);
    if(!file.is_open()){
        cout << "unable to open login file" << endl;
    }
    string line;
    while(getline(file, line)){
        vector<string> row;
        stringstream ss(line);
        string cell;
        while(getline(ss, cell, ',')){
            row.push_back(cell);
        }
        login_table.push_back(row);
    }
    file.close();
}
void database::load_activities_table() {
    ifstream file(activities_file_path);
    if(!file.is_open()){
        cout << "unable to open activities file" << endl;
    }
    string line;
    while(getline(file, line)){
        vector<string> row;
        stringstream ss(line);
        string cell;
        while(getline(ss, cell, ',')){
            row.push_back(cell);
        }
        activities_table.push_back(row);
    }
    file.close();
}
void database::load_feedback_table() {
    ifstream file(feedback_file_path);
    if(!file.is_open()){
        cout << "unable to open activities file" << endl;
    }
    string line;
    while(getline(file, line)){
        vector<string> row;
        stringstream ss(line);
        string cell;
        while(getline(ss, cell, ',')){
            row.push_back(cell);
        }
        feedback_table.push_back(row);
    }
    file.close();
}
void database::load_info_table() {
    ifstream file(info_file_path);
    if(!file.is_open()){
        cout << "unable to open feedback file" << endl;
    }
    string line;
    getline(file, line);
    vector<string> row;
    stringstream ss(line);
    string cell;
    while(getline(ss, cell, ',')){
        row.push_back(cell);
    }
    info_table= row;

    file.close();
}
void database::load_news_table() {
    ifstream file(news_file_path);
    if(!file.is_open()){
        cout << "unable to open feedback file" << endl;
    }
    string line;
    vector<string> news_data;
    while(getline(file, line, ',')){
        news_data.push_back(line);
    }
    news_table= news_data;

    file.close();
}

// ---------- Saving Functions ----------
void database::save_tables(){
    save_login_table();
    save_activities_table();
    save_feedback_table();
    save_info_table();
    save_news_table();
}
void database::save_login_table(){
    ofstream file(login_file_path);
    if(!file.is_open()){
        cout << "unable to open login file" << endl;
    }

    for(int i=0; i<login_table.size(); i++){
        vector<string> user= login_table[i];
        for(int j=0; j<user.size(); j++){
            file << user[j] << ",";
        }
        file << "\n";
    }

    file.close();
}
void database::save_activities_table(){
    ofstream file(activities_file_path);
    if(!file.is_open()){
        cout << "unable to open activities file" << endl;
    }

    for(int i=0; i<activities_table.size(); i++){
        vector<string> activity= activities_table[i];
        for(int j=0; j<activity.size(); j++){
            file << activity[j] << ",";
        }
        file << "\n";
    }

    file.close();

}
void database::save_feedback_table(){
    ofstream file(feedback_file_path);
    if(!file.is_open()){
        cout << "unable to open feedback file" << endl;
    }

    for(int i=0; i<feedback_table.size(); i++){
        vector<string> feedback= feedback_table[i];
        for(int j=0; j<feedback.size(); j++){
            file << feedback[j] << ",";
        }
        file << "\n";
    }

    file.close();
}
void database::save_info_table(){
    ofstream file(info_file_path);
    if(!file.is_open()){
        cout << "unable to open activities file" << endl;
    }

    for(int i=0; i<info_table.size(); i++){
        file<< info_table[i] << ",";
    }

    file.close();
}
void database::save_news_table(){
    ofstream file(news_file_path);
    if(!file.is_open()){
        cout << "unable to open news file" << endl;
    }

    for(int i=0; i<news_table.size(); i++){
        file<< news_table[i] << ",";
    }

    file.close();
}

// ---------- Login Functions ----------
void database::add_user(string username, string password){
    vector<string> new_user= {username, password};
    login_table.push_back(new_user);
}
bool database::login_attempt(const string username, const string password) {
    vector<string> user= {username, password};

    if(find(login_table.begin(), login_table.end(), user) != login_table.end()){
        return true;
    }else{
        return false;
    }
}
// ---------- Activities Functions ----------
vector<string> database::get_newest_activity(){
    return activities_table.back();
}
vector<vector<string>> database::get_activities() {
    return activities_table;
}
void database::add_activity(string name, string date, string time, string description){
    vector<string> new_activity= {name, date, time, description};
    activities_table.push_back(new_activity);
}

// ---------- Feedback Functions ----------
vector<vector<string>> database::get_feedback(){
    return feedback_table;
}
void database::add_feedback(string rating, string comment){
    vector<string> new_feedback= {rating, comment};
    feedback_table.push_back(new_feedback);
}

// ---------- Info Functions ----------
vector<string> database::get_info(){
    return info_table;
}
void database::update_info(string hours, string phone, string address){
    vector<string> new_info= {hours, phone, address};
    info_table= new_info;
}

// ---------- News Functions ----------
vector<string> database::get_news(){
    return news_table;
}
void database::add_news(string input){
    news_table.push_back( input);
}