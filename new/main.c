#include "inverted_search.h"

int main(int argc , char *argv[])
{
    system("clear");

    Wlist *head[27] = {NULL};                  //initialising with NULL
	int choice;
	char word[WORD_SIZE];

    //validate CLA
    if(argc <= 1)                                       //Checking the argument count
    {
		printf("Enter the valid no. arguments\n");
		printf("./Slist.exe file1.txt file2.txt .........\n");
		return 0;
    }

    //declare head pointer

    Flist *f_head = NULL;

    //file validation

    file_validation_n_file_list(&f_head , argv);

    if(f_head == NULL)                    //checking if any files are added
    {
		printf("No files added to file linked list\n");
		printf("Hence process got terminated\n");
		return 0;
    }
	do
	{
		printf("\tSelect your choice among following options:\n");
		printf("1.Create DATABASE\n");
		printf("2.Display DATABASE\n");
		printf("3.Update DATABASE\n");
		printf("4.Search\n");
		printf("5.Save DATABASE\n");
		printf("6.Exit\n");
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:create_database(f_head , head);
					break;
			case 2:display_database(head);
					break;
			case 3:update_database(head,&f_head);
					break;
			case 4:printf("Enter the word to be searched\n");
				getchar();
				scanf("%s",word);
				int index = tolower(word[0]) % 97;             //converting the first letter of the word into index
				if(!(index>=0 && index <=25))
            		index=26;                                   //if the first letter is not a alphabet then index is 26
				search(head[index],word);
					break;
			case 5:save_database(head);
					break;
			case 6:printf("Exit");
					break;
			default:printf("Enter a valid choice\n");
		}

	} while (choice>=1 && choice <=5);

}

































