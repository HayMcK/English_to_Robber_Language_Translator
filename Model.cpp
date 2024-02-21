#include "Model.h"
 
Model::Model(){}

Model::~Model(){}

string Model::translateSingleConsonant(char cons){
    if(isupper(cons)){
        string tmp(1, toupper(cons));
        return tmp + "O" + tmp;
    }
    else{
        string tmp(1, tolower(cons));
        return tmp + "o" + tmp;
    }
}

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