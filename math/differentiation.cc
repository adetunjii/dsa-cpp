#include <iostream>
#include <cmath>

double f(double x) {
	return std::pow(3*x*x + 2 * x, 5);
}

double derivative(double (*f)(double), double x) {
	constexpr double h = 1e-5;
	return (f(x + h) - f(x-h)) / (2*h);
}

int main() {
	double x = 2.0;
	double result = derivative(f, x);

	std::cout << "df/dx: " << result << std::endl;
	return 0;
}
