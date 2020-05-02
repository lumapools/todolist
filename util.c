#include <stdio.h>
#include "util.h"
#include <string.h>

void print_line(void) {
    printf("|-------------------------------------------------------------------\n");
}

void print_subjects(void) {
	FILE* file = fopen(FILE_LIST, "r");
	char line[MAX_STR_SIZE];
	print_line();
	printf("|   ######### SUBJECTS #########\n");
	do{
		fgets(line, MAX_STR_SIZE, file);
		if(feof(file)) {break;}
		correct(line);
		printf("|   #    %-22s#\n", line);
	} while(!feof(file));
	printf("|   ############################\n");
	print_line();
	fclose(file);
}

int isFileEmpty(char filename[]) {
	FILE* file = fopen(filename, "r");
	char first;
	if((fscanf(file, "%c", &first)) == EOF) { 
		fclose(file);
		return TRUE;
	}
	fclose(file);
	return FALSE;
}


char parse_answer(char read[]) {
    char str[1];
    str[0] = read[0];
    if(read[1] != '\n') {return 'X';}
    if(strcmp(str, "Y") == 0) {return 'Y';}
    else if(strcmp(str, "N") == 0) {return 'N';}
    else if(strcmp(str, "n") == 0) {return 'n';}
    else if(strcmp(str, "y") == 0) {return 'y';}
    else {return 'X';}
}


void print_nonempty_subjects(void) {
	printf("|   ######### SUBJECTS #########\n");
	FILE* file = fopen(FILE_LIST, "r");
    char line[MAX_FILENAME_SIZE];
    do{
        fgets(line, MAX_STR_SIZE, file);
        if(feof(file)) {break;}
        correct(line);
		if(isFileEmpty(line) == FALSE) {
        	printf("|   #    %-22s#\n", line);
		}
    } while(!feof(file));
	
	fclose(file);
	printf("|   ############################\n");
}

int allEmpty(void) {
	FILE* all_files = fopen(FILE_LIST, "r");
	char line[MAX_FILENAME_SIZE];
	while(!feof(all_files)) {
		fgets(line, MAX_FILENAME_SIZE, all_files);
		correct(line);
		if(isFileEmpty(line) == FALSE) {
			return FALSE;
		}
	}
	return TRUE;
}	

void correct(char filename[]) {
    for(int i = 0; i < MAX_FILENAME_SIZE+1; i++) {
        if(filename[i] == '\n') {
            filename[i] = '\0';
            return;
        }
    }
}

int file_exists(char filename[]) {
    FILE* all_files = fopen(FILE_LIST, "r");
    char line[MAX_STR_SIZE];
    while(!feof(all_files)) {
        fgets(line, MAX_STR_SIZE, all_files);
        correct(line);
        if(strcmp(line, filename) == 0) {
            fclose(all_files);
            return TRUE;
        }
    }
    fclose(all_files);
    return FALSE;
}

void print_subject_name(char subject[], int withEndline) {
	char copied[MAX_STR_SIZE];
	strncpy(copied, subject, MAX_STR_SIZE);
	correct(copied);

	long int length = strlen(copied);

	long int magic_number = (SUBJECT_TITLE_SIZE - length - 2)/2;
	printf("|  ");	
	for(int i = 0; i < magic_number; i++) {
		printf("#"); 		
	}
	printf(" ");
	printf("%s", copied);
	printf(" ");
	if(length % 2 != 0) {
		printf("#");
	}
	for(int i = 0; i < magic_number; i++) {
		printf("#");
	}
	if(withEndline == TRUE) {
		printf("\n");
	}
}

int line_count(char file[]) {
	char line[MAX_STR_SIZE];
	FILE* f_toCount = fopen(file, "r");
	if(f_toCount == NULL) {
		printf("Some files are missing.\n");
		return -1;
	}	
	int count = 0;
	while(!feof(f_toCount)) {
		fgets(line, MAX_STR_SIZE, f_toCount);
		if(!feof(f_toCount)) {
			count++;
		}	
	}
	return count;
}
