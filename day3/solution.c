#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int getNumber(char chars[], int i) {
  bool stillNumber = true, foundNumber = false;
  int tempstack[10]; // Stores up to 10 digits
  int size = 0;

  while (stillNumber && chars[i] != '\0') {
    switch (chars[i]) {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
      tempstack[size] = chars[i] - '0';
      i++;
      size++;
      foundNumber = true;
      break;
    default:
      stillNumber = false;
    }
  }

  if (!foundNumber) {
    return -1;
  } else {
    int number = 0;
    for (int j = 0; j < size; j++) {
      number += tempstack[j] * pow(10, size - j - 1);
    }
    return number;
  }
}

int numPlaces(int n) {
  if (n < 0)
    n = (n == INT_MIN) ? INT_MAX : -n;
  if (n < 10)
    return 1;
  if (n < 100)
    return 2;
  if (n < 1000)
    return 3;
  if (n < 10000)
    return 4;
  if (n < 100000)
    return 5;
  if (n < 1000000)
    return 6;
  if (n < 10000000)
    return 7;
  if (n < 100000000)
    return 8;
  if (n < 1000000000)
    return 9;
  return 10;
}

int main() {

  char line[102400];
  int size = 0;
  int ch;
  while ((ch = getchar()) != EOF) {
    line[size] = ch;
    size++;
  }
  line[size + 1] = '\0';

  int result1 = 0;
  int progress = 0;
  int num1 = 0, num2 = 0;

  // part 1
  for (int i = 0; i < size; ++i) {
    ch = line[i];
    if (ch == 'm' && progress == 0) {
      progress++;
    } else if (ch == 'u' && progress == 1) {
      progress++;
    } else if (ch == 'l' && progress == 2) {
      progress++;
    } else if (ch == '(' && progress == 3) {
      progress++;
    } else if (getNumber(line, i) != -1 && progress == 4) {
      num1 += getNumber(line, i);
      i += numPlaces(num1) - 1;
      progress++;
    } else if (ch == ',' && progress == 5) {
      progress++;
    } else if (getNumber(line, i) != -1 && progress == 6) {
      num2 += getNumber(line, i);
      i += numPlaces(num2) - 1;
      progress++;
    } else if (ch == ')' && progress == 7) {
      progress = 0;
      result1 += num1 * num2;
      num1 = 0, num2 = 0;
    } else {
      num1 = 0, num2 = 0;
      progress = 0;
    }
  }

  // part2
  int result2 = 0;
  bool doMul = true;
  for (int i = 0; i < size; ++i) {
    ch = line[i];
    if (ch == 'm' && progress == 0) {
      progress++;
    } else if (ch == 'u' && progress == 1) {
      progress++;
    } else if (ch == 'l' && progress == 2) {
      progress++;
    } else if (ch == '(' && progress == 3) {
      progress++;
    } else if (getNumber(line, i) != -1 && progress == 4) {
      num1 += getNumber(line, i);
      i += numPlaces(num1) - 1;
      progress++;
    } else if (ch == ',' && progress == 5) {
      progress++;
    } else if (getNumber(line, i) != -1 && progress == 6) {
      num2 += getNumber(line, i);
      i += numPlaces(num2) - 1;
      progress++;
    } else if (ch == ')' && progress == 7) {
      progress = 0;
      if (doMul) {
        result2 += num1 * num2;
      }
      num1 = 0, num2 = 0;
    } else if (ch == 'd') {
      progress = 10;
      progress++;
    } else if (ch == 'o' && progress == 11) {
      progress++;
    } else if (ch == '(' && progress == 12) {
      progress++;
    } else if (ch == ')' && progress == 13) {
      progress = 0;
      num1 = 0, num2 = 0;
      doMul = true;
    } else if (ch == 'n' && progress == 12) {
      progress++;
    } else if (ch == 39 && progress == 13) {
      progress++;
    } else if (ch == 't' && progress == 14) {
      progress++;
    } else if (ch == '(' && progress == 15) {
      progress++;
    } else if (ch == ')' && progress == 16) {
      progress = 0;
      num1 = 0, num2 = 0;
      doMul = false;
    } else {
      num1 = 0, num2 = 0;
      progress = 0;
    }
  }

  printf("result1 = %d, result2 = %d\n", result1, result2);
}