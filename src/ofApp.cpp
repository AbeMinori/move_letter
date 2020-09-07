#include "ofApp.h"
#include <stdio.h>

//--------------------------------------------------------------
void ofApp::setup(){

    // 画面基本設定
    ofSetFrameRate(60); //秒間60コマで描画
    ofSetVerticalSync(true); //フレームレートの上限をモニタのリフレッシュレートに合わせる
    ofSetBackgroundColor(255); //背景色を白に
    
    // フォント
    ofTrueTypeFont::setGlobalDpi(72);

    font.load("Arial.ttf", 120); //フォントのデータを指定する
    font.setLineHeight(24); //行間を指定する
    font.setLetterSpacing(1.0); //文字間を指定する
    
    //位置と速度を初期化
    location = ofVec2f(ofGetWidth()/2 /*- width_by_space[0]*/, ofGetHeight()/2 /*+ height_by_space[0]*/); //画面の中心に
    location_right = ofVec2f(-font.stringWidth(display_text_enter[0]), ofGetHeight()/2);
    location_left = ofVec2f(ofGetWidth(), ofGetHeight()/2); //画面の右端に
    location_center = ofVec2f(ofGetWidth()/2 , ofGetHeight()/2 /*+ height_by_space[0]*/); //画面の中心に
    velocity_right = ofVec2f(10, 0); //ランダムな速度で
    velocity_left = ofVec2f(-10, 0); //ランダムな速度で
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // 表示の文字
    // spaceキーを押した時
    if (pressed_space >= 1){
        sprintf(text, display_text_space[pressed_space-1].c_str()); //文字の表示
    }
    if(pressed_space > 2){
        pressed_space = 1; //初期化
    }
       
    // enterキーを押した時
    //int direction_array[] = {2,1,2,1,2,1,2,1,2};
    if(pressed_enter >= 1){
        sprintf(text, display_text_enter[pressed_enter-1].c_str()); //文字の表示
        if(pressed_enter%2 == 0){ //pressed_enterが偶数なら左に進む
            move_right = false;
            move_left = true;
        }else{ //奇数なら右に進む
            move_right = true;
            move_left = false;
        }
    }
    
    if(pressed_enter > 10){ //pressed_enterが10より大きくなった場合、何も表示しない
        sprintf(text, "");
    }
    
    if(click){ //マウスがクリックされた時
        angle += 3;
        if(angle == 360){ //角度が360度になった時
            click = false;
            angle = 0;
        }
    }else if(!click){ //マウスがクリックされていない時
        if(pressed_space >= 1){ //pressed_spaceが1以上の時
            location.x = ofGetWidth()/2 - font.stringWidth(display_text_space[pressed_space-1])/2; //location.xを中心に合わせる
            location.y = ofGetHeight()/2 + font.stringHeight(display_text_space[pressed_space-1])/2; //location.yを中心に合わせる
        }
        if((pressed_enter >= 1) && (pressed_enter <= 10)){ //pressed_enterが1以上、10以下の時
            if(move_right){ //右に進む
                velocity_right = ofVec2f(10*(font.stringWidth(display_text_enter[pressed_enter-1])/font.stringWidth(display_text_enter[5])), 0);
                location_right += velocity_right;
                location = location_right;
                if(location.x >= ofGetWidth()){ //右端に文字が行ったら
                    pressed_enter++;
                    location_right = ofVec2f(-font.stringWidth(display_text_enter[pressed_enter]), ofGetHeight()/2);
                }
            }else if (move_left){ //左に進む
                velocity_left = ofVec2f(-10*(font.stringWidth(display_text_enter[pressed_enter-1])/font.stringWidth(display_text_enter[5])), 0);
                location_left += velocity_left;
                location = location_left;
                if ((location.x + font.stringWidth(display_text_enter[pressed_enter-1]))<= 0){ //左端に文字が行ったら
                    pressed_enter++;
                    location_left = ofVec2f(ofGetWidth(), ofGetHeight()/2);
                }
            }
        }
//        if((pressd_enter >= 1) && (pressd_enter <= 10)){
//            location_right += velocity_right; //速度から位置を更新(右に進む)
//            location_left += velocity_left; //速度から位置を更新(左に進む)
//        }
    }
    
    // 色をランダムに変化
    R = ofRandom(255);
    G = ofRandom(255);
    B = ofRandom(255);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if(pressed_space >= 1 || pressed_enter >= 1){
        ofPushMatrix(); //現在の座標系を保存
        ofSetColor(R, G, B); // 文字の色
        ofRotateXDeg(angle); //Z軸周りに回転
        ofRotateYDeg(angle);
        ofRotateZDeg(angle);
        if(angle != 0){
            ofSetBackgroundColor(0); //背景色を白に
        }else{
            ofSetBackgroundColor(255); //背景色を白に
        }
        font.drawString(text,location.x,location.y); // 中央に文字の描画
    
        ofPopMatrix(); //座標系を復元
    }
    
    //if(location_right.x >= ofGetWidth()){ //location_rightが右端に行ったら
    //    location_right = ofVec2f(0, ofGetHeight()/2); //画面の中心に(location_rightの初期化)
    //}else if(location_left.x <= 0){ //location_leftが左端に行ったら
    //    location_left = ofVec2f(ofGetWidth(), ofGetHeight()/2); //画面の中心に(location_leftの初期化)
    //}
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key==32){ //スペースキーのキーコード
        pressed_space++;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    if(key == 13){ //エンターキーのキーコード
        pressed_enter++;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

    if(!click){ //マウスをクリックしたら
        click = true;
    }else if(click){
        click = false;
    }
    
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
