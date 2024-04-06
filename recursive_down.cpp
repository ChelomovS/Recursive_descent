#include <stdio.h>
#include "debug.h"
#include "recursive_down.h"

const char* str = nullptr;

int recursive_down(const char* buffer) // written
{
    ASSERT(buffer != nullptr);
    str = buffer;
    fprintf(stderr, "BEGIN RECURSIVE DOWN\n");
    return get_G();
}

int get_G() // written
{
    int val = get_E();
    REQUIRE('$', str);
    fprintf(stderr, "Find: $\n");
    fprintf(stderr, "BYE\n");

    return val;
}

int get_E()
{
    int val = get_T();

    while (*str == '+' || *str == '-')
    {
        char op = *str;
        str++;
        int val2 = get_T();
        if (op == '+')
        {
            val += val2;
        }
        else if (op == '-')
        {
            val -= val2;
        }
    }
    return val;
}

int get_T() // written
{
    int val = get_P();
    while(*str == '*' || *str == '/')
    {
        char op = *str;

        str++;

        int val2 = get_P();

        if (op == '*')  
        {
            val *= val2;
        }
        else if (op == '/')
        {
            val /= val2;
        }
    }
    return val;
}

int get_P() // written
{
    if (*str == '(')
    {
        fprintf(stderr, "Find: (\n");
        str++;

        int val = get_E();
        REQUIRE(')', str);
        return val;
    }
    else 
    {
        return get_N();
    }
}

int get_N() // written
{
    int val = 0;

    const char* old_str = str;

    while('0' <= *str && *str <= '9')
    {
        val = val * 10 + (*str - '0');
        str++;
    }

    if (old_str == str)
    {
        syntax_error();
    }

    return val;
}

void syntax_error()
{
    fprintf(stderr, "SYNTAX ERROR!\n");
    exit(1);
}