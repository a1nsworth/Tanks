//
// Created by Daniel on 30.04.2023.
//

#include "Window.h"
Window::Window(const sf::VideoMode &video_mode, const sf::String &title)
{
  render_window_ = new sf::RenderWindow(video_mode, title);
}
sf::RenderWindow *Window::GetRenderWindow() const
{
  return render_window_;
}
