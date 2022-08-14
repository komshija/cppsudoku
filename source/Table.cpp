#include <Table.hpp>
#include <algorithm>
#include <set>

#define WIDTH 9
#define HEIGHT 9
#define TABLE_STRING_LENGTH WIDTH* HEIGHT

namespace sudoku {

namespace utils {

Number from_char(char str) {
  switch (str) {
    case '0':
      return Number::EMPTY;
    case '1':
      return Number::ONE;
    case '2':
      return Number::TWO;
    case '3':
      return Number::THREE;
    case '4':
      return Number::FOUR;
    case '5':
      return Number::FIVE;
    case '6':
      return Number::SIX;
    case '7':
      return Number::SEVEN;
    case '8':
      return Number::EIGHT;
    case '9':
      return Number::NINE;
    default:
      return Number::EMPTY;
  }
}

std::string to_string(Number num) {
  switch (num) {
    case Number::EMPTY:
      return "0";
    case Number::ONE:
      return "1";
    case Number::TWO:
      return "2";
    case Number::THREE:
      return "3";
    case Number::FOUR:
      return "4";
    case Number::FIVE:
      return "5";
    case Number::SIX:
      return "6";
    case Number::SEVEN:
      return "7";
    case Number::EIGHT:
      return "8";
    case Number::NINE:
      return "9";
    default:
      return "";
  }
}

}  // namespace utils

Table::Table(std::string const& table) {
  if (table.empty()) {
    throw std::runtime_error("table string is empty");
  }

  if (table.length() != TABLE_STRING_LENGTH) {
    throw std::runtime_error("table string not size");
  }

  m_table.resize(9);
  m_allowed_change.resize(9);

  for (auto i{0}; i < HEIGHT; ++i) {
    std::string row{table.substr(i * WIDTH, WIDTH)};
    for (auto& c : row) {
      auto val = utils::from_char(c);
      m_table[i].push_back(val);
      m_allowed_change[i].push_back(val == Number::EMPTY ? Number::EMPTY
                                                         : Number::ONE);
    }
  }
}

void Table::get_value(const size_t row_i, const size_t col_i,
                      Number& number) const {
  if (row_i >= 9 && col_i >= 9) {
    throw std::runtime_error("index out of range");
  }
  number = m_table[row_i][col_i];
}

Number Table::set_value(const size_t row_i, const size_t col_i,
                        Number const& number) {
  if (row_i >= 9 && col_i >= 9) {
    throw std::runtime_error("index out of range");
  }
  if (m_allowed_change[row_i][col_i] == Number::ONE) {
    throw std::runtime_error("can't change that value");
  }
  Number result = m_table[row_i][col_i];
  m_table[row_i][col_i] = number;
  return result;
}

void Table::print() {
  int vertical_separator_counter{0};
  for (auto const& row : m_table) {
    int horizontal_separator_counter{0};
    for (auto const& val : row) {
      if (horizontal_separator_counter % 3 == 0) {
        std::cout << "|";
      }
      std::cout << utils::to_string(val) << " ";
      ++horizontal_separator_counter;
    }
    std::cout << "|" << std::endl;
    ++vertical_separator_counter;
    if (vertical_separator_counter % 3 == 0) {
      std::cout << std::string(horizontal_separator_counter * 2 + 4, '_')
                << std::endl;
    }
  }
}

bool Table::is_valid() {
  return check_rows() && check_columns() && check_boxes();
}

bool Table::is_finished() {
  bool empty_found = false;
  for (auto const& row : m_table) {
    for (auto const& val : row) {
      empty_found = val == Number::EMPTY;
      if (empty_found) break;
    }
    if (empty_found) break;
  }
  return !empty_found & is_valid();
}

bool Table::check_rows() {
  bool result{true};
  for (auto const& row : m_table) {
    std::set<Number> tracker;
    for (auto const& val : row) {
      if (val == Number::EMPTY) continue;
      if (tracker.find(val) != tracker.end()) {
        result = false;
        break;
      }
      tracker.emplace(val);
    }
    if (!result) break;
  }
  return result;
}

bool Table::check_columns() {
  bool result{true};
  for (auto i{0}; i < WIDTH; ++i) {
    std::set<Number> tracker;
    for (auto j{0}; j < HEIGHT; ++j) {
      auto val{m_table[j][i]};
      if (val == Number::EMPTY) continue;
      if (tracker.find(val) != tracker.end()) {
        result = false;
        break;
      }
      tracker.emplace(val);
    }
    if (!result) break;
  }
  return result;
}

bool Table::check_boxes() {
  bool result{true};
  for (auto ri{0}; ri < HEIGHT / 3; ++ri) {
    for (auto ci{0}; ci < WIDTH / 3; ++ci) {
      std::set<Number> tracker;
      auto row_index = ri * 3;
      auto column_index = ci * 3;
      for (auto i{0}; i < 3; ++i) {
        for (auto j{0}; j < 3; ++j) {
          auto val{m_table[row_index + i][column_index + j]};
          if (val == Number::EMPTY) continue;
          if (tracker.find(val) != tracker.end()) {
            result = false;
            break;
          }
          tracker.emplace(val);
        }
      }
    }
  }
  return result;
}

}  // namespace sudoku
