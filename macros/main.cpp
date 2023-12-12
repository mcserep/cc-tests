#include "main.h"
#include <utility>
#include <cstddef>


////////////////


#define DUMMY_MACRO_TEST1 \
	long l; \
	const long cl = 8; \
	const size_t s = 8; \
	const unsigned int ui = 81; \
	\
	long* pl = &l; \
	const long* pcl = &cl; \
	long* const cpl = pl; \
	const long* const cpcl = pcl; \
	\
	long& rl = l; \
	const long& rcl = cl; \
	long&& rrl = std::move(l); \
	const long&& rrcl = std::move(cl); \
	\
	volatile int h = 8; \
	constexpr const char* c = ""; \
	static long long* sllp = nullptr; \


void dummy_macro1()
{
  DUMMY_MACRO_TEST1
}


////////////////


#define DUMMY_HELPER2 \
	int i = 0;

#define DUMMY_MACRO_TEST2 \
	DUMMY_HELPER2 \
		unsigned u = 1; \
		const char c = '2';

void dummy_macro2()
{
  DUMMY_MACRO_TEST2
}

////////////////

#if 0



#endif

void dummy_macro3()
{
  DUMMY_MACRO_TEST2
}

#define IFDEF_MACRO_TEST
#ifdef IFDEF_MACRO_TEST


#else




#endif

void dummy_macro4()
{
  DUMMY_MACRO_TEST2
  ++i;
}


////////////////


#define VARDEF_DUMMY \
	int i; \
	const unsigned long long coll = 8; \
	volatile const int v = 8; \
	mutable long long* m = nullptr; \
	static constexpr const char* c = ""; \


#define FUNDEF_DUMMY \
void fundef_dummy() \
{ \
  int xxx = 5; \
  DUMMY_MACRO_TEST2 \
}


class fundef_dummy_wrapper
{
  VARDEF_DUMMY
  FUNDEF_DUMMY
};


////////////////


#define CLASSDEF_DUMMY \
class classdef_dummy \
{ \
  int memdata = 8; \
  void memfun() \
  { \
    int yyy = -1; \
    DUMMY_MACRO_TEST2 \
  } \
};

class classdef_dummy_wrapper
{
  CLASSDEF_DUMMY
};


////////////////


void fromheader_vars_dummy()
{
	DUMMY_INHEADER_VARS
}

class fromheader_fun_dummy
{
	DUMMY_INHEADER_FUN
};


////////////////


int main()
{
	return 0;
}

