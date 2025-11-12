#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include "credential.h"

// File operations - CO4: file handling and pointers
int save_credentials(Credential *credentials, int count);
int load_credentials(Credential *credentials);
void initialize_data_file();

#endif