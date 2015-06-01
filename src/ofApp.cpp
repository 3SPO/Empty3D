//Alex Esposito
//FFTerrain final
//6/1/15

#include "ofApp.h"

//-----------------------------------------------------------------------------------------
//
void ofApp::setup()
{
    
    //set up some simple settings
    ofSetFrameRate(30);
    ofSetVerticalSync(true);
    ofBackground(100);
    
    //set up the fft
    fftFile.setMirrorData(false);
    fftFile.setup();
    
    //load in the song
    soundPlayer.loadSound("sound/ellie.wav");
    //loops the song
    soundPlayer.setLoop(true);
    //play the song when started
    soundPlayer.play();
    //sets up a random scale for all models
    float randScale = ofRandom(.004, .01) ;
    //brute force load 30 models
    tree1.loadModel("tree1.stl") ;
    tree1.setScale(randScale,randScale,randScale) ;
    tree2.loadModel("tree1.stl") ;
    tree2.setScale(randScale,randScale,randScale) ;
    tree3.loadModel("tree1.stl") ;
    tree3.setScale(randScale,randScale,randScale) ;
    tree4.loadModel("tree1.stl") ;
    tree4.setScale(randScale,randScale,randScale) ;
    tree5.loadModel("tree1.stl") ;
    tree5.setScale(randScale,randScale,randScale) ;
    tree6.loadModel("tree2.stl") ;
    tree6.setScale(randScale,randScale,randScale) ;
    tree7.loadModel("tree2.stl") ;
    tree7.setScale(randScale,randScale,randScale) ;
    tree8.loadModel("tree2.stl") ;
    tree8.setScale(randScale,randScale,randScale) ;
    tree9.loadModel("tree2.stl") ;
    tree9.setScale(randScale,randScale,randScale) ;
    tree10.loadModel("tree2.stl") ;
    tree10.setScale(randScale,randScale,randScale) ;
    tree11.loadModel("tree3.stl") ;
    tree11.setScale(randScale,randScale,randScale) ;
    tree12.loadModel("tree3.stl") ;
    tree12.setScale(randScale,randScale,randScale) ;
    tree13.loadModel("tree3.stl") ;
    tree13.setScale(randScale,randScale,randScale) ;
    tree14.loadModel("tree3.stl") ;
    tree14.setScale(randScale,randScale,randScale) ;
    tree15.loadModel("tree3.stl") ;
    tree15.setScale(randScale,randScale,randScale) ;
    tree16.loadModel("tree1.stl") ;
    tree16.setScale(randScale,randScale,randScale) ;
    tree17.loadModel("tree1.stl") ;
    tree17.setScale(randScale,randScale,randScale) ;
    tree18.loadModel("tree1.stl") ;
    tree18.setScale(randScale,randScale,randScale) ;
    tree19.loadModel("tree1.stl") ;
    tree19.setScale(randScale,randScale,randScale) ;
    tree20.loadModel("tree1.stl") ;
    tree20.setScale(randScale,randScale,randScale) ;
    tree21.loadModel("tree2.stl") ;
    tree21.setScale(randScale,randScale,randScale) ;
    tree22.loadModel("tree2.stl") ;
    tree22.setScale(randScale,randScale,randScale) ;
    tree23.loadModel("tree2.stl") ;
    tree23.setScale(randScale,randScale,randScale) ;
    tree24.loadModel("tree2.stl") ;
    tree24.setScale(randScale,randScale,randScale) ;
    tree25.loadModel("tree2.stl") ;
    tree25.setScale(randScale,randScale,randScale) ;
    tree26.loadModel("tree3.stl") ;
    tree26.setScale(randScale,randScale,randScale) ;
    tree27.loadModel("tree3.stl") ;
    tree27.setScale(randScale,randScale,randScale) ;
    tree28.loadModel("tree3.stl") ;
    tree28.setScale(randScale,randScale,randScale) ;
    tree29.loadModel("tree3.stl") ;
    tree29.setScale(randScale,randScale,randScale) ;
    tree30.loadModel("tree3.stl") ;
    tree30.setScale(randScale,randScale,randScale) ;
    
    //brute for generate 30 random numers between 350 and 650
    rand1 = (int)ofRandom(350, 650) ; rand2 = (int)ofRandom(350, 650) ; rand3 = (int)ofRandom(350, 650) ; rand4 = (int)ofRandom(350, 650) ; rand5 = (int)ofRandom(350, 650) ; rand6 = (int)ofRandom(350, 650) ; rand7 = (int)ofRandom(350, 650) ; rand8 = (int)ofRandom(350, 650) ; rand9 = (int)ofRandom(350, 650) ; rand10 = (int)ofRandom(350, 650) ; rand11 = (int)ofRandom(350, 650) ; rand12 = (int)ofRandom(350, 650) ; rand13 = (int)ofRandom(350, 650) ; rand14 = (int)ofRandom(350, 650) ; rand15 = (int)ofRandom(350, 650), rand16 = (int)ofRandom(350, 650) ; rand17 = (int)ofRandom(350, 650) ; rand18 = (int)ofRandom(260, 425) ; rand19 = (int)ofRandom(350, 650) ; rand20 = (int)ofRandom(350, 650) ; rand21 = (int)ofRandom(350, 650) ; rand22 = (int)ofRandom(350, 650) ; rand23 = (int)ofRandom(350, 650) ; rand24 = (int)ofRandom(350, 650) ; rand25 = (int)ofRandom(350, 650) ; rand26 = (int)ofRandom(350, 650) ; rand27 = (int)ofRandom(350, 650) ; rand28 = (int)ofRandom(350, 650) ; rand29 = (int)ofRandom(350, 650) ; rand30 = (int)ofRandom(350, 650) ;
    
    
    
    
    //create all of the vertex points and give the color
    for (int y=0; y<gridY; y++) {
        for (int x=0; x<gridX; x++) {
            mesh.addVertex(ofPoint( (x - gridX/2), (y - gridY/2), 0 ) );
            mesh.addColor( ofColor( 0, 0, 0 ) );
        }
    }
    //actually create the triangles
    for (int y=0; y<gridY-1; y++) {
        for (int x=0; x<gridX-1; x++) {
            int i1 = x + gridX * y;
            int i2 = x+1 + gridX * y;
            int i3 = x + gridX * (y+1);
            int i4 = x+1 + gridX * (y+1);
            mesh.addTriangle( i1, i2, i3 );
            mesh.addTriangle( i2, i4, i3 );
        }
    }
    
    setNormals( mesh ); //Set normals to the surface
    //Note, setNormals is our function, which is declared
    
    // Make the camera look down
    camera.setNearClip(0.01f);
    camera.setPosition( -15, 4, -15 );
    camera.lookAt( ofVec3f( 0, 0, 0 ));
    camera.setMovementMaxSpeed( 1 );
    
    //Enabling light source
    light.enable();
    
}

//-----------------------------------------------------------------------------------------
//
void ofApp::update()
{
    fftFile.update();
    
    //=====moving noise=================================
    float time = ofGetElapsedTimef();	//Get time
    //Change vertices
    for (int y=0; y<gridY; y++) {
        for (int x=0; x<gridX; x++) {
            int i = x + gridX * y;			//Vertex index
            ofPoint change = mesh.getVertex( i );
            
            float value = ofNoise(.2, y * (fftFile.getAveragePeak() * .2), time * .7) ;
            float value2 = ofNoise((fftFile.getAveragePeak() * .2), value , value) ;
            //Change z-coordinate of vertex
            change.z = value * value2 * 4;
            mesh.setVertex( i, change );
            color.set(28, 113, 38) ;
            
            //Change color of vertex
            mesh.setColor( i, color );
        }
    }
    //brute force set the position of every tree
    tree1.setPosition(mesh.getVertex(rand1).x,mesh.getVertex(rand1).y,mesh.getVertex(rand1).z) ;
    tree2.setPosition(mesh.getVertex(rand2).x,mesh.getVertex(rand2).y,mesh.getVertex(rand2).z) ;
    tree3.setPosition(mesh.getVertex(rand3).x,mesh.getVertex(rand3).y,mesh.getVertex(rand3).z) ;
    tree4.setPosition(mesh.getVertex(rand4).x,mesh.getVertex(rand4).y,mesh.getVertex(rand4).z) ;
    tree5.setPosition(mesh.getVertex(rand5).x,mesh.getVertex(rand5).y,mesh.getVertex(rand5).z) ;
    tree6.setPosition(mesh.getVertex(rand6).x,mesh.getVertex(rand6).y,mesh.getVertex(rand6).z) ;
    tree7.setPosition(mesh.getVertex(rand7).x,mesh.getVertex(rand7).y,mesh.getVertex(rand7).z) ;
    tree8.setPosition(mesh.getVertex(rand8).x,mesh.getVertex(rand8).y,mesh.getVertex(rand8).z) ;
    tree9.setPosition(mesh.getVertex(rand9).x,mesh.getVertex(rand9).y,mesh.getVertex(rand9).z) ;
    tree10.setPosition(mesh.getVertex(rand10).x,mesh.getVertex(rand10).y,mesh.getVertex(rand10).z) ;
    tree11.setPosition(mesh.getVertex(rand11).x,mesh.getVertex(rand11).y,mesh.getVertex(rand11).z) ;
    tree12.setPosition(mesh.getVertex(rand12).x,mesh.getVertex(rand12).y,mesh.getVertex(rand12).z) ;
    tree13.setPosition(mesh.getVertex(rand13).x,mesh.getVertex(rand13).y,mesh.getVertex(rand13).z) ;
    tree14.setPosition(mesh.getVertex(rand14).x,mesh.getVertex(rand14).y,mesh.getVertex(rand14).z) ;
    tree15.setPosition(mesh.getVertex(rand15).x,mesh.getVertex(rand15).y,mesh.getVertex(rand15).z) ;
    tree16.setPosition(mesh.getVertex(rand16).x,mesh.getVertex(rand16).y,mesh.getVertex(rand16).z) ;
    tree17.setPosition(mesh.getVertex(rand17).x,mesh.getVertex(rand17).y,mesh.getVertex(rand17).z) ;
    tree18.setPosition(mesh.getVertex(rand18).x,mesh.getVertex(rand18).y,mesh.getVertex(rand18).z) ;
    tree19.setPosition(mesh.getVertex(rand19).x,mesh.getVertex(rand19).y,mesh.getVertex(rand19).z) ;
    tree20.setPosition(mesh.getVertex(rand20).x,mesh.getVertex(rand20).y,mesh.getVertex(rand20).z) ;
    tree21.setPosition(mesh.getVertex(rand21).x,mesh.getVertex(rand21).y,mesh.getVertex(rand21).z) ;
    tree22.setPosition(mesh.getVertex(rand22).x,mesh.getVertex(rand22).y,mesh.getVertex(rand22).z) ;
    tree23.setPosition(mesh.getVertex(rand23).x,mesh.getVertex(rand23).y,mesh.getVertex(rand23).z) ;
    tree24.setPosition(mesh.getVertex(rand24).x,mesh.getVertex(rand24).y,mesh.getVertex(rand24).z) ;
    tree25.setPosition(mesh.getVertex(rand25).x,mesh.getVertex(rand25).y,mesh.getVertex(rand25).z) ;
    tree26.setPosition(mesh.getVertex(rand26).x,mesh.getVertex(rand26).y,mesh.getVertex(rand26).z) ;
    tree27.setPosition(mesh.getVertex(rand27).x,mesh.getVertex(rand27).y,mesh.getVertex(rand28).z) ;
    tree28.setPosition(mesh.getVertex(rand28).x,mesh.getVertex(rand28).y,mesh.getVertex(rand28).z) ;
    tree29.setPosition(mesh.getVertex(rand29).x,mesh.getVertex(rand29).y,mesh.getVertex(rand29).z) ;
    tree30.setPosition(mesh.getVertex(rand30).x,mesh.getVertex(rand30).y,mesh.getVertex(rand30).z) ;
    
    setNormals( mesh );	//Update the normals
    
}

//-----------------------------------------------------------------------------------------
//
void ofApp::draw()
{
    ofBackgroundGradient( ofColor(40,40,40), ofColor(0,0,0), OF_GRADIENT_CIRCULAR);
    
    ofEnableDepthTest(); //start the depth test every frame
    
    camera.begin(); //start drawing to the camera view
    
    // draw a grid on the floor
    ofSetColor( ofColor(60) ); //color of the grid
    ofPushMatrix();
    ofRotate(90, 0, 0, -1); //turn the YZ plane CCW to make a "floor"
    //ofDrawGridPlane( 15, 10, false); //Draws a YZ plane
    ofPopMatrix();
    //============================================================
    ofPushMatrix();	//Store the coordinate system
    
    ofRotate( 90, -1, 0, 0 );
    ofTranslate(0, 0, -2.5);//Rotate coordinate system
    
    //Draw mesh
    mesh.draw();
    //brute force rotate and draw all trees
    tree1.setRotation(0,90,1,0,0) ;
    tree1.drawFaces() ;
    tree2.setRotation(0,90,1,0,0) ;
    tree2.drawFaces() ;
    tree3.setRotation(0,90,1,0,0) ;
    tree3.drawFaces() ;
    tree4.setRotation(0,90,1,0,0) ;
    tree4.drawFaces() ;
    tree5.setRotation(0,90,1,0,0) ;
    tree5.drawFaces() ;
    tree6.setRotation(0,90,1,0,0) ;
    tree6.drawFaces() ;
    tree7.setRotation(0,90,1,0,0) ;
    tree7.drawFaces() ;
    tree8.setRotation(0,90,1,0,0) ;
    tree8.drawFaces() ;
    tree9.setRotation(0,90,1,0,0) ;
    tree9.drawFaces() ;
    tree10.setRotation(0,90,1,0,0) ;
    tree10.drawFaces() ;
    tree11.setRotation(0,90,1,0,0) ;
    tree11.drawFaces() ;
    tree12.setRotation(0,90,1,0,0) ;
    tree12.drawFaces() ;
    tree13.setRotation(0,90,1,0,0) ;
    tree13.drawFaces() ;
    tree14.setRotation(0,90,1,0,0) ;
    tree14.drawFaces() ;
    tree15.setRotation(0,90,1,0,0) ;
    tree15.drawFaces() ;
    tree16.setRotation(0,90,1,0,0) ;
    tree16.drawFaces() ;
    tree17.setRotation(0,90,1,0,0) ;
    tree17.drawFaces() ;
    tree18.setRotation(0,90,1,0,0) ;
    tree18.drawFaces() ;
    tree19.setRotation(0,90,1,0,0) ;
    tree19.drawFaces() ;
    tree20.setRotation(0,90,1,0,0) ;
    tree20.drawFaces() ;
    tree21.setRotation(0,90,1,0,0) ;
    tree21.drawFaces() ;
    tree22.setRotation(0,90,1,0,0) ;
    tree22.drawFaces() ;
    tree23.setRotation(0,90,1,0,0) ;
    tree23.drawFaces() ;
    tree24.setRotation(0,90,1,0,0) ;
    tree24.drawFaces() ;
    tree25.setRotation(0,90,1,0,0) ;
    tree25.drawFaces() ;
    tree26.setRotation(0,90,1,0,0) ;
    tree26.drawFaces() ;
    tree27.setRotation(0,90,1,0,0) ;
    tree27.drawFaces() ;
    tree28.setRotation(0,90,1,0,0) ;
    tree28.drawFaces() ;
    tree29.setRotation(0,90,1,0,0) ;
    tree29.drawFaces() ;
    tree30.setRotation(0,90,1,0,0) ;
    tree30.drawFaces() ;
    
    ofPopMatrix();

    camera.end(); //stop drawing to the camera
    
    
    ofDisableDepthTest(); //stop drawing to the z-buffer
    
}

//--------------------------------------------------------------
//Universal function which sets normals for the triangle mesh
void ofApp::setNormals( ofMesh &mesh ){
    
    //The number of the vertices
    int nV = mesh.getNumVertices();
    
    //The number of the triangles
    int nT = mesh.getNumIndices() / 3;
    
    vector<ofPoint> norm( nV ); //Array for the normals
    
    //Scan all the triangles. For each triangle add its
    //normal to norm's vectors of triangle's vertices
    for (int t=0; t<nT; t++) {
        
        //Get indices of the triangle t
        int i1 = mesh.getIndex( 3 * t );
        int i2 = mesh.getIndex( 3 * t + 1 );
        int i3 = mesh.getIndex( 3 * t + 2 );
        
        //Get vertices of the triangle
        const ofPoint &v1 = mesh.getVertex( i1 );
        const ofPoint &v2 = mesh.getVertex( i2 );
        const ofPoint &v3 = mesh.getVertex( i3 );
        
        //Compute the triangle's normal
        ofPoint dir = ( (v2 - v1).crossed( v3 - v1 ) ).normalized();
        
        //Accumulate it to norm array for i1, i2, i3
        norm[ i1 ] += dir;
        norm[ i2 ] += dir;
        norm[ i3 ] += dir;
    }
    
    //Normalize the normal's length
    for (int i=0; i<nV; i++) {
        norm[i].normalize();
    }
    
    //Set the normals to mesh
    mesh.clearNormals();
    mesh.addNormals( norm );
}

//-----------------------------------------------------------------------------------------
//
void ofApp::keyPressed(int key)
{
    if( key == 'f' )
    {
        ofToggleFullscreen();
    }
}