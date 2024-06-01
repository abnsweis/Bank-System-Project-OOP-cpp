#pragma once
#include <iostream>
#include "./clsScreen.h"
#include "../lib/clsInputValidation.h"
#include "../clsBankClient.h"
#include "./clsMainScreen.h"


#include "./TransactionsScreens/clsDepositScreen.h"
#include "./TransactionsScreens/clsWithdrowScreen.h"
#include "./TransactionsScreens/clsTotalBalancesScreen.h"
#include "./TransactionsScreens/clsTransferScreen.h"
#include "./TransactionsScreens/clsTransfersLogScreen.h"
using namespace std;


class clsTransactionsScreen: protected clsScreen {

    private:
    enum enTransacionsOpations {
        eDeposit = 1,
        eWithdrow = 2,
        eTotalBalanses = 3,
        eTransfer = 4,
        eTransfersLog = 5,
        eMainMenueScreen = 6
    };

    static void _GoBackToTransactionsMenu() {
        cout << "Press Enter to go back to main menu....";
        cin.ignore().get();
        clsTransactionsScreen::showTransactionsMemu();
    }
    static short _ReadTransactionsOpation() {
        short Choose;
        cout << "Choose What Do You want to Do? [1 to 6]:";
        Choose = clsInputValidation::ReadShortNumberBetween(1, 6, "Number is not within range (1 to 6)");
        return Choose;
    }
    static void _ShowDepositScreen() {
        clsDepositScreen::ShowDepositScreen();
    }
    static void _ShowWithdrowScreen() {
        clsWithdrowScreen::ShowWithDrowScreen();
    }
    static void _ShowTotalBalancecreen() {
        clsTotalBalanceScreen::ShowTotalBalancesScreen();
    }
    static void _ShowTransferScreen() {
        clsTransferScreen::ShowTransferScreen();
    }
    static void _ShowTransfersLogScreen() {
        clsTransfersLogScreen::ShowTransfersScreen();
    }
    
    static void _PerformTransactionsOpation(enTransacionsOpations Opation) {

        switch(Opation) {

            case enTransacionsOpations::eDeposit: {
                system("cl");
                _ShowDepositScreen();
                _GoBackToTransactionsMenu();
                break;
            }
            case enTransacionsOpations::eWithdrow: {
                system("cl");
                _ShowWithdrowScreen();
                _GoBackToTransactionsMenu();
                break;
            }
            case enTransacionsOpations::eTotalBalanses: {
                system("cl");
                _ShowTotalBalancecreen();
                _GoBackToTransactionsMenu();
                break;
            }
            case enTransacionsOpations::eTransfer: {
                system("cl");
                _ShowTransferScreen();
                _GoBackToTransactionsMenu();
                break;
            }
            
            case enTransacionsOpations::eTransfersLog: {
                system("cl");
                _ShowTransfersLogScreen();
                _GoBackToTransactionsMenu();
                break;
            }
            
            case enTransacionsOpations::eMainMenueScreen: {}
        }

    }

    public:


    static void showTransactionsMemu() {
        if(!CheckAccessRights(clsUser::enPermissions::eTransacions)){
            return ;
        }
        _DrowScreenHeader("Transactions Screen ");

        cout << "[1] Deposit." << endl;
        cout << "[2] Withdrow." << endl;
        cout << "[3] Total Balanses." << endl;
        cout << "[4] Transfer." << endl;
        cout << "[5] Transfers Log." << endl;
        cout << "[6] Main Menue." << endl;


        _PerformTransactionsOpation((enTransacionsOpations)_ReadTransactionsOpation());

    }
};