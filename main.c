#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "define_func.h"
int main(){
    printf(" new in main");
    char input;
    int n;
    int* graph;
    int* values;
    scanf("%c",&input);

    while(input!='!'){
        if(input==' '){
            scanf("%c",&input);

        }
        if(input=='A'){
            printf("in A");

            scanf("%c",&input);
            if(input==' '){
                scanf("%c",&input);
            }
            n=input-'0';
            graph=(int*)malloc(sizeof(int)*n*n);
            for(int i=0;i<n*n;i++){
                *(graph+i)=-1;
            }
            values=(int*)malloc(sizeof(int)*n);
            for(int i=0;i<n;i++){
                *(values+i)=i;
            }
            

        }else if(input=='n'){
            input=set_node(graph,n,-1);
        }else if(input=='B'){
            printf("in B");
            n++;
            char* curinput;
            int a=0;
            int* exist=&a;
            graph =add_node(graph,n,values,curinput,exist);
            if(*exist==1){
                n--;
            }
            input=*curinput;
            
            
        }else if(input=='D'){
            printf("in D");
            printf("\nsize of:%d\n",n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",*(graph+i*n+j));
        }
        printf("\n");
    }
            scanf("%c",&input);
            if(input==' '){
                scanf("%c",&input);
            }
            remove_node(graph,n,(int)input,values);
            n--;
        }else if(input=='S'){
            printf("in S");

            printf("%d",shortest_path(graph,n,values));
            scanf("%c",&input);
        }else if(input=='T'){
            printf("in T");

        }else{
            break;
        }
        if(isdigit(input)!=0){
            scanf("%c",&input);

        }
    }
    printf("\nsize of:%d\n",n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",*(graph+i*n+j));
        }
        printf("\n");
    }
    free(graph);
    free(values);
    return 0;
}