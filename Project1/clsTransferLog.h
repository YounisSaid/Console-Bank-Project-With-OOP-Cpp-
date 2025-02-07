
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

#include "Global.h"
 
class clsTransferLog : protected clsScreen
{
private:
    

    string Date1;
    string AccountName1;
    string AccountName2;
    string Username1;
    static string _ConvertTransferLogToLine(string Seperator = "#//#")
    {

        string stTransferRecord = "";
        stTransferRecord += clsDate::GetSystemDateTimeString() + Seperator;
        stTransferRecord += FromClient.GetUsername() + Seperator;
        stTransferRecord += ToClient.GetUsername() + Seperator;
        stTransferRecord += CurrentUser.Username ;



        return stTransferRecord;

    }



    static clsTransferLog _ConvertLinetoTransferObject(string Line, string Seperator = "#//#")
    {
        vector < string > vTransferData;
        clsTransferLog Transfer;
        vTransferData = clsString::Split(Line, Seperator);
        Transfer.Date1 = vTransferData[0];
        Transfer.AccountName1 = vTransferData[1];
        Transfer.AccountName2 = vTransferData[2];
        Transfer.Username1 = vTransferData[3];


        return Transfer;
    }
    static void _SaveTransferLogsDataToFile(vector <clsTransferLog> vLogins)
    {
        fstream Myfile;
        Myfile.open("TransferLog.txt", ios::out);
        if (Myfile.is_open())
        {
            string line;

            for (clsTransferLog& C : vLogins)
            {

                line = _ConvertTransferLogToLine();
                Myfile << line << endl;


            }

        }
    }
    static void AddDataLineToFile(string line)
    {
        fstream Myfile;
        Myfile.open("TransferLog.txt", ios::out | ios::app);
        if (Myfile.is_open())
        {

            Myfile << line << endl;
        }
        Myfile.close();
    }
    static  vector <clsTransferLog> _LoadTransferLogFromFile()
    {

        vector <clsTransferLog> vLogins;

        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsTransferLog Login = _ConvertLinetoTransferObject(Line);

                vLogins.push_back(Login);
            }

            MyFile.close();

        }

        return vLogins;

    }
    static void PrintTransferRecordLine(clsTransferLog Transfer)
    {

        cout << "| " << setw(40) << left << Transfer.Date1;
        cout << "| " << setw(15) << left << Transfer.AccountName1;
        cout << "| " << setw(12) << left << Transfer.AccountName2;
        cout << "| " << setw(12) << left << Amount1;
        cout << "| " << setw(12) << left << FromClient.AccountBalance;
        cout << "| " << setw(12) << left << ToClient.AccountBalance;
        cout << "| " << setw(12) << left << Transfer.Username1;


    }
public:
    static void AddNewTransfer()
    {
        AddDataLineToFile(_ConvertTransferLogToLine());
    }

    static void ShowTransferScreen()
    {
        
        vector <clsTransferLog> vTransfers = _LoadTransferLogFromFile();
        string title = "Transfer Log Screen";
        string SubTitle = "(" + to_string(vTransfers.size()) + ") Transfer(s).";

        _DrawScreenHeader(title, SubTitle);

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << "| " << left << setw(40) << "Date/Time";
        cout << "| " << left << setw(15) << "S.Account";
        cout << "| " << left << setw(12) << "d.Account";
        cout << "| " << left << setw(12) << "Amount";
        cout << "| " << left << setw(12) << "S.Balance";
        cout << "| " << left << setw(12) << "d.Balance";
        cout << "| " << left << setw(12) << "User";


        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;


        if (vTransfers.size() == 0)
            cout << "\t\t\t\tNo  Logins In the System!";
        else

            for (clsTransferLog Login : vTransfers)
            {
                PrintTransferRecordLine(Login);
                cout << endl;
            }

        cout << "\n_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }


};


