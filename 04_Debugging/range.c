#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
	int start;
	int stop;
	int step;
	int iter;
} range;

void argparse(int argc, char *argv[], int *start, int *stop, int *step)
{
	if(argc==1){
		printf("help \n");
		*start=0;
		*stop=0;
		*step=1;
		return;
	}
	if(argc==2){
		*start=0;
		*stop=atoi(argv[1]);
		*step=1;
		return;
	}
	if(argc==3){
		*start=atoi(argv[1]);
		*stop=atoi(argv[2]);
		*step=1;
		return;
	}
	if(argc==4){
		*start=atoi(argv[1]);
		*stop=atoi(argv[2]);
		*step=atoi(argv[3]);
		return;
	}
}

void range_init(range *p){
	p->iter=p->start;
}

bool range_run(range *p){
	return p->iter<p->stop;
}

void range_next(range *p){
	p->iter+=p->step;
}

int range_get(range *p){
	return p->iter;
}

int main(int argc, char *argv[]) {
        range I;
        argparse(argc, argv, &I.start, &I.stop, &I.step);
        for(range_init(&I); range_run(&I); range_next(&I))
                printf("%d\n", range_get(&I));
        return 0;
}
