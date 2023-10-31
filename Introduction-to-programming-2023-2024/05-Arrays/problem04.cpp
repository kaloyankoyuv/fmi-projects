#include <iostream>

int main() {

  int arr[255];
  int n;
  std::cin >> n;

  for(int i=0; i<n; i++) {
    std::cin >> arr[i];
  }

  int max=arr[0];
  int min=arr[0];
  for(int i=1; i<n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
    if (arr[i] < min) {
      min = arr[i];
    }
  }

  std::cout << max << std::endl;
  std::cout << min << std::endl;
  
  
  return 0;
}
