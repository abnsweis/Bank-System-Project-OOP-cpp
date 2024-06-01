#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "./clsPerson.h"
#include "./lib/clsString.h"
#include "./lib/clsDate.h"
#include "./Global.h"
using namespace std;



class clsBankClient: public clsPerson {



    private:
    enum enMode {
        enEmptyMode = 0,
        enUpdateMod = 1,
        enAddNewMod = 2
    };
    enMode _Mode;
    string _AccountNumber;
    string _PINCode;
    float _AccountBalance;
    bool _MarkForDelete = false;

    static clsBankClient _ConvertLienRecordToObject(string Record, string Seperator = "#//#") {

        vector < string > vClientsDate = clsString::split(Record, Seperator);



        return clsBankClient(enMode::enUpdateMod, vClientsDate[0], vClientsDate[1],
            vClientsDate[2], vClientsDate[3], vClientsDate[4], vClientsDate[5], stof(vClientsDate[6]));

    }
    static clsBankClient _GetEmptyClientObject() {
        return clsBankClient(enMode::enEmptyMode, "", "", "", "", "", "", 0);
    }
    static string _ConveetObjectToLineDate(clsBankClient client, string Seperator = "#//#") {

        string Record = "";


        Record += client.GetFirstName() + Seperator;
        Record += client.GetLastName() + Seperator;
        Record += client.Email() + Seperator;
        Record += client.Phone() + Seperator;
        Record += client.AccountNumber() + Seperator;
        Record += client.PINCode() + Seperator;
        Record += to_string(client.AccountBalance());


        return Record;


    }
    static vector < clsBankClient > _LoadDateFromFile() {

        vector < clsBankClient > _vClients;

        fstream File;

        File.open("ClientsFile.txt", ios::in);

        if(File.is_open()) {

            string line;

            while(getline(File, line)) {

                clsBankClient client = _ConvertLienRecordToObject(line, "#//#");
                _vClients.push_back(client);

            }
            File.close();
        }
        return _vClients;
    }

    void _SaveDateToFile(vector < clsBankClient > _vClients) {

        fstream File;

        File.open("ClientsFile.txt", ios::out);

        if(File.is_open()) {
            string line;
            for (clsBankClient &C: _vClients) {
                if(C.MarkForDelete() != true) {
                    line = _ConveetObjectToLineDate(C);
                    File << line <<endl;
                }
            }
            File.close();
        }

    }
    void _Update() {

        vector < clsBankClient > _vClients;
        _vClients = _LoadDateFromFile();


        for (clsBankClient &C: _vClients) {

            if(C.AccountNumber() == AccountNumber()) {

                C = *this;
                break;
            }

        }

        _SaveDateToFile(_vClients);

    }

    void _AddNewClient() {
        _AddDataLineToFile(_ConveetObjectToLineDate(*this));
    }

    void _AddDataLineToFile(string LineDate) {
        fstream File;

        File.open("ClientsFile.txt", ios::in | ios::app);

        if(File.is_open()) {

            File << LineDate <<endl;
        }
        File.close();
    }

    string _ConvertDataTransferToLine(float Amount, clsBankClient DestaintionClient, string UserName, string Seperator = "#//#") {


        string Line = "";

        Line += clsDate::DateTime() + Seperator;
        Line += AccountNumber() + Seperator;
        Line += DestaintionClient.AccountNumber() + Seperator;
        Line += to_string(Amount) + Seperator;
        Line += to_string((AccountBalance())) + Seperator;
        Line += to_string(DestaintionClient.AccountBalance())+Seperator;
        Line += UserName;

        return Line;
    }
    void _RegisterTransfer(float Amount, clsBankClient DestaintionClient, string UserName) {

        string LineDate = _ConvertDataTransferToLine(Amount, DestaintionClient, UserName);
        fstream File;

        File.open("TransfersLog.txt", ios::out | ios::app);

        if(File.is_open()) {

            File << LineDate <<endl;
            File.close();
        }

    }

    
    public:


    struct stTransferlog {
        string datetime;
        string s_account;
        string d_account;
        float Amount;
        float s_balance;
        float d_balance;
        string UserName;
    };

    static stTransferlog _ConvertLineTransferDataToStruct(string Line, string Seperator = "#//#") {
        vector < string > vData = clsString::split(Line, Seperator);

        stTransferlog TransferData;

        TransferData.datetime = vData[0];
        TransferData.s_account = vData[1];
        TransferData.d_account = vData[2];
        TransferData.Amount = stof(vData[3]);
        TransferData.s_balance = stof(vData[4]);
        TransferData.d_balance = stof(vData[5]);
        TransferData.UserName = vData[6];

        return TransferData;
    }

    clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PINCode, double AccountBalance): clsPerson(FirstName, LastName, Email, Phone) {

        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PINCode = PINCode;
        _AccountBalance = AccountBalance;
    }

    bool IsEmpty() {
        return (_Mode == enMode::enEmptyMode);
    }

    string AccountNumber() {
        return _AccountNumber;
    }

    void SetPINCode(string PINCode) {
        _PINCode = PINCode;
    }
    string PINCode () {
        return _PINCode;
    }



    void SetAccountBalance(double AccountBalance) {
        _AccountBalance = AccountBalance;
    }
    double AccountBalance() {
        return _AccountBalance;
    }

    void SetMarkForDelete(bool MarkForDelete) {
        _MarkForDelete = MarkForDelete;
    }

    bool MarkForDelete() {
        return _MarkForDelete;
    }


    static clsBankClient Find(string AccountNumber) {

        vector < clsBankClient > vClients;

        fstream File;

        File.open("./ClientsFile.txt", ios::in);

        if(File.is_open()) {


            string line;

            while(getline(File, line)) {

                clsBankClient client = _ConvertLienRecordToObject(line);

                if(client.AccountNumber() == AccountNumber) {
                    File.close();
                    return client;
                }

            }
            File.close();
        }

        return _GetEmptyClientObject();
    }
    static clsBankClient Find(string AccountNumber, string PINCode) {

        vector < clsBankClient > vClients;

        fstream File;

        File.open("./ClientsFile.txt", ios::in);

        if(File.is_open()) {


            string line;

            while(getline(File, line)) {

                clsBankClient client = _ConvertLienRecordToObject(line);

                if(client.AccountNumber() == AccountNumber && client.PINCode() == PINCode) {
                    File.close();
                    return client;
                }

            }
            File.close();
        }

        return _GetEmptyClientObject();
    }

    static bool IsClientExist(string AccountNumber) {
        clsBankClient client = Find(AccountNumber);
        return !(client.IsEmpty());
    }

    static clsBankClient GetAddNewClientObject(string AccountNumber) {
        return clsBankClient(enMode::enAddNewMod, "", "", "", "", AccountNumber, "", 0);
    };



    enum enSaveResults {
        svFaildEmptyObject = 0,
        svSuccesseFully = 1,
        svFaildAccountNumberExist = 2
    };

    enSaveResults Save() {
        switch(_Mode) {

            case enMode::enEmptyMode: {
                if(IsEmpty()) {
                    return enSaveResults::svFaildEmptyObject;
                }
            }
            case enMode::enUpdateMod: {
                _Update();
                return enSaveResults::svSuccesseFully;
            }
            case enMode::enAddNewMod: {


                if(clsBankClient::IsClientExist(_AccountNumber)) {
                    return enSaveResults::svFaildAccountNumberExist;
                }else {

                    _AddNewClient();
                    _Mode = enMode::enUpdateMod;
                    return enSaveResults::svSuccesseFully;
                }
                break;
            }

        }
    }

    bool Delete() {

        vector < clsBankClient > vClients;

        vClients = _LoadDateFromFile();

        for (clsBankClient &C: vClients) {

            if(C.AccountNumber() == _AccountNumber) {
                C.SetMarkForDelete(true);
                break;
            }

        }

        _SaveDateToFile(vClients);

        *this = _GetEmptyClientObject();
        return true;

    }

    static vector < clsBankClient > GetClientList() {

        return _LoadDateFromFile();

    };

    static double GetTotalBalances() {

        vector < clsBankClient > vClients = clsBankClient::GetClientList();
        double TotalBalances;

        for (clsBankClient &C: vClients) {

            TotalBalances += C.AccountBalance();

        }

        return TotalBalances;
    }

    void Deposit(float Amount) {
        SetAccountBalance(_AccountBalance += Amount);
        Save();
    }

    bool Withdrow(float Amount) {

        if(_AccountBalance < Amount) {
            return false;
        }
        else {
            SetAccountBalance(_AccountBalance - Amount);
            Save();
            return true;
        }
    }

    bool Transfer(float Amount, clsBankClient &DestaintionClient, string UserName) {

        if(_AccountBalance < Amount) {
            return false;
        }
        else {
            Withdrow(Amount);
            DestaintionClient.Deposit(Amount);
            _RegisterTransfer(Amount, DestaintionClient, UserName);
            return true;
        }

    }


    static vector < stTransferlog > GetListOfTransfers() {
        vector < stTransferlog > vTransfersLog;

        fstream File;

        File.open("./TransfersLog.txt", ios::in);
        if(File.is_open()) {

            string line;
            while(getline(File, line)) {

                stTransferlog TransferLog = _ConvertLineTransferDataToStruct(line, "#//#");
                vTransfersLog.push_back(TransferLog);
            }
            File.close();
        }
        return vTransfersLog;
    };

};