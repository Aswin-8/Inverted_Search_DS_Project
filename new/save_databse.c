#include "inverted_search.h"

void save_database( Wlist *head[])
{
    int i=0;
    char file_name[FNAME_SIZE];
    printf("enter the file name\n");
    scanf("%s" , file_name);

    // open file
    FILE *fptr = fopen(file_name , "w" );                      //opening the file in write mode inorder to save
    if(fptr==NULL)
        return;
    for(i = 0; i< 27; i++)
    {
	    if(head[i] != NULL)                                          //checking if head is empty
	    {
	         write_databasefile(head[i] , fptr);
	    }
    }
    printf("Database saved\n");
    fclose(fptr);
}

void write_databasefile(Wlist *head, FILE* databasefile)

{
    Wlist *temp = head;
    while(temp)
    {
        int index = tolower(temp->word[0]) % 97;             //converting the first letter of the word into index
				if(!(index>=0 && index <=25))
            		index=26;                                   //if the first letter is not a alphabet then index is 26
        fprintf(databasefile,"#[%d]\n",index);              //writing index to file
        fprintf(databasefile,"word is [%s] : file count is [%d] : file is [%s] word count is [%d]\n",temp->word,temp->file_count,temp->Tlink->file_name,temp->Tlink->word_count);
        if(temp->Tlink->table_link!=NULL)
        {
            temp->Tlink=temp->Tlink->table_link;                       //traversing through the list
            while(temp->Tlink)
            {
                fprintf(databasefile,"file is [%s] : word count is [%d]\n",temp->Tlink->file_name,temp->Tlink->word_count);         //writing all word count and file name of the word
                temp->Tlink=temp->Tlink->table_link;                               //traversing through the list
            }
        }
        temp=temp->link;
    }
}

	





