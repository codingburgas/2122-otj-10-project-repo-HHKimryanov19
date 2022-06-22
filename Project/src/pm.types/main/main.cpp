#include <iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include "..\pm.dal\UserStore.h"
#include "..\pm.types\User.h"
#include <conio.h>

using namespace std;
#define KEY_UP 72
#define KEY_DOWN 80

void buttonCreate() {
	cout << "  __________________" << endl;
	cout << " /                  \\" << endl;
	cout << "{   Create account   }" << endl;
	cout << " \\__________________/" << endl;
}

void buttonsRemove() {
	cout << "  __________________" << endl;
	cout << " /                  \\" << endl;
	cout << "{   Remove account   }" << endl;
	cout << " \\__________________/" << endl;
}

void buttonsAdmin() {
	cout << "  __________________" << endl;
	cout << " /                  \\" << endl;
	cout << "{   Remove account   }" << endl;
	cout << " \\__________________/" << endl;
}

void buttonsRegister() {
	cout << "  __________________" << endl;
	cout << " /                  \\" << endl;
	cout << "{   Registr   }" << endl;
	cout << " \\__________________/" << endl;
}

void buttonsUpdate() {
	cout << "  __________________" << endl;
	cout << " /                  \\" << endl;
	cout << "{   Update account   }" << endl;
	cout << " \\__________________/" << endl;
}

void menuButtons(vector<pm::type::User> users) {
	int n = 1,n1 = 0;
	bool updatePress = false;
	pm::dal::UserStore userFunc;
	while (true)
	{
		switch (n)
		{
		case 1:
			system("CLS");
			cout << "\x1b[1;37m";
			buttonCreate();
			cout << "\x1b[1;30m";
			buttonsRemove();
			buttonsUpdate();
			break;
		case 2:
			system("CLS");
			cout << "\x1b[1;30m";
			buttonCreate();
			cout << "\x1b[1;37m";
			buttonsRemove();
			cout << "\x1b[1;30m";
			buttonsUpdate();
			break;
		case 3:
			system("CLS");
			cout << "\x1b[1;30m";
			buttonCreate();
			buttonsRemove();
			cout << "\x1b[1;37m";
			buttonsUpdate();
			if (_getch() == 13)
			{
				system("CLS");
				updatePress = true;
			}
			while (updatePress)
			{
				cin >> n1;
				for (int i = 0; i < users.size(); i++)
				{
					if (users[i].id == n1)
					{
						userFunc.update(&users[i]);
						n1 = 0;
						break;
					}
				}
				if (n1 != 0)
				{
					cout << "That user hasn't been found" << endl;
				}
				if (_getch() == 27)
				{
					updatePress = false;
				}
			}
			break;
		}

		switch (_getch())
		{
		case KEY_UP:
			if (n == 1)
			{
				n = 3;
				system("CLS");
			}
			else
			{
				n--;
			}
			break;
		case KEY_DOWN:
			if (n == 3)
			{
				n = 1;
			}
			else
			{
				n++;
			}
			break;
		}
	}
}

int main()
{
	vector<pm::type::User> users;
	pm::type::User newUser;
	pm::dal::UserStore userFunc;
	users = userFunc.getAll();

	size_t j = users.size();

	bool nameLogin = false, passwordLogin = false;
	string userName, password;
	cout << "User name: ";
	cin >> userName;
	cout << endl << "Password: ";
	cin>> password;
	if (j != 0)
	{
		for (size_t i = 0; i < users.size(); i++)
		{
			if (users[i].FirstName == userName && users[i].passwordHash == password)
			{
				cout << "You are stupid";
				break;
			}
		}
	}
	else
	{
		if (userName == "admin" && password == "adminpass")
		{
			cout << "You are admin";
		}
	}
}

/*while (_getch() != 27)
	{
		userFunc.create(&newUser);
		users.push_back(newUser);
		cout << endl;
	}

	for (auto i : users)
	{
		cout << i.id << ". " << i.FirstName << " " << i.LastName << " " << i.age << " " << i.email << " " << i.passwordHash << " " << i.createdOn << endl;
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

	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].id == n)
		{
			userFunc.update(&users[i]);
		}
	}



	cout << endl;
	for (auto i : users)
	{
		cout << i.id << ". " << i.FirstName << " " << i.LastName << " " << i.age << " " << i.email << " " << i.passwordHash << " " << i.createdOn << endl;
	}*/
