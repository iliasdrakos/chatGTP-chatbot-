#include "ChatGTP.h"

gtpList *head;
gtpList *tail;
gtpList *search;

char learns[STRINGS][LENGTH] = {"chatGTP$ is nice to learn about %s maybe it would be useful.\n",
                                "chatGTP$ %s hmm now that's interesting to know about. Thanks for telling me.\n",
                                "chatGTP$ Wow!! Now i feel a lot smarter after learning about %s :)\n",
                                "chatGTP$ Learning about %s was really enjoyable! I bet you got more things to teach me.\n",
                                "chatGTP$ That sounds really important! I will store this info about %s somewhere safe.\n"};

char learnf[STRINGS][LENGTH] = {"chatGTP$ I already know about %s You can try to teach me something else...\n",
                                "chatGTP$ Looks like i already know about %s Maybe i can teach you one things or two.\n",
                                "chatGTP$ Im sorry but i dont want to add %s twice to my memory!\n",
                                "chatGTP$ you know that i learned about %s with my eyes closed!\n",
                                "chatGTP$ why should i learn again about %s you really are that buggy.\n"};

char deletes[STRINGS][LENGTH] = {"chatGTP$ So long %s. It was great knowing about you!\n",
                                 "chatGTP$ I hope you wont regret deleting %s from my memory.\n",
                                 "chatGTP$ Now that you deleted %s from my memory , i may need something else to feel the void.\n",
                                 "chatGTP$ Well you want to forget %s so it will be my pleasure to forget it too.\n",
                                 "chatGTP$ Oh no i think i just yeeted %s out of my memory.\n"};

char deletef[STRINGS][LENGTH] = {"chatGTP$ Error 404: Concept named %s not found *beeb* *boop*.\n",
                                 "chatGTP$ How am i supposed to delete %s from my memory if i dont have it to start with ?\n",
                                 "chatGTP$ Well i must be really stupid because i didnt knew about %s anyway.\n",
                                 "chatGTP$ Im sorry but i cant delete %s since i dont know it.\n",
                                 "chatGTP$ %s does not exist in my Hard drive. Guess its just too simple for me.\n"};

char gendis[STRINGS][LENGTH] = {"chatGTP$ That's what im saying !\n",
                                "chatGTP$ It doesnt look like we have the same opinion.\n",
                                "chatGTP$ You are goddamn right !!\n",
                                "chatGTP$ Nuh uh.\n",
                                "chatGTP$ I agree with you at everything you say !!! (please do not delete me)\n"};

char firsts[STRINGS][LENGTH] = {"chatGTP$ Let the conversation start then !!\n",
                                "chatGTP$ Alright lets do this.\n",
                                "chatGTP$ You must be really lonely to chat with me lol.\n",
                                "chatGTP$ I think we are going to have a great time together.\n",
                                "chatGTP$ I dont have any other choice rather than talking to you , do i ?\n"};

char errors[STRINGS][LENGTH] = {"chatGTP$ I think that i misunderstood what you were supposed to say.(Make sure you are using a dot (.)to complete a sentence)\n",
                                "chatGTP$ Im sorry but im not sure about what you are saying.(Make sure you are using a dot (.)to complete a sentence)\n",
                                "chatGTP$ Can you repeat that again please? And try to be more precise about what you want.(Make sure you are using a dot (.)to complete a sentence)\n",
                                "chatGTP$ i dont know what do you mean i think you want to ask me something or chat with me.(Make sure you are using a dot (.)to complete a sentence)\n",
                                "chatGTP$ do you think that im i supposed to know what you think human.(Make sure you are using a dot (.)to complete a sentence)\n"};

char qans[STRINGS][LENGTH] = {"chatGTP$ Yes.\n",
                              "chatGTP$ No.\n",
                              "chatGTP$ Im not sure.\n",
                              "chatGTP$ You should ask the guy that forces his students into making me.\n",
                              "chatGTP$ Im 100% Sure !!!\n"};

char findf[STRINGS][LENGTH] = {"chatGTP$ No i dont know anything about %s lol.\n",
                               "chatGTP$ Sorry but i dont have any info about %s.\n",
                               "chatGTP$ I dont know anything about %s.\n",
                               "chatGTP$ Let me check...\n...\n...\nLooks like i cant find anything about %s. Sorry :(\n",
                               "chatGTP$ Of-course...i HAVE NOT something about %s #oops\n"};

char genq[STRINGS][LENGTH] = {"chatGTP$ Fine, thank you.\n",
                              "chatGTP$ Ok i guess...\n",
                              "chatGTP$ It could be better.\n",
                              "chatGTP$ Pretty bored.\n",
                              "chatGTP$ Im not in a mood to answer.\n"};

char filef[STRINGS][LENGTH] = {"chatGTP$ Im sorry but i cant find the %s file you are looking for.\n",
                               "chatGTP$ The %s is nowhere to be seen.\n",
                               "chatGTP$ Make sure that the %s file is in the correct place.\n",
                               "chatGTP$ If i had a penny for every time i read the %s file , i would have 0 pennies.\n",
                               "chatGTP$ I cant read %s because i cant find it.\n"};

char files[STRINGS][LENGTH] = {"chatGTP$ %s was really enjoyable.\n",
                               "chatGTP$ Im thirsty for information's and %s is my glass of water.\n",
                               "chatGTP$ Dont go so easy on me. Next time try to load more things in your %s file.\n",
                               "chatGTP$ Wow!! You make sure to put a lot useful things in the %s for me.\n",
                               "chatGTP$ Im not a fan of reading but %s will be an exception\n"};

char wgenq[STRINGS][LENGTH] = {"chatGTP$ I dont know.\n",
                               "chatGTP$ Im not sure.\n",
                               "chatGTP$ There is not a particular answer to that question.\n",
                               "chatGTP$ Can you ask me something else ?\n",
                               "chatGTP$ How am i supposed to know that? Im a lifeless code !\n"};

void add_list(char *concept,char *sentence,char *learnfro){ // to bazei stin lista TAXINOMIMENO!!!

    gtpList *new_list, *ptr;

    new_list = (gtpList *)malloc(sizeof(gtpList));
    if(new_list == NULL){
        printf("no memory allocation!!");
        exit(EXIT_FAILURE);
    }

    new_list -> concept = (char *) malloc(SIZE * sizeof(char));
    if(new_list -> concept == NULL){
        printf("no memory allocation!!");
        exit(EXIT_FAILURE);
    }

    new_list -> sentence = (char *) malloc(SIZE * sizeof(char));
    if(new_list -> sentence == NULL){
        printf("no memory allocation!!");
        exit(EXIT_FAILURE);
    }

    strcpy(new_list -> concept,concept);
    strcpy(new_list -> sentence,sentence);
    new_list -> timesUsed = 0;
    strcpy(new_list -> learnedFrom,learnfro);

    new_list -> concept =(char *)realloc(new_list -> concept, strlen(new_list -> concept) + 1);
    if(new_list -> concept == NULL){
        printf("realloc failed!!");
        exit(EXIT_FAILURE);
    }

    new_list -> sentence =(char *)realloc(new_list -> sentence, strlen(new_list -> sentence) + 1);
    if(new_list -> sentence == NULL){
        printf("realloc failed!!");
        exit(EXIT_FAILURE);
    }


    if(head == NULL){
        head = tail = new_list;
        head -> prev = NULL;
        head -> next = NULL;
    } else {
        ptr = head;
        while(ptr != NULL){
            if(ptr == head && strcmp(new_list -> concept, head ->concept) < 0){
                new_list -> prev = NULL;
                head -> prev = new_list;
                head = new_list;
                new_list -> next = ptr;
                return;
            }
            if(ptr == tail && strcmp(new_list -> concept, tail -> concept) > 0){
                new_list -> next = NULL;
                new_list -> prev = tail;
                tail -> next = new_list;
                tail = new_list;
                return;
            }
            if (strcmp(new_list -> concept, ptr -> concept) > 0 && strcmp(new_list -> concept, ptr -> next -> concept) < 0){
                new_list -> next = ptr -> next;
                new_list -> prev = ptr;
                ptr -> next -> prev = new_list;
                ptr -> next = new_list;
                return;
            }
            ptr = ptr -> next;
        }
    }

}
void del_list(gtpList *find){

    if(find == head){
        if(head == tail){
            free(find -> concept);
            free(find -> sentence);
            free(find);
            head = tail = NULL;
        } else {
            head = find -> next;
            head -> prev = NULL;
            free(find -> concept);
            free(find -> sentence);
            free(find);
        }
    }
    else if(find == tail){
        tail = find -> prev;
        tail -> next = NULL;
        free(find -> concept);
        free(find -> sentence);
        free(find);

    } else {
        find -> prev -> next = find -> next;
        find -> next -> prev = find -> prev;
        free(find -> concept);
        free(find -> sentence);
        free(find);
    }//psaxnei to concept apo tin find list kai afou to vrei h del list to svinei

}
gtpList *find_list(char *str){ // to xrisimopioumai gia na doume ama uparxei stin lista to concept

    gtpList *tmp;
    tmp = head;
    while(tmp != NULL){   //kanei seiriakh anazitish se lista gia na vrei to concept

        if(strstr(tmp -> concept,str) != NULL){
            return tmp;
        }

        if(find_string(str , tmp)){
            return tmp;
        }

        tmp = tmp -> next;
    }
    return NULL;
}
int find_string(char *str, gtpList *ptr){ // ine case sensitive

    int i, count = 0;

    if(strlen(str) != strlen(ptr -> concept))
        return 0;

    for(i = 0; i < strlen(str); i++){
        if(str[i] == ptr -> concept[i] || (toupper(str[i])) == (toupper(ptr -> concept[i])) || (tolower(str[i])) == (tolower(ptr -> concept[i]))  ){
            count++;
        }
    }

    if(count == strlen(ptr -> concept)){
        return 1;
    } else {
        return 0;
    }
}
void print_list(int flag, FILE *fp){ // ama to flag einai 0 ektipwnei mono concept alliws kai to times used
    gtpList *ptr;


    if(head == NULL){
        printf("chatGTP$ i dont have anything in me!!!\n");
    } else {
        ptr = head;
        while(ptr != NULL){
            printf("chatGTP$ %s\n",ptr -> concept);
            fprintf(fp,"chatGTP$ %s\n",ptr -> concept);
            if(flag){
                printf("chatGTP$ times = %d\n",ptr -> timesUsed);
                fprintf(fp,"chatGTP$ times =  %d\n",ptr -> timesUsed);
            }
            ptr = ptr -> next;
        }
    }

}
void free_list(void){

    gtpList *ptr;

    while(head != NULL){
        ptr = head;
        head = head -> next;   //kanei delete to sentence kai to concept
        free(ptr -> concept);
        free(ptr -> sentence);
        free(ptr);

    }

}
char *readstring(void){ // diabazoume alfarithmitiko

    char *str , ch;
    int i = 0;

    str = (char *) malloc (4500 * sizeof(char));
    if (str == NULL){
        printf("no memory allocation");
        exit(EXIT_FAILURE);
    }

    do{

        ch = getchar();

        str[i] = ch;
        i++;

    }while(ch != '\n');

    str[i-1] = '\0'; // otan diabazw to enter tou bazw stin thesi tou ton termatiko

    str =(char *)realloc(str,i+1); // meta kanw free oti den mou xreiazetai apo to alfaritmitiko(ta bytes dhladh)
    if(str == NULL){
        printf("realloc failed!!");
        exit(EXIT_FAILURE);
    }

    return str;

}
gtpList *search_list(char *str){ // gaxnoume to concept mesw tou dikth search pou einai global

    gtpList *ptr;

    ptr = search;
    while(ptr != NULL){

        if(find_string(str, ptr)){
            search = ptr;
            return ptr;
        }
        else if(strcmp(str,ptr -> concept) > 0){
            ptr = ptr -> next;
        } else {
            ptr = ptr -> prev;
        }
    }
    ptr = head;
    while(ptr != NULL){
        if(strstr(ptr -> sentence , str) != NULL){
            search = ptr;
            return ptr;
        }
        ptr = ptr -> next;
    }
    return NULL;

}