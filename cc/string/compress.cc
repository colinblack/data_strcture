/*字符串压缩*/
#include<stdio.h>
#include<iostream>
#include<string.h>

#define MAXINPUT  256
#define EXIT  "exit"
using std::cin;
int usrInputStr(char* input, int maxsize)
{
	cin.get(input, maxsize);
	return strcmp(input,EXIT);

}

int invalidInput(const char* input)
{
  const	char* iter = input;
  while (*iter)
  {
	  if ((*iter < 'a') || (*iter > 'z'))
		  return 0;
	  iter++;
  }
  return iter != input;     //如果输入是空字符串返回应为0
}

int strToNum(int count, char* output)
{
	char* outiter = output;
	int targetbit = 0;
	while (count)
	{
		*(outiter++) = count % 10 + '0';
		count /= 10;
		targetbit++;
	}
	for (; outiter >= output; outiter--)
	{
		*output = *outiter;
 	}

	return targetbit;
}

char* compressProc(char* input, char* output,  int maxsize)
{
	char *inputIter = input, *usrOutput = output, preIter = 0;
	int sameCount = 0;

	while ((inputIter == input) || *(inputIter-1))         //遍历用户输入字符串, 同时应该考虑包含字符串结束标志
	{
		if (*inputIter != preIter)
		{
			if (sameCount > 1)            //当重复的字符大于1是就转换成数字
			{
				usrOutput += strToNum(sameCount, usrOutput);
			}
			if(preIter)
			{
				*(usrOutput++) = preIter;
			}
			sameCount = 1;			
			preIter = *inputIter;
		}
		else
		{
		
		
			sameCount++;  
		}
		
	}
	return usrOutput;
}

int main(void)
{
	char userInput[MAXINPUT], userOutput[MAXINPUT];

	while (usrInputStr(userInput, MAXINPUT))         //输入字符串
	{
		if (invalidInput(userInput))                                 //判断字符串是否合法
		{
			puts(compressProc(userInput, userOutput, MAXINPUT));                                                       //压缩字符串
		}
		else
			printf("invalid input");
	}

	return 0;
}
