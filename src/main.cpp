// 使用するボードに応じた define を記述します。
// （ボードマネージャで該当ボードを選択している場合は省略しても構いません）
#define LGFX_M5PAPER
// #define LGFX_M5STACK_COREINK
//#define LGFX_AUTODETECT      // 自動検出を使用する場合はこちらの記述だけで動作します。

#include <M5EPD.h>  // M5Paperのライブラリと同時に利用する場合はLovyanGFXより前にincludeします。

// 使用ボードのdefineより後にLovyanGFX.hppをincludeします。
#include <LovyanGFX.hpp>

LGFX gfx;
LGFX_Sprite sp(&gfx);

int w;
int h;

void setup(void)
{
// M5.begin();

  gfx.init();   // 初期化を行います。LCDもEPDも共通です。
  gfx.setRotation(0);  // 回転方向の設定はLCDもEPDも共通です。0～3で右回りに90度ずつ回転します。4～7は上下反転になります。

  // M5Paper (IT8951)での各モードの特徴は以下の通りです。
  // epd_fastest = DU4  更新時間 120msec  完全な白と黒のみ描画でき、中間階調は描画されない。また、中間階調で表示されている箇所を更新できない。
  // epd_fast    = DU   更新時間 260msec  完全な白と黒のみ描画でき、中間階調は描画されない。
  // epd_quality = GC16 更新時間 450msec  グレースケール16階調で描画できる。
  gfx.setEpdMode(epd_mode_t::epd_quality);  // 高品質更新、白黒反転が一瞬起きる

  gfx.setAutoDisplay(false);  // 自動表示更新を無効にする。（以降は display()を呼ぶまで画面に反映されない。）
  gfx.fillScreen(TFT_WHITE);
  gfx.setFont(&fonts::lgfxJapanGothicP_40);
  gfx.fillScreen(TFT_WHITE);
  gfx.setTextColor(TFT_BLACK, TFT_WHITE);
  gfx.setTextSize(1, 1);
  gfx.drawString("これでフォント描画できるの？", 0, 0);
  gfx.display();
  gfx.waitDisplay();
}

void loop(void)
{
}
