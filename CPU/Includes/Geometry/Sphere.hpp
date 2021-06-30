//
// Created by 유승우 on 2021/06/30.
//

#ifndef ILLUSTRAY_SPHERE_HPP
#define ILLUSTRAY_SPHERE_HPP

#include "Geometry.hpp"

namespace IllustRay {

    class Sphere: Geometry {

        /*
         * Intersection test for sphere.
         */
        final bool hit(const RayFloat& r, float t_near, float t_far, hit_record& record) {

        }
    };

}

#endif //ILLUSTRAY_SPHERE_HPP
