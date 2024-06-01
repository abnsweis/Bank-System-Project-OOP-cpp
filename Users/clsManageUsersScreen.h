#pragma once
#include <iostream>
#include "../Screens/clsScreen.h"
#include "../lib/clsInputValidation.h"

#include "./clsListUsersScreen.h"
#include "./clsAddNewUserScreen.h"
#include "./clsDeleteUserScreen.h"
#include "./clsUpdateUserScreen.h"
#include "./clsFindUserScreen.h"


class clsManageUsersScreen: protected clsScreen {

    private:
    enum enUserMenuOptions {
        eListUsers = 1,
        eAddUser = 2,
        eDeleteUser = 3,
        eUpdateUser = 4,
        eFindUser = 5,
        eMainMenue = 6
    };

    static short _ReadUsersManuOpation() {
        short Choose = 0;
        cout << "Choose What Do You want to Do? [1 to 6]:";
        Choose = clsInputValidation::ReadShortNumberBetween(1, 6, "Number is not within range (1 to 6)");

        return Choose;
    }
    static void _GobackToUsersManageMenu() {
        cout << "Press Enter To Go Users Manage Manu,...";
        cin.ignore().get();
        ShowManageUsersScreen();
    }


    static void _ShowListUsersScreen() {
        clsListUsersScreen::ShowListScreenHeader();
    }

    static void _ShowAddNewUserScreen() {
        clsAddNewUserScreen::ShowAddNewUserScreen();
    }
    static void _ShowDeleteUserScreen() {
        clsDeleteUserScreen::ShowDeleteUserScreen();
    }
    static void _ShowUpdateUserScreen() {
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }
    static void _ShowFindUserScreen() {
        clsFindUserScreen::ShowFindUserScreen();
    }

    static void _PerformManageUsersManuOpation(enUserMenuOptions Opation) {

        switch(Opation) {

            case enUserMenuOptions::eListUsers: {
                system("cl");
                _ShowListUsersScreen();
                _GobackToUsersManageMenu();
                break;
            }
            case enUserMenuOptions::eAddUser: {
                system("cl");
                _ShowAddNewUserScreen();
                _GobackToUsersManageMenu();
                break;
            }
            case enUserMenuOptions::eDeleteUser: {
                system("cl");
                _ShowDeleteUserScreen();
                _GobackToUsersManageMenu();
                break;
            }
            case enUserMenuOptions::eUpdateUser: {
                system("cl");
                _ShowUpdateUserScreen();
                _GobackToUsersManageMenu();
                break;
            }
            case enUserMenuOptions::eFindUser: {
                system("cl");
                _ShowFindUserScreen();
                _GobackToUsersManageMenu();
                break;
            }
            case enUserMenuOptions::eMainMenue: {
                //  ==================
            }

        }

    }
    public:

    static void ShowManageUsersScreen() {
        if(!CheckAccessRights(clsUser::enPermissions::eManageUsers)){
            return ;
        }
        _DrowScreenHeader("Manage Users Manu  Screen");

        cout << "\t[1] List Users" << endl;
        cout << "\t[2] Add New User" << endl;
        cout << "\t[3] Delete User" << endl;
        cout << "\t[4] Update User" << endl;
        cout << "\t[5] Find User" << endl;
        cout << "\t[6] Main Menue" << endl;


        _PerformManageUsersManuOpation((enUserMenuOptions)_ReadUsersManuOpation());







        //Choose What Do You want to Do? [1 to 6]:
    }



};