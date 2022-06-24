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
			pm::type::Team create(std::vector<pm::type::Team> teams,pm::type::User currentUser);
			void remove(std::vector<pm::type::Team>* teams, size_t id);
			void update(pm::type::Team* team, pm::type::User currentUser);
			/*pm::type::User getById(std::vector<pm::type::Team> user, size_t id); */
			void displayTeams(std::vector<pm::type::Team> teams);
		};
	}
}
