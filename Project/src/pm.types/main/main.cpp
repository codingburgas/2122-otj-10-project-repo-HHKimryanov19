#include <iostream>
#include"../consoleApp/Header.h"
using namespace std;

//int update(vector<pm::type::User> users, pm::dal::UserStore userFunc,pm::type::User currentUser,int& n)
//{
//	int Event,n1;
//	bool updatePress = false;
//	system("CLS");
//	cout << "\x1b[1;30m";
//	displayUsersButton();
//	buttonCreate(); 
//	buttonsRemove();
//	cout << "\x1b[1;37m";
//	buttonsUpdate();
//	cout << "\x1b[1;30m";
//	backButton();
//	Event = _getch();
//	if (Event == 13)
//	{
//		system("CLS");
//		updatePress = true;
//	}
//
//	while (updatePress)
//	{
//		userFunc.displayUsers(users);
//		cout << endl << "Who user do you want to edit? - ";
//		cin >> n1;
//		for (int i = 0; i < users.size(); i++)
//		{
//			if (users[i].id == n1)
//			{
//				userFunc.update(users, users[i], currentUser.id);
//				n1 = 0;
//				break;
//			}
//		}
//		if (n1 != 0)
//		{
//			cout << "User with that id hasn't been found" << endl;
//		}
//		cout << "Press enter..." << endl;
//		if (_getch() == 13)
//		{
//			n = -1;
//			updatePress = false;
//		}
//		else
//		{
//			system("CLS");
//		}
//	}
//	return Event;
//}
//int create()
//{
//	system("CLS");
//	cout << "\x1b[1;30m";
//	displayUsersButton();
//	cout << "\x1b[1;37m";
//	buttonCreate();
//	cout << "\x1b[1;30m";
//	buttonsRemove();
//	buttonsUpdate();
//	backButton();
//	cout << "\x1b[1;37m";
//	Event = _getch();
//	if (Event == 13)
//	{
//		system("CLS");
//		createPress = true;
//	}
//
//	if (createPress)
//	{
//		cout << "First name: ";
//		cin >> FirstName;
//		cout << "Last name: ";
//		cin >> LastName;
//		cout << "Email: ";
//		cin >> email;
//		cout << "Password: ";
//		cin >> passwordHash;
//		cout << "Age: ";
//		cin >> age;
//		cout << "This user is admin(true/false) - ";
//		cin >> adminPrivileges;
//		userFunc.create(users, currecntUser.id, FirstName, LastName, email, passwordHash, adminPrivileges, age);
//		n = -1;
//		createPress = false;
//	}
//}
//int display()
//{
//	system("CLS");
//	cout << "\x1b[1;37m";
//	displayUsersButton();
//	cout << "\x1b[1;30m";
//	buttonCreate();
//	buttonsRemove();
//	buttonsUpdate();
//	backButton();
//	cout << "\x1b[1;37m";
//	Event = _getch();
//	if (Event == 13)
//	{
//		system("CLS");
//		while (true)
//		{
//			userFunc.displayUsers(users);
//			cout << "Which user do you want to see? - ";
//			cin >> userId;
//			cout << endl;
//			pm::type::User wantedUser = userFunc.getById(users, userId);
//			displayUser(wantedUser, userFunc.getById(users, wantedUser.idOfCreater),
//				userFunc.getById(users, wantedUser.idOfUserChange));
//			cout << endl;
//			cout << "Do you want to go back?(YES/NO)" << endl;
//			cin >> choice;
//			if (choice == "YES")
//			{
//				n = -1;
//				break;
//			}
//			else
//			{
//				system("CLS");
//			}
//		}
//	}
//}
//int remove()
//{
//	system("CLS");
//	cout << "\x1b[1;30m";
//	displayUsersButton();
//	buttonCreate();
//	cout << "\x1b[1;37m";
//	buttonsRemove();
//	cout << "\x1b[1;30m";
//	buttonsUpdate();
//	backButton();
//	cout << "\x1b[1;37m";
//	Event = _getch();
//	if (Event == 13)
//	{
//		system("CLS");
//		removePress = true;
//	}
//
//	while (removePress)
//	{
//		size_t userId;
//		userFunc.displayUsers(users);
//		cout << endl << "Who user want to delete? - ";
//		cin >> userId;
//		userFunc.remove(users, userId);
//		cout << "Do you want another user?(YES/NO)" << endl;
//		string choice;
//		cin >> choice;
//		if (choice == "NO")
//		{
//			n = -1;
//			removePress = false;
//		}
//	}
//}
//int back()
//{
//	system("CLS");
//	cout << "\x1b[1;30m";
//	displayUsersButton();
//	buttonCreate();
//	buttonsRemove();
//	buttonsUpdate();
//	cout << "\x1b[1;37m";
//	backButton();
//	cout << "\x1b[1;30m";
//	Event = _getch();
//	if (Event == 13)
//	{
//		return;
//	}
//	break;
//}


int main()
{
	startMenu();
	/*vector<pm::type::User> users;
	pm::type::User newUser;
	pm::dal::UserStore userFunc;
	users = userFunc.getAll();

	pm::dal::ProjectStore projectFunc;
	vector<pm::type::Project> projects;
	projects = projectFunc.getAll();
	projectFunc.update(&projects, 2, 3);
	projectFunc.displayProjects(projects,users[0]);

	vector<pm::type::Team> teams;
	pm::dal::TeamStore teamFunc;
	teams = teamFunc.getAll();
	projectFunc.displayProjects(projects, users[0]);*/
	/*for (size_t i = 0; i < projects.size(); i++)
	{
		cout << "Projects " << projects[i].id << ": " << endl;
		cout<< projects[i].assignedTeams.size();
		for (size_t j = 0; j < projects[i].assignedTeams.size(); j++)
		{
			cout << projects[i].assignedTeams[j].id << endl;
		}
		cout << endl;
	}*/
	/*int n;
	cin >> n;
	int wantedTeam = 0;
	std::vector<std::vector<size_t>> v = projectFunc.teamsInTheProject();
	v = projectFunc.asignToTeam(projects, projects[1].id, teams[0].id);
	for (int i = 0; i < projects.size(); i++)
	{
		if (projects[i].id == n)
		{
			wantedTeam = i;
		}
	}
	cout << endl;
	cout << projects[wantedTeam].Title << ": " << endl;
	for (int j = 0; j < v[wantedTeam].size(); j++)
	{
		for (int k = 0; k < teams.size(); k++)
		{
			if (teams[k].id == v[wantedTeam][j])
			{
				cout << teams[k].Title<<endl;
			}
		}
	}*/

	//startMenu(users);

	/*vector<pm::type::Team> teams;
	pm::dal::TeamStore teamFunc;
	teams = teamFunc.getAll();
	vector<vector<size_t>> v = teamFunc.usersInTheTeams();
	v = teamFunc.asignToTeam(teams, 5, 3);*/


	/*int n;
	cin >> n;
	int wantedTeam = 0;
	for (int i = 0; i < teams.size(); i++)
	{
		if (teams[i].id == n)
		{
			wantedTeam = i;
		}
	}

	cout << teams[wantedTeam].Title << ": " << endl;
	for (int j = 0; j < v[wantedTeam].size(); j++)
	{
		for (int k = 0; k < users.size(); k++)
		{
			if (users[k].id == v[wantedTeam][j])
			{
				cout << users[k].FirstName << " " << users[k].LastName << endl;
			}
		}
	}*/


	//for (int i = 0; i < teams.size(); i++)
	//{
	//	cout << teams[i].Title<<": "<< endl;
	//	for (int j = 0; j < v[i].size(); j++)
	//	{
	//		for (int k = 0; k < users.size(); k++)
	//		{
	//			if (users[k].id == v[i][j])
	//			{
	//				cout << users[k].FirstName << " " << users[k].LastName<<endl;
	//			}
	//		}
	//	}
	//	cout << endl;
	//}

	//teams.push_back(teamFunc.create(teams, users[0]));
	/*size_t n;
	cin >> n;

	teamFunc.displayTeams(teams);
	teamFunc.update(&teams[0], users[0]);
	teamFunc.displayTeams(teams);*/

	return 0;
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
