#ifndef CIPHERSTRING_H_INCLUDED
#define CIPHERSTRING_H_INCLUDED

#include <iostream>
#include "cipher.h"
#include <cstring>
#include "memtrace.h"

/**
 * Cipher String osztály. Ő tárolja a titkosított szöveget és a hosszát.
 * Referenciával rendelkezik a titkosításra, ennek segítségével titkosítja a kapott szöveget.
 */
class CipherString {
private:
    Cipher* cipher;
    char* cipherString;
    int length;
public:
    /**
     * Publikus, paraméter nélküli konstruktor
     */
    CipherString() {
        this->cipherString = NULL;
        this->cipher = NULL;
    }

    /**
     * Caesar Titkosító metódus, a paraméterül kapott értéket a szintén paraméterül kapott kulccsal titkosítja.
     * a paraméterként kapott titkosító algoritmus típusától függően.
     *
     * @param plainStringIn A titkosítandó szüöveg
     * @param cipherKey A titkos kulcs
     * @param cipherType A titkosító algoritmus típusa
     * @return A titkosított szöveg
     */
    char* encrypt(char* plainStringIn, char* cipherKey, char* cipherType);

    /**
     * Caesar visszafejtő metódus, a paraméterül kapott kulccsal visszafejti az osztályban tárolt titkos szöveget,
     * a paraméterként kapott titkosító algoritmus típusától függően.
     *
     * @param cipherKey A titkos kulcs
     * @param cipherType A titkosító algoritmus típusa
     * @return Az osztály által tárolt szöveg visszafejtett változata
     */
    char* decrypt(char* cipherKey, char* cipherType);

    /**
     * Összehasonlítja a titkosítási módszereket a felhasználó által beírt
     * titkosítási algoritmussal, amennyiben az egyezik, inicializál.
     * Ha nem támogatott titkosítási algoritmust ír be a felhasználó, akkor
     * kivételt dob.
     * @param cipherType A titkosítási algoritmus típusa
     * @return nincsen
     */
    void initializeUserDefinedCipher(char* cipherType);

    /**
     * Destruktor.
     */
    virtual ~CipherString() {
        delete[] this->cipherString;
        // Ha nem támogatott titkosítási algoritmust ad meg a felhasználó
        // a kivételkezelés miatt a cipher értéke NULL marad.
        // Csak abban az esetben szabadítható fel, ha nem NULL.
        if(this->cipher != NULL) {
            delete this->cipher;
        }
    }

private:
    /**
     * Felszabadítja a CipherStringet, ha az inicializált.
     */
    void deleteCipherStringIfNotNull() {
        if(this->cipherString != NULL) {
            delete[] this->cipherString;
        }
    }

    /**
     * Felszabadítja a Ciphert, amennyiben az inicializált, majd
     * inicializálja NULL-ra.
     */
    void deleteCipher() {
        if(this->cipher != NULL) {
            delete this->cipher;
            this->cipher = NULL;
        }
    }

    char operator[](int i) {
        return cipherString[i];
    }
};


#endif // CIPHERSTRING_H_INCLUDED
