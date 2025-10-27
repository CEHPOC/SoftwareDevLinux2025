#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


int main(int argc, char *argv[]){
	char *infile = argv[1];
	char *outfile = argv[2];

	int saved_errno = 0;
	FILE *fin = fopen(infile, "r");
	if(fin == NULL){
		saved_errno = errno;
		perror("main()");
		return saved_errno;
	}
	FILE *fout = fopen(outfile, "w");
	if(fout == NULL){
		saved_errno = errno;
		perror("main()");
		fclose(fout);
		return saved_errno;
	}
	fseek(fin, 0, SEEK_END);
        long file_size = ftell(fin);
        fseek(fin, 0, SEEK_SET);

	char *buffer = (char *)malloc(file_size);
	if (buffer == NULL) {
		saved_errno=errno;
        	perror("main");
        	fclose(fin);
		fclose(fout);
        	return saved_errno;
    	}

	fread(buffer, 1, file_size, fin);
	if(fwrite(buffer, 1 ,file_size, fout)!=file_size){
		saved_errno = errno;
		perror("main");
		fclose(fin);
		fclose(fout);
		free(buffer);
		return saved_errno;
	}
	fclose(fin);
	fclose(fout);
	free(buffer);
	if(remove(infile)!=0){
		saved_errno = errno;
		perror("main");
		return saved_errno;
	}
	return 0;
}
