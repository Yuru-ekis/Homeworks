#include<stdio.h>

char josephOrderArray [30];
int n = 0; // n Ϊ�������� n <= 30

struct Node {
    int number; 
    int keyword;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *current = NULL;
struct Node *activeNode = NULL;

int currentInOrderArray = 0;

void insertFirst(int number, int keyword) 
{
   //create a link
   struct Node *link = (struct Node*) malloc(sizeof(struct Node));
	
   link->number = number;
   link->keyword = keyword;
	
   //point it to old first node
   current -> next = link;
	
   //point first to new first node
   current = link;
}

int deleteNode(int m, struct Node *previous, struct Node *activeHead)
{

    activeNode = activeHead;
    for (int i = 1; i < m; i++)
    {
        activeNode = activeNode -> next;
        previous = previous -> next;
    }
    josephOrderArray[currentInOrderArray] = activeNode -> number;
    previous -> next = activeNode -> next;
    
    currentInOrderArray = currentInOrderArray + 1;
    if (currentInOrderArray == n )
    {
        return 0;
    }
    
    deleteNode(activeNode -> keyword, previous, activeNode);

}

int main() 
{
    int m = 0; // m �ǳ�ʼ��������ֵ
    
    int is_n_InputLegal = 0;
    int password = 0;
    current = (struct Node*) malloc(sizeof(struct Node));
    head = current;

    printf("����������: ");
    do
    {   
        scanf("%d", &n);
        if (n <= 0)
        {
            printf("Illegal Argument! Please Input Again!\n");
        } else if ( (n > 0) && (n <= 30) )
        {
            is_n_InputLegal = 1;
        }
        
        
    } while (is_n_InputLegal == 0);
    
    
    printf("�������ʼ��������ֵ: ");
    scanf("%d", &m);
    printf("������ÿ���˵����룬һ��һ��: ");
    scanf("%d", &password);
    head -> number = 1;
    head -> keyword = password;
    for (int i = 2; i < (n+1); i++)
    {
        scanf("%d", &password);
        insertFirst(i, password);
    }
    current -> next = head;
    deleteNode(m, current, head);
    printf("����˳��Ϊ: \n");
    for (int i = 0; i < currentInOrderArray; i++)
    {
        printf("%d ", josephOrderArray[i]);
    }
    

    return 0;
}
