#include "inverted_search.h"

void display_database( Wlist *head[] )
{
    printf("[index]     [word]    file_count file/s    File: File_name    word_count\n");

   for(int i = 0; i < 27; i++)
   {
       if(head[i] != NULL)                         //checking if head is empty
       {
	       print_word_count(head[i]);                 //calling the print word count function 
       }
   }
   return ;
}
 int print_word_count(Wlist *head)
{
    //traverse through WList 
    while(head != NULL)
    {
        int count=(tolower(head->word[0]) % 97);         //converting the first letter into index number
        if(!(count>=0 && count <=25))
            count=26;                                  //if it is not alphabet then index value is 26
	    printf(" [%d] \t    [%s] \t %d \t file/s" , count , head->word , head->file_count);
	    Ltable *Thead = head->Tlink;
	//traverse

	    while(Thead)
	    {
	        printf("\tFile : \t %s  \t %d" , Thead->file_name , Thead->word_count);         //printing file name and word count
	        Thead = Thead->table_link;
	    }
        printf("\n");
        head = head->link;                        //traversing through list
    }
}























