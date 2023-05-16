//
// Created by Stif on 16.05.2023.
//

#ifndef LAB3_SUPINSTRUMENTS_H
#define LAB3_SUPINSTRUMENTS_H
#include <iostream>
#include <complex>
using namespace std;

int GetInt();
int GetInt(int lower, int upper);

template<typename T>
T getNumber();

complex<float>getNumber(complex<float> a);

int randomInt();
float randomFloat();
complex<float> randomComplex();

ostream& operator << (ostream& cout, complex<float> com);

#endif //LAB3_SUPINSTRUMENTS_H
