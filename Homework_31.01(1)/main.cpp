#include "Libraries.h"

struct Complex {
    double real;
    double imaginary;
};

Complex add(Complex num1, Complex num2) {
    Complex result;
    result.real = num1.real + num2.real;
    result.imaginary = num1.imaginary + num2.imaginary;
    return result;
}

Complex subtract(Complex num1, Complex num2) {
    Complex result;
    result.real = num1.real - num2.real;
    result.imaginary = num1.imaginary - num2.imaginary;
    return result;
}

Complex multiply(Complex num1, Complex num2) {
    Complex result;
    result.real = (num1.real * num2.real) - (num1.imaginary * num2.imaginary);
    result.imaginary = (num1.real * num2.imaginary) + (num1.imaginary * num2.real);
    return result;
}

Complex divide(Complex num1, Complex num2) {
    Complex result;
    double denominator = (num2.real * num2.real) + (num2.imaginary * num2.imaginary);
    result.real = (num1.real * num2.real + num1.imaginary * num2.imaginary) / denominator;
    result.imaginary = (num1.imaginary * num2.real - num1.real * num2.imaginary) / denominator;
    return result;
}

int main() {
    setlocale(LC_ALL, "RU");

    Complex num1 = { 2.0, 3.0 };
    Complex num2 = { 1.0, -2.0 };

    Complex sum = add(num1, num2);
    Complex difference = subtract(num1, num2);
    Complex product = multiply(num1, num2);
    Complex quotient = divide(num1, num2);

    cout << "Сумма: " << sum.real << " + " << sum.imaginary << "i" << endl;
    cout << "Разность: " << difference.real << " + " << difference.imaginary << "i" << endl;
    cout << "Произведение: " << product.real << " + " << product.imaginary << "i" << endl;
    cout << "Частное: " << quotient.real << " + " << quotient.imaginary << "i" << endl;

    return 0;
}
