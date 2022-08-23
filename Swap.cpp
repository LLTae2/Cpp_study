#include <stdio.h>
void myswap(int *a, int *b) 
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    myswap(&a, &b);
    printf("%d %d", a, b);
}