#include "main.h"

// function with different defaults (multiple files)

void f3(int p = 2);

// template class with different defaults (multiple files)

template<typename T = float> struct ts3;

static void use_ts3()
{
	ts3<> ta;
	ts3<> tb;
}

// template function with different defaults (multiple files)

template<typename T = float> void tf3(T&& t);

static void use_tf3()
{
	tf3(0);
	tf3(0);
}

