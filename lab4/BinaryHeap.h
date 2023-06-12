//
// Created by Stif on 12.06.2023.
//

#ifndef LAB_4_BINARYHEAP_H
#define LAB_4_BINARYHEAP_H

#endif //LAB_4_BINARYHEAP_H

#include "ArraySequence.h"

template <class T>
class BinaryHeap{
private:
    ArraySequence<T> arraySequence;
    int HeapSize;
public:
    void heapify(int i){
        int leftChild, rightChild, largestChild;

        for (; ; ){
            leftChild = 2 * i + 1;
            rightChild = 2 * i + 2;
            largestChild = i;

            if (leftChild < HeapSize && arraySequence.Get(largestChild) > arraySequence.Get(largestChild))
                largestChild = leftChild;

            if (rightChild < HeapSize && arraySequence.Get(rightChild) > arraySequence.Get(largestChild))
                largestChild = rightChild;

            if (largestChild == i)
                break;

            int temp = arraySequence.Get(i);
            arraySequence.InsertAt(arraySequence.Get(largestChild), i);
            arraySequence.InsertAt(temp, largestChild);
            i = largestChild;
        }
    }

    BinaryHeap(T *array, int count){
        arraySequence = ArraySequence<T>(array, count);
        HeapSize = count;
        for (int i = HeapSize / 2; i >= 0; i--)
            heapify(i);
    }

    BinaryHeap(const ArraySequence<T> &arraySequence1){
        arraySequence = ArraySequence<T>(arraySequence1);
        HeapSize = arraySequence.GetLength();
        for (int i = HeapSize / 2; i >= 0; i--)
            heapify(i);
    }

    BinaryHeap(const BinaryHeap<T> &binaryHeap){
        arraySequence = binaryHeap.arraySequence;
        HeapSize = arraySequence.GetLength();
    }

    void AddElement(T n) {
        arraySequence.Append(n);
        int i = HeapSize - 1;
        int parent = (i - 1) / 2;
        while (i > 0 && arraySequence.Get(parent) < arraySequence.Get(i)){
            int temp = arraySequence.Get(i);
            arraySequence.InsertAt(arraySequence.Get(parent), i);
            arraySequence.InsertAt(temp, parent);
            i = parent;
            parent = (i - 1) / 2;
        }
        HeapSize++;
        for (int i = HeapSize / 2; i >= 0; i--)
            heapify(i);
    }

    int findElement(T a){
        for (int i = 0; i < HeapSize; ++i) {
            if(arraySequence.Get(i) == a)
                return i;
        }
        return -1;
    }

    void deleteElement(T a){
        int b = findElement(a);
        if(b == -1) return;
        arraySequence.InsertAt(arraySequence.GetLast(), b);
        arraySequence.deleteLast();
        HeapSize--;
        for (int i = HeapSize / 2; i >= 0; i--)
            heapify(i);
    }

    BinaryHeap<T> *map(T func(T, T), T b){
        T *a = new T[HeapSize];
        for (int i = 0; i < HeapSize; ++i) {
            a[i] = 0;
        }
        ArraySequence<T> arraySequence1 = ArraySequence<T>(a, HeapSize);
        for (int i = 0; i < HeapSize; ++i) {
            arraySequence1.InsertAt(func(arraySequence.Get(i), b), i);
        }
        BinaryHeap<T> *binaryHeap = new BinaryHeap<T>(arraySequence1);

        return binaryHeap;
    }

    BinaryHeap<T> *where(bool func(T, T), T b){
        ArraySequence<T> arraySequence1 = ArraySequence<T>(arraySequence);
        for (int i = 0; i < arraySequence1.GetLength(); ++i) {
            if(!func(arraySequence1.Get(i), b))
                arraySequence1.deleteElement(i);
        }
        BinaryHeap<T> *binaryHeap = new BinaryHeap<T>(arraySequence1);
        for (int i = binaryHeap->HeapSize / 2; i >= 0; i--)
            binaryHeap->heapify(i);
        return binaryHeap;
    }

    BinaryHeap<T> *subBinaryHeap(T a){
        T *arr = new T[1];
        int b = findElement(a);
        if (b == -1)
            return nullptr;
        arr[0] = a;
        ArraySequence<T> arraySequence1 = ArraySequence<T>(arr, 1);
        for (int i = b, j = 1; i*2 + 1 + j*2 < HeapSize; i = i*2 + 1, j=j*2) {
            for (int k = 0; k < j*2; ++k) {
                arraySequence1.Append(arraySequence.Get(i*2 + 1 + k));
            }
        }

        BinaryHeap<T> *binaryHeap = new BinaryHeap<T>(arraySequence1);
        return binaryHeap;
    }

    friend bool operator==(BinaryHeap binaryHeap, BinaryHeap binaryHeap1){
        bool flag = true;
        if(binaryHeap.HeapSize != binaryHeap1.HeapSize)
            flag = false;
        for (int i = 0; i < binaryHeap.HeapSize; ++i) {
            if(binaryHeap.arraySequence.Get(i) !=binaryHeap1.arraySequence.Get(i))
                flag = false;
        }
        return flag;
    }

    bool findSubBinaryHeap(BinaryHeap<T> *binaryHeap){
        int a = findElement(binaryHeap->arraySequence.GetFirst());
        if (a == -1)
            return false;
        T *arr = new T[1];
        arr[0] = arraySequence.Get(a);
        ArraySequence<T> arraySequence1 = ArraySequence<T>(arr, 1);
        for (int i = a, j = 1; i*2 + 1 + j*2 < HeapSize; i = i*2 + 1, j = j*2) {
            for (int k = 0; k < j*2; ++k) {
                arraySequence1.Append(arraySequence.Get(i*2 + 1 + k));
            }
        }

        BinaryHeap<T> *binaryHeap1 = new BinaryHeap<T>(arraySequence1);
         if (*binaryHeap1 == *binaryHeap)
             return true;
         return false;
    }

    int GetHeapSize(){
        return HeapSize;
    }

    friend std::ostream& operator<<(std::ostream &out, BinaryHeap binaryHeap){
        out<<std::endl;
        int i = 0;
        int k = 1;
        while(i < binaryHeap.HeapSize) {
            for (int j = 0; j < binaryHeap.HeapSize - k; ++j) {
                out<<" ";
            }
            while((i < k) && (i < binaryHeap.HeapSize)) {
                    out << binaryHeap.arraySequence.Get(i) << " ";
                i++;
            }
            out << std::endl;
            k = k * 2 + 1;
        }
        out<<std::endl;
        return out;
    }

    ArraySequence<T> GetArray(){
        return arraySequence;
    }
};