set(CMAKE_CXX_STANDARD 11)

# Includes
include_directories(Includes)

# Subdirectories
add_subdirectory(Tests)

# Main executable
add_executable (Illustray_CPU
        "Illustray.cpp" "Illustray.h"
        "Includes/Vector/Vector.hpp" "Includes/Types.hpp" Includes/Vector/Vector2.hpp Includes/Vector/Vector3.hpp Includes/Vector/Vector4.hpp
        )