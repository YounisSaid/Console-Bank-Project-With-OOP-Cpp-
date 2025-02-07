
#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;
class clsBankClient : public clsPerson
{
private:
    enum enMode { EmptyMode = 0, UpdateMode = 1 , AddMode =2 };
    enMode _Mode;
    

    string _Username;
    string _Password;
    float _AccountBalance;
    bool _MarkedForDelete = true;

    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector < string > vClientData;
        vClientData = clsString::Split(Line, Seperator);
        return  clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

    }
    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }
    static  vector <clsBankClient> _LoadClientsDataFromFile()
    {

        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsBankClient Client = _ConvertLinetoClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();

        }

        return vClients;

    }
    static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {

        string stClientRecord = "";
        stClientRecord += Client.FirstName + Seperator;
        stClientRecord += Client.LastName + Seperator;
        stClientRecord += Client.Email + Seperator;
        stClientRecord += Client.Phone + Seperator;
        stClientRecord += Client.GetUsername() + Seperator;
        stClientRecord += Client.PinCode + Seperator;
        stClientRecord += to_string(Client.AccountBalance);

        return stClientRecord;

    }
    static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
    {
        fstream Myfile;
        Myfile.open("Clients.txt", ios::out);
        if (Myfile.is_open())
        {
            string line;

                for (clsBankClient C : vClients)
                {
                    if (C._MarkedForDelete == true)
                    {
                        line = _ConverClientObjectToLine(C);
                        Myfile << line << endl;
                    }
                    
                }
            
        }
    }
     void _Update()
    {
        vector < clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();
        
        for (clsBankClient& C : _vClients)
        {
            if (C._Username == _Username)
            {
                C = *this;
                break;
            }
        }
        _SaveCleintsDataToFile(_vClients);
    }

     
     static void AddDataLineToFile(string line)
     {
         fstream Myfile;
         Myfile.open("Clients.txt", ios::out |ios::app);
         if (Myfile.is_open())
         {
                                     
             Myfile << line << endl;
         }
         Myfile.close();
     }
     
     void _AddNew()
     {
         AddDataLineToFile(_ConverClientObjectToLine(*this));
     }
    
    
    

public:
    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string GetUsername, string PinCode,
        float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _Username = GetUsername;
        _Password = PinCode;
        _AccountBalance = AccountBalance;
    }
    string GetUsername()
    {
        return _Username;
    }

    void SetPassword(string PinCode)
    {
        _Password = PinCode;
    }

    string GetPassword()
    {
        return _Password;
    }
    __declspec(property(get = GetPassword, put = SetPassword)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

    /*void Print()
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << FirstName;
        cout << "\nLastName    : " << LastName;
        cout << "\nFull Name   : " << FullName();
        cout << "\nEmail       : " << Email;
        cout << "\nPhone       : " << Phone;
        cout << "\nAcc. Number : " << _AccountNumber;
        cout << "\nPassword    : " << _PinCode;
        cout << "\nBalance     : " << _AccountBalance;
        cout << "\n___________________\n";

    }*/
    static clsBankClient GetAddNewClientObject(string GetUsername)
    {
        return clsBankClient(enMode::AddMode, "", "", "", "", GetUsername, "", 0);
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };
    enSaveResults Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:
            return enSaveResults::svFaildEmptyObject;
        case enMode::UpdateMode:
            _Update();
            return enSaveResults::svSucceeded;
        case enMode::AddMode:
            /* if (!IsClientExist(_AccountNumber))
             {
                 return enSaveResults::svFaildAccountNumberExists;
             }
             else */
        {
            _AddNew();
            _Mode = enMode::UpdateMode;
            return enSaveResults::svSucceeded;
        }

        }
    }
    

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }
    bool Delete()
    {
        vector < clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C._Username == _Username)
            {
                C._MarkedForDelete = false;

                break;
            }
        }
        *this = _GetEmptyClientObject();
        _SaveCleintsDataToFile(_vClients);
        return true;
    }

    static clsBankClient Find(string Username)
    {
        fstream Myfile;
       
        Myfile.open("Clients.txt",ios::in);
        if (Myfile.is_open())
        {
            string line;
            while (getline(Myfile, line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(line);
                if (Client.GetUsername() == Username)
                {
                    Myfile.close();
                    return Client;
                }
                
            }
        }
        Myfile.close();
        return _GetEmptyClientObject();
    }
    static clsBankClient Find(string GetUsername,string PinCode)
    {
        fstream Myfile;

        Myfile.open("Clients.txt", ios::in);
        if (Myfile.is_open())
        {
            string line;
            while (getline(Myfile, line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(line);
                if (Client.GetUsername() == GetUsername && Client.PinCode == PinCode)
                {
                    Myfile.close();
                    return Client;
                }

            }
        }
        Myfile.close();
        return _GetEmptyClientObject();
    }
    static bool IsClientExist(string GetUsername)
    {
        clsBankClient Client = Find(GetUsername);
        return(!Client.IsEmpty());
    }
    

    static void ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();
    }

    

    

    
    static float GetTotalBalances()
    {
        vector <clsBankClient> vClients = _LoadClientsDataFromFile();

        double TotalBalances = 0;

        for (clsBankClient Client : vClients)
        {

            TotalBalances += Client.AccountBalance;
        }

        return TotalBalances;

    }



   
    static  vector <clsBankClient> GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }

     void Depoist(double Amount)
    {
         _AccountBalance += Amount;
         Save();
    }

     void Withdraw(double Amount)
     {
         _AccountBalance -= Amount;
         Save();

     }
     
};
