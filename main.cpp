#include <iostream>
#include <random_generator.h>
#include <matrix.h>


using namespace std;

int main() {

    Matrix A(2, 3);
    A.random_fill(0, 10);
    A.print();

    cout << "\n";

    Matrix B(3, 2);
    B.random_fill(0, 10);
    B.print();

    cout << "\n";
    Matrix C = A * B;
    C.print();

    return 0;
}
