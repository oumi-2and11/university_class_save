#include<stdio.h>
#include<windows.h>
#include<string.h>

#include<iostream>
using namespace std;
#define MAX_KEY 256
#define MAX_STR 100

int pos_i = 0;
int pos_j = 0;
int sbox[256];
unsigned char key[MAX_KEY] ="{This_is_a_key_!}";//{ 0xFC, 0xFB, 0x3B, 0x0D, 0x73, 0x6E }; //"secrets"; // 密钥
//unsigned char answer[MAX_STR] = { 0xd5, 0x23, 0xa5, 0x22, 0x75, 0x08, 0xb7, 0x80 };改这里没用改下面  ciphertext[MAX_STR]

void init_sbox();
unsigned char generate_key();
void encryption(unsigned char* plaintext, unsigned char* result);
void decryption(unsigned char* ciphertext, unsigned char* result);

// 解密函数
void decryption(unsigned char* ciphertext, unsigned char* result) {
    pos_i = 0;           // 重置 RC4 的指针
    pos_j = 0;           // 重置 RC4 的指针
    int len = strlen((const char*)ciphertext);  // 获取密文长度
    int i = 0;

    init_sbox();         // 初始化 S 箱
    for (i = 0; i < len; ++i) {
        result[i] = ciphertext[i] ^ generate_key();  // 密文与密钥流异或，，，，~generate_key()（如果密钥取反） 
    }
    result[i] = '\0';    // 结束符
}

int main() {
    // 示例密文
    unsigned char ciphertext[MAX_STR] ={0x3D, 0x93, 0x66, 0x29, 0xE7, 0x31, 0xF1, 0x0E, 0xB2, 0x06, 0x71, 0x91, 0x89, 0x93, 0x00, 0x00};
    unsigned char decrypted[MAX_STR] = { 0 };

    // 调用解密函数
    decryption(ciphertext, decrypted);

    // 输出明文（字符形式）
    puts("Decrypted plaintext（解密明文为）:");
    cout << decrypted << endl;  // 输出字符形式的明文

    system("pause");
    return 0;
}

// RC4 初始化 S 箱
void init_sbox() {
    int i, j;
    int key_len = strlen((const char*)key);
    unsigned char temp;
    for (i = 0; i < 256; ++i)
        sbox[i] = i;
    j = 0;

    for (i = 0; i < 256; ++i) {
        j = (j + sbox[i] + key[i % key_len]) % 256;
        temp = sbox[i];
        sbox[i] = sbox[j];
        sbox[j] = temp;
    }
}

// RC4 生成密钥流字节
unsigned char generate_key() {
    unsigned char temp;
    int t;

    pos_i = (pos_i + 1) % 256;
    pos_j = (pos_j + sbox[pos_i]) % 256;
    temp = sbox[pos_i];
    sbox[pos_i] = sbox[pos_j];
    sbox[pos_j] = temp;
    t = (sbox[pos_i] + sbox[pos_j]) % 256;
    return sbox[t];
}

// RC4 加密函数
void encryption(unsigned char* plaintext, unsigned char* result) {
    pos_i = 0;
    pos_j = 0;
    int len = strlen((const char*)plaintext);
    int i = 0;

    init_sbox();
    for (i = 0; i < len; ++i) {
        result[i] = plaintext[i] ^ generate_key();
    }
    result[i] = '\0';
}

