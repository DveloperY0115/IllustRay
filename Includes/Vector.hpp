#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <algorithm>
#include <array>

namespace IllustRay {

	//! Generic class for N-dimensional Vector
	template <typename T, size_t N>
	class Vector {

	public:
		//! Default constructor.
		//! 
		//! Initialize all elements to zero.
		Vector() {
			data = std::array<T, N>();
		}

		//! Initialize all elements to the given value.
		Vector(const T& value) {
			std::fill_n(data, N, val);
		}

		T& operator [] (const int idx) {
			return data[idx];
		}

		const T& operator [] (const int idx) const {
			return data[idx];
		}


	private:
		std::array<T, N> data;
	};
}
#endif