#include <M5Stack.h>
#include "ScrollTextWindow.h"

#define TOP_FIXED_HEIGHT        24  //上部の固定エリア高さ
#define BOTTOM_FIXED_HEIGHT     16  //下部の固定エリア高さ

ScrollTextWindow *stw;              //スクロールクラス

void setup() {
  M5.begin();
  M5.Lcd.fillScreen(TFT_BLACK);

  //固定エリアの描画
  M5.Lcd.setTextDatum(MC_DATUM);
  M5.Lcd.setTextColor(TFT_WHITE, TFT_BLUE);

  //上部固定エリア
  M5.Lcd.fillRect(0, 0, SCREEN_WIDTH, TOP_FIXED_HEIGHT, TFT_BLUE);
  M5.Lcd.drawString("TOP FIXED AREA", SCREEN_WIDTH/2, TOP_FIXED_HEIGHT/2);

  //下部固定エリア
  M5.Lcd.fillRect(0, SCREEN_HEIGHT-BOTTOM_FIXED_HEIGHT, SCREEN_WIDTH, BOTTOM_FIXED_HEIGHT, TFT_BLUE);
  M5.Lcd.drawString("BOTTOM FIXED AREA", SCREEN_WIDTH/2, SCREEN_HEIGHT - BOTTOM_FIXED_HEIGHT/2);

  M5.Lcd.setTextDatum(TL_DATUM);
  M5.Lcd.setTextColor(TFT_WHITE, TFT_BLACK);

  //スクロールクラスの初期化
  stw = new ScrollTextWindow(TOP_FIXED_HEIGHT, BOTTOM_FIXED_HEIGHT);
}

void loop() {
  if (M5.BtnA.wasPressed()) {
    stw->print("Hello World! ");
    stw->print((int)random(0,999));
  }
  if (M5.BtnB.wasPressed()) {
    stw->print("\r\n");
  }
  if (M5.BtnC.wasPressed()) {
    stw->cls();
  }
  M5.update();
}
