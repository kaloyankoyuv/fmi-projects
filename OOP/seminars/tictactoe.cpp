#include <iostream>

class Player {
private:
  char name[20];
  char sign;

public:
  void set_name() { std::cin >> name; }

  void set_sign() { std::cin >> sign; }

  char *get_name() { return name; }

  char get_sign() { return sign; }
};

class TicTacToe {
private:
  char board[3][3] = {
      {' ', ' ', ' '},
      {' ', ' ', ' '},
      {' ', ' ', ' '},
  };

public:
  bool set(int x, int y, Player p) {

    if (x < 0 || x > 2 || y < 0 || y > 2) {
      std::cout << "Invalid coordinates" << std::endl;
      return false;
    }

    if (board[x][y] != ' ') {
      std::cout << "Invalid coordiantes" << std::endl;
      return false;
    }
    board[x][y] = p.get_sign();
    return true;
  }

  void view() {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (j == 0 || j == 1) {
          std::cout << ' ' << board[i][j] << ' ' << '|';
        } else {
          std::cout << ' ' << board[i][j] << ' ';
        }
      }
      if (i < 2) {
        std::cout << std::endl;
        for (int i = 0; i < 11; i++) {
          std::cout << '-';
        }
        std::cout << std::endl;
      }
    }
    std::cout << std::endl;
  }

  bool win(Player p) {

    bool w3 = true;
    bool w4 = true;

    for (int i = 0; i < 3; i++) {
      bool w1 = true;
      bool w2 = true;
      for (int j = 0; j < 3; j++) {
        if (board[i][j] != p.get_sign()) {
          w1 = false;
        }
        if (board[j][i] != p.get_sign()) {
          w2 = false;
        }
        if (i == j && board[i][j] != p.get_sign()) {
          w3 = false;
        }
        if (i + j == 2 && board[i][j] != p.get_sign()) {
          w4 = false;
        }
      }
      if (w1 || w2) {
        return true;
      }
    }

    if (w3 || w4) {
      return true;
    }

    return false;
  }
};

void run_game(TicTacToe t, Player p1, Player p2) {

  t.view();
  while (true) {
    int x, y;
    std::cin >> x >> y;
    t.set(x, y, p1);
    t.view();
    if (t.win(p1)) {
      std::cout << p1.get_name() << " wins" << std::endl;
      break;
    }
    std::cin >> x >> y;
    t.set(x, y, p2);
    t.view();
    if (t.win(p2)) {
      std::cout << p2.get_name() << " wins" << std::endl;
      break;
    }
  }
}

int main() {

  TicTacToe t;
  Player p1;
  Player p2;

  std::cout << "Set name for Player 1: ";
  p1.set_name();
  std::cout << "Set sign for Player 1: ";
  p1.set_sign();
  std::cout << "Set name for Player 2: ";
  p2.set_name();
  std::cout << "Set sign for Player 2: ";
  p2.set_sign();

  run_game(t, p1, p2);

  return 0;
}
