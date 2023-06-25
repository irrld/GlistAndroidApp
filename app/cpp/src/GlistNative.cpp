#include <jni.h>
#include <string>
#include <iostream>
#include "gAppManager.h"
#include "gApp.h"
#include "gAndroidUtil.h"
#include <sys/ioctl.h>
#include <linux/fb.h>
#include <fcntl.h>

#include <cstdint>
#include <unistd.h>
#include <pthread.h>
#include <android/log.h>
#include <android/native_window.h> // requires ndk r5 or newer
#include <android/asset_manager_jni.h>
#include <android/asset_manager.h>
#include <EGL/egl.h> // requires ndk r5 or newer
#include <GLES3/gl3.h>
#include <thread>


extern "C" {

JNIEXPORT void JNICALL Java_dev_glist_glistapp_GlistNative_onCreate(JNIEnv *env, jclass clazz) {
    gLogi("GlistNative") << "onCreate";
}

JNIEXPORT void JNICALL Java_dev_glist_glistapp_GlistNative_onDestroy(JNIEnv *env, jclass clazz) {
    gLogi("GlistNative") << "onDestroy";
}

JNIEXPORT void JNICALL Java_dev_glist_glistapp_GlistNative_onStart(JNIEnv *env, jclass clazz) {
    gLogi("GlistNative") << "onStart";
}

JNIEXPORT void JNICALL Java_dev_glist_glistapp_GlistNative_onStop(JNIEnv *env, jclass clazz) {
    gLogi("GlistNative") << "onStop";
}

JNIEXPORT void JNICALL Java_dev_glist_glistapp_GlistNative_onPause(JNIEnv *env, jclass clazz) {
    gLogi("GlistNative") << "onPause";
}

JNIEXPORT void JNICALL Java_dev_glist_glistapp_GlistNative_onResume(JNIEnv *env, jclass clazz) {
    gLogi("GlistNative") << "onResume";
    static std::thread thread_obj([]() {
        gStartEngine(new gApp(),"GlistApp", G_WINDOWMODE_GUIAPP, 720, 1280);
    });

}

JNIEXPORT void JNICALL Java_dev_glist_glistapp_GlistNative_setAssetManager(JNIEnv *env, jclass clazz, jobject assets) {
    AAssetManager* man = AAssetManager_fromJava(env, assets);
    gAndroidUtil::assets = man;
}
}

