#include <iostream>
#include <matrix.h>

using namespace std;

int main() {

    cout << "Hello Matrix! \n";
    Matrix A(1, 2);
    A[0][0] = 1;
    A[0][1] = 2;

    A.print();
    cout << "\n";

    auto B = A.T();
    B.print();

    return 0;
}
