#pragma once
#include"pch.h"
#include"..\pm.types\types.h"
#include<string>
#include<vector>


namespace pm
{
	namespace dal
	{
		class TeamStore {
		public:
			std::vector<pm::type::Team> getAll();
			std::vector<pm::type::Team> create(std::vector<pm::type::Team> teams, pm::type::User currentUser);
			std::vector<pm::type::Team> remove(std::vector<pm::type::Team> teams, size_t idTeam);
			std::vector<pm::type::Team> update(std::vector<pm::type::Team> teams, size_t indexOfTeam, size_t currentUserId);
			size_t  getById(std::vector<pm::type::Team> teams, size_t idTeam);
			size_t  getByTitle(std::vector<pm::type::Team> teams, std::string titleOfTeam);
			void displayTeams(std::vector<pm::type::Team> teams);
			bool checkForAdded(pm::type::Team team, size_t idOfUser);
			bool checkId(std::vector<pm::type::Team> teams, size_t idTeam);
			std::vector<pm::type::Team> asignToTeam(std::vector< pm::type::Team> teams, size_t indexOfTeam, size_t idOfUser);
		};
	}
}
