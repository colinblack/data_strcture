//不分配额外的空间实现以null结尾的字符串的反转
#if 0
#include<stdio.h>
#include<stdlib.h>

void reverse(char* str)
{
	char *end = str;
	while (*end)
		++end;
	--end;

	char tmp;
	for (; str < end;)
	{
		tmp = *str;
		*str++ = *end;
		*end-- = tmp;
	}

	printf("%s \n",str);
}


int main(void)
{
	char p[] = "hello";
	reverse(p);
	//printf("%s", p);
	
	system("pause");
	return 0;
}

#endif