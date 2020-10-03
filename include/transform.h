#ifndef TRANSFORM_H
#define TRANSFORM_H

namespace Chaf
{
	template<typename T>
	struct transform
	{
		inline static vec<T, 3>trans(const vec<T, 3>& v, const matrix<T, 4, 4>& mat)
		{
			vec<T, 3> res;
			for (size_t i = 0; i < 3; i++)
				for (size_t j = 0; j < 3; j++)
					res[i] += v[j] * mat(i, j);
			for (size_t i = 0; i < 3; i++)res[i] += mat(i, 3);
			return res;
		}

		inline static matrix<T, 4, 4> transMatrix(const matrix<T, 4, 4>& translation, const matrix<T, 4, 4>& rotation, const matrix<T, 4, 4>& scale)
		{
			return translation * rotation * scale;
		}

		inline static matrix<T, 4, 4> transMatrix(const vec<T, 3>& translation, const matrix<T, 3, 3>& rotation, const vec<T, 3>& scale)
		{
			return matrix<T, 4, 4>{
				{ rotation(0, 0)* scale[0], rotation(0, 1), rotation(0, 2), translation[0] },
				{ rotation(1,0), rotation(1,1) * scale[1], rotation(1,2),translation[1] },
				{ rotation(2,0),rotation(2,1), rotation(2,2) * scale[2],translation[2] },
				{ 0,0,0,1 }
			};
		}

		inline static matrix<T, 4, 4> scale(const T& x, const T& y, const T& z)
		{
			return matrix<T, 4, 4>{
				{x, 0, 0, 0},
				{ 0,y,0,0 },
				{ 0,0,z,0 },
				{ 0,0,0,1 }
			};
		}

		inline static matrix<T, 4, 4> scale(const vec<T, 3>& v)
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

		inline static matrix<T, 4, 4> translation(const T& x, const T& y, const T& z)
		{
			return matrix<T, 4, 4>{
				{ 1, 0, 0, x },
				{ 0, 1, 0, y },
				{ 0, 0, 1, z },
				{ 0, 0, 0, 1 }
			};
		}

		inline static matrix<T, 4, 4> translation(const vec<T, 3>& v)
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

		inline static matrix<T, 4, 4> rotation(const T& angle, const vec<T, 3>& axis)
		{
			auto naxis = static_cast<vec<T, 3>>(axis).normalize();
			return matrix<T, 4, 4>{
				{naxis[0] * naxis[0] * (1 - Cos<T>(angle)) + Cos<T>(angle),
					naxis[0] * naxis[1] * (1 - Cos<T>(angle)) - naxis[2] * Sin<T>(angle),
					naxis[0] * naxis[2] * (1 - Cos<T>(angle)) + naxis[1] * Sin<T>(angle), 0},

				{ naxis[1] * naxis[0] * (1 - Cos<T>(angle)) + naxis[2] * Sin<T>(angle),
					naxis[1] * naxis[1] * (1 - Cos<T>(angle)) + Cos<T>(angle),
					naxis[1] * naxis[2] * (1 - Cos<T>(angle)) - naxis[0] * Sin<T>(angle),0 },

				{ naxis[2] * naxis[0] * (1 - Cos<T>(angle)) - naxis[1] * Sin<T>(angle),
					naxis[2] * naxis[1] * (1 - Cos<T>(angle)) + naxis[0] * Sin<T>(angle),
					naxis[2] * naxis[2] * (1 - Cos<T>(angle)) + Cos<T>(angle),0 },

				{ 0, 0, 0, 1 }
			};
		}

		inline static vec<T, 3> rotation(const vec<T, 3>& v, const T& angle, const vec<T, 3>& axis)
		{
			vec<T, 3>res;
			res = transform::trans(v, rotation(angle, axis));
			return res;
		}

		inline static matrix<T, 4, 4> lookAt(const point<T, 3>& position, const point<T, 3>& target, const vec<T, 3> up)
		{
			vec<T, 3> zAxis = (position - target).normalize();
			vec<T, 3> xAxis = static_cast<vec<T,3>>(up).cross(zAxis).normalize();
			vec<T, 3> yAxis = zAxis.cross(xAxis);
			return matrix<T, 4, 4>{
				{ xAxis[0], xAxis[1], xAxis[2], -xAxis.dot(position.cast<vec<T,3>>()) },
				{ yAxis[0], yAxis[1], yAxis[2], -yAxis.dot(position.cast<vec<T,3>>()) },
				{ zAxis[0], zAxis[1], zAxis[2], -zAxis.dot(position.cast<vec<T,3>>()) },
				{ 0, 0, 0,1 }
			};
		}

		inline static matrix<T, 4, 4> projection()
		{

		}
	};

	using transformf = transform<float>;
	using transformi = transform<int>;
	using transformu = transform<unsigned>;
	using transformb = transform<bool>;

}

#endif // !TRANSFORM_H
