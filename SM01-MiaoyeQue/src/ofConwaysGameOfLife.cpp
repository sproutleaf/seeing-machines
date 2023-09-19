#include "ofConwaysGameOfLife.h"

//--------------------------------------------------------------
void ofConwaysGameOfLife::setup(){
    ofSetFrameRate(3);
    ofSetWindowShape(w, h);
    canvas.allocate(w, h, OF_IMAGE_GRAYSCALE);
    
    rPentomino();
}

//--------------------------------------------------------------
void ofConwaysGameOfLife::update(){

}

//--------------------------------------------------------------
void ofConwaysGameOfLife::draw(){
    canvas.draw(0, 0);
    
    if (!paused) {
        ofPixels pixels = canvas.getPixels();
        for (int x = 0; x < canvas.getWidth(); x += l) {
            for (int y = 0; y < canvas.getHeight(); y += l) {
                int numAliveNeighbors = countNumAliveNeighbors(x, y);
                
                if (isAlive(x, y) && (numAliveNeighbors < 2 ||
                                      numAliveNeighbors > 3)) {
                    ofColor color = ofColor(0);
                    drawCell(x, y, pixels, color);
                    continue;
                }
                if (!isAlive(x, y) && (numAliveNeighbors == 3)) {
                    ofColor color = ofColor(255);
                    drawCell(x, y, pixels, color);
                }
            }
        }
        canvas.setFromPixels(pixels);
    }
}

//--------------------------------------------------------------
void ofConwaysGameOfLife::exit(){
    
}

//--------------------------------------------------------------
void ofConwaysGameOfLife::keyPressed(int key){
    if (key == 'p') {
        paused = !paused;
    }

    if (key == 'r') {
        random();
    }
    
    if (key == 'l') {
        setAllCells(true);
    }
    
    if (key == 'd') {
        setAllCells(false);
    }
}

//--------------------------------------------------------------
void ofConwaysGameOfLife::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofConwaysGameOfLife::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofConwaysGameOfLife::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofConwaysGameOfLife::mousePressed(int x, int y, int button){
    ofPixels pixels = canvas.getPixels();
        
    ofColor color = canvas.getColor(x, y);
    ofColor new_color = (color == ofColor(255)) ? ofColor(0) : ofColor(255);
        
    drawCell((x / l) * l, (y / l) * l, pixels, new_color);
    canvas.setFromPixels(pixels);
}
    

//--------------------------------------------------------------
void ofConwaysGameOfLife::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofConwaysGameOfLife::mouseScrolled(int x, int y, float scrollX, float scrollY){
    
}

//--------------------------------------------------------------
void ofConwaysGameOfLife::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofConwaysGameOfLife::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofConwaysGameOfLife::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofConwaysGameOfLife::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofConwaysGameOfLife::dragEvent(ofDragInfo dragInfo){
    
}

void ofConwaysGameOfLife::setAllCells(bool isAlive) {
    ofPixels pixels = canvas.getPixels();
    ofColor color = isAlive ? ofColor(255) : ofColor(0);
    for (int x = 0; x < canvas.getWidth(); x++) {
        for (int y = 0; y < canvas.getHeight(); y++) {
            pixels.setColor(x, y, color);
        }
    }
    
    canvas.setFromPixels(pixels);
}

void ofConwaysGameOfLife::rPentomino() {
    setAllCells(false);
    
    ofPixels pixels = canvas.getPixels();
    drawCell(190, 150, pixels, ofColor(255));
    drawCell(200, 150, pixels, ofColor(255));
    drawCell(180, 160, pixels, ofColor(255));
    drawCell(190, 160, pixels, ofColor(255));
    drawCell(190, 170, pixels, ofColor(255));
    
    canvas.setFromPixels(pixels);
}

void ofConwaysGameOfLife::random() {
    ofPixels pixels = canvas.getPixels();
    for (int x = 0; x < canvas.getWidth(); x += l) {
        for (int y = 0; y < canvas.getHeight(); y+= l) {
            ofColor color = (ofRandomuf() < 0.5) ? ofColor(0) : ofColor(255);
            drawCell(x, y, pixels, color);
        }
    }
    
    canvas.setFromPixels(pixels);
}

void ofConwaysGameOfLife::drawCell(int x, int y, ofPixels& pixels, ofColor color) {
    for (int i = x; i < x + l; i++) {
        for (int j = y; j < y + l; j++) {
            pixels.setColor(i, j, color);
        }
    }
}

int ofConwaysGameOfLife::isAlive(int x, int y) {
    ofColor color = canvas.getColor(x, y);
    if (x < 0 || x > canvas.getWidth() ||
        y < 0 || y > canvas.getHeight()) {
        return 0;
    }
    int i = (color == ofColor(255)) ? 1 : 0;
    
    return i;
}

int ofConwaysGameOfLife::countNumAliveNeighbors(int x, int y) {
    int n = 0;
    
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            n += isAlive(x + i * l, y + j * l);
        }
    }
    
    return n;
}
