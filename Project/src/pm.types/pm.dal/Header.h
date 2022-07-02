#pragma once
#include"pch.h"
#include"..\pm.types\User.h"
#include<string>
#include<vector>


namespace pm
{
	namespace dal
	{
		struct TeamStore {
			std::vector<pm::type::Team> getAll();
			std::vector<pm::type::Team> create(std::vector<pm::type::Team> teams,pm::type::User currentUser);
			std::vector<pm::type::Team> remove(std::vector<pm::type::Team> teams, size_t id);
			std::vector<pm::type::Team> update(std::vector<pm::type::Team> teams, size_t indexOfTeam, size_t currentUserId);
			size_t  getById(std::vector<pm::type::Team> teams, size_t id);
			void displayTeams(std::vector<pm::type::Team> teams);
			std::vector<pm::type::Team> asignToTeam(std::vector< pm::type::Team> teams, size_t indexOfTeam, size_t idOfUser);
			//std::vector<std::vector<size_t>> usersInTheTeams();
			//std::vector<std::vector<size_t>> asignToTeam(std::vector<pm::type::Team> teams, size_t teamId, size_t userId);
		};
	}
}
