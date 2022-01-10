int* add_node(int *graph,int n,int *values,char *curinput,int* exist);
int* remove_node(int *graph,int n,int k,int *vals);
int shortest_path(int *graph,int n,int *vals);
int tsp();
char set_node(int *graph,int n,int srcId);
int val_to_key(int val,int* vals,int n);
int is_exist(int val,int *vals,int n);