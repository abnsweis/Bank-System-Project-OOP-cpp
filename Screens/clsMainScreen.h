#pragma once
#include <iostream>
#include <iomanip>
#include "../lib/clsInputValidation.h"
#include "./clsScreen.h"
#include "../clsUser.h"
#include "./clsClientsListScreen.h"
#include "./clsAddNewClientScreen.h"
#include "./clsDeleteClientScreen.h"
#include "./clsUpdateClientScreen.h"
#include "./clsFindClientScreen.h"
#include "./clsTransactionsScreen.h"
#include "../Users/clsManageUsersScreen.h"
#include "./clsLoginsHistory.h"
#include "CurrencyExchange/clsCurrencyExchangeMainScreen.h"
#include "../Global.h"
using namespace std;



class clsMainScreen : protected clsScreen{
  
  
  private :
  enum enMainMenuOptions {
	  eShowAllClients=1,
	  eAddNewClients=2,
	  eDeleteClients=3,
	  eUpdateClient=4,
	  eTransactions=5,
	  eFindClient=6,
	  eManageUsers=7,
	  eLoginsHistory=8,
	  eCurrencyExchange=9,
	  eLogout=10
  };
  static short _ReadMainMenueOpation(){
    short Choice;
    cout  <<"Choose what do you want to do? [1 to 10] ?" ;
    Choice = clsInputValidation::ReadShortNumberBetween(1,10,"Number is not within range (1 to 10)");
    
    return Choice;
  }
  static void _GoBackToMainMenu(){
    cout << "Press Enter to go back to main menu...." ;
	  cin.ignore().get();
	  clsMainScreen::ShowMainMenuScreen();
  }
  
  static void _ShowAllClientsScreen(){
    clsClientsListScreen::ShowClientList();
  }
  static void _ShowAddNewClientsScreen(){
    clsAddNewClientScreen::ShowAddNewClientScreen();
  }
  static void _ShowDeleteClientsScreen(){
    
    clsDeleteClientScreen::ShowDeleteClientScreen();
    
  }
  static void _ShowUpDateClientScreen(){
      clsUpdateClientScreen::ShowUpdateClientScreen();
  }
  static void _ShowTransacionsMainMenueScreen(){
    
    clsTransactionsScreen::showTransactionsMemu();
  }
  static void _ShowFindClientScreen(){
    clsFindClientScreen::ShowFindClientScreen();
  }
  static void _ManageUsersScreen(){
    clsManageUsersScreen::ShowManageUsersScreen();
  }
  static void _LoginHistory(){
      clsLoginsHistoryScreen::ShowLoginsHistoryScreen();
  }
  static void _CurrencyExchange(){
      clsCurrencyExchangeScreen::ShowCurrenciesMainMenu();
  }
  static void _Logout(){
      CurrentUser = clsUser::Find("","");
  }
   
  static void _PerfromMainMenueOption(enMainMenuOptions opation){
    
    switch(opation){
		
		case enMainMenuOptions::eShowAllClients:
			system("cl");
			_ShowAllClientsScreen();
			_GoBackToMainMenu();
			break;
		
		case enMainMenuOptions::eAddNewClients:
			system("cl");
			_ShowAddNewClientsScreen();
			_GoBackToMainMenu();
			break;
			
		case enMainMenuOptions::eDeleteClients:
			system("cl");
			_ShowDeleteClientsScreen();
			_GoBackToMainMenu();
			break;
			
		case enMainMenuOptions::eUpdateClient:
			system("cl");
			_ShowUpDateClientScreen();
			_GoBackToMainMenu();
			break;
				
		case enMainMenuOptions::eTransactions:
			system("cl");
			_ShowTransacionsMainMenueScreen();
			_GoBackToMainMenu();
			break;
			
		case enMainMenuOptions::eFindClient:
			system("cl");
			_ShowFindClientScreen();
			_GoBackToMainMenu();
			break;
			
		case enMainMenuOptions::eManageUsers:
			system("cl");
			_ManageUsersScreen();
			_GoBackToMainMenu();
			break;
		case enMainMenuOptions::eLoginsHistory:
		    system("cl");
			_LoginHistory();
			_GoBackToMainMenu();
			break;
		case enMainMenuOptions::eCurrencyExchange:
		    system("cl");
			_CurrencyExchange();
			_GoBackToMainMenu();
			break;
			
		case enMainMenuOptions::eLogout:
			_Logout();
			break;
			
	}
    
  }
  
  
  public :
  
  static void ShowMainMenuScreen(){
    _DrowScreenHeader("Main Menu Screen ");
    
    cout<<  "  [1] Show Client List." << endl;
    cout<< "  [2] Add  Client." << endl;
    cout<< "  [3] Delete Client." << endl;
    cout<< "  [4] Update Client Info." << endl;
    cout<< "  [5] Transacions." << endl;
    cout<< "  [6] Find Client." << endl;
    cout<< "  [7] Manage Users." << endl;
    cout<< "  [8] Login History." << endl;
    cout<< "  [9] Currency Exchange" << endl;
    cout<< "  [10] Logout\n" << endl;
    
    _PerfromMainMenueOption((enMainMenuOptions)_ReadMainMenueOpation());
    
  }
};