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
        // if parse(g+1) returns 6, it means it has reached ')'
        // and no errors in parsing have been encountered, so we skip ahead
        // to the value after the closing ')'
//        int a = parse(g+1);
        if (parse(g + 1) > 5 )
        {
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

int main() {

    /*--JAVA INPUT START--*/
    int tests = 17;
    char *formulas[17] = {
        "AxEyX[xy]",
        "AxEyX[yx]",
        "(X[xy]>-X[yx])",
        "(X[xy]>-X[yx])",
        "(X[xy]>-X[yx])",
        "(ExAyX[yx]>AxEyX[xy])",
        "ExEy(X[xy]^Ex(X[yx]^Ey(X[xy]^ExX[yx])))",
        "ExEy(X[xy]^Ex(X[yx]^Ey(X[xy]^ExX[yx])))", //fail
        "AyX[yz]",
        "ExAyX[yx]",
        "ExEyEz((X[yx]^X[zx])^X[yz])",
        "ExEyEz((X[yx]^X[zx])^X[yz])", //fail
        "ExEy(AzX[zx]^AzX[zy])",
        "ExEyAz(X[zx]^X[zy])", //fail
        "Ax(EyX[xy]vX[zx])",
        "Ex((X[xx]^X[xy])^X[xz])",
        "Ex((X[xx]^X[xy])^X[xz])" //fail
    };
    int sizes[17][2] = {
        { 3, 4 },
        { 3, 4 },
        { 3, 4 },
        { 4, 4 },
        { 4, 4 },
        { 4, 4 },
        { 4, 4 },
        { 4, 4 },
        { 6, 7 },
        { 6, 7 },
        { 4, 4 },
        { 4, 4 },
        { 7, 14 },
        { 7, 14 },
        { 6, 5 },
        { 4, 4 },
        { 4, 3 }
    };
    int edges[17][20][2] = {
        {
            { 0, 1 },
            { 0, 2 },
            { 1, 2 },
            { 2, 2 }
        },
        {
            { 0, 1 },
            { 0, 2 },
            { 1, 2 },
            { 2, 2 }
        },
        {
            { 0, 1 },
            { 0, 2 },
            { 1, 2 },
            { 2, 2 }
        },
        {
            { 0, 1 },
            { 0, 2 },
            { 1, 2 },
            { 2, 2 }
        },
        {
            { 0, 1 },
            { 0, 2 },
            { 1, 2 },
            { 2, 2 }
        },
        {
            { 0, 0 },
            { 1, 0 },
            { 2, 0 },
            { 3, 0 }
        },
        {
            { 0, 1 },
            { 1, 2 },
            { 2, 3 },
            { 3, 0 }
        },
        {
            { 0, 1 },
            { 2, 1 },
            { 2, 3 },
            { 3, 0 }
        },
        {
            { 0, 0 },
            { 1, 0 },
            { 2, 0 },
            { 3, 0 },
            { 4, 0 },
            { 5, 0 },
            { 5, 5 }
        },
        {
            { 0, 0 },
            { 1, 0 },
            { 2, 0 },
            { 3, 0 },
            { 4, 0 },
            { 5, 0 },
            { 5, 5 }
        },
        {
            { 1, 0 },
            { 2, 0 },
            { 3, 0 },
            { 3, 1 }
        },
        {
            { 1, 2 },
            { 2, 0 },
            { 3, 0 },
            { 3, 1 }
        },
        {
            { 0, 0 },
            { 0, 1 },
            { 1, 0 },
            { 1, 1 },
            { 2, 0 },
            { 2, 1 },
            { 3, 0 },
            { 3, 1 },
            { 4, 0 },
            { 4, 1 },
            { 5, 0 },
            { 5, 1 },
            { 6, 0 },
            { 6, 1 }
        },
        {
            { 0, 0 },
            { 0, 1 },
            { 1, 0 },
            { 1, 1 },
            { 2, 0 },
            { 2, 1 },
            { 3, 0 },
            { 3, 1 },
            { 4, 0 },
            { 4, 1 },
            { 5, 0 },
            { 5, 1 },
            { 6, 0 },
            { 6, 1 }
        },
        {
            { 0, 1 },
            { 1, 2 },
            { 2, 3 },
            { 3, 4 },
            { 4, 5 }
        },
        {
            { 3, 0 },
            { 3, 1 },
            { 3, 2 },
            { 3, 3 }
        },
        {
            { 3, 0 },
            { 3, 1 },
            { 3, 2 }
        }
    };
    int assignments[17][3] = {
        { 1, 1, 1 },
        { 1, 1, 1 },
        { 1, 1, 1 },
        { 0, 2, 1 },
        { 2, 2, 1 },
        { 1, 1, 1 },
        { 1, 1, 1 },
        { 1, 1, 1 },
        { 1, 2, 0 },
        { 1, 2, 0 },
        { 1, 1, 1 },
        { 1, 1, 1 },
        { 1, 1, 1 },
        { 1, 1, 1 },
        { 0, 2, 4 },
        { 0, 1, 2 },
        { 0, 1, 2 }
    };
    int results[17] = {
        1,
        0,
        1,
        1,
        0,
        1,
        1,
        0,
        1,
        1,
        1,
        0,
        1,
        1,
        1,
        1,
        0
    };
    int i;
    for(i = 0; i < tests; i++) {
        no_edges = sizes[i][1];
        int type = parse(formulas[i]);
        int result = eval(formulas[i], edges[i], sizes[i][0], assignments[i]);
        printf("Test %d ", i + 1);
        printf(result == results[i] && type != 0 ? "OK" : "FAIL");
        if(type == 0) printf(", NOT A FORMULA");
        printf("\n", i + 1);
    }


//    char *name = malloc(Fsize);
//    scanf("%s", name);
//
//    printf("part one is: %s\npart two is: %s\nbin is %c\n", partOne(name), partTwo(name),bin(name));
}
