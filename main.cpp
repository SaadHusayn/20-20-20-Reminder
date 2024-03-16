#include<iostream>
#include<windows.h>
#include<thread>
#include<chrono>
using namespace std;


void pressKey(int keyCode) {
    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wScan = 0;
    input.ki.time = 0;
    input.ki.dwExtraInfo = 0;
    input.ki.wVk = keyCode;
    input.ki.dwFlags = 0; // 0 for key press

    SendInput(1, &input, sizeof(INPUT));
}

void releaseKey(int keyCode) {
    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wScan = 0;
    input.ki.time = 0;
    input.ki.dwExtraInfo = 0;
    input.ki.wVk = keyCode;
    input.ki.dwFlags = KEYEVENTF_KEYUP;

    SendInput(1, &input, sizeof(INPUT));
}

void minimize_all_windows(){
    pressKey(VK_LWIN);
    pressKey(char('D'));
    releaseKey(VK_LWIN);
    releaseKey(char('D'));
}

void display_image(){
    system(".\\image.png");
}

void main_loop(){
    cout<<"20-20-20-Reminder has been started...."<<endl;
    while(true){
        int time  = 20 * 60 * 1000; 
        Sleep(time); //takes time in milliseconds
        minimize_all_windows();
        display_image();
        cout<<"Reminder...."<<endl;
    }
    
}

int main() {

    main_loop();
    
    return 0;
}
