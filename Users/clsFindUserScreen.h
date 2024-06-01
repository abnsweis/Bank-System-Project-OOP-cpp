#pragma once 
#include <iostream>
#include "../clsUser.h"
#include "../lib/clsInputValidation.h"
#include "../Screens/clsScreen.h"


using namespace std;


class clsFindUserScreen : protected clsScreen{
    
    private :
    static void _PrintUserInfo(clsUser user) {
        cout << "===============================" << endl;
        cout << "        User Info" << endl;
        cout << "===============================" << endl;
        cout << "First Name : "<<user.GetFirstName() << endl;
        cout << "Last Name  : "<<user.GetLastName() << endl;
        cout << "Email      : "<<user.Email() << endl;
        cout << "Phone      : "<<user.Phone() << endl;
        cout << "Username   : "<<user.Username() << endl;
        cout << "Password   : "<<clsUtil::DecryptText(user.Password(),2003) << endl;
        cout << "Per**aions : "<<user.Permissions() << endl;
        cout << "===============================\n" << endl;
    }
    
    public :
    
    
    static void ShowFindUserScreen(){
        
        _DrowScreenHeader("Find User Screen ");
        
        string UserName = "";
        cout << "Please Enter UserName : " ;
        UserName = clsInputValidation::ReadString();
        
        while(!clsUser::IsUserExist(UserName)){
            cout << "UserName ( "<<UserName << " ) Not Found Choose Aonther One " << endl;
            cout << "Please Enter UserName : " ;
            UserName = clsInputValidation::ReadString();
        }
        
        
        clsUser User = clsUser::Find(UserName);
        
        if(!User.IsEmpty()){
            cout << "\nFound User :-)\n" << endl;
            _PrintUserInfo(User);
        }
        
        
    }
    
};