#include <iostream>
#include "Point.hpp"

void checkTest(const char *testName, bool result, bool expected) {
    if (result == expected) {
        std::cout << "[PASS ✅] " << testName << std::endl;
    } else {
        std::cout << "[FAIL ❌] " << testName 
                  << " (Got: " << result << ", Expected: " << expected << ")" 
                  << std::endl;
    }
}

void testIsoscelesTriangle() {
    std::cout << "=== Isosceles Triangle Test Suite ===" << std::endl;

    // Triangle: A(-5,0), B(5,0), C(0,10)
    Point const a(-5.0f, 0.0f);
    Point const b(5.0f, 0.0f);
    Point const c(0.0f, 10.0f);

    // Test points
    Point const center(0.0f, 3.0f);
    Point const insideLeft(-2.0f, 2.0f);
    Point const insideRight(2.0f, 2.0f);

    Point const vertexC(0.0f, 10.0f);
    Point const baseMidpoint(0.0f, 0.0f);
    Point const sideMidpoint(2.5f, 5.0f);

    Point const outsideTop(0.0f, 12.0f);
    Point const outsideBelow(0.0f, -1.0f);
    Point const outsideRight(6.0f, 1.0f);

    // Execution & Verification
    checkTest("Inside Center (0,3)    ", bsp(a, b, c, center), true);
    checkTest("Symmetric Left (-2,2)  ", bsp(a, b, c, insideLeft), true);
    checkTest("Symmetric Right (2,2)  ", bsp(a, b, c, insideRight), true);

    checkTest("Vertex C (0,10)        ", bsp(a, b, c, vertexC), false);
    checkTest("Base Midpoint (0,0)   ", bsp(a, b, c, baseMidpoint), false);
    checkTest("Side Midpoint (2.5,5) ", bsp(a, b, c, sideMidpoint), false);

    checkTest("Outside Top (0,12)     ", bsp(a, b, c, outsideTop), false);
    checkTest("Outside Below (0,-1)   ", bsp(a, b, c, outsideBelow), false);
    checkTest("Outside Right (6,1)    ", bsp(a, b, c, outsideRight), false);

    std::cout << "\n🎉 ALL ISOSCELES TRIANGLE TESTS COMPLETED! 🎉" << std::endl;
}

int main(void) {
    testIsoscelesTriangle();
    return 0;
}