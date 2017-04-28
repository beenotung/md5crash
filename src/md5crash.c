#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<openssl/md5.h>

void find(char* ans, int ans_len){
  char* str = ans;
  int length = ans_len;
  unsigned char digest[16];
  MD5_CTX md5;
  MD5Init(&md5);
  MD5Update(&md5, str, length);
  MD5Final(digest, &md5);
}

int main(int argc, char ** argv){
  printf("argc: %i\n",argc);
  if(argc!=2){
    fprintf(stderr, "Error: invalid argument.\nExample: %s <md5 hash to guess>\n", argv[0]);
    return 1;
  }
  char* ans = argv[1];
  printf("finding value for hash value: %s\n", ans);

  find(ans, strlen(ans));

  return 0;
}
