#ifndef GAME_H
#define GAME_H

#include <random>
#include <condition_variable>
#include <memory>
#include <thread>

#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "food.h"

using namespace std;


class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

 private:
  Snake snake;
  //Change
  shared_ptr<Food> food;
  shared_ptr<Acid> acid;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;
  //Change
  std::uniform_int_distribution<int> random_type;

  int score{0};
  std::condition_variable vCond;
  std::mutex mtx;

  void PlaceFood();
  void PlaceAcid();
  void Update();
};

#endif