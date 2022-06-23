#pragma once
#include"pch.h"
#include"..\pm.types\User.h"
#include<string>
#include<vector>


namespace pm
{
	namespace dal
	{
		struct UserStore
		{
			std::vector<pm::type::User> getAll();
			pm::type::User create(std::vector<pm::type::User> users,size_t idOfCreator);
			void remove(std::vector<pm::type::User>* user,size_t id);
			void update(pm::type::User* user);
			pm::type::User getById(std::vector<pm::type::User> user, size_t id);
			pm::type::User getByEmail(std::vector<pm::type::User> user, std::string email);
		};
	}
}
