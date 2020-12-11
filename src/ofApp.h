#pragma once

#include "ofMain.h"
#include "ofxSvg.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    ofColor readBackground(ofImage img, float x, float y);
    
    ofxSVG svg;
    //float step;
    vector<ofPolyline> outlines;
    //float sc;
    vector<glm::vec2> point;
    ofImage screenshot, backImage, colorImage;
    vector<float> rad;
    vector<float> ang;
    int rotNum, vc, vc2;
    float radius, thickMax, thickness;
};
