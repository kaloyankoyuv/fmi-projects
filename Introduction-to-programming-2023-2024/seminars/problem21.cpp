#include <iostream>

bool myStrCmp(char *s1, char *s2) {

  int i = 0;
  while (s1[i] != 0 && s2[i] != 0) {
    if (s1[i] != s2[i]) {
      return false;
    }
    i++;
  }
  return true;
}

int nameCourseMark(char *name, char *course, int N, int M, int **grades,
                   char **names, char **courses) {
  int studentIndex = 0;
  while (!(myStrCmp(name, names[studentIndex]))) {
    studentIndex++;
  }

  int courseIndex = 0;
  while (!(myStrCmp(course, courses[courseIndex]))) {
    courseIndex++;
  }

  return grades[studentIndex][courseIndex];
}

int allAvg(int N, int M, int **grades) {

  int sum = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      sum += grades[i][j];
    }
  }

  return sum / (N * M);
}

int studentAvg(char *name, int N, int M, int **grades, char **names) {
  int studentIndex = 0;
  while (!(myStrCmp(name, names[studentIndex]))) {
    studentIndex++;
  }

  int sum = 0;
  for (int i = 0; i < M; i++) {
    sum += grades[studentIndex][i];
  }

  return sum / M;
}

int courseAvg(char *course, int N, int M, int **grades, char **courses) {
  int courseIndex = 0;
  while (!(myStrCmp(course, courses[courseIndex]))) {
    courseIndex++;
  }

  int sum = 0;
  for (int i = 0; i < N; i++) {
    sum += grades[i][courseIndex];
  }

  return sum / N;
}

int main() {

  int N, M;
  std::cout << "Number of students: ";
  std::cin >> N;
  std::cout << "Number of courses: ";
  std::cin >> M;

  char **names = new char *[N];
  for (int i = 0; i < N; i++) {
    names[i] = new char[20];
  }

  std::cout << "Enter names of students" << std::endl;
  for (int i = 0; i < N; i++) {
    std::cin >> names[i];
  }

  char **courses = new char *[M];
  for (int i = 0; i < M; i++) {
    courses[i] = new char[20];
  }

  std::cout << "Enter names of courses" << std::endl;
  for (int i = 0; i < M; i++) {
    std::cin >> courses[i];
  }

  int **grades = new int *[N];
  for (int i = 0; i < N; i++) {
    grades[i] = new int[M];
  }

  std::cout << "Enter grades" << std::endl;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      std::cin >> grades[i][j];
    }
  }

  std::cout << "Enter name (or all): ";
  char *name = new char[20];
  std::cin >> name;

  std::cout << "Enter course (or all): ";
  char *course = new char[20];
  std::cin >> course;

  std::cout << studentAvg(name, N, M, grades, names) << std::endl;
  std::cout << courseAvg(course, N, M, grades, courses) << std::endl;
  std::cout << allAvg(N, M, grades) << std::endl;
  std::cout << nameCourseMark(name, course, N, M, grades, names, courses)
            << std::endl;

  return 0;
}
