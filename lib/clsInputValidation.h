#pragma once
#include <iostream>
#include <string>
#include "./clsDate.h"

class clsInputValidation{
  
  public :
  
  // Is Number Between  int  
  static bool IsNumberBetWeen(int Number,int From,int To){
      return (Number >= From && Number <= To );
    }
  // Is Number Between  double  
  static bool IsNumberBetWeen(double Number,double From,double To){
        return (Number > From && Number < To );
    }

  // Is Number Between  float
  static bool IsNumberBetWeen(float Number,float From,float To){
    return (Number > From && Number < To );
    }
  
    // Is Date Between
  static bool IsDateBetWeen(clsDate Date,clsDate DateBetween1,clsDate DateBetween2){
    
    
    if(clsDate::IsDate1BeforeDate2(DateBetween2,DateBetween1)){
      clsDate::SwapDates(DateBetween1,DateBetween2);
    }
    
    return clsDate::IsDate1AfterDate2(Date,DateBetween1)&&clsDate::IsDate1BeforeDate2(Date,DateBetween2);
    
  }
  
  
  // Read Short Number 
  static short ReadShortNumber(string ErrorMessage="Number is not within range, Enter again :"){
    
    short number;
    
    while(!(cin >> number)){
      cin.clear();
      cin.ignore(std::numeric_limits<short>::max(),'\n');
      cout << ErrorMessage  ;
      
    }
    
    return number;
  }
  // Read Int Number 
  static int ReadIntNumber(string ErrorMessage){
    
    int number;
    
    while(!(cin >> number)){
      cin.clear();
      cin.ignore(std::numeric_limits<int>::max(),'\n');
      cout << ErrorMessage  ;
      
    }
    
    return number;
  }  
  
  // Read Float Number 
  static float ReadFloatNumber(string ErrorMessage){
    bool IsValidNumber = false;
    float number;
    
    while(!(cin >> number)){
      cin.clear();
      cin.ignore(std::numeric_limits<float>::max(),'\n');
      cout << ErrorMessage  ;
      
    }
    
    return number;
  }
  
  // Read Short Number Between  
  static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		int Number = ReadShortNumber();

		while (!IsNumberBetWeen(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadShortNumber();
		}
		return Number;
	}
    // Read Int Number Between  
  static int ReadIntNumberBetween(int From , int To,string ErrorMessage){
    
    int Number ;
    
    Number = ReadIntNumber("Error , Please Enter Number : ");
    
    
    while(IsNumberBetWeen(Number,From,To)){
      cout << ErrorMessage ;
      Number = ReadIntNumber("Error , Please Enter Number : ");
      
    }
  
    return Number;
  }
  
    // Read Double Number 
  static double ReadDbNumber(string ErrorMessage){
    
    double Number ;
    
    
    while(!(cin >> Number)){
      
      cin.clear();
      cin.ignore(std::numeric_limits<double>::max(),'\n');
      
      cout << ErrorMessage ; 
    }
    return Number;
  }
  
  
  // Read Double Number  Between
  static double ReadDbNumberBetween(double From , double To,string ErrorMessage){
    
    double Number;
    
    Number = ReadDbNumber("Invalid Number , Enter Again :");
    while(IsNumberBetWeen(Number,From,To)){
      cout << ErrorMessage ;
      Number = ReadDbNumber("Invalid Number , Enter Again :");
    }
    return Number;
  }
  
  // Is Valid Date 
  static bool IsValidDate(clsDate Date) {

		return clsDate::IsValidDate(Date);

	}
	
	
	static string ReadString(){
	  string str ="";
	  
	  getline(cin >> ws,str);
	  return str;
	}
};

