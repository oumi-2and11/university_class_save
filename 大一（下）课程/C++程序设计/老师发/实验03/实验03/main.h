#ifndef _MAIN_H_
#define _MAIN_H_

#define WORD_NUMBER	100
#define TEXT_LEN	64
#define KEY_LEN		16

int Sort(char *p[], int n);
int EncSort(char *p[], char key[KEY_LEN], int cnt, char *c[]);
int DecSort(char *c[], char key[KEY_LEN], int cnt, char *r[]);

#endif//_MAIN_H_