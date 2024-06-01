#pragma once
#include <iostream>
#include "../clsScreen.h"
#include "../../lib/clsUtil.h"
#include "../../clsBankClient.h"

using namespace std;



class clsTotalBalanceScreen : protected clsScreen {
  
  private :
  
  static void _PrintClientBalance(clsBankClient  client){
	
	cout <<"| "<<left<< setw(15)  << client.AccountNumber() ;
	cout <<"| "<< setw(20)  << client.FullName() ;
	cout <<"| $"<< setw(10)  << client.AccountBalance() << "|";
	cout  << endl;
}

  
  public :
  
  
  
  static void ShowTotalBalancesScreen(){
  
  vector<clsBankClient> vClients = clsBankClient::GetClientList() ;
  string Title = "Total Balances Screen ";
  
  string Subtitle = "Balances  (" +to_string( vClients.size())+") Clients";
  _DrowScreenHeader(Title,Subtitle);
  
	cout << "\n====================================================="<<endl; 
	cout << "| " << left << setw(15) << "Accout Number";   
	cout << "| " << left << setw(20) << "Client Name";     
	cout << "| " << left << setw(10) << "Balance" << " |";     
	cout << "\n====================================================="<<endl;     

	float TotalBalances = clsBankClient::GetTotalBalances();
	for (clsBankClient  &C : vClients) {
		_PrintClientBalance(C);
	}
	cout << "====================================================="<<endl;
	cout << "\t\tTotal Balances is :"<< TotalBalances  << endl;
	cout << "\t  ( "<< clsUtil::NumberToText(TotalBalances)  <<" )"<< endl;
}

  
};