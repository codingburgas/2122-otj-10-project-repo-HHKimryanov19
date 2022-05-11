#include "pch.h"
#include "../pm.types/User.h"
#include "UserStore.h"
#include<fstream>
#include<string>
#include<vector>

/*void toFile(vector<pm::type::User> users)
{
	ofstream file("Info.txt");
	if (file.is_open())
	{
		file << users.id<<' ';
		file << users.FirstName << ' ';
		file << users.LastName << ' ';
		file << users.email << ' ';
		file << users.passwordHash << ' ';
		file << users.age << ' ';
		file << users.createdOn << std::endl;
	}
	file.close();
}*/

void pm::dal::UserStore::create(pm::type::User* user)
{
	int n = 1;
	std::ifstream file("Info.txt");
	std::string str;
	if (file.is_open())
	{
		while (getline(file, str)) {
			n = stoi(str.substr(0, str.find(' ')));
		}
	}
	file.close();
	(*user).id = n + 1;
	std::ofstream file1("Info.txt", std::ios::app);

	if (file1.is_open())
	{
		file1 << (*user).id << ' ';
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
		(*user).createdOn = time(NULL);
		file1 << (*user).FirstName << ' ';
		file1 << (*user).LastName << ' ';
		file1 << (*user).email << ' ';
		file1 << (*user).passwordHash << ' ';
		file1 << (*user).age << ' ';
		file1 << (*user).createdOn << std::endl;
	}
	file.close();
}

std::vector<pm::type::User> pm::dal::UserStore::getAll()
{
	std::vector<pm::type::User> user;
	pm::type::User newLine;
	std::ifstream file("Info.txt");
	std::string line;
	if (file.is_open())
	{
		for (size_t i = 0; getline(file, line); i++)
		{
			newLine.id = stoi(line.substr(0, line.find(' ')));
			line.erase(0, line.find(' ') + 1);
			newLine.FirstName = line.substr(0, line.find(' '));
			line.erase(0, line.find(' ') + 1);
			newLine.LastName = line.substr(0, line.find(' '));
			line.erase(0, line.find(' ') + 1);
			newLine.email = line.substr(0, line.find(' '));
			line.erase(0, line.find(' ') + 1);
			newLine.passwordHash = line.substr(0, line.find(' '));
			line.erase(0, line.find(' ') + 1);
			newLine.age = stoi(line.substr(0, line.find(' ')));
			line.erase(0, line.find(' ') + 1);
			newLine.createdOn = stoi(line);
			user.push_back(newLine);
		}
	}
	file.close();
	return user;
}

void pm::dal::UserStore::remove(std::vector<pm::type::User>* user, size_t id)
{

	std::ofstream file("Info.txt", std::ios::ate);
	if (file.is_open())
	{
		for (int i = 0; i < (*user).size(); i++)
		{
			if ((*user)[i].id != id)
			{
				file << (*user)[i].id << ' ';
				file << (*user)[i].FirstName << ' ';
				file << (*user)[i].LastName << ' ';
				file << (*user)[i].email << ' ';
				file << (*user)[i].passwordHash << ' ';
				file << (*user)[i].age << ' ';
				file << (*user)[i].createdOn << std::endl;
			}
		}
	}
	file.close();
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

pm::type::User pm::dal::UserStore::getById(std::vector<pm::type::User>* user, size_t id)
{
	for (size_t i = 0; i < (*user).size(); i++)
	{
		if (i == id - 1)
		{
			return (*user)[i];
		}
	}
}

pm::type::User pm::dal::UserStore::getByEmail(std::vector<pm::type::User>* user, std::string email)
{
	for (size_t i = 0; i < (*user).size(); i++)
	{
		if ((*user)[i].email == email)
		{
			return (*user)[i];
		}
	}
}
