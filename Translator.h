#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include "Model.h"

using namespace std;

//A class that will translate English sentences to Robber Language sentences using the Model class.
class Translator{
    private:
        Model *myModel;
    public:
        Translator();
        ~Translator();
        string translateEnglishWord(string &engWrd);
        string translateEnglishSentence(string &engSent);
        bool isVowel(char inp);
};
#endif