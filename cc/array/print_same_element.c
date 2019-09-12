#include <stdio.h>
#include <stdlib.h>

//     返回c写入的实际个数
int shas(int *a, int aSize, int *b, int bSize, int* c, int cSize){
    //int *indexa=a;
    //int *indexb=b;
   // int c[100];
    int indexA = 0;
    int indexB = 0;
    int indexC=0;
    int i = 0;
    while(1){
        if(indexA   >= aSize || indexB >= bSize || indexC >= cSize){
        break;
        }
        if( a[indexA] == b[indexB]){
        c[indexC] = a[indexA];
        indexA++;
        indexB++;
        indexC++;
	i++;
        }
        if(a[indexA] > b[indexB]){
        indexB++;
	i++;
        }
        if(a[indexA] < b[indexB]){
        indexA++;
	i++;
        }    

    }
    printf("%d \n", i);
    return indexC;
}
int main(){
	int cIndex;
    int a[]={13,2,3,4,5,6,7};
    int b[]={13,3,5,7,8,9,11};
    int c[100];
int cSize =    shas(a, 7, b, 7, c, 100);

for(cIndex = 0; cIndex < cSize; cIndex++){
printf("%d==asad\n", c[cIndex]);
//c++;
}
    //system("pause");
    return 1;
} 
