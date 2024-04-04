// function with different defaults (multiple files)

void f3(int p);

// template class with different defaults (multiple files)

template<typename T> struct ts3 { T value; };

// template function with different defaults (multiple files)

template<typename T> void tf3(T&& t) { T value = t; }

