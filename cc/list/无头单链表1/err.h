#ifndef _ERR_H_
#define _ERR_H_
#include <stdio.h>

#define MEMORYISNULL_1  (void*)(-1)
#define MEMORYISNULL_2	-1

#define Debug(...)  fprintf(stdout, __VA_ARGS__);

#define ERRMEMORY_1(condition, str)     do {                           \
					  						if(condition)              \
											{				           \
                                       			Debug(str);            \
                                       			return MEMORYISNULL_1; \
											}							\
										}while(0)



#define ERRMEMORY_2(condition, str)     do {                            \
											if(condition)		        \
											{					        \
												Debug(str); 	        \
												return MEMORYISNULL_2; \
											}					       \
										}while(0)

											
#endif

