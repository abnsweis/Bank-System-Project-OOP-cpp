#pragma once

#include <iostream>
#include "../clsScreen.h"
#include "../../lib/clsInputValidation.h"
#include "../../clsBankClient.h"



class clsDepositScreen : protected clsScreen {
  
  
  private :
  
  static void _PrintInfo(clsBankClient client){
    cout << "\n===========================" << endl;
      cout << "Account Number : "<<client.AccountNumber() << endl;
      cout << "First Name : "<<client.GetFirstName() << endl;
      cout << "Last Name  : "<<client.GetLastName() << endl;
      cout << "Email      : "<<client.Email() << endl;
      cout << "Phone      : "<<client.Phone() << endl;
      cout << "PIN Code   : "<<client.PINCode() << endl;
      cout << "Balance    : $"<<client.AccountBalance() << endl;
    cout << "===========================" << endl;
  }
  static string _ReadAccountNumber(){
    cout << "Please Enter Account Number :";
    string AccountNumber = clsInputValidation::ReadString();
    return AccountNumber;
  }
  
  public :
  
  static void ShowDepositScreen(){
    
    
    _DrowScreenHeader("Deposit Screen ");
    
    string AccountNumber = _ReadAccountNumber();
    
    while(!clsBankClient::IsClientExist(AccountNumber)){
      
      cout << "Client With Account Number ( "<< AccountNumber<<" )is Not Found :-(" << endl;
      AccountNumber = _ReadAccountNumber(); 
    }
    
    clsBankClient client = clsBankClient::Find(AccountNumber);
    _PrintInfo(client);
    
    float Amount ;
    cout << "\nPlease Enter Deposit Amount : $";
    Amount = clsInputValidation::ReadFloatNumber("Please Enter A Float Or Double Number ");
    
    char Answer ;
    cout << "Are you sure to complete this process?(Y/N)" ;
    cin >>  Answer;
    if(toupper(Answer) == 'Y'){
      client.Deposit(Amount);
      cout << "SuccessFuly Deposit $"<< Amount << endl;
      cout << "New Balance is $"<<client.AccountBalance() << endl;
      _PrintInfo(client);
    }else{
      
      cout << "Deposit Process canceled" << endl;
      
    }
    
    
    
  }
  
};