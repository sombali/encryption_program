#include <iostream>
#include "cipher.h"
#include "cipherstring.h"

char* CipherString::encrypt(char* plainStringIn, char* cipherKey, char* cipherType) {
    this->deleteCipherStringIfNotNull();
    this->deleteCipher();
    this->initializeUserDefinedCipher(cipherType);
    this->length = strlen(plainStringIn);
    this->cipherString = this->cipher->encrypt(plainStringIn, cipherKey, this->length);
    return this->cipherString;
}

char* CipherString::decrypt(char* cipherKey, char* cipherType) {
    this->deleteCipher();
    this->initializeUserDefinedCipher(cipherType);
    char* plainText = this->cipher->decrypt(this->cipherString, cipherKey, this->length);
    return plainText;
}


void CipherString::initializeUserDefinedCipher(char* cipherType) {
    if(strcmp("CAESAR", cipherType) == 0) {
        this->cipher = new CaesarCipher();
    } else if(strcmp("XOR", cipherType) == 0) {
        this->cipher = new XORCipher();
    } else {
        throw "Nem tamogatott titkositasi algoritmus!";
    }
}
