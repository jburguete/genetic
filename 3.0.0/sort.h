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

#define INDEX_SORT_MERGE_MIN 32
  ///< Minimum elements to sort with the merge algorithm.

/**
 * Function to sort an index array by the insertion algorithm.
 */
static inline void
index_sort_insertion (double *x,        ///< Evaluation values array.
                      unsigned int *index,      ///< Index array.
                      unsigned int n)   ///< Number of elements.
{
  register double xi;
  register int j;
  register unsigned int i, ii;
  for (i = 0; ++i < n;)
    {
      ii = index[i];
      xi = x[ii];
      for (j = (int) i; --j >= 0 && x[index[j]] > xi;)
        index[j + 1] = index[j];
      index[j + 1] = ii;
    }
}

/**
 * Function to sort an index array by the merge algorithm.
 */
static inline void
index_sort_merge (double *x,    ///< Evaluation values array.
                  unsigned int *index,  ///< Index array.
                  unsigned int n)       ///< Number of elements.
{
  unsigned int *ni1, *ni2, *nj, *nk, *nt, nn[n];
  int i, j, i1, i2, k, l;
  if (n <= 1)
    return;
  j = INDEX_SORT_MERGE_MIN;
  for (i = 0; i < (int) n - j; i += j)
    index_sort_insertion (x, index + i, j);
  if (i < (int) n)
    index_sort_insertion (x, index + i, n - i);
  for (nk = index, nj = nn; j <= (int) n; j *= 2)
    {
      for (ni1 = nk, l = 0, k = n / j; (k -= 2) >= 0; ni1 = ni2 + j)
        {
          ni2 = ni1 + j;
          for (i1 = i2 = 0; i1 < j && i2 < j;)
            {
              if (x[ni1[i1]] < x[ni2[i2]])
                nj[l++] = ni1[i1++];
              else
                nj[l++] = ni2[i2++];
            }
          while (i2 < j)
            nj[l++] = ni2[i2++];
          while (i1 < j)
            nj[l++] = ni1[i1++];
        }
      if (k == -1)
        {
          ni2 = ni1 + j;
          for (k = n - l - j, i1 = i2 = 0; i1 < j && i2 < k;)
            {
              if (x[ni1[i1]] < x[ni2[i2]])
                nj[l++] = ni1[i1++];
              else
                nj[l++] = ni2[i2++];
            }
          while (i2 < k)
            nj[l++] = ni2[i2++];
          while (i1 < j)
            nj[l++] = ni1[i1++];
        }
      for (; l < (int) n; ++l)
        nj[l] = nk[l];
      nt = nk;
      nk = nj;
      nj = nt;
    }
  if (index != nk)
    memcpy (index, nk, n * sizeof (unsigned int));
}

/**
 * Function to create and sort an index array by the optimal algorithm.
 */
static inline void
index_new (double *x,           ///< Evaluation values array.
           unsigned int *index, ///< Index array.
           unsigned int n)      ///< Number of elements.
{
  unsigned int i;
  for (i = 0; i < n; ++i)
    index[i] = i;
  if (n < INDEX_SORT_MERGE_MIN)
    index_sort_insertion (x, index, n);
  else
    index_sort_merge (x, index, n);
}

#endif
