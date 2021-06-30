set(CMAKE_CXX_STANDARD 17)

# Includes
include_directories(Includes)

# Subdirectories
add_subdirectory(Tests)

# Main executable
add_executable (Illustray_CPU
        "Illustray.cpp" "Illustray.h"
        "Includes/Vector/VectorBase.hpp" "Includes/Types.hpp" Includes/Vector/Vector2.hpp Includes/Vector/Vector3.hpp Includes/Vector/Vector4.hpp
        Includes/Ray/RayBase.hpp Includes/Vector/VectorTypes.hpp Includes/Point/PointBase.hpp Includes/Vector/Vector.hpp Includes/Point/Point.hpp Includes/Point/PointTypes.hpp Includes/MathUtils.hpp Includes/Geometry/Geometry.hpp Includes/Geometry/Sphere.hpp Includes/Ray/Ray.hpp Includes/Ray/RayTypes.hpp)