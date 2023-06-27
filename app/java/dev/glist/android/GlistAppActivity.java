package dev.glist.android;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.WindowManager;

import org.fmod.FMOD;

import dev.glist.android.lib.GlistNative;
import dev.glist.glistapp.R;

public class GlistAppActivity extends AppCompatActivity implements SurfaceHolder.Callback {

    private SurfaceView view;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        view = GlistNative.init(this);
        FMOD.init(this);

        // Your settings can go here.
        //GlistNative.setFullscreen(true); // Uncomment this line to hide status bar.

        GlistNative.onCreate();
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