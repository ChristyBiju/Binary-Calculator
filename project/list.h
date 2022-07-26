typedef struct node{
    char data;
    struct node*next;
    struct node*prev;
}node;

typedef node* list;

void init(list L);
node* append(list L,char d);
node* insertbeg(list L,char d);
void traverse(list L);
node* destroy(list L);
node* tail(list L);