#include <iostream>
#include <algorithm>

void adjustupdown(int n, int *array, int len)
{
	int l = 2 * n + 1;
	int r = 2 * n + 2;
	int max = n;

	if (l <= len && array[l] > array[max])
	{
		max = l;
	}

	if (r <= len && array[r] > array[max])
	{
		max = r;
	}

	if (max != n)
	{
		std::swap(array[max], array[n]);
		adjustupdown(max, array, len);
	}

}

void builMaxheap(int *array, int len)
{
	int node = (len - 1) / 2;
	for (; node >= 0; --node)  //注意此处是n,不是len
	adjustupdown(node, array, len);
}


int* heapSort(int* A, int n) {
	builMaxheap(A,n-1);
	//for (int i = 0; i < 10; ++i)
	//	std::cout << A[i] << std::endl;
	for (int i = n-1; i >=1; --i)
	{
		//std::cout << A[0] << std::endl;
		std::swap(A[i], A[0]);
		adjustupdown(0, A, i-1);
	}
	
	return A;
}



int main()
{
	int array[10] = {10,11,4,9,12,3,1,6,5,7};
	heapSort(array, 10);

	for (auto i : array)
	{
		std::cout << i << std::endl;
	}

}