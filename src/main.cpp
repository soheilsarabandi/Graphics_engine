#include "../include/glad.h"
#include "../include/input.hpp"
#include "../include/screen.hpp"
#include "SDL2/SDL.h"

#include <iostream>

bool isAppRunning = true;

int main() {

  Screen::Instance()->Initialize();

  float xPose = 0.0f;
  float yPose = 0.0f;

  while (isAppRunning) {
    Screen::Instance()->ClearScreen();
    Input::Instance()->Update();

    char keyPressed = Input::Instance()->GetKeyDown();
    isAppRunning = !Input::Instance()->IsXClicked();

    if (Input::Instance()->IsKeyPressed()) {
      if (Input::Instance()->GetKeyDown() == 'a') {
        xPose -= 0.01f;
      } else if (Input::Instance()->GetKeyDown() == 'd') {
        xPose += 0.01f;
      } else if (Input::Instance()->GetKeyDown() == 'w') {
        yPose += 0.01f;
      } else if (Input::Instance()->GetKeyDown() == 's') {
        yPose -= 0.01f;
      }
    }

    // render a quad the OLD way
    glBegin(GL_QUADS);

    // top left color and vertex of quad
    glColor3f(1, 0, 0);
    glVertex3f(xPose - 0.5f, yPose + 0.5f, 0.0f);

    // top right color and vertex of quad
    glColor3f(0, 1, 0);
    glVertex3f(xPose + 0.5f, yPose + 0.5f, 0.0f);

    // bottom right color and vertex of quad
    glColor3f(0, 0, 1);
    glVertex3f(xPose + 0.5f, yPose - 0.5f, 0.0f);

    // bottom left color and vertex of quad
    glColor3f(0, 0, 1);
    glVertex3f(xPose - 0.5f, yPose - 0.5f, 0.0f);

    glEnd();
    // update render Stuff
    Screen::Instance()->Present();
  }
  Screen::Instance()->Shutdown();

  system("pause");
  return 0;
}
