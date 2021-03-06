#include<stdio.h>
#include<string.h>

int isLower(int ch){
   if(ch >= 97 && ch <= 122)
      return 1;
   return 0 ;
}

int Strlen(const char* string){
    
    int len = 0;
    while (*string != '\0'){
        len++;
        string++;
    }
    return len;    
}

int power(int base, int p){ 
   int result = 1;
   if(p){ 
      for(int i = p; i > 0; i--){ 
      
         result *= base;
      }
      return result;
   }
   else{ 
      return result; 
   }
}

int delete(char*data, int index, int length){

    int i;
    for (i = index; i < (length)-1; i++){
        *(data+i) = *(data+i+1);
    }
    *(data+i) = '\0';
    length--;
    return length;

}


int insert(char*data, int index, int element, int uSize, int tSize){

    if(uSize >= tSize)
        return -1;
    for(int i = uSize-1; i >= index; i--)
        *(data+i+1) = *(data+i);
    
    *(data+index) = element;
    uSize++;
    *(data+(uSize)) = '\0';

    return uSize;
}

int binToDec(char* binary){ 
    
    int i = 0, j, k;
    int dec = 0;
    while(*(binary+i) != '\0')
        ++i;
    for(j = i-1, k = 0; j >= 0; --j, ++k){
        dec += (*(binary+k)-48)*power(2,j); 
    }
    return dec;

}


void reverse(char*str){
   
   int len = 0;
   char*ptr = str;
   while(*ptr != '\0'){
      len++;
      ptr++;
   }
   int i = 0, j = len-1;
   while(i < j){
      int temp  = *(str+i);
      *(str+i) = *(str+j);
      *(str+j) = temp;
      ++i;
      --j;
   }
}


char* decToBin(int n){ 
    
    unsigned int dec = n;
    char binary[20]; 
    int i = 0;

    while(dec){ 

        int remain = dec % 2; 
        binary[i++] = remain+48; 
        dec = dec/2; 
    }

    binary[i] = '\0';

    reverse(binary);
    return strdup(binary);
    
}   


int charValidate(char ch) {

    if(ch < 0 || ch > 126)
        return -1;
    return 0;
}


int get_filesize(char file_name[]){

    FILE* fp = fopen(file_name, "r");
    if (fp == NULL) {
        return -1;
    }
    fseek(fp, 0L, SEEK_END);
    int res = ftell(fp);
    fclose(fp);
  
    return res;
}


int checkIfFileExists(const char * filename) {

    FILE *file;
    if((file = fopen(filename, "r")) != NULL) {
        fclose(file);
        return 1;
    }
    return 0;
}


char *basename(char const *path, char slash) {
    
    char *s = strrchr(path, slash);
    if(!s) 
        return strdup(path);
    else 
        return strdup(s + 1);
}