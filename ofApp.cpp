#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(239);
	ofSetWindowTitle("Insta");

	ofNoFill();
	ofSetLineWidth(5);
	ofSetColor(39);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);

	float radius = 30;
	for (int i = 0; i < 50; i++) {

		float noise_value = ofNoise(i * 0.05 - ofGetFrameNum() * 0.005);
		radius += 10;

		ofPushMatrix();
		ofRotate(noise_value * 720);

		ofBeginShape();
		for (int deg = 0; deg <= 180; deg += 1) {

			float x = radius * cos(deg * DEG_TO_RAD);
			float y = radius * sin(deg * DEG_TO_RAD);

			ofVertex(x, y);
		}
		ofEndShape();

		ofPopMatrix();
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}