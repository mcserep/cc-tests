#include "main.h"

// === Non-template definitions ===


// undefined variables

extern int v0;
extern int v0;
extern int v0;

// defined variable

extern int v1;
       int v1;
extern int v1;


// undefined record

struct s0;
struct s0;
struct s0;

// defined record

struct s1;
struct s1 {};
struct s1;


// undefined function

void f0();
void f0();
void f0();

// defined function

void f1();
void f1() {}
void f1();

// function with different param names

void f2(int p0);
void f2(int p1) {}
void f2(int p2);
void f2(int);

// function with different defaults (multiple files)

void f3(int p) {}

// paramless function with and without void keyword

void f4(void);
void f4() {}


// === Template definitions ===


// undefined template class

template<typename T> struct ts0;
template<typename T> struct ts0;
template<typename T> struct ts0;

// defined template class

template<typename T> struct ts1;
template<typename T> struct ts1 { T value; };
template<typename T> struct ts1;

static void use_ts1()
{
	ts1<bool > lv0a;
	ts1<bool > lv0b;
	ts1<long > lv1a;
	ts1<long > lv1b;
	ts1<float> lv2a;
	ts1<float> lv2b;
}

// template class with different param names

template<typename T0> struct ts2;
template<typename T1> struct ts2;
template<typename T2> struct ts2;
template<typename T > struct ts2 { T value; };

static void use_ts2()
{
	ts2<bool > lv0a;
	ts2<bool > lv0b;
	ts2<long > lv1a;
	ts2<long > lv1b;
	ts2<float> lv2a;
	ts2<float> lv2b;
}

// template class with different defaults (multiple files)

template<typename T> struct ts3;

static void use_ts3()
{
	ts3<int> ta;
	ts3<int> tb;
}


// undefined template function

template<typename T> void tf0();
template<typename T> void tf0();
template<typename T> void tf0();

// defined template function

template<typename T> void tf1();
template<typename T> void tf1() { T value; }
template<typename T> void tf1();

static void use_tf1()
{
	tf1<bool >();
	tf1<bool >();
	tf1<long >();
	tf1<long >();
	tf1<float>();
	tf1<float>();
}

// template function with different param names

template<typename T0> void tf2();
template<typename T1> void tf2();
template<typename T2> void tf2();
template<typename T > void tf2() { T value; }

static void use_tf2()
{
	tf2<bool >();
	tf2<bool >();
	tf2<long >();
	tf2<long >();
	tf2<float>();
	tf2<float>();
}

// template function with different defaults (multiple files)

template<typename T> void tf3(T&& t);

static void use_tf3()
{
	tf3<int>(0);
	tf3<int>(0);
}


// === Main ===


int main() { return 0; }


