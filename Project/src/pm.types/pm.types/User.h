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
		};

		struct Project {
			std::string Title;
			std::string Description;
			std::time_t createdOn;
			size_t idOfCreator;
			std::time_t lastChange;
			size_t idOfUserChange;
		};
	}
}
