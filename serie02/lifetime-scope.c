#include<stdio.h>

int main() {

    int x = 1;
    int y = 2;
    int z = 3;

    printf("(x,y,z) = (%d,%d,%d)\n", x, y, z);
    
    {
        int x = 100;
        y = 2;
        if (x > y) {
            z = x;
        } else {
            z = y;
        }
        
        printf("(x,y,z) = (%d,%d,%d)\n", x, y, z);

        {
            int z = y;
            y = 200;
            
            printf("(x,y,z) = (%d,%d,%d)\n", x, y, z);
        }

        printf("(x,y,z) = (%d,%d,%d)\n", x, y, z);

    }

    printf("(x,y,z) = (%d,%d,%d)\n", x, y, z);





    

    return 0;
}