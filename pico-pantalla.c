#include "hardware/i2c.h"
#include "pico/stdlib.h"
#include <pico/time.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "ssd1306.h"

#define SLEEPTIME 1000

void setup_gpios(void);

int main() {
  stdio_init_all();
  setup_gpios();

  const char *fullName[] = {"Julio Cesar", " ", "Lopez Rodriguez"};
  const char *sticker1[] = {"\\ o /", "  |  ", " / \\ "};
  const char *sticker2[] = {
      "o/__ ",
      "|  (\\",
  };
  const char *sticker3[] = {"\\ /", " | ", "/o\\"};
  ssd1306_t disp;

  disp.external_vcc = false;

  ssd1306_init(&disp, 128, 64, 0x3C, i2c0);
  ssd1306_clear(&disp);

  int newLine = 0;

  for (int i = 0; i < sizeof(fullName) / sizeof(char *); i++) {
    ssd1306_draw_string(&disp, 0, newLine += 10, 1, fullName[i]);
  }

  ssd1306_show(&disp);
  sleep_ms(SLEEPTIME * 2);
  ssd1306_clear(&disp);

  while (true) {
    newLine = 0;
    for (int i = 0; i < sizeof(sticker1) / sizeof(char *); i++) {
      ssd1306_draw_string(&disp, 0, newLine += 10, 1, sticker1[i]);
    }

    ssd1306_show(&disp);
    sleep_ms(SLEEPTIME);
    ssd1306_clear(&disp);

    newLine = 0;
    for (int i = 0; i < sizeof(sticker2) / sizeof(char *); i++) {
      ssd1306_draw_string(&disp, 0, newLine += 10, 1, sticker2[i]);
    }

    ssd1306_show(&disp);
    sleep_ms(SLEEPTIME);
    ssd1306_clear(&disp);

    newLine = 0;
    for (int i = 0; i < sizeof(sticker3) / sizeof(char *); i++) {
      ssd1306_draw_string(&disp, 0, newLine += 10, 1, sticker3[i]);
    }

    ssd1306_show(&disp);
    sleep_ms(SLEEPTIME);
    ssd1306_clear(&disp);
  }
}

void setup_gpios(void) {
  i2c_init(i2c0, 100000);
  gpio_set_function(4, GPIO_FUNC_I2C); // SDA
  gpio_set_function(5, GPIO_FUNC_I2C); // SCK
  gpio_pull_up(4);
  gpio_pull_up(5);
}
