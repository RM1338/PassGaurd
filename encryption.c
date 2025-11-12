#include "encryption.h"
#include "config.h"

// Caesar cipher encryption - CO1: operators, expressions, control statements
void caesar_encrypt(char *text, int key) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = ((text[i] - 'a' + key) % 26) + 'a';
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ((text[i] - 'A' + key) % 26) + 'A';
        } else if (text[i] >= '0' && text[i] <= '9') {
            text[i] = ((text[i] - '0' + key) % 10) + '0';
        }
    }
}

// Caesar cipher decryption
void caesar_decrypt(char *text, int key) {
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = ((text[i] - 'a' - key + 26) % 26) + 'a';
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ((text[i] - 'A' - key + 26) % 26) + 'A';
        } else if (text[i] >= '0' && text[i] <= '9') {
            text[i] = ((text[i] - '0' - key + 10) % 10) + '0';
        }
    }
}

// XOR encryption (stronger than Caesar) - CO1: operators and expressions
void xor_encrypt(char *text, const char *key) {
    int text_len = strlen(text);
    int key_len = strlen(key);
    int i;
    
    for (i = 0; i < text_len; i++) {
        text[i] = text[i] ^ key[i % key_len];
    }
}

// XOR decryption (same as encryption)
void xor_decrypt(char *text, const char *key) {
    xor_encrypt(text, key);  // XOR is symmetric
}

// Simple hash function for password verification - CO1: expressions
unsigned long hash_password(const char *password) {
    unsigned long hash = 5381;
    int c;
    
    while ((c = *password++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    
    return hash;
}