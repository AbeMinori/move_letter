#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

    private:
        ofTrueTypeFont font; //フォント
    
        ofVec2f location; //文字の位置
        ofVec2f location_right; //右に進ませる場合の位置
        ofVec2f location_left; //左に進ませる場合の位置
        ofVec2f location_center; //中央に表示させる場合の位置
        ofVec2f velocity_right; //右に行く速度
        ofVec2f velocity_left; //左に行く速度
        
        int direction = 0; //方向
        double angle; //角度
    
        int pressed_enter = 0; //エンターキーを押した時に増える変数
        int pressed_space = 0; //スペースキーを押した時に増える変数
        bool click = false; //マウスがクリックされたかどうか
    
//#define MOVE_RIGHT 1
//#define MOVE_LEFT 2
//int move_direction = MOVE_RIGHT;
    
//typedef struct{
//    MOVE_RIGHT = 1,
//    MOVE_LEFT =2,
//}Move_Direction_t;
//
//Move_Direction_t move_direction = MOVE_RIGHT;
    
        bool move_right = true;
        bool move_left = false;
    
        //float width_by_space[2] = {font.stringWidth("ALEXANDROS")/2,font.stringWidth("Boo!")/2};
        //float height_by_space[2] = {font.stringHeight("ALEXANDROS")/2,font.stringHeight("Boo!")/2}; //文字の幅と高さの変数
    
        char text[255]; //テキストデータの変数の宣言
    
        int R; //R値
        int G; //G値
        int B; //B値
    
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
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
		
        const std::string display_text_enter[10] = {
            "I've got no luck",
            "They call me 'You suck!'",
            "But at least I know I've got a dope track",
            "You can call me big-headed",
            "And tweet them in bed",
            "But I'll tear u into a shred",
            "I'm got no time to make it all thyme",
            "but at least i know I've got a few dime",
            "I'ma take stand on the rough-sand",
            "I'ma make them understand",
        };
        
        const std::string display_text_space[2] = {
            "[ALEXANDROS]",
            "Boo!",
        };
    
};
