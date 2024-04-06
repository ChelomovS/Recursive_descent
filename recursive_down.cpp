#include <stdio.h>
#include "debug.h"
#include "recursive_down.h"

int recursive_down(const char* buffer) // written
{
    ASSERT(buffer != nullptr);

    fprintf(stderr, "BEGIN RECURSIVE DOWN\n");
    return get_G(buffer);
}

int get_G(const char* buffer) // written
{
    ASSERT(buffer != nullptr);

    int val = get_E(buffer);
    $
    REQUIRE('$', buffer);
    $
    fprintf(stderr, "Find: $\n");
    fprintf(stderr, "BYE\n");

    return val;
}

int get_E(const char* buffer)
{
    ASSERT(buffer != nullptr);

    int val = get_T(buffer);

    while (*buffer == '+' || *buffer == '-')
    {
        char op = *buffer;
        buffer++;
        int val2 = get_T(buffer);
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

int get_T(const char* buffer) // written
{
    ASSERT(buffer != nullptr);
    int val = get_P(buffer);
    while(*buffer == '*' || *buffer == '/')
    {
        char op = *buffer;

        buffer++;

        int val2 = get_P(buffer);

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

int get_P(const char* buffer) // written
{
    ASSERT(buffer != nullptr);

    if (*buffer == '(')
    {
        fprintf(stderr, "Find: (\n");
        buffer++;

        int val = get_E(buffer);
        REQUIRE(')', buffer);
        return val;
    }
    else 
    {
        return get_N(buffer);
    }
}

int get_N(const char* buffer) // written
{
    ASSERT(buffer != nullptr);

    int val = 0;

    const char* old_buffer = buffer;

    while('0' <= *buffer && *buffer <= '9')
    {
        val = val * 10 + (*buffer - '0');
        buffer++;
    }

    if (old_buffer == buffer)
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