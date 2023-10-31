#include <iostream>

int main() {

  int arr[1024];
  int n;
  std::cin >> n;

  for(int i=0; i<n; i++) {
    std::cin >> arr[i];
  }

  int even=0;
  for(int i=0; i<n; i++) {
    if(arr[i]%2==0) {
      even++;
    }
  }

  std::cout << even << std::endl;
  
  return 0;
}
