#ifndef RECURSIVE_DOWN_H
#define RECURSIVE_DOWN_H

#define REQUIRE(a, ptr_str)\
        if(*ptr_str == a) ptr_str++;\
        else syntax_error();


int recursive_down(const char* buffer);
int get_G(const char* buffer);
int get_E(const char* buffer);
int get_T(const char* buffer);
int get_P(const char* buffer);
int get_N(const char* buffer);
void syntax_error();

#endif // RECURSIVE_DOWN_H