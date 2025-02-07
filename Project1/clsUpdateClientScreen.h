#pragma once
#include "clsScreen.h"
#include"clsBankClient.h"

class clsUpdateClientScreen : protected clsScreen
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
    static void UpdateClient()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
        {
            return; // this will get out of the fun() without completing the code
        }
        string GetUsername;
        _DrawScreenHeader("Update Client Screen");
        cout << "\nPlease Enter Account Number : ";
        GetUsername = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(GetUsername))
        {
            cout << "Account Number is not Found , Please try again :)\n";
            GetUsername = clsInputValidate::ReadString();
        }
        clsBankClient Client = clsBankClient::Find(GetUsername);
        Client.Print();

        cout << "\n___________________\n";
        cout << "    Update Client   ";
        cout << "\n___________________\n";

        clsBankClient::ReadClientInfo(Client);
        _PrintClientInfo(Client);

        clsBankClient::enSaveResults Save;
        Save = Client.Save();
        switch (Save)
        {
        case clsBankClient::enSaveResults::svSucceeded:
            cout << "\nClient Is Saved succesfully:)\n";
            break;
        case clsBankClient::enSaveResults::svFaildEmptyObject:
            cout << "\n Client Was not saved Cause it is empty:(\n";
            break;

        }

    }
};
