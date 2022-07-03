#pragma once
#include"pch.h"
#include"..\pm.types\User.h"

namespace pm
{
	namespace dal
	{
		struct UserStore
		{
			std::vector<pm::type::User> getAll();
			std::vector<pm::type::User> create(std::vector<pm::type::User> users, size_t idOfCreator);
			std::vector<pm::type::User> remove(std::vector<pm::type::User> users, size_t id);
			std::vector<pm::type::User> update(std::vector<pm::type::User> users, size_t userIndex,size_t idOfUserChange);
			pm::type::User getById(std::vector<pm::type::User> user, size_t id);
			size_t getByEmail(std::vector<pm::type::User> user, std::string email);
			bool checkId(std::vector<pm::type::User> user, size_t id);
			void displayUsers(std::vector<pm::type::User> users);
		};
	}
}
