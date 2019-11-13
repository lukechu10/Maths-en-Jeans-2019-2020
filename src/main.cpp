#include "Minimax.h"
#include "Moitie.h"
#include <iostream>

using namespace std;

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
    cout << "P " << !game.IsPlayerOne() + 1 << ": " << game.FirstNumber() << " "
         << game.SecondNumber() << " (" << move.first << " " << move.second
         << ")" << endl;
    if (move.first == 0 && move.second == 0) {
      cout << "TIE";
      return 0;
    }

    game.ApplyMove((game.IsPlayerOne()) ? move.first > move.second
                                        : move.first < move.second);
  }
  cout << game.FirstNumber() << ", " << game.SecondNumber() << endl;
  cout << "PLAYER " << game.IsPlayerOne() + 1 << " WINS!";
}