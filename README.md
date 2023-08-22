# FunctionsApp

Function Solver. Build a set of classes that allow you to build and modify functions at runtime using
tools similar to those in the STL <functional> library. We have the following abstract class:
class Function
{
 public:
 virtual double evaluateAt(double value) = 0;
};
This class exports a single function, evaluateAt, that accepts a double as a parameter and returns the
value of some function evaluated at that point. Write these derived classes of Function and test them:
 SimpleFunction, whose constructor accepts a regular C++ function or a lambda function that
accepts and returns a double and whose evaluateAt function returns the value of the stored
function evaluated at the parameter.
 The composition of two functions F and G is defined as F(G(x)), i.e. function F is applied to the
value of G applied to x. Write a class CompositionFunction whose constructor accepts two
functions and whose evaluateAt returns the composition of the two functions evaluated at x.
 The derivative of a function is the slope of the tangent line to that function at a point. The derivative
of a function F can be approximated as F'(x) ≈ (F(x + Δx) – F(x - Δx)) / 2Δx for small values of Δx.
Write a class DerivativeFunction whose constructor accepts a function and a double
representing Δx and whose evaluateAt approximates the derivative of the stored function using
the initial value of Δx.
With these functions, it will be possible to write code like this:
double cube (double n) {
 return n * n * n;
}
double second (double d) {
 return d * d - 5 * d - 4;
}
double fun (double d) {
 return d * d - 3 * d - 4;
}
int main()
{
 SimpleFunction f1
 ([](double n) ->
 double {return n * n;});
 cout << f1.evaluateAt(5) << endl;
 DerivativeFunction f2 (second, 5);
 cout << f2.evaluateAt(5) << endl;

 CompositeFunction f3 (fun, cube);
 cout << f3.evaluateAt(5) << endl;
 return 0;
}
