//Alex Esposito
//FFTerrain final
//6/1/15

#pragma once

#include "ofMain.h"
#include "ofxGui.h"

#include "Math/MathUtils.h"

#include "Utils/ofTrueTypeFontExt.h"
#include "Utils/Cameras/ofxWalkingFirstPersonCamera.h"
#include "ofxFFTFile.h"
#include "ofxAssimpModelLoader.h"


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
    ofSoundPlayer soundPlayer;
    ofxFFTFile fftFile;
    int gridX = 30;
    int gridY = 30;
    int rand1, rand2, rand3, rand4, rand5, rand6, rand7, rand8, rand9, rand10, rand11, rand12, rand13, rand14, rand15, rand16, rand17, rand18, rand19, rand20, rand21, rand22, rand23, rand24, rand25, rand26, rand27, rand28, rand29, rand30 ;
    ofxAssimpModelLoader tree1 ;
    ofxAssimpModelLoader tree2 ;
    ofxAssimpModelLoader tree3 ;
    ofxAssimpModelLoader tree4 ;
    ofxAssimpModelLoader tree5 ;
    ofxAssimpModelLoader tree6 ;
    ofxAssimpModelLoader tree7 ;
    ofxAssimpModelLoader tree8 ;
    ofxAssimpModelLoader tree9 ;
    ofxAssimpModelLoader tree10 ;
    ofxAssimpModelLoader tree11 ;
    ofxAssimpModelLoader tree12 ;
    ofxAssimpModelLoader tree13 ;
    ofxAssimpModelLoader tree14 ;
    ofxAssimpModelLoader tree15 ;
    ofxAssimpModelLoader tree16 ;
    ofxAssimpModelLoader tree17 ;
    ofxAssimpModelLoader tree18 ;
    ofxAssimpModelLoader tree19 ;
    ofxAssimpModelLoader tree20 ;
    ofxAssimpModelLoader tree21 ;
    ofxAssimpModelLoader tree22 ;
    ofxAssimpModelLoader tree23 ;
    ofxAssimpModelLoader tree24 ;
    ofxAssimpModelLoader tree25 ;
    ofxAssimpModelLoader tree26 ;
    ofxAssimpModelLoader tree27 ;
    ofxAssimpModelLoader tree28 ;
    ofxAssimpModelLoader tree29 ;
    ofxAssimpModelLoader tree30 ;
    
    
};