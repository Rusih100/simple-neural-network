#include <iostream>
#include <random_generator.h>
#include <matrix.h>

using namespace std;

void test_for_matrix(){

    Matrix A(2, 3);
    A.random_fill(0, 1, 3);
    A.print();

    cout << "\n";

    Matrix B(3, 2);
    B.random_fill(0, 1, 3);
    B.print();

    cout << "\n";
    Matrix C = A * B;
    C.print();
}

int main() {
    srand(time(nullptr));
    test_for_matrix();


    return 0;
}
