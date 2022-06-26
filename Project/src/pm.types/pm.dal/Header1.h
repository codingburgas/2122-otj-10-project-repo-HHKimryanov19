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
			pm::type::Project create(size_t idOfCreator);
			void remove(std::vector<pm::type::Project>* projects, size_t idOfUser, size_t id);
			void update(std::vector<pm::type::Project>* projects, size_t idOfUser, size_t id);
			void displayProjects(std::vector<pm::type::Project> projects);
		};
	}
}