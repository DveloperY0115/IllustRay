// Illustray.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "Includes/Vector.hpp"

int main()
{
	IllustRay::Vector<float, 3> vec1 = IllustRay::Vector<float, 3>(2.0);
	IllustRay::Vector<float, 3> vec2 = IllustRay::Vector<float, 3>(1.0);

	IllustRay::Vector<float, 3> vec = IllustRay::Vector<float, 3>(vec1);
	vec += vec2;
	std::cout << vec[0] << " " << vec[1] << " " << vec[2] << "\n";

	vec = -vec2;
    std::cout << vec[0] << " " << vec[1] << " " << vec[2] << "\n";

    vec.normalize();
    std::cout << vec[0] << " " << vec[1] << " " << vec[2] << "\n";

    std::cout << vec.EuclideanNorm() << "\n";
}