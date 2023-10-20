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
  int j;
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] < arr[i + 1]) {
      counter++;
    } else {
      if (counter > max) {
        max = counter;
	j = i;
      }
      counter = 1;
    }
  }

  if (counter > max) {
    max = counter;
  }

  cout << j << endl;
  cout << max << endl;
  for(int i=j-max+1; i<=j; i++) {
    cout << arr[i] << endl;
  }

  return 0;
}
