#include <Game_loop.hpp>
#include <iostream>

namespace sudoku {
namespace game_loop {

void Game_loop::start() {}

void Game_loop::show_main_menu() {
  std::cout << "# # # # # Sudoku # # # # #" << std::endl;
  std::cout << "1) New game" << std::endl;
  std::cout << "2) Load game" << std::endl;
  std::cout << "3) Exit" << std::endl;
  std::cout << "Enter number: ";
}

bool Game_loop::handle_main_menu_input() {
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

void Game_loop::show_difficulty_menu() {
  std::cout << "# # # # # Select difficulty # # # # #" << std::endl;
  std::cout << "1) Baby" << std::endl;
  std::cout << "2) Kid" << std::endl;
  std::cout << "3) Teen" << std::endl;
  std::cout << "4) Parent" << std::endl;
  std::cout << "5) Grandparent" << std::endl;
  std::cout << "Enter number: ";
}

bool Game_loop::handle_difficulty_menu() {
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
