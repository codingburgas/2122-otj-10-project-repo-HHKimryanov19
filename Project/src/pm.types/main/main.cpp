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

void buttonsLogIn() {
	cout << "  __________________" << endl;
	cout << " /                  \\" << endl;
	cout << "{       Log in       }" << endl;
	cout << " \\__________________/" << endl;
}

void buttonsUpdate() {
	cout << "  __________________" << endl;
	cout << " /                  \\" << endl;
	cout << "{   Update account   }" << endl;
	cout << " \\__________________/" << endl;
}

void menuAdmin(vector<pm::type::User> users) {
	int n = 1, n1 = 0;
	bool updatePress = false, createPress = false, removePress = false;
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
			if (_getch() == 13)
			{
				system("CLS");
				createPress = true;
			}
			while (createPress)
			{
				if (_getch() == 27)
				{
					cout << "Create";
					createPress = false;
				}
			}
			break;
		case 2:
			system("CLS");
			cout << "\x1b[1;30m";
			buttonCreate();
			cout << "\x1b[1;37m";
			buttonsRemove();
			cout << "\x1b[1;30m";
			buttonsUpdate();
			if (_getch() == 13)
			{
				system("CLS");
				removePress = true;
			}

			while (removePress)
			{
				if (_getch() == 27)
				{
					cout << "Remove" << endl;
					removePress = false;
				}
			}
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

void startMenu(vector<pm::type::User> users)
{
	bool logIn = false, createButton = false;
	int n = 1;
	int n1;
	while (true)
	{
		switch (n)
		{
		case 1:
			system("CLS");
			cout << "\x1b[1;37m";
			buttonsLogIn();
			cout << "\x1b[1;30m";
			buttonCreate();
			cout << "\x1b[1;37m";
			n1 = _getch();
			if (n1 == 13)
			{
				system("CLS");
				logIn = true;
			}
			break;
		case 2:
			system("CLS");
			cout << "\x1b[1;30m";
			buttonsLogIn();
			cout << "\x1b[1;37m";
			buttonCreate();
			n1 = _getch();
			if (n1 == 13)
			{
				system("CLS");
				createButton = true;
			}
			break;
		}
		if (logIn == false && createButton == false)
		{
			switch (n1)
			{
			case KEY_UP:
				if (n == 1)
				{
					n = 2;
					system("CLS");
				}
				else
				{
					n--;
				}
				break;
			case KEY_DOWN:
				if (n == 2)
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
		else
		{
			int j = users.size();
			bool adminLogIn = false, userLogIn = false;
			string userName, password;
			cout << "User name: ";
			cin >> userName;
			cout << "Password: ";
			cin >> password;
			if (logIn)
			{
				if (j != 0)
				{
					if (userName == "admin" && password == "adminpass")
					{
						adminLogIn = true;
						n = 3;
					}
					else
					{
						for (size_t i = 0; i < users.size(); i++)
						{
							if (users[i].FirstName == userName && users[i].passwordHash == password)
							{
								n = 3;
								userLogIn = false;
								break;
							}
						}
					}
				}
				else
				{
					if (userName == "admin" && password == "adminpass")
					{
						cout << "You are admin" << endl;
						adminLogIn = true;
						n = 3;
					}
				}

				if (adminLogIn)
				{
					menuAdmin(users);
				}

				if (userLogIn)
				{
					cout << "Today is Wednesday" << endl;
				}
			}
		}


	}
}

int main()
{
	vector<pm::type::User> users;
	pm::type::User newUser;
	pm::dal::UserStore userFunc;
	users = userFunc.getAll();

	startMenu(users);
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




	/*size_t j = users.size();

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
		}*/
