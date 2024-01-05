#include <iostream>
#include <string>

using std::cout;
using std::endl;

class Test {
private:
    int N;
public:
    Test() {
        cout << "Allocated memory for int N at " << &N << endl;
    }
    void setN(int N_in) {
        N = N_in;
    }
    int getN() {
        return N;
    }
    int* getptrN() {
        return &N;
    };
};

int main() {
    Test A;
    A.setN(5);
    int* ptr = A.getptrN();
    cout << A.getN() << endl;
    *ptr = 10;
    cout << ptr << endl;
    cout << A.getN() << endl;
    
    return 0;
}

/*
Ausgabe:
5
0x7fff78aa78bc
10

Warum ist das möglich?
Wenn man eine Membervariable mit "private" einschränkt macht man das, wenn man nicht will dass der Wert an der Adresse frei im Programm manipuliert werden kann. 
*/