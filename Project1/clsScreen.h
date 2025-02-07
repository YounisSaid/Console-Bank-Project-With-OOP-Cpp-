#pragma once
#include<iostream>
#include<iomanip>
#include "Global.h"
#include "clsDate.h"
using namespace std;

class clsScreen
{
protected:
	static void _DrawScreenHeader(string Title, string SubTitle="")
	{
		                                  
		cout << setw(37) << left << "" << "-------------------------------------------\n";
		cout << setw(37) << left << "" << "                 "<< Title<<"\n" ;
		if(SubTitle !="") cout << setw(37)<<"" << "                 " << SubTitle << "\n";
		cout << setw(37) << left << "" << "-------------------------------------------\n\n\n";
		cout << setw(37) << left << "" << "User : " << CurrentUser.Username << "\n";
		cout << setw(37) << left << "" << "Date : " << clsDate::DateToString(clsDate()) << "\n";
	}

	static bool CheckAccessRights(clsUser::enPermissions Permission)
	{
		if (!CurrentUser.CheckAccessPermission(Permission))
		{
			cout << setw(37) << left << "" << "-------------------------------------------\n";
			cout << setw(37) << left << "" << "                 " << "Access Denied :(" << "\n";
			cout << setw(37) << "" << "                 " << "Please Contact Your Admin" << "\n";
			cout << setw(37) << left << "" << "-------------------------------------------\n";
			return false;
		}
		else return true;
		
	}
};

