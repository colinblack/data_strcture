#include "singlelistnode.hpp"
#include<stdlib.h>


int main()
{
	SingleList<int> s_list;
	s_list.addToTail(1);

	std::cout << s_list.isEmpty() << std::endl;



	system("pause");
	return 0;
}