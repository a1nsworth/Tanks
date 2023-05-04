//
// Created by Daniel on 29.04.2023.
//

#ifndef COURSE_WORK_SRC_GAME_MAINWINDOW_H
#define COURSE_WORK_SRC_GAME_MAINWINDOW_H

#include "Window.h"
#include "../application/ApplicationConstants.h"

class MainWindow : public Window
{
 public:
  explicit MainWindow(unsigned short fps = 60, bool vertical_sync = true);
  ~MainWindow() = default;
};

#endif //COURSE_WORK_SRC_GAME_MAINWINDOW_H
