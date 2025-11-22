#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "raylib.h"

#define MAX_PASSWORD_LENGTH 50
#define ENCRYPTION_KEY 5
#define MAX_USERS 10
#define MIN_PASSWORD_LENGTH 6
#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 700

typedef struct {
    char username[50];
    char encrypted_password[MAX_PASSWORD_LENGTH];
    int is_active;
} User;

User users[MAX_USERS];
int user_count = 0;

int currentScreen = 0; // 0=Menu, 1=Register, 2=Login, 3=View, 4=Search
char inputUsername[50] = {0};
char inputPassword[MAX_PASSWORD_LENGTH] = {0};
char searchUsername[50] = {0};
char messageText[200] = {0};
int messageType = 0; // 0=none, 1=success, 2=error
float messageTimer = 0;
int activeInput = 0; // 0=none, 1=username, 2=password

void caesarEncrypt(char *password, char *encrypted, int key);
void caesarDecrypt(char *encrypted, char *decrypted, int key);
int hashPassword(char *password);
void registerUser();
void loginUser();
void searchUser();
void bubbleSortUsers();
int searchUserIndex(const char *username);
void saveToFile();
void loadFromFile();
void drawMainMenu();
void drawRegisterScreen();
void drawLoginScreen();
void drawViewScreen();
void drawSearchScreen();
void showMessage(const char* text, int type);
void drawButton(Rectangle bounds, const char* text, Color color);
int isButtonPressed(Rectangle bounds);

// Caesar Cipher Encryption (CO1 - Expressions and Operators)
void caesarEncrypt(char *password, char *encrypted, int key) {
    int i;
    for (i = 0; password[i] != '\0'; i++) {
        if (isalpha((unsigned char)password[i])) {
            if (isupper((unsigned char)password[i])) {
                encrypted[i] = ((password[i] - 'A' + key) % 26) + 'A';
            } else {
                encrypted[i] = ((password[i] - 'a' + key) % 26) + 'a';
            }
        } else if (isdigit((unsigned char)password[i])) {
            encrypted[i] = ((password[i] - '0' + key) % 10) + '0';
        } else {
            encrypted[i] = password[i];
        }
    }
    encrypted[i] = '\0';
}

// Caesar Cipher Decryption
void caesarDecrypt(char *encrypted, char *decrypted, int key) {
    int i;
    for (i = 0; encrypted[i] != '\0'; i++) {
        if (isalpha((unsigned char)encrypted[i])) {
            if (isupper((unsigned char)encrypted[i])) {
                decrypted[i] = ((encrypted[i] - 'A' - key + 26) % 26) + 'A';
            } else {
                decrypted[i] = ((encrypted[i] - 'a' - key + 26) % 26) + 'a';
            }
        } else if (isdigit((unsigned char)encrypted[i])) {
            decrypted[i] = ((encrypted[i] - '0' - key + 10) % 10) + '0';
        } else {
            decrypted[i] = encrypted[i];
        }
    }
    decrypted[i] = '\0';
}

// Simple Hash Function (CO1 - Expressions)
int hashPassword(char *password) {
    int hash = 0;
    int i;
    for (i = 0; password[i] != '\0'; i++) {
        hash += password[i] * (i + 1);
    }
    return hash % 1000;
}

// Linear Search for user (CO2 - Searching Techniques)
int searchUserIndex(const char *username) {
    int i;
    for (i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0 && users[i].is_active) {
            return i;
        }
    }
    return -1;
}

// Register new user (CO3 - Structured Programming)
void registerUser() {
    if (user_count >= MAX_USERS) {
        showMessage("User limit reached!", 2);
        return;
    }

    if (strlen(inputUsername) == 0 || strlen(inputPassword) == 0) {
        showMessage("Please fill all fields!", 2);
        return;
    }

    if (strchr(inputUsername, ' ') || strchr(inputPassword, ' ')) {
        showMessage("No spaces allowed in username/password!", 2);
        return;
    }

    if (searchUserIndex(inputUsername) != -1) {
        showMessage("Username already exists!", 2);
        return;
    }

    if (strlen(inputPassword) < MIN_PASSWORD_LENGTH) {
        showMessage("Password too short! Minimum 6 characters.", 2);
        return;
    }

    strncpy(users[user_count].username, inputUsername, sizeof(users[user_count].username) - 1);
    caesarEncrypt(inputPassword, users[user_count].encrypted_password, ENCRYPTION_KEY);
    users[user_count].is_active = 1;

    showMessage("User registered successfully!", 1);
    memset(inputUsername, 0, sizeof(inputUsername));
    memset(inputPassword, 0, sizeof(inputPassword));
    user_count++;
}

// Login user (Verify credentials)
void loginUser() {
    char decrypted[MAX_PASSWORD_LENGTH] = {0};
    int index;

    if (strlen(inputUsername) == 0 || strlen(inputPassword) == 0) {
        showMessage("Please fill all fields!", 2);
        return;
    }

    index = searchUserIndex(inputUsername);

    if (index == -1) {
        showMessage("User not found!", 2);
        return;
    }

    caesarDecrypt(users[index].encrypted_password, decrypted, ENCRYPTION_KEY);

    if (strcmp(inputPassword, decrypted) == 0) {
        char msg[100];
        snprintf(msg, sizeof(msg), "Login Successful! Welcome, %s!", inputUsername);
        showMessage(msg, 1);
        memset(inputUsername, 0, sizeof(inputUsername));
        memset(inputPassword, 0, sizeof(inputPassword));
    } else {
        showMessage("Incorrect password!", 2);
    }
}

// Search user
void searchUser() {
    int index = searchUserIndex(searchUsername);
    if (index != -1) {
        char msg[100];
        snprintf(msg, sizeof(msg), "User found: %s", users[index].username);
        showMessage(msg, 1);
    } else {
        showMessage("User not found!", 2);
    }
}

// Bubble Sort users by username (CO2 - Sorting Techniques)
void bubbleSortUsers() {
    int i, j;
    User temp;
    for (i = 0; i < user_count - 1; i++) {
        for (j = 0; j < user_count - i - 1; j++) {
            if (strcmp(users[j].username, users[j + 1].username) > 0) {
                temp = users[j];
                users[j] = users[j + 1];
                users[j + 1] = temp;
            }
        }
    }
    showMessage("Users sorted alphabetically!", 1);
}

// Save data to file (CO4 - File Handling)
void saveToFile() {
    FILE *fp = fopen("users.dat", "w");
    int i;
    if (fp == NULL) {
        showMessage("Error opening file!", 2);
        return;
    }
    fprintf(fp, "%d\n", user_count);
    for (i = 0; i < user_count; i++) {
        fprintf(fp, "%s\t%s\t%d\n",
                users[i].username,
                users[i].encrypted_password,
                users[i].is_active);
    }
    fclose(fp);
    showMessage("Data saved to file successfully!", 1);
}

// Load data from file (CO4 - File Handling)
void loadFromFile() {
    FILE *fp = fopen("users.dat", "r");
    int i;
    if (fp == NULL) {
        showMessage("No saved data found!", 2);
        return;
    }
    if (fscanf(fp, "%d\n", &user_count) != 1 || user_count > MAX_USERS) {
        user_count = 0;
        fclose(fp);
        showMessage("Error loading data!", 2);
        return;
    }
    for (i = 0; i < user_count; i++) {
        char line[128] = {0};
        if (!fgets(line, sizeof(line), fp) ||
            sscanf(line, "%49[^\t]\t%49[^\t]\t%d",
                   users[i].username,
                   users[i].encrypted_password,
                   &users[i].is_active) < 3)
        {
            users[i].username[0] = '\0';
            users[i].encrypted_password[0] = '\0';
            users[i].is_active = 0;
        }
    }
    fclose(fp);
    showMessage("Data loaded successfully!", 1);
}

// Show message
void showMessage(const char* text, int type) {
    strncpy(messageText, text, sizeof(messageText) - 1);
    messageType = type;
    messageTimer = 3.0f;
}

// Draw button
void drawButton(Rectangle bounds, const char* text, Color color) {
    DrawRectangleRounded(bounds, 0.3f, 10, color);
    int textWidth = MeasureText(text, 20);
    DrawText(text, bounds.x + (bounds.width - textWidth) / 2,
             bounds.y + (bounds.height - 20) / 2, 20, WHITE);
}

// Check if button is pressed
int isButtonPressed(Rectangle bounds) {
    Vector2 mousePos = GetMousePosition();
    if (CheckCollisionPointRec(mousePos, bounds)) {
        DrawRectangleRounded(bounds, 0.3f, 10, ColorAlpha(WHITE, 0.2f));
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            return 1;
        }
    }
    return 0;
}

// Draw Main Menu
void drawMainMenu() {
    DrawText("PASSWORD ENCRYPTION & CREDENTIAL MANAGER", 150, 50, 30, DARKBLUE);
    DrawText("Cybersecurity Micro Project", 350, 90, 20, GRAY);

    Rectangle btn1 = {150, 150, 250, 60};
    Rectangle btn2 = {450, 150, 250, 60};
    Rectangle btn3 = {750, 150, 200, 60};
    Rectangle btn4 = {150, 240, 250, 60};
    Rectangle btn5 = {450, 240, 250, 60};
    Rectangle btn6 = {750, 240, 200, 60};
    Rectangle btn7 = {150, 330, 250, 60};
    Rectangle btn8 = {450, 330, 250, 60};

    drawButton(btn1, "Register User", DARKGREEN);
    drawButton(btn2, "Login", DARKBLUE);
    drawButton(btn3, "View Users", DARKPURPLE);
    drawButton(btn4, "Search User", ORANGE);
    drawButton(btn5, "Sort Users", MAROON);
    drawButton(btn6, "Save Data", DARKGRAY);
    drawButton(btn7, "Load Data", BROWN);
    drawButton(btn8, "Exit", RED);

    if (isButtonPressed(btn1)) currentScreen = 1;
    if (isButtonPressed(btn2)) currentScreen = 2;
    if (isButtonPressed(btn3)) currentScreen = 3;
    if (isButtonPressed(btn4)) currentScreen = 4;
    if (isButtonPressed(btn5)) { bubbleSortUsers(); currentScreen = 3; }
    if (isButtonPressed(btn6)) saveToFile();
    if (isButtonPressed(btn7)) loadFromFile();
    if (isButtonPressed(btn8)) CloseWindow();

    DrawText(TextFormat("Total Users: %d", user_count), 150, 450, 25, DARKBLUE);
    DrawText(TextFormat("Encryption Key: %d", ENCRYPTION_KEY), 150, 490, 25, DARKBLUE);
}

// Draw Register Screen
void drawRegisterScreen() {
    DrawText("REGISTER NEW USER", 350, 50, 30, DARKGREEN);

    DrawText("Username:", 200, 150, 25, BLACK);
    Rectangle usernameBox = {200, 190, 600, 40};
    DrawRectangleRec(usernameBox, activeInput == 1 ? LIGHTGRAY : WHITE);
    DrawRectangleLinesEx(usernameBox, 2, activeInput == 1 ? DARKGREEN : GRAY);
    DrawText(inputUsername, 210, 200, 20, BLACK);

    DrawText("Password:", 200, 260, 25, BLACK);
    Rectangle passwordBox = {200, 300, 600, 40};
    DrawRectangleRec(passwordBox, activeInput == 2 ? LIGHTGRAY : WHITE);
    DrawRectangleLinesEx(passwordBox, 2, activeInput == 2 ? DARKGREEN : GRAY);

    char masked[MAX_PASSWORD_LENGTH] = {0};
    int i;
    for (i = 0; i < strlen(inputPassword); i++) {
        masked[i] = '*';
    }
    masked[i] = '\0';
    DrawText(masked, 210, 310, 20, BLACK);

    if (isButtonPressed(usernameBox)) activeInput = 1;
    if (isButtonPressed(passwordBox)) activeInput = 2;

    int key;
    while ((key = GetCharPressed()) > 0) {
        if (activeInput == 1 && strlen(inputUsername) < sizeof(inputUsername) - 1) {
            int len = strlen(inputUsername);
            inputUsername[len] = (char)key;
            inputUsername[len + 1] = '\0';
        } else if (activeInput == 2 && strlen(inputPassword) < sizeof(inputPassword) - 1) {
            int len = strlen(inputPassword);
            inputPassword[len] = (char)key;
            inputPassword[len + 1] = '\0';
        }
    }

    if (IsKeyPressed(KEY_BACKSPACE)) {
        if (activeInput == 1) {
            int len = strlen(inputUsername);
            if (len > 0) inputUsername[len - 1] = '\0';
        } else if (activeInput == 2) {
            int len = strlen(inputPassword);
            if (len > 0) inputPassword[len - 1] = '\0';
        }
    }

    Rectangle registerBtn = {300, 400, 150, 50};
    Rectangle backBtn = {500, 400, 150, 50};

    drawButton(registerBtn, "Register", DARKGREEN);
    drawButton(backBtn, "Back", GRAY);

    if (isButtonPressed(registerBtn)) registerUser();
    if (isButtonPressed(backBtn)) {
        currentScreen = 0;
        memset(inputUsername, 0, sizeof(inputUsername));
        memset(inputPassword, 0, sizeof(inputPassword));
        activeInput = 0;
    }
}

// Draw Login Screen
void drawLoginScreen() {
    DrawText("USER LOGIN", 400, 50, 30, DARKBLUE);

    DrawText("Username:", 200, 150, 25, BLACK);
    Rectangle usernameBox = {200, 190, 600, 40};
    DrawRectangleRec(usernameBox, activeInput == 1 ? LIGHTGRAY : WHITE);
    DrawRectangleLinesEx(usernameBox, 2, activeInput == 1 ? DARKBLUE : GRAY);
    DrawText(inputUsername, 210, 200, 20, BLACK);

    DrawText("Password:", 200, 260, 25, BLACK);
    Rectangle passwordBox = {200, 300, 600, 40};
    DrawRectangleRec(passwordBox, activeInput == 2 ? LIGHTGRAY : WHITE);
    DrawRectangleLinesEx(passwordBox, 2, activeInput == 2 ? DARKBLUE : GRAY);

    char masked[MAX_PASSWORD_LENGTH] = {0};
    int i;
    for (i = 0; i < strlen(inputPassword); i++) {
        masked[i] = '*';
    }
    masked[i] = '\0';
    DrawText(masked, 210, 310, 20, BLACK);

    if (isButtonPressed(usernameBox)) activeInput = 1;
    if (isButtonPressed(passwordBox)) activeInput = 2;

    int key;
    while ((key = GetCharPressed()) > 0) {
        if (activeInput == 1 && strlen(inputUsername) < sizeof(inputUsername) - 1) {
            int len = strlen(inputUsername);
            inputUsername[len] = (char)key;
            inputUsername[len + 1] = '\0';
        } else if (activeInput == 2 && strlen(inputPassword) < sizeof(inputPassword) - 1) {
            int len = strlen(inputPassword);
            inputPassword[len] = (char)key;
            inputPassword[len + 1] = '\0';
        }
    }

    if (IsKeyPressed(KEY_BACKSPACE)) {
        if (activeInput == 1) {
            int len = strlen(inputUsername);
            if (len > 0) inputUsername[len - 1] = '\0';
        } else if (activeInput == 2) {
            int len = strlen(inputPassword);
            if (len > 0) inputPassword[len - 1] = '\0';
        }
    }

    Rectangle loginBtn = {300, 400, 150, 50};
    Rectangle backBtn = {500, 400, 150, 50};

    drawButton(loginBtn, "Login", DARKBLUE);
    drawButton(backBtn, "Back", GRAY);

    if (isButtonPressed(loginBtn)) loginUser();
    if (isButtonPressed(backBtn)) {
        currentScreen = 0;
        memset(inputUsername, 0, sizeof(inputUsername));
        memset(inputPassword, 0, sizeof(inputPassword));
        activeInput = 0;
    }
}

// Draw View Screen
void drawViewScreen() {
    DrawText("ALL REGISTERED USERS", 350, 30, 30, DARKPURPLE);

    if (user_count == 0) {
        DrawText("No users registered yet!", 350, 300, 25, GRAY);
    } else {
        DrawText("No.", 50, 100, 20, BLACK);
        DrawText("Username", 150, 100, 20, BLACK);
        DrawText("Encrypted Password", 350, 100, 20, BLACK);
        DrawText("Hash", 650, 100, 20, BLACK);

        DrawLine(50, 130, 950, 130, BLACK);

        int i;
        char decrypted[MAX_PASSWORD_LENGTH] = {0};
        for (i = 0; i < user_count && i < 10; i++) {
            if (users[i].is_active) {
                caesarDecrypt(users[i].encrypted_password, decrypted, ENCRYPTION_KEY);
                DrawText(TextFormat("%d", i + 1), 50, 150 + i * 40, 20, BLACK);
                DrawText(users[i].username, 150, 150 + i * 40, 20, BLACK);
                DrawText(users[i].encrypted_password, 350, 150 + i * 40, 20, BLACK);
                DrawText(TextFormat("%d", hashPassword(decrypted)), 650, 150 + i * 40, 20, BLACK);
            }
        }
    }

    Rectangle backBtn = {425, 600, 150, 50};
    drawButton(backBtn, "Back", GRAY);

    if (isButtonPressed(backBtn)) currentScreen = 0;
}

// Draw Search Screen
void drawSearchScreen() {
    DrawText("SEARCH USER", 400, 50, 30, ORANGE);

    DrawText("Enter Username:", 200, 150, 25, BLACK);
    Rectangle searchBox = {200, 190, 600, 40};
    DrawRectangleRec(searchBox, activeInput == 1 ? LIGHTGRAY : WHITE);
    DrawRectangleLinesEx(searchBox, 2, activeInput == 1 ? ORANGE : GRAY);
    DrawText(searchUsername, 210, 200, 20, BLACK);

    if (isButtonPressed(searchBox)) activeInput = 1;

    int key;
    while ((key = GetCharPressed()) > 0) {
        if (activeInput == 1 && strlen(searchUsername) < sizeof(searchUsername) - 1) {
            int len = strlen(searchUsername);
            searchUsername[len] = (char)key;
            searchUsername[len + 1] = '\0';
        }
    }

    if (IsKeyPressed(KEY_BACKSPACE) && activeInput == 1) {
        int len = strlen(searchUsername);
        if (len > 0) searchUsername[len - 1] = '\0';
    }

    Rectangle searchBtn = {300, 300, 150, 50};
    Rectangle backBtn = {500, 300, 150, 50};

    drawButton(searchBtn, "Search", ORANGE);
    drawButton(backBtn, "Back", GRAY);

    if (isButtonPressed(searchBtn)) searchUser();
    if (isButtonPressed(backBtn)) {
        currentScreen = 0;
        memset(searchUsername, 0, sizeof(searchUsername));
        activeInput = 0;
    }
}

// Main function
int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Password Encryption Tool - Cybersecurity Project");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        if (messageTimer > 0) {
            messageTimer -= GetFrameTime();
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        switch (currentScreen) {
            case 0: drawMainMenu(); break;
            case 1: drawRegisterScreen(); break;
            case 2: drawLoginScreen(); break;
            case 3: drawViewScreen(); break;
            case 4: drawSearchScreen(); break;
        }

        if (messageTimer > 0) {
            Color msgColor = (messageType == 1) ? DARKGREEN : RED;
            Color bgColor = (messageType == 1) ? ColorAlpha(GREEN, 0.3f) : ColorAlpha(RED, 0.3f);

            Rectangle msgBox = {200, SCREEN_HEIGHT - 80, 600, 50};
            DrawRectangleRec(msgBox, bgColor);
            DrawRectangleLinesEx(msgBox, 2, msgColor);

            int textWidth = MeasureText(messageText, 20);
            DrawText(messageText, 200 + (600 - textWidth) / 2, SCREEN_HEIGHT - 65, 20, msgColor);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}