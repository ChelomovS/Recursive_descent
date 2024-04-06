#ifndef RECURSIVE_DOWN_H
#define RECURSIVE_DOWN_H

#define REQUIRE(a, ptr_str)\
        if(*ptr_str == a) ptr_str++;\
        else syntax_error();


int recursive_down(const char* buffer);
int get_G();
int get_E();
int get_T();
int get_P();
int get_N();
void syntax_error();

#endif // RECURSIVE_DOWN_H