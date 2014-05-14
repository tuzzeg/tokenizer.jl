#include "stdio.h"
#include "string.h"

#include "tokenizer.h"

int main(int argc, char** argv) {
  if (1 < argc) {
    char* s = argv[1];
    printf("tokenize [%s]\n", s);

    Scanner scanner;
    Token token;
    Scanner_init(&scanner, s, strlen(s));
    while (0 < next(&scanner, &token)) {
      printf("  %04x [%.*s]\n", token.type, (int)token.length, token.start);
    }
  }
}
