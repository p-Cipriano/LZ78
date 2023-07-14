#ifndef treeNode_h
#define treeNode_h

#include <iostream>
#include <vector>
#include "treeNode.hpp"

class treeNode{
    
    public:

    treeNode(char content, unsigned long long key){
        this->content = content;
        this->key = key;
    };
    
    treeNode* findChild(char c){
        for(treeNode* child:children){
            if(child->content == c)
                return child;
        }
        return nullptr;
    };
    
    unsigned long long key;
    char content;
    std::vector<treeNode*> children;
};

#endif
