#include <stdio.h>
#include <stdlib.h>

int saveHandler(char* account,char* password){
  FILE *filePointer;

  filePointer = fopen("fun.txt", "a");
  fprintf(filePointer, "%s: %s\n",account, password);
  fclose(filePointer);
  return 1;
}

char* handleInput(FILE* fp, size_t size){
  char* str;
  int ch;
  size_t len = 0;

  str = malloc(sizeof(char)*size);
  if(!str) return str;
  while( EOF != (ch=fgetc(fp)) && ch != '\n'){
    str[len++] = ch;
    if(len == size){
      str = realloc(str, sizeof(char)*(size+=16));
      if(!str) return str;
    }
  }
  str[len++]='\0';
  return realloc(str, sizeof(char)*len);
}

void newPassword(){
  char* account;
  char* password ;
  int foo;
  printf("Enter the Account name: ");
  account = handleInput(stdin, 10);
  printf("\nEnter Password:");
  password = handleInput(stdin,10);

  foo = saveHandler(account, password);
  if(foo){
    printf("Saved Successfully\n");
  }
  else{
    printf("Error\n");
  }
}

void main(){
  int option;
  printf("---------------------------------\n");
  printf("Welcome to the Password Manager\n");
  printf("---------------------------------\n");

  while (1) {
    printf("Press 1 to enter new password\n");
    printf("Press 2 to retrieve password\n");
    scanf("%d", &option);

    switch (option) {
      case 1: newPassword();
            break;
      case 2: retrievePassword();
            break;
    }
  }
}
