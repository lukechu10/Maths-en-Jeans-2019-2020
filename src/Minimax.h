#pragma once

#include <iostream>
#include <algorithm>
#include "Moitie.h"

constexpr int MAX_WIN = +200;
constexpr int MIN_WIN = -200;

int iterationCount = 0;

int minimax(Moitie& game) {
  using namespace std;
  iterationCount++;

  Moitie initial = game;
  int first;
  int second;
  // check for win
  if(game.IsFinalState()) {
    // check for tie
    // cout << game.mTurnsCount << endl;
    if((game.FirstNumber() % 2) == 0 && (game.SecondNumber() % 2) == 0) {
      // cout << "TIE" << endl;
      return 0;

      }
    // player 1 looses
    else if(game.IsPlayerOne()){
      // cout << "LOSE: " << game.FirstNumber() << ", " << game.SecondNumber() << endl;
      return MIN_WIN;
    }
    // player 2 looses
    else {
      // cout << "WIN: " << game.FirstNumber() << ", " << game.SecondNumber() << endl;
      return MAX_WIN;
      }
  }
  
  // try first node
  game.ApplyMove(true);
  first = minimax(game);

  // try second node
  game = initial;
  game.ApplyMove(false);
  second = minimax(game);

  game = initial;

  
  // get return result with depth
  if(game.IsPlayerOne()) {
    if(max(first, second) > 0) {
      return max(first, second) - 1;
    }
    else return max(first, second);
  }
  // player 2
  else {
    if(min(first, second) < 0){
      return min(first, second) + 1;
    }
    else return min(first, second);
  }
}

std::pair<int, int> bestMove(Moitie& game) {
  using namespace std;
  iterationCount = 0;
  Moitie initial = game;
  int first;
  int second;

  // try first node
  game.ApplyMove(true);
  first = minimax(game);
  
  // try second node
  game = initial;
  game.ApplyMove(false);
  second = minimax(game);

  game = initial;
  // cout << iterationCount << " ";
  return pair<int, int>(first, second);
}