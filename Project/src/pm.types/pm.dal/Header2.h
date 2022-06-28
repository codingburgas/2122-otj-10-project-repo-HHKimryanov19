#pragma once
#include"pch.h"
#include"..\pm.types\User.h"
#include<string>
#include<vector>


namespace pm
{
	namespace dal
	{
		struct TaskStore
		{
			std::vector<pm::type::Task> getAll();
			pm::type::Task create(std::vector<pm::type::Task> tasks, size_t idOfCreator);
			void remove(std::vector<pm::type::Task>* tasks, size_t taskId);
			void update(std::vector<pm::type::Task>* tasks, size_t idOfUser, size_t id);
			void displayProjects(std::vector<pm::type::Task> tasks, pm::type::User currentUser);
		};
	}
}