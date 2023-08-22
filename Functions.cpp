#include <iostream>
using namespace std;

double cube (double n) {
    return n * n * n;
}
double second (double d) {
    return d * d - 5 * d - 4;
}
double fun (double d) {
    return d * d - 3 * d - 4;
}

class Function {
public:
    virtual double evaluateAt(double value) = 0;
};

class SimpleFunction:public Function {
    double (*pointer)(double);
public:
    SimpleFunction(double(*function)(double)){
        pointer = function;
    }
    double evaluateAt(double value){
        return pointer(value);
    }
};


class CompositionFunction: public Function {
    double (*pointer)(double);
    double (*pointer2)(double);
public:
    CompositionFunction(double(*function1)(double), double(*function2)(double)){
        pointer = function2;
        pointer2 = function1;
    }
    double evaluateAt(double value){
        double x = pointer(value);
        return pointer2(x);
    }
};

class DerivativeFunction: public Function {
    double (*pointer)(double);
    double delta_x;
public:
    DerivativeFunction(double(*function)(double), double num){
        delta_x = num;
        pointer = function;
    }
    double evaluateAt(double value){
        double Sum = value + delta_x;
        double Sub = value - delta_x;
        double SumFun = pointer(Sum);
        double SubFun = pointer(Sub);
        return ((SumFun-SubFun)/(2*delta_x));
    }
};

int main(){
    SimpleFunction f1 ([](double n) -> double {return n * n;});
    cout << f1.evaluateAt(5) << endl;
    DerivativeFunction f2 (second, 5);
    cout << f2.evaluateAt(5) << endl;
    CompositionFunction f3 (fun, cube);
    cout << f3.evaluateAt(5) << endl;
    return 0;
}

