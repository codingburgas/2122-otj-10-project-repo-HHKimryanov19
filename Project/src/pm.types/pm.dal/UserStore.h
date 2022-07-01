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
			pm::type::User getByEmail(std::vector<pm::type::User> user, std::string email);
			void displayUsers(std::vector<pm::type::User> users);
		};
	}
}
