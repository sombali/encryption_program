#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <stdexcept>
#include "cipher.h"
#include "cipherstring.h"
#include "memtrace.h"

char* CaesarCipher::encrypt(char* plainText, char* cipherKey, int length){
        // A sz�veg sz�mokk� alak�t�sa.
        int key = atoi(cipherKey);
        if(key < 0) {
            int tmpKey = abs(key);
            key = tmpKey;
        }
        while(key > 26) {
            key = key - 26;
        }
        if(key <= 48 && key >= 57) {
            throw "A Caesar titkositas szamot var!";
        }
        // A titkos�t�s v�grehajt�sa, annak �j karaktert�mbbe m�sol�sa.
        char* result = new char[length + 1];
        for(int i = 0; i < length; i++) {
            result[i] = (char) (plainText[i] + key);
        }
        result[length] = '\0';
        return result;
    }

char* CaesarCipher::decrypt(char* cipherText, char* cipherKey, int length) {
        char* result = new char[length + 1];
        // A titkos kulcs sz�mm� alak�t�sa.
        int key = atoi(cipherKey);
        // A titkos sz�m abszol�t�rt�ke, hogy j� ir�nyba tol�djon.
        if(key > 0) {
            int tmpKey = key*(-1);
            key = tmpKey;
        }
        while(key < -26) {
            key = key + 26;
        }
        // A visszafejt�s v�grehajt�sa.
        for(int i = 0; i < length; i++) {
            result[i] = (char) (cipherText[i] + key);
        }
        result[length] = '\0';
        return result;
}

char* XORCipher::encrypt(char* plainText, char* cipherKey, int length) {
        int cipherKeyLength = strlen(cipherKey);
        // Sz�ml�l�, hogy a titkos kulcsot a titkos�tand� sz�veggel
        // karakterenk�nt lehessen titkos�tani.
        int cipherKeyCounter = 0;
        char* result = new char[length + 1];
        for(int i = 0; i < length; i++) {
            if(cipherKeyCounter < cipherKeyLength) {
                result[i] = plainText[i] ^ cipherKey[cipherKeyCounter++];
            } else {
                cipherKeyCounter = 0;
                result[i] = plainText[i] ^ cipherKey[cipherKeyCounter++];
            }
        }
        result[length] = '\0';
        return result;
}

char* XORCipher::decrypt(char* cipherText, char* cipherKey, int length) {
        int cipherKeyLength = strlen(cipherKey);
        int cipherKeyCounter = 0;
        char* result = new char[length + 1];
        for(int i = 0; i < length; i++) {
            if(cipherKeyCounter < cipherKeyLength) {
                result[i] = cipherText[i] ^ cipherKey[cipherKeyCounter++];
            } else {
                cipherKeyCounter = 0;
                result[i] = cipherText[i] ^ cipherKey[cipherKeyCounter++];
            }
        }
        result[length] = '\0';
        return result;
}
