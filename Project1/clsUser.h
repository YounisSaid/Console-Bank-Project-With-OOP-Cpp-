#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include "clsUtil.h"


using namespace std;
class clsUser : public clsPerson
{
private:
    enum enMode { EmptyMode = 0, UpdateMode = 1, AddMode = 2 };
    enMode _Mode;


    string _Username;
    string _Password;
    int _Permissions;
    bool _MarkedForDelete = true;

    static clsUser _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
    {
        vector < string > vUserData;
        vUserData = clsString::Split(Line, Seperator);
        return  clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
            vUserData[3], vUserData[4],clsUtil::DecryptText( vUserData[5]), stod(vUserData[6]));

    }
    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }
    static  vector <clsUser> _LoadUsersDataFromFile()
    {

        vector <clsUser> vUsers;

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsUser User = _ConvertLinetoUserObject(Line);

                vUsers.push_back(User);
            }

            MyFile.close();

        }

        return vUsers;

    }
    static string _ConvertUserObjectToLine(clsUser User, string Seperator = "#//#")
    {

        string stUserRecord = "";
        stUserRecord += User.FirstName + Seperator;
        stUserRecord += User.LastName + Seperator;
        stUserRecord += User.Email + Seperator;
        stUserRecord += User.Phone + Seperator;
        stUserRecord += User.Username + Seperator;
        stUserRecord += clsUtil::EncryptText( User.Password) + Seperator;
        stUserRecord += to_string(User.Permissions);

        return stUserRecord;

    }
    static void _SaveUsersDataToFile(vector <clsUser> vUsers)
    {
        fstream Myfile;
        Myfile.open("Users.txt", ios::out);
        if (Myfile.is_open())
        {
            string line;

            for (clsUser C : vUsers)
            {
                if (C._MarkedForDelete == true)
                {
                    line = _ConvertUserObjectToLine(C);
                    Myfile << line << endl;
                }

            }

        }
    }
    void _Update()
    {
        vector < clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& C : _vUsers)
        {
            if (C._Username == _Username)
            {
                C = *this;
                break;
            }
        }
        _SaveUsersDataToFile(_vUsers);
    }


    static void AddDataLineToFile(string line)
    {
        fstream Myfile;
        Myfile.open("Users.txt", ios::out | ios::app);
        if (Myfile.is_open())
        {

            Myfile << line << endl;
        }
        Myfile.close();
    }

    void _AddNew()
    {
        AddDataLineToFile(_ConvertUserObjectToLine(*this));
    }




public:
    clsUser(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string GetUsername, string Password,
        int Permissions) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _Username = GetUsername;
        _Password = Password;
        _Permissions = Permissions;
    }
    
    void  SetUsername(string Username)
    {
        _Username= Username;
    }
    string GetUsername()
    {
        return _Username;
    }
    __declspec(property(get = GetUsername, put = SetUsername)) string Username;

    void SetPassword(string PinCode)
    {
        _Password = PinCode;
    }

    string GetPassword()
    {
        return _Password;
    }
    __declspec(property(get = GetPassword, put = SetPassword)) string Password;

    void SetPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }

    int GetPermissions()
    {
        return _Permissions;
    }
    __declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

    static clsUser GetAddNewUserObject(string Username)
    {
        return clsUser(enMode::AddMode, "", "", "", "", Username, "", 0);
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
        {
            _AddNew();
            _Mode = enMode::UpdateMode;
            return enSaveResults::svSucceeded;
        }

        }
    }
   /* static void ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter Your First name : ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter Your Last name : ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Your Email : ";
        User.Email = clsInputValidate::ReadString();

        cout << "\nEnter Your Phone : ";
        User.Phone = clsInputValidate::ReadString();

        cout << "\nEnter Your Password : ";
        User.PinCode = clsInputValidate::ReadString();

        cout << "\nEnter Your Balance : ";
        User.AccountBalance = clsInputValidate::ReadDblNumber();
    }*/

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }
    bool Delete()
    {
        vector < clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& C : _vUsers)
        {
            if (C._Username == _Username)
            {
                C._MarkedForDelete = false;

                break;
            }
        }
        *this = _GetEmptyUserObject();
        _SaveUsersDataToFile(_vUsers);
        return true;
    }

    static clsUser Find(string Username)
    {
        fstream Myfile;

        Myfile.open("Users.txt", ios::in);
        if (Myfile.is_open())
        {
            string line;
            while (getline(Myfile, line))
            {
                clsUser User = _ConvertLinetoUserObject(line);
                if (User.Username == Username)
                {
                    Myfile.close();
                    return User;
                }

            }
        }
        Myfile.close();
        return _GetEmptyUserObject();
    }
    static clsUser Find(string Username, string Password)
    {
        fstream Myfile;

        Myfile.open("Users.txt", ios::in);
        if (Myfile.is_open())
        {
            string line;
            while (getline(Myfile, line))
            {
                clsUser User = _ConvertLinetoUserObject(line);
                if (User.Username == Username && User.Password == Password)
                {
                    Myfile.close();
                    return User;
                }

            }
        }
        Myfile.close();
        return _GetEmptyUserObject();
    }
    static bool IsUserExist(string Username)
    {
        clsUser User = Find(Username);
        return(!User.IsEmpty());
    }
    static  vector <clsUser> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }
    enum enPermissions {
        eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
        pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64,pLoginRegister=128
    };

    
    
    bool CheckAccessPermission(enPermissions Permission)
    {
        if (this->Permissions == enPermissions::eAll)
            return true;

        return (static_cast<int>(Permission) & static_cast<int>(this->Permissions)) == static_cast<int>(Permission);

    }

};
