#include <stdlib.h>
#include <stdio.h>

typedef struct stack {
  int value;
  struct stack * next;
} stack;

void push(stack **top, int value)
{
  stack * new = (stack *) malloc(sizeof(stack));
  if ( !new ) {
    fprintf(stderr, "Out of memory!\n");
    exit(0);
  }
  new->value = value;
  new->next = *top;
  *top = new;
}

stack *pop(stack **top)
{
  if ( !*top ) {
    fprintf(stderr, "Cannot pop NULL\n");
    exit(0);
  } else {
    //printf("pop: %d at %p\n", (*top)->value, *top);
    stack *y = *top;
    *top = y->next;
    /*if ( *top )
      //printf("new top: %d at %p\n", (*top)->value, *top);
    else
      //printf("stack empty\n");
    */
    return y;
  }
}

void process_line(char * line, stack **top)
{
  int pos = 0;
  int val = 0;
  int isNegative = 0;
  char c = line[0];
  while (c != '\0' && c != '\n')
  {
    c = line[pos];
    if (c == '-') {
      // save the sign
      isNegative = 1;
    } else if (c == ' ' || c == '\n' || c == '\0') { 
      // push the value
      if (isNegative)
        val *= -1;
      push(top, val);
      isNegative = 0;
      val = 0;
    } else if (c >= '0' && c <= '9') {
      // build the value
      val *= 10;
      val += atoi(&c);
    } else {
      continue;
    }
    pos++;
  }
}

int main(int argc, char** argv)
{
  char line[1024];
  FILE * fd = fopen(argv[1], "r");

  stack *top = NULL;
  stack *out = NULL;
  int i;
  //printf("top at %p, out at %p\n", top, out);
  
  while (fgets(line, sizeof(line), fd))
  {
    /* Skip empty lines */
    if (line[0] == '\n')
      continue;
    process_line(line, &top);
    //printf("stack top is %d at %p (address of pointer %p)\n", top->value, top, &top);
    i = 1;
    while ( top ) {
      // handle popped element
      out = pop(&top);
      if ( out ) {
        // print only elements from the stack in even
        if ( i % 2 != 0)
          printf("%d ", out->value);
        //printf("freeing out %d at %p\n", out->value, out);
        free(out);
        i++;
      }
    }
    printf("\n");
  }
  
  fclose(fd);

  return 0;
}
