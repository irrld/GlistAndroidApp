package dev.glist.android.lib;

import android.content.Context;
import android.view.Display;
import android.view.OrientationEventListener;
import android.view.Surface;
import android.view.WindowManager;

public class GlistOrientationListener extends OrientationEventListener {
    private int lastOrientation;
    private boolean firstCheck = true;

    public GlistOrientationListener(Context context) {
        super(context);
    }

    @Override
    public void enable() {
        firstCheck = true;
        checkOrientation();
        super.enable();
    }

    @Override
    public void onOrientationChanged(int orientation) {
        checkOrientation();
    }

    public void checkOrientation() {
        WindowManager windowManager = (WindowManager)GlistNative.getActivity().getSystemService(Context.WINDOW_SERVICE);
        Display display = windowManager.getDefaultDisplay();

        if(lastOrientation != display.getRotation() || firstCheck) {
            lastOrientation = display.getRotation();
            firstCheck = false;

            int orientation;
            switch (display.getRotation()) {
                case Surface.ROTATION_90:
                    orientation = 0; // landscape
                    break;
                case Surface.ROTATION_180:
                    orientation = 9; // reverse portrait
                    break;
                case Surface.ROTATION_270:
                    orientation = 8; // reverse landscape
                    break;
                case Surface.ROTATION_0:
                default:
                    orientation = 1; // portrait
                    break;
            }
            GlistNative.onOrientationChanged(orientation);
        }
    }
}
