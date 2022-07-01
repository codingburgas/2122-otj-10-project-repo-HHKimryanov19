#include "pch.h"
#include "Header.h"
#include "Header1.h"
#include "Header2.h"
#include "UserStore.h"
#include<fstream>
#include<string>
#include<vector>
#include <sstream>
using namespace std;

size_t generateNewId(vector<pm::type::Task> tasks)
{
	size_t maxId = 0;
	for (auto task : tasks)
	{
		if (task.id > maxId)
		{
			maxId = task.id;
		}
	}

	return maxId + 1;
}

std::vector<pm::type::Task> pm::dal::TaskStore::getAll()
{
	vector<pm::type::Task> tasks;
	pm::type::Task task;
	ifstream file("tasks.txt");
	string line;
	string str;
	if (file.is_open())
	{
		for (size_t i = 0; getline(file, line); i++)
		{
			if (i % 2 == 0)
			{
				vector<string> str1;
				stringstream ss(line);
				while (getline(ss, str, ','))
				{
					str1.push_back(str);
				}
				task.id = size_t(stoi(str1[0]));
				task.idOfProject = size_t(stoi(str1[0]));
				task.idOfAssignee = size_t(stoi(str1[0]));
				task.title = str1[0];
				task.status = str1[0];
				task.createdOn = time_t(stoi(str1[0]));
				task.idOfCreator = size_t(stoi(str1[0]));
				task.lastChange = time_t(stoi(str1[0]));
				task.idOfLastChange = size_t(stoi(str1[0]));
			}
			else
			{
				task.description = line;
			}
		}
	}
	file.close();
	return tasks;
}

pm::type::Task pm::dal::TaskStore::create(std::vector<pm::type::Task> tasks, size_t idOfCreator)
{
	pm::type::Task task;
	task.id = generateNewId(tasks);
	cout << "Id of project";
	cin >> task.idOfProject;
	cout << "Id of assignee";
	cin >> task.idOfAssignee;
	cout << "Title: ";
	cin >> task.title;
	cin.ignore();
	cout << "Description:" << endl;
	getline(cin, task.description);
	task.status = "pending";
	task.createdOn = time(NULL);
	task.idOfCreator = idOfCreator;
	task.lastChange = time(NULL);
	task.idOfLastChange = idOfCreator;
	ofstream file("tasks.txt", ios::app);
	if (file.is_open())
	{
		file << task.id << ',';
		file << task.idOfProject << ',';
		file << task.idOfAssignee << ',';
		file << task.title << ',';
		file << task.status << ',';
		file << task.createdOn << ',';
		file << task.idOfCreator << ',';
		file << task.lastChange << ',';
		file << task.idOfLastChange << endl;
		file << task.description << endl;
	}
	file.close();
	return task;
}

void pm::dal::TaskStore::remove(std::vector<pm::type::Task>& tasks, size_t taskId, pm::type::Project project, size_t userId)
{
	pm::dal::TaskStore taskFunc;
	ofstream file("tasks.txt", ios::trunc);
	if (file.is_open())
	{
		if (project.idOfCreator == userId)
		{
			for (size_t i = 0; i < tasks.size(); i++)
			{
				if (tasks[i].id != taskId)
				{
					file << tasks[i].id << ',';
					file << tasks[i].idOfProject << ',';
					file << tasks[i].idOfAssignee << ',';
					file << tasks[i].title << ',';
					file << tasks[i].status << ',';
					file << tasks[i].createdOn << ',';
					file << tasks[i].idOfCreator << ',';
					file << tasks[i].lastChange << ',';
					file << tasks[i].idOfLastChange << endl;
					file << tasks[i].description << endl;
				}
			}
		}
		else
		{
			cout << "Sorry! You aren't able to remove this task";
		}
	}
	tasks = taskFunc.getAll();
	file.close();
}

void pm::dal::TaskStore::update(std::vector<pm::type::Task>& tasks, pm::type::Task& task, size_t idOfUser, pm::type::Project project)
{
	if (project.idOfCreator == idOfUser)
	{
		cout << "Id of assignee";
		cin >> task.idOfAssignee;
		cout << "New title: ";
		cin >> task.title;
		cin.ignore();
		cout << "New description:" << endl;
		getline(cin, task.description);
		cout << "Status of task:";
		cin >> task.status;
		task.lastChange = time(NULL);
		task.idOfLastChange = idOfUser;
		ofstream file("tasks.txt", ios::trunc);
		if (file.is_open())
		{
			for (size_t i = 0; i < tasks.size(); i++)
			{

				file << tasks[i].id << ',';
				file << tasks[i].idOfProject << ',';
				file << tasks[i].idOfAssignee << ',';
				file << tasks[i].title << ',';
				file << tasks[i].status << ',';
				file << tasks[i].createdOn << ',';
				file << tasks[i].idOfCreator << ',';
				file << tasks[i].lastChange << ',';
				file << tasks[i].idOfLastChange << endl;
				file << tasks[i].description << endl;
			}
		}
		file.close();
	}
	else
	{
		cout << "Sorry! You aren't able to edit this task";
	}
}

void pm::dal::TaskStore::displayAllProjectsTasks(std::vector<pm::type::Task> tasks, pm::type::User currentUser, vector<pm::type::Project> projects, vector<pm::type::User> users, vector<pm::type::Team> teams)
{
	pm::dal::ProjectStore projectFunc;
	pm::type::Project project;
	pm::dal::UserStore userFunc;
	pm::type::User user;
	pm::dal::TeamStore teamFunc;
	pm::type::Team team;
	for (size_t i = 0; i < projects.size(); i++)
	{
		if (projects[i].idOfCreator == currentUser.id)
		{
			cout << "Project: " << projects[i].Title << endl;
			for (size_t j = 0; j < tasks.size(); j++)
			{
				if (tasks[j].idOfProject == projects[i].id)
				{
					cout << "Title of the task: " << tasks[j].title << endl;
					user = userFunc.getById(users, tasks[j].idOfCreator);
					cout << "Created by: " << user.FirstName << " " << user.LastName << endl;
					user = userFunc.getById(users, tasks[j].idOfAssignee);
					cout << "Assignee user: " << user.FirstName << " " << user.LastName << endl;
					cout << "Description: " << tasks[j].description << endl;
					cout << "Status: " << tasks[j].status << endl;
				}
			}
		}
	}
	for (size_t i = 0; i < projects.size(); i++)
	{
		for (size_t j = 0; j < projects[i].idOfTeams.size(); j++)
		{
			team = teamFunc.getById(teams, projects[i].idOfTeams[j]);
			for (size_t k = 0; k < team.idOfUsers.size(); i++)
			{
				if (team.idOfUsers[k] == currentUser.id)
				{
					for (size_t m = 0; m < tasks.size(); m++)
					{
						if (tasks[m].idOfAssignee == currentUser.id)
						{
							cout << "Title of the task: " << tasks[m].title << endl;
							user = userFunc.getById(users, tasks[m].idOfCreator);
							cout << "Created by: " << user.FirstName << " " << user.LastName << endl;
							cout << "Description: " << tasks[m].description << endl;
							cout << "Status: " << tasks[m].status << endl;
						}
					}
				}
			}
		}
	}
}

void pm::dal::TaskStore::displayProjectTasks(size_t id,std::vector<pm::type::Task> tasks, pm::type::User currentUser, vector<pm::type::Project> projects, vector<pm::type::User> users, vector<pm::type::Team> teams)
{
	pm::dal::ProjectStore projectFunc;
	pm::type::Project project;
	pm::dal::UserStore userFunc;
	pm::type::User user;
	pm::dal::TeamStore teamFunc;
	pm::type::Team team;
	for (size_t i = 0; i < projects.size(); i++)
	{
		if (projects[i].idOfCreator == currentUser.id)
		{
			if (projects[i].id == id)
			{
				cout << "Project: " << projects[i].Title << endl;
				for (size_t j = 0; j < tasks.size(); j++)
				{
					if (tasks[j].idOfProject == projects[i].id)
					{
						cout << "Title of the task: " << tasks[j].title << endl;
						user = userFunc.getById(users, tasks[j].idOfCreator);
						cout << "Created by: " << user.FirstName << " " << user.LastName << endl;
						user = userFunc.getById(users, tasks[j].idOfAssignee);
						cout << "Assignee user: " << user.FirstName << " " << user.LastName << endl;
						cout << "Description: " << tasks[j].description << endl;
						cout << "Status: " << tasks[j].status << endl;
					}
				}
			}
		}
	}

	for (size_t i = 0; i < projects.size(); i++)
	{
		if (projects[i].id == id)
		{
			for (size_t j = 0; j < projects[i].idOfTeams.size(); j++)
			{
				team = teamFunc.getById(teams, projects[i].idOfTeams[j]);
				for (size_t k = 0; k < team.idOfUsers.size(); i++)
				{
					if (team.idOfUsers[k] == currentUser.id)
					{

						for (size_t m = 0; m < tasks.size(); m++)
						{
							if (tasks[m].idOfAssignee == currentUser.id)
							{
								cout << "Title of the task: " << tasks[m].title << endl;
								user = userFunc.getById(users, tasks[m].idOfCreator);
								cout << "Created by: " << user.FirstName << " " << user.LastName << endl;
								cout << "Description: " << tasks[m].description << endl;
								cout << "Status: " << tasks[m].status << endl;
							}
						}
					}
				}
			}
		}
	}
}