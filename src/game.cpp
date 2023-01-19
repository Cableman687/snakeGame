#include "game.h"
#include <iostream>
#include <thread>
#include "SDL.h"
#include "food.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {

          PlaceFood();
          PlaceAcid();  
        
  
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, food, acid);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood() {
  std::lock_guard<std::mutex> lock(mtx);

  //Change
  int x, y, rand;
  foodState type;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    //Change
    rand = random_type(engine);
    //Change
    if(rand % 30 == 0){
      type = foodState::extra;
    } else if (!rand % 30 == 0) {
      type = foodState::normal;
    }
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      food = make_shared<Food>(x,y,type);
      vCond.notify_one();
      return;
    }
  }
}

void Game::PlaceAcid() {
  
  std::unique_lock<std::mutex> lock(mtx);
  vCond.wait(lock, [this] () {return (food->x != -1 && food->y != -1) ? true : false; });

  //Change
  int x, y, rand;
  acidState type;

  

  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    //Change
    rand = random_type(engine);
    //Change
    if(rand % 30 == 0){
      type = acidState::superAcid;
    } else if (!rand % 30 == 0) {
      type = acidState::acid;
    } 
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      acid = make_shared<Acid>(x,y,type);
      
      return;
    }
  }
}

void Game::Update() {
  if (!snake.alive) return;

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
  if (food->x == new_x && food->y == new_y) {
    //Change
    if(food->state == foodState::normal){
      score++;
      


    } else if (food->state == foodState::extra) {
      score++;
      score++;
      

    }
      
    
    PlaceFood();
    PlaceAcid();

    

    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02;
    
  }


  if (acid->x == new_x && acid->y == new_y) {


    if(acid->state == acidState::acid){
      score--;
      
      if(score == -1){
        snake.alive = false;
      }
    } else if (acid->state == acidState::superAcid) {
      score --;
      score --;
      
      if(score == -1){
        snake.alive = false;
      }
    }

    PlaceFood();
    PlaceAcid();

    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02;
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }