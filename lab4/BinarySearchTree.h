//
// Created by Stif on 10.06.2023.
//

#ifndef LAB_4_BINARYSEARCHTREE_H
#define LAB_4_BINARYSEARCHTREE_H

#endif //LAB_4_BINARYSEARCHTREE_H
#include "BinaryHeap.h"

template <class T>
class TreeElement{
public:
    T data;
    TreeElement *leftChild;
    TreeElement *rightChild;
    unsigned char height;
    TreeElement(T val){
        leftChild = nullptr;
        rightChild = nullptr;
        data = val;
        height = 1;
    }
};

template <class T>
class BinarySearchTree{
private:
    TreeElement<T> *root;
    size_t size;
    void delete_tree(TreeElement<T> * current){
        if(current){
            delete_tree(current->rightChild);
            delete_tree(current->leftChild);
            delete current;
        }
    }
public:
    BinarySearchTree(T a){
        root = new TreeElement<T>(a);
        size = 1;
    }

    BinarySearchTree(TreeElement<T> *r){
        root = r;
        size = 1;
    }

    ~BinarySearchTree(){
        delete_tree(root);
    }

    bool Find(T key){
        TreeElement<T> *current = root;
        while (current && current->data != key){
            if (current->data > key)
                current = current->leftChild;
            else
                current = current->rightChild;
        }
        return current != nullptr;
    }

    void Add(T key){
        TreeElement<T> *current = root;
        while (current && current->data != key){
            if (current->data > key && current->leftChild == nullptr){
                current->leftChild  = new TreeElement<T>(key);
                ++size;
                return;
            }
            if (current->data < key && current->rightChild == nullptr){
                current->rightChild = new TreeElement<T>(key);
                ++size;
                return;
            }
            if (current->data > key)
                current = current->leftChild;
            else
                current = current->rightChild;
        }
    }

    unsigned char height(TreeElement<T> * p){
        return p?p->height:0;
    }

    int balanceFactor(TreeElement<T>* p){
        return height(p->rightChild)-height(p->leftChild);
    }

    void fixHeight(TreeElement<T>* p){
        unsigned char hl = height(p->leftChild);
        unsigned char hr = height(p->rightChild);
        p->height = (hl>hr?hl:hr)+1;
    }

    TreeElement<T>* rotateRight(TreeElement<T>* p){
        TreeElement<T>* q = p->leftChild;
        p->leftChild = q->rightChild;
        q->rightChild = p;
        fixHeight(p);
        fixHeight(q);
        return q;
    }

    void balanceTree(TreeElement<T> *root1){
        if (root1!= nullptr)
            return;
        balance(root1);
        balanceTree(root1->leftChild);
        balanceTree(root1->rightChild);
    }


    void DeleteElement(T key){
        TreeElement<T> * current = root;
        TreeElement<T> * parent = nullptr;
        while (current && current->data != key){
            parent = current;
            if (current->data > key)
                current = current->leftChild;
            else
                current = current->rightChild;
        }
        if (!current)
            return;
        if (current->leftChild == nullptr){
            if (parent && parent->leftChild == current)
                parent->leftChild = current->rightChild;
            if (parent && parent->rightChild == current)
                parent->rightChild = current->rightChild;
            --size;
            delete current;
            return;
        }
        if (current->rightChild == nullptr){
            if (parent && parent->leftChild == current)
                parent->leftChild = current->leftChild;
            if (parent && parent->rightChild == current)
                parent->rightChild = current->leftChild;
            --size;
            delete current;
            return;
        }
        TreeElement<T> * replace = current->rightChild;
        while (replace->leftChild)
            replace = replace->leftChild;
        T replace_value = replace->data;
        DeleteElement(replace_value);
        current->data = replace_value;
    }

    size_t GetSize(){
        return size;
    }

    TreeElement<T> *copyElements(TreeElement<T> *treeElement, T func(T, T), T b){
        if(treeElement == nullptr)
            return nullptr;
        T a = treeElement->data;
        TreeElement<T> *newNode = new TreeElement<T>(func(a, b));
        newNode->leftChild = copyElements(treeElement->leftChild, func, b);
        newNode->rightChild = copyElements(treeElement->rightChild, func, b);
        return newNode;
    }

    BinarySearchTree<T> *map(T func(T, T), T a){
        TreeElement<T> *newNode = copyElements(root, func, a);
        BinarySearchTree<T> *binarySearchTree = new BinarySearchTree<T>(newNode);
        return binarySearchTree;
    }

    TreeElement<T> *copyElements(TreeElement<T> *treeElement){
        if(treeElement == nullptr)
            return nullptr;
        T a = treeElement->data;
        TreeElement<T> *newNode = new TreeElement<T>(a);
        newNode->leftChild = copyElements(treeElement->leftChild);
        newNode->rightChild = copyElements(treeElement->rightChild);
        return newNode;
    }

    bool isEqual(TreeElement<T> *treeElement, TreeElement<T> *treeElement1, bool flag){
        if(treeElement == nullptr)
            return flag;
        T a = treeElement->data;
        T b = treeElement1->data;
        if(a!=b)
            flag = false;
        isEqual(treeElement->rightChild, treeElement1->rightChild, flag);
        isEqual(treeElement->leftChild, treeElement1->leftChild, flag);
        return flag;
    }

    void TraverseTree(bool func(T, T), TreeElement<T> *treeElement, T b){
        if(treeElement == nullptr)
            return;
        TraverseTree(func, treeElement->leftChild, b);
        TraverseTree(func, treeElement->rightChild, b);
        T a = treeElement->data;
        if (func(a, b))
            DeleteElement(a);
    }

    BinarySearchTree<T> *where(bool func(T, T), T a){
        TreeElement<T> *newNode = copyElements(root);
        BinarySearchTree<T> *binarySearchTree =  new BinarySearchTree<T>(newNode);
        binarySearchTree->TraverseTree(func, binarySearchTree->GetRoot(), a);
        return binarySearchTree;
    }

    TreeElement<T> *GetRoot(){
        return root;
    }

    BinarySearchTree<T> *GetSubTree(T element){
        TreeElement<T> *current = root;
        while (current && current->data != element){
            if (current->data > element)
                current = current->leftChild;
            else
                current = current->rightChild;
        }
        if(current == nullptr)
            return nullptr;

        auto *r = copyElements(current);
        BinarySearchTree<T> *binarySearchTree = new BinarySearchTree<T>(r);
        return binarySearchTree;
    }
};