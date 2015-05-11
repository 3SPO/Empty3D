//Alex Esposito
//5/11/15
//3D Noise Example
#pragma once

#include "ofMain.h"
#include "ofxGui.h"

#include "Math/MathUtils.h"

#include "Utils/ofTrueTypeFontExt.h"
#include "Utils/Cameras/ofxWalkingFirstPersonCamera.h"

class ofApp : public ofBaseApp
{
public:
    
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void setNormals(ofMesh &mesh);
    
    ofxFirstPersonCamera	camera;
    
    ofTrueTypeFontExt		fontSmall;
    
    ofMesh mesh;
    ofLight light;
    ofColor color ;
    int gridX = 30;
    int gridY = 30;
    
};