#include "pch.h"
#include "../pm.types/User.h"
#include "UserStore.h"
#include "Header.h"
using namespace std;

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

void toFile(vector<pm::type::User> users)
{
	ofstream file1("Info.txt", ios::trunc);
	for (int i = 0; i < users.size(); i++)
	{
		file1 << users[i].id << ',';
		file1 << users[i].FirstName << ',';
		file1 << users[i].LastName << ',';
		file1 << users[i].email << ',';
		file1 << users[i].passwordHash << ',';
		file1 << users[i].age << ',';
		file1 << users[i].createdOn << ',';
		file1 << users[i].lastChange << ',';
		file1 << users[i].idOfCreater << ',';
		file1 << users[i].idOfUserChange << ',';
		if (users[i].adminPrivileges)
		{
			file1 << "true" << endl;
		}
		else
		{
			file1 << "false" << endl;
		}
	}
	file1.close();
}

vector<pm::type::User> pm::dal::UserStore::getAll()
{
	vector<pm::type::User> users;
	pm::type::User user;
	string str1;
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
			user.lastChange = time_t(stoi(str[7]));
			user.idOfCreater = size_t(stoi(str[8]));
			user.idOfUserChange = size_t(stoi(str[9]));
			if (str[10] == "true")
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

vector<pm::type::User> pm::dal::UserStore::create(vector<pm::type::User> users, size_t idOfCreator)
{
	string str;
	pm::type::User user;
	ofstream file1("Info.txt", ios::app);
	user.id = generateNewId(users);
	if (file1.is_open())
	{
		user.createdOn = time(NULL);
		user.idOfCreater = idOfCreator;
		user.lastChange = time(NULL);
		user.idOfUserChange = idOfCreator;

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
		cout << "Admin or user(type in lowercase) - ";
		cin >> str;
		if (str == "admin")
		{
			user.adminPrivileges = 1;
		}
		else
		{
			user.adminPrivileges = 0;
		}

		file1 << user.id << ',';
		file1 << user.FirstName << ',';
		file1 << user.LastName << ',';
		file1 << user.email << ',';
		file1 << user.passwordHash << ',';
		file1 << user.age << ',';
		file1 << user.createdOn << ',';
		file1 << user.lastChange << ',';
		file1 << user.idOfCreater << ',';
		file1 << user.idOfUserChange << ',';
		if (user.adminPrivileges)
		{
			file1 << "true" << endl;
		}
		else
		{
			file1 << "false" << endl;
		}
	}
	file1.close();
	users.push_back(user);
	return users;
}

vector<pm::type::User> pm::dal::UserStore::remove(vector<pm::type::User> users, size_t id)
{
	ofstream file1("Info.txt", ios::trunc);
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].id != id)
		{
			file1 << users[i].id << ',';
			file1 << users[i].FirstName << ',';
			file1 << users[i].LastName << ',';
			file1 << users[i].email << ',';
			file1 << users[i].passwordHash << ',';
			file1 << users[i].age << ',';
			file1 << users[i].createdOn << ',';
			file1 << users[i].lastChange << ',';
			file1 << users[i].idOfCreater << ',';
			file1 << users[i].idOfUserChange << ',';
			if (users[i].adminPrivileges)
			{
				file1 << "true" << endl;
			}
			else
			{
				file1 << "false" << endl;
			}
		}
	}
	file1.close();
	pm::dal::UserStore u;
	users = u.getAll();
	return users;
}

vector<pm::type::User> pm::dal::UserStore::update(std::vector<pm::type::User> users, size_t userIndex, size_t idOfUserChange)
{
	string str;
	cout << "First name: ";
	cin >> users[userIndex].FirstName;
	cout << "Last name: ";
	cin >> users[userIndex].LastName;
	cout << "Email: ";
	cin >> users[userIndex].email;
	cout << "Password: ";
	cin >> users[userIndex].passwordHash;
	cout << "Age: ";
	cin >> users[userIndex].age;
	users[userIndex].lastChange = time(NULL);
	users[userIndex].idOfUserChange = idOfUserChange;
	cout << "Admin or user(type in lowercase) - ";
	cin >> str;
	if (str == "admin")
	{
		users[userIndex].adminPrivileges = 1;
	}
	else
	{
		users[userIndex].adminPrivileges = 0;
	}
	toFile(users);
	return users;
}

pm::type::User pm::dal::UserStore::getById(vector<pm::type::User> user, size_t id)
{
	for (auto i : user)
	{
		if (i.id == id)
		{
			return i;
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

bool pm::dal::UserStore::checkId(vector<pm::type::User> user, size_t id)
{
	for (size_t i = 0; i < user.size(); i++)
	{
		if (user[i].id == id)
		{
			return true;
		}
	}
	return false;
}

void pm::dal::UserStore::displayUsers(vector<pm::type::User> users)
{
	for (int i = 0; i < users.size(); i++)
	{
		cout << users[i].id << ". " << users[i].FirstName << " " << users[i].LastName << " " << users[i].email << " " << users[i].age << " " << users[i].createdOn << endl;
	}
}