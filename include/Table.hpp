#ifndef _SUDOKU_TABLE_H_
#define _SUDOKU_TABLE_H_

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

namespace sudoku {
enum class Number {
  EMPTY,
  ONE,
  TWO,
  THREE,
  FOUR,
  FIVE,
  SIX,
  SEVEN,
  EIGHT,
  NINE
};

class Table {
 public:
  Table(std::string const& table);
  bool is_valid();
  bool is_finished();
  void print();
  void get_value(const size_t row_i, const size_t col_i, Number& number) const;
  Number set_value(const size_t row_i, const size_t col_i,
                   Number const& number);

 protected:
  bool check_rows();
  bool check_columns();
  bool check_boxes();

 protected:
  using Table_t = std::vector<std::vector<Number>>;
  Table_t m_table;
  Table_t m_allowed_change;
};
}  // namespace sudoku
#endif  // _SUDOKU_TABLE_H_