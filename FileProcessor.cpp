#include "FileProcessor.h" 
#include "Translator.h"

FileProcessor::FileProcessor(){}

FileProcessor::~FileProcessor(){}

bool FileProcessor::checkHTML(string fileName){
    bool isFound;
    string check = ".html";
    isFound = fileName.find(check) != string::npos;
    return isFound;
}

void FileProcessor::writeHTMLFile(string engInp, string rovInp, string outFile){
    ofstream newFile(outFile);
    if(!checkHTML(outFile)){
        cout << "Failed to open output file. Possible invalid file name or type." << endl;
    }
    else{
        newFile << "<!DOCTYPE html>" << endl;
        newFile << "<html>" << endl;
        newFile << "<head>" << endl;
        newFile << "<title> English to Robber translation </title>" << endl;
        newFile << "</head>" << endl;
        newFile << "<body>" << endl;
        newFile << "<p><b>" << engInp << "</b></p>" << endl;
        newFile << "<p><i>" << rovInp << "</i></p>" << endl;
        newFile << "</body>" << endl;
        newFile << "</html>" << endl;
        newFile.close();
    }
}

void FileProcessor::processFile(string inpFile, string outFile){
    ifstream myFile(inpFile);
    if (!myFile){
        cout << "Failed to open input file. Possible invalid file name." << endl;
    }
    else{
        string myLine;
        string engOut;
        string rovOut;
        while(!myFile.eof()){
            getline(myFile, myLine);
            Translator t;
            engOut = engOut + myLine + "<br>";
            rovOut = rovOut + t.translateEnglishSentence(myLine) + "<br>";
        }
        writeHTMLFile(engOut, rovOut, outFile);
        myFile.close();
    }
}