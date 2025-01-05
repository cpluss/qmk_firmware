#include "os_specific.h"

os_mode_t current_os = MAC_MODE;
const os_keycode_map_t* keycode_mappings = NULL;
size_t mapping_count = 0;

void init_os_management(const os_keycode_map_t* mappings, size_t count) {
    keycode_mappings = mappings;
    mapping_count = count;
    current_os = MAC_MODE;
}

void toggle_os(void) {
    current_os = (current_os == MAC_MODE) ? WIN_MODE : MAC_MODE;
}

os_mode_t get_current_os(void) {
    return current_os;
}

const char* get_os_name(void) {
    return current_os == MAC_MODE ? "MAC" : "WIN";
}

static uint16_t get_os_specific_keycode(uint16_t keycode) {
    for (size_t i = 0; i < mapping_count; i++) {
        if (keycode_mappings[i].keycode == keycode) {
            return current_os == MAC_MODE ? 
                keycode_mappings[i].mac_keycode : 
                keycode_mappings[i].win_keycode;
        }
    }
    return keycode;
}

bool process_os_specific_keycode(uint16_t keycode, keyrecord_t *record) {
    for (size_t i = 0; i < mapping_count; i++) {
        if (keycode == keycode_mappings[i].keycode) {
            if (record->event.pressed) {
                uint16_t os_keycode = get_os_specific_keycode(keycode);
                tap_code16(os_keycode);
            }
            return false;
        }
    }
    return true;
} 