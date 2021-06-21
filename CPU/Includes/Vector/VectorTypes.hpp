/*
 * VectorTypes.hpp : Type aliases for various vector classes.
 */

#ifndef ILLUSTRAY_VECTORTYPES_HPP
#define ILLUSTRAY_VECTORTYPES_HPP

namespace IllustRay {

    // 2D Vectors
    using Vector2Double = Vector<double, 2>;
    using Vector2Float = Vector<float, 2>;
    using Vector2Int = Vector<int, 2>;
    using Vector2UInt = Vector<unsigned int, 2>;

    // 3D Vectors
    using Vector3Double = Vector<double, 3>;
    using Vector3Float = Vector<float, 3>;
    using Vector3Int = Vector<int, 3>;
    using Vector3UInt = Vector<unsigned int, 3>;

    // 4D Vectors
    using Vector4Double = Vector<double, 4>;
    using Vector4Float = Vector<float, 4>;
    using Vector4Int = Vector<int, 4>;
    using Vector4UInt = Vector<unsigned int, 4>;

}

#endif //ILLUSTRAY_VECTORTYPES_HPP
