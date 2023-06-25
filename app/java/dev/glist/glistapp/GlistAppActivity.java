package dev.glist.glistapp;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.content.res.AssetManager;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.View;

import org.fmod.FMOD;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

public class GlistAppActivity extends AppCompatActivity implements SurfaceHolder.Callback {

    static {
        System.loadLibrary("fmod");
    }

    private SurfaceView view;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        FMOD.init(this);

        getSupportActionBar().hide();
        setContentView(R.layout.main);
        view = findViewById(R.id.surfaceview);
        view.getHolder().addCallback(this);
        GlistNative.onCreate();
        GlistNative.setAssetManager(getAssets());
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        GlistNative.onDestroy();
        org.fmod.FMOD.close();
    }

    @Override
    protected void onStart() {
        super.onStart();
        GlistNative.onStart();
    }

    @Override
    protected void onStop() {
        super.onStop();
        GlistNative.onStop();
    }

    @Override
    protected void onPause() {
        super.onPause();
        GlistNative.onPause();
    }

    @Override
    protected void onResume() {
        super.onResume();
        GlistNative.onResume();
    }

    @Override
    public void surfaceCreated(@NonNull SurfaceHolder holder) {
    }

    @Override
    public void surfaceChanged(@NonNull SurfaceHolder holder, int i, int i1, int i2) {
        GlistNative.setSurface(holder.getSurface());
    }

    @Override
    public void surfaceDestroyed(@NonNull SurfaceHolder holder) {

    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        int[] coords = new int[2];
        view.getLocationInWindow(coords);
        float x = event.getRawX() - coords[0];
        float y = event.getRawY() - coords[1];
        return GlistNative.onTouchEvent(event, (int) x, (int) y);
    }
}