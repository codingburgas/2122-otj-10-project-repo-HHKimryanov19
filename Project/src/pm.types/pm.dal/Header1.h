#pragma once
#pragma once
#include"pch.h"
#include"..\pm.types\User.h"
#include<string>
#include<vector>


namespace pm
{
	namespace dal
	{
		struct ProjectStore
		{
			std::vector<pm::type::Project> getAll();
			pm::type::User create(std::vector<pm::type::Project> users, size_t idOfCreator);
			void remove(std::vector<pm::type::Project>* user, size_t id);
			void update(std::vector<pm::type::Project>* users, pm::type::Project* user, size_t idOfUserChange);
			void displayProjects(std::vector<pm::type::Project> users);
		};
	}
}