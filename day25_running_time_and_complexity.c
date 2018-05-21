#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long int n;
    scanf("%li", &n);
    
    for (long int i=0; i<n; ++i) {
        
        long int p;
        scanf("%li", &p);

        if (p == 1) {
            printf("%s", "Not prime\n");
            continue;
        }

        if (p == 2) {
            printf("%s", "Prime\n");
            continue;
        }

        if (p%2 == 0) {
            printf("%s", "Not prime\n");
            continue;
        }
       
        long int p_max = sqrt(p)/2. + 1;
        
        for (long int j=1; j<p_max; ++j) {
            long int k = j*2 + 1;
            if (p%k == 0) {
                printf("%s", "Not prime\n");
                break;
            }
            if (j == p_max-1) {
                printf("%s", "Prime\n");
            }
        }
        
        
    }
    
    
    return 0;
}
