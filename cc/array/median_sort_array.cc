/*
* There are two sorted arrays A and B of size m and n respectively.Find the median of the two sorted arrays.
* The overall run time complexity should be O(log(m + n)).
*/

#include <iostream>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
class Solution {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		int *array = new int[m + n]{0};
		int i = 0, j = 0, k = 0;
		while (i < m && j < n)
		{
			if (A[i] < B[j])
			{
				array[k] = A[i];
				++i;
			}
			else
			{
				array[k] = B[j];
				++j;
			}
			++k;
		}

		if (i >=m && j < n)
		{
			memcpy(array + k, &B[j], sizeof(int)*(n - j));
		}
		else if (j >= n && i < m)
		{
			memcpy(array + k, &A[i], sizeof(int)*(m - i));
		}

		double media = 0.0;
		if ((m + n) % 2)
		{
			media = array[(m + n) / 2];
		}
		else
		{
			media = (array[(m + n) / 2] + array[(m + n) / 2 - 1]) / 2.0;
		}

		delete[] array;
		return media;
	}

};

int main()
{
	int a[] = { 1, 3};
	int b[] = { 2, 4 };
	Solution A;
	double x = A.findMedianSortedArrays(a, 2, b, 2);
	printf("%f", x);
	return 0;
}
