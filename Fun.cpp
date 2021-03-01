#include "Fun.h"
#include "memory"
using std::make_unique;

Identity::Identity(csr var_name):var_name(var_name){}
string Identity::expression()
{
    return var_name;
}
pFun Identity::derive(const string& dv)
{
    return (dv=="" || var_name==dv) ? make_unique<Fun>(Constant(Num(1))) : make_unique<Fun>(Constant(Num(0)));
}

Constant::Constant(Num num):num(num){}
string Constant::expression()
{
    return num.expression();
}
pFun Constant::derive(csr dv)
{
    return make_unique<Fun>(Constant(Num(0)));
}

DoubleComposition::DoubleComposition(pFun f1, pFun f2):f1(f1),f2(f2){}
string DoubleComposition::p_expression(csr marking)
{
    return "("+f1->expression()+")"+marking+"("+f2->expression()+")";
}

pFun Add::derive(csr dv)
{
    return Add(f1->derive(dv),f2->derive(dv));
}
string Add::expression()
{
    return p_expression("+");
}

string Mult::expression()
{
    return p_expression("*");
}
pFun Mult::derive(csr dv)
{
    return make_unique<Fun>(Add(make_unique<Fun>(Mult(f1->derive(dv),f2)),make_unique<Fun>(Mult(f1,f2->derive(dv)))));
}

// string Power::expression()
// {
//     return p_expression("^");
// }
// Fun Power::derive(csr dv)
// {
//     return 
// }


