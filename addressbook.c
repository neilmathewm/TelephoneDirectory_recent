#include "addressbook.h"
#include "commands.h"
#include "addressbook_list.h"
#include<stdlib.h>
#include<string.h>
/**
* This file is to contain the main menu loop and thus it will have console
* output, meaning printf's are expected to be seen in this file.
*
* After the user enters a command, then the corresponding function is to be
* called from commands.c, e.g., "forward" corresponds to "commandForward(...)".
*/
struct addressBook
{
    int id;
    char name[20];
    char telephone_no[50];
    struct addressBook * previousNode; /* The previous node in the linked-list */
    struct addressBook * nextNode; /* The next node in the linked-list */
} *start=NULL,*temp=NULL,*temp2=NULL;
char array_of_string[10][6]; /* 10 strings of a maximum of 5 characters each, plus the NUL */
char msg[50];
/* now split the msg and put the words in array_of_string */
int string_num = 0;
int word_size = 0;
int msg_index = 0;
int x,c,m,n,o,i,n,count1,id_int;

FILE *fptr;
AddressBookList *a;
int main(int argc, char ** argv)
{
  /** ----------------------------Format-------------------------------
    * -----------------------------------------------------------------
    * Student name: Firstname Lastname
    * Student number: 1234567
    * Advanced Programming Techniques, Assignment Two, Semester 1, 2017
    * -----------------------------------------------------------------
  */
    char str[50],id[10],name[20],telephone[20];
    printf("-----------------------------------------------------------------\n");
    printf("Student name: Ashish John\n");
    printf("Student number: s3624455\n");
    printf("Advanced Programming Techniques, Assignment Two, Semester 1, 2017\n");
    printf("----------------------------------------------------------------- \n");
    do
    {
      printf("\n\nEnter your command : ");
      scanf(" %[^\n]",msg);
     string_num=0;
	word_size=0;
	msg_index=0;
	      while (msg[msg_index] != '\0') {
        if (msg[msg_index] != ' ') {
            /* add the character to the proper place in array_of_string */
            array_of_string[string_num][word_size] = msg[msg_index];
            array_of_string[string_num][word_size+1] ='\0';
            /* and update word_size for next time through the loop */
            word_size++; /* needs check for reserved word size (5) */
               } else {
            /* a space! */
            /* first, terminate the current word */
            array_of_string[string_num][word_size] = '\0';
            /* prepare to start the next word */
            string_num++; /* needs check for reserved number of "strings" (10) */
            word_size = 0;

        }
	msg_index++;
    }


        if(strcmp(array_of_string[0],"load")==0) {
            printf("> Opening the file %s",array_of_string[1]);
            fptr = fopen(array_of_string[1], "r");
            if (fptr == NULL)
                {
                printf("Cannot open file \n");
                }
            c=0;
            printf("\n>Loading the file ...");
            // Read contents from file
            while (fscanf(fptr, " %[^\n]", str)!=EOF)
              {
              c++;
              m=0;
              n=0;
              i=0;
              o=0;
              count1=0;
              if(str[0]!='#')
                {
                    while(str[i]!='\0')
                    {
                        if(str[i]!=','&&count1==0)
                            {id[m++]=str[i];
                             id[m]='\0';
                            }
                         else if(str[i]==','&&count1<2)
                                count1++;
                         else if(count1==1)
                            {
                             name[n++]=str[i];
                             name[n]='\0';
                            }
                        else if(count1>=2)
                            {
                            telephone[o++]=str[i];
                            telephone[o]='\0';
                            }
                    i++;
                    }
                    id_int = atoi (id);
                    Insert(id_int,name,telephone);
                    //printf("%d--%s--%s--",id_int,name,telephone);
                }
              }

              printf("\n>%d phone book entries have been loaded from the file.",c);
              printf("\n> Closing the file.");
              fclose(fptr);
            }
            else if(strcmp(array_of_string[0],"display")==0)
            {
                 display();
            }
            else if(strcmp(array_of_string[0],"unload")==0)
            {
                unload();
            }
            else if(strcmp(array_of_string[0],"save")==0)
            {
            save(array_of_string[1]);
            }


    } while(strcmp(array_of_string[0],"quit"));
    printf("> Goodbye. \n\n");
    return EXIT_SUCCESS;
}
void Insert(int id,char name[20],char telephone[20])
{
 struct addressBook *newn=(struct addressBook*)malloc(sizeof(struct addressBook));
 newn->id=id;
 strcpy(newn->name,name);
 //printf("%s",telephone);
 strcpy(newn->telephone_no,telephone);


 if(start==NULL)
         {
         newn->previousNode=NULL;
         newn->nextNode=NULL;
         start=newn;
        }
 else
        {
        temp=start;
        while(temp->nextNode!=NULL)
                temp=temp->nextNode;
        temp->nextNode=newn;
        newn->previousNode=temp;
        newn->nextNode=NULL;
        }
}
void display()
{

    if(start==NULL)
        printf("NO ELEMENTS FOUND");
else
        {
        temp=start;
        printf("\nID\tNAME\tPHONE\n\n");
        while(temp->nextNode!=NULL)
                {
                printf("\n%d\t%s\t%s",temp->id,temp->name,temp->telephone_no);
                temp=temp->nextNode;
                }
        printf("\n%d\t%s\t%s",temp->id,temp->name,temp->telephone_no);
        }
}
void save(char filename[50])
{
    FILE * file= fopen(filename, "w");
if (file != NULL) {
     if(start==NULL)
        printf("NO ELEMENTS FOUND");
else
        {
        temp=start;
        while(temp->nextNode!=NULL)
                {
                fprintf(file, "%d  %s   %s\n",temp->id,temp->name,temp->telephone_no);
                printf("\n%d\t%s\t%s",temp->id,temp->name,temp->telephone_no);
                temp=temp->nextNode;
                }
            fprintf(file, "%d  %s   %s\n",temp->id,temp->name,temp->telephone_no);
        }

fclose(file);
    }
}
void unload()
{
   if(start==NULL)
        printf("NO ELEMENTS FOUND");
else
        {
        temp=start;
        while(temp->nextNode!=NULL)
                {
                temp2=temp;
                temp=temp->nextNode;
                free(temp2);
                }
                free(temp);
        start=NULL;
        }

}
