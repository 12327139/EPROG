#include <iostream>

bool find_zero(int* a, int n, int* p) {
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            *p = i;
            return true;
        }
    }
    return false;
}

bool find_zero(double* a, int n, int* p, int tolerance = 0) {
    for (int i = 0; i < n; i++) {
        if (abs(a[i]) < tolerance) {
            *p = i;
            return true;
        }
    }
    return false;
}

int main() {
    int n = 0;
    std::cout << "n="; 
    std::cin >> n;

    int* a = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        std::cout << "a[" << i << "]=";
        std::cin >> a[i];
    }

    int p = 0;
    bool contains_zero = find_zero(a, n, &p);

    std::cout << contains_zero << std::endl;
    std::cout << p << std::endl;

    return 0;
}