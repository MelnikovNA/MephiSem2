#ifndef LAB_2_TEST_H
#define LAB_2_TEST_H

#endif //LAB_2_TEST_H

#include "Matrix.h"
#include "iostream"

using namespace std;

void isAllRight(bool a){
    if(a){
        cout<<"Test passed successfully."<<endl;
    } else{
        cout<<"Something went wrong"<<endl;
    }
}

void testMatrixGetElement(){
    bool m = true;
    int *a = new int[9];
    for (int i = 0; i < 9; ++i) {
        a[i] = i+1;
    }
    Matrix<int> matrix = Matrix<int>(a, 3,3);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
           if(matrix.GetElement(i,j) != i*matrix.GetLength() + j);
        }
    }
    isAllRight(m);
}

void testMatrixSum(){
    bool m = true;
    int *a = new int[9];
    for (int i = 0; i < 9; ++i) {
        a[i] = i+1;
    }
    int *b = new int[9];
    for (int i = 0; i < 9; ++i) {
        b[i] = i+1;
    }
    Matrix<int> matrix1 = Matrix<int>(a, 3,3);
    Matrix<int> *matrix2 = new Matrix<int>(b, 3,3);
    Matrix<int> *matrix = matrix1.sumMatrices(matrix2);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(matrix->GetElement(i,j) != i*matrix1.GetLength() + j + i*matrix2->GetLength() + j);
        }
    }
    isAllRight(m);
}

void testMatrixSub(){
    bool m = true;
    int *a = new int[9];
    for (int i = 0; i < 9; ++i) {
        a[i] = i+1;
    }
    int *b = new int[9];
    for (int i = 0; i < 9; ++i) {
        b[i] = i+1;
    }
    Matrix<int> matrix1 = Matrix<int>(a, 3,3);
    Matrix<int> *matrix2 = new Matrix<int>(b, 3,3);
    Matrix<int> *matrix = matrix1.sumMatrices(matrix2);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if(matrix->GetElement(i,j) != 0);
        }
    }
    isAllRight(m);
}

void testMatrixMult(){
    bool m = true;
    int *a = new int[9];
    for (int i = 0; i < 9; ++i) {
        a[i] = i+1;
    }
    int *b = new int[9];
    for (int i = 0; i < 9; ++i) {
        b[i] = i+1;
    }
    Matrix<int> matrix1 = Matrix<int>(a, 3,3);
    Matrix<int> *matrix2 = new Matrix<int>(b, 3,3);
    Matrix<int> *matrix = matrix1.sumMatrices(matrix2);
    isAllRight(m);
}

void matrixTests(){
    cout<<"Sum: ";
    testMatrixSum();
    cout<<"Sub: ";
    testMatrixSub();
    cout<<"Mult: ";
    testMatrixMult();
    cout<<"GetElement: ";
    testMatrixGetElement();
}