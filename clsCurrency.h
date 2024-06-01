#pragma once
#include <iostream>
#include <fstream>
#include <vector>

#include "./lib/clsString.h"
class clsCurrency {
    
    
    
    private :
    
    enum eMode {EmptyMode = 0,UpdateMode=1};
    string _Country;
    string _CurrencyCode;
    string _CurrencyName ;
    float _Rate;
    
    eMode _Mode;
    
    
    // Convert Line To Currency Object
    static clsCurrency _ConvertLineToCurrencyObject(string Line,string Separator = "#//#"){
        
        vector<string> vDate = clsString::split(Line,Separator);
        
        return clsCurrency(eMode::UpdateMode,vDate[0],vDate[1],vDate[2],stof(vDate[3]));
    }
    
    // Get Empty Object
    static clsCurrency _GetEmptyCurrencyObject(){
        return clsCurrency(eMode::EmptyMode,"","","",0);
    }
    static vector<clsCurrency>   _LoadCurrencysFromFile(){
        vector <clsCurrency> vCurrencys;
        
        fstream File ;
        
        File.open("./currency.txt",ios::in);//Read Mode ;
        
        if(File.is_open()){
            
            string line = "";
            while(getline(File,line)){
                
                clsCurrency Currency = _ConvertLineToCurrencyObject(line);
                
                vCurrencys.push_back(Currency);
                
            }
            
            File.close();
        }
        return vCurrencys;
    }
    
    string _ConvertCurrencyObjectToLine(clsCurrency Currency,string Separator ="#//#"){
        
        string Line = "";
        
        Line += Currency.Country() + Separator;
        Line += Currency.CurrencyCode() + Separator;
        Line += Currency.CurrencyName() + Separator;
        Line += to_string(Currency.Rate()) ;
        
        return Line;
    }
    void _SaveCurrencysToFile(vector<clsCurrency> vCurrencys){
        fstream File;
        
        File.open("./currency.txt",ios::out);
        if(File.is_open()){
            
            string line = "";
            for (clsCurrency &C : vCurrencys) {
                line = _ConvertCurrencyObjectToLine(C);
                File << line << endl;
            }
            File.close();
        }
    }
    
    void _Update(){
        
        vector <clsCurrency> _vCurrencys = _LoadCurrencysFromFile();
        
        
        for (clsCurrency  &C : _vCurrencys) {
            if(C.CurrencyCode() == _CurrencyCode){
                C = *this;
                break;
            }
        }
        _SaveCurrencysToFile(_vCurrencys);
    }
    
    public :
    
    clsCurrency(eMode Mode ,string Country,string CurrencyCode,string CurrencyName,float Rate){
        
        
        _Mode = Mode ;
        _Country = Country;
        _CurrencyCode = CurrencyCode;
        _CurrencyName = CurrencyName;
        _Rate = Rate;
        
    }
    
    bool IsEmpty(){
        return (_Mode == eMode::EmptyMode);
    }
    
    string Country(){
        return _Country;
    }
    
    string CurrencyCode(){
        
        return _CurrencyCode;
    }
    
    string CurrencyName(){
        return _CurrencyName;
    }
    
    void UpdateRate(float UpdateRate){
        _Rate = UpdateRate;
        _Update();
    }
    
    float Rate(){
        return _Rate;
    }
    static clsCurrency FindByCode(string CurrencyCode){
      
      CurrencyCode = clsString::StringToUppercase(CurrencyCode);
      
      fstream File ;
      
      File.open("./currency.txt",ios::in);// Read Mode 
      
      if(File.is_open()){
         
          string line = "";
          
          while(getline(File,line)){
              
              clsCurrency Currency = _ConvertLineToCurrencyObject(line);
              if(Currency.CurrencyCode() == CurrencyCode){
                  
                  File.close();
                  return Currency;
              }
              
          }
          
      }
      
      
      return _GetEmptyCurrencyObject();
  }   
    
    static clsCurrency FindByCountry(string Country){
      
      Country = clsString::StringToUppercase(Country);
      
      fstream File ;
      
      File.open("./currency.txt",ios::in);// Read Mode 
      
      if(File.is_open()){
          
          string line = "";
          
          while(getline(File,line)){
              
              clsCurrency Currency = _ConvertLineToCurrencyObject(line);
              if(clsString::StringToUppercase(Currency.Country()) == Country){
                  
                  
                  File.close();
                  return Currency;
              }
              
          }
          
      }
      
      
      return _GetEmptyCurrencyObject();
  }   
  
  
    static bool IsCurrencyExist(string CurrencyCode){
        clsCurrency Currency = FindByCode(CurrencyCode);
        return (!Currency.IsEmpty());
    }
    
    static vector<clsCurrency> GetCurrencysList(){
        return _LoadCurrencysFromFile();
    }
    
    
    float ConvertToUSD(float Amount){
        
        return (float)Amount / Rate(); 
        
    };
    
    float ConvertToOtherCurrency(float Amount,clsCurrency Currency){
        float AmountInUSD = ConvertToUSD(Amount);
        if(Currency.CurrencyCode() == "USD"){
            return AmountInUSD;
        }
        return (float) AmountInUSD * Currency.Rate();
    }
    
    
};
