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
            if (parse(g+2)== 3 && *(g+2) != '(')
            {
                return 3;
            }
            else if (parse(g+2) != 0)
            {
                return 4;
            }
        }
        return 0;

    case 'A':
        if (checkVariable(g + 1))
        {
            if (parse(g+2)== 3 && *(g+2) != '(')
            {
                return 3;
            }
            else if (parse(g+2) != 0)
            {
                return 5;
            }
        }
        return 0;

    case '(':
        // if parse(g+1) returns 6, it means it has reached ')'
        // and no errors in parsing have been encountered, so we skip ahead
        // to the value after the closing ')'
       if (parse(g+1) == 6 )
       {
           int offset =1;

           while (*(g+offset))
           {
               if (*(g+offset)== ')')
               {
                   offset++;
                    break;
               }
               offset++;
           }
           return parse(g+offset);
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
        if (*(g+1))
        {
            return 6;
        }
        break;
    default:
        return 0;
    }

}

bool isLastParen(char *g)
{
    g++;
    while (*g)
    {
        if (*g == ')') return false;
        g++;
    }
    return true;
}

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
    int numOfCon = 0;
    int count = 0;
    int i;
    char *connective;
    char *A = malloc(Fsize);
    char *start;
//    memcpy(start, g, sizeof(*g));

    while (*g)
    {
        count++;
        if (checkConnective(g)&& *(g-1) == ')' && *(g+1) == '(')
        {
            printf("connective is %c\n", *g);
            connective = g;
            numOfCon++;
        }
        g++;
    }

    for (i = 0; i < count; i++)
    {
        printf("*(g+count) is %c\n", *(start+count));
        *(A+count) = *(start+count);
    }

    if (numOfCon == 1)
    {

    }

    return A;
}

char *parttwo(char *g)
/*
Given a formula (A*B) this should return B
 */
{

    return "B";
}

char bin(char *g)
/*
Given a formula (A*B) this should return the character *
 */
{
    while (*g)
    {
        if (checkConnective(g) && *(g - 1) == ')' && *(g + 1) == '(')
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
        printf("The first part is %s, the binary connective is %c, the second part is %s", partone(name), bin(name), parttwo(name));
    }
    return(1);
}
