#include <game_loop_cmds/Handle_main_menu_input_command.hpp>
#include <iostream>

namespace sudoku {
namespace game_loop {
bool Handle_main_menu_input_command::exec() {
  std::string input;
  std::cin >> input;
  std::cin.ignore();
  if (input.length() != 1) {
    std::cout << "Invalid input." << std::endl;
  }
  if (input.find('1') != std::string::npos) {
    // Open difficulty menu
    // Make api call and generate new sudoku
  } else if (input.find('2') != std::string::npos) {
    // Open input for filename
  } else if (input.find('3') != std::string::npos) {
    exit(0);
  } else {
    return false;
  }
  return true;
}
}  // namespace game_loop
}  // namespace sudoku
