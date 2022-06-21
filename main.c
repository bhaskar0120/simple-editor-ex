#include <stdio.h>
#include <stdlib.h>

const char ESC = '\x1b';

int min(int a, int b){ return a<b?a:b; } 
int max(int a, int b){ return a>b?a:b; } 

// Simple terminal colors
typedef enum {
  BLACK,
  RED,
  GREEN,
  YELLOW,
  BLUE,
  MAGENTA,
  CYAN,
  WHITE,
  BR_BLACK,
  BR_RED,
  BR_GREEN,
  BR_YELLOW,
  BR_BLUE,
  BR_MAGENTA,
  BR_CYAN,
  BR_WHITE,
} Color;

// Function to change color using ansi escape codes
void colorFG(Color col){
  printf("%c[%dm",ESC,(int)col+30);
}

void colorBG(Color col){
  printf("%c[%dm",ESC,(int)col+40);
}

// Revert to original terminal
void revert(){
  printf("%c[0m",ESC);
}

typedef struct{
  char val;
  node* next;
} node;

int main(int argc, char** argv){
  if(argc < 3){
    printf("USAGE: ex <rows> <colums> <filename>\n");
    exit(1);
  }

  const int rows = atoi(argv[1]);
  const int cols = atoi(argv[2]);


  FILE *f = fopen(argv[3], "r");
  fseek(f,0L,SEEK_END);
  const size_t size = ftell(f);
  printf("Size: %d\n", size);
  rewind(f);
  fclose(f);

  colorBG(WHITE);
  colorFG(RED);
  printf("Hello world");
  revert();
  return 0;
}
