//#ifndef PROJECT2_CHATGTP_H
//#define PROJECT2_CHATGTP_H

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define STRINGS 5
#define LENGTH 150
#define SIZE 1000
#define RANDOM rand() % 5


typedef struct gList {
    char *concept;
    char *sentence;
    int timesUsed;
    char learnedFrom[5];
    struct gList *next;
    struct gList *prev;

} gtpList;

extern gtpList *head;
extern gtpList *tail;
extern gtpList *search;

extern char learns[STRINGS][LENGTH] ;

extern char learnf[STRINGS][LENGTH] ;

extern char deletes[STRINGS][LENGTH] ;

extern char deletef[STRINGS][LENGTH];

extern char gendis[STRINGS][LENGTH] ;

extern char firsts[STRINGS][LENGTH];

extern char errors[STRINGS][LENGTH];

extern char qans[STRINGS][LENGTH];

extern char findf[STRINGS][LENGTH] ;

extern char genq[STRINGS][LENGTH];

extern char filef[STRINGS][LENGTH];

extern char files[STRINGS][LENGTH];

extern char wgenq[STRINGS][LENGTH];


void add_list(char *concept,char *sentence,char *learnfro);
void del_list(gtpList *find);
gtpList *find_list(char *str);
int find_string(char *str, gtpList *ptr);
gtpList *search_list(char *str);
void print_list(int flag , FILE *fp);
void free_list(void);
char *readstring(void);
