#pragma once
#include"pch.h"
#include<iostream>
#include<string>
#include<ctime>
#include<vector>

namespace pm {
	namespace type {
		struct User {
			size_t id;
			std::string firstName;
			std::string lastName;
			std::string email;
			unsigned short age;
			std::string passwordHash;
			std::time_t createdOn;
			std::time_t lastChange;
			size_t idOfCreator;
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
			std::vector<size_t> idOfUsers;
		};

		struct Project {
			size_t id;
			std::string title;
			std::string description;
			std::time_t createdOn;
			size_t idOfCreator;
			std::time_t lastChange;
			size_t idOfUserChange;
			std::vector<size_t> idOfTeams;
		};

		struct Task {
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
