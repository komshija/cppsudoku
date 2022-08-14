#ifndef _HANDLE_MAIN_MENU_INPUT_COMMAND_H_
#define _HANDLE_MAIN_MENU_INPUT_COMMAND_H_
#include <game_loop_cmds/IGame_loop_command.hpp>

namespace sudoku {
namespace game_loop {
class Handle_main_menu_input_command : public IGame_loop_command {
 public:
  void get_name(std::string& name) { name = "handle_main_menu_input"; }
  bool exec();
};
}  // namespace game_loop
}  // namespace sudoku
#endif  // _HANDLE_MAIN_MENU_INPUT_COMMAND_H_