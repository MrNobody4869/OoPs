#include <iostream>
using namespace std;

class Complex {
    float real, imag;

public:
    // Default constructor
    Complex() : real(0), imag(0) {}

    // Parameterized constructor
    Complex(float r, float i) : real(r), imag(i) {}

    // Overload + operator
    Complex operator+(const Complex& c) {
        return Complex(real + c.real, imag + c.imag);
    }

    // Overload * operator
    Complex operator*(const Complex& c) {
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }

    // Overload >> operator
    friend istream& operator>>(istream& input, Complex& c) {
        cout << "Enter real part: ";
        input >> c.real;
        cout << "Enter imaginary part: ";
        input >> c.imag;
        return input;
    }

    // Overload << operator
    friend ostream& operator<<(ostream& output, const Complex& c) {
        output << c.real << " + " << c.imag << "i";
        return output;
    }
};

int main() {
    Complex c1, c2, c3;
    cout << "Enter first complex number:\n";
    cin >> c1;
    cout << "Enter second complex number:\n";
    cin >> c2;

    c3 = c1 + c2;
    cout << "Addition: " << c3 << endl;

    c3 = c1 * c2;
    cout << "Multiplication: " << c3 << endl;

    return 0;
}
