#pragma once
#include "clsScreen.h"
#include"clsBankClient.h"

class clsDepoistScreen : protected clsScreen
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
    static void ShowDepoistScreen()
    {

        _DrawScreenHeader("Depoist Screen");

        string AccountNumber;
        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClientInfo(Client);

        double Amount = 0;
        cout << "\n Enter Depoist Amount : ";
        Amount= clsInputValidate::ReadDblNumber();

        char Answer = 'n';
        cout << "\n Are you Sure you want to preform this transaction ? [y,n] ";
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            Client.Depoist(Amount);
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
