#include <stdio.h>
#include "calc.h"
#include "calc2/calc2.h"
#include "calc3.h"

void app_main(void)
{
    int n1 = 3;
    int n2 = 4;
    int resultSum = add(n1, n2);
    printf("sum of %d and %d is %d\n", n1, n2, resultSum);

    int resultSub = sub(n1, n2);
    printf("subtracting %d from %d result in %d\n", n1, n2, resultSub);

    int resultMul = mul(n1, n2);
    printf("%d multiplied %d resulted %d\n", n1, n2, resultMul);
}
