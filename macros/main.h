#pragma once

#define DUMMY_INHEADER_VARS \
	int i0 = 1; \
	short i1 = 2; \
	long i3 = 8; \

#define DUMMY_INHEADER_FUN \
void inheader_fun() \
{ \
	int i = 9; \
	DUMMY_INHEADER_VARS \
}

