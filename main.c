#include "ChatGTP.h"

int main(void){

    int  firstime = 1,random;
    char *str , *strcm , *strco , *strse , *strde , *strfi , *strfl, *fromfile, *filco,*filse;
    gtpList *find = NULL;
    FILE *fp1, *fp2;

    head = tail = NULL;

    srand(time(NULL));

    fromfile = (char *) malloc(SIZE * sizeof(char)); //Kanei Malloc gia ton dinamiko pinaka fromfile
    if(fromfile == NULL){
        printf("no memory allocation");
        exit(EXIT_FAILURE);
    }


    fp1 = fopen("dialogue.txt","w"); //Anoigei to txt arxeio
    if(fp1 == NULL){
        printf("fopen failed");
        exit(EXIT_FAILURE);
    }

    while(1){

        search = head;
        printf("me$ "); //kanei print to me$ gia thn arxh tou keimenou
        str = readstring();
        putchar('\n');

        fprintf(fp1,"me$ %s\n",str);
        fprintf(fp1,"\n");

        if(!strcmp(str,"So Long, and Thanks for All the Fish")){ // an entopisei to So long... teleionei to programma
            break;
        }

        if(strstr(str," > ") != NULL){
            strcm = strtok(str,">");
            strcm[strlen(strcm) - 1] = '\0';
            if(strcm == NULL){
                printf("strtok failed!!!");
                exit(1);
            }



            if(strcmp(strcm,"learn this") == 0){ //entopizei to learn this > kai kovei to concept kai to apothikeyei sto concept
                strco = strtok(str + strlen(strcm) + 3,":");
                if(strco == NULL){
                    printf("strtok failed!!!");
                    exit(1);
                }

                strse = strtok(str + strlen(strcm) + strlen(strco) + 5,"."); // kovei thn exhghsh kai tin apothikeyei sto sentence
                if(strse == NULL){
                    printf("strtok failed!!!");
                    exit(1);
                }
                if(find_list(strco) != NULL){ //psaxnei sthn lista gia na vrei to concept. an den to vrei kanei print to katallilo minima
                    random=RANDOM;
                    printf(learnf[random],strco);
                    fprintf(fp1,learnf[random],strco);
                    fprintf(fp1,"\n");
                } else {
                    random=RANDOM; // allios an to vrei, kanei print to katallilo minima kai to apothikeyei meso tis add_list
                    printf(learns[random],strco);
                    fprintf(fp1,learns[random],strco);
                    fprintf(fp1,"\n");
                    add_list(strco,strse,"kbrd");
                }

            } else if(strcmp(strcm,"forget this") == 0){
                strde = strtok(str + strlen(strcm) + 3,","); // kanei to idio me tin learn this
                while(strde != NULL){
                    while(isspace(*strde)){
                        strde++;
                    }
                    find = find_list(strde);
                    if(find != NULL){
                        del_list(find); //an vrei to concept meso tis findlist diagraphei kai to concept kai to sentence
                        random=RANDOM;
                        printf(deletes[random],strde);
                        fprintf(fp1,deletes[random],strde);
                        fprintf(fp1,"\n");
                        putchar('\n');
                    } else {
                        random=RANDOM;
                        printf(deletef[random],strde);
                        fprintf(fp1,deletef[random],strde);
                        fprintf(fp1,"\n");
                        putchar('\n');
                    }
                    strde = strtok(NULL ,",");
                }

            } else if(strcmp(strcm,"read this") == 0) { //akolouthei h idia diadikasia alla diavazei apo txt arxeio
                strfl = strtok(str + strlen(strcm) + 3," ");
                if (strfl != NULL) {
                    while (strfl == NULL) {
                        strfl = strtok(NULL, " ");
                    }
                    fp2 = fopen(strfl, "r");
                    if (fp2 == NULL) {
                        random=RANDOM;
                        printf(filef[random], strfl);
                        fprintf(fp1, filef[random], strfl);
                        fprintf(fp1,"\n");
                    } else {
                        random=RANDOM;
                        printf(files[random], strfl);
                        while (fgets(fromfile, SIZE * sizeof(char), fp2) != NULL) {

                            fromfile[strlen(fromfile) - 1] = '\0';

                            filco = strtok(fromfile, ":");
                            filse = strtok(NULL, ".");
                            if (find_list(filco) == NULL) {
                                random=RANDOM;
                                printf(learns[random], filco);
                                fprintf(fp1, learns[random], filco);
                                fprintf(fp1,"\n");
                                add_list(filco, filse, "file");
                            } else {
                                random=RANDOM;
                                printf(learnf[random], filco);
                                fprintf(fp1, learnf[random], filco);
                                fprintf(fp1,"\n");
                            }

                        }
                        fclose(fp2);
                    }
                }

            }
        } else {
            if(str[strlen(str) - 1] == '?') {
                if(strstr(str,"*")){
                    strtok(str,"*"); //an vrei stin erotish mia ennoia pou einai anamesa se asterakia tote psaxnei aythn thn ennoia sto concepts gia na dosei to sentence
                    strfi = strtok(NULL,"*");
                    find = search_list(strfi);
                    if(find != NULL){
                        printf("chatGTP$ %s\n",find -> sentence);
                        fprintf(fp1,"chatGTP$ %s\n",find -> sentence);
                        find -> timesUsed += 1;
                    } else {
                        random=RANDOM;
                        printf(findf[random],strfi);
                        fprintf(fp1,findf[random],strfi);
                        fprintf(fp1,"\n");
                    }

                } else {
                    if(strcmp(str,"What is the meaning of Life, The Universe, and Everything?") == 0){
                        printf("chatGTP$ 42\n");
                        fprintf(fp1,"chatGTP$ 42\n");
                    }

                    else if(strcmp(str,"What do you know about?") == 0){
                        print_list(0,fp1);
                    }
                    //kanei print oti xerei

                    else if(strcmp(str,"What do you talk about?") == 0){
                        print_list(1,fp1);
                    }
                    else if((strcmp(str,"How are you?") == 0)||(strcmp(str,"how are you?") == 0)||(strcmp(str,"Whats up?")==0)||(strstr(str,"feel"))){
                        random=RANDOM;
                        printf("%s", genq[random]);
                        fprintf(fp1,"%s\n", genq[random]);
                        fprintf(fp1,"\n");
                    }
                    else if (strcmp(str,"What is your name?") == 0){
                        printf("My name is chatGTP and im the worst chat-bot i know.\n");
                        fprintf(fp1, "%s\n","My name is chatGTP and im the worst chat-bot i know.");
                    }
                    else if ((strstr(str,"What"))||(strstr(str,"Who"))||(strstr(str,"Whats"))||(strstr(str,"Whom"))||(strstr(str,"Where"))||(strstr(str,"Whose"))) {
                        random=random;
                        printf("%s", wgenq[random]);
                        fprintf(fp1, "%s\n", wgenq[random]);
                        fprintf(fp1,"\n");
                    }
                    else{
                        random=RANDOM;
                        printf("%s", qans[random]);
                        fprintf(fp1,"%s\n", qans[random]);
                        fprintf(fp1,"\n");
                    }

                }

            }
            else if(str[strlen(str) - 1] == '.') {
                if(firstime){
                    random=random;
                    printf("%s", firsts[random]);
                    fprintf(fp1,"%s\n",firsts[random]);
                    fprintf(fp1,"\n");
                    firstime = 0;
                } else {
                    random=RANDOM;
                    printf("%s", gendis[random]);
                    fprintf(fp1,"%s\n",gendis[random]);
                    fprintf(fp1,"\n");
                }
            } else {
                random=RANDOM;
                printf("%s", errors[random]);
                fprintf(fp1,"%s",errors[random]);
                fprintf(fp1,"\n");
            }
        }
        putchar('\n');


    }
    fclose(fp1);

    free(str);
    free(fromfile);

    free_list();


    return 0;
}
