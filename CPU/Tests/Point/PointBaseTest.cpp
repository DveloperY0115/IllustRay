/*
 * PointBaseTest.cpp : Unit-test for Point base class.
 */

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "Point/PointBase.hpp"

using namespace IllustRay;

TEST_CASE("[PointBase] Testing constructors") {

    // Default constructor initializing all coordinates to zero.
    SUBCASE("Test default constructor") {
        Point3Float p = Point3Float();
        REQUIRE((p[0] == 0.0 && p[1] == 0.0 && p[2] == 0.0));
    }

    SUBCASE("Constructors with initial values") {
        Point2Double p1 = Point2Double(1.0);
        REQUIRE((p1[0] == 1.0 && p1[1] == 1.0));

        std::array<float, 2> container = { 1.0, 2.0 };
        Point2Float p2 = Point2Float(container);
        REQUIRE((p2[0] == 1.0 && p2[1] == 2.0));
    }

    SUBCASE("Copy constructor") {
        Point2Double p1 = Point2Double(1.0);
        Point2Double p2 = Point2Double(p1);
        REQUIRE((p1[0] == p2[0] && p1[1] == p2[1]));
    }
}

TEST_CASE("[PointBase] Testing unary operators") {

    SUBCASE("Add vector to point") {
        std::array<float, 3> pointContainer = { 1.0, 2.0, 3.0 };
        std::array<float, 3> vectorContainer = {-1.0, 1.0, 2.0};
        Point3Float p = Point3Float(pointContainer);
        Vector3Float v = Vector3Float(vectorContainer);
        p += v;
        REQUIRE((p[0] == 0.0 && p[1] == 3.0 && p[2] == 5.0));
    }

    SUBCASE("Subtract vector from point") {
        std::array<float, 3> pointContainer = { 1.0, 2.0, 3.0 };
        std::array<float, 3> vectorContainer = {-1.0, 1.0, 2.0};
        Point3Float p = Point3Float(pointContainer);
        Vector3Float v = Vector3Float(vectorContainer);
        p -= v;
        REQUIRE((p[0] == 2.0 && p[1] == 1.0 && p[2] == 1.0));
    }
}

TEST_CASE("[PointBase] Testing binary operators") {

    // Point - Point = Vector
    SUBCASE("Point - Point") {
        std::array<double, 3> pointContainer1 = {2.0, 3.0, 4.0};
        std::array<double, 3> pointContainer2 = {1.0, 5.0, 2.0};
        Point3Double p1 = Point3Double(pointContainer1);
        Point3Double p2 = Point3Double(pointContainer2);
        Vector3Double v1 = p1 - p2;
        Vector3Double v2 = p2 - p1;
        REQUIRE((v1[0] == 1.0 && v1[1] == -2.0 && v1[2] == 2.0));
        REQUIRE((v2[0] == -1.0 && v2[1] == 2.0 && v2[2] == -2.0));
    }

    // Point + Vector = Point & Vector + Point = Point
    SUBCASE("Point + Vector") {
        std::array<float, 3> pointContainer = { 1.0, 2.0, 3.0 };
        std::array<float, 3> vectorContainer = {-1.0, 1.0, 2.0};
        Point3Float p0 = Point3Float(pointContainer);
        Vector3Float v = Vector3Float(vectorContainer);
        Point3Float p1 = p0 + v;
        Point3Float p2 = v + p0;
        REQUIRE((p1[0] == 0.0 && p1[1] == 3.0 && p1[2] == 5.0));
        REQUIRE((p2[0] == 0.0 && p2[1] == 3.0 && p2[2] == 5.0));
    }

    // Point - Vector = Point
    SUBCASE("Point + Vector") {
        std::array<float, 3> pointContainer = { 1.0, 2.0, 3.0 };
        std::array<float, 3> vectorContainer = {-1.0, 1.0, 2.0};
        Point3Float p0 = Point3Float(pointContainer);
        Vector3Float v = Vector3Float(vectorContainer);
        Point3Float p1 = p0 - v;
        REQUIRE((p1[0] == 2.0 && p1[1] == 1.0 && p1[2] == 1.0));
    }
}