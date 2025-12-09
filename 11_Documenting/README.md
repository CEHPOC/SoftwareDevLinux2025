# Задание 08_I18n  
Сборка и установка:
```shell
autoreconf -fisv && ./configure && make
```  
Запуск без перевода на русский:
```shell
./numbergame
```
Запуск с переводом на русский:
```shell
LANG=ru_RU.UTF-8 ./numbergame
```
Генерация документации и привязка man страницы
```shell
make doxy  
export MANPATH=$MANPATH:$PWD/docs/man
```
Удаление генератов
```shell
make gitclean
```
