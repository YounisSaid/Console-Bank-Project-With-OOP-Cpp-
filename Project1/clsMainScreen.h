#pragma once
#include "clsScreen.h"
#include "clsClientListScreen.h"
#include "clsInputValidate.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsMangeUsersScreen.h"
#include "clsLoginRegisterScreen.h"
#include "Global.h"
#include "clsShowCurrencyExchangeScreen.h"
class clsMainScreen : protected clsScreen
{
private:
    enum enMainMenueOptions
    {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7,eLoginRegister =8 ,eCurrencyExchange = 9,eExit = 10
    };
    static short _ReadMainMenuoption()
    {  
        cout << setw(37) << left << "" << "\tChoose What you Want to do [1-10] ";
        return clsInputValidate::ReadIntNumberBetween(1, 10, "Invaild Number , try Again.\n");
    }
    static void _GoBackToMainMenu()
    {
        cout << setw(37) << left << "" << "\tPress any key to go back to MainMenu.... \n";
        system("Pause>0");
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
        //cout << "\nClient List Screen Will be here...\n";

        clsClientListScreen::ShowClientsList();
    }

    static void _ShowAddNewClientsScreen()
    {
        //cout << "\nAdd New Client Screen Will be here...\n";
        clsAddNewClientScreen::AddNewClient();

    }

    static void _ShowDeleteClientScreen()
    {
        //cout << "\nDelete Client Screen Will be here...\n";
        clsDeleteClientScreen::DeleteClient();
    }

    static void _ShowUpdateClientScreen()
    {
        //cout << "\nUpdate Client Screen Will be here...\n";
        clsUpdateClientScreen::UpdateClient();
    }

    static void _ShowFindClientScreen()
    {
        //cout << "\nFind Client Screen Will be here...\n";
        clsFindClientScreen::ShowFindClientScreen();
    }

    static void _ShowTransactionsMenue()
    {
        //cout << "\nTransactions Menu Will be here...\n";
        clsTransactionsScreen::ShowTransactionsMenu();

    }

    static void _ShowManageUsersMenue()
    {
        //cout << "\nUsers Menu Will be here...\n";
        clsManageUsersScreen::ShowManageUsersMenu();

    }
    static void _ShowLoginRegisterScreen()
    {
        clsLoginRegisterScreen::ShowLoginScreen();
    }
    static void _ShowCurrencyExchangeScreen()
    {
        clsShowCurrencyExchangeScreen::ShowCurrencyExchangeScreen();
    }

    /*static void _ShowEndScreen()
    {
        cout << "\nEnd Screen Will be here...\n";

    }*/
    static void _Logout()
    {
        CurrentUser = clsUser::Find("","");
        // it will go back and get out of the system
    }

    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenu();
            break;
        }

        case enMainMenueOptions::eAddNewClient:
        {
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenu();
            break;
        }

        case enMainMenueOptions::eDeleteClient:
        {
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenu();
            break;
        }

        case enMainMenueOptions::eUpdateClient:
        {
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenu();
            break;
        }

        case enMainMenueOptions::eFindClient:
        {
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenu();
            break;
        }

        case enMainMenueOptions::eShowTransactionsMenue:
        {
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenu();
            break;
        }

        case enMainMenueOptions::eManageUsers:
        {
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenueOptions::eLoginRegister:
        {
            system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenu();
            break;
        }
        case enMainMenueOptions::eCurrencyExchange:
        {
            system("cls");
            _ShowCurrencyExchangeScreen();
            _GoBackToMainMenu();
            break;
        }

        case enMainMenueOptions::eExit:
        {
            system("cls");
            _Logout();
            break;
        }
           
        }
            
    }


public:
    static void ShowMainMenue()
    {

        system("cls");
        _DrawScreenHeader("Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenuoption());
    }
};

