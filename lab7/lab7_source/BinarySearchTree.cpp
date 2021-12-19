//
// Created by ck on 2021/11/5.
//
#ifndef _BINARY_SEARCH_TREE_CPP
#define _BINARY_SEARCH_TREE_CPP
#include <iostream>

#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree(int id)
    : id(id), leftSubTree(nullptr), rightSubTree(nullptr) {}

BinarySearchTree::BinarySearchTree(const BinarySearchTree& other): id(other.id)
{
    // TODO: Clone the two subtrees accordingly.
    
    //id=other.id;
    if(other.leftSubTree!=nullptr)
        leftSubTree=new BinarySearchTree(*(other.leftSubTree));
    // else
    // {
    //     leftSubTree=nullptr;
    // }
    if(other.rightSubTree!=nullptr)
        rightSubTree=new BinarySearchTree(*(other.rightSubTree));
    // else
    // {
    //     rightSubTree=nullptr;
    // }
}

BinarySearchTree::~BinarySearchTree()
{
    // TODO: release the resources occupied by the two subtrees if any.
    // if(leftSubTree!=nullptr) 
    //     leftSubTree->~BinarySearchTree();
    // if(rightSubTree!=nullptr)
    //     rightSubTree->~BinarySearchTree();
    // delete this;
    if(leftSubTree!=nullptr)
        delete leftSubTree;
    if(rightSubTree!=nullptr)
        delete rightSubTree;

}

void BinarySearchTree::add(int newId)
{
    // TODO: Insert the newId to the current tree.
    // You need to create a new node for the newId and attach it to the correct place.
    // Do nothing if the id is already in the tree.
    if(newId==id)
        return;
    if(newId<id && leftSubTree!=nullptr)
        leftSubTree->add(newId);
    if(newId>id && rightSubTree!=nullptr)
        rightSubTree->add(newId);
    if(newId<id && leftSubTree==nullptr)
        leftSubTree=new BinarySearchTree(newId); //found
    if(newId>id && rightSubTree==nullptr)
        rightSubTree=new BinarySearchTree(newId); //found

}

bool BinarySearchTree::hasId(int idToFind) const
{
    // TODO: Check whether the given id is in the tree.
    // You need to determinate whether to seach the left subtree or right subtree.
    if(idToFind==id)
        return true;
    if(idToFind<id  && leftSubTree!=nullptr)
        return leftSubTree->hasId(idToFind);
    if(idToFind>id && rightSubTree!=nullptr)
        return rightSubTree->hasId(idToFind);
    return false;


}

int BinarySearchTree::height() const
{
    // TODO: Calculate the height of the tree.
    // Tree like this has height 0:
    //    O
    //
    // Trees like these have height 1:
    //    O        O       O
    //  /  \        \     /
    // O    O        O   O
    //base case: reach the leaf

    if(leftSubTree==nullptr && rightSubTree==nullptr)
        return 0;
    //left sub tree is not null
    else if(leftSubTree && rightSubTree==nullptr)
        return leftSubTree->height()+1;
    else if(rightSubTree && leftSubTree==nullptr)
        return rightSubTree->height()+1;
    else
        return(leftSubTree->height() > rightSubTree->height())?leftSubTree->height()+1:rightSubTree->height()+1;
}

void BinarySearchTree::printDFSPrefix() const
{
    std::cout << id << " ";
    if (leftSubTree != nullptr)
        leftSubTree->printDFSPrefix();

    if (rightSubTree != nullptr)
        rightSubTree->printDFSPrefix();
}

void BinarySearchTree::printDFSInfix() const
{
    if (leftSubTree != nullptr)
        leftSubTree->printDFSInfix();
    std::cout << id << " ";
    if (rightSubTree != nullptr)
        rightSubTree->printDFSInfix();
}
#endif