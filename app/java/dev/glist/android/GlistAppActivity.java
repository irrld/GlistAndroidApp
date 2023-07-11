package dev.glist.android;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

import org.fmod.FMOD;

import java.util.concurrent.BlockingDeque;
import java.util.concurrent.Executors;
import java.util.concurrent.LinkedBlockingDeque;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.ScheduledFuture;
import java.util.concurrent.TimeUnit;

import dev.glist.android.lib.GlistNative;

public class GlistAppActivity extends AppCompatActivity implements SurfaceHolder.Callback {

    private SurfaceView view;
    private final ScheduledExecutorService mainExecutor = Executors.newSingleThreadScheduledExecutor();
    private final BlockingDeque<Runnable> executeQueue = new LinkedBlockingDeque<>(30);
    private boolean surfaceSet = false;
    private ScheduledFuture<?> task;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        view = GlistNative.init(this);
        FMOD.init(this);

        // Your settings can go here.
        //GlistNative.setFullscreen(true); // Uncomment this line to hide status bar.
        executeQueue.offerLast(GlistNative::onCreate);
        initExecutors();
    }

    private void initExecutors() {
        task = mainExecutor.scheduleAtFixedRate(() -> {
            if (!surfaceSet) {
                return;
            }
            for (Runnable runnable : executeQueue) {
                runnable.run();
            }
            executeQueue.clear();
        }, 0, 1000 / 30, TimeUnit.MILLISECONDS);
    }

    private void shutdownExecutors() {
        if (task != null) {
            task.cancel(false);
        }
        mainExecutor.shutdown();
        for (Runnable runnable : executeQueue) {
            runnable.run();
        }
        executeQueue.clear();
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        executeQueue.offerLast(GlistNative::onDestroy);
        org.fmod.FMOD.close();
        shutdownExecutors();
    }

    @Override
    protected void onStart() {
        super.onStart();
        executeQueue.offerLast(GlistNative::onStart);
    }

    @Override
    protected void onStop() {
        super.onStop();
        executeQueue.offerLast(GlistNative::onStop);
        surfaceSet = false;
    }

    @Override
    protected void onPause() {
        super.onPause();
        executeQueue.offerLast(GlistNative::onPause);
    }

    @Override
    protected void onResume() {
        super.onResume();
        executeQueue.offerLast(GlistNative::onResume);
    }

    @Override
    public void surfaceCreated(@NonNull SurfaceHolder holder) {
    }

    @Override
    public void surfaceChanged(@NonNull SurfaceHolder holder, int i, int i1, int i2) {
        surfaceSet = true;
        executeQueue.offerFirst(() -> GlistNative.setSurface(holder.getSurface()));
    }

    @Override
    public void surfaceDestroyed(@NonNull SurfaceHolder holder) {
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        if(!surfaceSet) {
            return true;
        }
        int[] coords = new int[2];
        view.getLocationInWindow(coords);
        int pointers = event.getPointerCount();
        int[] fingerIds = new int[pointers];
        for (int i = 0; i < pointers; i++) {
            fingerIds[i] = event.getPointerId(i);
        }
        int[] x = new int[pointers];
        int[] y = new int[pointers];
        for (int i = 0; i < pointers; i++) {
            x[i] = (int) (event.getAxisValue(MotionEvent.AXIS_X, i) - coords[0]);
            y[i] = (int) (event.getAxisValue(MotionEvent.AXIS_Y, i) - coords[1]);
        }
        return GlistNative.onTouchEvent(pointers, fingerIds, x, y);
    }
}