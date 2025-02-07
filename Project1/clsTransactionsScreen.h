#pragma once
#include "clsScreen.h"
#include"clsBankClient.h"
#include "clsDepoistScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLog.h"
class clsTransactionsScreen : protected clsScreen
{
private:
    enum enTransactionsMenuOptions {
        eDeposit = 1, eWithdraw = 2,
        eShowTotalBalance = 3,eTransfer = 4, eTransferLog = 5,eShowMainMenue = 6 };

    static short _ReadTransactionsMenuOptions()
    {
        cout << setw(37) << left << "" << "\tChoose What you Want to do [1-6] ";
        return clsInputValidate::ReadIntNumberBetween(1, 6, "Invaild Number , try Again.\n");
    }
    static void _GoBackToTransactionsMenu()
    {
        cout << setw(37) << left << "" << "\tPress any key to go back to Transactions Menu.... \n";
        system("Pause>0");
        ShowTransactionsMenu();
    }
    static void _ShowDepositScreen()
    {
        //cout << "\n Deposit Screen will be here.\n";
        clsDepoistScreen::ShowDepoistScreen();
    }

    static void _ShowWithdrawScreen()
    {
        //cout << "\n Withdraw Screen will be here.\n";
        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        //cout << "\n Balances Screen will be here.\n";
        clsTotalBalancesScreen::ShowTotalBalances();
    }
    static void _ShowTransferScreen()
    {
        clsTransferScreen::ShowTransferScreen();
    }
    static void _ShowTranferLogScreen()
    {
        clsTransferLog::ShowTransferScreen();
    }

    static void PreformTransactionsMenuOptions(enTransactionsMenuOptions MenuOptions)
    {
        switch (MenuOptions)
        {
        case enTransactionsMenuOptions::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenu();
        }

        case enTransactionsMenuOptions::eWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenu();
        }

        case enTransactionsMenuOptions::eShowTotalBalance:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenu();
        }
        case enTransactionsMenuOptions::eTransfer:
        {
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsMenu();
        }
        case enTransactionsMenuOptions::eTransferLog:
        {
            system("cls");
            _ShowTranferLogScreen();
            _GoBackToTransactionsMenu();
        }
        case enTransactionsMenuOptions::eShowMainMenue:
        {

        }
        }
    };
public:
	static void ShowTransactionsMenu()
	{
        if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
        {
            return; // this will get out of the fun() without completing the code
        }
		system("cls");
		_DrawScreenHeader("Transactions Menu Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tTransactions Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Depoist.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] TransferLog.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";

        cout << setw(37) << left << "" << "===========================================\n";

        PreformTransactionsMenuOptions((enTransactionsMenuOptions)_ReadTransactionsMenuOptions());
	}
};
