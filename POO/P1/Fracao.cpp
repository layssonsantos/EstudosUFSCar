#include "Fracao.h"

Fracao::Fracao(float a, float b): a(a), b(b){
};

float Fracao::getA(){
    return a;
}

float Fracao::getB(){
    return b;
}

void Fracao::setA(float a){
    this -> a = a;
}

void Fracao::setB(float b){
    this -> b = b;
}

Fracao Fracao::operator-(Fracao z)
{
    Fracao t(a,b);
    t.a = a * z.b - z.a * b;
    t.b = b * z.b;
    return t;
}

Fracao Fracao::operator/(Fracao z)
{
    Fracao t(a, b);
    t.a = (a * z.b);
    t.b = (b * z.a); 
    return t;
}

bool Fracao::operator==(Fracao z) {
    bool x;
    if (a == z.a && b == z.b)
        x = true;
    else {
        x = false;
    }
    return x;
}

ostream &operator<<(ostream &os, Fracao &z) {
    os << z.a << "/" << z.b << endl;
    return os;
}