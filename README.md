# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## Rubric Criteria Satisfaction

Compiling & Testing:
- The Project code must compile & run without errors,
- Use of 'cmake' and 'make'.

1) Loops, Functions, I/O
- Addition of User input capabilities to retrieve the name of the User, 
- Addition of 'data.txt' text file to store user scores and names, as well as returning the highscore card on application close,
- addition of enum classes to hold various food and acid states in the food.h headerfile,
- addition of conditional statements to control points and snake length upon food/acid consumption.

2) Object Oriented Programming
- Addition of 'food' and 'acid' classes to control the characteristics of each food type.

3) Memory Management
- Several variables defined as references,
- All food and acid variables are  now controlled by shared pointers to manage class objects from the traditional raw pointers used in the original game version,
- destructors used appropriately where constructors are utilised.

4) Concurrency
- Mutexes & lock_guards used to control thread access between functions,
- Condition variables used in conjuction with lock_guards to synchronise thread execution.

## Features

1) For each food item that is generated, so is a 'poison' item. Each time these are generated, there is a small chance for each item to be provide +2 points, or -2 points. These can be seen as a different color from the normal food.
2) The application requests the users name on startup. This will then be used to generate a scoresheet where the user can see their own performance, as well as the performance of any competitors of the same machine.
 


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
