#pragma once
#include <iostream>
#include "../clsUser.h"
#include "../Global.h"
#include "../lib/clsDate.h"

using namespace std;



class clsScreen {


    protected:

    static void _DrowScreenHeader(string Title, string SubTitle = "") {


        cout << "\e[0m" << endl;
        system("cl");
        if(!CurrentUser.IsEmpty()) {
            cout <<"=====================================================" << endl;
             
            cout << "\tUsername : "<< CurrentUser.Username() << "\t";
            cout <<"\t" <<clsDate::DateToString(clsDate::GetSystemDate()) <<endl;
            
        }
        cout <<"=====================================================" << endl;
        cout << "\t\t   "<<Title << endl;
        if(SubTitle != "") {
            cout << "\t\t\t"<<SubTitle << endl;
        }

        cout<<"=====================================================" << endl;

    }

    static bool CheckAccessRights(clsUser::enPermissions Permission) {
        
        if(!CurrentUser.CheckAccessPermission(Permission)){
            
            cout<<"\e[91m ============================================"<<endl;
	        cout<<"      Access Denid Contact To Admin :-(     " << endl;
	        cout<<"============================================"<<endl;
            cout << "Access Denied :-(, \nYou dont Have Permission To Do this,\nPlease Conact Your Admin.\n\n\e[94m";
            return false;
        }
        else{
            return true;
        }
        
    }

};