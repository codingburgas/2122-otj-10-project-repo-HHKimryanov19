#include <iostream>
#include<fstream>
#include<string>
#include "..\pm.dal\UserStore.h"
#include "..\pm.types\User.h"
#include <conio.h>

using namespace std;

int main()
{
	vector<pm::type::User> users;
	pm::type::User newUser;
	pm::dal::UserStore userFunc;
	int n;
	users = userFunc.getAll();
	while (_getch()!=27)
	{
		userFunc.create(&newUser);
		users.push_back(newUser);
		cout << endl;
	}
	
	for (auto i : users)
	{
		cout << i.id << ". " << i.FirstName << " " << i.LastName << " " << i.age << " " << i.email << " " << i.passwordHash << " " << i.createdOn<<endl;
	}

	cout << endl;

	cin >> n;
	userFunc.remove(&users, n);
	cout << endl;
	for (auto i : users)
	{
		cout << i.id << ". " << i.FirstName << " " << i.LastName << " " << i.age << " " << i.email << " " << i.passwordHash << " " << i.createdOn << endl;
	}

	cout << endl;
	cin >> n;
	cout << endl;

	for (int i = 0; i< users.size();i++)
	{
		if (i + 1 == n)
		{
			userFunc.update(&users[i]);
		}
	}



	cout << endl;
	for (auto i : users)
	{
		cout << i.id << ". " << i.FirstName << " " << i.LastName << " " << i.age << " " << i.email << " " << i.passwordHash << " " << i.createdOn << endl;
	}
}
