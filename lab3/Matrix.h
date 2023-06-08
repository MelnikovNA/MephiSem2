#ifndef LAB_2_MATRIX_H
#define LAB_2_MATRIX_H

#endif //LAB_2_MATRIX_H
#include "ArraySequence.h"

template <class T>
class Matrix{
private:
    int length;
    int height;
    size_t elementSize = sizeof(T);
    ArraySequence<T> arraySequence;
public:
    Matrix(){}

    Matrix(T* array, int len, int hei){
        arraySequence = ArraySequence<T>(array, len*hei);
        length = len;
        height = hei;
    }

    Matrix(const ArraySequence<T> arraySequence1, int len, int hei){
        length = len;
        height = hei;
        arraySequence = arraySequence1;
    }

    Matrix<T> *sumMatrices(Matrix<T> *matrix){
        if(elementSize!=matrix->elementSize)
            return nullptr;
        if(length!=matrix->length||height!=matrix->height)
            return nullptr;
        T *a = new T[length*height];
        for (int i = 0; i < length*height; ++i) {
            a[i] = arraySequence.Get(i) + matrix->arraySequence.Get(i);
        }
        Matrix<T> *matrix1 = new Matrix<T>(a, length, height);
        return matrix1;
    }

    Matrix<T> *subMatrices(Matrix<T> *matrix){
        if(elementSize!=matrix->elementSize)
            return nullptr;
        if(length!=matrix->length||height!=matrix->height)
            return nullptr;
        T *a = new T[length*height];
        for (int i = 0; i < length*height; ++i) {
            a[i] = arraySequence.Get(i) - matrix->arraySequence.Get(i);
        }
        Matrix<T> *matrix1 = new Matrix<T>(a, length, height);
        return matrix1;
    }

    void scalarMultMatrix(float b){
        for (int i = 0; i < length*height; ++i) {
            arraySequence.InsertAt(arraySequence.Get(i)*b, i);
        }
    }

    Matrix<T> *multMatrices(Matrix<T> *matrix){
        if(elementSize!=matrix->elementSize) return nullptr;
        if(height!=matrix->length) return nullptr;
        T *a = new T[matrix->length*height];
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < matrix->height; ++j) {
                a[i*matrix->length + j] = 0;
                for (int k = 0; k < height; ++k) {
                    a[i*matrix->length + j] = a[i*matrix->length + j] + arraySequence.Get(i*length + k) * matrix->arraySequence.Get(k*matrix->length + j);
                }
            }
        }
        Matrix<T> *matrix1 = new Matrix<T>(a, matrix->length, height);
        return matrix1;
    }

    void changeLines(int first, int second){
        if(first<1||first>height||second<1||second>height) throw IndexOutOfRange();
        for (int i = 0; i < length; ++i) {
            arraySequence.changeElements((first-1)*length + i, (second-1)*length + i);
        }
    }

    void multLine(int line, float a){
        if(line<1||line>height) throw IndexOutOfRange();
        for (int i = 0; i < length; ++i) {
            arraySequence.InsertAt(arraySequence.Get((line-1)*length+i)*a, (line-1)*length+i);
        }
    }

    void addLineToLine(int first, int second){
        if(first<1||first>height||second<1||second>height) throw IndexOutOfRange();
        for (int i = 0; i < length; ++i) {
            arraySequence.InsertAt(arraySequence.Get((first-1)*length + i) + arraySequence.Get((second-1)*length + i), (first-1)*length+i);
        }
    }

    void subLineToLine(int first, int second){
        if(first<1||first>height||second<1||second>height) throw IndexOutOfRange();
        for (int i = 0; i < length; ++i) {
            arraySequence.InsertAt(arraySequence.Get((first-1)*length + i) - arraySequence.Get((second-1)*length + i), (first-1)*length+i);
        }
    }


    friend std::ostream& operator<<(std::ostream &out, Matrix &matrix){
        out<<""<<std::endl;
        for (int i = 0; i < matrix.height; ++i) {
            for (int j = 0; j < matrix.length; ++j) {
                out<<matrix.arraySequence.Get(i*matrix.length + j)<<" ";
            }
           out<<""<<std::endl;
        }
        return out;
    }

    int GetLength(){
        return length;
    }

    int GetHeight(){
        return height;
    }

    T GetElement(int i, int j){
        return arraySequence.Get(i*length + j);
    }
};