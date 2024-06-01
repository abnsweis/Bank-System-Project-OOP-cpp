#include <iostream>
#include "../clsBankClient.h"
#include "./clsScreen.h"
#include "../clsUser.h"
#include<iomanip>
using namespace std;

class clsClientsListScreen: protected clsScreen {

    private:
    static void PrintClientRecord(clsBankClient client) {

        cout <<"| "<<left<< setw(15) << client.AccountNumber();
        cout <<"| "<< setw(10) << client.PINCode();
        cout <<"| "<< setw(20) << client.FullName();
        cout <<"| "<< setw(15) << client.Phone();
        cout <<"| "<< setw(20) << client.Email();
        cout <<"| $"<< setw(10) << client.AccountBalance() << "|";
        cout << endl;

    }
    public:
    static void ShowClientList() {

        if(!CheckAccessRights(clsUser::enPermissions::eShowListClients)){
            return ;
        }
        vector < clsBankClient > vClients = clsBankClient::GetClientList();
        string Title = "Clients List Screen";
        string SubTitle = ""+to_string(vClients.size()) + " Clients";


        _DrowScreenHeader(Title, SubTitle);
        cout << "\n==============================================";
        cout << "========================================================" << endl;
        cout << "| " << left << setw(15) << "Accout Number";
        cout << "| " << left << setw(10) << "Pin Code";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(15) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Balance" << "|";
        cout << "\n==============================================";
        cout << "==========================================================" << endl;

        if(vClients.size() == 0) {
            cout << "\t\t\t\t No Clients Available In System" << endl;
        }else {
            for (clsBankClient &client: vClients) {
                PrintClientRecord(client);
            }

        }
        cout << "==============================================";
        cout << "========================================================" << endl;
    }
};