//
// Created by 유승우 on 2021/06/30.
//

#ifndef ILLUSTRAY_MATHUTILS_HPP
#define ILLUSTRAY_MATHUTILS_HPP

#include <cmath>
#include <limits>
#include <iomanip>
#include <iostream>
#include <type_traits>
#include <algorithm>

namespace IllustRay {
    template <typename T>
    typename std::enable_if<!std::numeric_limits<T>::is_integer, bool>::type
    equals(T x, T y) {
        return std::fabs(x - y) <= std::numeric_limits<T>::epsilon();
    }
}

#endif //ILLUSTRAY_MATHUTILS_HPP
