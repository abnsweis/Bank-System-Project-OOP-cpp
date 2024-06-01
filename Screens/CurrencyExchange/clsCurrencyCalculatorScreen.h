#pragma once 

#include <iostream>
#include "../clsScreen.h"
#include "../../clsCurrency.h"
#include "../../lib/clsInputValidation.h"



class clsCurrencyCalculatorScreen : protected clsScreen{
    
    private :
    static void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card:") {

        cout << "\n" << Title << "\n";
        cout << "_____________________________\n";
        cout << "\nCountry       : " << Currency.Country();
        cout << "\nCode          : " << Currency.CurrencyCode();
        cout << "\nName          : " << Currency.CurrencyName();
        cout << "\nRate(1$) =    : " << Currency.Rate();
        cout << "\n_____________________________\n\n";

    }
    static clsCurrency _GetCurrency(string Message){
        cout << Message ;
        string CurrencyCode = clsInputValidation::ReadString();
        while(!clsCurrency::IsCurrencyExist(CurrencyCode)){
            cout << "Currency Not Found :-( choose Aonther Currency  " << endl;
            cout << Message ;
            CurrencyCode = clsInputValidation::ReadString();
        }
        
        return clsCurrency::FindByCode(CurrencyCode);
    }
    
    static float _ReadAmount(){
        float Amount =0;
        cout << "Enter Amount To Exchange :" ;
        Amount = clsInputValidation::ReadFloatNumber("Enter Float Number ");
        
        return Amount;
    }
    
    static void _PrintCalculationsResults(float Amount,clsCurrency CurrencyFrom,clsCurrency CurrencyTo){
        
        float AmountInUSD = CurrencyFrom.ConvertToUSD(Amount);
        _PrintCurrencyCard(CurrencyFrom, "Convert From:");
        cout << Amount <<" "<<CurrencyFrom.CurrencyCode() <<" = "<<AmountInUSD <<" USD" << endl;
        if(CurrencyTo.CurrencyCode() == "USD"){
            return;
        }
        
        cout << "Converting From USD To " << endl;
        _PrintCurrencyCard(CurrencyTo, "Convert To:");
        
        
        float AmountInCurrrencyTo = CurrencyFrom.ConvertToOtherCurrency(Amount,CurrencyTo);
        cout << AmountInCurrrencyTo << endl;
        
        cout << Amount << " "<<CurrencyFrom.CurrencyCode() <<" = "<<AmountInCurrrencyTo << " "<<CurrencyTo.CurrencyCode() << endl;
        
    }
    public :
    
    static void ShowCurrencyCalclatorScreen(){
        
        char Continue = 'Y';
        
        while(toupper(Continue) == 'Y'){
            system("cl");
            _DrowScreenHeader("Currency Calclator Screen ");
        
            clsCurrency CurrencyFrom = _GetCurrency("Pleace Enter Currency Code From : ");
            clsCurrency CurrencyTo = _GetCurrency("Pleace Enter Currency Code  To : ");
            float Amount = _ReadAmount();
            
            
            _PrintCalculationsResults(Amount , CurrencyFrom,CurrencyTo);
            
            cout << "\n\nDo you want to perform another calculation? y/n ? ";
            cin >> Continue;
        }
        
        
        
        

        

        
    }
    
};