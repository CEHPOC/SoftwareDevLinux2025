/**
 * @mainpage
 * # Number guess game
 *
 * Бесплатное и открытое ПО
 *
 * Загадайте число и отвечайте на вопросы
 *
 * Использование:  
 * ./numbergame [-r | --help]
 *
 * -r - переход в римскую запись  
 *  --help - отображает данный текст
 */

#include <stdio.h>
#include <string.h>
#include <libintl.h>
#include <locale.h>
#include <stdlib.h>
#include "config.h"
#include "guesser.h"

#define _(STRING) gettext(STRING)
#define LOCALE_PATH "."

/**
 * @brief Вывод справки
 */
void print_help(){
	printf(_("Number guess game\n"));
	printf(_("Usage: ./numbergame [-r | --help]\n"));
	printf(_("-r - in roman system\n"));
	printf(_("--help - show this text\n"));
}


/**
 * @brief Запуск и разбор флагов
 */
int main(int argc, char *argv[]){

	setlocale(LC_ALL, "");
        bindtextdomain(PACKAGE, LOCALE_PATH);
        textdomain(PACKAGE);

	int left = 1;
	int right = 100;
	if(argc>1 && strcmp(argv[1],"-r")==0){
		printf(_("Guess number from %s to %s\n"), toRoman(left), toRoman(right));
		int res = guess_roman(left, right);
		if(res == -1){
			return 1;
		}
        	printf(_("Your number is %s\n"), toRoman(res));
	}
	else if(argc>1 && strcmp(argv[1],"--help")==0){
		print_help();
		return 0;
	}
	else if(argc>1 && strcmp(argv[1],"--version")==0){
		printf("number game 1.0\n");
		return 0;
	}
	else{
		printf(_("Guess number from %d to %d\n"), left, right);
		int res = guess_common(left, right);
		if(res == -1){
			return 1;
		}
		printf(_("Your number is %d\n"), res);
	}
	return 0;
}
