#include <stdio.h>
#include <stdlib.h>
void main()
{
int b = 15;
int a = 11;
int *b2 = &b;
int c = 5;
b2 = &c;
c = 15;
int *b3 = &c;
int d;
d = 12;
a += c * a + 7;
d = d + a * (a - 2) * 3 % 2;
c *= b + a;
d = c;
printf("\nnilai 1 : %d", b);
printf("\nnilai 2 : %p", *b2);
printf("\nnilai 3 : %d", &b3);
printf("\nnilai 4 : %d", b);
printf("\nnilai 5 : %p", a);
printf("\nnilai 6 : %d", *b2);
}