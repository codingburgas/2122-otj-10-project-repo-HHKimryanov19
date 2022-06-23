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
			bool adminPrivileges;
		};
	}
}
