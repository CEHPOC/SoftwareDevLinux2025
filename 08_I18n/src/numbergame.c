#include <stdio.h>
#include <string.h>
#include <libintl.h>
#include <locale.h>
#include <stdlib.h>
#include "config.h"

#define _(STRING) gettext(STRING)
#define LOCALE_PATH "."

int guess_common(int left, int right){
	char answer[100];
	while(left<=right){
		int mid = (left+right)/2;
		if(left == right){
			return left;
		}
		else{
			printf(_("Your number more than %d? (Yes/No)"), mid);
			if (fgets(answer, 100, stdin) == NULL) {
            			printf(_("Error: stdin is closed\n"));
				return -1;
        		}
			answer[strcspn(answer, "\n")] = '\0';
			if (strcmp(answer, _("Yes")) != 0 && strcmp(answer, _("No")) != 0) {
            			printf(_("Error: Only 'Yes' or 'No' is allowed\n"));
            			continue; 
			}
			if (strcmp(answer, _("Yes")) == 0) {
				left = mid + 1;
            			continue; 
			}
			if (strcmp(answer, _("No")) == 0) {
				right = mid;
            			continue; 
			}
		}
	}
	return -1;
}	

int main(int argc, char *argv[]){

	setlocale(LC_ALL, "");
	bindtextdomain(PACKAGE, LOCALE_PATH);
	textdomain(PACKAGE);

	int left = 1;
	int right = 100;
	printf(_("Guess a number from %d to %d\n"), left, right);
	int res = guess_common(left, right);
	if(res == -1){
		return 1;
	}
	printf(_("Your number: %d\n"), res);
	return 0;
}
