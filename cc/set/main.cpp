#include<stdio.h>
#include "Set.h"
#include<stdlib.h>

int main(void)
{
	BitSet* demo = NULL;
	demo = createEmptySet(256);
	Insert(demo, 2);
	Insert(demo, 8);
	Insert(demo, 16);
	Insert(demo, 24);
	//printf("%d \n", insert(demo, 97));
	set_print(demo);
	
	system("pause");
	return 0;
}