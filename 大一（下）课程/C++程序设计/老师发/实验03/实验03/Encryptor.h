#ifndef _ENCRYPTOR_H_
#define _ENCRYPTOR_H_

#define SUCCESS         0
#define PLAIN_NULL      1
#define KEY_NULL        2
#define CHIPHER_NULL    3
#define RESULT_NULL     4
#define MEM_EMPTY       5



int Encryptor(char plain[], char key[], char cipher[]);
int Decryptor(char cipher[], char key[], char result[]);

#endif//_ENCRYPTOR_H_