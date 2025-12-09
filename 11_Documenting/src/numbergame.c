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
 * @brief Таблица перевода чисел между системами
 */
char *roman[] = {"0", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X", "XI", "XII",
    "XIII", "XIV", "XV", "XVI", "XVII", "XVIII", "XIX", "XX", "XXI", "XXII",
    "XXIII", "XXIV", "XXV", "XXVI", "XXVII", "XXVIII", "XXIX", "XXX", "XXXI",
    "XXXII", "XXXIII", "XXXIV", "XXXV", "XXXVI", "XXXVII", "XXXVIII", "XXXIX",
    "XL", "XLI", "XLII", "XLIII", "XLIV", "XLV", "XLVI", "XLVII", "XLVIII",
    "XLIX", "L", "LI", "LII", "LIII", "LIV", "LV", "LVI", "LVII", "LVIII",
    "LIX", "LX", "LXI", "LXII", "LXIII", "LXIV", "LXV", "LXVI", "LXVII",
    "LXVIII", "LXIX", "LXX", "LXXI", "LXXII", "LXXIII", "LXXIV", "LXXV",
    "LXXVI", "LXXVII", "LXXVIII", "LXXIX", "LXXX", "LXXXI", "LXXXII",
    "LXXXIII", "LXXXIV", "LXXXV", "LXXXVI", "LXXXVII", "LXXXVIII", "LXXXIX",
    "XC", "XCI", "XCII", "XCIII", "XCIV", "XCV", "XCVI", "XCVII", "XCVIII",
    "XCIX", "C"};



/**
 * @brief Перевод из римской системы в обычную
 *
 * Перевод из римской системы в обычную
 *
 * @param str Число в римской системе
 * @return Число в обычной записи
 */
int toDec(char *str){
        for(int i = 1; i< 101;i++){
                if(roman[i]==str){
                        return i;
                }
        }
	return -1;
}

/**
 * @brief Перевод из обычной записи в римскую
 *
 * Перевод из обычной записи в римскую
 *
 * @param n Число в обычной записи
 * @return Число в римской записи
 */
char* toRoman(int n){
        return roman[n];
}

/**
 * @brief Угадывание в римской записи
 *
 * @param left левая граница
 * @param right правая граница
 */
char *guess_roman(int left, int right){
	char answer[100];
	while(left<=right){
		int mid = (left+right)/2;
		if(left == right){
			return toRoman(left);
		}
		else{
			printf(_("Your number more than %s?(Yes/No)"), toRoman(mid));
			if (fgets(answer, 100, stdin) == NULL) {
            			printf(_("Error: stdin is closed\n"));
				return "-1";
        		}
			answer[strcspn(answer, "\n")] = '\0';
			if (strcmp(answer, _("Yes")) != 0 && strcmp(answer, _("No")) != 0) {
            			printf(_("Error: only 'Yes' and 'No' are allowed\n"));
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
	return "-1";
}

/**
 * @brief Угадывание в обычной записи
 *
 * @param left левая граница
 * @param right правая граница
 */
int guess_common(int left, int right){
	char answer[100];
	while(left<=right){
		int mid = (left+right)/2;
		if(left == right){
			return left;
		}
		else{
			printf(_("Your number more than %d?(Yes/No)"), mid);
			if (fgets(answer, 100, stdin) == NULL) {
            			printf(_("Error: stdin is closed\n"));
				return -1;
        		}
			answer[strcspn(answer, "\n")] = '\0';
			if (strcmp(answer, _("Yes")) != 0 && strcmp(answer, _("No")) != 0) {
            			printf(_("Error: only 'Yes' and 'No' are allowed\n"));
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
		char *res = guess_roman(left, right);
		if(strcmp(res, "-1")){
			return 1;
		}
        	printf(_("Your number is %s\n"), res);
	}
	else if(argc>1 && strcmp(argv[1],"--help")==0){
		print_help();
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
