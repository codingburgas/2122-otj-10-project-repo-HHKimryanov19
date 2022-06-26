#include "pch.h"
#include "Header1.h"
#include<fstream>
#include<string>
#include<vector>
#include <sstream>
using namespace std;

void toFile(std::vector<pm::type::Project> projects)
{
	ofstream file("projects.txt", ios::trunc);
	for (int i = 0; i < projects.size(); i++)
	{
		file << projects[i].Title << ',';
		file << projects[i].createdOn << ',';
		file << projects[i].idOfCreator << ',';
		file << projects[i].lastChange << ',';
		file << projects[i].idOfUserChange << endl;
		file << projects[i].Description << endl;
	}
	file.close();
}

std::vector<pm::type::Project> pm::dal::ProjectStore::getAll()
{
	vector<pm::type::Project> projects;
	pm::type::Project project;
	string str1;
	ifstream file("projects.txt");
	string line;
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
	}
	file.close();
	return projects;
}

pm::type::Project pm::dal::ProjectStore::create(size_t idOfCreator)
{
	pm::type::Project project;
	ofstream file("projects.txt", ios::app);
	if (file.is_open())
	{
		cout << "Title:";
		cin >> project.Title;
		cout << "Description of project" << endl;
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
	ofstream file("projects.txt", ios::trunc);
	if (file.is_open())
	{
		for (size_t i = 0; i < (*projects).size(); i++)
		{
			if ((*projects)[i].id != id && (*projects)[i].idOfCreator != idOfUser)
			{
				file << (*projects)[i].Title << ',';
				file << (*projects)[i].createdOn << ',';
				file << (*projects)[i].idOfCreator << ',';
				file << (*projects)[i].lastChange << ',';
				file << (*projects)[i].idOfUserChange << endl;
				file << (*projects)[i].Description << endl;
			}
		}
	}
	file.close();
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
			std::cin >> (*projects)[i].Title;
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
	toFile(*projects);
}

void pm::dal::ProjectStore::displayProjects(std::vector<pm::type::Project> projects)
{
}
