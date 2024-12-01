#include "inverted_search.h"

int insert_at_last(Wlist **head, data_t *data)
{
    //create node 

    Wlist *new = malloc(sizeof(Wlist));             //dynamically allocating memory

    //error check

    if(new == NULL)                                  //checking if memory is allocated or not
    {
	    return FAILURE;
    }

    //update
    new->file_count =  1;
    strcpy(new->word,data);                            //updating filecount ,word ,tlink and link fiels of new
    new->Tlink = NULL;
    new->link = NULL;

    //call fun to update link table

    update_link_table(&new);

    //check Wlist is empty or not

    if(*head == NULL)                             //checking if list is empty
    {
	    *head = new;
	    return SUCCESS;
    }
    //not empty

    Wlist *temp = *head;

    //traverse through WList

    while(temp->link)
    {
	    temp = temp->link;                                    //traversing through list
    }
        temp->link = new;                                    //updating new at last node
    return SUCCESS;

}

 int update_link_table(Wlist **head)
{
    //create a node
    extern char *fname;
    Ltable *new = malloc(sizeof(Ltable));                                //dynamically allocating memory

    //error check
    if(new == NULL)
    {
	    return FAILURE;                                                   //checking if memory is allocated or not
    }

    //UPDATE 
    new->word_count = 1;
    strcpy(new->file_name,fname);                                       //updating the fields of new
    new->table_link = NULL;
    if((*head)->Tlink==NULL)               //if head->Tlink is null then only updating new
    (*head)->Tlink = new;
}























