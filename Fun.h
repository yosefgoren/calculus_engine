#ifndef FUN
#define FUN
#include "list"
#include "Tree.h"
#include "string"
#include "Num.h"

using std::string;
typedef const string& csr;

class Fun
{
public:
    string expression();
    Fun derive(csr dv="");
};

class Identity : public Fun
{
public:
    Identity(csr var_name="x");
    string expression();
    Fun derive(csr dv="");
private:
    string var_name;
};

class Constant : public Fun
{
public:
    Constant(Num num);
    string expression();
    Fun derive(csr dv="");
private:
    Num num;
};

//make these virtual classes?
// class SingleComposition
// {
// };

// class DoubleComposition
// {
// };

class Add : public Fun
{
public:
    Add(const Fun& f1, const Fun& f2);
    string expression();
    Fun derive(csr dv="");
private:
    Fun f1;
    Fun f2;
};

class Mult : public Fun
{
public:
    Mult(const Fun& f1, const Fun& f2);
    string expression();
    Fun derive(csr dv="");
private:
    Fun f1;
    Fun f2;  
};

class Power : public Fun
{
public:
    Power(const Fun& f1, const Fun& f2);
    string expression();
    Fun derive(csr dv="");

private:
    Fun f1;
    Fun f2;
};

#endif