#pragma once
#include <iostream>
#include "./clsScreen.h"
#include "../lib/clsInputValidation.h"

using namespace std;


class clsDeleteClientScreen: protected clsScreen {


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
    static void ShowDeleteClientScreen() {
        
        if(!CheckAccessRights(clsUser::enPermissions::eDeleteClients)){
            return ;
        }
        
        _DrowScreenHeader("Delete Client Screen ");
        string AccountNumber = "";
        cout << "\nPlease Enter Account Number : ";
        AccountNumber = clsInputValidation::ReadString();

        while(!clsBankClient::IsClientExist(AccountNumber)) {

            cout << "Account Number Doe's Not Exist :-(  Enter another one" << endl;
            cout << "Please Enter Account Number : ";
            AccountNumber = clsInputValidation::ReadString();
        }

        clsBankClient client = clsBankClient::Find(AccountNumber);
        _PrintInfo(client);

        char Answer = 'Y';
        cout << "\nAre you sure you want to delete this client? (Y/N)";
        cin >> Answer;

        if(toupper(Answer) == 'Y') {

            if(client.Delete()) {
                _PrintInfo(client);
                cout << "SuccessFully Deleded Client ( "<<AccountNumber<<" )" << endl;

            }

        }

    }


};