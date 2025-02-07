#pragma once
#include "clsScreen.h"
#include"clsBankClient.h"


class clsDeleteClientScreen : protected clsScreen
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
    static void DeleteClient()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
        {
            return; // this will get out of the fun() without completing the code
        }
        string GetUsername = "";
        _DrawScreenHeader("Delete Client Screen");
        cout << "\nPlease Enter Account Number : ";
        GetUsername = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(GetUsername))
        {
            cout << "\nAccount Number is not Found , Please try again :)\n";
            GetUsername = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(GetUsername);
        _PrintClientInfo(Client);

        cout << "\nAre you sure you want to delete this client [y,n] ??";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            if (Client.Delete())
            {
                cout << "\nClient Deleted Successfully\n";
                _PrintClientInfo(Client);

            }
            else
            {
                cout << "\nError Your Client was not Deleted\n";
            }
        }
    }
};