#include "pch.h"
#include<string>
#include<conio.h>
#include "..\pm.dal\UserStore.h"
#include "..\pm.dal\Header.h"
#include "..\consoleApp\Header.h"
#include "..\pm.dal\Header1.h"
#include "..\pm.types\User.h"
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

void backButton() {
	cout << "  __________________" << endl;
	cout << " /                  \\" << endl;
	cout << "{        Back        }" << endl;
	cout << " \\__________________/" << endl;
}

void usersManagement() {
	cout << "  __________________" << endl;
	cout << " /                  \\" << endl;
	cout << "{  Users Management  }" << endl;
	cout << " \\__________________/" << endl;
}

void projectsManagement() {
	cout << "  __________________" << endl;
	cout << " /                  \\" << endl;
	cout << "{ Project Management }" << endl;
	cout << " \\__________________/" << endl;
}

void tasksManagement() {
	cout << "  __________________" << endl;
	cout << " /                  \\" << endl;
	cout << "{   Task Management  }" << endl;
	cout << " \\__________________/" << endl;
}

void assignUserButton()
{
	cout << "  __________________" << endl;
	cout << " /                  \\" << endl;
	cout << "{     Assign user    }" << endl;
	cout << " \\__________________/" << endl;
}

void assignTeamButton()
{
	cout << "  __________________" << endl;
	cout << " /                  \\" << endl;
	cout << "{     Assign team    }" << endl;
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

void displayTeam(pm::type::Team team, pm::type::User createrUser, pm::type::User changerUser)
{
	cout << team.id << ". " << team.Title << endl;

	cout << "Created on: " << team.createdOn << endl;
	cout << "Created by: " << createrUser.FirstName << " " << createrUser.LastName << endl;

	cout << "Last change: " << team.lastChange << endl;
	cout << "Last changed by: " << changerUser.FirstName << " " << changerUser.LastName << endl;

}

void menuAdminUser(vector<pm::type::User>& users, pm::type::User& currentUser) {
	int Event;
	int option = 1, updateId, userId;
	string choice;
	pm::dal::UserStore userFunc;
	while (true)
	{
		switch (option)
		{
		case 1:
			system("CLS");
			cout << "\x1b[1;37m";
			displayUsersButton();
			cout << "\x1b[1;30m";
			buttonCreate();
			buttonsRemove();
			buttonsUpdate();
			backButton();
			cout << "\x1b[1;37m";
			Event = _getch();
			if (Event == 13)
			{
				Event = 1;
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
			backButton();
			cout << "\x1b[1;37m";
			Event = _getch();
			if (Event == 13)
			{
				Event = 2;
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
			backButton();
			cout << "\x1b[1;37m";
			Event = _getch();
			if (Event == 13)
			{
				Event = 3;
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
			cout << "\x1b[1;30m";
			backButton();
			cout << "\x1b[1;37m";
			Event = _getch();
			if (Event == 13)
			{
				Event = 4;
			}
			break;
		case 5:
			system("CLS");
			displayUsersButton();
			buttonCreate();
			buttonsRemove();
			buttonsUpdate();
			cout << "\x1b[1;37m";
			backButton();
			cout << "\x1b[1;37m";
			Event = _getch();
			if (Event == 13)
			{
				Event = 5;
			}
			break;
		}
		switch (Event)
		{
		case KEY_DOWN:
			if (option == 5)
			{
				option = 1;
			}
			else
			{
				option++;
			}
			break;
		case KEY_UP:
			if (option == 1)
			{
				option = 5;
			}
			else
			{
				option--;
			}
			break;
		case 1:
			system("CLS");
			while (true)
			{
				userFunc.displayUsers(users);
				cout << "Which user do you want to see? - ";
				cin >> userId;
				cout << endl;
				pm::type::User wantedUser = userFunc.getById(users, userId);
				displayUser(wantedUser, userFunc.getById(users, wantedUser.idOfCreater),
					userFunc.getById(users, wantedUser.idOfUserChange));
				cout << endl;
				cout << "Press enter to update another user or escape to go back" << endl;
				Event = _getch();
				if (Event == 27)
				{
					option = 1;
					break;
				}
				else
				{
					system("CLS");
				}
			}
			break;
		case 2:
			system("CLS");
			cout << "Create new user" << endl << endl;
			while (true)
			{
				users = userFunc.create(users, currentUser.id);
				cout << "Press enter to create another user or escape to go back" << endl;
				Event = _getch();
				if (Event == 27)
				{
					option = 1;
					break;
				}
				else
				{
					system("CLS");
				}
			}
			break;
		case 3:
			system("CLS");
			while (true)
			{
				size_t userId;
				userFunc.displayUsers(users);
				cout << endl << "Who user want to delete? - ";
				cin >> userId;
				users = userFunc.remove(users, userId);
				cout << "Press enter to remove another user or escape to go back" << endl;
				Event = _getch();
				if (Event == 27)
				{
					option = 1;
					break;
				}
				else
				{
					system("CLS");
				}
			}
			break;
		case 4:
			system("CLS");
			while (true)
			{
				userFunc.displayUsers(users);
				cout << endl << "Who user do you want to edit? - ";
				cin >> updateId;
				for (int i = 0; i < users.size(); i++)
				{
					if (users[i].id == updateId)
					{
						users = userFunc.update(users, i, currentUser.id);
						string str;
						updateId = 0;
						break;
					}
				}
				if (updateId != 0)
				{
					cout << "User with that id hasn't been found" << endl;
				}
				cout << "Press enter to update another user or escape to go back";
				Event = _getch();
				if (Event == 27)
				{
					option = 1;
					break;
				}
				else
				{
					system("CLS");
				}
			}
			break;
		case 5:
			return;
			break;
		}
	}
}

void menuAdminTeam(vector<pm::type::Team>& teams, vector<pm::type::User>& users, pm::type::User& currentUser)
{
	int Event;
	int option = 1, updateId, teamId;
	pm::dal::TeamStore teamFunc;
	pm::dal::UserStore userFunc;
	while (true)
	{
		switch (option)
		{
		case 1:
			system("CLS");
			cout << "\x1b[1;37m";
			displayUsersButton();
			cout << "\x1b[1;30m";
			buttonCreate();
			buttonsRemove();
			buttonsUpdate();
			assignUserButton();
			backButton();
			cout << "\x1b[1;37m";
			Event = _getch();
			if (Event == 13)
			{
				Event = 1;
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
			assignUserButton();
			backButton();
			cout << "\x1b[1;37m";
			Event = _getch();
			if (Event == 13)
			{
				Event = 2;
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
			assignUserButton();
			backButton();
			cout << "\x1b[1;37m";
			Event = _getch();
			if (Event == 13)
			{
				Event = 3;
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
			cout << "\x1b[1;30m";
			assignUserButton();
			backButton();
			cout << "\x1b[1;37m";
			Event = _getch();
			if (Event == 13)
			{
				Event = 4;
			}
			break;
		case 5:
			system("CLS");
			cout << "\x1b[1;30m";
			displayUsersButton();
			buttonCreate();
			buttonsRemove();
			buttonsUpdate();
			cout << "\x1b[1;37m";
			assignUserButton();
			cout << "\x1b[1;30m";
			backButton();
			cout << "\x1b[1;37m";
			Event = _getch();
			if (Event == 13)
			{
				Event = 5;
			}
			break;
		case 6:
			system("CLS");
			cout << "\x1b[1;30m";
			displayUsersButton();
			buttonCreate();
			buttonsRemove();
			buttonsUpdate();
			assignUserButton();
			cout << "\x1b[1;37m";
			backButton();
			Event = _getch();
			if (Event == 13)
			{
				Event = 6;
			}
			break;
		}
		switch (Event)
		{
		case KEY_DOWN:
			if (option == 6)
			{
				option = 1;
			}
			else
			{
				option++;
			}
			break;
		case KEY_UP:
			if (option == 1)
			{
				option = 6;
			}
			else
			{
				option--;
			}
			break;
		case 1:
			system("CLS");
			while (true)
			{
				teamFunc.displayTeams(teams);
				cout << "Which team do you want to see? - ";
				cin >> teamId;
				cout << endl;
				pm::type::Team wantedTeam = teamFunc.getById(teams, teamId);
				displayTeam(wantedTeam, userFunc.getById(users, wantedTeam.idOfCreator),
					userFunc.getById(users, wantedTeam.idOfUserChange));
				cout << endl;
				cout << "Press enter to update another team or escape to go back" << endl;
				Event = _getch();
				if (Event == 27)
				{
					option = 1;
					break;
				}
				else
				{
					system("CLS");
				}
			}
			break;
		case 2:
			system("CLS");
			cout << "Create new team" << endl << endl;
			while (true)
			{
				teams = teamFunc.create(teams, currentUser);
				cout << "Press enter to create another user or escape to go back" << endl;
				Event = _getch();
				if (Event == 27)
				{
					option = 1;
					break;
				}
				else
				{
					system("CLS");
				}
			}
			break;
		case 3:
			system("CLS");
			while (true)
			{
				teamFunc.displayTeams(teams);
				cout << endl << "Who user want to delete? - ";
				cin >> teamId;
				teams = teamFunc.remove(teams, teamId);
				cout << "Press enter to remove another user or escape to go back" << endl;
				Event = _getch();
				if (Event == 27)
				{
					option = 1;
					break;
				}
				else
				{
					system("CLS");
				}
			}
			break;
		case 4:
			system("CLS");
			while (true)
			{
				teamFunc.displayTeams(teams);
				cout << endl << "Who user do you want to edit? - ";
				cin >> updateId;
				for (size_t i = 0; i < teams.size(); i++)
				{
					if (teams[i].id == updateId)
					{
						teams = teamFunc.update(teams, i, currentUser.id);
						string str;
						updateId = 0;
						break;
					}
				}
				if (updateId != 0)
				{
					cout << "User with that id hasn't been found" << endl;
				}
				cout << "Press enter to update another user or escape to go back";
				Event = _getch();
				if (Event == 27)
				{
					option = 1;
					break;
				}
				else
				{
					system("CLS");
				}
			}
			break;
		case 5:
			system("CLS");
			if (teams.size() != 0)
			{
				while (true)
				{

					userFunc.displayUsers(users);
					int idOfUser;
					cout << "Choose user by Id: ";
					cin >> idOfUser;
					system("CLS");

					size_t idOfTeam, indexOfTeam = 0;
					teamFunc.displayTeams(teams);
					cout << "Choose team by Id: ";
					cin >> idOfTeam;
					for (size_t i = 0; i < teams.size(); i++)
					{
						if (teams[i].id == idOfTeam)
						{
							indexOfTeam = i;
						}
					}
					system("CLS");

					teams = teamFunc.asignToTeam(teams, indexOfTeam, idOfUser);
					cout << "Press enter to update another user or escape to go back";
					Event = _getch();
					if (Event == 27)
					{
						option = 1;
						break;
					}
					else
					{
						system("CLS");
					}
				}
			}
			else
			{
				option = 1;
				Event = 0;
			}
			break;
		case 6:
			return;
			break;
		}
	}
}

void managementMenuAdmin(vector<pm::type::User>& users, pm::type::User& currentUser, vector<pm::type::Team>& teams)
{
	int n = 1;
	int Event;
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
			backButton();
			cout << "\x1b[1;37m";
			Event = _getch();
			if (Event == 13)
			{
				Event = 1;
			}
			break;
		case 2:
			system("CLS");
			cout << "\x1b[1;30m";
			usersManagement();
			cout << "\x1b[1;37m";
			teamsManagement();
			cout << "\x1b[1;30m";
			backButton();
			cout << "\x1b[1;37m";
			Event = _getch();
			if (Event == 13)
			{
				Event = 2;
			}
			break;
		case 3:
			system("CLS");
			cout << "\x1b[1;30m";
			usersManagement();
			teamsManagement();
			cout << "\x1b[1;37m";
			backButton();
			Event = _getch();
			if (Event == 13)
			{
				Event = 3;
			}
			break;
		}

		switch (Event)
		{
		case KEY_UP:
			if (n == 1)
			{
				n = 3;
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
		case 1:
			menuAdminUser(users, currentUser);
			break;
		case 2:
			menuAdminTeam(teams, users, currentUser);
			break;
		case 3:
			return;
			break;
		}
	}
}

void menuUserProject(vector<pm::type::Project>& projects,pm::type::User& currentUser,vector<pm::type::Team>& teams)
{
	int Event = 0;
	int option = 1, updateId, teamId;
	pm::dal::TeamStore teamFunc;
	pm::dal::UserStore userFunc;
	pm::dal::ProjectStore projectFunc;
	while (true)
	{
		switch (option)
		{
		case 1:
			system("CLS");
			cout << "\x1b[1;37m";
			displayUsersButton();
			cout << "\x1b[1;30m";
			buttonCreate();
			buttonsRemove();
			buttonsUpdate();
			assignTeamButton();
			backButton();
			cout << "\x1b[1;37m";
			Event = _getch();
			if (Event == 13)
			{
				Event = 1;
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
			assignTeamButton();
			backButton();
			cout << "\x1b[1;37m";
			Event = _getch();
			if (Event == 13)
			{
				Event = 2;
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
			assignTeamButton();
			backButton();
			cout << "\x1b[1;37m";
			Event = _getch();
			if (Event == 13)
			{
				Event = 3;
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
			cout << "\x1b[1;30m";
			assignTeamButton();
			backButton();
			cout << "\x1b[1;37m";
			Event = _getch();
			if (Event == 13)
			{
				Event = 4;
			}
			break;
		case 5:
			system("CLS");
			cout << "\x1b[1;30m";
			displayUsersButton();
			buttonCreate();
			buttonsRemove();
			buttonsUpdate();
			cout << "\x1b[1;37m";
			assignTeamButton();
			cout << "\x1b[1;30m";
			backButton();
			cout << "\x1b[1;37m";
			Event = _getch();
			if (Event == 13)
			{
				Event = 5;
			}
			break;
		case 6:
			system("CLS");
			cout << "\x1b[1;30m";
			displayUsersButton();
			buttonCreate();
			buttonsRemove();
			buttonsUpdate();
			assignTeamButton();
			cout << "\x1b[1;37m";
			backButton();
			Event = _getch();
			if (Event == 13)
			{
				Event = 6;
			}
			break;
		}

		switch (Event)
		{
		case KEY_DOWN:
			if (option == 6)
			{
				option = 1;
			}
			else
			{
				option++;
			}
			break;
		case KEY_UP:
			if (option == 1)
			{
				option = 6;
			}
			else
			{
				option--;
			}
			break;
		case 1:
			system("CLS");
			while (true)
			{
				projectFunc.displayProjects(projects,currentUser,teams);
				Event = _getch();
				if (Event == 27)
				{
					option = 1;
					break;
				}
				else
				{
					system("CLS");
				}
			}
			break;
		case 2:
			system("CLS");

			projectFunc.create(projects, currentUser.id);
			Event = _getch();
			if (Event == 27)
			{
				option = 1;
				break;
			}
			else
			{
				system("CLS");
			}
			break;
		case 3:
			system("CLS");
			while (true)
			{
				int idOfProject = 0;
				cin >> idOfProject;
				projects = projectFunc.remove(projects, currentUser.id, idOfProject);
				Event = _getch();
				if (Event == 27)
				{
					option = 1;
					break;
				}
				else
				{
					system("CLS");
				}
			}
			break;
		case 4:
			system("CLS");
			while (true)
			{
				int idOfProject;
				cin >> idOfProject;
				projectFunc.update(projects,currentUser.id,idOfProject);
				if (Event == 27)
				{
					option = 1;
					break;
				}
				else
				{
					system("CLS");
				}
			}
			break;
		case 5:
			system("CLS");
			if (true)
			{
				while (true)
				{
					Event = _getch();
					if (Event == 27)
					{
						option = 1;
						break;
					}
					else
					{
						system("CLS");
					}
				}
			}
			else
			{
				option = 1;
				Event = 0;
			}
			break;
		case 6:
			return;
			break;
		}
	}
}

void managementMenuUser(vector<pm::type::Project>& projects,pm::type::User& currentUser,vector<pm::type::Team>& teams)
{
	int Event = 1, n = 1;
	while (true)
	{
		switch (n)
		{
		case 1:
			system("CLS");
			cout << "\x1b[1;37m";
			projectsManagement();
			cout << "\x1b[1;30m";
			tasksManagement();
			backButton();
			cout << "\x1b[1;37m";
			Event = _getch();
			if (Event == 13)
			{
				Event = 1;
			}
			break;
		case 2:
			system("CLS");
			cout << "\x1b[1;30m";
			projectsManagement();
			cout << "\x1b[1;37m";
			tasksManagement();
			cout << "\x1b[1;30m";
			backButton();
			cout << "\x1b[1;37m";
			Event = _getch();
			if (Event == 13)
			{
				Event = 2;
			}
			break;

		case 3:
			system("CLS");
			cout << "\x1b[1;30m";
			projectsManagement();
			tasksManagement();
			cout << "\x1b[1;37m";
			backButton();
			Event = _getch();
			if (Event == 13)
			{
				Event = 3;
			}
			break;
		}

		switch (Event)
		{
		case KEY_UP:
			if (n == 1)
			{
				n = 3;
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
		case 1:
			system("CLS");
			menuUserProject(projects,currentUser,teams);
			break;
		case 2:
			system("CLS");
			cout << "You are not stupid";
			break;
		case 3:
			return;
			break;
		}
	}
}

void startMenu()
{
	pm::dal::UserStore userFunc;
	vector<pm::type::User> users = userFunc.getAll();
	pm::dal::TeamStore teamFunc;
	vector<pm::type::Team> teams = teamFunc.getAll();
	pm::dal::ProjectStore projectFunc;
	vector<pm::type::Project> projects = projectFunc.getAll();
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
						adminLogIn = true;
						n = 3;
					}
				}

				if (adminLogIn)
				{
					managementMenuAdmin(users, currentUser, teams);
					logIn = false;
					createButton = false;
					adminLogIn = false;
					n = 1;
				}

				if (userLogIn)
				{
					managementMenuUser(projects,currentUser,teams);
					logIn = false;
					createButton = false;
					userLogIn = false;
					n = 1;
				}
			}
		}


	}
}
