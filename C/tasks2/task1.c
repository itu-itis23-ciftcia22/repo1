#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define ALPHABET_SIZE 26
#define MAX_WORD_COUNT 20
#define SIZE 50

void count_letter(char* text, int* counts) // string alip icinde hangi harf kac defa var sayan fonskiyon
{
    for(int i = 0; *(text+i) != '\0' ; i++) 
    {
      char letter = tolower(*(text+i));
      int letter_int = letter - 'a';
      if(isalpha(letter)){
        (*(counts+letter_int))++;
      }
    }
}

void print_counts(int* counts)
{
  printf("Letter\tNumber\n");
  for(int i = 0; i < ALPHABET_SIZE; i++)
  {
      if(*(counts+i) != 0){
        printf("%c\t%d\n",toupper(('a'+i)),*(counts+i));
      }
  }
}

void count_word(char* text, int*counts)
{
  
  int length = 0;
  for(int i=0; *(text+i) != '\0' && *(text+i) != '\n'; i++)
  {
    if(*(text+i) == ' ')
    {
      if(length > 0){
          (*(counts+length))++;
          length = 0;
      }
    }
    else if(isalpha(*(text+i)))
    {
        length++;
    }
  }
  if(length > 0){
          (*(counts+length))++;
  }
}

void print_counts2(int* counts)
{
  printf("Word Length\tOccurrences\n");

  for(int i = 1; i < MAX_WORD_COUNT; i++)
  {
      if((*(counts+i)) != 0){
        printf("%d letter words\t%d\n",i,*(counts+i));
      }
  }
}

int main()
{
  char* text = (char*)malloc(sizeof(char)*SIZE);
  int* counts = (int*)malloc(sizeof(int)*ALPHABET_SIZE);
  int* counts2 = (int*)malloc(sizeof(int)*MAX_WORD_COUNT);
  
  puts("Enter a line of text");
  fgets(text,SIZE,stdin);

  count_letter(text,counts);
  print_counts(counts);
  count_word(text,counts2);
  print_counts2(counts2);

  free(text);
  free(counts);
  free(counts2);

  return 0;
}