#pragma once
#include"pch.h"
#include<string>
#include<ctime>

namespace pm::type {
	struct User {
		size_t id;
		std::string FirstName;
		std::string LastName;
		std::string email;
		unsigned short age;
		std::string passwordHash;
		std::time_t createdOn;
	};
}
