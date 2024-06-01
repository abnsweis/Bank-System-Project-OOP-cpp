#pragma once 
#include <iostream>
#include "../../clsCurrency.h"
#include "../../lib/clsInputValidation.h"
#include "../clsScreen.h"


class clsFindCurrencyScreen : protected clsScreen {
    
    private :
        
    
    
    static void _ShowResults(clsCurrency Currency){
        if(!Currency.IsEmpty()){
            cout << "Currency Found :-)" << endl;
            _PrintCurrency(Currency);
        }else{
            cout << "Currency Not Found :-(" << endl;
        }
        
    }
    
    
    static void _PrintCurrency(clsCurrency Currency){
        
        cout << "\n==============================" << endl;
        cout << "\t Currency Info" << endl;
        cout << "==============================" << endl;
        cout << "Country       : "<<Currency.Country() << endl;
        cout << "Currency Code : "<<Currency.CurrencyCode() << endl;
        cout << "Currency Name : "<<Currency.CurrencyName() << endl;
        cout << "Rate          : "<<Currency.Rate() << endl;
        cout << "==============================\n" << endl;
    }
    public :
    static void ShowFindCurrencyScreen(){
        
        _DrowScreenHeader("Find Currency Screen");
        
        short  Answer ;
        cout << "Find By [1] By Code or [2] By Country Name ? " ;
        cin >> Answer;
        
        
        
        if(Answer == 1 ){
            string CurrencyCode ;
            cout << "Please Enter Currency Code :" ;
            CurrencyCode = clsInputValidation::ReadString();
            clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
            _ShowResults(Currency);
            
        }
        else{
            string Country ;
            cout << "Please Enter Country Name  :" ;
            Country = clsInputValidation::ReadString();
            clsCurrency Currency = clsCurrency::FindByCountry(Country);
            _ShowResults(Currency);
        }
        
        
    }
    
};