#include <iostream>
#include "cipherstring.h"
#include "test.h"

void Test::testEncryptFromStdIn() {
    char *plainStringIn = NULL;
    char *cipherKey = NULL;
    char* cipherType = NULL;
    try {
        cout << "Ird be a titkositando uzenetet: " << endl;
        plainStringIn = read(plainStringIn);
        cout << "Ird be a titkos kulcsot: " << endl;
        cipherKey = read(cipherKey);
        cout << "Ird be a titkosito algoritmus tipusat: \n(CAESAR vagy XOR)" << endl;
        cipherType = read(cipherType);
        cout << this->cipherString.encrypt(plainStringIn, cipherKey, cipherType) << endl;
    } catch(const char* p) {
        cout << p << endl;
    }
    delete[] plainStringIn;
    delete[] cipherKey;
    delete[] cipherType;
}

void Test::testDecryptFromStdIn() {
    char* cipherKey = NULL;
    char* plainText = NULL;
    char* cipherType = NULL;
    try {
        cout << "Ird be a titkos kulcsot: " << endl;
        cipherKey = read(cipherKey);
        cout << "Ird be a titkosito algoritmus tipusat: " << endl;
        cipherType = read(cipherType);
        plainText = this->cipherString.decrypt(cipherKey, cipherType);
        cout << plainText << endl;
    } catch(const char* p) {
        cout << p << endl;
    }
    delete[] plainText;
    delete[] cipherKey;
    delete[] cipherType;
}
