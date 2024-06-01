#pragma once
#include <iostream>
#include <vector>

using namespace std;



class clsString {
	private:
	string _value;
	
	
	
	public:
	clsString() {
		_value = "";
	}
	clsString(string value){
		_value = value;
	}
	
	
	void SetValue(string value){
		_value = value;
		
	}
	string GetValue(){
		return _value;
	}
	
	//__declspec(property(get = GetValue, put = SetValue)) string Value;
  
	static short Length(string str){
		return str.length();
	}
	short Length(){
		return Length(_value);
	}
	
	// return sum words in string 
	static short CountWords(string str ){
	
		short counter = 0;
		string delimiter = " ";
		short pos = 0;
		string word = "";
		while((pos = str.find(delimiter)) != std::string::npos){
			
			word = str.substr(0,pos);
			
			if(word != ""){
				counter++;
			}
			str.erase(0,pos + delimiter.length());
			
		}
		
		if(word != ""){
			counter++;
			
		}
		return counter;
	}
	short CountWords(){
		return CountWords(_value);
	}
	
	// Convert First Letter To Upper Case 
	static string UpperFirstLetterOfEachWord(string str){
	
		bool isFirstLetter = true;
		
		for (int i = 0; i < str.length(); i++) {
			
			if(str[i] != ' ' && isFirstLetter ){
				str[i] = toupper(str[i]);	
			}
			
			isFirstLetter = str[i] == ' ' ? true : false;
			
		}
		return str;
	}
	void UpperFirstLetterOfEachWord(){
		_value = UpperFirstLetterOfEachWord(_value);
	};
	
	// Convert First Letter To Lower
	static string LowerFirstLetterOfEachWord(string str){
	
		bool isFirstLetter=true;
		for (int i = 0; i < str.length(); i++) {
			
			if(str[i] != ' ' && isFirstLetter){
				str[i] = tolower(str[i]);
			}
			
			isFirstLetter = str[i] == ' ' ? true : false;
			
		}
		return str;
	}
	void LowerFirstLetterOfEachWord(){
		_value = LowerFirstLetterOfEachWord(_value);
	}
	
	//  Convert  String To Lowercase
	static string StringToLowercase(string str) {

		for (int i = 0; i < str.length(); i++) {
			str[i] = tolower(str[i]);
		}

		return str;
	
		
		
	}
	void StringToLowercase(){
	 	_value = StringToLowercase(_value);
	}	
	
	//  Convert  String To Upper
	static string StringToUppercase(string str) {

		for (int i = 0; i < str.length(); i++) {
			str[i] = toupper(str[i]);
		}

		return str;
	
		
		
	}
	void StringToUppercase(){
		_value = StringToUppercase(_value);
	}
	
	static char InvertCharCase(char character){
		return character == toupper(character) ? tolower(character) :
		toupper(character);
	}
	// Invert String Case 
	static string InvertAllLettersCase(string str){
		for (int i = 0; i < str.length(); i++) {
			str[i] = InvertCharCase(str[i]);
		}
		return str;
	}
	void InvertAllLettersCase(){
		_value =  InvertAllLettersCase(_value);
	}
	
	enum enWhatToCount {
		SmallLetters = 0,
		CapitalLetters = 1,
		All = 3
	};
	// Count Of All Letters
	static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All) {


		if (WhatToCount == enWhatToCount::All) {
			return S1.length();
		}

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++) {

			if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
			Counter++;


			if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
			Counter++;


		}

		return Counter;

	}
	
	// Return Number Of All Upper Case Letters
	static short NumberOfUppercaseLetters (string str ){
	
		int counter =0;
		for (int i = 0; i < str.length(); i++) {
			if(isupper(str[i]) ){
				counter++;
			}
		}
		return counter;
	}
	short NumberOfUppercaseLetters(){
		return NumberOfUppercaseLetters(_value);
	}
	
	// Return Number Of All Lower Case Letters
	static short NumberOfLowercaseLetters (string str ){
	
		int counter =0;
		for (int i = 0; i < str.length(); i++) {
			if(islower(str[i]) ){
				counter++;
			}
		}
		return counter;
	}
	short NumberOfLowercaseLetters(){
		return NumberOfLowercaseLetters(_value);
	}

	static short CountSpecificLetter(string S1, char Letter, bool MatchCase = true) {

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++) {

			if (MatchCase) {
				if (S1[i] == Letter)
				Counter++;
			}
			else
			{
				if (tolower(S1[i]) == tolower(Letter))
				Counter++;
			}

		}

		return Counter;
	}
	short CountSpecificLetter(char Letter, bool MatchCase = true) {
		return CountSpecificLetter(_value, Letter, MatchCase);
	}

	static bool IsVowel(char Ch1) {
		Ch1 = tolower(Ch1);

		return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));

	}
	static short CountVowels(string S1) {

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++) {

			if (IsVowel(S1[i]))
			Counter++;

		}

		return Counter;
	}
	
	// Split All String And Return As Vector
	static vector <string> split(string str, string delimiter) {

		vector < string > vString;

		short pos = 0;
		string word = "";
		while((pos = str.find(delimiter)) != std::string::npos) {
			word = str.substr(0, pos);
			if(word != "") {
				vString.push_back(word);
			}
			str = str.erase(0, pos + delimiter.length());
		}
		if(word != "") {
			vString.push_back(str);
		}
		return vString;
	}
	vector <string>  split(string delimiter){
		return split(_value,delimiter);
	}
	
	
	// Remove all spaces from left side 
	static string TrimLeft(string str){
		for (int i = 0; i < str.length(); i++) {
		if(str[i] != ' ' ){
			str.erase(0,i);
		}
	}
	return str;
	
	}
	void TrimLeft(){
		_value =TrimLeft(_value);
	};
	
	// Remove all spaces from Right side 
	static string TrimRight(string str){
		for (int i = str.length() - 1  ; i > 0; i--) {
			if(str[i] != ' '){
				return str.erase(i+1,str.length());
			}
		}
	return str;
	}
	void TrimRight(){
		_value = TrimRight(_value);
	}
	
	// Remove All Spaces From Right And left
	static string trim(string str){
		return TrimRight(TrimLeft(str));
	}
	void Trim(){
		_value = trim(_value);
	}
	
	
	// Join Words To One line String  =>> Requires vector
	static string join(vector <string> vWords,string delimiter=" "){
		
		string str="";
		for (string &word : vWords) {
			str += word + delimiter;
		}
		
		return str.substr(0,str.length() - delimiter.length());
	}
	
	// Join Words To One line String  =>> Requires Array Of String
	static string join(string arrStr[],int arrlength , string delimiter){
		
		string str = "";
	
		for (int i = 0; i < arrlength; i++) {
			str += arrStr[i] + delimiter;
		}
		return str.substr(0,str.length() - delimiter.length());
	}
	
	// Reverse String
	static string RevereString(string S1) {
		string S2 = "";
		vector < string > vString;
	
	
		vString = clsString::split(S1, " ");
	
		vector <string> ::iterator iter = vString.end();
	
		while(iter != vString.begin()) {
	
			iter--;
	
			S2 += *iter + " ";
		}
	
		return clsString::TrimRight(S2);
	}
	void RevereString(){
		_value =  RevereString(_value);
	}
	
	// Replce Word in String
	static string replceWord(string S1,string WordToReplce,string NewWord){
	
		short pos = S1.find(WordToReplce);
		while(pos != std::string::npos){
			
			S1 = S1.replace(pos,WordToReplce.length(),NewWord);
			pos = S1.find(WordToReplce);
			
		}
		return S1; 
	}
	void replceWord(string WordToReplce,string NewWord){
		_value = replceWord(_value , WordToReplce,NewWord);
	}
	
	// Remover All Punctuations From String
	static string RemoverAllPunctuationsFromString(string S1){
		string NewString = "";
		for (int i = 0; i < S1.length(); i++) {
				
			if(!ispunct(S1[i])){
				NewString += S1[i] ;
					
			}
		}
		return NewString;
	}
	
	void RemoverAllPunctuationsFromString(){
		_value = RemoverAllPunctuationsFromString(_value);
	}
	
	static string FirstLetteraOfAllWordsToUpper(string text){
	string str="";
	bool isFirstLetter=true;
	for (short i = 0; i < text.length(); i++) {
	  
		if(text[i] != ' ' && isFirstLetter){
			text[i] = toupper(text[i]);
		}
		str+=text[i];
		
		isFirstLetter = (text[i] == ' ' ? true : false );
		
	}
  
		return str;
  }
  
  void FirstLetteraOfAllWordsToUpper(){
    _value = FirstLetteraOfAllWordsToUpper(_value);
  }
};