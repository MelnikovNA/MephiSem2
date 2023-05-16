//
// Created by Stif on 16.05.2023.
//

#include "SupInstruments.h"


int GetInt(){
    int a;
    cin>>a;
    if (a<1){
        cout<<"Number is out of range. Try again:";
        GetInt();
    }
    return a;
}

int GetInt(int lower, int upper){
    int a;
    cout<<"Input number: ";
    cin>>a;
    if(a>upper||a<lower){
        cout<<"Number is out of range, try again"<<endl;
        GetInt(lower, upper);
    }
    return a;
}

template<typename T>
T getNumber(T a){
    T b;
    cin>>b;
    return b;
}

complex<float>getNumber(complex<float> a){
    float b, c;
    cout<<endl;
    cout<<"Input real part: ";
    cin>>b;
    cout<<"Input imaginary part: ";
    cin>>c;
    complex<float> num = complex<float>(b,c);
    return num;
}

int randomInt() {
    return rand()%1000;
}

float randomFloat() {
    return static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100));
}

complex<float> randomComplex() {
    return complex<float>(randomFloat(), randomFloat());
}

ostream& operator << (ostream& cout, complex<float> com){
    if (com.imag() == 0) return cout << com.real();
    if (com.real() != 0) {
        cout << com.real();
    }
    if (com.imag() > 0) {
        if (com.real() != 0)
            cout << '+';
        if (com.imag() != 1)
            cout << com.imag();
        return cout << 'i';
    }
    else {
        if (com.imag() == -1)
            return cout << "-i";
        return cout << com.imag() << 'i';
    }
}