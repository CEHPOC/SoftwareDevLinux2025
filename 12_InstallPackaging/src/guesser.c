#include "guesser.h"
#include <libintl.h>
#include <string.h>
#include <stdio.h>
#define _(STRING) gettext(STRING)


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
int guess_roman(int left, int right){
        char answer[100];
        while(left<=right){
                int mid = (left+right)/2;
                if(left == right){
                        return left;
                }
                else{
                        printf(_("Your number more than %s?(Yes/No)\n"), toRoman(mid));
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
                        printf(_("Your number more than %d?(Yes/No)\n"), mid);
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


