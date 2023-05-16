//
// Created by Daniel on 29.04.2023.
//

#ifndef TANKS_SRC_WINDOW_MAINWINDOW_H_
#define TANKS_SRC_WINDOW_MAINWINDOW_H_

#include "Window.h"
#include "../application/ApplicationConstants.h"

class MainWindow : public Window
{
 public:
  explicit MainWindow(unsigned short fps = 60, bool vertical_sync = true);
  ~MainWindow() = default;
};

#endif //TANKS_SRC_WINDOW_MAINWINDOW_H_
