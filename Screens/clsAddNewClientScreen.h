#pragma once
#include <iostream>
#include "./clsScreen.h"
#include "../clsBankClient.h"
#include "../lib/clsInputValidation.h"


using namespace std;

class clsAddNewClientScreen: protected clsScreen {



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

    static void ShowAddNewClientScreen() {
        if(!CheckAccessRights(clsUser::enPermissions::eAddClients)){
            return ;
        }
        _DrowScreenHeader("Add New Client Screen ");
        string AccountNumber = "";

        cout << "Please Enter Account Number :";
        AccountNumber = clsInputValidation::ReadString();

        while(clsBankClient::IsClientExist(AccountNumber)) {
            cout << "Account Number \""<<AccountNumber<<"\" Is Already Used, Choose another one : ";
            AccountNumber = clsInputValidation::ReadString();
        }


        clsBankClient Newclient = clsBankClient::GetAddNewClientObject(AccountNumber);

        cout << "\nRead New client Informations" << endl;
        cout << "----------------------------" << endl;

        _ReadClientInfo(Newclient);


        clsBankClient::enSaveResults SaveResults;
        SaveResults = Newclient.Save();

        switch(SaveResults) {

            case clsBankClient::enSaveResults::svSuccesseFully:
            _PrintInfo(Newclient);
            cout << "SuccessFully Added New Client :-)" << endl;
            break;


            case clsBankClient::enSaveResults::svFaildEmptyObject:
            cout << "\nError account was not saved because it's Empty :-(" << endl;
            break;


            case clsBankClient::enSaveResults::svFaildAccountNumberExist:
            cout << "\nError account was not saved because account number is used :-(" << endl;
            break;
        }
    }

};