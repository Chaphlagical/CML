#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "vec.h"
#include "matrix.h"

namespace Chaf
{
	namespace cml
	{
		template<typename T>
		struct transform
		{
			inline static vec<T, 3>trans(const vec<T, 3>& v, const mat<T, 4, 4>& mat)
			{
				vec<T, 3> res;
				for (size_t i = 0; i < 3; i++)
					for (size_t j = 0; j < 3; j++)
						res[i] += v[j] * mat(i, j);
				for (size_t i = 0; i < 3; i++)res[i] += mat(i, 3);
				return res;
			}

			inline static mat<T, 4, 4> transMatrix(const mat<T, 4, 4>& translation, const mat<T, 4, 4>& rotation, const mat<T, 4, 4>& scale)
			{
				return translation * rotation * scale;
			}

			inline static mat<T, 4, 4> transMatrix(const vec<T, 3>& translation, const mat<T, 3, 3>& rotation, const vec<T, 3>& scale)
			{
				return mat<T, 4, 4>{
					{ rotation(0, 0)* scale[0], rotation(0, 1), rotation(0, 2), translation[0] },
					{ rotation(1,0), rotation(1,1) * scale[1], rotation(1,2),translation[1] },
					{ rotation(2,0),rotation(2,1), rotation(2,2) * scale[2],translation[2] },
					{ 0,0,0,1 }
				};
			}

			inline static mat<T, 4, 4> scale(const T& x, const T& y, const T& z)
			{
				return mat<T, 4, 4>{
					{x, 0, 0, 0},
					{ 0,y,0,0 },
					{ 0,0,z,0 },
					{ 0,0,0,1 }
				};
			}

			inline static mat<T, 4, 4> scale(const vec<T, 3>& v)
			{
				return scale(v[0], v[1], v[2]);
			}

			inline static vec<T, 3> scale(const vec<T, 3>& v, const T& x, const T& y, const T& z)
			{
				vec<T, 3> res;
				res = v[0] * x;
				res = v[1] * y;
				res = v[2] * z;
				return res;
			}

			inline static vec<T, 3> scale(const vec<T, 3>& v, const vec<T, 3>& scale_vec)
			{
				return scale(v, scale_vec[0], scale_vec[1], scale_vec[2]);
			}

			inline static mat<T, 4, 4> translation(const T& x, const T& y, const T& z)
			{
				return mat<T, 4, 4>{
					{ 1, 0, 0, x },
					{ 0, 1, 0, y },
					{ 0, 0, 1, z },
					{ 0, 0, 0, 1 }
				};
			}

			inline static mat<T, 4, 4> translation(const vec<T, 3>& v)
			{
				return translation(v[0], v[1], v[2]);
			}

			inline static vec<T, 3> translation(const vec<T, 3>& v, const T& x, const T& y, const T& z)
			{
				vec<T, 3> res;
				res[0] = v[0] + x;
				res[1] = v[1] + y;
				res[2] = v[2] + z;
				return res;
			}

			inline static void translation(const vec<T, 3>& v, const vec<T, 3>& translation_vec)
			{
				return translation(v, translation_vec[0], translation_vec[1], translation_vec[2]);
			}

			inline static mat<T, 4, 4> rotation(const T& angle, const vec<T, 3>& axis)
			{
				auto naxis = static_cast<vec<T, 3>>(axis).normalize();
				return mat<T, 4, 4>{
					{naxis[0] * naxis[0] * (1 - std::cos(angle)) + std::cos(angle),
						naxis[0] * naxis[1] * (1 - std::cos(angle)) - naxis[2] * std::sin(angle),
						naxis[0] * naxis[2] * (1 - std::cos(angle)) + naxis[1] * std::sin(angle), 0},

					{ naxis[1] * naxis[0] * (1 - std::cos(angle)) + naxis[2] * std::sin(angle),
						naxis[1] * naxis[1] * (1 - std::cos(angle)) + std::cos(angle),
						naxis[1] * naxis[2] * (1 - std::cos(angle)) - naxis[0] * std::sin(angle),0 },

					{ naxis[2] * naxis[0] * (1 - std::cos(angle)) - naxis[1] * std::sin(angle),
						naxis[2] * naxis[1] * (1 - std::cos(angle)) + naxis[0] * std::sin(angle),
						naxis[2] * naxis[2] * (1 - std::cos(angle)) + std::cos(angle),0 },

					{ 0, 0, 0, 1 }
				};
			}

			inline static vec<T, 3> rotation(const vec<T, 3>& v, const T& angle, const vec<T, 3>& axis)
			{
				vec<T, 3>res;
				res = transform::trans(v, rotation(angle, axis));
				return res;
			}

			inline static mat<T, 4, 4> rotationQuat(const vec<T, 3>& angle)
			{
				// Euler to Quarternion; I will fix this in the future
				T x = to_radians(angle[0]) / 2;
				T y = to_radians(angle[1]) / 2;
				T z = to_radians(angle[2]) / 2;

				T cX = std::cos(x); T cY = std::cos(y); T cZ = std::cos(z);
				T sX = std::sin(x); T sY = std::sin(y); T sZ = std::sin(z);

				T w = cX * cY * cZ + sX * sY * sZ;
				T ix = sX * cY * cZ + cX * sY * sZ;
				T iy = cX * sY * cZ - sX * cY * sZ;
				T iz = cX * cY * sZ - sX * sY * cZ;

				// calculate rotation matrix
				T xx = ix * ix;
				T xy = ix * iy;
				T xz = ix * iz;
				T xw = ix * w;
				T yy = iy * iy;
				T yz = iy * iz;
				T yw = iy * w;
				T zz = iz * iz;
				T zw = iz * w;

				return {
					{ 1 - 2 * (yy + zz), 2 * (xy - zw), 2 * (xz + yw), 0 },
					{2 * (xy + zw), 1 - 2 * (zz + xx),2 * (yz - xw),0 },
					{2 * (xz - yw),2 * (yz + xw),1 - 2 * (xx + yy),0},
					{0, 0, 0, 1}
				};
			}

			inline static mat<T, 4, 4> rotationQuat(const vec<T, 3>& v, const vec<T, 3>& angle)
			{
				vec<T, 3>res;
				res = transform::trans(v, rotationQuat(angle));
				return res;
			}

			inline static mat<T, 4, 4> lookAt(const point<T, 3>& position, const point<T, 3>& target, const vec<T, 3> up)
			{
				vec<T, 3> zAxis = (position - target).normalize();
				vec<T, 3> xAxis = static_cast<vec<T, 3>>(up).cross(zAxis).normalize();
				vec<T, 3> yAxis = zAxis.cross(xAxis);
				return mat<T, 4, 4>{
					{ xAxis[0], xAxis[1], xAxis[2], -xAxis.dot(position.cast<vec<T, 3>>()) },
					{ yAxis[0], yAxis[1], yAxis[2], -yAxis.dot(position.cast<vec<T,3>>()) },
					{ zAxis[0], zAxis[1], zAxis[2], -zAxis.dot(position.cast<vec<T,3>>()) },
					{ 0, 0, 0,1 }
				};
			}

			inline static mat<T, 4, 4> perspective(const T& fov, const T& aspect, const T& near, const T& far)
			{
				auto rfov = to_radians<T>(fov);
				return{
					{1 / (aspect * std::tan(rfov / 2)), 0, 0, 0},
					{0,1 / (std::tan(rfov / 2)), 0, 0},
					{0, 0, -(far + near) / (far - near), 0},
					{0, 0, -1, 0}
				};
			}

			inline static mat<T, 4, 4> ortho(const T& left, const T& right, const T& bottom, const T& top, const T& near, const T& far)
			{
				return {
					{2 / (right - left), 0, 0, 0},
					{0, 2 / (top - bottom, 0, 0)},
					{0, 0, -2 / (far - near), -(far + near) / (far - near)},
					{0, 0, 0, 1}
				};
			}
		};

		using transformf = transform<float>;
		using transformi = transform<int>;
		using transformu = transform<unsigned>;
		using transformb = transform<bool>;

	}
}

#endif // !TRANSFORM_H
