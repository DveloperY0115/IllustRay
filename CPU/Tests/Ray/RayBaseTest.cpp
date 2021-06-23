/*
 * RayBaseTest.cpp : Unit-test for Ray base class.
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "Ray/RayBase.hpp"

using namespace IllustRay;

// TODO: Make Catch 2 detect multiple test sources
TEST_CASE("Testing constructors") {

    // Default constructor initializing all elements to zero.
    SUBCASE("Test default constructor") {
        Point3<float> p = Point3<float>();
        CHECK((p[0] == 0 && p[1] == 0 && p[2] == 0));
    }
}