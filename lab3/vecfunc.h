//
// Created by Stif on 16.05.2023.
//

#ifndef LAB3_VECFUNC_H
#define LAB3_VECFUNC_H
#include "SupInstruments.h"
#include "Vector.h"

template<typename T>
void createVector(ArraySequence<Vector<T>*> *array, int dimension);

void createRandomIntVector(ArraySequence<Vector<int>*> *vectorInt, int dimension);

void createRandomFloatVector(ArraySequence<Vector<float>*> *vectorFloat, int dimension);

void createRandomComplexVector(ArraySequence<Vector<complex<float>>*> *vectorComplex, int dimension);

void getVector(ArraySequence<Vector<int>*> *vectorInt, ArraySequence<Vector<float>*> *vectorFloat, ArraySequence<Vector<complex<float>>*> *vectorComplex);

template<class T>
void printVectorsFromMemory(ArraySequence<Vector<T>*> *arraySequence);

#endif //LAB3_VECFUNC_H
