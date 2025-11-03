#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <rhash.h>

#ifdef USE_READLINE
#include <readline/readline.h>
#include <readline/history.h>
#endif

int get_hash_id(const char* algorithm) {
    if (strcasecmp(algorithm, "MD5") == 0)
        return RHASH_MD5;
    else if (strcasecmp(algorithm, "SHA1") == 0)
        return RHASH_SHA1;
    else if (strcasecmp(algorithm, "TTH") == 0)
        return RHASH_TTH;
    else
        return 0;
}

void hash_file(const char *algorithm, const char *argument, int is_upper){
	char digest[64];
	char output[130];

	int hash_id = get_hash_id(algorithm);
	int output_type;

	if(is_upper == 0){
		output_type = RHPR_BASE64;
	}
	else{
		output_type = RHPR_HEX;
	}

	int res = rhash_file(hash_id, argument, digest);
   	if(res < 0) {
     		fprintf(stderr, "LibRHash error: %s: %s\n", argument, strerror(errno));
     		return;
   	}

	rhash_print_bytes(output, digest, rhash_get_digest_size(hash_id), (output_type | RHPR_UPPERCASE));

	printf("%s (%s) = %s\n", rhash_get_name(hash_id), argument, output);
}

void hash_string(const char *algorithm, const char *argument, int is_upper){
	char digest[64];
	char output[130];

	int hash_id = get_hash_id(algorithm);
	int output_type;

	if(is_upper == 0){
		output_type = RHPR_BASE64;
	}
	else{
		output_type = RHPR_HEX;
	}

	int res = rhash_msg(hash_id, argument, strlen(argument), digest);
   	if(res < 0) {
		fprintf(stderr, "message digest calculation error\n");
     		return;
   	}

	rhash_print_bytes(output, digest, rhash_get_digest_size(hash_id), (output_type | RHPR_UPPERCASE));

	printf("%s (%s) = %s\n", rhash_get_name(hash_id), argument, output);
}

void parse(char *command){
	char algorithm[16];
	char argument[256];

	int is_upper_case;

	char *token = strtok(command, " ");
	if (token == NULL){
		fprintf(stderr, "Не хватает аргументов\n");
		return;
	}

	strncpy(algorithm, token, sizeof(algorithm)-1);
	algorithm[sizeof(algorithm) - 1] = '\0';

	token = strtok(NULL, " ");
	if (token == NULL) {
        	fprintf(stderr, "Не хватает аргументов\n");
        	return;
    	}
	strncpy(argument, token, sizeof(argument)-1);
	argument[sizeof(argument) - 1] = '\0';

	is_upper_case = isupper(algorithm[0]);
	if(argument[0] == '"'){
		hash_string(algorithm, argument+1, is_upper_case);
	}
	else{
		hash_file(algorithm, argument, is_upper_case);
	}
}

int main(){
	char *command=NULL;
	size_t len=0;
	ssize_t read;

	rhash_library_init();

	while (1) {
#ifdef USE_READLINE
    		command = readline(">> ");
#else
        	printf(">> ");
		read = getline(&command, &len, stdin); 
        	if ( read == -1) {
            		break; 
		}
		command[read-1]='\0';
#endif

		parse(command);

    	}

	return 0;
}
