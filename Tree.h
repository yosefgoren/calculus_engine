#ifndef TREE
#define TREE
#include "list"

template <class Data>
struct Tree
{
    Tree(const Data& head_value, const std::list<Tree>* sons = nullptr)
        :head_value(head_value), sons(sons){}
    
    Data head_value;
    std::list<Tree>* sons;
};

#endif