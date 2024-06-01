#pragma once 
#include <iostream>
#include "../clsScreen.h"
#include "../../clsBankClient.h"

using namespace std;

class clsTransferScreen : protected clsScreen{
    
    
    private :
    static void _PrintClientCard(clsBankClient client){
        cout << "\n=============================" << endl;
        cout << "\tClient Card " << endl;
        cout << "=============================" << endl;
        cout <<"Full Name     : "<< client.FullName() << endl;
        cout <<"Account Number: "<< client.AccountNumber() << endl;
        cout <<"Balance       : $"<< client.AccountBalance() << endl;
        cout <<"=============================\n" << endl;
    }
    
    static string _ReadAccountNumber(string FormOrTo = ""){
        cout << "Please Enter Account Number "<<FormOrTo<< ":";
        string AccountNumber = clsInputValidation::ReadString();
    
        return AccountNumber;
   }
    
    static clsBankClient _ReadTransferAccount(string  FormOrTo){
        string AccountNumber = _ReadAccountNumber(FormOrTo);
        while(!clsBankClient::IsClientExist(AccountNumber)){
            cout << "Client With Account Number ( "<<AccountNumber<<" ) is Not Found :-("<< endl;
            AccountNumber = _ReadAccountNumber(FormOrTo);
        }
        return clsBankClient::Find(AccountNumber);
    }
    
    public :
    
    static void ShowTransferScreen(){
        _DrowScreenHeader("Transfer Screen ");
        clsBankClient SourceClient = _ReadTransferAccount("From");
        _PrintClientCard(SourceClient);
        
        clsBankClient DestaintionClient = _ReadTransferAccount("To");
        _PrintClientCard(DestaintionClient);
        
        double Amount ;
        char Answer =  'n';
        
        cout << "Please Enter Amount To Tranafer : $" ;
        cin >> Amount;
        
        cout << "Are you sure to complete this process?(Y/N) :" ;
        cin >> Answer;
        if(toupper(Answer) == 'Y'){
            if(SourceClient.Transfer(Amount,DestaintionClient,CurrentUser.Username())){
                
                // system("cl");
                cout << "SuccessFully Transfer :-)" << endl;
                _PrintClientCard(SourceClient);
                cout  << endl;
                _PrintClientCard(DestaintionClient);
                
            }else{
                
                cout << "\nCannot withdraw :-(, ( "<<SourceClient.AccountNumber()<<" ) Insuffecient Balancel  " << endl;
                cout << "Amount to Withdrow is "<<Amount << endl;
                cout << "Your Balance is : $"<<SourceClient.AccountBalance() << endl;
                
            }
        }
    }
    
};