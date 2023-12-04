#ifndef FRACAO_H
#define FRACAO_H
#include <string>
#include<iostream>

using namespace std;

class Fracao {
    private:
        float a, b; // A = numerador e B = denominador
    public:
        Fracao(float a, float b);
        float getA();
        float getB();
        void setA(float a);
        void setB(float b);
        Fracao operator-(Fracao z);
        Fracao operator/(Fracao z);
        bool operator==(Fracao z);
        friend ostream &operator<<(ostream &os, Fracao &z);
};


#endif // FRACAO_H