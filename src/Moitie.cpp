#include "Moitie.h"

using namespace std;

Moitie::Moitie(int mFirst, int mSecond) {
  if(mFirst < LOWER_BOUND || mFirst > HIGHER_BOUND ||
  mSecond < LOWER_BOUND || mSecond > HIGHER_BOUND) {
    // numbers are out of bound
    throw out_of_range("The numbers are not between the upper and lower bounds");
  }

  // numbers are correct
  this->mFirst = mFirst;
  this->mSecond = mSecond;
}

Moitie& Moitie::ApplyMove(bool isFirstNumber) {
  // see rules for game
  if(isFirstNumber && (mFirst % 2) == 0) {
    mFirst /= 2;
    mSecond += mFirst;
  }
  else if (!isFirstNumber && (mSecond % 2) == 0){
    mSecond /= 2;
    mFirst += mSecond;
  }
  // invalid input
  else {
    throw runtime_error("The chosen number is not even");
  }
  mTurnsCount++;
  // opposite turn
  mIsPlayerOne = !mIsPlayerOne;
  return *this;
}