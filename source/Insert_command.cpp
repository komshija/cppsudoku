#include <Insert_command.hpp>

namespace sudoku {
Insert_command::Insert_command(std::weak_ptr<Table> table, Number number)
    : m_table(table), m_number(number), done(false) {}

void Insert_command::exec(size_t row_index, size_t column_index) {
  if (done) {
    throw std::runtime_error("can't do same command twice");
  }
  m_row_index = row_index;
  m_column_index = column_index;
  auto table = m_table.lock();
  if (!table) {
    throw std::runtime_error("table expired");
  }
  m_old_number = table->set_value(m_row_index, m_column_index, m_number);
  done = true;
}

void Insert_command::undo() {
  if (!done) {
    throw std::runtime_error("can't undo something which isn't done");
  }
  auto table = m_table.lock();
  if (!table) {
    throw std::runtime_error("table expired");
  }
  table->set_value(m_row_index, m_column_index, m_old_number);
  done = false;
}
}  // namespace sudoku