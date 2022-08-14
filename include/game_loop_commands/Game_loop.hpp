#ifndef _GAME_LOOP_H
#define _GAME_LOOP_H
#include <IGame_loop_command.hpp>
#include <Sudoku.hpp>
#include <queue>

namespace sudoku {
namespace game_loop {

class Game_loop {
 public:
  Game_loop();

  void start();

 protected:
  void show_main_menu();
  bool handle_main_menu_input();
  bool handle_game_input();

  void show_difficulty_menu();
  bool handle_difficulty_menu();

 private:
  std::unique_ptr<Sudoku> m_sudoku;
  std::queue<std::unique_ptr<IGame_loop_command>> m_commands;
};

}  // namespace game_loop
}  // namespace sudoku
#endif  // _GAME_LOOP_H