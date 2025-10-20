#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>

#define MAXGR 10

int print_substitution(char *sub, char *text, regmatch_t *bags){

	int len = strlen(sub);
	char *p = sub;
	while(*p != '\0'){
		if(*p == '\\'){
			p++;
			if(*p == '\\'){
				len--;
			}
			else if(*p >= '0' && *p <= '9'){
				int ref = *p-'0';
				if(bags[ref].rm_so == -1){
					fprintf(stderr, "Error: backreference \\%d does not exist\n", ref);
                    			return 1;
				}
				len+=bags[ref].rm_eo-bags[ref].rm_so-2;
			}
			else{
				len--;
			}
		}
		p++;
	}
	char *res = malloc(strlen(text)-bags[0].rm_eo+bags[0].rm_so+len+1);

	char *q = res;
	memcpy(q, text, bags[0].rm_so);
	q+=bags[0].rm_so;

	p = sub;
	while(*p != '\0'){
		if(*p == '\\'){
			p++;
			if(*p == '\\'){
				*q='\\';
				q++;
			}
			else if(*p >= '0' && *p <= '9'){
				int ref = *p-'0';
				if(bags[ref].rm_so == -1){
					fprintf(stderr, "Error: backreference \\%d does not exist\n", ref);
                    			return 1;
				}
				int len_match = bags[ref].rm_eo-bags[ref].rm_so;
				memcpy(q, text+bags[ref].rm_so, len_match);
				q+=len_match;
			}
			else{
				*q=*p;
				q++;
			}
		}
		else{
			*q=*p;
			q++;
		}
		p++;
	}

	int len_tail = strlen(text)-bags[0].rm_eo;
	memcpy(q, text+bags[0].rm_eo, len_tail);
	q+=len_tail;

	*q='\0';
	puts(res);
	return 0;
}

int main(int argc, char *argv[]) {
        regex_t regex;
        regmatch_t bags[MAXGR];

	if(argc != 4){
		printf("./esub <regex> <substitution> <text>\n");
		return 1;
	}

        int comp_exitcode = regcomp(&regex, argv[1], REG_EXTENDED);

	if(comp_exitcode != 0 ){
		char err_buf[256];
		regerror(comp_exitcode, &regex, err_buf, sizeof(err_buf));
		puts(err_buf);
		return 1;
	}

	int exec_exitcode = regexec(&regex, argv[3], MAXGR, bags, 0);
	if(exec_exitcode != 0){
		char err_buf[256];
		regerror(exec_exitcode, &regex, err_buf, sizeof(err_buf));
		puts(err_buf);
		return 1;
	}

	if(print_substitution(argv[2], argv[3], bags)!=0){
		return 1;
	}

	regfree(&regex);

        return 0;
}
