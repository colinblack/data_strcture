#include<stdio.h>
#include<string.h>
void printString(char str[], int count)
{
    char temp[100] = {'\0'};
    temp[0] = str[0];
    int j = 1;
    int k;
    for (int i = 1; i < count; i++) {
        if (str[i] == ' ') {
            continue;
        } 

	 for(k = 0; k < strlen(temp); k++)
	 {	
		 if(str[i] == temp[k])
			break;
	 }
//	 printf("%d, %d \n",strlen(temp), k);
	if(k == strlen(temp))
	{
          temp[j] = str[i];
          j++;
	}
    }
    printf("去掉相同字符之后 \n");
    for (int i = 0; i < count; i++) {
        printf("%c",temp[i]);
    }
}

int main(void)
{
        printString("gggggoogoooood", 15);
	return 0;
}
