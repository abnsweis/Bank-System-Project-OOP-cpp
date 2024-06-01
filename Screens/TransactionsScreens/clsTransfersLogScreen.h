#pragma once 

#include <iostream>
#include "../clsScreen.h"
#include "../../clsBankClient.h"



class clsTransfersLogScreen : protected clsScreen{
    
    
    
    private :
    
    static void PrintTransferRecord(clsBankClient::stTransferlog transfer) {
        cout <<"| "<<left<< setw(20) << transfer.datetime;
        cout <<"| "<< setw(10) << transfer.s_account;
        cout <<"| "<< setw(10) << transfer.d_account;
        cout <<"| $"<< setw(10) << transfer.Amount;
        cout <<"| $"<< setw(12) << transfer.s_balance;
        cout <<"| $"<< setw(12) << transfer.d_balance;
        cout <<"| "<< setw(10) << transfer.UserName << "|";
        
        cout << endl;

    }
    
    public :
    
    
    static void ShowTransfersScreen(){
        
        vector<clsBankClient::stTransferlog> vTransfers = clsBankClient::GetListOfTransfers();
        
        _DrowScreenHeader("Transfers History ");
        
        cout << "\n==============================================";
        cout << "========================================================" << endl;
        cout << "| " << left << setw(20) << "Date / Time ";
        cout << "| " << left << setw(10) << "s.Accnt";
        cout << "| " << left << setw(10) << "d.Accnt";
        cout << "| " << left << setw(11) << "Amount";
        cout << "| " << left << setw(13) << "s.Balance";
        cout << "| " << left << setw(13) << "d.Balance";
        cout << "| " << left << setw(10) << "UserName |" ;
        
        
        cout << "\n==============================================";
        cout << "========================================================" << endl;
        if(vTransfers.size() != 0)
        for (clsBankClient::stTransferlog &transfer : vTransfers) {
            PrintTransferRecord(transfer);
        }
        else{
            cout << "\t\t No transfers Available In System" << endl;
        }
        cout << "==============================================";
        cout << "======================================================" << endl;
        
        
    }
    
    
};

