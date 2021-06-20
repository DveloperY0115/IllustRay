#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <algorithm>
#include <array>
#include <cmath>

namespace IllustRay {

	//! Generic class for N-dimensional Vector
	template <typename T, size_t N>
	class Vector {

	public:

		// Initialize all elements to zero.
		Vector() {
			data = std::array<T, N>();
		}

		// Initialize all elements to the given value.
		Vector(const T& value) {
			data.fill(value);
		}

		// Copy constructor.
		Vector(const Vector<T, N>& otherVector) {
		    data = otherVector.data;
		}

		// Indexing operator.
		T& operator [] (const int index) {
			return data[index];
		}

		// Indexing operator.
		const T& operator [] (const int index) const {
			return data[index];
		}

		// Vector negation.
        Vector<T, N> operator - () const {

		    Vector<T, N> result = Vector<T, N>(*this);

		    for (int index = 0; index < N; ++index) {
		        result.data[index] *= -1;
		    }

		    return result;
		}

		// Vector addition.
		Vector<T, N>& operator += (const Vector<T, N> otherVector) {

		    for (int index = 0; index < N; ++index) {
		        this->data[index] += otherVector.data[index];
		    }

		    return *this;
		}

		// Vector subtraction.
		Vector<T, N>& operator -= (const Vector<T, N> otherVector) {

            for (int index = 0; index < N; ++index) {
                this->data[index] -= otherVector.data[index];
            }

            return *this;
		}

		// Element-wise vector multiplication.
		Vector<T, N>& operator *= (const Vector<T, N> otherVector) {

		    for (int index = 0; index < N; ++index) {
		        this->data[index] *= otherVector.data[index];
		    }

		    return *this;
		}

        // Element-wise vector division.
        Vector<T, N>& operator /= (const Vector<T, N> otherVector) {

            for (int index = 0; index < N; ++index) {
                this->data[index] /= otherVector.data[index];
            }

            return *this;
        }

        // Element-wise scalar multiplication.
        Vector<T, N>& operator *= (const T value) {

            for (int index = 0; index < N; ++index) {
                this->data[index] *= value;
            }

            return *this;
		}

        // Element-wise scalar division.
        Vector<T, N>& operator /= (const T value) {

		    T reciprocalValue = 1 / value;

            for (int index = 0; index < N; ++index) {
                this->data[index] *= reciprocalValue;
            }

            return *this;
        }

        // Manhattan norm (L1 norm) of vector.
        double ManhattanNorm() {

		    double norm = 0;

            for (int index = 0; index < N; ++index) {
                norm += std::abs(this->data[index]);
            }

            return norm;
		}

        // Euclidean norm (L2 norm) of vector.
        double EuclideanNorm() {

		    double norm = 0;

		    for (int index = 0; index < N; ++index) {
		        norm += this->data[index] * this->data[index];
		    }

		    return std::sqrt(norm);
		}

		// Make a vector to have unit length in terms of Euclidean distance.
		void normalize() {
		    double norm = this->EuclideanNorm();

            for (int index = 0; index < N; ++index) {
                this->data[index] /= norm;
            }
		}

	private:
		std::array<T, N> data;
	};
}
#endif