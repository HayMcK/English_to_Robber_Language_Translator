#include "FileProcessor.h" 

//Default constructor
FileProcessor::FileProcessor(){
    myTranslator = new Translator;
}

//Destructor
FileProcessor::~FileProcessor(){}

//A boolean function to check if the output file
//that is input in the command line is an HTML file
bool FileProcessor::checkHTML(string fileName){
    string end = ".html";
    string tmp;
    if(fileName.length() <= 5){//make sure the file name isn't just ".html" or shorter
        return 0;
    }
    for (int i = fileName.length()-5; i < fileName.length(); ++i){//only compare the end of the string for the filename extension type of html
        tmp = tmp + fileName[i];
    }
    if(tmp == end){
        return 1;
    }
    else{return 0;}
}

//A function to write to the HTML file
void FileProcessor::writeHTMLFile(string engInp, string rovInp, string outFile){
    if(!checkHTML(outFile)){//check if the file ends with .html
        cout << "Failed to open output file. Possible invalid file name or type." << endl;
    }
    else{//set up the formatting and input the original/translation texts for the html file
        ofstream newFile(outFile);
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

/* A function to process the input file and call the translator class 
then output the original text with the translated text to the output 
file name that is input as a command line prompt. The output file will 
have the original text in bold and the translated text in italics. */
void FileProcessor::processFile(string inpFile, string outFile){
    ifstream myFile(inpFile);
    if (!myFile){//check if the input file opens
        cout << "Failed to open input file. Possible invalid file name." << endl;
    }
    else{
        string myLine;
        string engOut;
        string rovOut;
        while(!myFile.eof()){//while the file contains another line
            getline(myFile, myLine);
            engOut = engOut + myLine + "<br>";
            rovOut = rovOut + myTranslator->translateEnglishSentence(myLine) + "<br>";
        }
        writeHTMLFile(engOut, rovOut, outFile);
        myFile.close();
    }
}