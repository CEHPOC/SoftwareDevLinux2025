# Задание 08_I18n  
Сборка и установка:
```
autoreconf -fisv && ./configure && make
```  
Запуск без перевода на русский:
```
./numbergame
```
Запуск с переводом на русский:
```
LANG=ru_RU.UTF-8 ./numbergame
```
Удаление генератов
```
make gitclean
```
