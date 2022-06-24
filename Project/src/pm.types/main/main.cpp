#include <iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include "..\pm.dal\UserStore.h"
#include "..\pm.dal\Header.h"
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

void displayUsersButton()
{
	cout << "  __________________" << endl;
	cout << " /                  \\" << endl;
	cout << "{ Display all users  }" << endl;
	cout << " \\__________________/" << endl;
}

void teamsManagement() {
	cout << "  __________________" << endl;
	cout << " /                  \\" << endl;
	cout << "{  Teams Management  }" << endl;
	cout << " \\__________________/" << endl;
}

void usersManagement() {
	cout << "  __________________" << endl;
	cout << " /                  \\" << endl;
	cout << "{  Users Management  }" << endl;
	cout << " \\__________________/" << endl;
}

//menuAdmin(users,currentUser);

void displayUser(pm::type::User user, pm::type::User createrUser, pm::type::User changerUser)
{
	cout << user.id << ". " << user.FirstName << " " << user.LastName << endl;
	cout << "Age: " << user.age << endl;
	cout << "Email: " << user.email << endl;

	cout << "Created on: " << user.createdOn << endl;
	cout << "Last change: " << user.lastChange << endl;

	cout << "Created by: " << createrUser.FirstName << " " << createrUser.LastName << endl;
	cout << "Last changed by: " << changerUser.FirstName << " " << changerUser.LastName << endl;
}

void menuAdmin(vector<pm::type::User> users, pm::type::User currecntUser) {
	int n = 1, n1 = 0;
	bool updatePress = false, createPress = false, removePress = false, allUsersPress = false;
	pm::dal::UserStore userFunc;
	while (true)
	{
		switch (n)
		{
		case 1:
			system("CLS");
			cout << "\x1b[1;37m";
			displayUsersButton();
			cout << "\x1b[1;30m";
			buttonCreate();
			buttonsRemove();
			buttonsUpdate();
			cout << "\x1b[1;37m";
			if (_getch() == 13)
			{
				system("CLS");
				allUsersPress = true;
			}
			while (allUsersPress)
			{
				userFunc.displayUsers(users);
				cout << "Which user do you want to see? - ";
				size_t userId;
				cin >> userId;
				cout << endl;
				pm::type::User wantedUser = userFunc.getById(users, userId);
				displayUser(wantedUser, userFunc.getById(users, wantedUser.idOfCreater),
					userFunc.getById(users, wantedUser.idOfUserChange));
				cout << endl;
				cout << "Do you want to go back?(YES/NO)" << endl;
				string choice;
				cin >> choice;
				if (choice == "YES")
				{
					n = -1;
					allUsersPress = false;
				}
				else
				{
					system("CLS");
				}
			}
			break;
		case 2:
			system("CLS");
			cout << "\x1b[1;30m";
			displayUsersButton();
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
			if (createPress)
			{
				users.push_back(userFunc.create(users, currecntUser.id));
				n = -1;
				createPress = false;
			}
			break;
		case 3:
			system("CLS");
			cout << "\x1b[1;30m";
			displayUsersButton();
			buttonCreate();
			cout << "\x1b[1;37m";
			buttonsRemove();
			cout << "\x1b[1;30m";
			buttonsUpdate();
			cout << "\x1b[1;37m";
			if (_getch() == 13)
			{
				system("CLS");
				removePress = true;
			}

			while (removePress)
			{
				size_t userId;
				userFunc.displayUsers(users);
				cout << endl << "Who user want to delete? - ";
				cin >> userId;
				userFunc.remove(&users, userId);
				cout << "Do you want another user?(YES/NO)" << endl;
				string choice;
				cin >> choice;
				if (choice == "NO")
				{
					n = -1;
					removePress = false;
				}
			}
			break;
		case 4:
			system("CLS");
			cout << "\x1b[1;30m";
			displayUsersButton();
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
				userFunc.displayUsers(users);
				cout << endl << "Who user do you want to edit? - ";
				cin >> n1;
				for (int i = 0; i < users.size(); i++)
				{
					if (users[i].id == n1)
					{
						userFunc.update(&users,&users[i], currecntUser.id);
						n1 = 0;
						break;
					}
				}
				if (n1 != 0)
				{
					cout << "User with that id hasn't been found" << endl;
				}
				cout << "Press enter..." << endl;
				if (_getch()==13)
				{
					n = -1;
					updatePress = false;
				}
				else
				{
					system("CLS");
				}
			}
		}

		if (n != -1)
		{
			switch (_getch())
			{
			case KEY_UP:
				if (n == 1)
				{
					n = 4;
					system("CLS");
				}
				else
				{
					n--;
				}
				break;
			case KEY_DOWN:
				if (n == 4)
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
			n = 1;
		}
	}
}

void managementMenu(vector<pm::type::User> users, pm::type::User currentUser)
{
	bool teamM = false, userM = false;
	int n = 1;
	while (true)
	{
		switch (n)
		{
		case 1:
			system("CLS");
			cout << "\x1b[1;37m";
			usersManagement();
			cout << "\x1b[1;30m";
			teamsManagement();
			if (_getch() == 13)
			{
				menuAdmin(users, currentUser);
			}
			break;
		case 2:
			system("CLS");
			cout << "\x1b[1;30m";
			usersManagement();
			cout << "\x1b[1;37m";
			teamsManagement();
			break;
		}

		switch (_getch())
		{
		case KEY_UP:
			if (n == 1)
			{
				n = 2;
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
}

void startMenu(vector<pm::type::User> users)
{
	bool logIn = false, createButton = false;
	int n = 1;
	int n1;
	pm::type::User currentUser = users[0];
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
								if (users[i].adminPrivileges)
								{
									currentUser = users[i];
									adminLogIn = true;
								}
								else
								{
									userLogIn = true;
								}
								n = 3;

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
					managementMenu(users, currentUser);
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

	/*vector<pm::type::Team> teams;
	pm::dal::TeamStore teamFunc;
	teams = teamFunc.getAll();*/
	//teams.push_back(teamFunc.create(teams, users[0]));
	/*size_t n;
	cin >> n;

	teamFunc.displayTeams(teams);
	teamFunc.update(&teams[0], users[0]);
	teamFunc.displayTeams(teams);*/
	
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
