
#pragma once
#include "clsScreen.h"
#include"clsBankClient.h"

class clsAddNewClientScreen : protected clsScreen
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
    static void _ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter Your First name : ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter Your Last name : ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Your Email : ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nEnter Your Phone : ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nEnter Your Password : ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nEnter Your Balance : ";
        Client.AccountBalance = clsInputValidate::ReadDblNumber();
    }
public:
    static void AddNewClient()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
        {
            return; // this will get out of the fun() without completing the code
        }
        string GetUsername = "";
        _DrawScreenHeader("Add client Screen");

        cout << "\nPlease Enter Account Number : ";
        GetUsername = clsInputValidate::ReadString();
        while (clsBankClient::IsClientExist(GetUsername))
        {
            cout << "Account Number already taken , Please try again :)\n";
            GetUsername = clsInputValidate::ReadString();
        }
        clsBankClient Client = clsBankClient::GetAddNewClientObject(GetUsername);
        _ReadClientInfo(Client);

        clsBankClient::enSaveResults Save;
        Save = Client.Save();
        switch (Save)
        {
        case clsBankClient::enSaveResults::svSucceeded:
            cout << "\nClient Is Saved succesfully:)\n";
            _PrintClientInfo(Client);
            break;
        case clsBankClient::enSaveResults::svFaildEmptyObject:
            cout << "\n Client Was not saved Cause it is empty:(";
            break;
        case clsBankClient::enSaveResults::svFaildUserExists:
            cout << "\n Cilent Was not saved cause Account Number Already Exists:(\n";
            break;
        }


    }
};
