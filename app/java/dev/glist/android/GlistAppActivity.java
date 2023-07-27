package dev.glist.android;

import android.os.Bundle;

public class GlistAppActivity extends BaseGlistAppActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        // Your settings can go here.
        //GlistNative.setFullscreen(true); // Uncomment this line to hide status bar.
    }
}