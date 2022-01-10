#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "define_func.h"
int main(){
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
            
            scanf("%c",&input);
            if(input==' '){
                scanf("%c",&input);
            }
            graph= remove_node(graph,n,(int)(input-'0'),values);
            n--;
        }else if(input=='S'){

            printf("%d",shortest_path(graph,n,values));
            scanf("%c",&input);
        }else if(input=='T'){

        }else{
            break;
        }
        if(isdigit(input)!=0){
            scanf("%c",&input);

        }
    }
   
    free(graph);
    free(values);
    return 0;
}