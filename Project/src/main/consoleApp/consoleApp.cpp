#include "pch.h"
#include<string>
#include<conio.h>
#include "..\pm.dal\userStore.h"
#include "..\pm.dal\teamStore.h"
#include "..\consoleApp\consoleApp.h"
#include "..\pm.dal\projectStore.h"
#include "..\pm.dal\taskStore.h"
#include "..\pm.types\types.h"
#include"..\pm.tools\md5.h"
using namespace std;
#define KEY_UP 72
#define KEY_DOWN 80

void buttonCreate() {
	cout << "  __________________" << endl;
	cout << " /                  \\" << endl;
	cout << "{       Create       }" << endl;
	cout << " \\__________________/" << endl;
}

void buttonsRemove() {
	cout << "  __________________" << endl;
	cout << " /                  \\" << endl;
	cout << "{       Remove       }" << endl;
	cout << " \\__________________/" << endl;
}

void buttonsSignIn() {
	cout << "  __________________" << endl;
	cout << " /                  \\" << endl;
	cout << "{       Sign in      }" << endl;
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
	cout << "{       Update       }" << endl;
	cout << " \\__________________/" << endl;
}

void displayUsersButton()
{
	cout << "  __________________" << endl;
	cout << " /                  \\" << endl;
	cout << "{       Display      }" << endl;
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
	cout << user.id << ". " << user.firstName << " " << user.lastName << endl;
	cout << "Age: " << user.age << endl;
	cout << "Email: " << user.email << endl;

	cout << "Created on: " << user.createdOn << endl;
	cout << "Last change: " << user.lastChange << endl;
	if (user.idOfCreator == 0)
	{
		cout << "Created by: admin" << endl;
	}
	else
	{
		cout << "Created by: " << createrUser.firstName << " " << createrUser.lastName << endl;
	}

	cout << "Last changed by: " << changerUser.firstName << " " << changerUser.lastName << endl;
}

void displayTeam(vector<pm::type::Team> teams, size_t indexOfTeam, pm::type::User createrUser, pm::type::User changerUser)
{
	cout << teams[indexOfTeam].id << ". " << teams[indexOfTeam].Title << endl;

	cout << "Created on: " << teams[indexOfTeam].createdOn << endl;
	cout << "Created by: " << createrUser.firstName << " " << createrUser.lastName << endl;

	cout << "Last change: " << teams[indexOfTeam].lastChange << endl;
	cout << "Last changed by: " << changerUser.firstName << " " << changerUser.lastName << endl;

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
			cout << "\x1b[1;30m";
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
			if (users.size() != 0)
			{
				while (true)
				{
					if (users.size() != 0)
					{
						userFunc.displayUsers(users);
						cout << "Which user do you want to see? - ";
						cin >> userId;
						cout << endl;
						if (userFunc.checkId(users, userId))
						{
							pm::type::User wantedUser = userFunc.getById(users, userId);
							displayUser(wantedUser, userFunc.getById(users, wantedUser.idOfCreator),
								userFunc.getById(users, wantedUser.idOfUserChange));
							cout << endl;
						}
						else
						{
							cout << "There are not user with that id." << endl;
						}
						cout << "Press enter to display another user or escape to go back" << endl;
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
			}
			else
			{
				cout << "There are not users. Press escape to go back";
				Event = _getch();
				if (Event == 27)
				{
					option = 1;
					break;
				}
			}
			break;
		case 2:
			system("CLS");
			cout << "Create new user" << endl << endl;
			while (true)
			{
				users = userFunc.create(users, currentUser.id, 1);
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
			if (users.size() != 0)
			{
				while (true)
				{
					size_t userId;
					userFunc.displayUsers(users);
					cout << endl << "Who user want to delete? - ";
					cin >> userId;
					if (userFunc.checkId(users, userId))
					{
						users = userFunc.remove(users, userId);

					}
					else
					{
						cout << "There are not user with that id." << endl;
					}
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
			}
			else
			{
				cout << "There are not users. Press escape to go back";
				Event = _getch();
				if (Event == 27)
				{
					option = 1;
					break;
				}
			}
			break;
		case 4:
			system("CLS");
			if (users.size() != 0)
			{
				while (true)
				{
					userFunc.displayUsers(users);
					cout << endl << "Who user do you want to edit? - ";
					cin >> updateId;
					if (userFunc.checkId(users, updateId))
					{
						for (int i = 0; i < users.size(); i++)
						{
							if (users[i].id == updateId)
							{
								users = userFunc.update(users, i, currentUser.id);
								break;
							}
						}
					}
					else
					{
						cout << "There are not user with that id." << endl;
					}
					cout << "Press enter to edit another user or escape to go back";
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
				cout << "There are not users. Press escape to go back";
				Event = _getch();
				if (Event == 27)
				{
					option = 1;
					break;
				}
			}
			break;
		case 5:
			return;
			break;
		}
	}
}
//ready

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
			if (teams.size() != 0)
			{
				while (true)
				{
					teamFunc.displayTeams(teams);
					cout << "Which team do you want to see? - ";
					cin >> teamId;
					if (teamFunc.checkId(teams, teamId))
					{
						cout << endl;
						size_t wantedTeam = teamFunc.getById(teams, teamId);
						displayTeam(teams, wantedTeam, userFunc.getById(users, teams[wantedTeam].idOfUserChange), userFunc.getById(users, teams[wantedTeam].idOfUserChange));
						cout << endl;
					}
					else
					{
						cout << "There is not team with that id." << endl;
					}
					cout << "Press enter to display another team or escape to go back" << endl;
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
				cout << "There are not teams. Press escape to go back";
				Event = _getch();
				if (Event == 27)
				{
					option = 1;
					break;
				}
			}
			break;
		case 2:
			system("CLS");
			cout << "Create new team" << endl << endl;
			while (true)
			{
				teams = teamFunc.create(teams, currentUser);
				cout << "Press enter to create another team or escape to go back" << endl;
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
			if (teams.size() != 0)
			{
				while (true)
				{
					teamFunc.displayTeams(teams);
					cout << endl << "Who user want to delete? - ";
					cin >> teamId;
					if (teamFunc.checkId(teams, teamId))
					{
						teams = teamFunc.remove(teams, teamId);
					}
					else
					{
						cout << "There is not a team with that id." << endl;
					}
					cout << "Press enter to remove another team or escape to go back" << endl;
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
				cout << "There are not teams. Press escape to go back";
				Event = _getch();
				if (Event == 27)
				{
					option = 1;
					break;
				}
			}
			break;
		case 4:
			system("CLS");
			if (teams.size() != 0)
			{
				while (true)
				{
					teamFunc.displayTeams(teams);
					cout << endl << "Who user do you want to edit? - ";
					cin >> updateId;
					if (teamFunc.checkId(teams, updateId))
					{
						for (size_t i = 0; i < teams.size(); i++)
						{
							if (teams[i].id == updateId)
							{
								teams = teamFunc.update(teams, i, currentUser.id);
								break;
							}
						}
					}
					else
					{
						cout << "There are not user with that id." << endl;
					}
					cout << "Press enter to edit another team or escape to go back";
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
				cout << "There are not teams. Press escape to go back";
				Event = _getch();
				if (Event == 27)
				{
					option = 1;
					break;
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
					if (userFunc.checkId(users, idOfUser) && teamFunc.checkId(teams, idOfTeam))
					{
						for (size_t i = 0; i < teams.size(); i++)
						{
							if (teams[i].id == idOfTeam)
							{
								indexOfTeam = i;
							}
						}
						system("CLS");
						if (teamFunc.checkForAdded(teams[indexOfTeam], idOfUser) == false)
						{
							teams = teamFunc.asignToTeam(teams, indexOfTeam, idOfUser);
						}
						else
						{
							cout << "Sorry! That user has already been added.";
						}
					}
					else
					{
						cout << "There is not user or team with those ids." << endl;
					}
					cout << "Press enter to assign another user or escape to go back";
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
//ready

void menuUserTasks(vector<pm::type::Task> tasks, pm::type::User currentUser, vector<pm::type::Project>& projects, vector<pm::type::User>& users, vector<pm::type::Team>& teams)
{
	int Event;
	pm::dal::TaskStore tasksFunc;
	pm::dal::ProjectStore projectFunc;
	pm::dal::UserStore userProject;
	size_t index = 0;
	int option = 1;
	size_t idTask, idOfProject;
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
			cout << "\x1b[1;30m";
			displayUsersButton();
			buttonCreate();
			buttonsRemove();
			buttonsUpdate();
			cout << "\x1b[1;37m";
			backButton();
			Event = _getch();
			if (Event == 13)
			{
				Event = 5;
			}
			break;
		}

		switch (Event)
		{
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
		case 1:
			if (tasks.size() != 0)
			{
				while (true)
				{
					system("CLS");
					projectFunc.displayProjects(projects, currentUser, teams, 1);
					cin >> idOfProject;
					if (projectFunc.checkId(projects, idOfProject))
					{
						index = projectFunc.getById(projects, idOfProject);
						cout << endl;
						tasksFunc.displayProjectTasks(projects[index].id, tasks, currentUser, projects, users, teams);
						cin >> idTask;
					}
					else
					{
						cout << "Sorry! There is not a project with that title";
					}
					cout << "Press enter to display other tasks of another project or escape to go back";
					Event = _getch();
					if (Event == 27)
					{
						option = 1;
						break;
					}
				}
			}
			else
			{
				cout << "There are not tasks. Press escape to go back";
				Event = _getch();
				if (Event == 27)
				{
					option = 1;
					break;
				}
			}
			break;
		case 2:
			while (true)
			{
				system("CLS");
				projectFunc.displayProjects(projects, currentUser, teams, 0);

				tasksFunc.create(tasks, currentUser.id, users, projects, teams, currentUser);
				cout << "Press enter to display other tasks of another project or escape to go back";
				Event = _getch();
				if (Event == 27)
				{
					option = 1;
					break;
				}
			}
			break;
		case 3:
			if (tasks.size() != 0)
			{
				while (true)
				{
					system("CLS");

					tasksFunc.displayCreated(tasks, currentUser, projects, users, teams);
					cin >> idTask;
					tasksFunc.remove(tasks, idTask, currentUser.id);
					cout << "Press enter to display other tasks of another project or escape to go back";
					Event = _getch();
					if (Event == 27)
					{
						option = 1;
						break;
					}
				}
			}
			else
			{
				cout << "There are not tasks. Press escape to go back";
				Event = _getch();
				if (Event == 27)
				{
					option = 1;
					break;
				}
			}
			break;
		case 4:
			while (true)
			{
				system("CLS");
				tasksFunc.displayCreated(tasks, currentUser, projects, users, teams);
				cin >> idTask;
				system("CLS");
				int indexTask = tasksFunc.getById(tasks, idTask);
				idOfProject = tasks[indexTask].idOfProject;
				if (projectFunc.checkId(projects, idOfProject) && tasksFunc.checkId(tasks, idTask))
				{
					cout << projects[projectFunc.getById(projects, idOfProject)].title;
					tasksFunc.update(tasks, tasks[tasksFunc.getById(tasks, idTask)], currentUser.id, projects[projectFunc.getById(projects, idOfProject)], teams, users);
				}
				else
				{
					cout << "Sorry! There is not a project with that title or task with that id " << endl;
				}
				cout << "Press enter to display other tasks of another project or escape to go back";
				Event = _getch();
				if (Event == 27)
				{
					option = 1;
					break;
				}
			}
			break;
		case 5:
			return;
			break;
		}
	}
}

void managementMenuAdmin(vector<pm::type::User>& users, pm::type::User& currentUser, vector<pm::type::Team>& teams)
{
	int option = 1;
	int Event;
	while (true)
	{
		switch (option)
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
			if (option == 1)
			{
				option = 3;
			}
			else
			{
				option--;
			}
			break;
		case KEY_DOWN:
			if (option == 3)
			{
				option = 1;
			}
			else
			{
				option++;
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

void menuUserProject(vector<pm::type::Project>& projects, pm::type::User& currentUser, vector<pm::type::Team>& teams, vector<pm::type::User>& users)
{
	int Event = 0;
	int option = 1, updateId, teamId;
	size_t index, idOfProject, idOfTeam;
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
				projectFunc.displayProjects(projects, currentUser, teams, 1);
				cout << "Which project do you want? - ";
				cin >> idOfProject;
				if (projectFunc.checkId(projects, idOfProject))
				{
					index = projectFunc.getById(projects, idOfProject);
					cout << endl;
					projectFunc.displayProject(projects[index], users);
				}
				else
				{
					cout << "Sorry! There is not a project with this id" << endl;
				}
				cout << "Press enter to display another project or escape to go back";
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
			cout << "Create project: " << endl << endl;
			projects.push_back(projectFunc.create(projects, currentUser.id));
			cout << "Press enter to create another project or escape to go back";
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
				projectFunc.displayProjects(projects, currentUser, teams, 0);
				cout << "Which project do you want to delete? - ";
				cin >> idOfProject;
				if (projectFunc.checkId(projects, idOfProject))
				{
					projects = projectFunc.remove(projects, currentUser.id, idOfProject);
				}
				else
				{
					cout << "Sorry! There is not a project with this id" << endl;
				}
				cout << "Press enter to remove another project or escape to go back";
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
				projectFunc.displayProjects(projects, currentUser, teams, 0);
				cout << "Which project do you want to edit? - ";
				cin >> idOfProject;
				if (projectFunc.checkId(projects, idOfProject))
				{
					projectFunc.update(projects, currentUser.id, idOfProject);
				}
				else
				{
					cout << "Sorry! There is not a project with this id." << endl;
				}
				cout << "Press enter to edit another project or escape to go back";
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

			while (true)
			{
				projectFunc.displayProjects(projects, currentUser, teams, 0);

				cout << "Choose project: ";
				cin >> idOfProject;
				if (projectFunc.checkId(projects, idOfProject))
				{
					size_t projectIndex = projectFunc.getById(projects, idOfProject);

					system("CLS");
					cout << "Teams: " << endl << endl;
					teamFunc.displayTeams(teams);
					cout << "Choose teams: ";
					cin >> idOfTeam;
					if (teamFunc.checkId(teams, idOfTeam))
					{
						size_t teamIndex = teamFunc.getById(teams, idOfTeam);
						if (projectFunc.checkForAdded(projects[projectIndex], teams[teamIndex].id) == false)
						{
							projectFunc.asignToTeam(projects, projectIndex, teamIndex, teams);
						}
						else
						{
							cout << "Sorry! This team has already been added" << endl << endl;
						}
					}
					else
					{
						cout << "Sorry! There is not a team with this id";
					}
				}
				else
				{
					cout << "Sorry! There is not a project with this id" << endl;
				}
				cout << "Press enter to assign another team or escape to go back";
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
		case 6:
			return;
			break;
		}
	}
}

void managementMenuUser(vector<pm::type::Project>& projects, pm::type::User& currentUser, vector<pm::type::Team>& teams, vector<pm::type::User>& users, vector<pm::type::Task>& tasks)
{
	int Event = 1, option = 1;
	while (true)
	{
		switch (option)
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
			if (option == 1)
			{
				option = 3;
			}
			else
			{
				option--;
			}
			break;
		case KEY_DOWN:
			if (option == 3)
			{
				option = 1;
			}
			else
			{
				option++;
			}
			break;
		case 1:
			system("CLS");
			menuUserProject(projects, currentUser, teams, users);
			break;
		case 2:
			system("CLS");
			menuUserTasks(tasks, currentUser, projects, users, teams);
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
	pm::dal::TaskStore tasksFunc;
	vector<pm::type::Task> tasks = tasksFunc.getAll();
	string userName, password;
	int option = 1, numberOfUsers;
	int Event;
	pm::type::User currentUser{ 0 };
	while (true)
	{
		switch (option)
		{
		case 1:
			system("CLS");
			cout << "\x1b[1;37m";
			buttonsLogIn();
			cout << "\x1b[1;30m";
			buttonsSignIn();
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
			buttonsLogIn();
			cout << "\x1b[1;37m";
			buttonsSignIn();
			Event = _getch();
			if (Event == 13)
			{
				Event = 2;
			}
			break;
		}

		switch (Event)
		{
		case KEY_UP:
			if (option == 1)
			{
				option = 2;
				system("CLS");
			}
			else
			{
				option--;
			}
			break;
		case KEY_DOWN:
			if (option == 2)
			{
				option = 1;
			}
			else
			{
				option++;
			}
			break;
		case 1:
			system("CLS");
			numberOfUsers = users.size();
			cout << "User name: ";
			cin >> userName;
			cout << "Password: ";
			cin >> password;

			if (numberOfUsers != 0)
			{
				if (userName == "admin" && password == "adminpass")
				{
					managementMenuAdmin(users, currentUser, teams);
					option = 1;
				}
				else
				{
					for (size_t i = 0; i < users.size(); i++)
					{
						if (users[i].firstName == userName && users[i].passwordHash == md5(password))
						{
							if (users[i].adminPrivileges)
							{
								currentUser = users[i];
								managementMenuAdmin(users, currentUser, teams);
							}
							else
							{
								currentUser = users[i];
								managementMenuUser(projects, currentUser, teams, users, tasks);
							}
							option = 1;
							break;
						}
					}
				}
			}
			else
			{
				if (userName == "admin" && password == "adminpass")
				{
					managementMenuAdmin(users, currentUser, teams);
					option = 1;
				}
			}
			break;
		case 2:
			system("CLS");
			users = userFunc.create(users, currentUser.id, 0);
			option = 1;
			break;
		}

	}
}
