#include <iostream>
#include <cassert>
#include "Point.hpp"

void testIsoscelesTriangle() {
    std::cout << "=== Isosceles Triangle Test Suite ===" << std::endl;

    // Define Isosceles Triangle: A(-5,0), B(5,0), C(0,10)
    Point const a(-5.0f, 0.0f);
    Point const b(5.0f, 0.0f);
    Point const c(0.0f, 10.0f);

    // 1. Strictly inside points
    Point const center(0.0f, 3.0f);       // On line of symmetry
    Point const insideLeft(-2.0f, 2.0f);  // Left side
    Point const insideRight(2.0f, 2.0f);  // Right side (symmetric to insideLeft)

    // 2. Points on edges/vertices (Must return false!)
    Point const vertexC(0.0f, 10.0f);
    Point const baseMidpoint(0.0f, 0.0f);
    Point const sideMidpoint(2.5f, 5.0f); // Midpoint of BC

    // 3. Points strictly outside
    Point const outsideTop(0.0f, 12.0f);
    Point const outsideBelow(0.0f, -1.0f);
    Point const outsideRight(6.0f, 1.0f);

    // Assertions
    assert(bsp(a, b, c, center) == true);
    assert(bsp(a, b, c, insideLeft) == true);
    assert(bsp(a, b, c, insideRight) == true);

    assert(bsp(a, b, c, vertexC) == false);
    assert(bsp(a, b, c, baseMidpoint) == false);
    assert(bsp(a, b, c, sideMidpoint) == false);

    assert(bsp(a, b, c, outsideTop) == false);
    assert(bsp(a, b, c, outsideBelow) == false);
    assert(bsp(a, b, c, outsideRight) == false);

    std::cout << "Inside Center (0,3):     " << bsp(a, b, c, center) << " (Expected: 1)" << std::endl;
    std::cout << "Symmetric Left (-2,2):   " << bsp(a, b, c, insideLeft) << " (Expected: 1)" << std::endl;
    std::cout << "Symmetric Right (2,2):   " << bsp(a, b, c, insideRight) << " (Expected: 1)" << std::endl;
    std::cout << "Base Midpoint (0,0):     " << bsp(a, b, c, baseMidpoint) << " (Expected: 0)" << std::endl;
    std::cout << "Side Midpoint (2.5,5):   " << bsp(a, b, c, sideMidpoint) << " (Expected: 0)" << std::endl;
    std::cout << "Outside Top (0,12):      " << bsp(a, b, c, outsideTop) << " (Expected: 0)" << std::endl;

    std::cout << "\n🎉 ALL ISOSCELES TRIANGLE TESTS PASSED! 🎉" << std::endl;
}

int main(void) {
    testIsoscelesTriangle();
    return 0;
}