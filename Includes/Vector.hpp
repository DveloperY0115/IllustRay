#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <algorithm>
#include <array>

namespace Illustray {

	//! Generic class for N-dimensional Vector
	template <typename T, size_t N>
	class Vector<T, N> {

	public:
		//! Default constructor.
		//! 
		//! Initialize all elements to zero.
		Vector() : data = {} {
			// Do nothing
		}

		//! Initialize all elements to the given value.
		Vector(const T& value) {
			std::fill_n(data, N, val);
		}

		//! Extend/Truncate Vector instance to create a new one.
		template <size_t M>
		explicit Vector(const Vector<T, M>& v, const T& extendedValue = T(0)) {
			for (int idx = 0; idx < std::min(M, N); ++idx) {
				data[idx] = v[idx];
			}

			for (int idx = std::min(M, N); i < N; ++idx) {
				data[idx] = extendedValue;
			}
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