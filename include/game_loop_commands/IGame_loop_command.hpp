#ifndef _IGAME_LOOP_COMMAND_H
#define _IGAME_LOOP_COMMAND_H
#include <string>
namespace sudoku {
namespace game_loop {
class IGame_loop_command {
 public:
  virtual void get_name(std::string& name) = 0;
  virtual bool exec() = 0;
  virtual ~IGame_loop_command() = default;
};

}  // namespace game_loop
}  // namespace sudoku
#endif  // _IGAME_LOOP_COMMAND_H