#include "Minimax.h"
#include "Moitie.h"
#include <fstream>
#include <iostream>
#include <bitset>

using namespace std;

enum class WhoWin : char { Player1, Player2, Tie };
/*
bool theoryCorrect(const Moitie &game, WhoWin &who) {
  // deconstruct into powers of two
  int n1 = int exp1;
  for ()
    int exp2;s
}
*/

void writeDataToCSV() {
  ofstream csvData;
  csvData.open("data.csv");
  // repeat for different data
  for (unsigned x = 0; x < 3000; x += 2) {
    for (unsigned y = 0; y <= x; y += 2) {
      Moitie game(x, y);
      auto move = bestMove(game);
      csvData << x << "&" << y << "(" << move.first << "&" << move.second
              << "),";
    }
    csvData << endl;
  }
  csvData.close();
}

void findLoose(unsigned num1) {
  for (unsigned num2 = 1500; num2 < 2500; num2 += 2) {
    Moitie game(num1, num2);
    auto move = bestMove(game);
    if (move.first < 0 && move.second < 0) {
      cout << num2 << "\n";
    }
  }
}

int main() {
  
  // std::cout << "Hello World!\n";
  int first;
  int second;
  cout << "First number:\n>";
  cin >> first;
  cout << "Second number:\n>";
  cin >> second;
  Moitie game(first, second);
  while (!game.IsFinalState()) {
    auto move = bestMove(game);

    cout << "T" << game.mTurnsCount << "\tP" << !game.IsPlayerOne() + 1 << ": "
         << game.FirstNumber() << " " << game.SecondNumber() << "\t("
         << move.first << " " << move.second << ")   ";
    
    cout << "\tBinary: " << bitset<16>(game.FirstNumber()) << " " << bitset<16>(game.SecondNumber()) << endl;
    
    if (move.first == 0 && move.second == 0) {
      cout << "TIE\n";
      return 0;
    }

    game.ApplyMove((game.IsPlayerOne()) ? move.first > move.second
                                        : move.first < move.second);
  }
  cout << game.FirstNumber() << ", " << game.SecondNumber() << endl;
  cout << "PLAYER " << game.IsPlayerOne() + 1 << " WINS!\n";
  cout << endl;

  /*
  cout << "Started" << endl;
  //   writeDataToCSV();
        //   findLoose(2304);
  cout << "Finished" << endl;
*/
}