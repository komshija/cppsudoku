#ifndef _ICOMMAND_H
#define _ICOMMAND_H
#include <Table.hpp>
#include <string>

namespace sudoku {
class ISudoku_command {
 public:
  virtual void get_name(std::string& name) = 0;
  virtual void exec() = 0;
  virtual void undo() = 0;
  virtual ~ISudoku_command() = default;
};

}  // namespace sudoku
#endif  // _ICOMMAND_H