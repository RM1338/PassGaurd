#include "file_handler.h"
#include "config.h"

// Save credentials to file - CO4: file handling
int save_credentials(Credential *credentials, int count) {
    FILE *file = fopen(CREDENTIAL_FILE, "wb");
    
    if (file == NULL) {
        printf("Error: Unable to open file for writing.\n");
        return 0;
    }
    
    // Write count first
    fwrite(&count, sizeof(int), 1, file);
    
    // Write credentials - CO4: pointers for data processing
    fwrite(credentials, sizeof(Credential), count, file);
    
    fclose(file);
    return 1;
}

// Load credentials from file - CO4: file handling
int load_credentials(Credential *credentials) {
    FILE *file = fopen(CREDENTIAL_FILE, "rb");
    int count = 0;
    
    if (file == NULL) {
        return 0;  // File doesn't exist yet
    }
    
    // Read count
    fread(&count, sizeof(int), 1, file);
    
    // Read credentials - CO4: pointers for memory management
    fread(credentials, sizeof(Credential), count, file);
    
    fclose(file);
    return count;
}

// Initialize data file if it doesn't exist
void initialize_data_file() {
    FILE *file = fopen(CREDENTIAL_FILE, "rb");
    
    if (file == NULL) {
        // Create new file
        file = fopen(CREDENTIAL_FILE, "wb");
        int count = 0;
        fwrite(&count, sizeof(int), 1, file);
        fclose(file);
        printf("Data file initialized.\n");
    } else {
        fclose(file);
    }
}