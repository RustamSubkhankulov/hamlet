#pragma once

#include <stdio.h>

#include "../logs/errors_and_logs.h"
#include "hamlet_conf.h"

//===================================================================

struct Word
{
	char* data;
	unsigned int len;
	unsigned int num;
};

typedef Word String;

//===================================================================

struct Hamlet
{
	unsigned int number;
	unsigned int size;

	char* buffer;

	#ifdef SPLIT_IN_WORDS

		Word* words;

	#else 

		String* strings;

	#endif 

};

//===================================================================

#define HAMLET_PTR_CHECK(hamlet_ptr)								\
																	\
	do																\
	{																\
		if (!hamlet_ptr)											\
		{															\
			error_report(INV_HAMLET_STRUCTURE_PRT);					\
			return -1;												\
																	\
		}															\
	} while(0);

//===================================================================

int _hamlet_init(struct Hamlet* hamlet, const char* filename 
									 FOR_LOGS(, LOG_PARAMS));

int _hamlet_destruct(Hamlet* hamlet FOR_LOGS(, LOG_PARAMS));

int _hamlet_print_data(Hamlet* hamlet FOR_LOGS(, LOG_PARAMS));

//====================================================================

#define hamlet_print_data(hamlet) \
	   _hamlet_print_data(hamlet FOR_LOGS(, LOG_ARGS))

#define hamlet_init(hamlet, filename) \
	   _hamlet_init(hamlet, filename FOR_LOGS(, LOG_ARGS))

#define hamlet_destruct(hamlet) \
	   _hamlet_destruct(hamlet FOR_LOGS(, LOG_ARGS))

