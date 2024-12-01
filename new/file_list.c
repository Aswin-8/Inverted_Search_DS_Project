#include "inverted_search.h"

void file_validation_n_file_list(Flist **f_head, char *argv[])
{
    int i = 1 , empty;
    while(argv[i] != NULL)                     //checking all command line arguments
    {
		empty = isFileEmpty(argv[i]);                   //checking file is empty
		if(empty == FILE_NOTAVAILABLE )
		{
			printf("FIle : %s is not available \n" , argv[i]);
			printf("Hence we are not adding that file into file linked list\n");     //printing error message
			i++;
			continue;
		}
		else if(empty == FILE_EMPTY)
		{
			printf("FIle : %s is not having any content \n" , argv[i]);
			printf("Hence we are not adding that file into file linked list\n");
			i++;
			continue;
		}
	else
	{
	    int ret_val = to_create_list_of_files(f_head , argv[i]);

	    if(ret_val == SUCCESS )
	    {
			printf("Successfull : inserting the file name %s into file linked list\n" , argv[i]);
	    }
	    else if (ret_val == REPEATATION)
	    {
			printf("THis file name : %s is repeated\n" , argv[i]);
			printf("Hence we are not adding that file\n");
	    }
	    else
	    {
			printf("Failure\n");
	    }

	    i++;
	    continue;
	}
    }
}

//fun will check for file availability anf checks for file content
int isFileEmpty(char *filename)
{
    FILE *fptr = fopen(filename , "r");

    if(fptr == NULL)
    {
		if(errno == ENOENT)               //file not present
		{
	    	return FILE_NOTAVAILABLE;
		}
    }
    //check for contents

    fseek(fptr , 0 , SEEK_END);
    if(ftell(fptr) == 0)                   //ftell value is 0 then file is empty
    {
		return FILE_EMPTY;
    }
}

 int to_create_list_of_files(Flist **f_head, char *name)
{
   Flist *temp=*f_head;
   while(temp)
   {
		if(strcmp(temp->file_name,name)==0)              //comparing file name
		{
			return REPEATATION;                          //if file names are repeated
		}
		temp=temp->link;
   }
    FILE *fptr;
	char word[10];
	fptr=fopen(name,"r");
	fscanf(fptr,"%s",word);
	fclose(fptr);
	if(!(strncmp(word,"#[",2)))
	{
		return BACKUP;
	}
   Flist *new=malloc(sizeof(Flist));                   //dynamically allocating memory
   strcpy(new->file_name,name);                      //copying file name to new
	new->link=NULL;
   if(*f_head==NULL)
   {
		*f_head=new;
		return SUCCESS;
   }
   else
   {
   		Flist *t1=*f_head;
   		while(t1->link!=NULL)
   		{
			t1=t1->link;
   		}
		t1->link=new;                                 //updating new in last node
		return SUCCESS;
   }
}














