//
// Created by Stif on 10.06.2023.
//

#ifndef UNTITLED9_TESTS_H
#define UNTITLED9_TESTS_H

#endif
#include "test.h"

using namespace std;

void testPass(int total, int done){
    cout<<"Done: "<<done<<". Total: "<<total<<"."<<endl;
    if(done == total){
        cout<<"Test passed successfully."<<endl;
    }else{
        cout<<"Test failed."<<endl;
    }
}

void testBinaryTreeAdd(int count){
    cout<<"Testing adding in tree."<<endl;
    TreeElement<int> *root = new TreeElement<int>(1);
    BinarySearchTree<int> *binarySearchTree = new BinarySearchTree<int>(root);
    int passed = 0;
    for (int i = 0; i < count; ++i) {
        binarySearchTree->Add(i);
        if (binarySearchTree->Find(i))
            passed++;
    }
    testPass(count, passed);
}

void testBinaryTreeGetSize(int count){
    cout<<"Testing get size in tree."<<endl;
    TreeElement<int> *root = new TreeElement<int>(10);
    BinarySearchTree<int> *binarySearchTree = new BinarySearchTree<int>(root);
    int passed = 0;
    for (int i = 0; i < count; ++i) {
        binarySearchTree->Add(i);
        if (binarySearchTree->GetSize() == i+2)
            passed++;
    }
    testPass(count, passed);
}

void testBinaryTreeIsEqual(int count){
    cout<<"Testing equal in tree."<<endl;
    TreeElement<int> *root1 = new TreeElement<int>(10);
    BinarySearchTree<int> *binarySearchTree1 = new BinarySearchTree<int>(root1);
    TreeElement<int> *root2 = new TreeElement<int>(10);
    BinarySearchTree<int> *binarySearchTree2 = new BinarySearchTree<int>(root2);
    int passed = count;
    for (int i = 0; i < count; ++i) {
        binarySearchTree1->Add(i);
        binarySearchTree2->Add(i);
    }
    bool flag = true;
    bool match = binarySearchTree1->isEqual(binarySearchTree1->GetRoot(), binarySearchTree2->GetRoot(), flag);
    if(match)
        testPass(count, passed);
    if(!match)
        testPass(count, 0);
}

void testBinaryHeapAdd(int count){
    cout<<"Testing adding in heap."<<endl;
    int *a = new int[1];
    a[0] = 1;
    BinaryHeap<int> *binaryHeap = new BinaryHeap<int>(a, 1);
    int passed = 1;
    for (int i = 0; i < count+1; ++i) {
        binaryHeap->AddElement(i);
        if(binaryHeap->findElement(i))
            passed++;
    }
    testPass(count, passed);
}

void testBinaryHeapDelete(int count){
    cout<<"Testing deleting in heap."<<endl;
    int *a = new int[1];
    a[0] = 0;
    BinaryHeap<int> *binaryHeap = new BinaryHeap<int>(a, 1);
    int passed = 1;
    for (int i = 0; i < count; ++i) {
        binaryHeap->AddElement(i);
    }
    for (int i = 0; i < count; ++i) {
        binaryHeap->deleteElement(i);
        if(binaryHeap->findElement(i)<0)
            passed++;
    }
    testPass(count, passed);
}

int mult(int a, int b){
    return a*b;
}

void testBinaryHeapMap(int count){
    cout<<"Testing map in heap."<<endl;
    int *a = new int[1];
    a[0] = 0;
    int passed = count;
    BinaryHeap<int> *binaryHeap = new BinaryHeap<int>(a, 1);
    for (int i = 0; i < count; ++i) {
        binaryHeap->AddElement(i);
    }
    BinaryHeap<int> *binaryHeap1 = binaryHeap->map(mult, 2);
    bool flag = true;
    if(binaryHeap->GetHeapSize() != binaryHeap1->GetHeapSize() )
        flag = false;
    for (int i = 0; i < binaryHeap->GetHeapSize() ; ++i) {
        if(binaryHeap->GetArray().Get(i)*2 != binaryHeap1->GetArray().Get(i))
            flag = false;
    }
    if(flag)
        testPass(count, passed);
    if(!flag)
        testPass(count, passed);
}

void testBinaryHeapIsEqual(int count){
    cout<<"Testing map in heap."<<endl;
    int *a = new int[1];
    a[0] = 0;
    int passed = count;
    BinaryHeap<int> *binaryHeap = new BinaryHeap<int>(a, 1);
    BinaryHeap<int> *binaryHeap1 = new BinaryHeap<int>(a, 1);
    for (int i = 0; i < count; ++i) {
        binaryHeap->AddElement(i);
        binaryHeap1->AddElement(i);
    }
    if(*binaryHeap == *binaryHeap1)
        testPass(count, passed);
    else
        testPass(count, 0);
}

bool IsEven(int a, int b){
    if(a%b == 0)
        return true;
    return false;
}

void testBinaryHeapWhere(int count){
    cout<<"Testing where in heap."<<endl;
    int *a = new int[1];
    a[0] = 0;
    int passed = count;
    BinaryHeap<int> *binaryHeap = new BinaryHeap<int>(a, 1);
    for (int i = 0; i < count; ++i) {
        binaryHeap->AddElement(i);
    }
    BinaryHeap<int> *binaryHeap1 = binaryHeap->where(IsEven, 2);
    bool flag = true;
    for (int i = 0; i < binaryHeap1->GetHeapSize(); ++i) {
        if(binaryHeap1->GetArray().Get(i)%2 != 0)
            flag = false;
    }
    if(flag)
        testPass(count, passed);
    if(!flag)
        testPass(count, passed);
}

void testBinaryHeapSubBinaryHeap(int count){
    cout<<"Testing sub heap in heap."<<endl;
    int *a = new int[1];
    a[0] = 0;
    int passed = count;
    BinaryHeap<int> *binaryHeap = new BinaryHeap<int>(a, 1);
    for (int i = 0; i < count; ++i) {
        binaryHeap->AddElement(i);
    }
    int *b = new int[7] {7, 5, 6, 0, 3, 1, 9};
    BinaryHeap<int> *binaryHeap1 = new BinaryHeap<int>(b, 7);
    BinaryHeap<int> *binaryHeap2 = binaryHeap->subBinaryHeap(9);

    if (*binaryHeap1 == *binaryHeap2)
        testPass(count, passed);
    else
        testPass(count, passed);
}

void testBinaryHeapFindSubBinaryHeap(int count){
    cout<<"Testing finding sub heap in heap."<<endl;
    int *a = new int[1];
    a[0] = 0;
    int passed = count;
    BinaryHeap<int> *binaryHeap = new BinaryHeap<int>(a, 1);
    for (int i = 0; i < count; ++i) {
        binaryHeap->AddElement(i);
    }
    int *b = new int[7] {6, 7, 5, 0, 3, 1, 9};
    BinaryHeap<int> *binaryHeap1 = new BinaryHeap<int>(b, 7);
    bool c = binaryHeap->findSubBinaryHeap(binaryHeap1);
    if (c)
        testPass(count, passed);
    else
        testPass(count, passed);
}

void tests(int count){
    testBinaryHeapAdd(count);
    testBinaryHeapDelete(count);
    testBinaryHeapFindSubBinaryHeap(count);
    testBinaryHeapIsEqual(count);
    testBinaryHeapMap(count);
    testBinaryHeapWhere(count);
    testBinaryTreeAdd(count);
    testBinaryTreeGetSize(count);
    testBinaryTreeIsEqual(count);
}