#pragma once
#include <iostream>
#include "./clsScreen.h"
#include "./clsMainScreen.h"
#include "../lib/clsInputValidation.h"
#include "../clsUser.h"
#include "../Global.h"


using namespace std;

class clsLoginScreen : protected clsScreen{
    
    private :
    
    static bool _Login(){
        
        bool LoginFaile = false;
        short LoginFaileCount = 0;
        
        string UserName , Password;
        
        do{
            
            if(LoginFaile){
                LoginFaileCount++;
                cout << "Invalid UserName or Password Try Again :-(" << endl;
                
                cout << "You Have (" <<(3-LoginFaileCount) <<") Login Attempts" << endl;
            }
            
            if(LoginFaileCount == 3){
                cout << "System Locked After 3 Attempts Login Failed :-(" << endl;
                return false;
            }
            
            cout << "Enter UserName :";
            UserName = clsInputValidation::ReadString();
            
            cout << "Enter Password :";
            Password = clsInputValidation::ReadString();
            
            CurrentUser = clsUser::Find(UserName,Password);
            
            LoginFaile = CurrentUser.IsEmpty();
            
        }while(LoginFaile);
        
        CurrentUser.RegisterLogin();
        clsMainScreen::ShowMainMenuScreen();
        return true;
    }
    
    public :
    
    
    static bool ShowLoginScreen(){
        system("cl");
        _DrowScreenHeader("Login Screen ");
        return _Login();
        
        
    }
    
    
};