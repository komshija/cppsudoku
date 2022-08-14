#ifndef _INSERT_COMMAND_H
#define _INSERT_COMMAND_H
#include <ISudoku_command.hpp>
#include <memory>

namespace sudoku {
class Insert_command : public sudoku::ISudoku_command {
 public:
  Insert_command(std::weak_ptr<Table> table, size_t row_index,
                 size_t column_index, Number number);
  void get_name(std::string& name) override { name = "insert"; }
  void exec() override;
  void undo() override;

 protected:
  std::weak_ptr<Table> m_table;
  size_t m_row_index;
  size_t m_column_index;
  Number m_number;
  Number m_old_number;
  bool done;
};

}  // namespace sudoku
#endif  // _INSERT_COMMAND_H