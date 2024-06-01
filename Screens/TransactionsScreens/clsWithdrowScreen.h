#pragma once 

#include <iostream>
#include "../clsScreen.h"
#include "../../lib/clsInputValidation.h"
#include "../../clsBankClient.h"

using namespace std;


class clsWithdrowScreen : protected clsScreen {
  
  private  :
  
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
  
  
  static void ShowWithDrowScreen(){
    
    _DrowScreenHeader("Withdrow Screen");
    
    string AccountNumber = _ReadAccountNumber();
    
    while(!clsBankClient::IsClientExist(AccountNumber)){
      
      cout << "Client With Account Number ( "<<AccountNumber <<" ) is Not Found" << endl;
      AccountNumber = _ReadAccountNumber();
      
    }
    
    
    clsBankClient client = clsBankClient::Find(AccountNumber);
    _PrintInfo(client);
    
    float Amount ;
    cout << "\nPlease Enter Withdrow Amount : $";
    Amount = clsInputValidation::ReadFloatNumber("Please Enter A Float Or Double Number ");
    
    char Answer =  'n';
    cout << "Are you sure to complete this process?(Y/N) :" ;
    cin >> Answer;
    
    if(toupper(Answer) == 'Y'){
      
      if(client.Withdrow(Amount)){
        cout << "Seccussfully Withdrow $"<<Amount << endl;
        cout << "New Balance is $"<<client.AccountBalance() << endl;
      }else{
        cout << "\nCannot withdraw, Insuffecient Balancel " << endl;
        cout << "Amount to Withdrow is "<<Amount << endl;
        cout << "Your Balance is : $"<<client.AccountBalance() << endl;
      }
      
      _PrintInfo(client);
      
    }
  }
  
};