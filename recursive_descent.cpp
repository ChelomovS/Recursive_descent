#include <stdio.h>
#include <math.h>
#include <string.h>
#include "debug.h"
#include "recursive_descent.h"

const char* str = nullptr;

double recursive_descent(const char* buffer) // written
{
    ASSERT(buffer != nullptr);

    str = buffer;

    return get_G();
}

double get_G() // written
{
    double val = get_E();

    REQUIRE('$', str);

    return val;
}

double get_E() // written
{
    double val = get_T();

    while (*str == '+' || *str == '-')
    {
        char op = *str;
        str++;
        double val2 = get_T();

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

double get_T() // written
{
    double val = get_O();

    while(*str == '*' || *str == '/')
    {
        char op = *str;

        str++;

        double val2 = get_O();

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

double get_O()
{
    if (strncmp(str, "sin", 3) == 0)
    {
        str += 3;

        return sin(CONVERT_TO_RAD(get_P()));
    }

    if (strncmp(str, "ln", 2) == 0)
    {
        str += 2;

        return log(get_P());
    }

    if (strncmp(str, "cos", 3) == 0)
    {
        str += 3;

        return cos(CONVERT_TO_RAD(get_P()));
    }

    if (strncmp(str, "tg", 2) == 0)
    {
        str += 2;

        return tan(CONVERT_TO_RAD(get_P()));
    }

    return get_F();
}

double get_F() // written
{
    double val = get_P();

    while(*str == '^')
    {
        str++;

        double val2 = get_P();
        val = pow(val, val2);
    }

    return val;
}

double get_P() // written
{
    if (*str == '(')
    {
        str++;

        double val = get_E();
        REQUIRE(')', str);

        return val;
    }

    return get_N();
}

double get_N() // written
{
    double val = 0;

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