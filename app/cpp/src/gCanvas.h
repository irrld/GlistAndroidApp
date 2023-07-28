/*
* gCanvas.h
*
*  Created on: May 6, 2020
*      Author: noyan
*/

#ifndef GCANVAS_H_
#define GCANVAS_H_

#include "gImage.h"
#include "gApp.h"
#include "gAndroidCanvas.h"
#include "gAndroidUtil.h"


class gCanvas : public gAndroidCanvas {
public:
	gCanvas(gApp* root);
	virtual ~gCanvas();

	void setup();
	void update();
	void draw();

	void deviceOrientationChanged(DeviceOrientation deviceorientation);

	void touchMoved(int x, int y, int fingerId);
	void touchPressed(int x, int y, int fingerId);
	void touchReleased(int x, int y, int fingerId);

	void pause();
	void resume();

	void windowResized(int w, int h);

	void showNotify();
	void hideNotify();
private:
	gApp* root;
	gImage logo;

};

#endif /* GCANVAS_H_ */
