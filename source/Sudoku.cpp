#include <Insert_command.hpp>
#include <Sudoku.hpp>

namespace sudoku {
Sudoku::Sudoku(std::string const& table)
    : m_table(std::make_shared<Table>(table)) {}

void Sudoku::insert(size_t row_index, size_t column_index, Number value) {
  std::shared_ptr<Insert_command> cmd =
      std::make_shared<Insert_command>(m_table, row_index, column_index, value);
  cmd->exec();
  m_commands.push(cmd);
  m_table->print();
}

void Sudoku::clear(size_t row_index, size_t column_index) {
  std::shared_ptr<Insert_command> cmd = std::make_shared<Insert_command>(
      m_table, row_index, column_index, Number::EMPTY);
  cmd->exec();
  m_commands.push(cmd);
  m_table->print();
}

void Sudoku::undo() {
  auto cmd = m_commands.top();
  cmd->undo();
  m_commands.pop();
  m_table->print();
}

void Sudoku::save() {}

void Sudoku::load() {}

}  // namespace sudoku
