#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pico/stdlib.h"
#include "pico_rgb_keypad.hpp"

using namespace pimoroni;

PicoRGBKeypad pico_keypad;

constexpr uint8_t num_colors = 6;

// Simple struct to pair r/g/b together as a color
struct color {uint8_t r, g, b;};

color colors[num_colors] = {
  {0x00, 0x20, 0x00}, // Green
  {0x20, 0x20, 0x00}, // Yellow
  {0x20, 0x00, 0x00}, // Red
  {0x20, 0x00, 0x20}, // Pink
  {0x00, 0x00, 0x20}, // Blue
  {0x00, 0x20, 0x20}  // Teal
};


int main() {
  pico_keypad.init();
  stdio_init_all();
  pico_keypad.set_brightness(1.0f);

  uint8_t color_index = 0;
  color current_color = colors[color_index];

  while(true) {
    for(auto i = 0u; i < PicoRGBKeypad::NUM_PADS; i++) {
      pico_keypad.illuminate(i, current_color.r, current_color.g, current_color.b);
      pico_keypad.update();
      sleep_ms(2000);
    }
    pico_keypad.update();
    sleep_ms(2000);
    color_index += 1;
    if(color_index == num_colors) {
      color_index = 0;
    }
    current_color = colors[color_index];
  }
  return 0;
}