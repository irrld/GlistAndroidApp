#include "gApp.h"
#include "gAppManager.h"
#include "gAndroidUtil.h"

void androidMain() {
    gStartEngine(new gApp(),"GlistApp", G_WINDOWMODE_GUIAPP, 720, 1280);
}
