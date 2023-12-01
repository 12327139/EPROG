#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int num_digits_of_number_to_base(int number, int base) {
    int num_bin_digits = 1;
    while ((number /= base) >= 1) num_bin_digits++;
    return num_bin_digits;
}

int bin2int(int bin) {
    int summe = 0;
    int num_digits_bin_to_dec = num_digits_of_number_to_base(bin, 10);
    for (int i = 0; i < num_digits_bin_to_dec; i++) {
        summe += bin % 10 * pow(2, i);
        bin /= 10;
    }
    return summe;
}

int main() {
    int bin = 0;

    printf("bin=");
    scanf("%d", &bin);

    printf("Erg: %d\n", bin2int(bin));

    return 0;
}