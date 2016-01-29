#include <stdio.h>
#include <string.h>   /* for all the new-fangled string functions */
#include <stdlib.h>     /* malloc, free, rand */


const int Fsize = 50;
int no_edges;
int no_nodes;
int i;
const int cases = 6;

char *partOne(char *g);
char *partTwo(char *g);
char bin(char *g);

int parse(char *g)
{
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
        if (parse(g + 1) > 5 )
        {
	  printf("parsing ahead\n");
            return parse(g + parse(g + 1));
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
        if (*(g + 1) && parse(g + 1) != 0)
        {
            int count = 0;
            while (*g != '(')
            {
                count= count+1;
                g=g-1;
            }
            return count;
        }
	else if (*(g+1) && parse(g+1) == 0)
	  {
	    return 0;
	  }
        return 1;
    default:
        return 0;
    }
}

int checkPredicate(char *g)
{
    if (*g == 'X')
    {
        return 1;
    }
    return 0;
}

int checkVariable(char *g)
{
    if (*g == 'x' || *g == 'y' || *g == 'z')
        return 1;
    return 0;
}

int checkExist(char *g)
{
    if (*g == 'E')
    {
        return 1;
    }
    return 0;
}
int checkAll(char *g)
{
    if (*g == 'A')
    {
        return 1;
    }
    return 0;
}

int checkConnective(char *g)
{
    if (*g == '^' || *g == 'v' || *g == '>')
        return 1;
    return 0;
}

int eval(char *nm, int edges[no_edges][2], int size, int V[3])
{
    /* returns 1 if formula nm evaluates to true in graph with 'size' nodes,
    no_edges edges, edges stored in 'edges', variable assignment V.
    Otherwise returns 0.*/
    char var1, var2, var3, next;
    char *a = malloc(Fsize);
    char *b = malloc(Fsize);
    char con;
    int i,    isTrue, offset;

    switch (*nm)
    {
    case 'X':
        // now assess graph in this part
        var1 = *(nm + 2);
        var2 = *(nm + 3);
        isTrue = 0;

        for (i = 0; i < no_edges; i++)
        {
            if (var1 == 'x' && V[0] == edges[i][0])
            {
                if (var2 == 'x' && V[0] == edges[i][1])
                {
                    isTrue = 1;
                    break;
                }
                else if (var2 == 'y' && V[1] == edges[i][1])
                {
                    isTrue = 1;
                    break;
                }
                else if (var2 == 'z' && V[2] == edges[i][1])
                {
                    isTrue = 1;
                    break;
                }
            }
            else if (var1 == 'y' && V[1] == edges[i][0])
            {
                if (var2 == 'x' && V[0] == edges[i][1])
                {
                    isTrue = 1;
                    break;
                }
                else if (var2 == 'y' && V[1] == edges[i][1])
                {
                    isTrue = 1;
                    break;
                }
                else if (var2 == 'z' && V[2] == edges[i][1])
                {
                    isTrue = 1;
                    break;
                }
            }
            else if (var1 == 'z' && V[2] == edges[i][0])
            {
                if (var2 == 'x'  && V[0] == edges[i][1])
                {
                    isTrue = 1;
                    break;
                }
                else if (var2 == 'y'  && V[1] == edges[i][1])
                {
                    isTrue = 1;
                    break;
                }
                else if (var2 == 'z' && V[2] == edges[i][1])
                {
                    isTrue = 1;
                    break;
                }
            }
        }
        return isTrue;

    case 'A':
        // check characters ahead to determine all quanitfiers.
        // if a single assignment of bound variable returns 0, then whole thing is false.
        for (i = 0; i < size; i++)
        {
            next = *(nm + 1);
            if (next == 'x')
                V[0] = i;
            else if (next == 'y')
                V[1] = i;
            else if (next == 'z')
                V[2] = i;

            if (eval((nm + 2), edges, size, V) == 0)
            {
                return 0;
            }
        }
        return 1;

    case 'E':
        // if not a single assignment returns 1, then 0;
        for (i = 0; i < size; i++)
        {
            next = *(nm + 1);
            if (next == 'x')
                V[0] = i;
            else if (next == 'y')
                V[1] = i;
            else if (next == 'z')
                V[2] = i;

            if (eval((nm + 2), edges, size, V) == 1)
            {
                return 1;
            }
        }
        return 0;

    case '(':
        a = partOne(nm);
        b = partTwo(nm);
        con = bin(nm);

        int aEval = eval(a, edges, size, V);
        int bEval = eval(b, edges, size, V);

        if (con == '>')
        {
            if (aEval == 1 && bEval == 0)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        else if (con=='^')
        {
            if (aEval == 1 && bEval == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if (con == 'v')
        {
            if (aEval == 1 || bEval == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    case '-':
        if (eval((nm + 1), edges, size, V) == 1)
        {
            return 0;
        }
        else if (eval((nm + 1), edges, size, V) == 0)
        {
            return 1;
        }
    default:
        return 0;
    }
}

char *partOne(char *g)
{
    char *a = malloc(Fsize);
    int parenCount = 0;
    int i;
    int aIndex = 0;
    for (i = 0; g[i] && i < Fsize; i++)
    {
        if (g[i] == '(' && i == 0)
        {
            continue;
        }
        else if (g[i] == '(')
        {
            parenCount++;
        }
        if (g[i] == ')')
        {
            parenCount--;
        }
        if (checkConnective(g + i) && parenCount == 0)
        {
            break;
        }

        a[aIndex] = g[i];
        aIndex++;
    }
    a[aIndex] = '\0';
    return a;
}

// should be called on the first character of part A
char *partTwo(char *g)
{
    char *b = malloc(Fsize);
    int parenCount = 0;
    int i;
    int bIndex = 0;
    int passedConn = 0;

    for (i = 0; g[i] && i < Fsize; i++)
    {
        if (g[i] == '(' && i == 0)
        {
            continue;
        }
        else if (g[i] == '(')
        {
            parenCount++;
        }
        if (g[i] == ')')
        {
            parenCount--;
        }
        if (checkConnective(g + i) && parenCount == 0)
        {
            int j = i + 1;
            parenCount = 0;
            while (g[j])
            {
                if (g[j] == '(')
                {
                    parenCount++;
                }
                if (g[j + 1] == ')' && parenCount == 0)
                {
                    b[bIndex] = g[j];
                    bIndex++;
                    break;
                }
                else if (g[j] == ')' && parenCount > 0)
                {
                    parenCount--;
                    if (parenCount == 0)
                    {
                        b[bIndex] = g[j];
                        bIndex++;
                        break;
                    }
                }
                b[bIndex] = g[j];
                bIndex++;
                j++;
            }
        }
    }
    b[bIndex] = '\0';
    return b;
}

char bin (char *g)
{
    int parenCount = 0;
    int i = 0;
    while (g[i])
    {
        if (g[i] == '(' && i == 0)
        {
            i++;
            continue;
        }
        if (g[i] == '(')
        {
            parenCount++;
        }
        if (g[i] == ')')
        {
            parenCount--;
        }
        if (checkConnective(g + i) && parenCount == 0)
        {
            return g[i];
        }
        i++;
    }
}

int main()
{
    char *name = malloc(Fsize); /*create space for the formula*/
    FILE *fp, *fpout;

    /* reads from input.txt, writes to output.txt*/
    if ((  fp = fopen("input2.txt", "r")) == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    if ((  fpout = fopen("output.txt", "w")) == NULL)
    {
        printf("Error opening file");
        exit(1);
    }

    int j;
    for(j = 0; j < cases; j++)
    {
        fscanf(fp, "%s %d %d", name, &no_nodes, &no_edges); /*read formula, number of nodes, number of edges*/
        int edges[no_edges][2];  /*Store edges in 2D array*/
        for(i = 0; i < no_edges; i++)	 fscanf(fp, "%d%d", &edges[i][0], &edges[i][1]); /*read all the edges*/

        /*Assign variables x, y, z to nodes */
        int W[3];
        /*Store variable values in array
        value of x in V[0]
        value of y in V[1]
        value of z in V[2] */
        for(i = 0; i < 3; i++)  fscanf(fp, "%d", &W[i]);
        int p = parse(name);

        switch(p)
        {
        case 0:
            fprintf(fpout, "%s is not a formula.  ", name);
            break;
        case 1:
            fprintf(fpout, "%s is an atomic formula.  ", name);
            break;
        case 2:
            fprintf(fpout, "%s is a negated formula.  ", name);
            break;
        case 3:
            fprintf(fpout, "%s is a binary connective formula.  ", name);
            break;
        case 4:
            fprintf(fpout, "%s is an existential formula.  ", name);
            break;
        case 5:
            fprintf(fpout, "%s is a universal formula.  ", name);
            break;
        default:
            fprintf(fpout, "%s is not a formula.  ", name);
            break;
        }

        /*Now check if formula is true in the graph with given variable assignment. */
        if (eval(name, edges, no_nodes,  W) == 1)	fprintf(fpout, "The formula %s is true in G under W\n", name);
        else fprintf(fpout, "The formula %s is false in G under W\n", name);
    }

    fclose(fp);
    fclose(fpout);
    free(name);
    return 1;
}
