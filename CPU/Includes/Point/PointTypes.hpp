//
// Created by 유승우 on 2021/06/22.
//

#ifndef ILLUSTRAY_POINTTYPES_HPP
#define ILLUSTRAY_POINTTYPES_HPP

namespace IllustRay {

    // 2D Points
    template <typename T>
    using Point2 = Point<T, 2>;
    using Point2Double = Point<double, 2>;
    using Point2Float = Point<float, 2>;
    using Point2Int = Point<int, 2>;
    using Point2UInt = Point<unsigned int, 2>;

    // 3D Points
    template <typename T>
    using Point3 = Point<T, 3>;
    using Point3Double = Point<double, 3>;
    using Point3Float = Point<float, 3>;
    using Point3Int = Point<int, 3>;
    using Point3UInt = Point<unsigned int, 3>;

    // 4D Points
    template <typename T>
    using Point4 = Point<T, 4>;
    using Point4Double = Point<double, 4>;
    using Point4Float = Point<float, 4>;
    using Point4Int = Point<int, 4>;
    using Point4UInt = Point<unsigned int, 4>;

}
#endif //ILLUSTRAY_POINTTYPES_HPP
