#include "Model.h"
 
//Default constructor
Model::Model(){}

//Destructor
Model::~Model(){}

//A function to translate a consonant while maintaining capitalization when needed.
string Model::translateSingleConsonant(char cons){
    if(isupper(cons)){
        string tmp(1, toupper(cons));
        string tmp2(1, tolower(cons));
        return tmp + "o" + tmp2;
    }
    else{
        string tmp(1, tolower(cons));
        return tmp + "o" + tmp;
    }
}

//A function to translate a vowel while maintaining capitalization when needed.
string Model::translateSingleVowel(char vowel){
    if(isupper(vowel)){
        string tmp(1, toupper(vowel));
        return tmp;
    }
    else{
        string tmp(1, tolower(vowel));
        return tmp;
    }
}