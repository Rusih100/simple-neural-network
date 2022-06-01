#include <iostream>
#include <random_generator.h>
#include <matrix.h>


using namespace std;

int main() {

    cout << "Hello Random! \n";
    Random R(-1, 1, 1);

    for (int i = 0; i < 10; ++i) {
        cout << R.generate() << "\n";
    }

    return 0;
}
