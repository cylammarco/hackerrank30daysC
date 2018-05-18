#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int N;
    scanf("%i", &N);
    
    for (int k=1; k<=N; k++) {
        
        char st[10001];
        char s1[5001];
        char s2[5001];
        
        scanf("%s", st);
        int length = strlen(st);

        int so=0;
        int se=0;
        
        for (int i=0; i<length; i++) {
            if (i%2==1) {
                s1[so] = st[i];
                so++;
            }
            else {
                s2[se] = st[i];
                se++;
            }
        }
        
        s1[so] = '\0';
        s2[se] = '\0';

        printf("%s %s\n", s2, s1);

    }
    
    return 0;
}
