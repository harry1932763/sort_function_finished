// Author: Harry Dean 
// Date: 24/11/21
// version 1.0 
// function purpose: to order an input array in ascending order (small to big). 

#include <stdio.h> /*printf(), scanf() */
#include <string.h> /*strlen()*/
#include <stdlib.h> /*malloc(), free()*/

const char * sort(char input_sentence[]);

int main(void) {

  // allocate storage for the users input sentence 
  char *user_input = malloc(200 * sizeof(char));
  // check to see if the memory was allocated properly
  if (user_input == NULL) {
    return -1;
  }
  // promput for sentence
  printf("enter your sentence\n");
  // scan the console until a '\n'(newline) is found and stores it to user_input, then %*c scans reads the character but does nothing with it
  scanf("%[^\n]%*c", user_input); 
  int length = strlen(user_input);
  // allocate storage for the result/return of the sort function
  char *sorted_result = malloc((length+1) * sizeof(char));
  // check to see if the memory was allocated properly
  if (sorted_result == NULL) {
    return -1;
  }
  // copy the result of sort(user_input) onto sorted_result, since the return of sort(user_input) is a pointer and the destination 'sorted_result' is a pointer they end up pointing to the same memory location, so by freeing sorted_result this would also free input_sentence_copy
  strcpy(sorted_result, sort(user_input));
  printf("\n%s", sorted_result);
  
  // we no long need the memory allocated so we free any memory allocated by malloc
  free(sorted_result);
  free(user_input);
  // set the pointers = to NULL so that if they were to be used later in the code we will know, this is useful as freed memory should not be reused, instead use realloc for that purpose. 
  *sorted_result = '\0';
  *user_input = '\0';
  
  return 0;
}

const char * sort(char input_sentence[]){
  int length = strlen(input_sentence);
  // temp will be used to store the result of input_sentence_cpy[i] in the for loop
  char temp;
  // allocate memory for the input_sentence to be copied. 
  char *input_sentence_cpy = malloc((length +1 ) * sizeof(char));
  // copy input_sentence to input_sentnece_cpy as we can't manipulate input_sentence but we can manipulate a copy of it. 
  strcpy(input_sentence_cpy, input_sentence);
  // swap letter indexes if the next index is smaller so 4321 -> 1234
  for (int i = 0; i < length; i++){
    for (int j = i+1; j < length; j++){
      // check to see if the current char is bigger than the next one if its bigger it gets swapped and moved to the right. 
      if (input_sentence_cpy[i] > input_sentence_cpy[j]){
          // place holder for the current letter 
          temp = input_sentence_cpy[i];
          // make the current index equal to the next index, so now the current and next index are both equal to input_sentence_cpy[]
          input_sentence_cpy[i] = input_sentence_cpy[j];
          // the next index is then changed to the current letter which was stored in temp which completes the switch
          input_sentence_cpy[j] = temp;
      }
    }
  }
  // returns the pointer input_sentence_cpy
  return input_sentence_cpy;
}
