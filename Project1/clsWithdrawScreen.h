#pragma once
#include "clsScreen.h"
#include"clsBankClient.h"

class clsWithdrawScreen : protected clsScreen
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
    static void ShowWithdrawScreen()
    {

        _DrawScreenHeader("Withdraw Screen");

        string GetUsername;
        cout << "\nPlease Enter Account Number: ";
        GetUsername = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(GetUsername))
        {
            cout << "\nAccount number is not found, choose another one: ";
            GetUsername = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(GetUsername);
        _PrintClientInfo(Client);

        double Amount = 0;
        cout << "\n Enter Withdraw Amount : ";
        Amount = clsInputValidate::ReadDblNumber();

        char Answer = 'n';
        cout << "\n Are you Sure you want to preform this transaction ? [y,n] ";
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            Client.Withdraw(Amount);
            cout << "\nTransaction Done Successfully Your Total Balance is : ";
            cout << Client.AccountBalance;
            _PrintClientInfo(Client);

        }
        else
        {
            "\nError No Transcaction :(\n";
        }


    }
};
