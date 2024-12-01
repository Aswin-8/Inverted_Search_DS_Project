#include "inverted_search.h"

char *fname;

void create_database(Flist *f_head, Wlist *head[])
{
    //traverse through the file linked list
    while(f_head)
    {
		
		read_datafile(f_head , head , f_head->file_name);               //calling the read_datafile function file number of times
		f_head = f_head->link;
    }
	printf(" DATABASE created successfully\n");
}

 Wlist * read_datafile(Flist *file, Wlist *head[], char *filename)
{
	
    fname = filename;
    
    //open the file read  mode 

    FILE *fptr = fopen(filename , "r");

    //declare an array to store the word
    char word[WORD_SIZE]={};

    while(fscanf(fptr , "%s" , word) != EOF)
    {
		int flag = 1;
		//index 
		int index = tolower(word[0]) % 97;

		//other than alphabet 
		if(!(index >= 0 && index <= 25))
			index = 26;

		//word is repeated or not

		if(head[index] != NULL)
		{
			Wlist *temp = head[index];
		//compare the words of each node with new word
		
			while(temp)
			{
				if(!strcmp(temp->word,word))             
				{	
					update_word_count(&temp , filename);
					flag = 0;
					break;
				}
				temp = temp->link;
			}
		}
		if(flag == 1)
		{
			//if words are not repeated
				insert_at_last(&head[index] , word);         //calling insert at last function
				
		}
	}
	fclose(fptr);                 //closing the file pointer
}

int update_word_count(Wlist ** head, char * file_name)
{
    Ltable *t1=(*head)->Tlink;
	while (t1 != NULL)			
		{
			if (strcmp (t1->file_name,file_name) == 0)	//checking if filenames are equal
			{
				t1->word_count += 1;	//Incrementing word count by 1
				return SUCCESS;
			}

			t1 = t1->table_link;    	//Update the 't1 to point to the Next node.
		}

	Ltable *temp=(*head)->Tlink;
	Ltable *new = malloc(sizeof(Ltable));           //dynamically allocating memory
	new->table_link=NULL;
	strcpy(new->file_name,file_name);                  //storing filename
	if(new==NULL)
		return FAILURE;
	else
	{
		(*head)->file_count+=1;                     //incrementing word and file count
		new->word_count++;
	}
	if((*head)->Tlink==NULL)
	{
		(*head)->Tlink=new;                         //updating head of tlink with new
		return SUCCESS;            
	}
	temp=(*head)->Tlink;                            //traversing throug list
	while(temp->table_link)
    {
	
		temp = temp->table_link;
    } 
    temp->table_link = new;                             //updating new at the last node
	return SUCCESS;	
}












