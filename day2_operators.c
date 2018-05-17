#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    double meal_cost; 
    scanf("%lf", &meal_cost);
    int tip_percent; 
    scanf("%i", &tip_percent);
    int tax_percent; 
    scanf("%i", &tax_percent);
    
    double total_cost = meal_cost * (1. + tip_percent * 0.01 + tax_percent * 0.01);
    
    printf("%s", "The total meal cost is ");
    printf("%.0f", total_cost);
    printf("%s", " dollars.");
    
    return 0;
}
