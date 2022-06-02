#include <iostream>
#include <random_generator.h>
#include <matrix.h>


using namespace std;

int main() {

    cout << "Hello Random! \n";
    Random R(-10, 10, 4);


    for (int i = 0; i < 50; ++i) {
        cout << R.generate() << "\n";
    }
    return 0;
}
