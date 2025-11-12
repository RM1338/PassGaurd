#ifndef CREDENTIAL_H
#define CREDENTIAL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure for credential storage - CO3: structured programming
typedef struct {
    char service_name[100];
    char username[64];
    char encrypted_password[128];
    unsigned long password_hash;
} Credential;

// Function prototypes
int add_credential(Credential *cred);
int verify_credential(const char *service, const char *username, const char *password);
void display_credentials();
int search_credential(const char *service_name, Credential *result);
int delete_credential(const char *service_name);
void sort_credentials_by_service();  // CO2: sorting techniques

#endif