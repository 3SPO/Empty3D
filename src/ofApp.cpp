//Alex Esposito
//5/11/15
//3D Noise Example
#include "ofApp.h"

//-----------------------------------------------------------------------------------------
//
void ofApp::setup()
{
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
    camera.setPosition( 0, 30, 1 );
    camera.lookAt( ofVec3f( 0, 0, 0 ));
    camera.setMovementMaxSpeed( 1 );
    
    //Enabling light source
    light.enable();
    
    //=====static noise=================================
    
    //Change vertices
    for (int y=0; y<gridY; y++) {
        for (int x=0; x<gridX; x++) {
            int i = x + gridX * y;			//Vertex index
            ofPoint change = mesh.getVertex( i );
            
            //Get noise value
            float value = ofNoise( x * 1000, y * 1000, 2 * .06 );
            
            //Change z-coordinate of vertex
            change.z = value * 5;
            mesh.setVertex( i, change );
            
            color.setHsb(255 * value, 220, 255) ;
            //Change color of vertex
            mesh.setColor( i, color );
        }
    }
    setNormals( mesh );	//Update the normals
    
}

//-----------------------------------------------------------------------------------------
//
void ofApp::update()
{
    //=====moving noise=================================
    float time = ofGetElapsedTimef();	//Get time
    //Change vertices
    for (int y=0; y<gridY; y++) {
        for (int x=0; x<gridX; x++) {
            int i = x + gridX * y;			//Vertex index
            ofPoint change = mesh.getVertex( i );
            
            //Get Perlin noise value
            float value = ofNoise( x * 1000, y * 1000, time * .06 );
            
            //Change z-coordinate of vertex
            change.z = value * 5;
            mesh.setVertex( i, change );
            
            color.setHsb(255 * value, 220, 255) ;
            //Change color of vertex
            mesh.setColor( i, color );
        }
    }
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