# Задание 12_InstallPackaging  
## Сборка и установка:
```shell
autoreconf -fisv && ./configure && make
```
## Для установки в систему:
```shell
sudo make install
```
---  
## Запуск:
```shell
src/numbergame
```
## Запуск с переводом на русский:
```shell
LANG=ru_RU.UTF-8 src/numbergame
```
## Запуск, если усатновлено в систему
```shell
numbergame
```
---
## Тесты
```shell
make check
```
---
## Документация
```shell
./docs/html/index.html
```
## man
При установке в систему будет доступна по
```
man numbergame
```
В ином случае доступна локально
```
man ./numbergame.1
```
---
## Удаление генератов
```shell
make gitclean
```
