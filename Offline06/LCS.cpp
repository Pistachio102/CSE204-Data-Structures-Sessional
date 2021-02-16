#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;


void lcs( char *X, char *Y, int m, int n )
{
   int L[m+1][n+1];


   for (int i=0; i<=m; i++)
   {
     for (int j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }

   // To print LCS
   int index = L[m][n];

   // Create a character array to store the lcs string
   char lcs[index+1];
   lcs[index] =' '; // Set the terminating character

   // Start from the right-most-bottom-most corner and
   // one by one store characters in lcs[]
   int i = m, j = n;
   while (i > 0 && j > 0)
   {

      if (X[i-1] == Y[j-1])
      {
          lcs[index-1] = X[i-1];
          i--; j--; index--;
      }


      else if (L[i-1][j] > L[i][j-1])
         i--;
      else
         j--;
   }


   cout << "LCS of " << X << " and " << Y << " is " << lcs;
}


int main()
{
  char X[] = "AGGTAB";
  char Y[] = "GXTXAYB";
  int m = strlen(X);
  int n = strlen(Y);
  lcs(X, Y, m, n);
  return 0;
}
