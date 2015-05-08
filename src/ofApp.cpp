#include "ofApp.h"


void ofApp::setup(){
        bg.loadMovie("bg.mp4");
    ol.loadImage("ol.png")  ;

    bg.play();
    
    ofDirectory dir;
    
    int nFiles = dir.listDir("anim");
    
    if(nFiles) {
        
        for(int i=0; i<dir.numFiles(); i++) {
            
            // add the image to the vector
            string filePath = dir.getPath(i);
            images.push_back(ofImage());
            images.back().loadImage(filePath);
            
        }
    }
    
    for (int i=0; i<100; ++i) {
        flock.addBoid();
    }
    flock.addBoid();
 

}


void ofApp::update(){
    
    flock.update();
    bg.update();

}


void ofApp::draw(){
    
    bg.draw(0, 0, ofGetWidth(), ofGetHeight());
     ofSetColor(255,255,255,0);
        flock.draw();

    ofSetColor(255,255,255,255);
    
    int frameIndex = 0;
        frameIndex = (int)(ofGetElapsedTimef() * 24) % images.size();



     for (int i=0; i<flock.boids.size(); i++) {
          flock.boids[i].seek(ofPoint(mouseX,mouseY));
         flock.boids[i].maxspeed = 7;
         flock.boids[i].maxforce = .01;
         int j = frameIndex;
         ofPushMatrix();
         ofTranslate(flock.boids[i].loc.x, flock.boids[i].loc.y+20);
         ofRotateZ(flock.boids[i].dirAgnle-90);
         images[j].draw(0,0, 40, 40);
         ofPopMatrix();
         
        
     }
    
    float rand;
    rand = +ofRandom(0, 2);
    ol.draw(0, 0,ofGetWidth(), ofGetHeight());

}


