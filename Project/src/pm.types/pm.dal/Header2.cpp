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
				task.idOfProject = size_t(stoi(str1[1]));
				task.idOfAssignee = size_t(stoi(str1[2]));
				task.title = str1[3];
				task.status = str1[4];
				task.createdOn = time_t(stoi(str1[5]));
				task.idOfCreator = size_t(stoi(str1[6]));
				task.lastChange = time_t(stoi(str1[7]));
				task.idOfLastChange = size_t(stoi(str1[8]));
			}
			else
			{
				task.description = line;
			}
		}
		tasks.push_back(task);
	}
	file.close();
	return tasks;
}

pm::type::Task pm::dal::TaskStore::create(std::vector<pm::type::Task> tasks, size_t idOfCreator,vector<pm::type::User> users)
{
	pm::type::Task task;
	pm::dal::UserStore userFunc;
	cin.ignore();
	task.id = generateNewId(tasks);
	cout << "Project: ";
	cin >> task.idOfProject;
	cout << "Assignee: ";
	for (size_t i = 0; i < users.size(); i++)
	{
		cout << users[i].FirstName << " " << users[i].LastName << " " << users[i].email << endl;
	}
	string email;
	cout << "Email of user: ";
	cin >> email;
	task.idOfAssignee = users[userFunc.getByEmail(users,email)].id;
	cout << "Title: ";
	cin >> task.title;
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

void pm::dal::TaskStore::remove(std::vector<pm::type::Task>& tasks, size_t taskId, size_t userId)
{
	pm::dal::TaskStore taskFunc;
	ofstream file("tasks.txt", ios::trunc);
	if (file.is_open())
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
			size_t index = teamFunc.getById(teams, projects[i].idOfTeams[j]);
			for (size_t k = 0; k < teams[index].idOfUsers.size(); i++)
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
void pm::dal::TaskStore::displayCreated(std::vector<pm::type::Task> tasks, pm::type::User currentUser, vector<pm::type::Project> projects, vector<pm::type::User> users, vector<pm::type::Team> teams)
{
	pm::dal::ProjectStore projectFunc;
	pm::type::Project project;
	pm::dal::UserStore userFunc;
	pm::type::User user;
	pm::dal::TeamStore teamFunc;
	for (size_t i = 0; i < projects.size(); i++)
	{
		if (projects[i].idOfCreator == currentUser.id)
		{
			for (size_t j = 0; j < tasks.size(); j++)
			{
				if (tasks[j].idOfProject == projects[i].id)
				{
					cout << tasks[i].id<<"." << tasks[j].title << endl;
					user = userFunc.getById(users, tasks[j].idOfCreator);
					cout << "Created by: " << user.FirstName << " " << user.LastName << endl;
					user = userFunc.getById(users, tasks[j].idOfAssignee);
					cout << "Assignee user: " << user.FirstName << " " << user.LastName << endl;
					cout << "Description: " << tasks[j].description << endl;
					cout << "Status: " << tasks[j].status << endl;
					cout << endl;
				}
			}
		}
	}
}

void pm::dal::TaskStore::displayProjectTasks(size_t id, std::vector<pm::type::Task> tasks, pm::type::User currentUser, vector<pm::type::Project> projects, vector<pm::type::User> users, vector<pm::type::Team> teams)
{
	pm::dal::ProjectStore projectFunc;
	pm::type::Project project;
	pm::dal::UserStore userFunc;
	pm::type::User user;
	pm::dal::TeamStore teamFunc;
	int index = 1;
	index = 1;

	for (size_t i = 0; i < projects.size(); i++)
	{
		if (projects[i].id == id)
		{
			for (size_t j = 0; j < projects[i].idOfTeams.size(); j++)
			{
				size_t index = teamFunc.getById(teams, projects[i].idOfTeams[j]);
				for (size_t k = 0; k < teams[index].idOfUsers.size(); k++)
				{
					if (teams[index].idOfUsers[k] == currentUser.id)
					{

						for (size_t m = 0; m < tasks.size(); m++)
						{
							if (tasks[m].idOfAssignee == currentUser.id)
							{
								cout << "Team: " << teams[index].Title << endl;
								cout << "Task " << index++;
								cout << "Title of the task: " << tasks[m].title << endl;
								user = userFunc.getById(users, tasks[m].idOfCreator);
								cout << "Created by: " << user.FirstName << " " << user.LastName << endl;
								cout << "Description: " << tasks[m].description << endl;
								cout << "Status: " << tasks[m].status << endl;
								cout << endl;
							}
						}
					}
				}
			}
		}
	}
}

size_t pm::dal::TaskStore::getById(vector<pm::type::Task> tasks, size_t id)
{
	for (size_t i = 0; i < tasks.size(); i++)
	{
		if (i == id)
		{
			return i;
		}
	}
}

bool pm::dal::TaskStore::checkId(std::vector<pm::type::Task> tasks, size_t id)
{
	for (size_t i = 0; i < tasks.size(); i++)
	{
		if (tasks[i].id == id)
		{
			return true;
		}
	}
	return false;
}