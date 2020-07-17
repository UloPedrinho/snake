#include "debug.hpp"

void debug_printBoard(std::vector<std::vector<Cell>> board, int w, int h){
  std::cout << "w: " << w << " h: " << h << "\n";

  for(int y = 0; y < h ; y++ ){
    for(int x = 0; x < w; x++ )
      if(board[x][y] == Cell::Empty)
        std::cout << "  ";
    else 
      std::cout << static_cast<std::underlying_type<Cell>::type>(board[x][y]) << " ";
    std::cout << "\n";
  }
}
