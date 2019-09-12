template<typename EleType>

#pragma once
#define MAXSIZE 1000


class StaticList
{
public:
	typedef struct
	{
		EleType data;
		int cur;
	}Node;
	StaticList();
	~StaticList();
	bool Insert(const EleType& e, int index = 1);
	bool Delete( EleType& e, int index = 1);
	void Show()const;
private:
	int NewSpace();//����list��һ�������õĿռ��±�
	void DeleteSpace(int index);//ɾ��list�е�indexԪ��
	bool Empty()const;
	bool Full()const;
	Node StList[MAXSIZE];
	int Length;
};

