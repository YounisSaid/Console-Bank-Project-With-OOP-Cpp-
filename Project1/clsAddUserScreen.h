#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include <iomanip>

class clsAddNewUserScreen : protected clsScreen
{
private:

    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        User.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidate::ReadString();

        cout << "\nEnter Password: ";
        User.Password = clsInputValidate::ReadString();

        cout << "\nEnter Permission: ";
        User.Permissions = _ReadPermissionsToSet();
    }

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.Username;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }

    static int _ReadPermissionsToSet()
    {
        int Permission = 0;
        char Answer = 'n';

        cout << "/nDo you want to give full accsess ? [y,n] ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            return -1;
        }

        cout << "\nDo you want to give accsess to : ";
        cout << "List Clients ? [y,n] ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            Permission+= clsUser::enPermissions::pListClients;
        }


        cout << "\nDo you want to give accsess to : ";
        cout << "Add new Client ? [y,n] ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            Permission += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDo you want to give accsess to : ";
        cout << "Delete Client ? [y,n] ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            Permission += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nDo you want to give accsess to : ";
        cout << "Update Client ? [y,n] ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            Permission += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nDo you want to give accsess to : ";
        cout << "Find Client ? [y,n] ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            Permission += clsUser::enPermissions::pFindClient;
        }

        cout << "\nDo you want to give accsess to : ";
        cout << " Tranactions ? [y,n] ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            Permission += clsUser::enPermissions::pTranactions;
        }

        cout << "\nDo you want to give accsess to : ";
        cout << "Manage Users ? [y,n] ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            Permission += clsUser::enPermissions::pManageUsers;
        }

        cout << "\nDo you want to give accsess to : ";
        cout << "Login Register ? [y,n] ";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            Permission += clsUser::enPermissions::pLoginRegister;
        }

        return Permission;


    }

public:

    static void ShowAddNewUserScreen()
    {

        _DrawScreenHeader("Add New User Screen");

        string UserName = "";

        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();
        while (clsUser::IsUserExist(UserName))
        {
            cout << "\nUserName Is Already Used, Choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::GetAddNewUserObject(UserName);

        _ReadUserInfo(User);

        clsUser::enSaveResults SaveResult;

        SaveResult = User.Save();

        switch (SaveResult)
        {
        case  clsUser::enSaveResults::svSucceeded:
        {
            cout << "\nUser Addeded Successfully :-)\n";
            _PrintUser(User);
            break;
        }
        case clsUser::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError User was not saved because it's Empty";
            break;

        }
        case clsUser::enSaveResults::svFaildUserExists:
        {
            cout << "\nError User was not saved because UserName is used!\n";
            break;

        }
        }
    }



};


