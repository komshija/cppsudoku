#ifndef _ICOMMAND_H
#define _ICOMMAND_H
#include <Table.hpp>
#include <string>

namespace sudoku {
class ISudoku_command {
 public:
  virtual void get_name(std::string& name) = 0;
  virtual void exec(size_t row_index, size_t column_index) = 0;
  virtual void undo() = 0;
  ~ISudoku_command() = default;
};

}  // namespace sudoku
#endif  // _ICOMMAND_H