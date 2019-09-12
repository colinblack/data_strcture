//位向量表示集合

#include "Set.h"
#include <stdlib.h>
#include <stdio.h>

BitSet* createEmptySet(int n)
{
	int i;
	BitSet* s = (BitSet*)malloc(sizeof(BitSet));
	if (s != NULL)
	{
		s->size = (n + 7) / 8;
		s->array = (char*)malloc(s->size * sizeof(char));
		if (s->array != NULL)
		{	
			for (i = 0; i < s->size; i++)
				s->array[i] = '\0';
			return s;
		}
	
	
	}

	return NULL;
}

int Insert(BitSet* s, int index)
{
	if (index >= 0 && index >> 3 < s->size)
	{
		s->array[index >> 3] |= (1 << (index & 07));
		return 1;
	}
	//printf("%d \n", 1 << (index & 07));

	//printf("%c \n", s->array[0]);
	//printf("%c \n", s->array[1]);
	//printf("%c \n", s->array[2]);
	//printf("%c \n", s->array[3]);
	//printf("%d \n", index >> 3);
	return 0;
}

int Delete(BitSet* s, int index)
{
	if (index >= 0 && index >> 3 < s->size)
	{
		s->array[index >> 3] &= ~(1 << (index & 07));
		return 1;
	
	}

	return 0;

}

int Ismember(BitSet* s, int index)
{
	if (index >= 0 && index >> 3 < s->size && (s->array[index >> 3] & (1 << (index & 07))))
		return 1;
	return 0;

}

BitSet* Union(BitSet* s1, BitSet* s2)
{
	int i, j;
	int b_size = s1->size > s2->size ? s1->size : s2->size;
	int l_size = s1->size < s2->size ? s1->size : s2->size;
	BitSet* s3 = (BitSet*)malloc(sizeof(BitSet));
	if (s3 != NULL)
	{
		s3->size = b_size;
		s3->array = (char*)malloc(sizeof(char) * b_size);
		if (s3->array != NULL)
		{
			for (int i = 0; i < s3->size; i++)
				s3->array[i] = '\0';
		}
		else
		{
			free(s3);
			return NULL;
		}
	}
	else
	{
		return NULL;
	}
		

	if (s1->size == l_size)
	{
		for (i = 0; i < l_size; i++)
		{
			s3->array[i] = s1->array[i] | s2->array[i];

		}
		for (j = i; j < b_size; j++)
		{
			s3->array[j] = s2->array[j];
		}
	}
	else if (s2->size == l_size)
	{
		for (i = 0; i < l_size; i++)
		{
			s3->array[i] = s1->array[i] | s2->array[i];

		}
		for (j = i; j < b_size; j++)
		{
			s3->array[j] = s1->array[j];
		}
	}

	return s3;
}

BitSet* Intersection(BitSet* s1, BitSet* s2)
{
	int i;
	int l_size = s1->size < s2->size ? s1->size : s2->size;
	BitSet* s3 = (BitSet*)malloc(sizeof(BitSet));
	
	if (s3 != NULL)
	{
		s3->size = l_size;
		s3->array = (char*)malloc(sizeof(char) * l_size);
		if (s3->array != NULL)
		{
			for (int i = 0; i < s3->size; i++)
				s3->array[i] = '\0';
		}
		else
		{
			free(s3);
			return NULL;
		}
	}
	else
	{
		return NULL;
	}
	for (i = 0; i < l_size; i++)
	{
		s3->array[i] = s1->array[i] & s2->array[i];
	}


	return s3;

}

void set_print(BitSet* s)
{
	int i, j = 0;
	int bit = s->size << 3;
	for (i = 0; i < s->size; i++)
	{
		while (j < bit)
		{
			if (s->array[i] & (j << 1))
				printf("%d \n", i * 8 + j);
			j++;
		}
	}

}