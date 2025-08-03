#include<iostream>
using namespace std;

struct Complex {
    double real, imag;
};

Complex setComplex(double r, double i);
void printComplex(Complex c);
Complex operator + (Complex c1 , Complex c2);
Complex operator - (Complex c1 , Complex c2);

int main(){
    Complex a, b, c, d;
    a = setComplex(1.0, 1.0);
    b = setComplex(2.0, 2.0);

    c = a + b;
    d = b + c - a;
    
    cout << "c = ";
    printComplex(c);
    cout << "d = ";
    printComplex(d);
    
    return 0;
}

Complex setComplex(double r, double i){
    Complex temp;
    temp.real = r;
    temp.imag = i;
    return temp;
}

void printComplex(Complex t){
    cout << "(" << t.real << ", " << t.imag << ")" << endl;
}

Complex operator + (Complex c1 , Complex c2){
    Complex temp;
    temp.real = c1.real + c2.real;
    temp.imag = c1.imag + c2.imag;
    return temp;
}

Complex operator - (Complex c1 , Complex c2){
    Complex temp;
    temp.real = c1.real - c2.real;
    temp.imag = c1.imag - c2.imag;
    return temp;
}
