#include "ofApp.h"

void ofApp::setup() {

	cols = w / scl;
	rows = h / scl;

	// initialize terrain 2D array
	terrain = new float*[cols];
	for (int i = 0; i < cols; i++)
		terrain[i] = new float[rows];
}

void ofApp::update() {

	flying -= ofRandom(0.05, 0.1);
	float yoff = flying;

	for (int y = 0; y < rows; y++) {
		float xoff = 0;
		for (int x = 0; x < cols; x++) {
			terrain[x][y] = ofMap(ofNoise(xoff, yoff), 0, 1, -100, 100);
			xoff += 0.2;
		}
		yoff += 0.2;
	}
}

void ofApp::draw() {

	ofBackground(ofColor(0));
	ofNoFill();

	// translate to center (0,0)
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	ofRotateX(60);

	// substact terrain size / 2 to center everything again
	ofTranslate(-w / 2, -h / 2);

	for (int y = 0; y < rows - 1; y++) {
		ofBeginShape();
		for (int x = 0; x < cols; x++) {
			ofVertex(x * scl, y * scl, terrain[x][y]);
			ofVertex(x * scl, (y + 1) * scl, terrain[x][y + 1]);
		}
		ofEndShape();
	}


}

