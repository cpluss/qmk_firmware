#pragma once

#include QMK_KEYBOARD_H

typedef enum {
    MAC_MODE,
    WIN_MODE
} os_mode_t;

// Structure to hold OS-specific keycode mappings
typedef struct {
    uint16_t keycode;      // The keycode to match
    uint16_t mac_keycode;  // What to output on Mac
    uint16_t win_keycode;  // What to output on Windows
} os_keycode_map_t;

// Initialize OS management with keycode mappings
void init_os_management(const os_keycode_map_t* mappings, size_t count);

// Toggle between operating systems
void toggle_os(void);

// Get current OS
os_mode_t get_current_os(void);

// Process OS-specific keycodes
bool process_os_specific_keycode(uint16_t keycode, keyrecord_t *record);

// Get OS name for display
const char* get_os_name(void); 