#include "Translator.h"
#include "Model.h"

Translator::Translator(){};

Translator::~Translator(){};

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

string Translator::translateEnglishWord(string &engWord){   
    string myWord;
    for(int i = 0; i < engWord.size(); ++i){
        char tmp = engWord[i];
        if (isVowel(tmp)){
            Model m;
            myWord += m.translateSingleVowel(tmp);
        }
        else{
            Model n;
            myWord += n.translateSingleConsonant(tmp);
        }
    }
    return myWord;
}

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