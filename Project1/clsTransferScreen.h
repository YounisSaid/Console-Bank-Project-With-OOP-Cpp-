#pragma once
#include "clsScreen.h"
#include"clsBankClient.h"
#include "clsTransferLog.h"
#include "Global.h"
class clsTransferScreen : protected clsScreen
{
private:
    static void _PrintClientInfo(clsBankClient Client)
    {
        cout << "\nClient Card:";                       
        cout << "\nFull Name   : " << Client.FullName();        
        cout << "\nAcc. Number : " << Client.GetUsername();      
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";
    }
public:
	static void ShowTransferScreen()
	{
        _DrawScreenHeader("Transfer Screen");
        //Client1
        string AccountNumber;
        cout << "\nPlease Enter Account Number to Transfer From : ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        _PrintClientInfo(Client1);

        //Client2
        
        cout << "\nPlease Enter Account Number to Transfer to : ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client2 = clsBankClient::Find(AccountNumber);
        _PrintClientInfo(Client2);


        double Amount = 0;
        cout << "\n Enter Transfer Amount : ";
        Amount = clsInputValidate::ReadDblNumber();
        while (Client1.AccountBalance < Amount)
        {
            cout << "\nAmount Excceds The avaliable Balance , Please Enter Anthor Amount : ";
            Amount = clsInputValidate::ReadDblNumber();
        }

        char Answer = 'n';
        cout << "\n Are you Sure you want to preform this transaction ? [y,n] ";
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            Client1.Withdraw(Amount);
            Client2.Depoist(Amount);
            FromClient = Client1;
            ToClient = Client2;
            Amount1 = Amount;
            clsTransferLog::AddNewTransfer();
            _PrintClientInfo(Client1);
            _PrintClientInfo(Client2);


        }
        else
        {
            "\nError No Transcaction :(\n";
        }


    
	}
};