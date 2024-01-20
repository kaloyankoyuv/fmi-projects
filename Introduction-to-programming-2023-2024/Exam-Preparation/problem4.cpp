#include <iostream>

int myStrLen(char *str) {
  int result = 0;

  while (str[result] != 0) {
    result++;
  }
  return result;
}

char *longestSubString(char *str) {

  int start = 0;
  int end = 1;

  int max = 1;
  for(int i = 0; i<myStrLen(str); i++) {

    int count = 1;
    for(int j = i+1; j<myStrLen(str); j++) {

      bool isHere = false;
      for(int k = i; k<j; k++) {
	if(str[j] == str[k]) {
	  isHere = true;
	  break;
	}
      }
      if(isHere) {
	break;
      } else {
	count++;
      }
    }
    if (count>max) {
      max = count;
      start = i;
      end = i+count;
    }
    
  }

  char *result = new char[max];
  int k = 0;
  for(int i = start; i<end; i++) {
    result[k] = str[i];
    k++;
  }
  
  return result;

}

int main() {

  int n;
  std::cin >> n;
  char *str = new char[n];

  std::cin >> str;

  char *result = longestSubString(str);
  std::cout << result;

  delete[] str;
  delete[] result;

  return 0;
}
