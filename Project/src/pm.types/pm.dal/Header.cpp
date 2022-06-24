#include "pch.h"
#include "Header.h"
#include<fstream>
#include<string>
#include<vector>
#include <sstream>
using namespace std;

size_t generateNewId(vector<pm::type::Team> teams)
{
	size_t maxId = 0;
	for (auto team : teams)
	{
		if (team.id > maxId)
		{
			maxId = team.id;
		}
	}

	return maxId + 1;
}

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

pm::type::Team pm::dal::TeamStore::create(std::vector<pm::type::Team> teams, pm::type::User currentUser)
{
	pm::type::Team team;
	ofstream file("teams.txt", ios::app);
	team.id = generateNewId(teams);
	if (file.is_open())
	{
		cout << "Title: ";
		cin >> team.Title;
		team.createdOn = time(NULL);
		team.idOfCreater = currentUser.id;
		team.lastChange = time(NULL);
		team.idOfUserChange = currentUser.id;

		file << team.id << ',';
		file << team.Title << ',';
		file << team.createdOn << ',';
		file << team.idOfCreater << ',';
		file << team.lastChange << ',';
		file << team.idOfUserChange << endl;
	}
	file.close();
	return team;
}

void pm::dal::TeamStore::remove(std::vector<pm::type::Team>* teams, size_t id)
{
	ofstream file("teams.txt", ios::trunc);
	if (file.is_open())
	{
		for (size_t i = 0;i<(*teams).size();i++)
		{
			if ((*teams)[i].id != id)
			{
				file << (*teams)[i].id << ',';
				file << (*teams)[i].Title<< ',';
				file << (*teams)[i].createdOn << ',';
				file << (*teams)[i].idOfCreater<< ',';
				file << (*teams)[i].lastChange<< ',';
				file << (*teams)[i].idOfUserChange << endl;
			}
		}
	}
	pm::dal::TeamStore teamsFunc;
	*teams = teamsFunc.getAll();
}

//void pm::dal::TeamStore::update(pm::type::Team* user)
//{
//
//}

//pm::type::User pm::dal::TeamStore::getById(std::vector<pm::type::Team> user, size_t id)
//{
//    
//}
