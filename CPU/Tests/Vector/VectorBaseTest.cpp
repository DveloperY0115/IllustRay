/*
 * VectorBaseTest.cpp : Unit-test for Vector base class.
 */

#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "Vector/VectorBase.hpp"

using namespace IllustRay;

TEST_CASE("Testing constructors") {

    // Default constructor initializing all elements to zero.
    SECTION("Test default constructor") {
        Vector<float, 3> v = Vector<float, 3>();
        REQUIRE((v[0] == 0 && v[1] == 0 && v[2] == 0));
    }

        // Constructor initializing all elements to the given value.
    SECTION("Initialize with single value") {
        Vector<float, 100> v = Vector<float, 100>(1.0);
        bool isOne = true;
        for (int i = 0; i < 100; ++i) {
            if (v[i] != 1.0) {
                isOne = false;
                break;
            }
        }
        REQUIRE(isOne);
    }

        // Constructor initializing all elements with values in the container.
    SECTION("Initialize with container") {
        std::array<double, 4> container = {1.0, 2.0, 3.0, 4.0};
        Vector<double, 4> v = Vector<double, 4>(container);
        REQUIRE((v[0] == 1.0 && v[1] == 2.0 && v[2] == 3.0 && v[3] == 4.0));
    }

        // Copy constructor.
    SECTION("Copy constructor") {
        std::array<double, 4> container = {1.0, 2.0, 3.0, 4.0};
        Vector<double, 4> v1 = Vector<double, 4>(container);
        Vector<double, 4> v2 = Vector<double, 4>(v1);
        REQUIRE((v2[0] == 1.0 && v2[1] == 2.0 && v2[2] == 3.0 && v2[3] == 4.0));
    }
}

TEST_CASE("Testing unary operators") {

    // Vector negation.
    SECTION("Vector negation") {
        Vector2Int v = Vector2Int(1);
        v = -v;
        REQUIRE((v[0] == -1 && v[1] == -1));
    }

    // Vector addition.
    SECTION("Vector addition") {
        std::array<float, 3> container1 = {1.0, 3.0, 4.0};
        std::array<float, 3> container2 = {-1.0, 1.0, 2.0};
        Vector3Float v1 = Vector3Float(container1);
        Vector3Float v2 = Vector3Float(container2);
        v1 += v2;
        REQUIRE((v1[0] == 0 && v1[1] == 4.0 && v1[2] == 6.0));
    }

    // Vector subtraction.
    SECTION("Vector subtraction") {
        std::array<float, 3> container1 = {1.0, 3.0, 4.0};
        std::array<float, 3> container2 = {-1.0, 1.0, 2.0};
        Vector3Float v1 = Vector3Float(container1);
        Vector3Float v2 = Vector3Float(container2);
        v1 -= v2;
        REQUIRE((v1[0] == 2.0 && v1[1] == 2.0 && v1[2] == 2.0));
    }

    // Element-wise vector multiplication.
    SECTION("Element-wise vector multiplication") {
        std::array<float, 3> container1 = {1.0, 3.0, 4.0};
        std::array<float, 3> container2 = {-1.0, 1.0, 2.0};
        Vector3Float v1 = Vector3Float(container1);
        Vector3Float v2 = Vector3Float(container2);
        v1 *= v2;
        REQUIRE((v1[0] == -1.0 && v1[1] == 3.0 && v1[2] == 8.0));
    }

    // Element-wise scalar multiplication.
    SECTION("Element-wise scalar multiplication") {
        double s = 10.0;
        Vector3Double v = Vector3Double(2.0);
        v *= s;
        REQUIRE((v[0] == 20.0 && v[1] == 20.0 && v[2] == 20.0));
    }

    // Element-wise scalar division.
    SECTION("Element-wise scalar division") {
        double s = 2.0;
        Vector2Float v = Vector2Float(1.0);
        v /= s;
        REQUIRE((v[0] == 0.5 && v[1] == 0.5));
    }

    // Norms & Normalization
    SECTION("Various norms") {
        std::array<double, 3> container = {1.0, 2.0, 3.0};
        Vector3Double v = Vector3Double(container);
        REQUIRE(v.ManhattanNorm() == 6.0);
        REQUIRE(v.EuclideanNorm() == std::sqrt(1.0 + 2.0 * 2.0 + 3.0 * 3.0));

        v = v.normalize();
        REQUIRE(v.EuclideanNorm() == 1.0);
    }
}

TEST_CASE("Testing binary operators") {

    // Binary vector addition
    SECTION("Vector addition") {
        Vector3Float v1 = Vector3Float(1.0);
        Vector3Float v2 = Vector3Float(2.0);
        Vector3Float v3 = v1 + v2;
        REQUIRE((v3[0] == 3.0 && v3[1] == 3.0 && v3[2] == 3.0));
    }

    // Binary vector subtraction
    SECTION("Vector subtraction") {
        Vector3Float v1 = Vector3Float(1.0);
        Vector3Float v2 = Vector3Float(2.0);
        Vector3Float v3 = v1 - v2;
        REQUIRE((v3[0] == -1.0 && v3[1] == -1.0 && v3[2] == -1.0));
    }

    // Element-wise vector multiplication
    SECTION("Element-wise vector multiplication") {
        Vector3Float v1 = Vector3Float(2.0);
        Vector3Float v2 = Vector3Float(2.0);
        Vector3Float v3 = v1 * v2;
        REQUIRE((v3[0] == 4.0 && v3[1] == 4.0 && v3[2] == 4.0));
    }

    // Scalar multiplication
    SECTION("Scalar multiplication") {
        Vector3Float v1 = Vector3Float(2.0);
        Vector3Float v2 = static_cast<float>(2.0) * v1;
        Vector3Float v3 = v1 * static_cast<float>(2.0);
        REQUIRE((v2[0] == 4.0 && v2[1] == 4.0 && v2[2] == 4.0));
        REQUIRE((v3[0] == 4.0 && v3[1] == 4.0 && v3[2] == 4.0));
    }

    // Scalar division
    SECTION("Scalar division") {
        Vector3Float v1 = Vector3Float(2.0);
        Vector3Float v2 = v1 / static_cast<float>(2.0);
        REQUIRE((v2[0] == 1.0 && v2[1] == 1.0 && v2[2] == 1.0));
    }

    // Unit vector
    SECTION("Make unit vector") {
        Vector3Float v1 = Vector3Float(10.0);
        Vector3Float v2 = unitVector(v1);
        REQUIRE(Approx(v2.EuclideanNorm()) == 1.0);
    }

    // Dot product
    SECTION("Dot product") {
        Vector3Float v1 = Vector3Float(2.0);
        Vector3Float v2 = Vector3Float(3.0);
        double result = dot(v1, v2);
        REQUIRE(result == 18.0);
    }

    // Cross product
    SECTION("Cross product") {
        std::array<float, 3> v1Container = {1.0, 2.0, 3.0};
        std::array<float, 3> v2Container = {3.0, 2.0, 1.0};
        Vector3Float v1 = Vector3Float(v1Container);
        Vector3Float v2 = Vector3Float(v2Container);
        Vector3Float result = cross(v1, v2);
        REQUIRE((result[0] == -4.0 && result[1] == 8.0 && result[2] == -4.0));
    }

    // Reflection
    SECTION("Reflect") {
        std::array<float, 3> v1Container = {1.0, 2.0, 3.0};
        Vector3Float n = Vector3Float(1.0);
        Vector3Float v1 = Vector3Float(v1Container);
        Vector3Float v2 = reflect(v1, n);
        REQUIRE((v2[0] == -11.0 && v2[1] == -10.0 && v2[2] == -9.0));
    }
}