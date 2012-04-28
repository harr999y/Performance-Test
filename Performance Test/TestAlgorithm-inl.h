/**
**********************************************************************
*	@defgroup TestAlgorithm header for test algorithms
*	@author Li Suyong
*  @version 1.0
*  @date 2011/10/12
***********************************************************************
@{ */

#ifndef TEST_ALGORITHM_H_
#define TEST_ALGORITHM_H_

#include "common.h"

/** 
@note 
    This namespace Can Not include outside this project.
*/
namespace TestAlgorithm
{
	/** Test algorithm : time depletion. */
	inline void timeDepletion(size_t count)
	{
		size_t it, jt, sum;
		it = jt = sum = 0;

		for (; it < count; ++it)
		{
			for (; jt < count; ++jt)
			{
				sum += it * jt;
			}
		}
	}

	/** Test algorithm : cycle sum 1. */
	inline void cycleSum1(float a[], float p[], long n)
	{
		long i;
		p[0] = a[0];
		for (i = 1; i < n; ++i)
		{
			p[i] = p[i - 1] + a[i];
		}
	}

	/** Test algorithm : cycle sum 2. */
	inline void cycleSum2(float a[], float p[], long n)
	{
		long i;
		p[0] = a[0];
		for (i = 1; i < n-1; i += 2)
		{
			float mid_val = p[i - 1] + a[i];
			p[i] = mid_val;
			p[i + 1] = mid_val + a[i + 1];
		}

		if (i < n)
			p[i] = p[i - 1] + a[i];
	}

	//////////////////////////////////////////////////////////////////////////
	/** About test algorithm : combine 1-7. */
	namespace
	{
#define IDENT 1
#define OP +

		typedef int data_t;

		typedef struct
		{
			long len;
			data_t *data;
		} vec_rec, *vec_ptr;

		vec_ptr createVec(long len)
		{
			vec_ptr result = (vec_ptr) malloc(sizeof(vec_rec));
			IF_NULL_RETURN_VALUE(result, NULL);

			result->len = len;
			if (len > 0)
			{
				data_t *data = (data_t *) calloc(len, sizeof(data_t));
				if (!data)
				{
					free((void *)result);
					return NULL;
				}

				memset(data, 1, sizeof(data[0]) * len);
				result->data = data;
			}
			else
			{
				result->data = NULL;
			}

			return result;
		}

		int getVecElement(vec_ptr v, long index, data_t *dest)
		{
			if (index < 0 || index >= v->len)
				return 0;

			*dest = v->data[index];

			return 1;
		}

		long getVecLength(vec_ptr v)
		{
			return v->len;
		}

		data_t *getVecStart(vec_ptr v)
		{
			return v->data;
		}
	}

	//////////////////////////////////////////////////////////////////////////

	/** Test algorithm : combine1. */
	inline void combine1(vec_ptr v, data_t *dest)
	{
		*dest = IDENT;

		for (long i = 0; i < getVecLength(v); ++i)
		{
			data_t val;
			getVecElement(v, i, &val);
			*dest = *dest OP val;
		}
	}

	/** Test algorithm : combine2. */
	inline void combine2(vec_ptr v, data_t *dest)
	{
		*dest = IDENT;

		long length = getVecLength(v);
		for (long i = 0; i < length; ++i)
		{
			data_t val;
			getVecElement(v, i, &val);
			*dest = *dest OP val;
		}
	}

	/** Test algorithm : combine3. */
	inline void combine3(vec_ptr v, data_t *dest)
	{
		*dest = IDENT;

		long length = getVecLength(v);
		data_t *data = getVecStart(v);

		for (long i = 0; i < length; ++i)
			*dest = *dest OP data[i];
	}

	/** Test algorithm : combine4. */
	inline void combine4(vec_ptr v, data_t *dest)
	{
		*dest = IDENT;

		long length = getVecLength(v);
		data_t *data = getVecStart(v);
		data_t acc = IDENT;

		for (long i = 0; i < length; ++i)
			acc = acc OP data[i];

		*dest = acc;
	}

	/** Test algorithm : combine5. */
	inline void combine5(vec_ptr v, data_t *dest)
	{
		*dest = IDENT;

		long length = getVecLength(v);
		data_t *data = getVecStart(v);
		data_t acc = IDENT;
		long limit = length - 1;

		for (long i = 0; i < limit; i += 2)
			acc = (acc OP data[i]) OP data[i + 1];
		for (long i = length - 2; i < length; ++i)
			acc = acc OP data[i];

		*dest = acc;
	}

	/** Test algorithm : combine6. */
	inline void combine6(vec_ptr v, data_t *dest)
	{
		*dest = IDENT;

		long length = getVecLength(v);
		data_t *data = getVecStart(v);
		data_t acc1 = IDENT;
		data_t acc2 = IDENT;
		long limit = length - 1;

		for (long i = 0; i < limit; i += 2)
		{
			acc1 = acc1 OP data[i];
			acc2 = acc2 OP data[i + 1];
		}

		for (long i = length - 2; i < length; ++i)
			acc1 = acc1 OP data[i];

		*dest = acc1 OP acc2;
	}

	/** Test algorithm : combine7. */
	inline void combine7(vec_ptr v, data_t *dest)
	{
		*dest = IDENT;

		long length = getVecLength(v);
		data_t *data = getVecStart(v);
		data_t acc = IDENT;
		long limit = length - 1;

		for (long i = 0; i < limit; i += 2)
			acc = acc OP (data[i] OP data[i + 1]);
		for (long i = length - 2; i < length; ++i)
			acc = acc OP data[i];

		*dest = acc;
	}

	/** Test algorithm : minmax1. */
	inline void minmax1(int a[], int b[], int n)
	{
		for (int i = 0; i < n; ++i)
		{
			if (a[i] > b[i])
			{
				int t = a[i];
				a[i] = b[i];
				b[i] = t;
			}
		}
	}

	/** Test algorithm : minmax2. */
	inline void minmax2(int a[], int b[], int n)
	{
		for (int i = 0; i < n; ++i)
		{
			int min = a[i] < b[i] ? a[i] : b[i];
			int max = a[i] < b[i] ? b[i] : a[i];
			a[i] = min;
			b[i] = max;
		}
	}

	//////////////////////////////////////////////////////////////////////////
	/** About test algorithm : aboutMemory 1-7. */
	namespace
	{
		inline void createArrayOfArray(int ***a, int ***b, int ***c, int count)
		{
			*a = new int *[count];
			for (int i = 0; i < count; ++i)
			{
				(*a)[i] = new int[count];
				memset((*a)[i], 1, sizeof((*a)[0][0]) * count);
			}

			*b = new int *[count];
			for (int i = 0; i < count; ++i)
			{
				(*b)[i] = new int[count];
				memset((*b)[i], 1, sizeof((*b)[0][0]) * count);
			}

			*c = new int *[count];
			for (int i = 0; i < count; ++i)
			{
				(*c)[i] = new int[count];
				memset((*c)[i], 1, sizeof((*c)[0][0]) * count);
			}
		}

		inline void deleteArrayOfArray(int **a, int **b, int **c, int count)
		{
			for (int i = 0; i < count; ++i)
				delete [](a[i]);

			for (int i = 0; i < count; ++i)
				delete [](b[i]);

			for (int i = 0; i < count; ++i)
				delete [](c[i]);
		}
	}
	//////////////////////////////////////////////////////////////////////////

	/** Test algorithm : AboutMemory1. */
	inline void aboutMemory1(int count)
	{
		int **a, **b, **c;
		a = b = c = NULL;
		createArrayOfArray(&a, &b, &c, count);

		int i, j, m, sum;
		i = j = m = sum = 0;
		for (i = 0; i < count; ++i)
		{
			for (j = 0; j < count; ++j)
			{
				sum = 0; 
				for (m = 0; m < count; ++m)
				{
					sum += a[i][m] * b[m][j];
				}
				c[i][j] += sum;
			}
		}
		
		deleteArrayOfArray(a, b, c, count);
	}

	/** Test algorithm : AboutMemory2. */
	inline void aboutMemory2(int count)
	{
		int **a, **b, **c;
		a = b = c = NULL;
		createArrayOfArray(&a, &b, &c, count);

		int i, j, k, r;
		i = j = k = r = 0;
		for (j = 0; j < count; ++j)
		{
			for (k = 0; k < count; ++k)
			{
				r = b[k][j]; 
				for (i = 0; i < count; ++i)
				{
					c[i][j] += a[i][k] * r;
				}
			}
		}

		deleteArrayOfArray(a, b, c, count);
	}

	/** Test algorithm : AboutMemory3. */
	inline void aboutMemory3(int count)
	{
		int **a, **b, **c;
		a = b = c = NULL;
		createArrayOfArray(&a, &b, &c, count);

		int i, j, k, r;
		i = j = k = r = 0;
		for (k = 0; k < count; ++k)
		{
			for (i = 0; i < count; ++i)
			{
				r = a[i][k]; 
				for (j = 0; j < count; ++j)
				{
					c[i][j] += r * b[k][j];
				}
			}
		}

		deleteArrayOfArray(a, b, c, count);
	}

}

#endif

/** @} */