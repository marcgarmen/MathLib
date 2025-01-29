#include <iostream>
#include "MyMathLib.h"
#include "BasicMath.h"
#include "AdvancedMath.h"

int main() {
    std::cout << "==== Welcome to the Math Library Program ====" << std::endl;

    // Prueba de raíz cuadrada
    try {
        std::cout << "Sqrt(9) = " << mySqrt(9) << std::endl;
        std::cout << "Sqrt(16) = " << mySqrt(16) << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Pruebas de operaciones básicas
    std::cout << "Addition (5 + 3): " << BasicMath::add(5, 3) << std::endl;
    std::cout << "Subtraction (5 - 3): " << BasicMath::subtract(5, 3) << std::endl;
    std::cout << "Multiplication (5 * 3): " << BasicMath::multiply(5, 3) << std::endl;
    try {
        std::cout << "Division (6 / 3): " << BasicMath::divide(6, 3) << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Pruebas de operaciones avanzadas
    try {
        std::cout << "Factorial of 5: " << AdvancedMath::factorial(5) << std::endl;
        std::cout << "Combination of 5 choose 3: " << AdvancedMath::combination(5, 3) << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "==== Program End ====" << std::endl;

    return 0;
}
