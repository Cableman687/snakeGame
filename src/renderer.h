#ifndef RENDERER_H
#define RENDERER_H

#include <memory>
#include <vector>
#include <mutex>
#include <future>
#include <thread>

#include "SDL.h"
#include "snake.h"
#include "food.h"

using namespace std;

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(Snake const snake, shared_ptr<Food> const &food, shared_ptr<Acid> const &acid);
  void UpdateWindowTitle(int score, int fps);
  void RenderFood(shared_ptr<Food> const &food, SDL_Rect &block);
  void RenderAcid(shared_ptr<Acid> const &acid, SDL_Rect &block);

  void RenderSnake(Snake const snake, SDL_Rect &block);
  

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;
  mutex _mutex;
  

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif