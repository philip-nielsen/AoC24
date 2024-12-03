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
  int distance, direction, oldDirection = 0, result1 = 0, result2 = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < b[i]->size - 1; j++) {
      distance = b[i]->list[j + 1] - b[i]->list[j];
      if (distance == 0 || abs(distance) > 3) {
        break;
      }
      direction = (distance > 0) ? 1 : 0;
      if (j > 0) {
        if (direction != oldDirection) {
          break;
        }

        if (j == b[i]->size - 2) {
          result1++;
        }
      }
      oldDirection = direction;
    }
  }

  //part 2
  int ignoreIndex;
  for (i = 0; i < n; i++) {
    for (ignoreIndex = -1; ignoreIndex < b[i]->size; ignoreIndex++) {
      for (j = 0; j < b[i]->size - 1; j++) {
        if (ignoreIndex == b[i]->size - 1 && j == b[i]->size - 2) { //If it ignorers the last level and has come to the last
          result2++;
          goto correct;
        } else if (j == ignoreIndex - 1) { //Ignores one level in the "middle"
          distance = b[i]->list[j + 2] - b[i]->list[j];
        } else if (ignoreIndex == 0 && j == 0) { //Ignores the first level
          distance = b[i]->list[j + 2] - b[i]->list[j + 1];
        } else if (j == ignoreIndex) { //Do nothing, if you are on the ignored level
          // do nothing
        } else {
          distance = b[i]->list[j + 1] - b[i]->list[j]; //The normal way
        }
        if (distance == 0 || abs(distance) > 3) {
          break;
        }
        direction = (distance > 0) ? 1 : 0;
        if (j > 0) {
          if (direction != oldDirection) {
            break;
          }
          if (j == b[i]->size - 2) {
            result2++;
            goto correct;
          }
        }
        oldDirection = direction;
      }
    }
  correct:;
  }

  printf("result1 = %d and result2 = %d\n", result1, result2);
}