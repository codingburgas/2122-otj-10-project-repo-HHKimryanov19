#include "pch.h"
#include "../pm.types/User.h"
#include "UserStore.h"

void pm::dal::UserStore::create(pm::type::User user)
{
	int n = 0;
	std::ifstream file("Info.txt");
	std::string str;
	if (file.is_open())
	{
		while (getline(std::cin, str))
		{
			n++;
		}
	}
	file.close();
	user.id = n;
	std::ofstream file1("Info.txt");

	if (file1.is_open())
	{
		file1 << user.id<<' ';
		std::cin >> user.FirstName;
		std::cin >> user.LastName;
		std::cin >> user.email;
		std::cin >> user.passwordHash;
		std::cin >> user.age;
		user.createdOn = time(NULL);
		file1 << user.FirstName << ' ';
		file1 << user.LastName << ' ';
		file1 << user.email << ' ';
		file1 << user.passwordHash << ' ';
		file1 << user.age << ' ';
		file1 << user.createdOn<<' ';
	}
	file.close();
}

std::vector<pm::type::User> pm::dal::UserStore::getAll()
{
	return std::vector<pm::type::User>();
}

void pm::dal::UserStore::remove(size_t id)
{

}

void pm::dal::UserStore::update(pm::type::User user)
{

}

pm::type::User pm::dal::UserStore::getById(size_t id)
{
	return pm::type::User();
}

pm::type::User pm::dal::UserStore::getByEmail(std::string email)
{
	return pm::type::User();
}
