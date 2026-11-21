#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <XPT2046_Touchscreen.h>
#include <ESP_I2S.h>

#define TFT_CS 10
#define TFT_DC 9
#define TFT_RST 14
#define TFT_MOSI 11
#define TFT_MISO 13
#define TFT_SCK 12
#define TOUCH_CS 8

#define I2S_LRC 4
#define I2S_BCLK 5
#define I2S_DIN 6
#define AMP_SD 17

#define TOUCH_X_MIN 300
#define TOUCH_X_MAX 3800
#define TOUCH_Y_MIN 300
#define TOUCH_Y_MAX 3800

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define SAMPLE_RATE 22050

Adafruit_ILI9341 tft = Adafruit_ILI9341(&SPI, TFT_DC, TFT_CS, TFT_RST);
XPT2046_Touchscreen ts(TOUCH_CS);
I2SClass i2s;

int volumeLevel = 5;
int16_t audioBuffer[256];

const int BEEP_X = 10;
const int BEEP_Y = 85;
const int BEEP_W = 145;
const int BEEP_H = 65;

const int SONG_X = 165;
const int SONG_Y = 85;
const int SONG_W = 145;
const int SONG_H = 65;

const int VOLDOWN_X = 10;
const int VOLDOWN_Y = 160;
const int VOLDOWN_W = 95;
const int VOLDOWN_H = 65;

const int VOLBOX_X = 115;
const int VOLBOX_Y = 160;
const int VOLBOX_W = 90;
const int VOLBOX_H = 65;

const int VOLUP_X = 215;
const int VOLUP_Y = 160;
const int VOLUP_W = 95;
const int VOLUP_H = 65;

int melodyNotes[] = {262, 262, 392, 392, 440, 440, 392, 349, 349, 330, 330, 294, 294, 262};
int melodyLengths[] = {300, 300, 300, 300, 300, 300, 600, 300, 300, 300, 300, 300, 300, 600};
int melodyCount = 14;

void playTone(int frequency, int durationMs) {
  int totalSamples = (SAMPLE_RATE / 100) * durationMs / 10;
  int amplitude = volumeLevel * 2000;
  float angle = 0.0;
  float angleStep = 2.0 * PI * frequency / SAMPLE_RATE;
  int index = 0;

  for (int i = 0; i < totalSamples; i++) {
    int16_t sample = (int16_t)(amplitude * sin(angle));
    audioBuffer[index] = sample;
    audioBuffer[index + 1] = sample;
    index = index + 2;

    angle = angle + angleStep;
    if (angle >= 2.0 * PI) {
      angle = angle - 2.0 * PI;
    }

    if (index >= 256) {
      i2s.write((uint8_t *)audioBuffer, sizeof(audioBuffer));
      index = 0;
    }
  }

  if (index > 0) {
    i2s.write((uint8_t *)audioBuffer, index * sizeof(int16_t));
  }
}

void playBeep() {
  playTone(1000, 200);
  playTone(0, 30);
}

void playClick() {
  playTone(1500, 40);
  playTone(0, 20);
}

void playSong() {
  for (int i = 0; i < melodyCount; i++) {
    playTone(melodyNotes[i], melodyLengths[i]);
    playTone(0, 50);
  }
  playTone(0, 30);
}

void drawButton(int x, int y, int w, int h, String label, uint16_t color) {
  tft.fillRoundRect(x, y, w, h, 10, color);
  tft.drawRoundRect(x, y, w, h, 10, ILI9341_WHITE);
  tft.setTextSize(2);
  tft.setTextColor(ILI9341_WHITE);
  int textWidth = label.length() * 12;
  int textX = x + (w - textWidth) / 2;
  int textY = y + (h - 16) / 2;
  tft.setCursor(textX, textY);
  tft.print(label);
}

void drawVolume() {
  tft.fillRoundRect(VOLBOX_X, VOLBOX_Y, VOLBOX_W, VOLBOX_H, 10, ILI9341_DARKGREY);
  tft.setTextSize(2);
  tft.setTextColor(ILI9341_WHITE);
  String text = "Vol " + String(volumeLevel);
  int textWidth = text.length() * 12;
  int textX = VOLBOX_X + (VOLBOX_W - textWidth) / 2;
  int textY = VOLBOX_Y + (VOLBOX_H - 16) / 2;
  tft.setCursor(textX, textY);
  tft.print(text);
}

void showStatus(String message) {
  tft.fillRect(0, 45, SCREEN_WIDTH, 30, ILI9341_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(ILI9341_YELLOW);
  tft.setCursor(10, 52);
  tft.print(message);
}

void drawScreen() {
  tft.fillScreen(ILI9341_BLACK);

  tft.fillRect(0, 0, SCREEN_WIDTH, 40, ILI9341_NAVY);
  tft.setTextSize(2);
  tft.setTextColor(ILI9341_WHITE);
  tft.setCursor(10, 12);
  tft.print("ESP32-S3 Sound Demo");

  drawButton(BEEP_X, BEEP_Y, BEEP_W, BEEP_H, "Beep", ILI9341_BLUE);
  drawButton(SONG_X, SONG_Y, SONG_W, SONG_H, "Play Song", ILI9341_DARKGREEN);
  drawButton(VOLDOWN_X, VOLDOWN_Y, VOLDOWN_W, VOLDOWN_H, "Vol -", ILI9341_MAROON);
  drawButton(VOLUP_X, VOLUP_Y, VOLUP_W, VOLUP_H, "Vol +", ILI9341_MAROON);
  drawVolume();

  showStatus("Touch a button");
}

bool isInside(int touchX, int touchY, int x, int y, int w, int h) {
  if (touchX >= x && touchX <= x + w && touchY >= y && touchY <= y + h) {
    return true;
  }
  return false;
}

void handleTouch(int touchX, int touchY) {
  if (isInside(touchX, touchY, BEEP_X, BEEP_Y, BEEP_W, BEEP_H)) {
    drawButton(BEEP_X, BEEP_Y, BEEP_W, BEEP_H, "Beep", ILI9341_ORANGE);
    showStatus("Beep!");
    playBeep();
    drawButton(BEEP_X, BEEP_Y, BEEP_W, BEEP_H, "Beep", ILI9341_BLUE);
  }
  else if (isInside(touchX, touchY, SONG_X, SONG_Y, SONG_W, SONG_H)) {
    drawButton(SONG_X, SONG_Y, SONG_W, SONG_H, "Play Song", ILI9341_ORANGE);
    showStatus("Playing song...");
    playSong();
    drawButton(SONG_X, SONG_Y, SONG_W, SONG_H, "Play Song", ILI9341_DARKGREEN);
    showStatus("Song finished");
  }
  else if (isInside(touchX, touchY, VOLDOWN_X, VOLDOWN_Y, VOLDOWN_W, VOLDOWN_H)) {
    drawButton(VOLDOWN_X, VOLDOWN_Y, VOLDOWN_W, VOLDOWN_H, "Vol -", ILI9341_ORANGE);
    if (volumeLevel > 0) {
      volumeLevel = volumeLevel - 1;
    }
    drawVolume();
    showStatus("Volume down");
    playClick();
    drawButton(VOLDOWN_X, VOLDOWN_Y, VOLDOWN_W, VOLDOWN_H, "Vol -", ILI9341_MAROON);
  }
  else if (isInside(touchX, touchY, VOLUP_X, VOLUP_Y, VOLUP_W, VOLUP_H)) {
    drawButton(VOLUP_X, VOLUP_Y, VOLUP_W, VOLUP_H, "Vol +", ILI9341_ORANGE);
    if (volumeLevel < 10) {
      volumeLevel = volumeLevel + 1;
    }
    drawVolume();
    showStatus("Volume up");
    playClick();
    drawButton(VOLUP_X, VOLUP_Y, VOLUP_W, VOLUP_H, "Vol +", ILI9341_MAROON);
  }
  else {
    showStatus("Tap X:" + String(touchX) + " Y:" + String(touchY));
  }
}

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("Starting...");

  pinMode(TOUCH_CS, OUTPUT);
  digitalWrite(TOUCH_CS, HIGH);
  pinMode(TFT_CS, OUTPUT);
  digitalWrite(TFT_CS, HIGH);

  pinMode(AMP_SD, OUTPUT);
  digitalWrite(AMP_SD, HIGH);

  SPI.begin(TFT_SCK, TFT_MISO, TFT_MOSI);

  tft.begin();
  tft.setRotation(1);

  ts.begin(SPI);
  ts.setRotation(1);

  i2s.setPins(I2S_BCLK, I2S_LRC, I2S_DIN);
  if (!i2s.begin(I2S_MODE_STD, SAMPLE_RATE, I2S_DATA_BIT_WIDTH_16BIT, I2S_SLOT_MODE_STEREO)) {
    Serial.println("I2S audio failed to start");
  } else {
    Serial.println("I2S audio started");
  }

  drawScreen();

  playTone(880, 100);
  playTone(0, 50);
  playTone(1320, 150);
  playTone(0, 30);

  Serial.println("Ready");
}

void loop() {
  if (ts.touched()) {
    TS_Point p = ts.getPoint();

    int touchX = map(p.x, TOUCH_X_MIN, TOUCH_X_MAX, 0, SCREEN_WIDTH - 1);
    int touchY = map(p.y, TOUCH_Y_MIN, TOUCH_Y_MAX, 0, SCREEN_HEIGHT - 1);
    touchX = constrain(touchX, 0, SCREEN_WIDTH - 1);
    touchY = constrain(touchY, 0, SCREEN_HEIGHT - 1);

    Serial.print("Raw X: ");
    Serial.print(p.x);
    Serial.print("  Raw Y: ");
    Serial.print(p.y);
    Serial.print("  Screen X: ");
    Serial.print(touchX);
    Serial.print("  Screen Y: ");
    Serial.println(touchY);

    handleTouch(touchX, touchY);

    while (ts.touched()) {
      delay(10);
    }
  }

  delay(10);
}