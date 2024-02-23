#include "FileProcessor.h"


int main(int argc, char **argv){
    if(argc == 3){
        FileProcessor f;
        f.processFile(argv[1], argv[2]);
    }
    else{
        cout << "Invalid number of command line arguments." << endl;
    }    
    return 0;
}