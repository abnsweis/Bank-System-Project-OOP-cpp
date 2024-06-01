#pragma once 

#include <iostream>
#include <fstream>
#include "../clsUser.h"
#include "./clsScreen.h"
#include "../lib/clsDate.h"
#include "../Global.h"
using namespace std;


class clsLoginsHistoryScreen : protected clsScreen{
    
    private :
    
    static void PrintLoginRecord(clsUser::stLoginHistory login) {
        cout <<"| "<<left<< setw(20) << login.DateTime;
        cout <<"| "<< setw(10) << login.Username;
        
        cout <<"| "<< setw(20) << login.Password;
        
        cout <<"| "<< setw(10) << login.Permissions << "|";
        cout << endl;

    }

    
    
    
    
    public :
    
    static void ShowLoginsHistoryScreen(){
        
        if(!CheckAccessRights(clsUser::enPermissions::eLoginsHistory)){
            return ;
        }
        _DrowScreenHeader("Logins History Screen ");
        
        vector <clsUser::stLoginHistory> vLogins = clsUser::GetLoginsHistory();
        cout << "\n==============================================";
        cout << "========================" << endl;
        cout << "| " << left << setw(20) << "Date / Time ";
        cout << "| " << left << setw(10) << "UserName ";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << "\n==============================================";
        cout << "========================" << endl;
        if(vLogins.size() != 0)
        for (clsUser::stLoginHistory &login : vLogins) {
            PrintLoginRecord(login);
        }
        else{
            cout << "\t\t No Logins Available In System" << endl;
        }
        cout << "==============================================";
        cout << "========================" << endl;
    }
};