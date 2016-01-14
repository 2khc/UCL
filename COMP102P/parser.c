#include <stdio.h>
#include <string.h>   /* for all the new-fangled string functions */
#include <stdlib.h>     /* malloc, free, rand */
#include <stdbool.h>
/*  The main program calls procedures parse, partone, parttwo and bin
which are not implemented here.
*/

bool checkVariable(char *g);
bool checkPredicate(char *g);
bool checkAll(char *g);
bool checkExist(char *g);
bool isLastParen(char *g);
bool checkConnective(char *g);
char bin(char *g);

int Fsize = 50; /*big enough for our formulas*/

int parse(char *g)
/* returns 0 for non-formulas, 1 for atoms, 2 for negations, 3 for binary
connective fmlas, 4 for existential and 5 for universal formulas.*/
{
    /*
    count (, increment count
           see ), decrement count.
           if at anypoint count < 0 then false,
            if count = 0 by end of string then true, otherwise false
    */
//    unsigned char *first;
////    if (!*(g - 1))
////        first = g;
//        first = &g[0];
////    first = g;
////    printf("First is %i\n", first);
//    printf("First is %c\n", *(first+1));
    /* returns 0 for non-formulas, 1 for atoms, 2 for negations, 3 for binary
    connective fmlas, 4 for existential and 5 for universal formulas.*/
    switch(*g)
    {
    case 'X':
        if (*(g + 1) == '[' && checkVariable(g + 2) && checkVariable(g + 3) && *(g + 4) == ']')
        {
            if (*(g + 5))
            {
                return parse(g + 5);
            }
            else
            {
                return 1;
            }

        }
        return 0;

    case 'E':
        if (checkVariable(g + 1))
        {
            if (parse(g + 2) == 3 && *(g + 2) != '(')
            {
                return 3;
            }
            else if (parse(g + 2) != 0)
            {
                return 4;
            }
        }
        return 0;

    case 'A':
        if (checkVariable(g + 1))
        {
            if (parse(g + 2) == 3 && *(g + 2) != '(')
            {
                return 3;
            }
            else if (parse(g + 2) != 0)
            {
                return 5;
            }
        }
        return 0;

    case '(':
        // if parse(g+1) returns 6, it means it has reached ')'
        // and no errors in parsing have been encountered, so we skip ahead
        // to the value after the closing ')'
//        int a = parse(g+1);
        if (parse(g + 1) > 5 )
        {
            return parse(g + parse(g+1));
        }
        return parse(g + 1);

    case '>':
        if (parse(g + 1) !=  0)
        {
            return 3;
        }
        return 0;
    case '^':
        if (parse(g + 1) !=  0)
        {
            return 3;
        }
        return 0;
    case 'v':
        if (parse(g + 1) !=  0)
        {
            return 3;
        }
        return 0;
    case '-':
        if (parse(g + 1) != 0)
        {
            return 2;
        }
        return 0;
    case ')':
        // return address of the closing brackets instead.
        // if returning address each case needs to consider address isntead of 123450
        if (*(g + 1) && parse(g+1) != 0)
        {
            int count = 0;
            while (*g != '(')
            {
                count++;
                g--;
            }
            return count;
        }
        break;
    default:
        return 0;
    }
}

//bool isLastParen(char *g)
//{
//    g++;
//    while (*g)
//    {
//        if (*g == ')') return false;
//        g++;
//    }
//    return true;
//}

bool checkPredicate(char *g)
{
    if (*g == 'X')
    {
        return true;
    }
    return false;
}

bool checkVariable(char *g)
{
    if (*g == 'x' || *g == 'y' || *g == 'z')
        return true;
    return false;
}

bool checkExist(char *g)
{
    if (*g == 'E')
    {
        return true;
    }
    return false;
}
bool checkAll(char *g)
{
    if (*g == 'A')
    {
        return true;
    }
    return false;
}

bool checkConnective(char *g)
{
    if (*g == '^' || *g == 'v' || *g == '>')
        return true;
    return false;
}

char *partone(char *g)
/*
Given a formula (A*B) this should return A
 */
{
    const size_t maxLength = 49;

    char *a = malloc(maxLength + 1);

    if (!a)
    {
        perror("couldn't allocate memory");
        exit(EXIT_FAILURE);
    }

    size_t i;
    size_t counter = 0;
    int parenCount = 0;
    size_t start;
    size_t end;
    for (i =0; g[i] && i < maxLength; ++i)
    {
//        printf("%c\n",g[i]);

        if (g[i - 1] == '(' && g[i] != '(')
        {
            if (parenCount > 1)
            {
                start = i - 1;
            }
            else
            {
                start = i;

            }
//            parenCount++;
//            printf("start stored and is %i\n", start);
        }
        else if (g[i] == '(')
        {
            parenCount++;
//            printf("( found\n");
        }
        else if (g[i] == ')')
        {
            parenCount--;
        }

//        printf("g[i] is %c\n", g[i]);
//        printf("parenCount is %i\n", parenCount);


        if (checkConnective(&g[i]) && parenCount == 1 && (g[i - 1] == ')' || g[i + 1] == '('))
        {
            end = i - 1;

//            printf("end is %i\n", end);
//            printf("connective is %c\n", checkConnective(&g[i]));
            size_t j;
            for (j = start; g[j] && j < end; ++j)
            {
//                printf("something");
//                printf("%c",g[j]);
                a[counter] = g[j];
                ++counter;
            }
            break;
        }
        else if (checkConnective(&g[i]) && parenCount == 1 && g[i - 1] == ']')
        {
            end = i;
            size_t j;
            for (j = start; g[j] && j < end; ++j)
            {
//                printf("something");
//                printf("%c",g[j]);
                a[counter] = g[j];
                ++counter;
            }
            break;
        }

    }
    a[counter] = '\0';

    return a;
}

char *parttwo(char *g)
/*
Given a formula (A*B) this should return B
 */
{
    char *b = malloc(Fsize);
    int maxLength = Fsize;
    int parenCount = 0;
    int i;
    int bCount = 0;
    for ( i = 0; i < maxLength; i++ )
    {
        if (g[i] == '(')
        {
            parenCount++;
        }
        else if (g[i] == ')')
        {
            parenCount--;
        }

        if (parenCount == 1 && checkConnective(&g[i]) && (g[i-1] == ')' || g[i-1] == ']'))
        {
            int j = i+1;
//            for (j = i + 1; j < maxLength; j++)
//            {
//
//            }
            while (g[j+1])
            {
                b[bCount] = g[j];
                bCount++;
                j++;
            }
        }
        b[bCount] = '\0';
    }

    return b;
}

char bin(char *g)
/*
Given a formula (A*B) this should return the character *
 */
{
    int parenCount = 0;
    while (*g)
    {
        if (*g == '(')
        {
            parenCount++;
        }
        else if (*g == ')')
        {
            parenCount--;
        }

        if (checkConnective(g) && parenCount == 1 && (*(g - 1) == ')' || *(g - 1) == ']'))
        {
            return *g;
        }
        g++;
    }
}


int main()
{
    /*Input a string and check if its a formula*/
    char *name = malloc(Fsize);
    printf("Enter a formula:");
    scanf("%s", name);
//  printf("\n");
    int p = parse(name);
    switch(p)
    {
    case 0:
        printf("Not a formula");
        break;
    case 1:
        printf("An atomic formula");
        break;
    case 2:
        printf("A negated formula");
        break;
    case 3:
        printf("A binary connective formula");
        break;
    case 4:
        printf("An existential formula");
        break;
    case 5:
        printf("A universal formula");
        break;
    default:
        printf("Not a formula");
        break;
    }
    printf("\n");
    if (p == 3)
    {
        printf("The first part is %s,\n the binary connective is %c,\n the second part is %s", partone(name), bin(name), parttwo(name));
    }
    free(name);
    return(1);
}
