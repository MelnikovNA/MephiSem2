//
// Created by Stif on 16.05.2023.
//
#include "vecfunc.h"

template<class T>
void createVector(ArraySequence<Vector<T>*> *array, int dimension){
    cout<<endl;
    cout<<"Input 1 coordinate:";
    T a = getNumber(a);
    T *r = new T[1];
    r[0] = a;
    ArraySequence<T> *arraySequence = new ArraySequence<T>(r, 1);
    for (int i = 0; i < dimension-1; ++i) {
        cout<<"Input "<<i + 2 <<" coordinate:";
        arraySequence->Append(getNumber(a));
    }
    auto *vector = new Vector<T>(*arraySequence);
    cout<<"This is your new vector: "<<*vector;
    array->Append(vector);
};

void createRandomIntVector(ArraySequence<Vector<int>*> *vectorInt, int dimension){
    int *a = new int[dimension];
    for (int i = 0; i < dimension; ++i) {
        a[i] = randomInt();
    }
    auto *vector = new Vector<int>(a, dimension);
    cout<<"This is your new vector: "<<vector;
    vectorInt->Append(vector);
}

void createRandomFloatVector(ArraySequence<Vector<float>*> *vectorFloat, int dimension){
    float *a = new float[dimension];
    for (int i = 0; i < dimension; ++i) {
        a[i] = randomFloat();
    }
    Vector<float> *vector = new Vector<float>(a, dimension);
    cout<<"This is your new vector: "<<vector;
    vectorFloat->Append(vector);
}

void createRandomComplexVector(ArraySequence<Vector<complex<float>>*> *vectorComplex, int dimension){
    float *a = new float[dimension];
    float *b = new float[dimension];
    for (int i = 0; i < dimension; ++i) {
        a[i] = randomFloat();
        b[i] = randomFloat();
    }
    complex<float> *c = new complex<float>[dimension];
    for (int i = 0; i < dimension; ++i) {
        c[i] = complex<float>(a[i],b[i]);
    }
    Vector<complex<float>> *vector = new Vector<complex<float>>(c, dimension);
    cout<<"This is your new vector: "<<vector;
    vectorComplex->Append(vector);
}

void getVector(ArraySequence<Vector<int>*> *vectorInt, ArraySequence<Vector<float>*> *vectorFloat, ArraySequence<Vector<complex<float>>*> *vectorComplex){
    cout<<"---------";
    int ch;
    cout<<endl;
    cout<<"What type of vector do you want?"<<endl;
    cout<<"1. Int."<<endl;
    cout<<"2. Float."<<endl;
    cout<<"3. Complex."<<endl;
    int a = GetInt(1, 3);

    cout<<"Input vector dimension: ";
    int dimension = GetInt();

    cout<<"How do you want to input your vector?"<<endl;
    cout<<"1. Randomly."<<endl;
    cout<<"2. By myself."<<endl;
    ch = GetInt(1, 2);

    switch (a) {
        case 1:
            if(ch==1) {
                createRandomIntVector(vectorInt, dimension);
            }else{
                createVector(vectorInt,dimension);
            }
            break;
        case 2:
            if (ch==1){
                createRandomFloatVector(vectorFloat, dimension);
            }else{
                createVector(vectorFloat, dimension);
            }
            break;
        case 3:
            if (ch==1){
                createRandomComplexVector(vectorComplex, dimension);
            }else{
                createVector(vectorComplex, dimension);
            }
            break;
        default: break;
    }
    cout<<"---------"<<endl;
}

template<class T>
void printVectorsFromMemory(ArraySequence<Vector<T>*> *arraySequence){
    for (int i = 0; i < arraySequence->GetLength(); ++i) {
        cout<<i+1<<": ";
        cout<<"{";
        if(arraySequence->Get(i)->GetDimension()<4){
            for (int j = 0; j < arraySequence->Get(i)->GetDimension(); ++j) {
                if(j!=0) cout<<", ";
                cout<<arraySequence->Get(i)->GetCoordinate(j+1);
            }
            cout<<"}";
        }else{
            for (int j = 0; j < 3; ++j) {
                cout<<arraySequence->Get(i)->GetCoordinate(j+1)<<", ";
            }
            cout<<"...}";
        }
        cout<<" | ";
    }
    cout<<endl;
}

void showAvailableVector(ArraySequence<Vector<int>*> *vectorInt, ArraySequence<Vector<float>*> *vectorFloat, ArraySequence<Vector<complex<float>>*> *vectorComplex){
    cout<<"---------";
    cout<<"What type do you want to look at?"<<endl;
    cout<<"1. Int."<<endl;
    cout<<"2. Float."<<endl;
    cout<<"3. Complex."<<endl;
    int a = GetInt(1, 3);
    switch (a) {
        case 1:
            printVectorsFromMemory(vectorInt);
            break;
        case 2:
            printVectorsFromMemory(vectorFloat);
            break;
        case 3:
            printVectorsFromMemory(vectorComplex);
            break;
        default: break;
    }
    cout<<"---------"<<endl;
}