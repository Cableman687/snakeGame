#ifndef FOOD_H
#define FOOD_H

enum class foodState {
    normal,
    extra,

};

enum class acidState {
    acid,
    superAcid,
};

class Food {
public:
int x;
int y;
foodState state;

Food() : x(0), y(0), state(foodState::normal){}
Food(int x, int y, foodState type) : x(x), y(y), state(type){}
~Food(){}

private:
//No Private variables

};

class Acid {
public:
int x;
int y;
acidState state;

Acid() : x(0), y(0), state(acidState::acid){}
Acid(int x, int y, acidState type) : x(x), y(y), state(type){}
~Acid(){}

private:
//No Private variables

};

#endif