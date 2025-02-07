#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include <iomanip>

class clsCurrencyCalculatorScreen :protected clsScreen
{
private:
    static void _PrintCurrency(clsCurrency Currency)
    {
    
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";

    }
public:

    static void ShowCurrencyCalculatorScreen()
    {
            char Answer = 'n';
        do {
            system("cls");
            _DrawScreenHeader("Currency Calculator Screen");
            cout << "\nPlease Enter Currency1(From) Code ? ";
            string CurrencyCode1 = clsInputValidate::ReadString();
            clsCurrency currency1 = clsCurrency::FindByCode(CurrencyCode1);
            while (!clsCurrency::IsCurrencyExistBycode(CurrencyCode1))
            {
                cout << "\nCurrncy is not found ,Please try Again:)\n";
                CurrencyCode1 = clsInputValidate::ReadString();

            }

            cout << "\nPlease Enter Currency2(To) Code ? ";
            string CurrencyCode2 = clsInputValidate::ReadString();
            clsCurrency currency2 = clsCurrency::FindByCode(CurrencyCode2);
            while (!clsCurrency::IsCurrencyExistBycode(CurrencyCode2))
            {
                cout << "\nCurrncy is not found ,Please try Again:)\n";
                CurrencyCode2 = clsInputValidate::ReadString();

            }
            float Amount = 0;
            cout << "\nEnter Amount To Exchange : ";
            Amount = clsInputValidate::ReadFloatNumber();
            cout << "\nConvert From : \n";
            _PrintCurrency(currency1);
            clsCurrency USD = clsCurrency::FindByCode("USD");
            if (currency2.Rate() == 1)
            {
                cout << Amount << " " << currency1.CurrencyCode() << " = " << (Amount / currency1.Rate())
                    << " " << USD.CurrencyCode() << "\n\n";
            }
            else
            {
                cout  << Amount << " " << currency1.CurrencyCode() << " = " << (Amount / currency1.Rate())
                    << " " << USD.CurrencyCode() << "\n\n";

                cout << "\n Convert From USD to : ";
                cout << "\n To: \n";
                _PrintCurrency(currency2);
                cout  << Amount << " " << currency1.CurrencyCode() << " = " << (Amount / currency1.Rate() * currency2.Rate())
                    << " " << currency2.CurrencyCode() << "\n\n";
            }
            cout << "\nDo you Want to Prefrm Anthor Calculation ?[y,n] ";
            cin >> Answer;
        } while (Answer == 'Y' || Answer == 'y');
    }
};
