#include "game.hpp"

Game::Game(){
  int window_w = 400;           // FIXME
  int window_h = 400;           // FIXME

  sf::Vector2f view_origin(0.01f, 0.01f);
  sf::Vector2f boardView_size(window_w*0.75f, window_h*0.99f);
  sf::Vector2f infoView_size(window_w/4, window_h);
  int board_width;
  int board_height;

  // cell dimension alaways a square and fixed
  cell_dimension = sf::Vector2f(8.f, 8.f);

  // init board
  board_width = boardView_size.x /cell_dimension.x;
  board_height = boardView_size.y /cell_dimension.y;
  initBoard(board, board_width, board_height, Cell::Empty);

  // init snake
  initSnake(snake, 3, 10, Direction::North, {10,10});

  // create window
  window.create(sf::VideoMode(window_w,window_h), "snake", sf::Style::Resize); // FIXME: video mode and title ;;
  window.setFramerateLimit(10); // FIXME:  https://www.sfml-dev.org/tutorials/2.5/window-window.ph

  // create views
  boardView_dimensions = sf::FloatRect(view_origin, boardView_size);
  infoView_dimensions = sf::FloatRect(view_origin,infoView_size);
  boardView.reset(boardView_dimensions);
  infoView.reset(infoView_dimensions);
  boardView.setViewport(sf::FloatRect(0.01f, 0.01f, 0.75f, 0.99f));
  infoView.setViewport(sf::FloatRect(0.75f, 0.f, 0.25f, 1.f));

  //boardView.zoom(1.1f);

  // cells positions
  cells_position.setPrimitiveType(sf::Points);
  for (int i = 0; i < board.height; ++i) {
    for (int j = 0; j < board.width; ++j) {
      cells_position.append(sf::Vertex(sf::Vector2f(cell_dimension.x*j,cell_dimension.y*i)));
    }
  }

  // wall
  wall_points = generateWall(board.width, board.height);
  putElementsInBoard(board, wall_points, Cell::Wall);

}

void Game::run(){
  while(window.isOpen()){
    events();
    update();
    render();
    draw();
    window.display();
  }
}

void Game::events() {
  sf::Event event;
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed)
      window.close();
    if (event.type == sf::Event::KeyPressed) {
      switch (event.key.code) {
      case sf::Keyboard::Left: {
        if (snake.direction != Direction::East)
          turnSnake(snake, Direction::West);
        break;
      }
      case sf::Keyboard::Right: {
        if (snake.direction != Direction::West)
          turnSnake(snake, Direction::East);
        break;
      }
      case sf::Keyboard::Up: {
        if (snake.direction != Direction::South)
          turnSnake(snake, Direction::North);
        break;
      }
      case sf::Keyboard::Down: {
        if (snake.direction != Direction::North)
          turnSnake(snake, Direction::South);
        break;
      }
      // // debug
      case sf::Keyboard::G: {
        growSnake(snake, 1);
        break;
      }
      case sf::Keyboard::S: {
        snake.to_split = true;
        break;
      }

      default:
        break;
      }
    }
  }
}

void Game::update(){

  moveSnake(snake);             // FIXME ?

  // collisions
  if (collision(board, snake.head)){
    std::cout << "collision" << "\n"; // TODO:
  }

  // split snake
  if(snake.to_split){
    putElementsInBoard(board, splitSnake(snake), Cell::Wall);
    snake.to_split = false;
  }

  // wall
  generateCellsPosition(wall_origins, cells_position, getElementsFromBoard(board, Cell::Wall), {board.width,board.height});
  // snake
  generateCellsPosition(snake_body_origins, cells_position, snake.body, {board.width,board.height});
  snake_head_origin = cells_position[snake.head.x + snake.head.y*board.width];
}


void Game::render(){
  // FIXME: move to a function. use a grid background ?
  grid.clear();
  for (int i = 0; i < cells_position.getVertexCount(); ++i) {
    // cell_pos = points[i].y +
    //            points[i].x *
    //                board_size.x; // FIXME reversed cordinates, snake
    //                class...etc

    cell.setSize(cell_dimension);
    cell.setPosition(cells_position[i].position);

    // cell.setSize(sf::Vector2f(cell_size, cell_size)); // FIXME
    // cell.setPosition(origins[cell_pos].position);

    if (i % 2 == 0)
      cell.setFillColor(sf::Color::Black);
    else
      cell.setFillColor(sf::Color::Blue);

    grid.push_back(cell);
  }

  // render wall
  renderElements(wall, wall_origins, cell_dimension, sf::Color::Magenta);

  // render snake
  renderElement(snake_head_shape, snake_head_origin.position, cell_dimension, sf::Color::Green);
  renderElements(snake_body_shape, snake_body_origins, cell_dimension, sf::Color::Yellow);

}

void Game::draw(){
  window.clear(sf::Color::White);

  window.setView(boardView);
  for (int i = 0; i < grid.size(); ++i)
    window.draw(grid[i]);
  for (int i = 0; i < wall.size(); ++i)
    window.draw(wall[i]);

  // snake
  window.draw(snake_head_shape);
  for (int i = 0; i < snake_body_shape.size(); ++i)
    window.draw(snake_body_shape[i]);
}
