/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 04 - Dynamic STructures
 *   Hari dan Tanggal    : Selasa, 5 Mei 2026
 *   Nama (NIM)          : Hamzah Abdul Rahim (13224066)
 *   Nama File           : Soal1
 *   Deskripsi           : Soal 1 - Ritual Penyegelan
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Buat struct node untuk linked list
typedef struct n{
    char c;
    struct n* next;
}Node;

//Fungsi tambah
void add(Node ** head, char ch){
    Node * cur;
    Node * newChar = (Node*)malloc(sizeof(Node));
    cur = *head;
    newChar->c = ch;
    newChar->next = NULL;
    if(cur==NULL){
        *head = newChar;
        //printf("Success add %c\n", ch);
        return;
    }
    while(cur->next!=NULL){
        cur = cur->next;
    }
    cur->next = newChar;
    //printf("Success add %c\n", ch);
    return;
}

//fungsi lihat nilai di posisi
void seeAt(Node * head, int pos, char *Ch){
    Node * cur;
    cur = head;
    int i = 0;
    while(i<pos && cur->next!=NULL){
        cur = cur->next;
        i++;
    }
    if(cur == NULL){
        *Ch = '0';
        return;
    }
    *Ch = cur->c;
    return;
}

//fungsi hapus nilai di posisi
void delAt(Node ** head, int pos){
    Node * cur;
    Node * temp;
    cur = *head;
    int i = 0;
    if(pos == 0){
        temp = cur;
        *head = cur->next;
        free(temp);
        return;
    }
    while(i<pos-1){
        cur = cur->next;
        i++;
    }
    temp = cur->next;
    cur->next = cur->next->next;
    //printf("Success del %c\n", temp->c);
    free(temp);
    return;
}

//fungsi untuk memperlihatkan, untuk debug
void show(Node * head){
    //printf("got in show\n");
    Node * cur;
    cur = head;
    while(cur!=NULL){
        printf("%c", cur->c);
        cur = cur->next;
    }
    printf("\n");
}

//fungsi utk menghapus 2 elemen berurutan, agar simpel
void delTwo(Node ** head, int pos){
    delAt(head, pos);
    delAt(head, pos);
    //show(*head);
    return;
}


int main(){
    Node * word = NULL;
    char str[1000];
    scanf("%s", str);
    int len = strlen(str);
    int els = 0;
    for(int i = 0; i<len;i++){
        if(str[i] == '(' ||str[i] == ')'||str[i] == '['||str[i] == ']'||str[i] == '{'||str[i] == '}'){
            add(&word, str[i]);
            els++;
        }
    }

    //show(word);
    int exists = 1;
    int done;
    while(els >0 && exists == 1){
        done = 0;
        for(int i = 0;i<els-1;i++){
            char left, right;
            seeAt(word, i, &left);
            seeAt(word, i+1, &right);
            if(left == '('){
                if(right == ')'){
                    
                    delTwo(&word, i);
                    els-=2;
                    done++;
                }
            }
            else if(left == '{'){
                if(right == '}'){
                    delTwo(&word, i);
                    els-=2;
                    done++;
                }
            }
            else if(left == '['){
                if(right == ']'){
                    delTwo(&word, i);
                    els-=2;
                    done++;
                }
            }
        }
        if(done>0){
            exists = 1;
        }
        else{
            exists = 0;
        }
    }

    if(els >0){
        printf("INVALID\n");
    }
    else{
        printf("VALID\n");
    }




}
