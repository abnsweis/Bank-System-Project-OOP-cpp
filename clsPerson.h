#pragma once
#include <iostream>
#include <string>
using namespace std;


class clsPerson{
  
  private :
  
    string _FirstName ; 
    string _LastName ; 
    string _Email;
    string _Phone;
  
  public :
  
    clsPerson(string FirstName ,string LastName,string Email,string Phone){
      _FirstName = FirstName;
      _LastName  = LastName;
      _Email = Email;
      _Phone = Phone;
    }
  
    // Set First Name
    void SetFirstName(string FirstName){
      _FirstName = FirstName;
    }
    // Get First Name
    string GetFirstName(){
      return _FirstName;
    }
    
    
    // Set Last Name
    void SetLastName(string LastName){
      _LastName = LastName;
    }
    // Get Last Name
    string GetLastName(){
      return _LastName;
    }
    
    // Set Email
    void SetEmail(string Email){
      _Email = Email;
    }
    // Get Email
    string Email(){
      return _Email;
    }
    
    // Set Phone
    void SetPhone(string Phone){
      _Phone = Phone;
    }
    
    // Get Phone
    string Phone(){
      return _Phone;
    }


    
    string FullName(){
      return _FirstName +" "+_LastName;
    }
};