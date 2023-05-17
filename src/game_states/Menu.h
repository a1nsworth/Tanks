//
// Created by Daniel on 04.05.2023.
//

#ifndef TANKS_SRC_GAME_STATES_MENU_H_
#define TANKS_SRC_GAME_STATES_MENU_H_

#include "../application/Application.h"
#include "../ui/button/ButtonBuilder.h"
#include "../control/MenuMouseController.h"
#include "../entities/Object.h"
#include "../ui/menu/MainMenu.h"

class Game;

class Menu : public IApplicationState
{
 private:
  MainMenu *main_menu_;

 public:
  Menu();
  ~Menu() = default;

  void Update(Application *application, float delta_time) override;
  void Render(Application *application) override;
  void UpdateEvents(Application *application, float delta_time) override;
};

#endif //TANKS_SRC_GAME_STATES_MENU_H_
