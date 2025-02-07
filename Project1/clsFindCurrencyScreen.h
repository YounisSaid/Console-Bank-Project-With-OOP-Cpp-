#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include <iomanip>

class clsFindCurrencyScreen :protected clsScreen
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
            cout << "\nCurrency Found :-)\n";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\nCurrency Was not Found :-(\n";
        }
    }


    

public:

    static void ShowFindCurrencyScreen()
    {
        _DrawScreenHeader("Find Currency Screen");
        
        short Answer =0;
        
        clsCurrency currency = clsCurrency::FindByCode("");
        cout << "\nFind By: [1] Code or [2] Country ? ";
        Answer = clsInputValidate::ReadIntNumberBetween(1, 2, "\nInvaild Number,Please Try Again:)\n");

            if (Answer == 1)
            {
                cout << "\nPlease Enter Currency Code ? ";
               string CurrencyCode = clsInputValidate::ReadString();
                currency = clsCurrency::FindByCode(CurrencyCode);
                _ShowResults(currency);
            }
        

            else if (Answer == 2)

            {
                cout << "\nPlease Enter Country  ? ";
                string CountryCurrency = clsInputValidate::ReadString();

                currency = clsCurrency::FindByCountry(CountryCurrency);
                _ShowResults(currency);
            }
    }
};
