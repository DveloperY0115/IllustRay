/*
 * Vector3.hpp
 */


#ifndef ILLUSTRAY_VECTOR3_HPP
#define ILLUSTRAY_VECTOR3_HPP

namespace IllustRay {

    // Cross product.
    // Note that cross product is defined for 3D vector only.
    template <typename T>
    Vector3<T> cross(const Vector3<T>& v1, const Vector3<T>& v2) {
        std::array<T, 3> container = std::array<T, 3>();
        container[0] = v1[1] * v2[2] - v1[2] * v2[1];
        container[1] = -(v1[0] * v2[2] - v1[2] * v2[0]);
        container[2] = v1[0] * v2[1] - v1[1] * v2[0];

        return Vector<T, 3>(container);
    }
}

#endif //ILLUSTRAY_VECTOR3_HPP
