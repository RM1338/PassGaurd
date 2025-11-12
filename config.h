#ifndef CONFIG_H
#define CONFIG_H

// Security Configuration
#define MAX_PASSWORD_LENGTH 128
#define MAX_USERNAME_LENGTH 64
#define MAX_SERVICE_NAME 100
#define ENCRYPTION_KEY 7  // Default Caesar cipher key
#define MAX_CREDENTIALS 100
#define CREDENTIAL_FILE "data/credentials.dat"

// Preprocessor directives for security levels
#define BASIC_ENCRYPTION 1
#define ADVANCED_HASHING 2
#define SECURITY_LEVEL BASIC_ENCRYPTION  // Configurable security feature

#endif