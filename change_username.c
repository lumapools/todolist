#include <stdio.h>
#include "change_username.h"
#include "util.h"
#include <string.h>

int proc_usrn(void) {

	char username[USERNAME_SIZE];
    FILE* file_usr = fopen(FILE_USERNAME, "r");
    fscanf(file_usr, "%s", username);
    fclose(file_usr);

	char newUsername[MAX_STR_SIZE];

	printf("| Bot> Enter a new username (max %d characters).\n", USERNAME_SIZE);
	
	do {
		printf("| %s> (new username, EXIT to abort): ", username);
		fgets(newUsername, MAX_STR_SIZE, stdin);

	} while(strlen(newUsername) > USERNAME_SIZE+1);

	for(int i = 0; i < USERNAME_SIZE+1; i++) {
        if(newUsername[i] == '\n') {
            newUsername[i] = '\0';
            break;
        }
    }

		

	if(strcmp(newUsername, EXIT_CODE) == 0) {
		printf("| Bot> No changes.\n");
		return FALSE;
	}

	file_usr = fopen(FILE_USERNAME, "w");
	fprintf(file_usr, "%s\n", newUsername);
	fclose(file_usr);

	printf("| Bot> Username changed to '%s'.\n", newUsername);
	return TRUE;
}