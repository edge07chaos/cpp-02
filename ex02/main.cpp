#include <iostream>
#include <cassert>
#include "Fixed.hpp"

void testSubjectMain(void) {
    std::cout << "=== Subject Main Test ===" << std::endl;
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;
    std::cout << std::endl;
}

void testComparisons(void) {
    std::cout << "=== Comparison Operators Test ===" << std::endl;
    Fixed const a(10);
    Fixed const b(20);
    Fixed const c(10);

    assert(b > a);
    assert(a < b);
    assert(b >= a);
    assert(a >= c);
    assert(a <= b);
    assert(a <= c);
    assert(a == c);
    assert(a != b);

    std::cout << "All comparison assertions passed! ✅" << std::endl << std::endl;
}

void testArithmetic(void) {
    std::cout << "=== Arithmetic Operators Test ===" << std::endl;
    Fixed const a(10.5f);
    Fixed const b(2.0f);

    std::cout << a << " + " << b << " = " << (a + b) << " (Expected: 12.5)" << std::endl;
    std::cout << a << " - " << b << " = " << (a - b) << " (Expected: 8.5)" << std::endl;
    std::cout << a << " * " << b << " = " << (a * b) << " (Expected: 21)" << std::endl;
    std::cout << a << " / " << b << " = " << (a / b) << " (Expected: 5.25)" << std::endl;
    std::cout << std::endl;
}

void testIncrementDecrement(void) {
    std::cout << "=== Increment & Decrement Test ===" << std::endl;
    Fixed a(0);

    std::cout << "Initial a: " << a << std::endl;
    std::cout << "Pre-increment ++a: " << ++a << std::endl;
    std::cout << "Post-increment a++: " << a++ << std::endl;
    std::cout << "After post-increment a: " << a << std::endl;

    std::cout << "Pre-decrement --a: " << --a << std::endl;
    std::cout << "Post-decrement a--: " << a-- << std::endl;
    std::cout << "After post-decrement a: " << a << std::endl;
    std::cout << std::endl;
}

void testMinMax(void) {
    std::cout << "=== Min & Max Functions Test ===" << std::endl;
    
    // Mutable objects
    Fixed a(15.5f);
    Fixed b(42.0f);

    std::cout << "min(a, b): " << Fixed::min(a, b) << " (Expected: 15.5)" << std::endl;
    std::cout << "max(a, b): " << Fixed::max(a, b) << " (Expected: 42)" << std::endl;

    // Const objects
    Fixed const c(100.25f);
    Fixed const d(50.75f);

    std::cout << "const min(c, d): " << Fixed::min(c, d) << " (Expected: 50.75)" << std::endl;
    std::cout << "const max(c, d): " << Fixed::max(c, d) << " (Expected: 100.25)" << std::endl;
    std::cout << std::endl;
}

int main(void) {
    testSubjectMain();
    testComparisons();
    testArithmetic();
    testIncrementDecrement();
    testMinMax();

    std::cout << "🎉 ALL TESTS PASSED SUCCESSFULLY! 🎉" << std::endl;
    return 0;
}