#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>

#include "controller.h"
#include "game.h"
#include "renderer.h"
using namespace std;

//Store scores in vector
vector<string> high_scores;

//print highscores to console
void printScores(){
  for(auto &in: high_scores){
    cout << in << endl;
  }
}

//read from data.txt
void read_Data(){
  cout << "Highscores: " << endl;
  fstream scores; // Create object
  scores.open("data.txt", ios::in); //read in data
  if(scores.is_open()){
    string line;
    while(getline(scores, line)){
      high_scores.emplace_back(line); // add scores to high_scores vector
    }
  scores.close();  
  }
printScores();
}

string name;

//write to data.txt to append scores
void result (string score){
  fstream result;
  result.open("data.txt", ios::app);
  if(result.is_open()){
    string playerProfile = name + ": " + score;
    result << playerProfile;
    result.close();
  }
}



int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  std::cout << "Please enter your name: ";
  std::cin >> name;

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);

  //retrieve previous scores
  read_Data();

  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully! " << name << ", your performance: " << std::endl;
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";

  //Save the score
  string score = to_string(game.GetScore());
  score += "\n";

  result(score);
  

  return 0;
}