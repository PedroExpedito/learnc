## Comandos do Gnu compiler

Como compilar  

* ```x86_64-w64-mingw32-gcc``` para compilar linguagem C para windows
* ```gcc``` para Linux


### tags:

   ```-o``` para salvar o aquivo  
   ```-lm``` linkar a biblioteca math ou seja #include <math.h>  
   ```-I``` para procurar no diretorio 
    
exemplo de comando com tag:
```bash
    gcc calculos.c main.c -I headers/ -o main2
```
https://gcc.gnu.org/