#include <iostream>
using std::cout;
using std::endl;

class Test {
private:
    int N;
public:
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

- Warum ist das möglich? Erklären Sie, warum das schlechter Programmierstil ist.
Wenn man eine Membervariable mit "private" einschränkt macht man das wenn man nicht will, 
dass der Wert an der Adresse frei im Programm manipuliert werden kann. 
Auf die Adresse einer private-Membervariable hat man außerhalb der Klasse keinen Zugriff. 
Wenn man aber eine public-Methode schreibt, die die Adresse einer private-Membervariable zurückgibt,
dann hat man auch außerhalb der Klasse Zugriff auf die Adresse der private-Membervariable. 
Somit kann der Wert der Membervariable unkontrolliert verändert werden, was man eigentlich
durch "private" verhindern will. Wenn man auch außerhalb der Klasse Zugriff auf die Membervariable will,
dann sollte sie als public-Membervariable definiert werden.
*/