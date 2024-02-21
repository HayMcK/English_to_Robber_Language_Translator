#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <string>

using namespace std;

class Model{
    //A class named Model that will encode the rules of the Robber language.
    private:
    public:
        Model();
        ~Model();
        string translateSingleConsonant(char cons);//takes a single consonant character as input and returns a string representing its encoding in Rövarspråket. Capitalization should be preserved.
        string translateSingleVowel(char vowel);//takes a single vowel character as input and returns a string representing its encoding in Rövarspråket. Capitalization should be preserved.
        
};
#endif