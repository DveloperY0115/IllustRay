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

    private:
        std::array<T, N> coordinate;
    };
}

#include "PointTypes.hpp"

#endif //ILLUSTRAY_POINTBASE_HPP
