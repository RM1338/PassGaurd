#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function prototypes for encryption
void caesar_encrypt(char *text, int key);
void caesar_decrypt(char *text, int key);
void xor_encrypt(char *text, const char *key);
void xor_decrypt(char *text, const char *key);
unsigned long hash_password(const char *password);

#endif