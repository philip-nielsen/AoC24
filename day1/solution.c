#include "mergesort.c"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int tmp, index, result1, result2;
  int rightList[1000];
  int leftList[1000];

  for (int i = 0; i < 2000; i++) {
    scanf("%d", &tmp);
    if (i % 2 == 0) {
      index = i / 2;
      leftList[i / 2] = tmp;
    } else {
      rightList[index] = tmp;
    }
  }

  int n = 1000;

  mergeSort(rightList, 0, n - 1);
  mergeSort(leftList, 0, n - 1);

  // task 1
  for (int i = 0; i < n; i++) {
    result1 += abs(leftList[i] - rightList[i]);
  }

  // task 2
  int number;
  int count = 0;
  for (int i = 0; i < n; i++) {
    number = leftList[i];
    for (int j = 0; j < n; j++) {
      if (number < rightList[j]) {
        break;
      } else if (number == rightList[j]) {
        count++;
      }
    }
    result2 += count * number;
    count = 0;
  }

  printf("result1 = %d\n and result2 = %d\n", result1, result2);
}