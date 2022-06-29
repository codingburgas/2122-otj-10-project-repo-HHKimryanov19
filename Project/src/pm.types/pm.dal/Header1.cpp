#include "pch.h"
#include "Header1.h"
#include "Header.h"
#include<fstream>
#include<string>
#include<vector>
#include <sstream>
#include "Header2.h"
using namespace std;

size_t generateNewId(vector<pm::type::Project> projects)
{
	size_t maxId = 0;
	for (auto project : projects)
	{
		if (project.id > maxId)
		{
			maxId = project.id;
		}
	}

	return maxId + 1;
}

void toFile(std::vector<pm::type::Project> projects)
{
	ofstream file("projects.txt", ios::trunc);
	ofstream file1("teamsInTheProjects.txt", ios::trunc);
	if (file.is_open() && file1.is_open())
	{
		for (int i = 0; i < projects.size(); i++)
		{
			file << projects[i].id << ',';
			file << projects[i].Title << ',';
			file << projects[i].createdOn << ',';
			file << projects[i].idOfCreator << ',';
			file << projects[i].lastChange << ',';
			file << projects[i].idOfUserChange << endl;
			file << projects[i].Description << endl;
			for (size_t j = 0; j < projects[i].assignedTeams.size(); j++)
			{
				if (j == projects[i].assignedTeams.size() - 1)
				{
					file1 << projects[i].assignedTeams[j].id << ',';
				}
				else
				{
					file1 << projects[i].assignedTeams[j].id << endl;
				}
			}
		}
	}
	file.close();
}

std::vector<pm::type::Project> pm::dal::ProjectStore::getAll()
{
	vector<pm::type::Project> projects;
	pm::type::Project project;
	string str1;
	ifstream file("projects.txt");
	ifstream file1("teamsInTheProjects.txt");
	pm::dal::TeamStore teamFunc;
	string line;
	string line1;
	int n = 0;
	if (file.is_open())
	{
		for (size_t i = 0; getline(file, line); i++)
		{
			if (i % 2 == 0)
			{
				vector<string> teamField;
				stringstream ss(line);
				while (getline(ss, str1, ','))
				{
					teamField.push_back(str1);
				}
				project.id = size_t(stoi(teamField[0]));
				project.Title = teamField[1];
				project.createdOn = time_t(stoi(teamField[2]));
				project.idOfCreator = size_t(stoi(teamField[3]));
				project.lastChange = time_t(stoi(teamField[4]));
				project.idOfUserChange = size_t(stoi(teamField[5]));
			}
			else
			{
				project.Description = line;
				projects.push_back(project);
			}
		}
		for (size_t i = 0; getline(file1, line1); i++)
		{
			stringstream ss1(line1);
			while (getline(ss1, str1, ','))
			{
				projects[i].assignedTeams.push_back(teamFunc.getById(teamFunc.getAll(), stoi(str1)));
			}
		}
	}
	file.close();
	return projects;
}

pm::type::Project pm::dal::ProjectStore::create(std::vector<pm::type::Project> projects,size_t idOfCreator)
{
	pm::type::Project project;
	ofstream file("projects.txt", ios::app);
	if (file.is_open())
	{
		project.id = generateNewId(projects);
		cout << "Title:";
		cin >> project.Title;
		cout << "Description of project" << endl;
		cin.ignore();
		getline(cin, project.Description);
		project.createdOn = time(NULL);
		project.idOfCreator = idOfCreator;
		project.lastChange = time(NULL);
		project.idOfUserChange = idOfCreator;

		file << project.Title << ',';
		file << project.createdOn << ',';
		file << project.idOfCreator << ',';
		file << project.lastChange << ',';
		file << project.idOfUserChange << endl;
		file << project.Description;
	}
	file.close();
	return project;
}

void pm::dal::ProjectStore::remove(std::vector<pm::type::Project>* projects, size_t idOfUser, size_t id)
{
	pm::dal::ProjectStore projectFunc;
	ofstream file("projects.txt", ios::trunc);
	ofstream file1("teamsInTheProjects.txt", ios::trunc);
	
	int n = 0;
	if (file.is_open())
	{
		for (size_t i = 0; i < (*projects).size(); i++)
		{
			if ((*projects)[i].id != id)
			{
				file << (*projects)[i].id << ',';
				file << (*projects)[i].Title << ',';
				file << (*projects)[i].createdOn << ',';
				file << (*projects)[i].idOfCreator << ',';
				file << (*projects)[i].lastChange << ',';
				file << (*projects)[i].idOfUserChange << endl;
				file << (*projects)[i].Description << endl;
				for (size_t j = 0; j < (*projects)[i].assignedTeams.size(); j++)
				{
					if (j == (*projects)[i].assignedTeams.size() - 1)
					{
						file1 << (*projects)[i].assignedTeams[j].id << ',';
					}
					else
					{
						file1 << (*projects)[i].assignedTeams[j].id << endl;
					}
				}
				n++;
			}
			else
			{
				if ((*projects)[i].idOfCreator != idOfUser)
				{
					file << (*projects)[i].id << ',';
					file << (*projects)[i].Title << ',';
					file << (*projects)[i].createdOn << ',';
					file << (*projects)[i].idOfCreator << ',';
					file << (*projects)[i].lastChange << ',';
					file << (*projects)[i].idOfUserChange << endl;
					file << (*projects)[i].Description << endl;
					for (size_t j = 0; j < (*projects)[i].assignedTeams.size(); j++)
					{
						if (j == (*projects)[i].assignedTeams.size() - 1)
						{
							file1 << (*projects)[i].assignedTeams[j].id << ',';
						}
						else
						{
							file1 << (*projects)[i].assignedTeams[j].id << endl;
						}
					}
					n++;
				}
			}
		}
	}
	file.close();
	if (n == (*projects).size())
	{
		cout << "Sorry! You aren't able to edit this project";
	}
	else
	{
		*projects = projectFunc.getAll();
	}
}

void pm::dal::ProjectStore::update(std::vector<pm::type::Project>* projects, size_t idOfUser, size_t id)
{
	for (size_t i = 0; i < (*projects).size(); i++)
	{
		if ((*projects)[i].id == id && (*projects)[i].idOfCreator == idOfUser)
		{
			cout << "New title of project: ";
			std::cin >> (*projects)[i].Title;
			cout << "New description:" << endl;
			cin.ignore();
			getline(cin,(*projects)[i].Description);
			(*projects)[i].lastChange = time(NULL);
		}
		else
		{
			if ((*projects)[i].idOfCreator != idOfUser)
			{
				cout << "Sorry! You aren't able to edit this project";
				return;
			}
		}
	}
	pm::dal::ProjectStore projectFunc;
	toFile(*projects);
	(*projects) = projectFunc.getAll();
}

void pm::dal::ProjectStore::displayProjects(std::vector<pm::type::Project> projects,pm::type::User currentUser)
{
	for (size_t i = 0; i < projects.size(); i++)
	{
		if (projects[i].idOfCreator == currentUser.id)
		{
			cout << "Title: " << projects[i].Title << endl;
			cout << "Description: " << projects[i].Description << endl << endl;
		}
	}
	for (size_t i = 0; i < projects.size(); i++)
	{
		for (size_t j = 0; j < projects[i].assignedTeams.size(); j++)
		{
			for (size_t k = 0; k < projects[i].assignedTeams[j].assignedUser.size(); k++)
			{
				if (projects[i].assignedTeams[j].assignedUser[k].id == currentUser.id)
				{
					cout << "Title: " << projects[i].Title << endl;
					cout << "Description: " << projects[i].Description << endl << endl;
				}
			}
		}
	}
}



 void pm::dal::ProjectStore::asignToTeam(std::vector<pm::type::Project>* projects, pm::type::Project* project, pm::type::Team team)
{
	ofstream file("teamsInTheProjects.txt", ios::trunc);
	int n = 0;
	if (file.is_open())
	{
		(*project).idOfTeams.push_back(team.id);
		for (size_t i = 0; i < (*projects).size(); i++)
		{
			for (size_t j = 0; j < (*projects)[i].idOfTeams.size(); j++)
			{
				if (j != (*projects)[i].idOfTeams.size() - 1)
				{
					file << (*projects)[i].idOfTeams[j] << ',';
				}
				else
				{
					file << (*projects)[i].idOfTeams[j] << endl;
				}
			}
		}
	}
	file.close();
	return;
}
