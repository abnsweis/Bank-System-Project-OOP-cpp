#pragma once 

#include <iostream>
#include "../clsScreen.h"
#include "../../clsCurrency.h"
#include "../../lib/clsInputValidation.h"

class clsUpdateCurrencyRateScreen : protected clsScreen{
  
  private :
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
    static float _ReadRate( ){
        cout << "Enter New Rate : " ;
        float NewRate = clsInputValidation::ReadFloatNumber("Pleace Enter A Float Number ");
        return NewRate;
    }
  public :
  
  static void ShowUpdateRateScreen(){
      
        _DrowScreenHeader("Update Currency Rate Screen ");
        
        cout << "Please Enter Currency Code : ";
        string CurrencyCode = clsInputValidation::ReadString();
        
        while(!clsCurrency::IsCurrencyExist(CurrencyCode)){
            cout << "Currency Not Found :-( choose Aonther Currency  " << endl;
            cout << "Please Enter Currency Code : ";
            CurrencyCode = clsInputValidation::ReadString();
        }
        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        _PrintCurrency(Currency);
        
        char Answer = 'n';
        cout << "are you sure you want to update rate of this currency ? (Y?N)";
        cin >> Answer;
        
        if(toupper(Answer) == 'Y'){
            cout << "================================" << endl;
            
            Currency.UpdateRate(_ReadRate());
            cout << "Successflly Updated Rate :-)" << endl;
            _PrintCurrency(Currency);
        }
  }
    
};