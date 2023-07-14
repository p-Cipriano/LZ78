#include <fstream>
#include <iostream>
#include <math.h>
#include "treeNode.hpp"

using namespace std;

void compress(string inFileName, string outFileName){
    ifstream inFile;
    inFile.open(inFileName);
    inFile >> noskipws;
    
    ofstream outFile;
    outFile.open(outFileName, ios::out | ios::binary);
    
    // Retire as partes comentadas para criar o arquivo de representação
    //ofstream representationFile;
    //representationFile.open(outFileName.replace(outFileName.length()-4,outFileName.length(),"_z78representation.txt"));
    
    treeNode* root = new treeNode('\0', 0);
    treeNode* currentNode = root;
    treeNode* childFound;
    
    unsigned keyBytes = 1;
    
    unsigned long long int i=1;
    char c;
    
    while(inFile>>c){
	if(c=='\0')
	    break;
        
        childFound = currentNode->findChild(c);
        
        if(childFound!=nullptr)
            currentNode = childFound;
        
        else{
            //representationFile << '(' << currentNode->key <<','<< c << ')';
            outFile.write((char *) &currentNode->key, keyBytes);
            outFile.write((char *) &c, sizeof(char));
            currentNode->children.push_back(new treeNode(c, i++));
            currentNode = root;
            
            if(i == 0)
                cout<< "long long overflow" << endl;
            
            if(i == pow(2,8*keyBytes))
                keyBytes++;
        }
    }
    c = '\0';
    
    //representationFile << '(' << currentNode->key <<',' << c << ')';
    outFile.write((char *) &currentNode->key, keyBytes);
    outFile.write((char *) &c, sizeof(char));

}