#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include "Translator.h"
#include <fstream>

using namespace std;

/* A class that will thake text files (.txt) containing English text 
and produce a HTML file containing the equivalent Robber Language 
translation that can be viewed in a standard web browser. */
class FileProcessor{
    private:
        Translator *myTranslator;
    public:
        FileProcessor();
        ~FileProcessor();
        bool checkHTML(string fileName);
        bool checkTXT(string fileName);
        void processFile(string inpFile, string outFile);
        void writeHTMLFile(string engInp, string rovInput, string outFile);
};
#endif 