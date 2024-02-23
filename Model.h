#ifndef MODEL_H
#define MODEL_H

#include <iostream>

using namespace std;

//A class that will encode the rules of the robber language
class Model{
    private:
    public:
        Model();
        ~Model();
        string translateSingleConsonant(char cons);
        string translateSingleVowel(char vowel);
        
};
#endif