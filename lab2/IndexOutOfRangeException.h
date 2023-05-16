//
// Created by Stif on 05.05.2023.
//

#ifndef LAB2_INDEXOUTOFRANGEEXCEPTION_H
#define LAB2_INDEXOUTOFRANGEEXCEPTION_H


typedef enum {
    Empty,
    Invalid,
} ErrCode;

class IndexOutOfRangeException{
    ErrCode error;
    const char* text[2] = {"Sequence is empty", "Sequence doesn't have element with that index"};

public:
    void printError()
    {
        std::cout << text[(int) error] << std::endl;
    }
    IndexOutOfRangeException(ErrCode er) : error(er) {};
};

#endif //LAB2_INDEXOUTOFRANGEEXCEPTION_H
