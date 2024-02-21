#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <iostream>
#include <fstream>

using namespace std;

class FileProcessor{
    /*  A class named FileProcessor that will take text files (.txt) containing English text and produce 
    a HTML file containing the equivalent Rövarspråket translation that can be viewed
    in a standard web browser.  */
    private:
    public:
        FileProcessor();
        ~FileProcessor();
        bool checkHTML(string fileName);
        void processFile(string inpFile, string outFile);//should produce an HTML file that has the original English text in bold followed by an empty line, followed by the Rövarspråket translation in italics
        void writeHTMLFile(string engInp, string rovInput, string outFile);
};
#endif 