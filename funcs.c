#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "define_func.h"

#define INF 99999


char set_node(int* graph,int n,int srcId){
    if(srcId==-1){
        scanf("%d",&srcId);
        if(srcId==' '){
            scanf("%d",&srcId);
        }
    }
    int* src=graph+n*srcId;
    char input;
    scanf("%c",&input);
    if(input==' '){
        scanf("%c",&input);
    }

    while(isdigit(input)!=0){
        
        int dest=input-'0';
        scanf("%c",&input);
        if(input==' '){
            scanf("%c",&input);
        }
        int value=input-'0';
       
        *(src+dest)=value;
        scanf("%c",&input);
        if(input==' '){
            scanf("%c",&input);
        }
    }
    return input;
}

int* add_node(int *graph,int n,int *values,char *curinput,int* exist){
    int srcId;
    scanf("%d",&srcId);
    if(srcId==' '){
        scanf("%d",&srcId);
    }
    if(is_exist(srcId,values,n-1)==1){
        
        char input=set_node(graph,n-1,srcId);
        *curinput=input;
        *exist=1;
        return graph;
    }
    int *new_g=(int*)malloc(sizeof(int)*n*n);
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            *(new_g+i*n+j)=*(graph+i*(n-1)+j);
        }
        *(new_g+i*n+n-1)=-1;
    }
    for(int i=0;i<n;i++){
        *(new_g+(n-1)*n+i)=-1;
    }
    free(graph);
    values=(int*)realloc(values,sizeof(int)*n);
    *(values+(n-1))=srcId;
    char input=set_node(new_g,n,n-1);
    *curinput=input;
    return new_g;
}

int* remove_node(int *graph,int n,int k,int *vals){
    k=val_to_key(k,vals,n);
    int *new_g=(int*)malloc(sizeof(int)*(n-1)*(n-1));
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            *(new_g+i*(n-1)+j)=*(graph+i*n+j);
        }
        for(int j=k+1;j<n;j++){
            *(new_g+i*(n-1)+j-1)=*(graph+i*n+j);
        }
    }
    for(int i=k+1;i<n;i++){
        for(int j=0;j<k;j++){
            *(new_g+(i-1)*(n-1)+j)=*(graph+i*n+j);
        }
        for(int j=k+1;j<n;j++){
            *(new_g+(i-1)*(n-1)+j-1)=*(graph+i*n+j);
        }
    }

    free(graph);
    return new_g;
}

int shortest_path(int *graph,int n,int *vals){
    int dist[n][n], i, j, k;
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            if(*(graph+i*n+j)==-1){
                dist[i][j]= INF;
            }else{
                dist[i][j]=*(graph+i*n+j);
            }
        }
    }
    for (k = 0; k < n; k++){
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    char input;
    scanf("%c",&input);
    if(input==' '){
        scanf("%c",&input);
    }
    int src=input-'0';
    src=val_to_key(src,vals,n);
    scanf("%c",&input);
    if(input==' '){
        scanf("%c",&input);
    }
    int dest=input-'0';
    dest=val_to_key(dest,vals,n);
    if(dist[src][dest]==INF){
        return -1;
    }
    return dist[src][dest];
}
int val_to_key(int val,int* vals,int n){
    for(int i=0;i<n;i++){
        if(*(vals+i)==val){
            return i;
        }
    }
    return -1;
}

int is_exist(int val,int *vals,int n){
    for(int i=0;i<n;i++){
        if(val==*(vals+i)){
            return 1;
        }
    }
    return -1;
}