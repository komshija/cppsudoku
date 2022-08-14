#include <game_loop_cmds/Game_loop.hpp>
#include <iostream>

namespace sudoku {
namespace game_loop {

void Game_loop::start() {}

void Game_loop::show_difficulty_menu() {
  std::cout << "# # # # # Select difficulty # # # # #" << std::endl;
  std::cout << "1) Baby" << std::endl;
  std::cout << "2) Kid" << std::endl;
  std::cout << "3) Teen" << std::endl;
  std::cout << "4) Parent" << std::endl;
  std::cout << "5) Grandparent" << std::endl;
}

bool Game_loop::handle_difficulty_menu() {
  std::cout << "Enter number: ";
  std::string input;
  std::cin >> input;
  std::cin.ignore();
  if (input.length() != 1) {
    std::cout << "Invalid input." << std::endl;
  }
  if (input.find('1') != std::string::npos) {
    std::cout << "dummy baby" << std::endl;
  } else if (input.find('2') != std::string::npos) {
    std::cout << "dummy kid" << std::endl;
  } else if (input.find('3') != std::string::npos) {
    std::cout << "dummy teen" << std::endl;
  } else if (input.find('4') != std::string::npos) {
    std::cout << "dummy parent" << std::endl;
  } else if (input.find('5') != std::string::npos) {
    std::cout << "dummy grandparent" << std::endl;
  } else {
    return false;
  }
  return true;
}

bool Game_loop::handle_game_input() {
  // Input in format x y num
  int x, y, num;
  std::cout << "[x y num]:";
  std::cin >> x >> y >> num;
  std::cin.ignore();
  auto check_valid = [](int val) -> bool { return val <= 0 || val >= 9; };
  if (!check_valid(x) || check_valid(y) || check_valid(num)) {
    std::cout << "Invalid input." << std::endl;
    return false;
  } else {
    m_sudoku->insert(x, y, static_cast<Number>(num));
  }
  return true;
}

}  // namespace game_loop
}  // namespace sudoku
