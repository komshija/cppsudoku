#ifndef _SHOW_MAIN_MENU_COMMAND_H
#define _SHOW_MAIN_MENU_COMMAND_H
#include <game_loop_cmds/IGame_loop_command.hpp>
namespace sudoku {
namespace game_loop {
class Show_main_menu_command : public IGame_loop_command {
 public:
  void get_name(std::string& name) { name = "show_main_menu"; }
  bool exec();
};
}  // namespace game_loop
}  // namespace sudoku
#endif  // _SHOW_MAIN_MENU_COMMAND_H