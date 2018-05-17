#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i = 4;
    double d = 4.0;
    char s[] = "HackerRank ";
        
    // Declare second integer, double, and String variables.
    int i2;
    double d2;
    char s2[100];
    char dest[1000];

    strcpy(dest, s);

    // Read and save an integer, double, and String to your variables.
    scanf("%i\n", &i2);
    scanf("%lf\n", &d2);
    fgets(s2, 99, stdin);
    
    // Print the sum of both integer variables on a new line.
    i += i2;
    printf("%i\n", i);

    // Print the sum of the double variables on a new line.
    d += d2;
    printf("%.1lf\n", d);
    
    // Concatenate and print the String variables on a new line
    strcat(dest, s2);

    // The 's' variable above should be printed first.
    printf("%s\n", dest);

    return 0;
}
