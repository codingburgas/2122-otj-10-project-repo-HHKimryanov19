#include "pch.h"
#include "../pm.types/User.h"
#include "UserStore.h"
#include<fstream>
#include<string>
#include<vector>
#include <sstream>
using namespace std;

//void toFile(pm::type::User user, std::ofstream file1)
//{
//	file1 << user.id << ',';
//	file1 << user.FirstName << ',';
//	file1 << user.LastName << ',';
//	file1 << user.email << ',';
//	file1 << user.passwordHash << ',';
//	file1 << user.age << ',';
//	file1 << user.createdOn << std::endl;
//}

size_t generateNewId(vector<pm::type::User> users)
{
	size_t maxId = 0;
	for (auto user : users)
	{
		if (user.id > maxId)
		{
			maxId = user.id;
		}
	}

	return maxId + 1;
}

vector<pm::type::User> pm::dal::UserStore::getAll()
{
	vector<pm::type::User> users;
	pm::type::User user;
	string str1;
	pm::type::User newLine;
	ifstream file("Info.txt");
	string line;
	if (file.is_open())
	{
		for (size_t i = 0; getline(file, line); i++)
		{
			vector<string> str;
			stringstream ss(line);
			while (getline(ss, str1, ','))
			{
				str.push_back(str1);
			}
			user.id = size_t(stoi(str[0]));
			user.FirstName = str[1];
			user.LastName = str[2];
			user.email = str[3];
			user.passwordHash = str[4];
			user.age = size_t(stoi(str[5]));
			user.createdOn = time_t(stoi(str[6]));
			if (str[7] == "true")
			{
				user.adminPrivileges = true;
			}
			else
			{
				user.adminPrivileges = false;
			}
			users.push_back(user);
		}
	}
	file.close();
	return users;
}

pm::type::User pm::dal::UserStore::create()
{
	vector<pm::type::User> users = getAll();
	pm::type::User user;
	ofstream file1("Info.txt", ios::app);
	user.id = generateNewId(users);
	if (file1.is_open())
	{
		cout << "First name: ";
		cin >> user.FirstName;
		cout << "Last name: ";
		cin >> user.LastName;
		cout << "Email: ";
		cin >> user.email;
		cout << "Password: ";
		cin >> user.passwordHash;
		cout << "Age: ";
		cin >> user.age;
		user.createdOn = time(NULL);
		cout << "This user is admin - ";
		cin >> user.adminPrivileges;
	}
	file1.close();
	return user;
}

void pm::dal::UserStore::remove(vector<pm::type::User>* user, size_t id)
{
	ofstream file1("Info.txt",ios::trunc);
	for (int i = 0; i < (*user).size(); i++)
	{
		if ((*user)[i].id != id)
		{
			file1 << (*user)[i].id << ',';
			file1 << (*user)[i].FirstName << ',';
			file1 << (*user)[i].LastName << ',';
			file1 << (*user)[i].email << ',';
			file1 << (*user)[i].passwordHash << ',';
			file1 << (*user)[i].age << ',';
			file1 << (*user)[i].createdOn << ',';
			if ((*user)[i].adminPrivileges)
			{
				file1 << "true"<<endl;
			}
			else
			{
				file1 << "false" << endl;
			}
		}
	}
	pm::dal::UserStore u;
	(*user) = u.getAll();
}

void pm::dal::UserStore::update(pm::type::User* user)
{
	cout << "First name: ";
	cin >> (*user).FirstName;
	cout << "Last name: ";
	cin >> (*user).LastName;
	cout << "Email: ";
	cin >> (*user).email;
	cout << "Password: ";
	cin >> (*user).passwordHash;
	cout << "Age: ";
	cin >> (*user).age;
	cout << "This user is admin - ";
	cin >> (*user).adminPrivileges;
}

pm::type::User pm::dal::UserStore::getById(vector<pm::type::User> user, size_t id)
{
	for (size_t i = 0; i < user.size(); i++)
	{
		if (i == id - 1)
		{
			return user[i];
		}
	}
}

pm::type::User pm::dal::UserStore::getByEmail(vector<pm::type::User> user, string email)
{
	for (size_t i = 0; i < user.size(); i++)
	{
		if (user[i].email == email)
		{
			return user[i];
		}
	}
}
