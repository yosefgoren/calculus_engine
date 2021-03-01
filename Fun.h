#ifndef FUN
#define FUN
#include "list"
#include "memory"
#include "string"
#include "Num.h"


using std::string;
typedef const string& csr;
class Fun;
typedef std::unique_ptr<Fun> pFun;

class Fun
{
public:
    virtual string expression() = 0;
    virtual pFun derive(csr dv="") = 0;
    //virtual pFun& operator()(pFun f) = 0;
};

class Identity : public Fun
{
public:
    Identity(csr var_name="x");
    string expression();
    pFun derive(csr dv="");
private:
    string var_name;
};

class Constant : public Fun
{
public:
    Constant(Num num);
    string expression();
    pFun derive(csr dv="");
private:
    Num num;
};

class DoubleComposition : public Fun
{
public:
    DoubleComposition(pFun f1, pFun f2);
    pFun derive(csr dv="");
protected:
    pFun f1;
    pFun f2;
    string p_expression(csr marking);
};

class Add : public DoubleComposition
{
public:
    using DoubleComposition::DoubleComposition;
    string expression();
    pFun derive(csr dv="");
};

class Mult : public DoubleComposition
{
public:
    using DoubleComposition::DoubleComposition;
    string expression();
    pFun derive(csr dv="");
};

// class Power : public DoubleComposition
// {
// public:
//     using DoubleComposition::DoubleComposition;
//     string expression();
//     Mult derive(csr dv="");
// };

#endif