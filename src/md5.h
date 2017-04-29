/* This file was automatically generated.  Do not edit! */
#define uchar unsigned char
#define uint unsigned int
typedef struct {
   uchar data[64];
   uint datalen;
   uint bitlen[2];
   uint state[4];
} MD5_CTX;
void md5_final(MD5_CTX *ctx,uchar hash[]);
void md5_update(MD5_CTX *ctx,uchar data[],uint len);
void md5_init(MD5_CTX *ctx);
void md5_transform(MD5_CTX *ctx,uchar data[]);
