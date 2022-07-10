#include "pch.h"
#include "../pm.types/types.h"
#include "UserStore.h"
#include "../pm.dal/teamStore.h"
#include"../pm.tools/md5.h"
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

bool checkEmail(vector<pm::type::User> users, string email)
{
	for (size_t i = 0; i < users.size(); i++)
	{
		if (users[i].email == email)
		{
			return true;
		}
	}
	return false;
}

void toFile(vector<pm::type::User> users)
{
	ofstream file("Info.txt", ios::trunc);
	for (int i = 0; i < users.size(); i++)
	{
		file << users[i].id << ',';
		file << users[i].firstName << ',';
		file << users[i].lastName << ',';
		file << users[i].email << ',';
		file << users[i].passwordHash << ',';
		file << users[i].age << ',';
		file << users[i].createdOn << ',';
		file << users[i].lastChange << ',';
		file << users[i].idOfCreator << ',';
		file << users[i].idOfUserChange << ',';
		if (users[i].adminPrivileges)
		{
			file << "true" << endl;
		}
		else
		{
			file << "false" << endl;
		}
	}
	file.close();
}

vector<pm::type::User> pm::dal::UserStore::getAll()
{
	vector<pm::type::User> users;
	pm::type::User user;
	string currentField;
	ifstream file("Info.txt");
	string row;
	if (file.is_open())
	{
		for (size_t i = 0; getline(file, row); i++)
		{
			vector<string> userFields;
			stringstream ss(row);
			while (getline(ss, currentField, ','))
			{
				userFields.push_back(currentField);
			}
			user.id = size_t(stoi(userFields[0]));
			user.firstName = userFields[1];
			user.lastName = userFields[2];
			user.email = userFields[3];
			user.passwordHash = userFields[4];
			user.age = size_t(stoi(userFields[5]));
			user.createdOn = time_t(stoi(userFields[6]));
			user.lastChange = time_t(stoi(userFields[7]));
			user.idOfCreator = size_t(stoi(userFields[8]));
			user.idOfUserChange = size_t(stoi(userFields[9]));
			if (userFields[10] == "true")
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

vector<pm::type::User> pm::dal::UserStore::create(vector<pm::type::User> users, size_t idOfCreator,bool registerOrNot)
{
	string userOrAdmin;
	pm::type::User user;
	ofstream file1("Info.txt", ios::app);
	user.id = generateNewId(users);
	if (file1.is_open())
	{
		user.createdOn = time(NULL);
		user.lastChange = time(NULL);
		user.idOfUserChange = idOfCreator;

		cout << "First name: ";
		cin >> user.firstName;
		cout << "Last name: ";
		cin >> user.lastName;
		cout << "Email: ";
		cin >> user.email;
		while (checkEmail(users, user.email))
		{
			cout << "Sorry, this email is in use. Inter another" << endl;
			cout << "Email: ";
			cin >> user.email;
		}
		cout << "Password: ";
		cin >> user.passwordHash;
		user.passwordHash = md5(user.passwordHash);
		cout << "Age: ";
		cin >> user.age;

		if (registerOrNot)
		{
			user.idOfCreator = idOfCreator;
			cout << "Admin or user(type in lowercase) - ";
			cin >> userOrAdmin;
			if (userOrAdmin == "admin")
			{
				user.adminPrivileges = 1;
			}
			else
			{
				user.adminPrivileges = 0;
			}
		}
		else
		{
			user.idOfCreator = user.id;
			user.adminPrivileges = 0;
		}

		file1 << user.id << ',';
		file1 << user.firstName << ',';
		file1 << user.lastName << ',';
		file1 << user.email << ',';
		file1 << user.passwordHash << ',';
		file1 << user.age << ',';
		file1 << user.createdOn << ',';
		file1 << user.lastChange << ',';
		file1 << user.idOfCreator << ',';
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

vector<pm::type::User> pm::dal::UserStore::remove(vector<pm::type::User> users, size_t idOfUser)
{
	ofstream file1("Info.txt", ios::trunc);
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].id != idOfUser)
		{
			file1 << users[i].id << ',';
			file1 << users[i].firstName << ',';
			file1 << users[i].lastName << ',';
			file1 << users[i].email << ',';
			file1 << users[i].passwordHash << ',';
			file1 << users[i].age << ',';
			file1 << users[i].createdOn << ',';
			file1 << users[i].lastChange << ',';
			file1 << users[i].idOfCreator << ',';
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
	cin >> users[userIndex].firstName;
	cout << "Last name: ";
	cin >> users[userIndex].lastName;
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

pm::type::User pm::dal::UserStore::getById(vector<pm::type::User> user, size_t idOfUser)
{
	for (auto i : user)
	{
		if (i.id == idOfUser)
		{
			return i;
		}
	}
}

size_t pm::dal::UserStore::getByEmail(vector<pm::type::User> user, string email)
{
	for (size_t i = 0; i < user.size(); i++)
	{
		if (user[i].email == email)
		{
			return i;
		}
	}
}

bool pm::dal::UserStore::checkId(vector<pm::type::User> user, size_t idOfUser)
{
	for (size_t i = 0; i < user.size(); i++)
	{
		if (user[i].id == idOfUser)
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
		cout << users[i].id << ". " << users[i].firstName << " " << users[i].lastName << " " << users[i].email << " " << users[i].age << " " << users[i].createdOn << endl;
	}
}