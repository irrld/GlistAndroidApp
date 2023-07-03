package dev.glist.android.lib; // Do not change! GlistEngine links to this package.

import android.annotation.SuppressLint;
import android.content.res.AssetManager;
import android.graphics.Insets;
import android.os.Build;
import android.view.MotionEvent;
import android.view.Surface;
import android.view.SurfaceView;
import android.view.WindowInsets;
import android.view.WindowManager;

import androidx.appcompat.app.ActionBar;

import dev.glist.android.GlistAppActivity;
import dev.glist.glistapp.R;

public class GlistNative {

    static {
        System.loadLibrary("fmod");
        // this needs to be changed if project name inside CMakeLists.txt is changed.
        System.loadLibrary("GlistAppd");
    }

    @SuppressLint("StaticFieldLeak")
    private static GlistAppActivity activity;

    public static SurfaceView init(GlistAppActivity activity) {
        GlistNative.activity = activity;
        ActionBar actionBar = activity.getSupportActionBar();
        if (actionBar != null) {
            actionBar.hide();
        }
        setAssetManager(activity.getAssets());
        activity.setContentView(R.layout.main);
        SurfaceView view = activity.findViewById(R.id.surfaceview);
        view.getHolder().addCallback(activity);
        return view;
    }

    public static native void onCreate();
    public static native void onDestroy();
    public static native void onStart();
    public static native void onStop();
    public static native void onPause();
    public static native void onResume();

    public static native void setSurface(Surface surface);
    public static native void setAssetManager(AssetManager assets);
    public static native boolean onTouchEvent(int pointerCount, int[] fingerIds, int[] x, int[] y);

    public static void setFullscreen(boolean fullscreen) {
        if (fullscreen) {
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.R) {
                activity.getWindow().getInsetsController().hide(WindowInsets.Type.statusBars());
            } else {
                activity.getWindow().addFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN);
            }
        } else {
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.R) {
                activity.getWindow().getInsetsController().show(WindowInsets.Type.statusBars());
            } else {
                activity.getWindow().clearFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN);
            }
        }
    }
}
