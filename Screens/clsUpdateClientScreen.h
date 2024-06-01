#pragma once
#include <iostream>
#include "./clsScreen.h"
#include "../clsBankClient.h"

using namespace std;




class clsUpdateClientScreen: protected clsScreen {


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
    static void _ReadClientInfo(clsBankClient& client) {

        cout << "\nPlease Enter First Name :";
        client.SetFirstName(clsInputValidation::ReadString());

        cout << "\nPlease Enter Last Name :";
        client.SetLastName(clsInputValidation::ReadString());

        cout << "\nPlease Enter Email :";
        client.SetEmail(clsInputValidation::ReadString());

        cout << "\nPlease Enter Phone :";
        client.SetPhone(clsInputValidation::ReadString());

        cout << "\nPlease Enter PIN Code :";
        client.SetPINCode(clsInputValidation::ReadString());
        cout << "\nPlease Enter Account Balance  :";
        client.SetAccountBalance(clsInputValidation::ReadFloatNumber("Invaild Number , Please Enter Float Number : "));


    }


    public:

    static void ShowUpdateClientScreen() {
        
        if(!CheckAccessRights(clsUser::enPermissions::eUpdateClients)){
            return ;
        }
        
        
        _DrowScreenHeader("Update Client Screen ");
        cout << "Please Enter Account Number : ";
        string AccountNumber = clsInputValidation::ReadString();

        while(!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "\nAccount number is not found, choose another one: " << endl;
            cout << "\nPlease Enter Account Number : ";
            AccountNumber = clsInputValidation::ReadString();
        }

        clsBankClient client = clsBankClient::Find(AccountNumber);
        _PrintInfo(client);
        char Answer = 'Y';
        cout << "\nAre you sure you want to Update this client? (Y/N)";
        cin >> Answer;

        if(toupper(Answer) == 'Y') {
            cout << "\n\nUpdate Client Info :" << endl;
            cout << "--------------------------" << endl;

            _ReadClientInfo(client);
            _PrintInfo(client);


            clsBankClient::enSaveResults SaveResults;

            SaveResults = client.Save();

            switch(SaveResults) {
                case clsBankClient::svSuccesseFully:
                cout << "\nAccount Updated Successfully :-)\n" << endl;
                break;
                case clsBankClient::svFaildEmptyObject:
                cout << "\nError account was not saved because it's Empty :-(\n" << endl;
                break;
                case clsBankClient::svFaildAccountNumberExist:
                cout << "\nError account was not saved because it's Empty :-(\n" << endl;
                break;
            }
        }
    }

};