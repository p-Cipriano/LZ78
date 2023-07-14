#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <map>

using namespace std;

void decompress(string inFileName, string outFileName){
    ifstream inFile;
    inFile.open(inFileName);
    inFile >> noskipws;
    
    ofstream outFile;
    outFile.open(outFileName);
    
    unsigned long long int keyBytes = 1;
    
    unsigned long long int key = 0;
    char c;
    string newDictItem;
    
    unsigned long long int i = 0;
    map<unsigned long long int, string> dictionary;
    dictionary[i++] = "";
    
    while(inFile.read((char *) &key, keyBytes)){
        inFile.read((char *) &c, sizeof(char));
        
        newDictItem = dictionary[key];
        newDictItem+=c;
        dictionary[i++] = newDictItem;
        outFile<<newDictItem;
        
        if(i==pow(2,8*keyBytes))
            keyBytes++;
	key = 0;
    }
}
