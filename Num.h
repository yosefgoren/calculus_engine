#ifndef NUM
#define NUM
#include "string"
#include "stdlib.h"

class Num
{
public:
    Num(int num):num(num){}
    std::string expression(){return std::to_string(num);}
private:
    int num;
};

#endif