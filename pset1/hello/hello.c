#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Gets the user's name
    string name = get_string("What's your name?\n");
    printf("Hello, %s!\n", name);
}