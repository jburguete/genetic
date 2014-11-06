/*
GENETIC - A simple genetic algorithm.

Copyright 2014, Javier Burguete Tolosa.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
 
1. Redistributions of source code must retain the above copyright notice, this
	list of conditions and the following disclaimer.
 
2. Redistributions in binary form must reproduce the above copyright notice,
	this list of conditions and the following disclaimer in the documentation
	and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY Javier Burguete Tolosa ``AS IS'' AND ANY EXPRESS
OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
EVENT SHALL Javier Burguete Tolosa OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/**
 * \file sort.h
 * \brief Header file to define sort functions.
 * \author Javier Burguete Tolosa.
 * \copyright Copyright 2014, Javier Burguete Tolosa. All rights reserved.
 */
#ifndef SORT__H
#define SORT__H 1

/**
 * \def INDEX_SORT_MERGE_MIN
 * \brief Minimum elements to sort with the merge algorithm.
 */
#define INDEX_SORT_MERGE_MIN 32

/**
 * \fn static inline void index_sort_insertion(double *x, unsigned int *index, \
 *   unsigned int n)
 * \brief Function to sort an index array by the insertion algorithm.
 * \param x
 * \brief Evaluation values array.
 * \param index
 * \brief Index array.
 * \param n
 * \brief Number of elements.
 */
static inline void index_sort_insertion
(double *x, unsigned int *index, unsigned int n)
{
	register int i, j, ii;
	register double xi;
	for (i = 0; ++i < n;)
	{
		ii = index[i];
		xi = x[ii];
		for (j = i; --j >= 0 && x[index[j]] > xi;) index[j + 1] = index[j];
		index[j + 1] = ii;
	}
}

/**
 * \fn static inline void index_sort_merge(double *x, unsigned int *index, \
 *   unsigned int n)
 * \brief Function to sort an index array by the merge algorithm.
 * \param x
 * \brief Evaluation values array.
 * \param index
 * \brief Index array.
 * \param n
 * \brief Number of elements.
 */
static inline void index_sort_merge
(double *x, unsigned int *index, unsigned int n)
{
	int i, j, i1, i2, k, l;
	unsigned int *ni1, *ni2, *nj, *nk, *nt, nn[n];
	if (n <= 1) return;
	j = INDEX_SORT_MERGE_MIN;
	for (i = 0; i < n - j; i += j)
		index_sort_insertion(x, index + i, j);
	if (i < n) index_sort_insertion(x, index + i, n - i);
	for (nk = index, nj = nn; j <= n; j *= 2)
	{
		for (ni1 = nk, l = 0, k = n / j; (k -= 2) >= 0; ni1 = ni2 + j)
		{
			ni2 = ni1 + j;
			for (i1 = i2 = 0; i1 < j && i2 < j;)
			{
				if (x[ni1[i1]] < x[ni2[i2]]) nj[l++] = ni1[i1++];
				else nj[l++] = ni2[i2++];
			}
			while (i2 < j) nj[l++] = ni2[i2++];
			while (i1 < j) nj[l++] = ni1[i1++];
		}
		if (k == -1)
		{
			ni2 = ni1 + j;
			for (k = n - l - j, i1 = i2 = 0; i1 < j && i2 < k;)
			{
				if (x[ni1[i1]] < x[ni2[i2]]) nj[l++] = ni1[i1++];
				else nj[l++] = ni2[i2++];
			}
			while (i2 < k) nj[l++] = ni2[i2++];
			while (i1 < j) nj[l++] = ni1[i1++];
		}
		for (; l < n; ++l) nj[l] = nk[l];
		nt = nk;
		nk = nj;
		nj = nt;
	}
	if (index != nk) memcpy(index, nk, n * sizeof(unsigned int));
}

/**
 * \fn static inline void index_new(double *x, unsigned int *index, \
 *   unsigned int n)
 * \brief Function to create and sort an index array by the optimal algorithm.
 * \param x
 * \brief Evaluation values array.
 * \param index
 * \brief Index array.
 * \param n
 * \brief Number of elements.
 */
static inline void index_new(double *x, unsigned int *index, unsigned int n)
{
	unsigned int i;
	for (i = 0; i < n; ++i) index[i] = i;
	if (n < INDEX_SORT_MERGE_MIN) index_sort_insertion(x, index, n);
	else index_sort_merge(x, index, n);
}

#endif
