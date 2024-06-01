#pragma once 

#include <iostream>
#include "../Screens/clsScreen.h"
#include "../lib/clsInputValidation.h"
#include "../clsUser.h"

using namespace std;

class clsDeleteUserScreen : protected clsScreen{
    
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
    public :
    
    static void ShowDeleteUserScreen(){
        
        _DrowScreenHeader("Delete User Screen ");
        
        string UserName = "";
        cout << "Please Enter UserName :" ;
        UserName = clsInputValidation::ReadString();
        
        while(!clsUser::IsUserExist(UserName)){
            cout << "UserName ( "<<UserName << " ) Is Not Found Choose Aonther One " << endl;
            cout << "Please Enter UserName :" ;
            UserName = clsInputValidation::ReadString();
        };
        
        clsUser User = clsUser::Find(UserName);
        _PrintUserInfo(User);
        char Answer = 'n';
        cout << "Are you sure want to delete this user?(Y/N):";
        cin >> Answer;
        
        if(toupper(Answer) == 'Y'){
            
            if(User.Delete()){
                cout << "SuccessFully Deleted User ( "<<UserName<<" ) :-)" << endl;
                _PrintUserInfo(User);
            }else{
                cout << "Error User Not Deleted :-(" << endl;
            }
            
        }
    }
    
};
