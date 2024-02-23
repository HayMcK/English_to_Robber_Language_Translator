#include "Translator.h"

//Default constructor
Translator::Translator(){
    myModel = new Model;
};

//Destructor
Translator::~Translator(){
    delete myModel;
};

//Boolean function to check if the read character is a vowel
bool Translator::isVowel(char inp){
    char tmp = tolower(inp);
    switch(tmp){
        case 'a':
            return 1;
            break;
        case 'e':
            return 1;
            break;
        case 'i':
            return 1;
            break;
        case 'o':
            return 1;
            break;
        case 'u':
            return 1;
            break;
        default:
            return 0;
            break;
    }
}

//Function to translate a whole word by calling translate single vowel
//or translate single consonant from the model class.
string Translator::translateEnglishWord(string &engWord){   
    string myWord;
    for(int i = 0; i < engWord.size(); ++i){
        char tmp = engWord[i];
        if (isVowel(tmp)){
            myWord += myModel->translateSingleVowel(tmp);
        }
        else{
            myWord += myModel->translateSingleConsonant(tmp);
        }
    }
    return myWord;
}

//Function to translate whole sentences/lines by calling
//word translator after certain conditions are met.
string Translator::translateEnglishSentence(string &engSent){
    string mySent;
    string myWord;
    for(int j = 0; j < engSent.size(); ++j){
        char tmp = engSent[j];
        
        if(isalpha(tmp)){
            myWord += tmp;
        }
        else if(!isalpha(tmp) && !isspace(tmp)){
            mySent = mySent + translateEnglishWord(myWord);
            mySent = mySent + tmp;
            myWord = "";
        }
        else if(isspace(tmp)){
            mySent = mySent + translateEnglishWord(myWord);
            mySent = mySent + " ";
            myWord = "";
        }
        if(j == engSent.size()-1){
            mySent = mySent + translateEnglishWord(myWord);
            myWord = "";
        }
    }
    return mySent;
}