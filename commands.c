#include "commands.h"

/**
 * Note this file is to contain console output,
 * meaning printf's are expected to be seen in this file.
 */

AddressBookList * commandLoad(char * fileName)
{
    /**
     * Loads the given file and returns a new AddressBookList.
     *
     * If the file doesn't exist or corruption is found in the file
     * then NULL is returned.
     */

     FILE *data;
     printf("> Loading the file ... \n");
     if((data = fopen(fileName, "r"))!=-1) {
    	char parsedLine[100];
    	while (fgets(parsedLine, 140, data) != NULL) {
    			if(parsedLine[0]=='#')
			{
			   continue;
			} else
			{
				char *getId = strtok(parsedLine, ", ");
    				char *getName = strtok(NULL, ", ");
				char *getTelephone = strtok(NULL,", ");
				/*int i=0;
    				while(((*getTelephone)[i] = strtok(NULL, ", "))!=-1)
				i++;*/
			printf("%s - %s - %s \n",getId,getName,getTelephone);
		}}
	fclose(data);
    } else {
 	 printf("> Error: The specified file is in the wrong format and cannot be loaded.\n");
	}
    return NULL;
}

void commandUnload(AddressBookList * list)
{ }

void commandDisplay(AddressBookList * list)
{ }

void commandForward(AddressBookList * list, int moves)
{ }

void commandBackward(AddressBookList * list, int moves)
{ }

void commandInsert(AddressBookList * list, int id, char * name, char * telephone)
{ }

void commandAdd(AddressBookList * list, char * telephone)
{ }

void commandFind(AddressBookList * list, char * name)
{ }

void commandDelete(AddressBookList * list)
{ }

void commandRemove(AddressBookList * list, char * telephone)
{ }

void commandSort(
    AddressBookList * list,
    int sort(const void * node, const void * otherNode))
{
    /* Sort the nodes within list in ascending order using the
     * provided sort function to compare nodes.
     */
}

int compareName(const void * node, const void * otherNode)
{
    /* Compare node name with otherNode name.
     *
     * return < 0 when node name is smaller than otherNode name.
     * return 0 when the names are equal.
     * return > 0 when node name is bigger than otherNode name.
     */
    return 0;
}

int compareID(const void * node, const void * otherNode)
{
    /* Compare node id with otherNode id.
     *
     * return < 0 when node id is smaller than otherNode id.
     * return 0 when the ids are equal.
     * return > 0 when node id is bigger than otherNode id.
     */
    return 0;
}

void commandSave(AddressBookList * list, char * fileName)
{ }
