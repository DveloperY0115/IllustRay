/*
 * RayBase.hpp : Base class for ray used throughout rendering pipeline.
 */

#ifndef ILLUSTRAY_RAYBASE_HPP
#define ILLUSTRAY_RAYBASE_HPP

#include "../Point/Point.hpp"
#include "../Vector/Vector.hpp"

namespace IllustRay {

    template <typename T>
    class Ray {

    public:
        Ray() = default;

        Ray(const Point3<T>& origin, const Vector3<T>& direction)
                : origin(origin), direction(direction)
        {
            // Do nothing
        }

        Point3<T> getOrigin() const {
            return origin;
        }

        Vector3<T> getDirection() const {
            return direction;
        }

        Point3<T> at(T t) const {
            return origin + t * direction;
        }

    private:
        Point3<T> origin;
        Vector3<T> direction;
    };

}
#endif //ILLUSTRAY_RAYBASE_HPP
