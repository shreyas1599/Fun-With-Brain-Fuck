/* A simple brainfuck interpreter */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned char tape[30000] = {0};
unsigned char* ptr = tape;

void bf_to_c(char* input) {
    char current;
    size_t loop;

    for(size_t i = 0; input[i]!=0 ; i++)
    {
        current = input[i];
        switch(current) {
            case '>': ++ptr;
                break;
            case '<': --ptr;
                break;
            case '+': ++*ptr;
                break;
            case '-': --*ptr;
                break;
            case ',': *ptr = getchar();
                break;
            case '.': putchar(*ptr);
                break;
            case '[': continue;
            case ']': if(*ptr) {
                loop = 1;
                while(loop > 0) {
                    current = input[--i];
                    if(current == '[') {
                        loop--;
                    }
                    if(current == ']') {
                        loop++;
                    }
                }
            }
                break;
        }  
    }
}

int main()
{
    bf_to_c(">+++++++++[<++++++++>-]<.>+++++++[<++++>-]<+.+++++++..+++.[-]>++++++++[<++++>-] <.>+++++++++++[<++++++++>-]<-.--------.+++.------.--------.[-]>++++++++[<++++>- ]<+.[-]++++++++++."); //Prints hello world
    return 0;
}