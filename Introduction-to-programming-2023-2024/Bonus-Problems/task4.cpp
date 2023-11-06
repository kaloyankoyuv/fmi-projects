#include <iostream>

int generateRandomNumber() {

  srand(time(0));

  return 1000 + rand() % 9000;
}

bool isValid(int number) {

  while (number > 0) {
    if (number % 10 == 0) {
      return false;
    }

    number /= 10;
  }

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

  while (guess > 0) {

    while (secretNumber > 0) {
      if (guess % 10 == secretNumber % 10) {
	counter++;
      }
      secretNumber /= 10;
    }

    guess /= 10;
  }

  return counter;
  
}

void runGame(int secretNumber, int N) {

  int guess;
  while (N--) {

    std::cout << "Make a guess: " << std::endl;
    std::cin >> guess;

    if (guess == secretNumber) {
      std::cout << "You win!" << std::endl;
      return;
    } else {
      int bulls = countBulls(secretNumber, guess);
      int cows = countCows(secretNumber, guess);
      std::cout << bulls << " Bulls" << " & " << cows << " Cows" << std::endl;
    }
  }

  std::cout << "You lost!" << std::endl;
}

int main() {

  int secretNumber = generateSecretNumber();
  int N = 10;

  std::cout << secretNumber << std::endl;

  runGame(secretNumber, N);

  return 0;
}
