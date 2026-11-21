#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <XPT2046_Touchscreen.h>
#include <ESP_I2S.h>

int tftCS = 10;
int tftDC = 9;
int tftReset = 14;
int touchCS = 8;

int ampLRC = 4;
int ampBCLK = 5;
int ampDIN = 6;
int ampSD = 17;

int xMin = 300;
int xMax = 3800;
int yMin = 300;
int yMax = 3800;

Adafruit_ILI9341 tft = Adafruit_ILI9341(&SPI, tftDC, tftCS, tftReset);
XPT2046_Touchscreen touch(touchCS);
I2SClass i2s;

int sampleRate = 22050;
int vol = 5;
int16_t sound[256];

int notes[] = {262, 262, 392, 392, 440, 440, 392, 349, 349, 330, 330, 294, 294, 262};
int times[] = {300, 300, 300, 300, 300, 300, 600, 300, 300, 300, 300, 300, 300, 600};

void playNote(int freq, int ms) {
  int samples = sampleRate / 100 * ms / 10;
  int loudness = vol * 2000;
  float angle = 0;
  float step = 2 * PI * freq / sampleRate;
  int pos = 0;

  for (int i = 0; i < samples; i++) {
    int16_t value = loudness * sin(angle);
    sound[pos] = value;
    sound[pos + 1] = value;
    pos += 2;

    angle += step;
    if (angle > 2 * PI) {
      angle -= 2 * PI;
    }

    if (pos == 256) {
      i2s.write((uint8_t*)sound, sizeof(sound));
      pos = 0;
    }
  }

  if (pos > 0) {
    i2s.write((uint8_t*)sound, pos * 2);
  }
}

void beep() {
  playNote(1000, 200);
  playNote(0, 30);
}

void click() {
  playNote(1500, 40);
  playNote(0, 20);
}

void song() {
  for (int i = 0; i < 14; i++) {
    playNote(notes[i], times[i]);
    playNote(0, 50);
  }
}

void button(int x, int y, int w, int h, String text, uint16_t colour) {
  tft.fillRoundRect(x, y, w, h, 10, colour);
  tft.drawRoundRect(x, y, w, h, 10, ILI9341_WHITE);
  tft.setTextSize(2);
  tft.setTextColor(ILI9341_WHITE);
  tft.setCursor(x + (w - text.length() * 12) / 2, y + (h - 16) / 2);
  tft.print(text);
}

void showVolume() {
  button(115, 160, 90, 65, "Vol " + String(vol), ILI9341_DARKGREY);
}

void message(String text) {
  tft.fillRect(0, 45, 320, 30, ILI9341_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(ILI9341_YELLOW);
  tft.setCursor(10, 52);
  tft.print(text);
}

void drawScreen() {
  tft.fillScreen(ILI9341_BLACK);
  tft.fillRect(0, 0, 320, 40, ILI9341_NAVY);
  tft.setTextSize(2);
  tft.setTextColor(ILI9341_WHITE);
  tft.setCursor(10, 12);
  tft.print("ESP32-S3 Sound Demo");

  button(10, 85, 145, 65, "Beep", ILI9341_BLUE);
  button(165, 85, 145, 65, "Play Song", ILI9341_DARKGREEN);
  button(10, 160, 95, 65, "Vol -", ILI9341_MAROON);
  button(215, 160, 95, 65, "Vol +", ILI9341_MAROON);
  showVolume();

  message("Touch a button");
}

void setup() {
  Serial.begin(115200);
  delay(500);

  pinMode(touchCS, OUTPUT);
  digitalWrite(touchCS, HIGH);
  pinMode(tftCS, OUTPUT);
  digitalWrite(tftCS, HIGH);
  pinMode(ampSD, OUTPUT);
  digitalWrite(ampSD, HIGH);

  SPI.begin(12, 13, 11);

  tft.begin();
  tft.setRotation(1);

  touch.begin(SPI);
  touch.setRotation(1);

  i2s.setPins(ampBCLK, ampLRC, ampDIN);
  if (i2s.begin(I2S_MODE_STD, sampleRate, I2S_DATA_BIT_WIDTH_16BIT, I2S_SLOT_MODE_STEREO)) {
    Serial.println("Audio OK");
  } else {
    Serial.println("Audio not working");
  }

  drawScreen();

  playNote(880, 100);
  playNote(0, 50);
  playNote(1320, 150);
  playNote(0, 30);
}

void loop() {
  if (touch.touched()) {
    TS_Point p = touch.getPoint();

    int x = map(p.x, xMin, xMax, 0, 319);
    int y = map(p.y, yMin, yMax, 0, 239);
    x = constrain(x, 0, 319);
    y = constrain(y, 0, 239);

    Serial.print("raw: ");
    Serial.print(p.x);
    Serial.print(", ");
    Serial.print(p.y);
    Serial.print("   screen: ");
    Serial.print(x);
    Serial.print(", ");
    Serial.println(y);

    if (x > 10 && x < 155 && y > 85 && y < 150) {
      button(10, 85, 145, 65, "Beep", ILI9341_ORANGE);
      message("Beep!");
      beep();
      button(10, 85, 145, 65, "Beep", ILI9341_BLUE);
    }
    else if (x > 165 && x < 310 && y > 85 && y < 150) {
      button(165, 85, 145, 65, "Play Song", ILI9341_ORANGE);
      message("Playing song...");
      song();
      button(165, 85, 145, 65, "Play Song", ILI9341_DARKGREEN);
      message("Song finished");
    }
    else if (x > 10 && x < 105 && y > 160 && y < 225) {
      button(10, 160, 95, 65, "Vol -", ILI9341_ORANGE);
      if (vol > 0) {
        vol--;
      }
      showVolume();
      message("Volume down");
      click();
      button(10, 160, 95, 65, "Vol -", ILI9341_MAROON);
    }
    else if (x > 215 && x < 310 && y > 160 && y < 225) {
      button(215, 160, 95, 65, "Vol +", ILI9341_ORANGE);
      if (vol < 10) {
        vol++;
      }
      showVolume();
      message("Volume up");
      click();
      button(215, 160, 95, 65, "Vol +", ILI9341_MAROON);
    }
    else {
      message("Tap X:" + String(x) + " Y:" + String(y));
    }

    while (touch.touched()) {
      delay(10);
    }
  }

  delay(10);
}