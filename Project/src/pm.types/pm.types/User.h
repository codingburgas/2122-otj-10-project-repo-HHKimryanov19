#pragma once
#include"pch.h"
#include<iostream>
#include<string>
#include<ctime>

namespace pm {
	namespace type {
		struct User {
			size_t id;
			std::string FirstName;
			std::string LastName;
			std::string email;
			unsigned short age;
			std::string passwordHash;
			std::time_t createdOn;
			std::time_t lastChange;
			size_t idOfCreater;
			size_t idOfUserChange;
			bool adminPrivileges;
		};

		struct Team {
			size_t id;
			std::string Title;
			std::time_t createdOn;
			size_t idOfCreator;
			std::time_t lastChange;
			size_t idOfUserChange;
			std::vector<pm::type::User> assignedUser;
		};

		struct Project {
			size_t id;
			std::string Title;
			std::string Description;
			std::time_t createdOn;
			size_t idOfCreator;
			std::time_t lastChange;
			size_t idOfUserChange;
			std::vector<pm::type::Team> assignedTeams;
		};

		struct Task{
			size_t id;
			size_t idOfProject;
			size_t idOfAssignee;
			std::string title;
			std::string description;
			std::string status;
			std::time_t createdOn;
			size_t idOfCreator;
			std::time_t lastChange;
			size_t idOfLastChange;
		};
	}
}
