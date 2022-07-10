#include "pch.h"
#include "../pm.dal/projectStore.h"
#include "../pm.dal/taskStore.h"
#include"../pm.dal/userStore.h"
#include<fstream>
#include<string>
#include<vector>
#include <sstream>
#include "../pm.dal/teamStore.h"
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
			file << projects[i].title << ',';
			file << projects[i].createdOn << ',';
			file << projects[i].idOfCreator << ',';
			file << projects[i].lastChange << ',';
			file << projects[i].idOfUserChange << endl;
			file << projects[i].description << endl;
			for (size_t j = 0; j < projects[i].idOfTeams.size(); j++)
			{
				if (j == projects[i].idOfTeams.size() - 1)
				{
					file1 << projects[i].idOfTeams[j] << ',';
				}
				else
				{
					file1 << projects[i].idOfTeams[j] << endl;
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
	string row;
	string idOfTeams;
	int n = 0;
	if (file.is_open())
	{
		for (size_t i = 0; getline(file, row); i++)
		{
			if (i % 2 == 0)
			{
				vector<string> teamField;
				stringstream ss(row);
				while (getline(ss, str1, ','))
				{
					teamField.push_back(str1);
				}
				project.id = size_t(stoi(teamField[0]));
				project.title = teamField[1];
				project.createdOn = time_t(stoi(teamField[2]));
				project.idOfCreator = size_t(stoi(teamField[3]));
				project.lastChange = time_t(stoi(teamField[4]));
				project.idOfUserChange = size_t(stoi(teamField[5]));
			}
			else
			{
				project.description = row;
				projects.push_back(project);
			}
		}
		for (size_t i = 0; getline(file1, idOfTeams); i++)
		{
			stringstream ss1(idOfTeams);
			while (getline(ss1, str1, ','))
			{
				projects[i].idOfTeams.push_back(stoi(str1));
			}
		}
	}
	file.close();
	return projects;
}

pm::type::Project pm::dal::ProjectStore::create(std::vector<pm::type::Project> projects, size_t idOfCreator)
{
	pm::type::Project project;
	ofstream file("projects.txt", ios::app);
	if (file.is_open())
	{
		project.id = generateNewId(projects);
		cout << "Title:";
		cin >> project.title;
		cout << "Description of project" << endl;
		cin.ignore();
		getline(cin, project.description);
		project.createdOn = time(NULL);
		project.idOfCreator = idOfCreator;
		project.lastChange = time(NULL);
		project.idOfUserChange = idOfCreator;

		file << project.id << ',';
		file << project.title << ',';
		file << project.createdOn << ',';
		file << project.idOfCreator << ',';
		file << project.lastChange << ',';
		file << project.idOfUserChange << endl;
		file << project.description << endl;
	}
	file.close();
	return project;
}

vector<pm::type::Project> pm::dal::ProjectStore::remove(std::vector<pm::type::Project> projects, size_t idOfUser, size_t idOfProject)
{
	pm::dal::ProjectStore projectFunc;
	ofstream file("projects.txt", ios::trunc);
	ofstream file1("teamsInTheProjects.txt", ios::trunc);

	int numberOfAddedRows = 0;
	if (file.is_open())
	{
		for (size_t i = 0; i < projects.size(); i++)
		{
			if (projects[i].id != idOfProject)
			{
				file << projects[i].id << ',';
				file << projects[i].title << ',';
				file << projects[i].createdOn << ',';
				file << projects[i].idOfCreator << ',';
				file << projects[i].lastChange << ',';
				file << projects[i].idOfUserChange << endl;
				file << projects[i].description << endl;
				for (size_t j = 0; j < projects[i].idOfTeams.size(); j++)
				{
					if (j == projects[i].idOfTeams.size() - 1)
					{
						file1 << projects[i].idOfTeams[j] << ',';
					}
					else
					{
						file1 << projects[i].idOfTeams[j] << endl;
					}
				}
				numberOfAddedRows++;
			}
			else
			{
				if (projects[i].idOfCreator != idOfUser)
				{
					file << projects[i].id << ',';
					file << projects[i].title << ',';
					file << projects[i].createdOn << ',';
					file << projects[i].idOfCreator << ',';
					file << projects[i].lastChange << ',';
					file << projects[i].idOfUserChange << endl;
					file << projects[i].description << endl;
					for (size_t j = 0; j < projects[i].idOfTeams.size(); j++)
					{
						if (j == projects[i].idOfTeams.size() - 1)
						{
							file1 << projects[i].idOfTeams[j] << ',';
						}
						else
						{
							file1 << projects[i].idOfTeams[j] << endl;
						}
					}
					numberOfAddedRows++;
				}
			}
		}
	}
	file.close();
	if (numberOfAddedRows == projects.size())
	{
		cout << "Sorry! You aren't able to delete this project";
	}
	else
	{
		projects = projectFunc.getAll();
	}
	return projects;
}

void pm::dal::ProjectStore::update(std::vector<pm::type::Project>& projects, size_t idOfUser, size_t idOfProject)
{
	pm::dal::ProjectStore projectFunc;
	size_t indexOfProject = projectFunc.getById(projects, idOfProject);
	if (projects[indexOfProject].idOfCreator == idOfUser)
	{
		cout << "New title of project: ";
		std::cin >> projects[indexOfProject].title;
		cout << "New description:" << endl;
		cin.ignore();
		getline(cin, projects[indexOfProject].description);
		projects[indexOfProject].lastChange = time(NULL);
	}
	else
	{
		cout << "Sorry! You aren't able to edit this project";
		return;
	}
	toFile(projects);
	projects = projectFunc.getAll();
}

void pm::dal::ProjectStore::displayProjects(std::vector<pm::type::Project> projects, pm::type::User currentUser, vector<pm::type::Team> teams, bool ownOrNot)
{
	pm::dal::TeamStore teamFunc;
	cout << "Created by me: " << endl;
	for (size_t i = 0; i < projects.size(); i++)
	{
		if (projects[i].idOfCreator == currentUser.id)
		{
			cout << projects[i].id << ". " << projects[i].title << endl;
		}
	}
	cout << endl;

	cout << "Projects which you are assigned: " << endl;
	if (ownOrNot)
	{
		for (size_t i = 0; i < projects.size(); i++)
		{
			for (size_t j = 0; j < projects[i].idOfTeams.size(); j++)
			{
				size_t index = teamFunc.getById(teams, projects[i].idOfTeams[j]);
				for (size_t k = 0; k < teams[index].idOfUsers.size(); k++)
				{
					if (teams[index].idOfUsers[k] == currentUser.id && projects[i].idOfCreator != currentUser.id)
					{
						cout << projects[i].id << ". " << projects[i].title << endl;
					}
				}
			}
		}
		cout << endl;
	}
	else
	{
		cout << endl;
	}
}

void pm::dal::ProjectStore::displayProject(pm::type::Project project, vector<pm::type::User> users)
{
	pm::dal::TeamStore teamFunc;
	pm::dal::UserStore userFunc;
	pm::type::User creator = userFunc.getById(users, project.idOfCreator);
	pm::type::User lastChanger = userFunc.getById(users, project.idOfUserChange);
	cout << "Title: " << project.title << endl;
	cout << "Description: " << project.description << endl;

	cout << "Created by: " << creator.firstName << " " << creator.lastName << endl;
	cout << "Created on: " << project.createdOn << endl;

	cout << "Last changed on: " << lastChanger.firstName << " " << lastChanger.lastName << endl;
	cout << "Last changed by: " << project.lastChange << endl << endl;
}

void pm::dal::ProjectStore::asignToTeam(std::vector<pm::type::Project>& projects, size_t indexOfProject, size_t indexOfTeam, vector<pm::type::Team> teams)
{
	ofstream file("teamsInTheProjects.txt", ios::trunc);
	if (file.is_open())
	{
		projects[indexOfProject].idOfTeams.push_back(teams[indexOfTeam].id);
		for (size_t i = 0; i < projects.size(); i++)
		{
			for (size_t j = 0; j < projects[i].idOfTeams.size(); j++)
			{
				if (j != projects[i].idOfTeams.size() - 1)
				{
					file << projects[i].idOfTeams[j] << ',';
				}
				else
				{
					file << projects[i].idOfTeams[j] << endl;
				}
			}
		}
	}
	file.close();
	return;
}

size_t pm::dal::ProjectStore::getById(vector<pm::type::Project> projects, size_t ifOfProject)
{
	for (size_t i = 0; i < projects.size(); i++)
	{
		if (projects[i].id == ifOfProject)
		{
			return i;
		}
	}
}

size_t pm::dal::ProjectStore::getByTitle(std::vector<pm::type::Project> projects, std::string titleOfTeam)
{
	for (size_t i = 0; i < projects.size(); i++)
	{
		if (projects[i].title == titleOfTeam)
		{
			return i;
		}
	}
}

bool pm::dal::ProjectStore::checkId(std::vector<pm::type::Project> projects, size_t idOfProject)
{
	for (size_t i = 0; i < projects.size(); i++)
	{
		if (projects[i].id == idOfProject)
		{
			return true;
		}
	}
	return false;
}

bool pm::dal::ProjectStore::checkForAdded(pm::type::Project project, size_t idOfTeam)
{
	for (size_t i = 0; i < project.idOfTeams.size(); i++)
	{
		if (project.idOfTeams[i] == idOfTeam)
		{
			return true;
		}
	}
	return false;
}