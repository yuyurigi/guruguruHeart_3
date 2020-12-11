#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundAuto(false);
    ofSetCircleResolution(64); //円の解像度設定
    ofSetVerticalSync(false);
    ofSetFrameRate(360);
    
    ofBackground(250, 246, 247);
    ofSetColor(54, 64, 91);
    thickness = 1.0; //線の太さの最小値
    thickMax = 8.0; //線の太さの最大値
    
    backImage.load("back.png");
    colorImage.load("color.png");
    
    svg.load("heart.svg");
    for (ofPath p: svg.getPaths()){
        // svg defaults to non zero winding which doesn't look so good as contours
        p.setPolyWindingMode(OF_POLY_WINDING_ODD);
        const vector<ofPolyline>& lines = p.getOutline();
        for(const ofPolyline & line: lines){
            outlines.push_back(line.getResampledBySpacing(1));
        }
    }
    
    //svgの頂点を配列に代入
    for (ofPolyline & line: outlines){
        for (int j = 0; j < line.size(); j++){
            point.push_back(line[j]);
        }
    }
    
    //配列に入れた頂点のradius,angleを計算
    glm::vec2 center= glm::vec2(svg.getWidth()/2, svg.getHeight()/2);
    for (int i = 0; i < point.size(); i++) {
        float a = atan2(point[i].y - center.y, point[i].x - center.x);
        ang.push_back(a);
        float r = (point[i].y - center.y) / sin(ang[i]);
        rad.push_back(r);
    }
    
    //ハートを何周描くか
    rotNum = point.size() * 34 + point.size()/2; //34周半
    vc = 0;
    vc2 = 0;
    radius = 0.01;
}


//--------------------------------------------------------------
void ofApp::update(){
    vc += 1;
    vc2 += 1;
    radius += 0.00003;
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(vc2 < rotNum){
        vc = vc%point.size();
        float hx = ofGetWidth()/2 + ((rad[vc]*radius) * cos(ang[vc]));
        float hy = ofGetHeight()/2 + ((rad[vc]*radius) * sin(ang[vc]));
        
        //画像の色を取得
        ofColor c = readBackground(backImage, hx, hy);
        //暗い色を太い線に、明るい色を細い線にする
        float brightness = c.getBrightness();
        float b = ofMap(c.getBrightness(), 0, 255, thickMax, thickness);
        //線の色
        ofColor cc = readBackground(colorImage, hx, hy);
        ofSetColor(cc);
        ofDrawEllipse(hx, hy, b, b);
    }
    
    screenshot.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------

ofColor ofApp::readBackground(ofImage img, float x, float y){
    ofPixels colorPixels = img.getPixels();
    ofColor c = colorPixels.getColor(x, y);
    return c;
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'S' || key == 's') {
        screenshot.save(ofGetTimestampString("%Y%m%d%H%M%S")+"##.jpg");
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
