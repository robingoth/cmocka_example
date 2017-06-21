#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double add(double a, double b)
{
    return a + b;
}

double subtract(double a, double b) 
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}

double divide(double a, double b)
{
    if (b == 0) {
	printf("ERROR: Cannot divide by zero.\n");
	return 0;
    }

    return a / b;
}

double pow_of_sum(double a, double b)
{
    return pow(a + b, a + b);
}

/*
int main(int argc, char **argv) {
    if (argc != 4) {
	printf("Usage: ./calc num1 operation num2.\n");
	exit(-1);
    }

    char operation;
    if (strlen(argv[2]) != 1) {
	printf("Supported operations: + - * /\n");
	exit(-1);
    } else {
	operation = argv[2][0];
    }

    double a, b;

    a = strtod(argv[1], NULL);
    b = strtod(argv[3], NULL);

    switch (operation) {
	case '+':
	    printf("Result = %.2f\n", add(a, b));
	    break;
	case '-':
	    printf("Result = %.2f\n", subtract(a, b));
	    break;
	case '*':
	    printf("Result = %.2f\n", multiply(a, b));
	    break;
	case '/':
	    printf("Result = %.2f\n", divide(a, b));
	    break;
	default:
	    printf("ERROR: operation %c not supported.\n", operation);
	    exit(-1);
    }

    return 0;
}
*/
