#include "credential.h"
#include "encryption.h"
#include "file_handler.h"
#include "config.h"

// Add new credential - CO3: structured programming
int add_credential(Credential *cred) {
    Credential credentials[MAX_CREDENTIALS];
    int count = load_credentials(credentials);
    
    // Check for duplicates - CO2: searching technique
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(credentials[i].service_name, cred->service_name) == 0 &&
            strcmp(credentials[i].username, cred->username) == 0) {
            printf("Credential already exists!\n");
            return 0;
        }
    }
    
    if (count >= MAX_CREDENTIALS) {
        printf("Maximum credentials limit reached!\n");
        return 0;
    }
    
    // Add new credential
    credentials[count] = *cred;
    count++;
    
    // Save to file
    return save_credentials(credentials, count);
}

// Verify credential against stored hash
int verify_credential(const char *service, const char *username, const char *password) {
    Credential credentials[MAX_CREDENTIALS];
    int count = load_credentials(credentials);
    int i;
    
    // Linear search - CO2: searching technique
    for (i = 0; i < count; i++) {
        if (strcmp(credentials[i].service_name, service) == 0 &&
            strcmp(credentials[i].username, username) == 0) {
            
            unsigned long input_hash = hash_password(password);
            
            if (input_hash == credentials[i].password_hash) {
                return 1;  // Verified
            } else {
                return 0;  // Wrong password
            }
        }
    }
    
    return -1;  // Credential not found
}

// Display all stored credentials (without passwords)
void display_credentials() {
    Credential credentials[MAX_CREDENTIALS];
    int count = load_credentials(credentials);
    int i;
    
    if (count == 0) {
        printf("No credentials stored.\n");
        return;
    }
    
    printf("\n%-20s %-20s\n", "Service", "Username");
    printf("----------------------------------------\n");
    
    for (i = 0; i < count; i++) {
        printf("%-20s %-20s\n", credentials[i].service_name, credentials[i].username);
    }
}

// Binary search for credential - CO2: searching technique
int search_credential(const char *service_name, Credential *result) {
    Credential credentials[MAX_CREDENTIALS];
    int count = load_credentials(credentials);
    int i;
    
    // First sort the credentials
    sort_credentials_by_service();
    
    // Binary search
    int left = 0, right = count - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(credentials[mid].service_name, service_name);
        
        if (cmp == 0) {
            *result = credentials[mid];
            return 1;
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return 0;  // Not found
}

// Delete credential by service name
int delete_credential(const char *service_name) {
    Credential credentials[MAX_CREDENTIALS];
    int count = load_credentials(credentials);
    int i, j;
    int found = 0;
    
    for (i = 0; i < count; i++) {
        if (strcmp(credentials[i].service_name, service_name) == 0) {
            // Shift all elements left
            for (j = i; j < count - 1; j++) {
                credentials[j] = credentials[j + 1];
            }
            count--;
            found = 1;
            break;
        }
    }
    
    if (found) {
        save_credentials(credentials, count);
        printf("Credential deleted successfully.\n");
        return 1;
    } else {
        printf("Credential not found.\n");
        return 0;
    }
}

// Bubble sort credentials by service name - CO2: sorting technique
void sort_credentials_by_service() {
    Credential credentials[MAX_CREDENTIALS];
    int count = load_credentials(credentials);
    int i, j;
    Credential temp;
    
    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (strcmp(credentials[j].service_name, credentials[j + 1].service_name) > 0) {
                // Swap
                temp = credentials[j];
                credentials[j] = credentials[j + 1];
                credentials[j + 1] = temp;
            }
        }
    }
    
    save_credentials(credentials, count);
}