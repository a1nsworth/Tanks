//
// Created by Daniel on 29.04.2023.
//

#include "MainWindow.h"

MainWindow::MainWindow(const unsigned short fps, const bool vertical_sync) : Window(sf::VideoMode(WIDTH_MAIN_WINDOW, HEIGHT_MAIN_WINDOW), TITLE_MAIN_WINDOW)
{
  this->render_window_->setVerticalSyncEnabled(vertical_sync);
  this->render_window_->setFramerateLimit(fps);
}
