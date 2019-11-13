#pragma once

#include <bits/stdc++.h>

// See rules
constexpr int LOWER_BOUND = 0; // 1500;
// See rules
constexpr int HIGHER_BOUND = 100000000; // 2500;

class Moitie {
bool mIsPlayerOne = true;

int mFirst;
int mSecond;



public:
int mTurnsCount = 0;
// Create a game with values for first and second numbers
Moitie(int mFirst, int mSecond);
// Whose turn is it?
bool IsPlayerOne() { return mIsPlayerOne; }

// Returns if the game is finished according to rules:
// (More than 12 rounds have passed; Both numbers are odd)
bool IsFinalState() {
  return (mTurnsCount == 100) || ((mFirst % 2) == 1 || (mSecond % 2) == 1);
}

// Changes numbers according to rules
Moitie& ApplyMove(bool isFirstNumber);

// Value of first number
int FirstNumber() { return mFirst; }
// Value of second number
int SecondNumber() { return mSecond; }
};