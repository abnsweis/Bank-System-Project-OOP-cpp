#pragma once
#include <iostream>
#include "./clsDate.h"




class clsUtil{
  
  
  
  public :
  
  static void Srand(){
    srand((unsigned) time(NULL));
  }
  // Positive Number 
  static int ReadNumberPositive() {
    int number;
    do {
      cout << "Enter Positive Number :";
      cin >> number;
    }while(number < 0);
  
    return number;
  };
  
  // Encrypt Text
  static string EncryptText(string text, short EncryptionKey) {
    for (int i = 0; i <= text.length(); i++) {
      text[i] = char((int) text[i] + EncryptionKey);
    }
    return text;
  }
  
  // Decrypt Text
  static string DecryptText(string text, short EncryptionKey) {
    //string Decrypt_Text = "";
    for (int i = 0; i <= text.length() - 1; i++) {
      text[i] = char((int) text[i]- EncryptionKey);
      
    }
    return text;
  }
  
  // Random Number
  static int RandomNumber(int from, int to) {
    return rand() % (to - from + 1) + from;
  }
  
  // Random Character
  enum enCharType {
    SmallLetters = 1,
    CapitallLetters = 2,
    SpecialCharacters = 3,
    Digits = 4,
    Mix=5
  };
  static char RandomCharacter(enCharType CharType) {
    switch (CharType) {
  
      case enCharType::SmallLetters:
      return char(clsUtil::RandomNumber(97, 122));
  
  
      case enCharType::CapitallLetters:
      return char(clsUtil::RandomNumber(65, 90));
  
  
      case enCharType::Digits:
      return char(clsUtil::RandomNumber(48, 57));
  
  
      case enCharType::SpecialCharacters:
      return char(clsUtil::RandomNumber(33, 47));
      
      case enCharType::Mix:
      return char(clsUtil::RandomNumber(33, 120));
  
  
    }
  
    return 0;
  }
  
  
  // Generate Word
  static string GenerateWord(enCharType CharType, short length) {
    string word = "";
  
    for (int i = 1; i <= length; i++) {
      word += RandomCharacter(CharType);
    }
    return word;
  }

  // Generate Key
  static string GenerateKey(enCharType CharType) {
  
    string Key = "";
  
    Key += GenerateWord(CharType, 4) + "-"+GenerateWord(CharType, 4) + "-"+GenerateWord(CharType, 4) + "-"+GenerateWord(CharType, 4);
  
    return Key;
  }
  
  // Generate Keys
  static void GenerateKeys(short NumberOfKeys,enCharType CharType){
    
    for (int i = 0; i < NumberOfKeys; i++) {
      cout <<"Key ["<<i+1<<"] "<<GenerateKey(CharType)  << endl;
    }
  }
  
  
  // Fill Array With Random Number
  static void FillArrayWithRandomNumber(int arr[100], int arrayLength,int from,int to) {
    
  
    for (int i = 0; i <= arrayLength -1; i++) {
      arr[i] = RandomNumber(from, to);
    }
  
  }
  
  static void FillArrayWithRandomWords(string arr[100],int arrayLength,enCharType CharType,int WordLength){
    
    for (int i = 0; i < arrayLength; i++) {
      arr[i] = GenerateWord(CharType,WordLength);
    }
    
  }
  
  
  
  static void FillArrayWithRandomKeys(string arr[100],int arrayLength,enCharType CharType){
    
    for (int i = 0; i < arrayLength; i++) {
      arr[i] = GenerateKey(CharType);
    }
    
  }
  
  // Swap Number of Type int
  static void Swap(int& number1,int& number2){
    int Temp;
    Temp=number1;
    number1=number2;
    number2 = Temp;
  }
    // Swap Number of Type double
  static void Swap(double &number1,double &number2){
    double Temp ;
    Temp =number1;
    number1 = number2;
    number2 = Temp;
  }
    // Swap Number of Type string
  static void Swap(string &string1,string &string2){
    
    string Temp;
    
    Temp =string1 ;
    string1 = string2;
    string2 = Temp;
    
  };
  
  // Shuffle Array Type Int
  static void ShuffleArray(int arr[100],int arrLength){
    
    for (int i = 0; i < arrLength; i++) {
      Swap(arr[RandomNumber(1,arrLength)-1],arr[RandomNumber(1,arrLength)-1]);
    }
    
  }
  
  
  
  static void ShuffleArray(string arr[100],int arrLength){
    
    for (int i = 0; i < arrLength; i++) {
      Swap(arr[RandomNumber(1,arrLength)-1],arr[RandomNumber(1,arrLength)-1]);
    }
  }
  // Tabs
  static string Tabs(short NumberOfTabs) {
    string t = "";

    for (int i = 1; i < NumberOfTabs; i++) {
      t = t + "\t";
      cout << t;
    }
    return t;

  }
  
  
  static void SwapDates(clsDate & Date1, clsDate & Date2) {

		clsDate TempDate;
		TempDate = Date1;
		Date1 = Date2;
		Date2 = TempDate;

	}
    
  static string NumberToText(int number){
	
	if(number ==0){
		return "";
	}
	
	if(number >= 1 && number <=19 ){
		
		string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven", "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen", "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
		return arr[number] + " ";
	}
	
	if(number >= 20 && number <= 99){
		string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
		
		return arr[number/10] + " " + NumberToText(number % 10);
		
	}
	
	if(number >=100 && number <= 199){
		return "One Hundred " + NumberToText(number%100);
	}
	
	if(number >=200 && number <= 999){
		return NumberToText(number/100) + "Hundreds " + NumberToText(number%100);
	}
	
	if(number >=1000 && number <=1999){
		return "One Thousand " + NumberToText(number%1000);
	}
	
	if(number >=2000 && number <=999999){
		return NumberToText(number/1000) + "Thousands "+ NumberToText(number%1000);
	}
	
	if(number >=1000000 &&number<=1999999){
		return "One Million " + NumberToText(number%1000000);	
	}
	
	if(number >=2000000 && number <=999999999){
		return NumberToText(number/1000000) + "Millions " + NumberToText(number%1000000);
	}
	
	if(number >=1000000000 && number <=1999999999){
		return "One Billion " + NumberToText(number%1000000000);
	}
	else{
	 	return NumberToText(number/1000000000) + " Billions "
	 	+NumberToText(number%1000000000);
	}						   
	
}
};