#include "monty.h"

/**
 * strtow - takes a string and seperates its words
 *
 * @str: string to seperate into words
 * @delims: delimitors to use to delimit words
 *
 * Return: 2D array of pointers to each word
 */

char** strtow(char *str, char *delimiters) {
    char **tokens = NULL;
    size_t token_count = 0;
    const char *token = strtok((char*)str, delimiters);

    while (token != NULL) {
        tokens = (char**)realloc(tokens, (token_count + 1) * sizeof(char*));
        if (tokens == NULL) 
            malloc_error();

        tokens[token_count] = (char*)malloc(strlen(token) + 1);
        if (tokens[token_count] == NULL)
            malloc_error();

        strcpy(tokens[token_count], token);

        token = strtok(NULL, delimiters);
        token_count++;
    }

    tokens = (char**)realloc(tokens, (token_count + 1) * sizeof(char*));
    if (tokens == NULL)
        malloc_error();

    tokens[token_count] = NULL;

    return tokens;
}