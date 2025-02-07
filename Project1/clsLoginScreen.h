#pragma once
#include "clsScreen.h"
#include"clsBankClient.h"
#include "Global.h"
#include "clsMainScreen.h"
#include "clsLoginRegisterScreen.h"

class clsLoginScreen : protected clsScreen
{
private:
	static bool _Login()
	{
		bool LoginFaild = false;
		
		int count = 3;
		string Username, Password;
		do
		{
			if (LoginFaild)
			{
				count--;
				if (count == 0)
				{
					cout << "\nYour Are locked After 3 Failed Trials\n";
					return false;
				}
				cout << "\nInvaild Username/Password , Please try again :)\n";
				
				cout << "You have " << count << " Trials to login. \n";
			}
			cout << "\nEnter UserName : ";
			getline(cin >> ws, Username);
			cout << "\nEnter Password : ";
			getline(cin, Password);
			CurrentUser = clsUser::Find(Username, Password);
			LoginFaild = CurrentUser.IsEmpty();
			
		} while (LoginFaild);
		clsLoginRegisterScreen::AddNewLogin();
		clsMainScreen::ShowMainMenue();
	}

public:
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("Login Screen");
		return _Login();

	}
};