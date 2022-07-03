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
			std::vector<pm::type::Project> remove(std::vector<pm::type::Project> projects, size_t idOfUser, size_t id);
			void update(std::vector<pm::type::Project>& projects, size_t idOfUser, size_t id);
			void displayProjects(std::vector<pm::type::Project> projects, pm::type::User currentUser, std::vector<pm::type::Team> teams, bool ownOrNot);
			void displayProject(pm::type::Project project, std::vector<pm::type::User> users);
			void asignToTeam(std::vector<pm::type::Project>& projects, size_t indexOfProject, size_t indexOfTeam, std::vector<pm::type::Team> teams);
			bool checkForAdded(pm::type::Project project, size_t idOfTeam);
			bool checkId(std::vector<pm::type::Project> projects,size_t id);
			size_t getById(std::vector<pm::type::Project> projects, size_t id);
			size_t getByTitle(std::vector<pm::type::Project> projects, std::string name);
		};
	}
}