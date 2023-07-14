#include <iostream>
#include <string>
#include "compress.cpp"
#include "decompress.cpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    string outName;
    
    if(strcmp(argv[1],"-x")==0){
        if(argc==3){
            outName = argv[2];
            outName = outName.replace(outName.length()-4,outName.length(),".txt");
        }
        else if(argc==5)
            outName = argv[4];
        else{
            cout << "Number of arguments is invalid: " << argc << endl;
            return -1;
        }
        decompress(argv[2], outName);
    }
    
    else if(strcmp(argv[1],"-c")==0){
        if(argc==3){
            outName = argv[2];
            outName = outName.replace(outName.length()-4,outName.length(),".z78");
        }
        else if(argc==5)
            outName = argv[4];
        else{
            cout << "Number of arguments is invalid: " << argc << endl;
            return -1;
        }
        compress(argv[2], outName);
    }
    
    else
        cout<<"compress/decompress command invalid" << endl;
        return -1;
    
    return 0;
}
