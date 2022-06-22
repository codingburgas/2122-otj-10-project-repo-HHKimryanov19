#include "pch.h"
#include "../pm.types/User.h"
#include "UserStore.h"
#include<fstream>
#include<string>
#include<vector>
#include <sstream>
using namespace std;

void toFile(pm::type::User user)
{
	std::ofstream file1("Info.txt", std::ios::app);
	if (file1.is_open())
	{
		file1 << user.id << ',';
		file1 << user.FirstName << ',';
		file1 << user.LastName << ',';
		file1 << user.email << ',';
		file1 << user.passwordHash << ',';
		file1 << user.age << ',';
		file1 << user.createdOn << std::endl;
	}
	file1.close();
}

size_t generateNewId(std::vector<pm::type::User> users)
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

std::vector<pm::type::User> pm::dal::UserStore::getAll()
{
	std::vector<pm::type::User> users;
	pm::type::User user;
	string str1;
	pm::type::User newLine;
	std::ifstream file("Info.txt");
	std::string line;
	if (file.is_open())
	{
		for (size_t i = 0; getline(file, line); i++)
		{
			std::vector<std::string> str;
			std::stringstream ss(line);
			while (getline(ss,str1,','))
			{
				str.push_back(str1);
			}
			user.id = size_t(stoi(str[0]));
			user.FirstName = str[1];
			user.LastName = str[2];
			user.email = str[3];
			user.passwordHash = str[4];
			user.age = size_t(stoi(str[5]));
			users.push_back(user);
		}
	}
	file.close();
	return users;
}

void pm::dal::UserStore::create(pm::type::User* user)
{
	std::vector<pm::type::User> users = getAll();
	std::ofstream file1("Info.txt", std::ios::app);
	(*user).id = generateNewId(users);
	if (file1.is_open())
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
		(*user).createdOn = time(NULL);
	}
	file1.close();
}

void pm::dal::UserStore::remove(std::vector<pm::type::User>* user, size_t id)
{
	for (int i = 0; i < (*user).size(); i++)
	{
		if ((*user)[i].id != id)
		{
			toFile((*user)[i]);
		}
	}
	pm::dal::UserStore u;
	(*user) = u.getAll();
}

void pm::dal::UserStore::update(pm::type::User* user)
{
	std::cout << "First name: ";
	std::cin >> (*user).FirstName;
	std::cout << "Last name: ";
	std::cin >> (*user).LastName;
	std::cout << "Email: ";
	std::cin >> (*user).email;
	std::cout << "Password: ";
	std::cin >> (*user).passwordHash;
	std::cout << "Age: ";
	std::cin >> (*user).age;
}

pm::type::User pm::dal::UserStore::getById(std::vector<pm::type::User> user, size_t id)
{
	for (size_t i = 0; i < user.size(); i++)
	{
		if (i == id - 1)
		{
			return user[i];
		}
	}
}

pm::type::User pm::dal::UserStore::getByEmail(std::vector<pm::type::User> user, std::string email)
{
	for (size_t i = 0; i < user.size(); i++)
	{
		if (user[i].email == email)
		{
			return user[i];
		}
	}
}
