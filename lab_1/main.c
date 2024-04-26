#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

char* getln() 
{
    size_t size = 8;
    char* str = malloc(size);
    size_t len = 0;

    char ch;
    while ((ch = getchar())) 
    {
        switch (ch) 
        {
        case '\n':
        {
            str[len] = '\0';
            return str;
        }
        break;
        default: 
        {
            str[len++] = ch;
            if (len == size) 
            {
                size *= 2;
                str = realloc(str, size);
            }
        }
        }
    }

    return NULL;
}

bool is_palindrome(char* str) 
{
    const char* delim = ",<.>/?;:'\"[]{} ";

    char* left = str;
    char* right = strchr(str, '\0') - 1;
    while (left <= right)
    {
        if (strchr(delim, *left)) 
        {
            ++left;
            continue;
        }
        else if (strchr(delim, *right)) 
        {
            --right;
            continue;
        }
        else if (toupper(*left) != toupper(*right))
        {
            return false;
        }
        ++left;
        --right;
    }
    return true;
}

size_t words_count(char* str) 
{
    size_t count = 0;

    const char* delim = ",<.>/?;:'\"[]{} ";
    char* tok = strtok(str, delim);
    while(tok)
    {
        ++count;
        tok = strtok(0, delim);
    }

    return count;
}

int main() 
{
    setlocale(LC_ALL, ".1251");

    puts("Введите строку:");
    char* str = getln();
    puts(is_palindrome(str) ? "Да. Данная строка является палиндромом." : "Нет. Данная строка не является палиндромом");
    printf("Количество слов: %lld", words_count(str));

    free(str);
    return 0;
}