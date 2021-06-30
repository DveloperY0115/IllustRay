/*
 * Geometry.hpp
 */

#ifndef ILLUSTRAY_GEOMETRY_HPP
#define ILLUSTRAY_GEOMETRY_HPP

#include "../Point/Point.hpp"
#include "../Ray/Ray.hpp"

namespace IllustRay {

    template <typename T>
    class Geometry {

        virtual bool hit(const RayFloat& r, float t_near, float t_far, hit_record& record) const = 0;
    };

    struct hit_record {
        Point3Float hitPoint;
        Vector3Float hitPointNormal;
        float t;
    };
}

#endif //ILLUSTRAY_GEOMETRY_HPP
