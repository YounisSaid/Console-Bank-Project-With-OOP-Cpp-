#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include <iomanip>

class clsUpdateCurrencyRateScreen :protected clsScreen
{
private:
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";

    }
    static void _ShowResults(clsCurrency Currency)
    {
        if (!Currency.IsEmpty())
        {           
          _PrintCurrency(Currency);
        }
        else
        {
            cout << "\nCurrency Was not Found :-(\n";
        }
    }




public:

    static void ShowUpdateCurrencyRateScreen()
    {
        _DrawScreenHeader("Update Currency Rate Screen");
        cout << "\nPlease Enter Currency Code ? ";
        string CurrencyCode = clsInputValidate::ReadString();
        clsCurrency currency = clsCurrency::FindByCode(CurrencyCode);
        _ShowResults(currency);

        char Answer = 'n';
        cout << "\n Are you sure you want to update this Currency Rate ? [y,n]";
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            cout << "\nUpdate Currncy rate :\n";
            cout << "---------------------\n";
            cout << "Enter New Rate : ";
            float Rate = 0;
            Rate = clsInputValidate::ReadDblNumber();
            currency.UpdateRate(Rate);
            cout << "\nCurrency Rate Updated Successfully:)\n";
            _ShowResults(currency);
        }
    }
};