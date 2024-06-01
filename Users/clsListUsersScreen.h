#pragma once

#include <iostream>
#include "../clsUser.h"
#include "../Screens/clsScreen.h"

using namespace std;



class clsListUsersScreen : protected clsScreen{
    
    private :
    static void PrintUserRecord(clsUser user){
	    cout <<"| "<<left <<setw(10) << user.Username();
	    cout <<"| "<<left <<setw(17) << user.FullName();
	    cout <<"| "<<left <<setw(20) << user.Phone();
	    cout <<"| "<<left <<setw(20) << user.Email();
	    cout <<"| "<<left <<setw(15) << user.Password();
	    cout <<"| "<<left <<setw(13) << user.Permissions() <<"|"<<endl;
    }
    
    public :
    
    static void ShowListScreenHeader(){
        
        vector<clsUser> vUsers = clsUser::GetListUsers() ;
        
        string Title = "List Users Screen";
        string Subtitle = "( " +to_string(vUsers.size()) + " ) Users ";
        
        _DrowScreenHeader(Title,Subtitle);
        
        
        cout << "\n============================================================================================================"<<endl; 
        cout << "| " << left << setw(10) << "Username";   
        cout << "| " << left << setw(17) << "Full Name ";     
        cout << "| " << left << setw(20) << "Phone" ;     
        cout << "| " << left << setw(20) << "Email" ;     
        cout << "| " << left << setw(15) << "Password" ;     
        cout << "| " << left << setw(5) << "Permissaions" << " |";     
        cout << "\n============================================================================================================"<<endl; 
        
        
        if(vUsers.size() != 0 ){
            
            for (clsUser &user : vUsers) {
                PrintUserRecord(user);
            }
        }else{
            cout << "\t\tNot Found Users In The System " << endl;
        }
        cout << "\n============================================================================================================"<<endl; 
        
    }
    
    
};
