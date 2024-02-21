#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <iostream>
using namespace std;

class Translator{
    //a class named Translator that will translate English sentences to Rövarspråket sentences using the Model class.
    private:
    public:
        Translator();
        ~Translator();
        string translateEnglishWord(string &engWrd);//Takes a single string representing a single English word as input and returns a string representing the Rövarspråket translation.
        string translateEnglishSentence(string &engSent);//Takes a single string representing a single English sentence as input and returns a string representing the Rövarspråket translation. Account for punctuation.
        bool isVowel(char inp);
};
#endif