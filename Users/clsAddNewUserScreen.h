#pragma once

#include <iostream>
#include "../Screens/clsScreen.h"
#include "../clsUser.h"
#include "../lib/clsInputValidation.h"

using namespace std;

class clsAddNewUserScreen: protected clsScreen {

    private:

    static void _PrintUserInfo(clsUser user) {
        cout << "===============================" << endl;
        cout << "        User Info" << endl;
        cout << "===============================" << endl;
        cout << "First Name : "<<user.GetFirstName() << endl;
        cout << "Last Name  : "<<user.GetLastName() << endl;
        cout << "Email      : "<<user.Email() << endl;
        cout << "Phone      : "<<user.Phone() << endl;
        cout << "Username   : "<<user.Username() << endl;
        cout << "Password   : "<<user.Password() << endl;
        cout << "Per**aions : "<<user.Permissions() << endl;
        cout << "===============================\n" << endl;
    }
    static void _ReadUserInfo(clsUser& user) {

        cout << "\nPlease Enter First Name :";
        user.SetFirstName(clsInputValidation::ReadString());

        cout << "\nPlease Enter Last Name :";
        user.SetLastName(clsInputValidation::ReadString());

        cout << "\nPlease Enter Email :";
        user.SetEmail(clsInputValidation::ReadString());

        cout << "\nPlease Enter Phone :";
        user.SetPhone(clsInputValidation::ReadString());


        cout << "\nPlease Enter Password  :";
        user.SetPassword(clsInputValidation::ReadString());

        cout << "\nPlease Enter Permissions  :";
        user.SetPermissions(_ReadPermissionsToSet());


    }
    static short _ReadPermissionsToSet() {

        int Permissions = 0;
        char Answer = 'n';

        cout << "\nDo you want to grant this user full permissions on the system?(y/N)";
        cin >> Answer;

        if(toupper(Answer) == 'Y') {
            return -1;
        }


        cout << "[1] Show All Clients ? (y/N)";
        cin >> Answer;
        if(toupper(Answer) == 'Y') {
            Permissions += clsUser::eShowListClients;
        }


        cout << "[2] Add New Clients? (y/N)";
        cin >> Answer;
        if(toupper(Answer) == 'Y') {
            Permissions += clsUser::eAddClients;
        }

        cout << "[3] Delete Clients? (y/N)";
        cin >> Answer;
        if(toupper(Answer) == 'Y') {
            Permissions += clsUser::eDeleteClients;
        }

        cout << "[4] Update Clients? (y/N)";
        cin >> Answer;
        if(toupper(Answer) == 'Y') {
            Permissions += clsUser::eUpdateClients;
        }

        cout << "[5] Find Clients? (y/N)";
        cin >> Answer;
        if(toupper(Answer) == 'Y') {
            Permissions += clsUser::eFindClients;
        }


        cout << "[6] Transacions? (y/N)";
        cin >> Answer;
        if(toupper(Answer) == 'Y') {
            Permissions += clsUser::eTransacions;
        }

        cout << "[7] Manage Users? (y/N)";
        cin >> Answer;
        if(toupper(Answer) == 'Y') {
            Permissions += clsUser::eManageUsers;
        }
        cout << "[8] Show Logins History? (y/N)";
        cin >> Answer;
        if(toupper(Answer) == 'Y') {
            Permissions += clsUser::eLoginsHistory;
        }

        return Permissions;
    }
    public:

    static void ShowAddNewUserScreen() {

        _DrowScreenHeader("Add New User Screen ");

        string UserName = "";
        cout << "Please Enter UserName : ";
        UserName = clsInputValidation::ReadString();

        while(clsUser::IsUserExist(UserName)) {
            cout << "username ( "<<UserName << " )  already exist please choose another one " << endl;

            cout << "Please Enter UserName : ";
            UserName = clsInputValidation::ReadString();
        }

        clsUser User = clsUser::GetAddNewObject(UserName);
        
        cout << "\nPlease Enter User information " << endl;
        _ReadUserInfo(User);
        
        
        
        
        
        clsUser::enSaveResults SaveResults;
        
        
        SaveResults = User.Save();
        
        switch(SaveResults){
            case clsUser::enSaveResults::svSuccessFully:{
                cout << "\nSuccessfully Saved User :-)" << endl;
                _PrintUserInfo(User);
                break;
            }
            case clsUser::svFaildEmptyObject:{
                if(User.IsEmpty()){
                    cout << "Error User was not saved because it's Empty :-( " << endl;
                    break;
                }
            }
            case clsUser::enSaveResults::svFaildUserExist:{
                
                cout << "Error User was not saved because UserName uesd :-(" << endl;
                break;
            }
        }
    }
};