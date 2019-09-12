//位向量表示集合
#ifndef _SET_H_
#define _SET_H_

typedef struct{
	int size;
	char* array;
}BitSet;

BitSet* createEmptySet(int);
int Insert(BitSet*, int);
int Delete(BitSet*, int);
int member(BitSet*, int);
BitSet* Union(BitSet*, BitSet*);
BitSet* Intersection(BitSet*, BitSet*);
void set_print(BitSet*);



















#endif