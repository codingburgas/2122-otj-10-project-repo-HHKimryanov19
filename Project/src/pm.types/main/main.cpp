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

void menuButtons() {
	int n = 0;
	while (true)
	{

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
			break;
		}
	}
}

int main()
{
	menuButtons();
	vector<pm::type::User> users;
	pm::type::User newUser;
	pm::dal::UserStore userFunc;
	int n;
	users = userFunc.getAll();
	while (_getch() != 27)
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
