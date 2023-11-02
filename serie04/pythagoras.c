#include<stdio.h>
#include<assert.h>

void pythagoras(int n) {
    int x = 0;
    int y = 1;
    int z = 2;
    while (++z <= n) {
        while(++y < z) {
            while (++x < y) {
                printf("%d, %d, %d\n", x, y, z);
            }            
        }
    }
}

int main() {
    int n = 0;

    printf("n=");
    scanf("%d", &n);

    pythagoras(n);

    return 0;
}