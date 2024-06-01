#pragma once

#include <iostream>
#include <fstream>
#include "./lib/clsString.h"
#include "./lib/clsUtil.h"
#include "./clsPerson.h"
#include "./lib/clsDate.h"


using namespace std;

class clsUser: public clsPerson {

    private:
    
    
    
    
    
    
    
    enum enMode {
        enEmptyMode = 0,
        eUpdateMode = 1,
        eAddNewMode = 2
    };

    
    enMode _Mode;
    string _Username;
    string _Password;
    int _Permissions;

    bool _MarkForDalete = false;


    static clsUser _GetEmptyObject() {
        return clsUser(enMode::enEmptyMode, "", "", "", "", "", "", 0);
    }

    static clsUser _ConvertLineDateToObject(string Line, string Seperator = "#//#") {
        
        vector < string > vDate = clsString::split(Line, Seperator);
        
        
        return clsUser(enMode::eUpdateMode, vDate[0], vDate[1], vDate[2], vDate[3], vDate[4], clsUtil::DecryptText(vDate[5],10), stoi(vDate[6]));

    }

    static string _ConvertObjectToLineDate(clsUser user, string Seperator = "#//#") {

        string line = "";

        line += user.GetFirstName() + Seperator;
        line += user.GetLastName() + Seperator;
        line += user.Email() + Seperator;
        line += user.Phone() + Seperator;
        line += user.Username() + Seperator;
        
        line += clsUtil::EncryptText(user.Password(),10) + Seperator;
        line += to_string(user.Permissions());

        return line;
    }

    static void _AddLineDateToFile(string LineDate) {

        fstream File;

        File.open("./Users.txt", ios::out | ios::app);


        if(File.is_open()) {
            File << LineDate <<endl;
            File.close();
        }

    }

    // Load Date From File
    static vector < clsUser > _LoadDateFromFile() {

        vector < clsUser > _vUsers;

        fstream File;

        File.open("Users.txt", ios::in);

        if(File.is_open()) {

            string line;
            
            while(getline(File, line)) {

                clsUser user = _ConvertLineDateToObject(line);
                
                _vUsers.push_back(user);

            }
            
            File.close();
        }
        return _vUsers;
    }
    // Save Date To Fike
    static void _SaveDateToFile(vector < clsUser > vUsers) {

        fstream File;

        File.open("./Users.txt", ios::out);

        if(File.is_open()) {

            string line;

            for (clsUser &user: vUsers) {
                if(user.MarkForDaleted() == false){
                    line = _ConvertObjectToLineDate(user);
                    File << line << endl;
                }
            }
            File.close();

        }

    }
    // Update User
    void _Update() {

        vector < clsUser > _vUsers = _LoadDateFromFile();


        for (clsUser &user: _vUsers) {

            if(user.Username() == _Username) {

                user = *this;
                break;

            }

        }
        _SaveDateToFile(_vUsers);
    }

    // Add New User
    void _AddNewUser() {

        _AddLineDateToFile(_ConvertObjectToLineDate(*this));


    }

    string _ConvertUserDateToDateLoginline(string Seperator = "#//#"){
            string line = "";
            
            line += clsDate::DateTime() + Seperator;
            line += _Username +  Seperator;
            line += clsUtil::EncryptText(_Password,10) +  Seperator;
            line += to_string(_Permissions);
            
            return line;
        }
    
    
    public:
    enum enPermissions {
	    eAll=-1,
	    eShowListClients=1,
	    eAddClients=2,
	    eDeleteClients=4,
	    eUpdateClients=8,
	    eFindClients = 16,
	    eTransacions=32,
	    eManageUsers=64,
	    eLoginsHistory =128
    };
    struct stLoginHistory{
        string DateTime ;
        string Username ;
        string Password ;
        int Permissions ;
    };
    
    clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string Username, string Password, int Permissions): clsPerson(FirstName, LastName, Email, Phone) {

        _Mode = Mode;
        _Username = Username;
        _Password = Password;
        _Permissions = Permissions;
    }


    static stLoginHistory _ConvertLoginRegisterLineToStrcat(string Line,string Seperator){
        vector <string> vDate = clsString::split(Line,Seperator);
       
        stLoginHistory UserLogin;
       
        UserLogin.DateTime = vDate[0];
        UserLogin.Username = vDate[1];
        UserLogin.Password = clsUtil::DecryptText(vDate[2],10);
        UserLogin.Permissions = stoi(vDate[3]);
        
        return UserLogin;
    }
    bool IsEmpty() {
        return (_Mode == enMode::enEmptyMode);
    }
    
    bool MarkForDaleted(){
        return _MarkForDalete;
    }
    
    string Username() {
        return _Username;
    }
    void SetUsername(string Username) {
        _Username = Username;
    }

    string Password() {
        return _Password;
    }
    void SetPassword(string Password) {
        _Password = Password;
    }

    int Permissions() {
        return _Permissions;
    }
    void SetPermissions(int Permissions) {
        _Permissions = Permissions;
    }

    bool MarkForDalete() {
        return _MarkForDalete;
    }
    void SetMarkForDelete(bool MarkForDalete) {

        _MarkForDalete = MarkForDalete;

    }

    // Get New Object
    static clsUser GetAddNewObject(string Username) {
        return clsUser(enMode::eAddNewMode, "", "", "", "", Username, "", 0);
    }

    // Find
    static clsUser Find(string Username) {

        fstream File;

        File.open("./Users.txt", ios::in);

        if(File.is_open()) {

            string line;

            while(getline(File, line)) {

                clsUser user = _ConvertLineDateToObject(line);
                if(user.Username() == Username) {

                    File.close();
                    return user;
                }

            }
            File.close();
        }

        return _GetEmptyObject();
    }
    static clsUser Find(string Username,string Password) {

        fstream File;

        File.open("./Users.txt", ios::in);

        if(File.is_open()) {

            string line;

            while(getline(File, line)) {

                clsUser user = _ConvertLineDateToObject(line);
                
                if(user.Username() == Username && user.Password() == clsUtil::EncryptText(Password,0)) {
                    File.close();
                    return user;
                }

            }
            File.close();
        }

        return _GetEmptyObject();
    }

    // Is User Exist
    static bool IsUserExist(string Username) {
        clsUser user = Find(Username);
        return !(user.IsEmpty());
    }


    enum enSaveResults {
        svFaildEmptyObject = 0,
        svSuccessFully = 1,
        svFaildUserExist = 2
    };


    // Save
    enSaveResults Save() {

        switch(_Mode) {
            case enMode::enEmptyMode: {
                if(IsEmpty()) {
                    return enSaveResults::svFaildEmptyObject;

                }
            }
            case enMode::eUpdateMode: {

                _Update();
                return enSaveResults::svSuccessFully;

            }

            case enMode::eAddNewMode: {
                _AddNewUser();
                return enSaveResults::svSuccessFully;
            }
        }
    }


    bool Delete() {
        vector < clsUser > _vUsers = _LoadDateFromFile();

        
        for (clsUser &user: _vUsers) {
            if(user.Username()==_Username){
                user.SetMarkForDelete(true);
                break;
            }
        }
        _SaveDateToFile(_vUsers);
        *this = _GetEmptyObject();
        return true;
    }
    
    static vector <clsUser> GetListUsers(){
        return _LoadDateFromFile();
    }
    
    bool CheckAccessPermission(enPermissions Permission){
        
        if(Permission == enPermissions::eAll){
            return true;
        }
        if((Permission & this->_Permissions )== Permission){
            return true;
        }
        return false;
    }  
    
    void RegisterLogin(){
        
        string DateLoginline = _ConvertUserDateToDateLoginline();
        fstream File ;
        File.open("./RegisterLogin.txt",ios::out | ios::app);
        if(File.is_open()){
            File << DateLoginline <<endl;
            File.close();
            
        }
    }
    
    
    
    static vector <stLoginHistory> GetLoginsHistory(){
        vector <stLoginHistory> vLogins;
        
        fstream File ;
        
        File.open("RegisterLogin.txt",ios::in);
        
        if(File.is_open()){
            
            string line = "";
            while(getline(File,line)){
                
                stLoginHistory stLogin = _ConvertLoginRegisterLineToStrcat(line,"#//#");
                vLogins.push_back(stLogin);
                
            }
            File.close();
        }
        
        return vLogins;
    }
    
    
};