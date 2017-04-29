#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<openssl/md5.h>
#include "./md5.h"
#include <stdbool.h>

void print_hash(unsigned char hash[]){
  for(int idx=0; idx< 16; idx++){
    printf("%02x", hash[idx]);
  }
}

bool check_md5(char* str, int str_length, char ans_md5[16]){
  unsigned char digest[16];
  MD5_CTX md5;
  md5_init(&md5);
  md5_update(&md5, str, str_length);
  md5_final(&md5, digest);
//  printf("the hash is: ");
//  print_hash(digest);
//  printf("\n");
  for(int i=0; i<16; i++){
    if(digest[i]!=ans_md5[i]){
      return false;
    }
  }
  return true;
}

//void search_message(int start, int end, char* ans_md5){
//  check_md5(str, str_length, ans_md5)
//}

int main(int argc, char ** argv){
  printf("argc: %i\n",argc);
  if(argc!=2){
    fprintf(stderr, "Error: invalid argument.\nExample: %s <md5 hash to guess>\n", argv[0]);
    return 1;
  }
  char* ans = argv[1];
  if(strlen(ans)!=32){
    fprintf(stderr, "Error: invalid argument.\n md5 hash should be length of 32\n");
  }
  unsigned char ans_md5[16];
  //TODO
  for(int i=0; i<16; i++){
    int idx = i*2;
    if('0'<=ans[idx] && ans[idx]<='9'){
      ans_md5[idx] = ans[idx]-'0';
    }else if('a'<=ans[idx] && ans[idx]<='f'){
      ans_md5[idx] = ans[idx]-'a'+10;
    }else{
      fprintf(stderr, "Error: invalid argument.\n md5 hash should be only consist of [0-9] and[a-f]\n");
      return 1;
    }
  }

  printf("finding value for hash value: %s\n", ans);
  printf("in hash form: ");
  print_hash(ans_md5);
  printf("\n");

  check_md5(ans, strlen(ans), ans);

  return 0;
}
