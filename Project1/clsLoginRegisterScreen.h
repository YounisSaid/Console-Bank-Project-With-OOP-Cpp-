#pragma once

#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "clsDate.h"
#include "Global.h"
#include "clsScreen.h"
#include <vector>
#include <fstream>
#include <iomanip>

class clsLoginRegisterScreen : protected clsScreen
{
private:


    string Date1;
    string Username1;
    string Password1;
    string Perrmissions1;
    static string _ConverLoginRegisterToLine( string Seperator = "#//#")
    {

        string stLoginRecord = "";
        stLoginRecord += clsDate::GetSystemDateTimeString() + Seperator;
        stLoginRecord += CurrentUser.Username + Seperator;
        stLoginRecord += clsUtil::EncryptText( CurrentUser.Password) + Seperator;
        stLoginRecord += to_string(CurrentUser.Permissions) ;
        
        

        return stLoginRecord;

    }
   
   
    
    static clsLoginRegisterScreen _ConvertLinetoLoginObject(string Line, string Seperator = "#//#")
    {
        vector < string > vLoginData;
        clsLoginRegisterScreen Login;
        vLoginData = clsString::Split(Line, Seperator);
        Login.Date1 = vLoginData[0];
        Login.Username1 = vLoginData[1];
        Login.Password1 = clsUtil::DecryptText( vLoginData[2]);
        Login.Perrmissions1 = vLoginData[3];


        return Login;
    }
    static void _SaveLoginRegistersDataToFile(vector <clsLoginRegisterScreen> vLogins)
    {
        fstream Myfile;
        Myfile.open("LoginRegister.txt", ios::out);
        if (Myfile.is_open())
        {
            string line;

            for (clsLoginRegisterScreen &C : vLogins)
            {
                
                    line = _ConverLoginRegisterToLine();
                    Myfile << line << endl;
                

            }

        }
    }
    static void AddDataLineToFile(string line)
    {
        fstream Myfile;
        Myfile.open("LoginRegister.txt", ios::out | ios::app);
        if (Myfile.is_open())
        {

            Myfile << line << endl;
        }
        Myfile.close();
    }
    static  vector <clsLoginRegisterScreen> _LoadLoginRegisterFromFile()
    {

        vector <clsLoginRegisterScreen> vLogins;

        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsLoginRegisterScreen Login = _ConvertLinetoLoginObject(Line);

                vLogins.push_back(Login);
            }

            MyFile.close();

        }

        return vLogins;

    }
    static void PrintLoginRecordLine(clsLoginRegisterScreen Login)
    {

        cout << "| " << setw(40) << left << Login.Date1;
        cout << "| " << setw(15) << left << Login.Username1 ;
        cout << "| " << setw(12) << left << clsUtil::EncryptText (Login.Password1);
        cout << "| " << setw(12) << left << Login.Perrmissions1;


    }
public:
    static void AddNewLogin()
    {
        AddDataLineToFile(_ConverLoginRegisterToLine());
    }
    
    static void ShowLoginScreen()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
        {
            return; // this will get out of the fun() without completing the code
        }
        vector <clsLoginRegisterScreen> vLogins = _LoadLoginRegisterFromFile();
        string title = "Login Register Screen";
        string SubTitle = "(" + to_string(vLogins.size()) + ") Login(s).";

        _DrawScreenHeader(title, SubTitle);

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(40) << "Date/Time";
        cout << "| " << left << setw(15) << "Username";
        cout << "| " << left << setw(12) << "Password";
        cout << "| " << left << setw(12) << "Permmisions";

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;


        if (vLogins.size() == 0)
            cout << "\t\t\t\tNo  Transfers In the System!";
        else

            for (clsLoginRegisterScreen Login : vLogins)
            {
                PrintLoginRecordLine(Login);
                cout << endl;
            }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }


};

