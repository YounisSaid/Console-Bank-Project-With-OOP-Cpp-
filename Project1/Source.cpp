
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsLoginScreen.h"

int main()

{
    while (true)
    {
        if (!clsLoginScreen::ShowLoginScreen())
            break;

    }
    
    return 0;
}