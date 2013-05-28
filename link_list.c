#include<stdlib.h>
#include<stdio.h>
#define LIST_INIT_SIZE 100
#define LISTICREASE 10
typedef struct{
    int *node;                    //The start point of this list
    int length;                   //the length of list
    int listsize;                 //the menory has assign with list
}Sql_list

void InitList(Sql_list &L ){
    L.node = (int *)malloc(LIST_INIT_SIZE*sizeof(int));
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return;
}
void ListInsert(Sql_list &L,int i,int e){
    //i was the place you would like to insert
    if(i < 1 || i >L.length+1){
    printf("The value of place was illegal!");
    return;
    }
    else if(L.length >= L.listsize){
    tempbase = (int *)realloc(L.node,(L.listsize+LISTICREASE)*sizeof(int));
    if(!tempbase){
        printf("The momory was overflow");
        return;
    }
    L.node = tempbase;
    L.listsize += LISTICREASE;
    }
    q = &(L.node[i-1]);
    for(p=&(L.node[L.length-1]);p>=q;--p)
        *(p+1) = *p;
    *q = e;
    ++L.length;
    return;

}
void ListDelete(Sql_list &L,int i,int &e){
    //The i was the element you would like to delete
    if(i<1||i>L.length){
        printf("The vlaue of i was illegal!");
        return;
    }
    p = &(L.node[i-1]);                 //p was the element you want to delete
    q = L.node[L.length-1];             //q was the ending point of the list
    for(;p<=q;++p){
    *(p-1)=*p;                          //delete the element in for
    }
    --L.length;
    return;
}

