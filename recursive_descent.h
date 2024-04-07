#ifndef RECURSIVE_DESCENT_H
#define RECURSIVE_DESCENT_H

#define REQUIRE(a, ptr_str)\
        if(*ptr_str == a) ptr_str++;\
        else syntax_error();\

#define CONVERT_TO_RAD(deg)\
        ((deg) * M_PI / 180)\

double recursive_descent(const char* buffer);
double get_G();
double get_E();
double get_T();
double get_P();
double get_O();
double get_F();
double get_N();
void syntax_error();

#endif // RECURSIVE_DESCENT_H