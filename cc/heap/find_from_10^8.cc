//从一亿个数中找最大的一万个数
//topk
#include <iostream>
#include <algorithm>

void adjustHeap(int* array, int root)
{
	int l = root * 2 + 1;
	int r = root * 2 + 2;
	int min = root;

	if (array[min] > array[l])
	{
		min = l;
	}

	if (array[min] > array[r])
	{
		min = r;
	}

	if (min != root)
	{
		std::swap(array[min], array[root]);
		adjustHeap(array, min);
	}
}


void buildMinHeap(int* array, int len)
{
	int root = (array[len] - 1) / 2;
	for (int i = root; i >= 0; --i)
	{
		adjustHeap(array, i);
	}
}


int* findMaxthousand(int* array, int len)
{
	buildMinHeap(array, 10000);
	len -= 1000000;
	for (int i = 0; i < len; --len)
	{
		if (array[i] > array[0])
		{
			array[0] = array[i];
			adjustHeap(array, array[0]);
		}

	}

	return array;
}




int main()
{




	return 0;
}
