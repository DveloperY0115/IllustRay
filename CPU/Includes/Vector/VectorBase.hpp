/*
 * VectorBase.hpp : Base class for vectors.
 */

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
		explicit Vector(const T& value) {
			data.fill(value);
		}

		// Initialize elements with values in existing container.
		explicit Vector(const std::array<T, N> container) {
		    data = container;
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
		Vector<T, N>& normalize() {

		    double norm = this->EuclideanNorm();

            for (int index = 0; index < N; ++index) {
                this->data[index] /= norm;
            }

            return *this;
		}

	private:
		std::array<T, N> data;
	};



	// Binary vector addition.
	template <typename T, size_t N>
	Vector<T, N> operator + (const Vector<T, N>& v1, const Vector<T, N>& v2) {

	    std::array<T, N> container = std::array<T, N>();

	    for (int index = 0; index < N; ++index) {
            container[index] = v1[index] + v2[index];
	    }

	    return Vector<T, N>(container);
	}

	// Binary vector subtraction.
	template <typename T, size_t N>
	Vector<T, N> operator - (const Vector<T, N>& v1, const Vector<T, N>& v2) {

        std::array<T, N> container = std::array<T, N>();

        for (int index = 0; index < N; ++index) {
            container[index] = v1[index] - v2[index];
        }

        return Vector<T, N>(container);
	}

	// Binary element-wise vector multiplication.
	template <typename T, size_t N>
	Vector<T, N> operator * (const Vector<T, N>& v1, const Vector<T, N>& v2) {

        std::array<T, N> container = std::array<T, N>();

        for (int index = 0; index < N; ++index) {
            container[index] = v1[index] * v2[index];
        }

        return Vector<T, N>(container);
	}

	// Binary scalar multiplication.
	template <typename T, size_t N>
	Vector<T, N> operator * (T s, const Vector<T, N>& v) {

        std::array<T, N> container = std::array<T, N>();

        for (int index = 0; index < N; ++index) {
            container[index] = s * v[index];
        }

        return Vector<T, N>(container);
	}

	template <typename T, size_t N>
	Vector<T, N> operator * (const Vector<T, N>& v, T s) {
	    return s * v;
	}

	// Binary scalar division.
	template <typename T, size_t N>
	Vector<T, N> operator / (const Vector<T, N>& v, T s) {
	    return (1 / s) * v;
	}

	// Make unit vector from existing vector.
	template <typename T, size_t N>
	Vector<T, N> unitVector(Vector<T, N> v) {
	    return v / static_cast<T>(v.EuclideanNorm());
	}

	// Dot product.
	template <typename T, size_t N>
	float dot(const Vector<T, N>& v1, const Vector<T, N>& v2) {

	    float result = 0;

	    for (int index = 0; index < N; ++index) {
	        result += static_cast<float>(v1[index]) * static_cast<float>(v2[index]);
	    }

	    return result;
	}

	// Cross product.
	// Note that cross product is defined for 3D vector only.
	template <typename T>
	Vector<T, 3> cross(const Vector<T, 3>& v1, const Vector<T, 3>& v2) {

	    std::array<T, 3> container = std::array<T, 3>();
	    container[0] = v1[1] * v2[2] - v1[2] * v2[1];
	    container[1] = -(v1[0] * v2[2] - v1[2] * v2[0]);
	    container[2] = v1[0] * v2[1] - v1[1] * v2[0];

	    return Vector<T, 3>(container);
	}

	// Reflect operator.
	// Calculate perfect mirror reflection of passed vector.
	template <typename T, size_t N>
	Vector<T, N> reflect(const Vector<T, N>& v, const Vector<T, N>& n) {
	    return v - 2 * dot(v, n) * n;
	}
}

#include "VectorTypes.hpp"
#include "Vector2.hpp"
#include "Vector3.hpp"
#include "Vector4.hpp"

#endif