#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL 200

int comp_inc (char x, char y)
{
    if(x > y)
    return 1;
    else   
    return 0;
}
int comp_dec (char x, char y)
{
    if(x > y)
    return 0;
    else
    return 1;
}

void bubble_sort(char *buf, int length, int(*compare)(char,char))
{
    int i, j;
    char tmp;

    for (i = 0; i< (length - 1); i++)
    {
        for (j = i; j< length; j++)
        {
            if (compare(buf[i],buf[j]) > 0)
            {
                tmp = buf[i];
                buf[i] = buf[j];
                buf[j] = tmp;   
            }
        }
    }
}

void print_result (char *buf)
{
    int i;
    printf("    Result: %s \n", buf);
}

int main (void)
{
    int i, flag, length;
    char *buf = (char*)malloc(TOTAL*sizeof(char));
    int (*compare[2])(char,char)={comp_inc,comp_dec};

    while (1)
    {        
        //menu 
        printf("Please enter (0) increasing or (1) descesing sort: ");
        scanf("%d", &flag);
        if (flag < 0 || flag > 1)
        {
            printf("ERROR: no such option! \n\n");
            continue;
        }
        
        printf("  Please enter a string: ");
        scanf("%s",buf);
        length=strlen(buf);
        //here you can modify to function pointer array
        bubble_sort(buf, length, compare[flag]);
        print_result(buf);
    }
}
