#include <iostream>
using namespace std;

int main() {

  int n;
  cin >> n;

  int arr[100];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int counter = 1;
  int max = 1;
  for (int i = 0; i < n-1; i++) {
    if (arr[i] < arr[i + 1]) {
      counter++;
    } else {
      if (counter > max) {
        max = counter;
      }
      counter = 1;
    }
  }

  if (counter > max) {
    max = counter;
  }
  
  cout << max << endl;

  return 0;
}
