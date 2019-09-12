/*�ַ���ѹ��*/
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
  return iter != input;     //��������ǿ��ַ�������ӦΪ0
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

	while ((inputIter == input) || *(inputIter-1))         //�����û������ַ���, ͬʱӦ�ÿ��ǰ����ַ���������־
	{
		if (*inputIter != preIter)
		{
			if (sameCount > 1)            //���ظ����ַ�����1�Ǿ�ת��������
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

	while (usrInputStr(userInput, MAXINPUT))         //�����ַ���
	{
		if (invalidInput(userInput))                                 //�ж��ַ����Ƿ�Ϸ�
		{
			puts(compressProc(userInput, userOutput, MAXINPUT));                                                       //ѹ���ַ���
		}
		else
			printf("invalid input");
	}

	return 0;
}
