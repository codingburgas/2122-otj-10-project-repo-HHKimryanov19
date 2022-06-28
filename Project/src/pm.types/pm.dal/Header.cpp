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
			team.idOfCreator = size_t(stoi(teamField[3]));
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
	return team;
}

void pm::dal::TeamStore::remove(std::vector<pm::type::Team>* teams, size_t id)
{
	pm::dal::TeamStore teamsFunc;
	ofstream file("teams.txt", ios::trunc);
	vector<vector<size_t>> v = teamsFunc.usersInTheTeams();
	ofstream file1("usersInTheTeams.txt", ios::trunc);

	if (file.is_open()&&file1.is_open())
	{
		for (size_t i = 0; i < (*teams).size(); i++)
		{
			if ((*teams)[i].id != id)
			{
				file << (*teams)[i].id << ',';
				file << (*teams)[i].Title << ',';
				file << (*teams)[i].createdOn << ',';
				file << (*teams)[i].idOfCreator << ',';
				file << (*teams)[i].lastChange << ',';
				file << (*teams)[i].idOfUserChange << endl;

				for (size_t j = 0; j < v.size(); j++)
				{
					if (j != v.size() - 1)
					{
						file1 << v[i][j]<<',';
					}
					else
					{
						file1 << v[i][j] << endl;
					}
				}
			}
		}
	}
	file.close();
	file1.close();
	*teams = teamsFunc.getAll();
}

void pm::dal::TeamStore::update(pm::type::Team* team, pm::type::User currentUser)
{
	cout << "New title: ";
	cin >> (*team).Title;
	(*team).idOfUserChange = currentUser.id;
	(*team).lastChange = time(NULL);
}

void pm::dal::TeamStore::displayTeams(vector<pm::type::Team> teams)
{
	for (int i = 0; i < teams.size(); i++)
	{
		cout << teams[i].id << ". " << teams[i].Title << endl;
	}
}

vector<vector<size_t>> pm::dal::TeamStore::usersInTheTeams()
{
	vector<vector<size_t>> v;
	vector<size_t> v1;
	ifstream file("usersInTheTeams.txt");
	string str1;
	string line;
	if (file.is_open())
	{
		for (size_t i = 0; getline(file, line); i++)
		{
			vector<size_t> usersId;
			stringstream ss(line);
			while (getline(ss, str1, ','))
			{
				usersId.push_back(size_t(stoi(str1)));
			}
			v.push_back(usersId);
		}
	}
	file.close();
	return v;
}

std::vector<vector<size_t>> pm::dal::TeamStore::asignToTeam(std::vector<pm::type::Team> teams, size_t teamId, size_t userId)
{
	vector<vector<size_t>> v = usersInTheTeams();
	ofstream file("usersInTheTeams.txt", ios::trunc);
	int n = 0;
	if (file.is_open())
	{
		for (size_t i = 0; i < teams.size(); i++)
		{
			if (teams[i].id == teamId)
			{
				for (size_t j = 0; j < v[i].size(); j++)
				{
					if (v[i][j] == userId)
					{
						break;
					}
					else
					{
						n++;
					}
				}
				if (n == v[i].size())
				{
					v[i].push_back(userId);
					for (size_t k = 0; k < teams.size(); k++)
					{
						for (size_t m = 0; m < v[k].size(); m++)
						{
							if (m == v[k].size() - 1)
							{
								file << v[k][m] << endl;
							}
							else
							{
								file << v[k][m] << ",";
							}
						}
					}
					break;
				}
				else
				{
					cout << "This user has already been added";
					for (size_t k = 0; k < teams.size(); k++)
					{
						for (size_t m = 0; m < v[k].size(); m++)
						{
							if (m == v[k].size() - 1)
							{
								file << v[k][m] << endl;
							}
							else
							{
								file << v[k][m] << ",";
							}
						}
					}
					break;
				}
			}
		}

	}
	file.close();
	return v;
}

//pm::type::User pm::dal::TeamStore::getById(std::vector<pm::type::Team> user, size_t id)
//{
//    
//}
