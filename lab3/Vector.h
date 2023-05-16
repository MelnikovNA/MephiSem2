//
// Created by Stif on 15.05.2023.
//

#ifndef LAB3_VECTOR_H
#define LAB3_VECTOR_H
#include "ArraySequence.h"
#include "IndexOutOfRangeException.h"

template<class T>
class Vector {
private:
    int dimension;
    ArraySequence<T> data;
    size_t elemSize = sizeof(T);
public:
    Vector(){
    }

    Vector(Vector<T> &vector){
        data = ArraySequence<T>(vector.data);
        this->dimension = vector.data.GetLength();
    }

    Vector(T *array, int dim){
        dimension = dim;
        data = ArraySequence<T>(array, dim);
    }

    ~Vector(){
        delete [] data;
    }

    Vector<T> *addVectors(Vector<T> vector){
        if(elemSize!=vector.elemSize)return nullptr;
        ArraySequence<T> arraySequence1;
        T *a;
        if(dimension == vector.dimension||dimension>vector.dimension){
            a = new T[dimension];
            for(int i = 0; i<dimension; i++){
                a[i] = data.Get(i);
            }
            arraySequence1 = ArraySequence<T>(a, dimension);
        } else{
            a = new T[vector.dimension];
            for (int i = 0; i < vector.dimension; ++i) {
                a[i] = vector.arraySequence.Get(i);
            }
            arraySequence1 = ArraySequence<T>(a, vector.dimension);
        }
        int b = dimension;
        if (b>vector.dimension) b = vector.dimension;
        for (int i = 0; i < b; ++i) {
            arraySequence1.InsertAt(vector.arraySequence.Get(i) + data.Get(i), i);
        }
        Vector<T> *vector1 = new Vector<T>(arraySequence1);
        return vector1;
    }

    Vector<T> *subVectors(Vector<T> vector){
        if(elemSize != vector.elementSize) return nullptr;
        ArraySequence<T> arraySequence1;
        T *a;
        if (dimension == vector.dimension || dimension>vector.dimension){
            a = new T[dimension];
            for (int i = 0; i < dimension; ++i) {
                a[i] = data.Get(i);
            }
            arraySequence1 = ArraySequence<T>(a, dimension);
        }else{
            a = new T[vector.dimension];
            for (int i = 0; i < vector.dimension; ++i) {
                a[i] = vector.arraySequence.Get(i);
            }
            arraySequence1 = ArraySequence<T>(a, vector.dimension);
        }
        int b = dimension;
        if (b>vector.dimension) b = vector.dimension;
        for (int i = 0; i < b; ++i) {
            arraySequence1.InsertAt(data.Get(i) - vector.arraySequence.Get(i) , i);
        }
        Vector<T> *vector1 = new Vector<T>(arraySequence1);
        return vector1;
    }

    Vector<T> *multVectors(Vector<T> vector){
        if(elemSize != vector.elementSize) return nullptr;
        ArraySequence<T> arraySequence1;
        T *a;
        if (dimension == vector.dimension || dimension>vector.dimension){
            a = new T[dimension];
            for (int i = 0; i < dimension; ++i) {
                a[i] = data.Get(i);
            }
            arraySequence1 = ArraySequence<T>(a, dimension);
        }else{
            a = new T[vector.dimension];
            for (int i = 0; i < vector.dimension; ++i) {
                a[i] = vector.arraySequence.Get(i);
            }
            arraySequence1 = ArraySequence<T>(a, vector.dimension);
        }
        int b = dimension;
        if (b>vector.dimension) b = vector.dimension;
        for (int i = 0; i < b; ++i) {
            arraySequence1.InsertAt(data.Get(i) * vector.arraySequence.Get(i) , i);
        }
        Vector<T> *vector1 = new Vector<T>(arraySequence1);
        return vector1;
    }

    Vector<T> *scalarMultVector(float  a){
        T *b = new T[dimension];
        ArraySequence<T> arraySequence1 = ArraySequence<T>(b, dimension);
        for (int i = 0; i < dimension; ++i) {
            arraySequence1.InsertAt(data.Get(i)*a, i);
        }
        Vector<T> *vector1 = new Vector<T>(arraySequence1);
        return vector1;
    }

    friend std::ostream& operator<<(std::ostream &out, Vector &vector){
        out<<"{";
        for (int i = 0; i < vector.dimension - 1; ++i) {
            out<<vector.arraySequence.Get(i)<<", ";
        }
        out<<vector.arraySequence.Get(vector.dimension-1)<<"}"<<std::endl;
        return out;
    }

};


#endif //LAB3_VECTOR_H
