#include <windows.h>
#include <stdio.h>

void DisableNotifications() {
    HKEY hKey;
    LONG result;

    // Open the registry key for notifications
    result = RegOpenKeyEx(HKEY_CURRENT_USER,
                          TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\PushNotifications"),
                          0,
                          KEY_SET_VALUE,
                          &hKey);

    if (result == ERROR_SUCCESS) {
        DWORD value = 0; // 0 - disable notifications
        RegSetValueEx(hKey, TEXT("ToastEnabled"), 0, REG_DWORD, (const BYTE*)&value, sizeof(value));
        RegCloseKey(hKey);
        printf("Notifications disabled.\n");
    } else {
        printf("Failed to open registry key: %ld\n", result);
    }

    // Disable system notifications
    result = RegOpenKeyEx(HKEY_CURRENT_USER,
                          TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Notifications"),
                          0,
                          KEY_SET_VALUE,
                          &hKey);

    if (result == ERROR_SUCCESS) {
        DWORD value = 0; // 0 - disable notifications
        RegSetValueEx(hKey, TEXT("ToastEnabled"), 0, REG_DWORD, (const BYTE*)&value, sizeof(value));
        RegCloseKey(hKey);
        printf("System notifications disabled.\n");
    } else {
        printf("Failed to open registry key: %ld\n", result);
    }
}

void EnableNotifications() {
    HKEY hKey;
    LONG result;

    // Open the registry key for notifications
    result = RegOpenKeyEx(HKEY_CURRENT_USER,
                          TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\PushNotifications"),
                          0,
                          KEY_SET_VALUE,
                          &hKey);

    if (result == ERROR_SUCCESS) {
        DWORD value = 1; // 1 - enable notifications
        RegSetValueEx(hKey, TEXT("ToastEnabled"), 0, REG_DWORD, (const BYTE*)&value, sizeof(value));
        RegCloseKey(hKey);
        printf("Notifications enabled.\n");
    } else {
        printf("Failed to open registry key: %ld\n", result);
    }

    // Enable system notifications
    result = RegOpenKeyEx(HKEY_CURRENT_USER,
                          TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Notifications"),
                          0,
                          KEY_SET_VALUE,
                          &hKey);

    if (result == ERROR_SUCCESS) {
        DWORD value = 1; // 1 - enable notifications
        RegSetValueEx(hKey, TEXT("ToastEnabled"), 0, REG_DWORD, (const BYTE*)&value, sizeof(value));
        RegCloseKey(hKey);
        printf("System notifications enabled.\n");
    } else {
        printf("Failed to open registry key: %ld\n", result);
    }
}

int main() {
    int choice;

    printf("Choose an action:\n");
    printf("1. Disable notifications\n");
    printf("2. Enable notifications\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            DisableNotifications();
            break;
        case 2:
            EnableNotifications();
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}
