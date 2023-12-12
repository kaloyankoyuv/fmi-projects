#include <iostream>

bool isSaw(int *arr, int n) { // 5 2 6 3

  if(arr[0] < arr[1]) {

    for(int i = 2; i<n; i++) {
      if(i%2==0 && arr[i] >= arr[i-1]) {
	return false;
      }
      if(i%2!=0 && arr[i] <= arr[i-1]) {
	return false;
      }
    }
    
  } else if (arr[0] > arr[1]) {

    for(int i = 2; i<n; i++) {
      if(i%2==0 && arr[i] <= arr[i-1]) {
	return false;
      }
      if(i%2!=0 && arr[i] >= arr[i-1]) {
	return false;
      }
    }
  } else {
    return false;
  }

  return true;
  
}

int main() {

  int arr[20];
  int n;
  std::cin >> n;

  for(int i=0; i<n; i++) {
    std::cin >> arr[i];
  }

  std::cout << isSaw(arr, n);

  return 0;
}
