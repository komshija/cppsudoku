#include <game_loop_cmds/Show_main_menu_command.hpp>
#include <iostream>

namespace sudoku {
namespace game_loop {
bool Show_main_menu_command::exec() {
  std::cout << "# # # # # Sudoku # # # # #" << std::endl;
  std::cout << "1) New game" << std::endl;
  std::cout << "2) Load game" << std::endl;
  std::cout << "3) Exit" << std::endl;
  return true;
}
}  // namespace game_loop
}  // namespace sudoku
