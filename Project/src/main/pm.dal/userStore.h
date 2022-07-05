#pragma once
#include"pch.h"
#include"..\pm.types\types.h"

namespace pm
{
	namespace dal
	{
		class UserStore
		{
		public:
			std::vector<pm::type::User> getAll();
			std::vector<pm::type::User> create(std::vector<pm::type::User> users, size_t idOfCreator, bool registerOrNot);
			std::vector<pm::type::User> remove(std::vector<pm::type::User> users, size_t idOfUser);
			std::vector<pm::type::User> update(std::vector<pm::type::User> users, size_t userIndex, size_t idOfUserChange);
			pm::type::User getById(std::vector<pm::type::User> user, size_t idOfUser);
			size_t getByEmail(std::vector<pm::type::User> user, std::string email);
			bool checkId(std::vector<pm::type::User> user, size_t idOfUser);
			void displayUsers(std::vector<pm::type::User> users);
		};
	}
}
