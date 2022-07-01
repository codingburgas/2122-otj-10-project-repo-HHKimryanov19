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
			void remove(std::vector<pm::type::Task>& tasks, size_t taskId, pm::type::Project project, size_t userId);
			void update(std::vector<pm::type::Task>& tasks, pm::type::Task& task, size_t idOfUser, pm::type::Project project);
			void displayAllProjectsTasks(std::vector<pm::type::Task> tasks, pm::type::User currentUser, std::vector<pm::type::Project> projects, std::vector<pm::type::User> users, std::vector<pm::type::Team> teams);
			void displayProjectTasks(size_t id, std::vector<pm::type::Task> tasks, pm::type::User currentUser, std::vector<pm::type::Project> projects, std::vector<pm::type::User> users, std::vector<pm::type::Team> teams);
		};
	}
}