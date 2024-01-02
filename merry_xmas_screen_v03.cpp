#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);


void setup(void) {
  u8g2.begin();
  pinMode(8, OUTPUT);
  pinMode(5, OUTPUT);
  
}


boolean delay_without_delaying(unsigned long time) {
  // return false if we're still "delaying", true if time ms has passed.
  // this should look a lot like "blink without delay"
  static unsigned long previousmillis = 0;
  unsigned long currentmillis = millis();
  if (currentmillis - previousmillis >= time) {
    previousmillis = currentmillis;
    return true;
  }
  return false;
}

boolean delay_without_delaying(unsigned long &since, unsigned long time) {
  // return false if we're still "delaying", true if time ms has passed.
  // this should look a lot like "blink without delay"
  unsigned long currentmillis = millis();
  if (currentmillis - since >= time) {
    since = currentmillis;
    return true;
  }
  return false;
}



void loop() {
  static unsigned long ledtime = 0;
  static unsigned long atime, btime, ctime, nltime;
  static int ledstateR = false;
  static int ledstateY = true;
  

  if (delay_without_delaying(ledtime, 400)) {
    ledstateR = !ledstateR;
    digitalWrite(8, ledstateR);
    ledstateY = !ledstateY;
    digitalWrite(5, ledstateY);

  }
  if (delay_without_delaying(atime, 2000)) {

    u8g2.clearBuffer();					// clear the internal memory
    u8g2.setFont(u8g2_font_ncenB08_tr);	// choose a suitable font
    u8g2.drawStr(0,20,"Merry Christmas!");	// write something to the internal memory
    u8g2.sendBuffer();

  }
  if (delay_without_delaying(ctime, 4000)) {
    u8g2.clearBuffer();					// clear the internal memory
    u8g2.setFont(u8g2_font_ncenB08_tr);	// choose a suitable font
    u8g2.drawStr(0,50,"Happy New Year!");	// write something to the internal memory
    u8g2.sendBuffer();	
  }

  
}

