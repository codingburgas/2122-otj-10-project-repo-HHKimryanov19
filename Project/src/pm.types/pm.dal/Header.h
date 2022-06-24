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
			/*pm::type::User create(std::vector<pm::type::Team> teams);
			void remove(std::vector<pm::type::Team>* teams, size_t id);
			void update(pm::type::Team* user);
			pm::type::User getById(std::vector<pm::type::Team> user, size_t id);*/
		};
	}
}
