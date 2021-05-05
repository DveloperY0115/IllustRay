// Illustray.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "Includes/Vector.hpp"

int main()
{
	Illustray::Vector<int, 3> vec3 = Illustray::Vector<int, 3>();

	std::cout << vec3[0] << " " << vec3[1] << " " << vec3[2] << "\n";
}
