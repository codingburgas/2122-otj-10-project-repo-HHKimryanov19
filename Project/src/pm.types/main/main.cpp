#include <iostream>
#include<string>
#include "..\pm.dal\UserStore.h"
#include "..\pm.types\User.h"

using namespace std;

int main()
{
	vector<pm::type::User> user;
	pm::dal::UserStore u;
	user = u.getAll();
	for (int i = 0; i < user.size(); i++)
	{
		cout << user[i].FirstName << " ";
	}
}
