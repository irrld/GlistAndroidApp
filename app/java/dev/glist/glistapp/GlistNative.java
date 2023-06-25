package dev.glist.glistapp;

import android.content.res.AssetManager;
import android.view.Surface;

public class GlistNative {

    static {
        System.loadLibrary("GlistAppd");
    }


    public static native void onCreate();
    public static native void onDestroy();
    public static native void onStart();
    public static native void onStop();
    public static native void onPause();
    public static native void onResume();

    public static native void setSurface(Surface surface);

    public static native void setAssetManager(AssetManager assets);
}
