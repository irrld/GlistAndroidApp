/*
* GameCanvas.cpp
*
*  Created on: May 6, 2020
*      Author: noyan
 */


#include "GameCanvas.h"

#include <random>


GameCanvas::GameCanvas(gApp* root) : gBaseCanvas(root) {
  this->root = root;
}

GameCanvas::~GameCanvas() {
}

void GameCanvas::setup() {
  gLogi("GameCanvas") << "setup";
  root->getAppManager()->getGUIManager()->setCurrentFrame(&frame);
  frame.setSizer(&framesizer);
  framesizer.setSize(1, 3);
  framesizer.enableBorders(true);
  framesizer.enableResizing(true);
  float columnprs[]{0.2f, 0.6f, 0.2f};
  framesizer.setColumnProportions(columnprs);
  framesizer.setControl(0, 0, &panel1);
  framesizer.setControl(0, 1, &panel2);
  framesizer.setControl(0, 2, &panel3);

  panel1sizer.enableBorders(true);
  panel1sizer.setSize(6, 1);
  panel1sizer.setControl(2, 0, &box);
  text.setText("Yeşil ağaçlar güzeldir. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mauris porta eros lacus. Nullam a dignissim elit, tempus pretium dui. Quisque eleifend pharetra sem, et facilisis neque blandit vitae.");
  text.setTextAlignment(gGUIText::TEXTALIGNMENT_CENTER);
  panel1sizer.setControl(1, 0, &text);

  panel1.setSizer(&panel1sizer);
  std::vector<std::string> items{"Adem Yılmaz", "Başak Kadakal", "Furkan Kömürlü", "Melih Eskici", "Tarık Sağlamer", "Alper Turhan", "Egemen Sefer"};
  for (const auto& item : items) {
    list.addData(item);
  }
  list.enableScrollbars(true, false);
  panel1sizer.setControl(0, 0, &list);

  panel1.setTitle("Test");


  panel3.setSizer(&panel3sizer);
  panel3sizer.setSize(6, 1);
  panel3sizer.setControl(0, 0, &dropdown);
  std::shuffle(items.begin(), items.end(), std::mt19937(std::random_device()()));
  for (const auto& item : items) {
    auto* elem = new gGUITreelist::Element();
    elem->title = item;
    dropdown.addElement(elem);
  }
  dropdown.setParentFrame(&frame);


  frame.setMenuBar(&menubar);
  menubar.addChild("File");

  toolbarsizer.setSize(1, 30);
  toolbar.setSizer(&toolbarsizer);
  frame.addToolBar(&toolbar);
  toolbarsizer.setRootApp(root);
  toolbarbutton1.setImage(gGUIResources::ICON_FILE);
  toolbarbutton2.setImage(gGUIResources::ICON_BRUSH);
  toolbarbutton3.setImage(gGUIResources::ICON_CLOCK);
  toolbarbutton4.setImage(gGUIResources::ICON_DOWNLOAD);
  toolbarbutton5.setImage(gGUIResources::ICON_EXITBLACK);
  toolbarsizer.setControl(0,0, &toolbarbutton1);
  toolbarsizer.setControl(0,1, &toolbarbutton2);
  toolbarsizer.setControl(0,2, &toolbarbutton3);
  toolbarsizer.setControl(0,3, &toolbarbutton4);
  toolbarsizer.setControl(0,4, &toolbarbutton5);

  panel2sizer.setSize(3, 1);
  panel2sizer.enableBorders(true);
  panel2.setSizer(&panel2sizer);
  grid.setGrid(20, 20);
  panel2sizer.setControl(0, 0, &grid);
  linegraph.enableGridlinesX(true);
  linegraph.addLine();
  linegraph.addPointToLine(0, 4, 2);
  linegraph.addPointToLine(0, 8.7f, 4.5f);
  linegraph.addPointToLine(0, 2, 6.2f);
  linegraph.addPointToLine(0, 6.4f, 4.5f);
  linegraph.addPointToLine(0, 11, 7.7f);
  linegraph.addLine();
  linegraph.addPointToLine(1, 2, 2);
  linegraph.addPointToLine(1, 1.7f, 4.5f);
  linegraph.addPointToLine(1, 3, 6.2f);
  linegraph.addPointToLine(1, 4.4f, 4.5f);
  linegraph.addPointToLine(1, 5, 7.7f);
  panel2sizer.setControl(1, 0, &linegraph);
  //panel2sizer.setControl(2, 0, &dimmer);

}

void GameCanvas::onGuiEvent(int guiObjectId, int eventType, std::string value1, std::string value2) {
  if (guiObjectId == list.getId() && eventType == G_GUIEVENT_LISTBOXSELECTED) {
    text.setText(list.getSelectedData());
  }
}

void GameCanvas::update() {
  //	gLogi("GameCanvas") << "update";
}

void GameCanvas::draw() {
    gLogi("GameCanvas") << "draw";
}

void GameCanvas::keyPressed(int key) {
  //	gLogi("GameCanvas") << "keyPressed:" << key;
}

void GameCanvas::keyReleased(int key) {
  //	gLogi("GameCanvas") << "keyReleased:" << key;
}

void GameCanvas::charPressed(unsigned int codepoint) {
  //	gLogi("GameCanvas") << "charPressed:" << gCodepointToStr(codepoint);
  //gLogi("GameCanvas") << dimmer.getValue();
  //dimmer.setValue(10);
}

void GameCanvas::mouseMoved(int x, int y) {
  //	gLogi("GameCanvas") << "mouseMoved" << ", x:" << x << ", y:" << y;
}

void GameCanvas::mouseDragged(int x, int y, int button) {
  //	gLogi("GameCanvas") << "mouseDragged" << ", x:" << x << ", y:" << y << ", b:" << button;
}

void GameCanvas::mousePressed(int x, int y, int button) {
}

void GameCanvas::mouseReleased(int x, int y, int button) {
  //	gLogi("GameCanvas") << "mouseReleased" << ", button:" << button;
}

void GameCanvas::mouseScrolled(int x, int y) {
  //	gLogi("GameCanvas") << "mouseScrolled" << ", x:" << x << ", y:" << y;
}

void GameCanvas::mouseEntered() {
}

void GameCanvas::mouseExited() {
}

void GameCanvas::windowResized(int w, int h) {
}

void GameCanvas::showNotify() {

}

void GameCanvas::hideNotify() {

}

