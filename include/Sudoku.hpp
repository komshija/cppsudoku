#ifndef _SUDOKU_GAME_H
#define _SUDOKU_GAME_H
#include <ISudoku_command.hpp>
#include <Table.hpp>
#include <memory>
#include <stack>

/**
 * @brief This class should be handling user input and act like fasade for whole
 * game
 *
 */
namespace sudoku {
class Sudoku {
 public:
  Sudoku(std::string const& table);
  void insert(size_t row_index, size_t column_index, Number value);
  void undo();

 protected:
  std::shared_ptr<Table> m_table;
  std::stack<std::shared_ptr<ISudoku_command>> m_commands;
};

}  // namespace sudoku
#endif  // _SUDOKU_GAME_H