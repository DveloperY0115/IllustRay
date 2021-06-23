/*
 * RayBaseTest.cpp : Unit-test for Ray base class.
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "Ray/RayBase.hpp"

using namespace IllustRay;

TEST_CASE("Testing constructors") {

    // Default constructor initializing all elements to zero.
    SUBCASE("Test default constructor") {
        Ray<float> ray = Ray<float>();
    }

    SUBCASE("Constructors with initial values") {
        std::array<float, 3> pointContainer = { 1.0, 2.0, 3.0 };
        std::array<float, 3> vectorContainer = { 1.0, -1.0, 1.0 };
        Point3Float origin = Point3Float(pointContainer);
        Vector3Float direction = Vector3Float(vectorContainer);
        Ray<float> ray = Ray<float>(origin, direction);

        Point3Float orig = ray.getOrigin();
        Vector3Float dir = ray.getDirection();
        // Point3Float at = ray.at(1.0);
    }
}