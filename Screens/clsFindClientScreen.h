#pragma once
#include <iostream>
#include "./clsScreen.h"
#include "../clsBankClient.h"
#include "../lib/clsInputValidation.h"
using namespace std;



class clsFindClientScreen: protected clsScreen {


    private:
    static void _PrintInfo(clsBankClient client) {
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

    public:


    static void ShowFindClientScreen() {

        if(!CheckAccessRights(clsUser::enPermissions::eFindClients)){
            return ;
        }

        _DrowScreenHeader("Find Client Screen");
        cout << "Please Enter Account Number :";
        string AccountNumber = clsInputValidation::ReadString();

        while(!clsBankClient::IsClientExist(AccountNumber)) {

            cout << "Account Number Not Exist Choose Another one :-( :" << endl;
            cout << "Please Enter Account Number :";
            string AccountNumber = clsInputValidation::ReadString();

        }

        clsBankClient client = clsBankClient::Find(AccountNumber);

        if(!client.IsEmpty()) {
            cout << "Client Found SuccessFully :-)" << endl;
        }else {
            cout << "Client Not Found :-(" << endl;
        }
        _PrintInfo(client);

    }

};