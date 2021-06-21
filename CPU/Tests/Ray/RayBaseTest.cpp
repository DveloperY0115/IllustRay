/*
 * RayBaseTest.cpp : Unit-test for Ray base class.
 */

#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "Ray/RayBase.hpp"

using namespace IllustRay;

// TODO: Make Catch 2 detect multiple test sources
TEST_CASE("Testing constructors") {

    // Default constructor initializing all elements to zero.
    SECTION("Test default constructor") {
        Point3<float> p = Point3<float>();
        REQUIRE((p[0] == 0 && p[1] == 0 && p[2] == 0));
    }
}