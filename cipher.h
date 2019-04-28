#ifndef CIPHER_H_INCLUDED
#define CIPHER_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <stdexcept>
#include "memtrace.h"

/**
 * Abstract osztály. Minden titkosító osztály őse.
 */
class Cipher {
public:
    /**
     * Az abstract osztály virtuális titkosító metódusa.
     * A paraméterül kapott értéket a szintén paraméterül kapott titkos kulccsal titkosítja.
     *
     * @param plainText A titkosítandó szöveg
     * @param cipherKey A titkos kulcs
     * @param length A titkosítandó szöveg hossza
     * @return A titkosított szöveg
     */
    virtual char* encrypt(char* plainText, char* cipherKey, int length) = 0;

    /**
     * Az abstract osztály virtuális visszafejtő metódusa.
     * A paraméterül kapott értéket a paraméterül kapott titkos kulccsal visszafejti eredeti állapotába.
     *
     * @param cipherText A titkosított szöveg
     * @param cipherKey A titkos kulcs
     * @param length A titkosított szöveg hossza
     * @return A visszafejtett szöveg
     */
    virtual char* decrypt(char* cipherText, char* cipherKey, int length) = 0;

    virtual ~Cipher() {}
};


/**
 * Caesar titkosító osztály. Ő végzi a Caesar titkosítást és visszafejtést.
 */
class CaesarCipher : public Cipher {
public:
    char* encrypt(char* plainText, char* cipherKey, int length);

    char* decrypt(char* cipherText, char* cipherKey, int length);
};

/**
 * XOR titkosító osztály. Ő végzi a XOR titkosítást és visszafejtést.
 */
class XORCipher : public Cipher {
public:
    char* encrypt(char* plainText, char* cipherKey, int length);

    char* decrypt(char* cipherText, char* cipherKey, int length);
};


#endif // CIPHER_H_INCLUDED
