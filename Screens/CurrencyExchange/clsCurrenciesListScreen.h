#pragma once 

#include <iostream>
#include "../../clsCurrency.h"
#include "../clsScreen.h"


class clsCurrenciesListScreen : protected clsScreen {
    
    private :
    
    static void PrintCurrencyRecord(clsCurrency Currency){
        
        cout << "| " << left << setw(30) << Currency.Country();   
        cout << "| " << left << setw(6) << Currency.CurrencyCode();     
        cout << "| " << left << setw(35) << Currency.CurrencyName() ;     
        cout << "| " << left << setw(10) << Currency.Rate() << " |\n";     
        
    }
    
    public :
    
    static void ShowCurrenciesList(){
        vector<clsCurrency> vCurrencys = clsCurrency::GetCurrencysList() ;
        string SubTitle = to_string(vCurrencys.size());
        
        _DrowScreenHeader("Currencies List Screen ",SubTitle);
        
        
        cout << "\n==========================================================================================="<<endl; 
        cout << "| " << left << setw(30) << "Country";   
        cout << "| " << left << setw(6) << "Code ";     
        cout << "| " << left << setw(35) << "Name" ;     
        cout << "| " << left << setw(10) << "Rate /(1$)" << " |";     
        cout << "\n==========================================================================================="<<endl; 
        
        if(vCurrencys.size() > 0){
            
            for (clsCurrency  &C : vCurrencys) {
                PrintCurrencyRecord(C);
            }
        }else{
            cout << "\t\t Not Currencies Availanle In The System" << endl;
        }
        cout << "\n==========================================================================================="<<endl; 
    }
    
};