#include "FileProcessor.h"
#include "Model.h"
#include "Translator.h"

int main(int argc, char **argv){
    //ask if this is valid error handling technique
    if(argc == 3){
        FileProcessor f;
        f.processFile(argv[1], argv[2]);
    }
    else{
        cout << "Invalid number of command line arguments." << endl;
    }    
    return 0;
}