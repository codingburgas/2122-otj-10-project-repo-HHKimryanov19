#include "pch.h"
#include "Header1.h"
#include<fstream>
#include<string>
#include<vector>
#include <sstream>
using namespace std;

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
				project.Title = teamField[0];
				project.createdOn = time_t(stoi(teamField[1]));
				project.idOfCreator = size_t(stoi(teamField[2]));
				project.lastChange = time_t(stoi(teamField[3]));
				project.idOfUserChange = size_t(stoi(teamField[4]));
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

pm::type::User pm::dal::ProjectStore::create(std::vector<pm::type::Project> users, size_t idOfCreator)
{
    return pm::type::User();
}

void pm::dal::ProjectStore::remove(std::vector<pm::type::Project>* user, size_t id)
{
}

void pm::dal::ProjectStore::update(std::vector<pm::type::Project>* users, pm::type::Project* user, size_t idOfUserChange)
{
}

void pm::dal::ProjectStore::displayProjects(std::vector<pm::type::Project> users)
{
}
