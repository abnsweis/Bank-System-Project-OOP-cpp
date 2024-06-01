#pragma once

#include <iostream>
#include "../../lib/clsString.h"
#include "../../lib/clsInputValidation.h"

#include "./clsCurrenciesListScreen.h"
#include "./clsFindCurrencyScreen.h"
#include "./clsUpdateCurrencyRateScreen.h"
#include "./clsCurrencyCalculatorScreen.h"


class clsCurrencyExchangeScreen : protected clsScreen{
    
    private :
    
    enum enCurrencyMenuOpations {eListCurrencies=1,eFindCurrency=2,eUpdateCurrency=3,eCurrencyCalculator=4,eMainMenu=5};
    static void _GoBackToCurrencyExchangeMainMenu(){
        cout << "Press Enter to go back to main menu...." ;
        cin.ignore().get();
        clsCurrencyExchangeScreen::ShowCurrenciesMainMenu();
    }
    static short _ReadCurrencyMenuOpation(){
        short Choice;
        cout  <<"Choose what do you want to do? [1 to 5] ?" ;
        Choice = clsInputValidation::ReadShortNumberBetween(1,5,"Number is not within range (1 to 5)");
    
    return Choice;
    }
    
    static void _ShowListCurrencies(){
        clsCurrenciesListScreen::ShowCurrenciesList();
    }
    static void _ShowFindCurrency(){
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }
    static void _ShowUpdateCurrency(){
        
        clsUpdateCurrencyRateScreen::ShowUpdateRateScreen();
        
    }
    static void _ShowCurrencyCalculator(){
        clsCurrencyCalculatorScreen::ShowCurrencyCalclatorScreen();
    }
    
    static void _PerformCurrencyMenuOption(enCurrencyMenuOpations CurrenciesMenuOpation){
        
        switch(CurrenciesMenuOpation){
          
            case enCurrencyMenuOpations::eListCurrencies:{
                system("cl");
                _ShowListCurrencies();
                _GoBackToCurrencyExchangeMainMenu();
                break;
            }
          
            case enCurrencyMenuOpations::eFindCurrency:{
                system("cl");
                _ShowFindCurrency();
                _GoBackToCurrencyExchangeMainMenu();
                break;
            }
            case enCurrencyMenuOpations::eUpdateCurrency:{
                system("cl");
                _ShowUpdateCurrency();
                _GoBackToCurrencyExchangeMainMenu();
                break;
            }
            case enCurrencyMenuOpations::eCurrencyCalculator:{
                system("cl");
                _ShowCurrencyCalculator();
                _GoBackToCurrencyExchangeMainMenu();
                break;
            }
            case enCurrencyMenuOpations::eMainMenu:{}
            
        };
    }
    public :
    static void ShowCurrenciesMainMenu(){
        _DrowScreenHeader("Currency Exchange Menu");
        
        cout<< "  [1] List Currencies ." << endl;
        cout<< "  [2] Find Currency." << endl;
        cout<< "  [3] Update Currency ." << endl;
        cout<< "  [4] Currency Calculator ." << endl;
        cout<< "  [5] Main Menu." << endl;
        
        _PerformCurrencyMenuOption((enCurrencyMenuOpations)_ReadCurrencyMenuOpation());   
    }
};