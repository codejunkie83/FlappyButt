//
// Created by codej on 3/14/2018.
//

#include "GameManager.h"

static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

GameManager::GameManager(int width, int height, const char *windowTitle)
{
    mWidth = width;
    mHeight = height;
    mWindowTitle = windowTitle;
}

GameManager::~GameManager()
{

}

void GameManager::init()
{
    if (!glfwInit())
        exit(EXIT_FAILURE);

    glfwSetErrorCallback(error_callback);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    mWindow = glfwCreateWindow(mWidth, mHeight, mWindowTitle, NULL, NULL);
    if (!mWindow)
    {
        //Error occurred
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(mWindow);

    if (glewInit() != GLEW_OK)
    {
        // GLEW failed to initialize
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // glewExperimental = true;

    while (!glfwWindowShouldClose(mWindow))
    {
        update();
    }

    close();
}

void GameManager::update()
{
    //update subsystems
    glfwGetFramebufferSize(mWindow, &mWidth, &mHeight);
    glViewport(0, 0, mWidth, mHeight);
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.5f, 0.5f, 0.5f, 1.f);

    draw();
    glfwPollEvents();
}

void GameManager::draw()
{
    //process subsystem draw calls
    glfwSwapBuffers(mWindow);
}

void GameManager::close()
{
    glfwDestroyWindow(mWindow);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
