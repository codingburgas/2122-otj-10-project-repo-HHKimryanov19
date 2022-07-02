#include "pch.h"
#include "Header.h"
#include "UserStore.h"
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

void toFile(std::vector<pm::type::Team> teams)
{
	ofstream file("teams.txt", ios::trunc);
	for (int i = 0; i < teams.size(); i++)
	{
		file << teams[i].id << ',';
		file << teams[i].Title << ',';
		file << teams[i].createdOn << ',';
		file << teams[i].idOfCreator << ',';
		file << teams[i].lastChange << ',';
		file << teams[i].idOfUserChange << endl;
	}
	file.close();
}

std::vector<pm::type::Team> pm::dal::TeamStore::getAll()
{
	vector<pm::type::Team> teams;
	pm::type::Team team;
	string str1;
	ifstream file("teams.txt");
	ifstream file1("usersInTheTeams.txt");
	string line;
	string line1;
	pm::dal::UserStore userFunc;
	if (file.is_open() && file1.is_open())
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
			team.idOfCreator = size_t(stoi(teamField[3]));
			team.lastChange = time_t(stoi(teamField[4]));
			team.idOfUserChange = size_t(stoi(teamField[5]));
			teams.push_back(team);
		}
		for (size_t i = 0; getline(file1, line1); i++)
		{
			stringstream ss1(line1);
			while (getline(ss1, str1, ','))
			{
				teams[i].idOfUsers.push_back(stoi(str1));
			}
		}
	}
	file.close();
	file1.close();
	return teams;
}

vector<pm::type::Team> pm::dal::TeamStore::create(std::vector<pm::type::Team> teams, pm::type::User currentUser)
{
	pm::type::Team team;
	ofstream file("teams.txt", ios::app);
	team.id = generateNewId(teams);
	if (file.is_open())
	{
		cout << "Title: ";
		cin >> team.Title;
		team.createdOn = time(NULL);
		team.idOfCreator = currentUser.id;
		team.lastChange = time(NULL);
		team.idOfUserChange = currentUser.id;

		file << team.id << ',';
		file << team.Title << ',';
		file << team.createdOn << ',';
		file << team.idOfCreator << ',';
		file << team.lastChange << ',';
		file << team.idOfUserChange << endl;
	}
	file.close();
	teams.push_back(team);
	return teams;
}
vector<pm::type::Team> pm::dal::TeamStore::remove(std::vector<pm::type::Team> teams, size_t id)
{
	pm::dal::TeamStore teamsFunc;
	ofstream file("teams.txt", ios::trunc);
	ofstream file1("usersInTheTeams.txt", ios::trunc);

	if (file.is_open() && file1.is_open())
	{
		for (size_t i = 0; i < teams.size(); i++)
		{
			if (teams[i].id != id)
			{
				file << teams[i].id << ',';
				file << teams[i].Title << ',';
				file << teams[i].createdOn << ',';
				file << teams[i].idOfCreator << ',';
				file << teams[i].lastChange << ',';
				file << teams[i].idOfUserChange << endl;
				for (size_t j = 0; j < teams[i].idOfUsers.size(); j++)
				{
					if (j == teams[i].idOfUsers.size() - 1)
					{
						file1 << teams[i].idOfUsers[j] << ',';
					}
					else
					{
						file1 << teams[i].idOfUsers[j] << endl;
					}
				}
			}
		}
	}
	file.close();
	file1.close();
	teams = teamsFunc.getAll();
	return teams;
}

std::vector<pm::type::Team> pm::dal::TeamStore::update(vector<pm::type::Team> teams,size_t indexOfTeam, size_t currentUserId)
{
	cout << "New title: ";
	cin >> teams[indexOfTeam].Title;
	teams[indexOfTeam].idOfUserChange = currentUserId;
	teams[indexOfTeam].lastChange = time(NULL);
	toFile(teams);
	return teams;
}

void pm::dal::TeamStore::displayTeams(vector<pm::type::Team> teams)
{
	for (int i = 0; i < teams.size(); i++)
	{
		cout << teams[i].id << ". " << teams[i].Title << endl;
	}
}

vector<pm::type::Team> pm::dal::TeamStore::asignToTeam(std::vector< pm::type::Team> teams,size_t indexOfTeam, size_t idOfUser)
{
	ofstream file("usersInTheTeams.txt", ios::trunc);
	int n = 0;
	if (file.is_open())
	{
		teams[indexOfTeam].idOfUsers.push_back(idOfUser);
		for (size_t i = 0; i < teams.size(); i++)
		{
			for (size_t j = 0; j < teams[i].idOfUsers.size(); j++)
			{
				if (j != teams[i].idOfUsers.size() - 1)
				{
					file << teams[i].idOfUsers[j] << ',';
				}
				else
				{
					file << teams[i].idOfUsers[j] << endl;
				}
			}
		}
	}
	file.close();
	return teams;
}

size_t pm::dal::TeamStore::getById(std::vector<pm::type::Team> teams, size_t id)
{
	for (size_t i = 0; i < teams.size(); i++)
	{
		if (teams[i].id == id)
		{
			return i;
		}
	}
}
