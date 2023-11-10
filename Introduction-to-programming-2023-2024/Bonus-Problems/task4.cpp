#include <iostream>

int generateRandomNumber() {

  srand(time(0));

  return 1000 + rand() % 9000;
}

bool isValid(int number) {

  int saveNumber = number;
  int counter = 0;
  while (number > 0) {
    counter++;
    number /= 10;
  }

  if (counter != 4)
    return false;

  int d1 = (saveNumber / 1000) % 10;
  int d2 = (saveNumber / 100) % 10;
  int d3 = (saveNumber / 10) % 10;
  int d4 = (saveNumber / 1) % 10;

  if (d1 == 0 || d2 == 0 || d3 == 0 || d4 == 0)
    return false;

  if (d1 == d2 || d1 == d3 || d1 == d4)
    return false;

  if (d2 == d1 || d2 == d3 || d2 == d4)
    return false;

  if (d3 == d1 || d3 == d2 || d3 == d4)
    return false;

  if (d4 == d1 || d4 == d2 || d4 == d3)
    return false;

  return true;
}

int generateSecretNumber() {

  int secretNumber = generateRandomNumber();

  while (!(isValid(secretNumber))) {
    secretNumber = generateRandomNumber();
  }

  return secretNumber;
}

int countBulls(int secretNumber, int guess) {

  int counter = 0;
  while (secretNumber > 0 && guess > 0) {
    if (secretNumber % 10 == guess % 10) {
      counter++;
    }
    secretNumber /= 10;
    guess /= 10;
  }
  return counter;
}

int countCows(int secretNumber, int guess) {

  int counter = 0;

  int g1 = guess / 1000 % 10;
  int g2 = guess / 100 % 10;
  int g3 = guess / 10 % 10;
  int g4 = guess / 1 % 10;

  int s1 = secretNumber / 1000 % 10;
  int s2 = secretNumber / 100 % 10;
  int s3 = secretNumber / 10 % 10;
  int s4 = secretNumber / 1 % 10;

  if (g1 == s2 || g1 == s3 || g1 == s4)
    counter++;
  if (g2 == s1 || g2 == s3 || g2 == s4)
    counter++;
  if (g3 == s1 || g3 == s2 || g3 == s4)
    counter++;
  if (g4 == s1 || g4 == s2 || g4 == s3)
    counter++;

  return counter;
}

void runGame(int secretNumber, int N) {

  int guess;
  while (N--) {

    if (N + 1 > 1) {
      std::cout << "You have " << N + 1 << " guesses!" << std::endl;
    } else {
      std::cout << "You have " << N + 1 << " guess!" << std::endl;
    }

    std::cout << "Make a guess: ";
    std::cin >> guess;

    if (isValid(guess)) {

      if (guess == secretNumber) {
        std::cout << std::endl << "You win!" << std::endl;
        return;
      } else {
        int bulls = countBulls(secretNumber, guess);
        int cows = countCows(secretNumber, guess);
        std::cout << std::endl
                  << bulls << " Bulls"
                  << " & " << cows << " Cows" << std::endl;
      }
    } else {
      std::cout << "Please enter a valid number!" << std::endl;
      N++;
    }
    std::cout << std::endl;
  }

  std::cout << std::endl << "You lost!" << std::endl;
  std::cout << "The secret number was: " << secretNumber << std::endl;
}

int main() {

  int secretNumber = generateSecretNumber();
  int N;

  std::cout << "How many tries do you want? ";
  std::cin >> N;
  std::cout << std::endl;

  runGame(secretNumber, N);

  return 0;
}
