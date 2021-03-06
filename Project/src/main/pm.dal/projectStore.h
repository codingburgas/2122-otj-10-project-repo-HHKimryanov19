#pragma once
#include"pch.h"
#include"..\pm.types\types.h"
#include<string>
#include<vector>


namespace pm
{
	namespace dal
	{
		class ProjectStore
		{
		public:
			std::vector<pm::type::Project> getAll();
			pm::type::Project create(std::vector<pm::type::Project> projects, size_t idOfCreator);
			std::vector<pm::type::Project> remove(std::vector<pm::type::Project> projects, size_t idOfUser, size_t idOfProject);
			void update(std::vector<pm::type::Project>& projects, size_t idOfUser, size_t idOfProject);
			void displayProjects(std::vector<pm::type::Project> projects, pm::type::User currentUser, std::vector<pm::type::Team> teams, bool ownOrNot);
			void displayProject(pm::type::Project project, std::vector<pm::type::User> users);
			void asignToTeam(std::vector<pm::type::Project>& projects, size_t indexOfProject, size_t indexOfTeam, std::vector<pm::type::Team> teams);
			bool checkForAdded(pm::type::Project project, size_t idOfTeam);
			bool checkId(std::vector<pm::type::Project> projects, size_t idOfProject);
			size_t getById(std::vector<pm::type::Project> projects, size_t idOfProject);
			size_t getByTitle(std::vector<pm::type::Project> projects, std::string titleOfteam);
		};
	}
}