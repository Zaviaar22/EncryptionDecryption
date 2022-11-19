
#include <stdio.h>
#include <string.h>




int main() {

  
  // variables
  int d, ASCII=0;
  int outChar = ASCII-16;
  char ans, getAns, fileName[20], getFileName, c;
 
  FILE *fd, *fw;
  
  

  // user input
  printf("Choose encryption/decryption (-E/-D): ");
  scanf("%s", &ans);
  getAns = getchar();
  printf("");

  
  
  // evaluating response for cases

  int decrypt = strcmp(&ans, "-D");
  int cases;


  if(decrypt == 0) {
    cases = 1;
  } else{
    cases = 2;
  }
  

  

  
  // case funtions
  
  switch(cases)
    {
      case 1: //decrypt (not working)

        printf("\nType in the file you would like to decrypt: ");
      scanf("%s", fileName);
     
      
      getFileName = getchar(); 
      printf("The file you chose is %s\n\n", fileName);

      fd = fopen((fileName), "r");
      fw = fopen(strcat(fileName, ".txt"), "w");
      

      if(fd == NULL){
        printf("File does not exist");
        } else {
          printf("Decrypting %s...\n", fileName);
          printf("Decrypted text uploaded to %s\n", fileName);
        }

       d =fgetc(fd);
      while(d!=EOF){
         int i = strcmp("d", "TT");
         if(i == 0){
           d = "  ";
           fprintf(fw, "%c", d);
         }
        
          fprintf(fw, "%c", d);
          d =fgetc(fd);
        
     }
     fclose(fd);
     fclose(fw);
      break;
       
     

      case 2: //encrypt (working)
      printf("\nType in the file you would like to encrypt: ");
      scanf("%s", fileName);
     
      
      getFileName = getchar(); 
      printf("The file you chose is %s\n\n", fileName);

      fd = fopen(fileName, "r");
      fw = fopen(strcat(fileName, ".crp"), "w");

      if(fd == NULL){
        printf("File does not exist");
        } else {
          printf("Encrypting %s...\n", fileName);
          printf("Encrypted text uploaded to %s\n", fileName);
        }

      c=fgetc(fd);
        
      while(c!=EOF){

        if(c=='\n'){
          fprintf(fw, "\n");
          c = fgetc(fd);
        }
         if(c == '\t'){
           fprintf(fw, "TT");
           fprintf(fw, "%c", c);
           c = fgetc(fd);
         }

        if(outChar<32){
          outChar = (outChar-32) + 144;
        }
      
         fprintf(fw, "%d", c);
         c=fgetc(fd);
          }
         
     fclose(fd);
     fclose(fw);
     break;
    }
      


return 0;
}
