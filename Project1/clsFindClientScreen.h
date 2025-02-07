#pragma once
#include "clsScreen.h"
#include"clsBankClient.h"

class clsFindClientScreen : protected clsScreen
{
private:
    static void _PrintClientInfo(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.GetUsername();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";
    }
public:
    static void ShowFindClientScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
        {
            return; // this will get out of the fun() without completing the code
        }
        _DrawScreenHeader("Find Client Screen");

        string GetUsername;
        cout << "\nPlease Enter Account Number: ";
        GetUsername = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(GetUsername))
        {
            cout << "\nAccount number is not found, choose another one: ";
            GetUsername = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(GetUsername);

        if (!Client.IsEmpty())
        {
            cout << "\nClient Found :-)\n";
        }
        else
        {
            cout << "\nClient Was not Found :-(\n";
        }

        _PrintClientInfo(Client);

    }


};
