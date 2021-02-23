#include "Fun.h"


Identity::Identity(csr var_name):var_name(var_name){}
string Identity::expression()
{
    return var_name;
}
Fun Identity::derive(const string& dv)
{
    return (dv=="" || var_name==dv) ? Constant(Num(1)) : Constant(Num(0));
}

Constant::Constant(Num num):num(num){}
string Constant::expression()
{
    return num.expression();
}
Fun Constant::derive(csr dv)
{
    return Constant(Num(0));
}


Add::Add(const Fun& f1, const Fun& f2):f1(f1),f2(f2){}
string Add::expression()
{
    return "("+f1.expression()+")+("+f2.expression()+")";
}
Fun Mult::derive(csr dv)
{
    return Add(f1.derive(dv),f2.derive(dv));
}


Mult::Mult(const Fun& f1, const Fun& f2):f1(f1),f2(f2){}
string Mult::expression()
{
    return "("+f1.expression()+")*("+f2.expression()+")";
}
Fun Mult::derive(csr dv)
{
    return Add(Mult(f1.derive(dv),f2),Mult(f1,f2.derive(dv)));
}

Power::Power(const Fun& f1, const Fun& f2):f1(f1),f2(f2){}
string Power::expression()
{
    return "("+f1.expression()+")^("+f2.expression()+")";
}
// Fun Power::derive(csr dv)
// {
//     return ??
// }


