#include <iostream>

bool duplicates (int **pointers, int n) {
  for(int i = 0; i<n; i++) {
    for(int j = i+1; j<n; j++) {
      if(*pointers[i] == *pointers[j]) {
	return true;
      }
    }
  }

  return false;
}

int main() {

  int variables[20] = {1, 2, 2, 4};

  int *pointers[20] = {&variables[0], &variables[1],&variables[2],&variables[3]};

  std::cout << duplicates(pointers, 4);

  return 0;
}
