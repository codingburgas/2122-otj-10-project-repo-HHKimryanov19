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
			pm::type::Project create(std::vector<pm::type::Project> projects, size_t idOfCreator);
			void remove(std::vector<pm::type::Project>* projects, size_t idOfUser, size_t id);
			void update(std::vector<pm::type::Project>* projects, size_t idOfUser, size_t id);
			void displayProjects(std::vector<pm::type::Project> projects, pm::type::User currentUser);
			std::vector<std::vector<size_t>> teamsInTheProject();
			std::vector<std::vector<size_t>> asignToTeam(std::vector<pm::type::Project> projects, size_t projectId, size_t teamId, size_t userId);
		};
	}
}