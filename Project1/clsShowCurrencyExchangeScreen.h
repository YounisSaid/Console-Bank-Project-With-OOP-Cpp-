#pragma once
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
class clsShowCurrencyExchangeScreen : public clsScreen
{
private:
    enum enCurrencyExchangeOptions
    {
        eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3,
        eCurrencyCalculator = 4, eMainMenu = 5
    };
    static short _ReadCurrencyExchangeoption()
    {
        cout << setw(37) << left << "" << "\tChoose What you Want to do [1-5] ";
        return clsInputValidate::ReadIntNumberBetween(1, 5, "Invaild Number , try Again.\n");
    }
    static void _GoBackToCurrencyExchangeScreen()
    {
        cout << setw(37) << left << "" << "\tPress any key to go back to Currency Exchange.... \n";
        system("Pause>0");
        ShowCurrencyExchangeScreen();
    }
    static void _ShowCurrenciesListScreen()
    {
        //cout << "\nCurriencies List Screen Will Be Here.\n";
        clsCurrenciesListScreen::ShowCurrenciesListScreen();

    }

    static void _ShowFindCurrencyScreen()
    {
        //cout << "\nFind Currency Screen Will Be Here.\n";
        clsFindCurrencyScreen::ShowFindCurrencyScreen();

    }

    static void _ShowUpdateCurrencyRateScreen()
    {
        //cout << "\nUpdate Currency Rate Screen Will Be Here.\n";
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
    }

    static void _ShowCurrencyCalculatorScreen()
    {
        //cout << "\nCurrency Calculator Screen Will Be Here.\n";
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();

    }

    static void _PerfromMainMenueOption(enCurrencyExchangeOptions CurrencyExchangeOptions)
    {
        switch (CurrencyExchangeOptions)
        {
        case enCurrencyExchangeOptions::eListCurrencies:
        {
            system("cls");
            _ShowCurrenciesListScreen();
            _GoBackToCurrencyExchangeScreen();
        }

        case enCurrencyExchangeOptions::eFindCurrency:
        {
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrencyExchangeScreen();
        }

        case enCurrencyExchangeOptions::eUpdateRate:
        {
            system("cls");
            _ShowUpdateCurrencyRateScreen();
            _GoBackToCurrencyExchangeScreen();
        }

        case enCurrencyExchangeOptions::eCurrencyCalculator:
        {
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrencyExchangeScreen();
        }

        case enCurrencyExchangeOptions::eMainMenu:
        {
            
        }
        }
    }
public:
    static void ShowCurrencyExchangeScreen()
    {

        system("cls");
        _DrawScreenHeader("Main Currency Exchange Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tCurrency Exchange Screen\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";


        _PerfromMainMenueOption((enCurrencyExchangeOptions)_ReadCurrencyExchangeoption());
    }
};

