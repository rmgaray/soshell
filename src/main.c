#include "AST.h"
#include "history.h"
#include "parser.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  char *line = NULL;

  while (line = readline("sosh> ")) {
    // Si no es una linea vacia
    history_add(line);
    read_from(line);
    size_t line_len = strlen(line);
    ASTNode *root = parse();
    if (root) {
      printf("==============\n");
      print_node(root, 0);
      printf("==============\n");
      free_node(root);
    }
  }

  history_delete();
  printf("\n");
  return 0;
}