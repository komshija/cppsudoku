#ifndef _ERASE_COMMAND_H
#define _ERASE_COMMAND_H
#include <ISudoku_command.hpp>

namespace sudoku {
class Erase_command : public ISudoku_command {
 public:
  Erase_command();
  void get_name(std::string& name) { name = "erase"; }
  void exec(size_t row_index, size_t column_index);
  void undo();
};

}  // namespace sudoku
#endif  // _ERASE_COMMAND_H