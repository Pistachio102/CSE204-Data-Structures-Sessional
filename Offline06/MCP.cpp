#include<stdio.h>
#include<limits.h>


int MCP(int p[], int i, int j)
{
    if(i == j)
        return 0;
    int x;
    int min = INT_MAX;
    int count;


    for (x = i; x <j; x++)
    {
        count = MCP(p, i, x) +
                MCP(p, x+1, j) +
                p[i-1]*p[x]*p[j];

        if (count < min)
            min = count;
    }


    return min;
}

int main()
{
    int A[] = {40, 20, 30, 10, 30};
    int n = sizeof(A)/sizeof(A[0]);

    printf(" %d ",MCP(A, 1, n-1));

   // getchar();
    return 0;
}
