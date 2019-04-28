#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include <iostream>
#include "cipher.h"
#include "cipherstring.h"
#include <stdexcept>
#include "memtrace.h"

using std::endl;
using std::cout;
using std::cin;

/**
 * Ez az osztály felelős a STD inuptról való beolvasásért illetve a
 * titkosítás lebonyolításáért.
 */
class Test {
private:
    CipherString cipherString;
public:
    /**
     * Ez a metódus bekéri a titkosítandó üzenetet, a titkos kulcsot, illetve
     * a titkosítási algoritmus típusát.
     * Amennyiben nem támogatott a titkosítási algoritmus, elkapja a kivételt.
     */
    void testEncryptFromStdIn();

    /**
     * Ez a metódus bekéri a felhasználótól a titkos kulcsot, illetve a titkosítási
     * algoritmus típusát, és elkapja a kivételt, ha az nem támogatott.
     */
    void testDecryptFromStdIn();

private:
    /**
     * Standard bemenetrõl beolvasó metódus, amely egy bufferba eltárolja az adatokat,
     * majd azzal visszatér.
     * @param buffer Tárolt szöveg
     * @return A tárolt szöveg
     */
    char* read(char* buffer) {
        int bufferLength = 10;
        int length = 0;
        char c;
        buffer = new char[bufferLength];
        while((c = (char) cin.get()) != '\n') {
            buffer[length++] = c;
            if(length >= bufferLength) {
                char *temp = new char[bufferLength * 2];
                for(int i = 0; i < bufferLength; i++) {
                    temp[i] = buffer[i];
                }
                delete[] buffer;
                buffer = temp;
                bufferLength *= 2;
            }
        }
        buffer[length] = '\0';
        return buffer;
    }
};



#endif // TEST_H_INCLUDED
