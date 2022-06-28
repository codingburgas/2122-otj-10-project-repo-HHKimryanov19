#include "pch.h"
#include "Header2.h"
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

pm::type::Task pm::dal::TaskStore::create(std::vector<pm::type::Task> tasks,size_t idOfCreator)
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
	ofstream file("tasks.txt",ios::app);
	if (file.is_open())
	{
		file<<task.id<<',';
		file<<task.idOfProject << ',';
		file<<task.idOfAssignee << ',';
		file<<task.title << ',';
		file<<task.status << ',';
		file<<task.createdOn << ',';
		file<<task.idOfCreator << ',';
		file<<task.lastChange << ',';
		file << task.idOfLastChange << endl;
		file<<task.description << endl;
	}
	file.close();
	return task;
}

void pm::dal::TaskStore::remove(std::vector<pm::type::Task>* tasks,size_t taskId)
{
	ofstream file("tasks.txt", ios::trunc);
	if (file.is_open())
	{
		for (size_t i = 0; i < (*tasks).size(); i++)
		{
			if ((*tasks)[i].id != taskId)
			{
				file << (*tasks)[i].id << ',';
				file << (*tasks)[i].idOfProject << ',';
				file << (*tasks)[i].idOfAssignee << ',';
				file << (*tasks)[i].title << ',';
				file << (*tasks)[i].status << ',';
				file << (*tasks)[i].createdOn << ',';
				file << (*tasks)[i].idOfCreator << ',';
				file << (*tasks)[i].lastChange << ',';
				file << (*tasks)[i].idOfLastChange << endl;
				file << (*tasks)[i].description << endl;
			}
		}
	}
	file.close();
}

void pm::dal::TaskStore::update(std::vector<pm::type::Task>* tasks, size_t idOfUser, size_t id)
{
	ofstream file("tasks.txt", ios::trunc);
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
	task.lastChange = time(NULL);
	task.idOfLastChange = idOfUser;
	for (size_t i = 0; i < (*tasks).size(); i++)
	{
		
			file << (*tasks)[i].id << ',';
			file << (*tasks)[i].idOfProject << ',';
			file << (*tasks)[i].idOfAssignee << ',';
			file << (*tasks)[i].title << ',';
			file << (*tasks)[i].status << ',';
			file << (*tasks)[i].createdOn << ',';
			file << (*tasks)[i].idOfCreator << ',';
			file << (*tasks)[i].lastChange << ',';
			file << (*tasks)[i].idOfLastChange << endl;
			file << (*tasks)[i].description << endl;
	}
}

void pm::dal::TaskStore::displayProjects(std::vector<pm::type::Task> tasks, pm::type::User currentUser)
{
}
