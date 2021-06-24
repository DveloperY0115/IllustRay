//
// Created by 유승우 on 2021/06/22.
//

#ifndef ILLUSTRAY_POINTBASE_HPP
#define ILLUSTRAY_POINTBASE_HPP

#include <array>

#include "../Vector/Vector.hpp"

namespace IllustRay {

    // Generic class for N-dimensional Point
    template <typename T, size_t N>
    class Point {

    public:
        // Initialize all elements to zero.
        Point() {
            coordinate = std::array<T, N>();
        }

        // Initialize all elements to the given value.
        explicit Point(const T& value) {
            coordinate.fill(value);
        }

        // Initialize elements with values in existing container.
        explicit Point(const std::array<T, N> container) {
            coordinate = container;
        }

        // Copy constructor.
        Point(const Point<T, N>& otherPoint) {
            coordinate = otherPoint.coordinate;
        }

        // Indexing operator.
        T& operator [] (const int index) {
            return coordinate[index];
        }

        // Indexing operator.
        const T& operator [] (const int index) const {
            return coordinate[index];
        }

        // Adding vector to point.
        Point<T, N>& operator += (const Vector<T, N> otherVector) {
            for (int index = 0; index < N; ++index) {
                coordinate[index] += otherVector[index];
            }
            return *this;
        }

        // Subtracting vector from point.
        Point<T, N>& operator -= (const Vector<T, N> otherVector) {
            for (int index = 0; index < N; ++index) {
                coordinate[index] -= otherVector[index];
            }
            return *this;
        }

    private:
        std::array<T, N> coordinate;
    };

    // Point - Point = Vector
    template <typename T, size_t N>
    Vector<T, N> operator - (const Point<T, N>& p1, const Point<T, N>& p2) {
        std::array<T, N> container = std::array<T, N>();

        for (int index = 0; index < N; ++index) {
            container[index] = p1[index] - p2[index];
        }

        return Vector<T, N>(container);
    }

    // Point + Vector = Point
    template <typename T, size_t N>
    Point<T, N> operator + (const Point<T, N>& p1, const Vector<T, N>& v1) {
        std::array<T, N> container = std::array<T, N>();

        for (int index = 0; index < N; ++index) {
            container[index] = p1[index] + v1[index];
        }

        return Point<T, N>(container);
    }

    // Vector + Point = Point
    template <typename T, size_t N>
    Point<T, N> operator + (const Vector<T, N>& v1, const Point<T, N>& p1) {
        return p1 + v1;
    }

    // Point - Vector = Point
    template <typename T, size_t N>
    Point<T, N> operator - (const Point<T, N>& p1, const Vector<T, N>& v1) {
        std::array<T, N> container = std::array<T, N>();

        for (int index = 0; index < N; ++index) {
            container[index] = p1[index] - v1[index];
        }

        return Point<T, N>(container);
    }
    
}

#include "PointTypes.hpp"

#endif //ILLUSTRAY_POINTBASE_HPP
