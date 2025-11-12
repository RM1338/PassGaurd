#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encryption.h"
#include "credential.h"
#include "file_handler.h"
#include "config.h"

// Function prototypes
void display_menu();
void add_new_credential();
void verify_user_credential();
void view_all_credentials();
void search_by_service();
void delete_credential_option();

// Main function - CO1: control statements
int main() {
    int choice;
    
    // Initialize data file
    initialize_data_file();
    
    printf("========================================\n");
    printf(" Password Encryption Tool v1.0\n");
    printf(" Secure Credential Management System\n");
    printf("========================================\n\n");
    
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear newline
        
        switch (choice) {
            case 1:
                add_new_credential();
                break;
            case 2:
                verify_user_credential();
                break;
            case 3:
                view_all_credentials();
                break;
            case 4:
                search_by_service();
                break;
            case 5:
                delete_credential_option();
                break;
            case 6:
                sort_credentials_by_service();
                printf("Credentials sorted successfully.\n");
                break;
            case 7:
                printf("Exiting... Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
        
        printf("\n");
    }
    
    return 0;
}

// Display menu - CO1: control statements
void display_menu() {
    printf("\n========== MAIN MENU ==========\n");
    printf("1. Add New Credential\n");
    printf("2. Verify Credential\n");
    printf("3. View All Credentials\n");
    printf("4. Search Credential\n");
    printf("5. Delete Credential\n");
    printf("6. Sort Credentials\n");
    printf("7. Exit\n");
    printf("===============================\n");
}

// Add credential function - CO3: structured programming
void add_new_credential() {
    Credential cred;
    char password[MAX_PASSWORD_LENGTH];
    char encryption_key_str[32];
    
    printf("\n--- Add New Credential ---\n");
    
    printf("Enter service name: ");
    fgets(cred.service_name, MAX_SERVICE_NAME, stdin);
    cred.service_name[strcspn(cred.service_name, "\n")] = 0;
    
    printf("Enter username: ");
    fgets(cred.username, MAX_USERNAME_LENGTH, stdin);
    cred.username[strcspn(cred.username, "\n")] = 0;
    
    printf("Enter password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);
    password[strcspn(password, "\n")] = 0;
    
    // Hash the password for verification
    cred.password_hash = hash_password(password);
    
#if SECURITY_LEVEL == BASIC_ENCRYPTION
    // Use Caesar cipher
    strcpy(cred.encrypted_password, password);
    caesar_encrypt(cred.encrypted_password, ENCRYPTION_KEY);
    printf("Using Basic Encryption (Caesar Cipher)\n");
#elif SECURITY_LEVEL == ADVANCED_HASHING
    // Use XOR encryption
    printf("Enter encryption key: ");
    fgets(encryption_key_str, 32, stdin);
    encryption_key_str[strcspn(encryption_key_str, "\n")] = 0;
    
    strcpy(cred.encrypted_password, password);
    xor_encrypt(cred.encrypted_password, encryption_key_str);
    printf("Using Advanced Encryption (XOR)\n");
#endif
    
    if (add_credential(&cred)) {
        printf("Credential added successfully!\n");
    } else {
        printf("Failed to add credential.\n");
    }
}

// Verify credential function
void verify_user_credential() {
    char service[MAX_SERVICE_NAME];
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    
    printf("\n--- Verify Credential ---\n");
    
    printf("Enter service name: ");
    fgets(service, MAX_SERVICE_NAME, stdin);
    service[strcspn(service, "\n")] = 0;
    
    printf("Enter username: ");
    fgets(username, MAX_USERNAME_LENGTH, stdin);
    username[strcspn(username, "\n")] = 0;
    
    printf("Enter password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);
    password[strcspn(password, "\n")] = 0;
    
    int result = verify_credential(service, username, password);
    
    if (result == 1) {
        printf("✓ Credential verified successfully!\n");
    } else if (result == 0) {
        printf("✗ Incorrect password!\n");
    } else {
        printf("✗ Credential not found!\n");
    }
}

// View all credentials
void view_all_credentials() {
    printf("\n--- All Stored Credentials ---\n");
    display_credentials();
}

// Search credential by service
void search_by_service() {
    char service[MAX_SERVICE_NAME];
    Credential result;
    
    printf("\n--- Search Credential ---\n");
    printf("Enter service name: ");
    fgets(service, MAX_SERVICE_NAME, stdin);
    service[strcspn(service, "\n")] = 0;
    
    if (search_credential(service, &result)) {
        printf("Found:\n");
        printf("Service: %s\n", result.service_name);
        printf("Username: %s\n", result.username);
    } else {
        printf("Credential not found.\n");
    }
}

// Delete credential option
void delete_credential_option() {
    char service[MAX_SERVICE_NAME];
    
    printf("\n--- Delete Credential ---\n");
    printf("Enter service name: ");
    fgets(service, MAX_SERVICE_NAME, stdin);
    service[strcspn(service, "\n")] = 0;
    
    delete_credential(service);
}