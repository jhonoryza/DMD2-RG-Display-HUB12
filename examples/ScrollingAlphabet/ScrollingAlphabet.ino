/*
  Scrolling alphabet demo, displays characters one at a time into a scrolling box.
 */

#include <SPI.h>
#include <DMD2.h>
#include <fonts/SystemFont5x7.h>
#include <fonts/Arial14.h>

// Set Width to the number of displays wide you have
const int WIDTH = 1;

// You can change to a smaller font (two lines) by commenting this line,
// and uncommenting the line after it:
const uint8_t *FONT = Arial14;
//const uint8_t *FONT = SystemFont5x7;

const char *MESSAGE = "abcdefghijklmnopqrstuvwxyz";

SoftDMD dmd(WIDTH, 1, 2, 16, 12, 0, 14, 13, 4);  // DMD controls the entire display
DMD_TextBox box(dmd);  // "box" provides a text box to automatically write to/scroll the display

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  dmd.setColor("kuning");
  dmd.selectFont(FONT);
  dmd.begin();
  const uint8_t period = 5000;
  uint32 pwm_duty_init[1] = {135};
  uint32 io_info[1][3] = {
    {PERIPHS_IO_MUX_GPIO5_U, FUNC_GPIO5, 5}
  };
  pwm_init(period, pwm_duty_init, 1, io_info);
  pwm_start();
}

// the loop routine runs over and over again forever:
void loop() {
  const char *next = MESSAGE;
  while(*next) {
    Serial.print(*next);
    box.print(*next);
    delay(200);
    next++;
  }
}
