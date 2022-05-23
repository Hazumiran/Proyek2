#include "linkedlist.h"

//Membuat Head
List *CreateHead(){
    List *list = (List *)malloc(sizeof(List));
    list->head = NULL;
    return list;
}

//Pengalokasian Node
Node *CreateNode(int value){
    Node *node = (Node *)malloc(sizeof(Node));
    node->next = NULL;
    node->prev = NULL;
    node->data = value;
    return node;
}

//Dealokasi Node
void DeAlokasi(Node *node){
	node->next = NULL;
	node->prev = NULL;
	free(node);
}

//Insert node dan menghubungkannya0
int insertNode(List *list, Node *node, int index){
    if(index == 0)
    {
        node->next = list->head;
        list->head = node;
    }
    else
    {
        if(index > (listLength(list)))
        index =-1;
            
        node->prev = getNode(list, index - 1);
        node->next = node->prev->next;
        node->prev->next = node;

    }
    return 0;
}

//menghapus node diakhir
int removeNode(List *list, Node *node){
    int indx = 0;
    Node *temp = NULL;
    for(temp = list->head; NULL != temp; temp = temp->next)
    {
        if(temp == node)
        {
            node->prev = getNode(list, indx - 1);
            node->prev->next = node->next;
            DeAlokasi(node);
            break;
        }
        ++indx;
    }
    return 0;
}

//menghapus Sesuai keinginan(index) dan menghubungkannya
int removeNodeByIndex(List *list, int index){
    if(index > listLength(list))
        index =-1;

    if(getNode(list, index) == NULL)
        index =-1;
        	
    if(index == 0)
    {
    	Node *tamp = getNode(list, index);
    	if(tamp->next == NULL){
	    	list->head = list->head->next;
	        free(list->head);
		}
		else{
			list->head = list->head->next;
	        free(list->head->prev);
		}

        return 0;
    }

    Node *before = getNode(list, index - 1);
    Node *to_remove = before->next;

    before->next = to_remove->next;
    free(to_remove);

    return 0;
}

//menghitung panjang semua kata 
int listLength(List *list){
    int len = 0;
    Node *temp = NULL;
    for(temp = list->head; NULL != temp; temp = temp->next)
    {
        ++len;
    }
    return len;
}

//mencari node dari index
Node * getNode(List *list, int index){
    if(index > listLength(list))
        return NULL;

    Node *temp = list->head;
    for(int i = 0; i < index; ++i)
    {
        temp = temp->next;
    }

    return temp;
}

//menampilkan satu baris
//void printList(List *list){
//    Node *temp = NULL;
//    for(temp = list->head; NULL != temp; temp = temp->next)
//    {
//        printf("[%d]->", temp->data);
//    }
//    printf("[NULL]\n");
//}

//menghapus baris
int deleteList(List * list){

    Node * freeme = list->head;
    Node * next = freeme;
    while(NULL != freeme)
    {
        next = freeme->next;
        DeAlokasi(freeme);
        freeme = next;
    }
    free(list);

    return 0;
}
