#include <iostream>
#include "cipher.h"
#include "test.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    Test cipherStringTest;
    cout << "Test Encrypt..." << endl;
    cipherStringTest.testEncryptFromStdIn();
    cout << "Test Encrypt... done!" << endl;
    cout << "Test Decrypt..." << endl;
    cipherStringTest.testDecryptFromStdIn();
    cout << "Test Decrypt... done!" << endl << endl;
    return 0;
}
