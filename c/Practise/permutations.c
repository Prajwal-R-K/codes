
// Formula to caluculate number of permutations of set ------ n! = n*(n−1)*(n−2)×  .... 2*1
#include <stdio.h>

#define SWAP(a, b, temp) ((temp) = (a), (a) = (b), (b) = (temp))

void perm(char *list, int i, int n) 
{
    int j, temp;

    if (i == n) 
    {//OR  printf("\n%s",list);
        for (j = 0; j <= n; j++)
            printf("%c", list[j]);
        printf("\n");
    } 
    else 
    {
        for (j = i; j <= n; j++) 
        {
            SWAP(list[i], list[j], temp);
            perm(list, i + 1, n);
            SWAP(list[i], list[j], temp);   // Convert to original list ---- ABC
        }
    }
}

int main() {
    char str[] = "ABC";
    // printf("%d",sizeof(str))  -- Gives 4 because it counts NULL(\0) character also
    int length = sizeof(str) / sizeof(str[0])-1;  // Gives 3
    perm(str, 0, length-1);

    return 0;
}
