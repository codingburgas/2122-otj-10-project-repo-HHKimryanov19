#include "pch.h"
#include "Header1.h"
#include<fstream>
#include<string>
#include<vector>
#include <sstream>
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
	for (int i = 0; i < projects.size(); i++)
	{
		file << projects[i].id << ',';
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
	std::vector<std::vector<size_t>> v = projectFunc.teamsInTheProject();
	ofstream file("projects.txt", ios::trunc);
	ofstream file1("teamsInTheProjects.txt", ios::trunc);
	
	int n = 0;
	if (file.is_open()&&file1.is_open())
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
				for (size_t j = 0; j < v[i].size(); j++)
				{
					if (j != v[i].size() - 1)
					{
						file1 << v[i][j] << ',';
					}
					else
					{
						file1 << v[i][j] << endl;
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
					for (size_t j = 0; j < v[i].size(); j++)
					{
						if (j != v[i].size() - 1)
						{
							file1 << v[i][j] << ',';
						}
						else
						{
							file1 << v[i][j] << endl;
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
	toFile(*projects);
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
}

vector<vector<size_t>> pm::dal::ProjectStore::teamsInTheProject()
{
	vector<vector<size_t>> v;
	vector<size_t> v1;
	ifstream file("teamsInTheProjects.txt");
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

std::vector<std::vector<size_t>> pm::dal::ProjectStore::asignToTeam(std::vector<pm::type::Project> projects, size_t projectId, size_t teamId,size_t userId)
{
	vector<vector<size_t>> v = teamsInTheProject();
	ofstream file("teamsInTheProjects.txt", ios::trunc);
	int n = 0;
	if (file.is_open())
	{
		for (size_t i = 0; i < projects.size(); i++)
		{
			if (projects[i].id == projectId)
			{
				if (projects[i].idOfCreator == userId)
				{
					for (size_t j = 0; j < v[i].size(); j++)
					{
						if (v[i][j] == teamId)
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
						v[i].push_back(teamId);
						for (size_t k = 0; k < projects.size(); k++)
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
						for (size_t k = 0; k < projects.size(); k++)
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
	}
	file.close();
	return v;
}
