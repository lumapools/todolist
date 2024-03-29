#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "util.h"
#include "remove_todo_helpers.h"
#include "print_subject_helpers.h"


void delete_todo(char subject[], char* username) {

	M_RET_IF_TRUE(missing(subject));
	print_full_subject(subject);
	int del_id;
	printf("| Bot> Enter the number of the todo you want to delete.\n");
	print_line();
	char line[MAX_STR_SIZE];
	int accepted = 0;

	M_RET_IF_TRUE(missing(subject));
	M_RET_IF_TRUE(missing(FILE_LIST));

	do {
		printf("| %s> (%s to exit): ", username, EXIT_CODE);
		fgets(line, MAX_STR_SIZE, stdin);
		if(isNumber(line) == TRUE) {
			del_id = atoi(line);
			accepted = 1;
		}
		else if(isX(line) == TRUE) {
			return;
		}
	} while(accepted == 0);
	print_line();

	M_RET_IF_TRUE(missing(FILE_LIST));
	M_RET_IF_TRUE(missing(subject));

	if(todoIdExists(subject, del_id) == FALSE) {
		printf("| Bot> The number you entered does not match any todo. Aborted.\n");
		return;
	}
	
	remove_todo(subject, del_id);
	printf("| Bot> Todo removed successfully.\n");
	
	if(isFileEmpty(subject) == TRUE) {
		printf("| Bot> %s is now empty.\n", subject);
		return;
	}	

	printf("| Bot> Do you want to remove another todo from %s?\n", subject);
	M_RET_IF_TRUE(missing(FILE_LIST));
	M_RET_IF_TRUE(missing(subject));
	if(confirm(username) == TRUE) {
		delete_todo(subject,username);
	}
 
}

void print_full_subject(char toPrint[]) {
	FILE* f_subj = fopen(toPrint, "r");
	int lineId;
	char separator;
	char todo[MAX_STR_SIZE];
	char dummy[MAX_STR_SIZE];
	print_subject_name(toPrint, FALSE);
	printf("########");
	printf("\n");

	while(!feof(f_subj)) {
        fscanf(f_subj, "%d", &lineId);
        fscanf(f_subj, "%c", &separator);
        fgets(todo, MAX_STR_SIZE, f_subj);
        strncpy(dummy, todo, MAX_TODO_SIZE);
        for(int i = 0; i < MAX_TODO_SIZE; i++) {
            if(dummy[i] == '\n') {
                dummy[i] = '\0';
                break;
            }
        }
        if(!feof(f_subj)) {
            printf("|  # %-6d: %-42s #\n", lineId, dummy);
        }
    }
    printf("|  ");
    for(int i = 0; i < SUBJECT_TITLE_SIZE+8; i++) {
        printf("#");
    }
	fclose(f_subj);
    printf("\n");
}


int isNumber(char str[]) {
	char currentChar = 'X';
	int index = 0;
	if(str[0] == '\n') {return FALSE;}
	while(currentChar != '\n') {
		currentChar = str[index];
		if(currentChar == '\n') {
			break;
		}
		index++;
		if(currentChar < 48 || currentChar > 57) {
			return FALSE;
		}
	}
	return TRUE;
}

int isX(char str[]) {
	if(str[0] == 'X' && str[1] == '\n') {
		return TRUE;
	}
	if(str[0] == 'X' && str[1] == '\0') {
		return TRUE;
	}
	return FALSE;
}


int todoIdExists(char subject[], int id) {
	FILE* f_subj = fopen(subject, "r");
	int currentId;
	char dummy[MAX_STR_SIZE];
	while(!feof(f_subj)) {
		fscanf(f_subj, "%d", &currentId);
		fgets(dummy, MAX_STR_SIZE, f_subj);
		if(currentId == id) {
			fclose(f_subj);
			return TRUE;
		}
	}
	fclose(f_subj);
	return FALSE;
}

void remove_todo(char subject[], int id) {
	FILE* f_subj = fopen(subject, "r");
	FILE* f_swap = fopen(FILE_SWAP, "w");
	
	char text[MAX_STR_SIZE];
	int currentId;
	while(!feof(f_subj)) {
		fscanf(f_subj, "%d", &currentId);
			if(feof(f_subj)) {
				break;
			}
		fgets(text, MAX_STR_SIZE, f_subj);
		if(currentId != id) {
			fprintf(f_swap, "%d%s", currentId, text);
		}
	}
	fclose(f_subj);
	fclose(f_swap);	

	remove(subject);
	rename(FILE_SWAP, subject);
	remove(FILE_SWAP);
}












