#include<stdio.h>
#include<assert.h>

void pythagoras(int n) {
    assert(n >= 0);
    int x = 0;
    int y = 0;
    int z = 0;

    while (++z <= n) {
        y = 0;
        while(++y < z) {
            x = 0;
            while (++x < y) {
                if (x*x + y*y == z*z) {
                    printf("%d, %d, %d\n", x, y, z);
                }
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