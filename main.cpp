#include "GameManager.h"

int main()
{
    GameManager* g = new GameManager(1280, 720, "Flappy Butt");
    g->init();
    return 0;
}