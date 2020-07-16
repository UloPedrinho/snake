#include "debug.hpp"

void debug_printBoard(std::vector<std::vector<Cell>> board){
  for(int y = 0; y < board.size(); y++ ){
    for(int x = 0; x < board[0].size(); x++ )
      std::cout << static_cast<std::underlying_type<Cell>::type>(board[x][y]);
    std::cout << "\n";
  }
}
