#include "pch.h"
#include "Header.h"
#include<fstream>
#include<string>
#include<vector>
#include <sstream>
using namespace std;


std::vector<pm::type::Team> pm::dal::TeamStore::getAll()
{
    vector<pm::type::Team> teams;
    pm::type::Team team;
    string e;
    string str1;
    ifstream file("teams.txt");
    string line;
    if (file.is_open())
    {
        for (size_t i = 0; getline(file, line); i++)
        {
            vector<string> teamField;
            stringstream ss(line);
            while (getline(ss, str1, ','))
            {
                teamField.push_back(str1);
            }
            team.id = stoi(teamField[0]);
            team.Title = teamField[1];
            team.createdOn = time_t(stoi(teamField[2]));
            team.idOfCreater = size_t(stoi(teamField[3]));
            team.lastChange = time_t(stoi(teamField[4]));
            team.idOfUserChange = size_t(stoi(teamField[5]));
            teams.push_back(team);
        }
    }
    file.close();
    return teams;
}

//pm::type::User pm::dal::TeamStore::create(std::vector<pm::type::Team> teams)
//{
//    
//}
//
//void pm::dal::TeamStore::remove(std::vector<pm::type::Team>* teams, size_t id)
//{
//
//}
//
//void pm::dal::TeamStore::update(pm::type::Team* user)
//{
//
//}
//
//pm::type::User pm::dal::TeamStore::getById(std::vector<pm::type::Team> user, size_t id)
//{
//    
//}
