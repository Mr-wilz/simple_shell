#include <stdio.h>

/**
 * main - entry point of program to add input nums
 * Return: sum of input
 */

int main(void)
{
	double num1, num2, sum;

	printf("Enter first number: ");
	scanf("%lf", &num1);
	printf("Enter second number: ");
	scanf("%lf", &num2);

	sum = num1 + num2;

	printf("Sum: %.2lf\n", sum);
}
