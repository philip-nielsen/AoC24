#include "mergesort.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list_t {
  int size;
  int list[10];
};

typedef struct list_t list_t;

int main() {
  int n = 1000;
  list_t *b[n];

  for (int i = 0; i < n; i++) {
    b[i] = malloc(sizeof(list_t));
    b[i]->size = 0;
  }

  int input, i = 0, j = 0;
  char line[1024];

  while (fgets(line, sizeof(line), stdin) != NULL) {
    char *token = strtok(line, " ");
    while (token != NULL) {
      input = atoi(token);
      if (b[j]->size < 1000) {
        b[j]->list[b[j]->size++] = input;
      }
      token = strtok(NULL, " ");
    }
    j++;
  }

  // part 1
  int distance, directon, oldDirection = 0, result = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < b[i]->size - 1; j++) {
      distance = b[i]->list[j + 1] - b[i]->list[j];
      if (distance == 0 || abs(distance) > 3) {
        break;
      }
      if (distance < 0)
        directon = 1;
      else
        directon = 0;
      if (j > 0) {
        if (directon != oldDirection) {
          break;
        }

        if (j == b[i]->size - 2) {
          result++;
        }
      }
      oldDirection = directon;
    }
  }

  // for (i = 0; i < n; i++) {
  //   for (j = 0; j < b[i]->size; j++) {
  //     printf("%d ", b[i]->list[j]);
  //   }
  //   printf("\n");
  // }

  printf("result = %d\n", result);
}