//
// Created by codej on 3/14/2018.
//

#ifndef FLAPPYBUTT_GAMEMANAGER_H
#define FLAPPYBUTT_GAMEMANAGER_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <cstdio>
#include <cstdlib>

class GameManager {
public:
    GameManager(int width, int height, const char* windowTitle);
    ~GameManager();

    void init();
private:
    GLFWwindow * mWindow;

    int mWidth, mHeight;
    const char* mWindowTitle;

    void update();
    void draw();
    void close();
};


#endif //FLAPPYBUTT_GAMEMANAGER_H
