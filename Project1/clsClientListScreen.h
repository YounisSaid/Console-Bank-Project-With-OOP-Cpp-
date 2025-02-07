#pragma once
#include "clsScreen.h"
#include"clsBankClient.h"


class clsClientListScreen : protected clsScreen
{
private:
    static void PrintClientRecordLine(clsBankClient Client)
    {
        cout << "\t";

        cout << "| " << setw(15) << left << Client.GetUsername();
        cout << "| " << setw(20) << left << Client.FullName();
        cout << "| " << setw(12) << left << Client.Phone;
        cout << "| " << setw(20) << left << Client.Email;
        cout << "| " << setw(10) << left << Client.PinCode;
        cout << "| " << setw(12) << left << Client.AccountBalance;

    }
public:
    static void ShowClientsList()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pListClients))
        {
            return; // this will get out of the fun() without completing the code
        }
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
        string title = "Client List Screen";
        string SubTitle = "(" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(title, SubTitle);
       
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        cout << "\t";
        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(12) << "Balance";
        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Clients Available In the System!";
        else

            for (clsBankClient Client : vClients)
            {

                PrintClientRecordLine(Client);
                cout << endl;
            }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};