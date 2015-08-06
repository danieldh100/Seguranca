//Segurança e Auditoria de Sistemas.
//Aluno: Daniel Maicon Lauermann.
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void cifrar(char *l, int key, int lenstr){
    int i, f =0;
    FILE *arq1;
    
    arq1 = fopen("cifrado.txt","a+");   	
    for(i=0;i<lenstr; i++){
		 putc((l[i]  + key) % 256, arq1);    
	}
	fclose(arq1);	
}

void decifrar(char *l , int key, int lenstr){
    int i;
    FILE *desc;
    desc = fopen("decifrado.txt","a+");   		
    for(i=0;i<lenstr; i++) putc(l[i] - key, desc); 

	fclose(desc);
}

int main()
{
   setlocale(LC_ALL, "Portuguese");
   FILE *fp;
   char *string=NULL;
   int i=0, key=0, menu=0, lenstr=0;
   char ch;
   printf("Seus dados de entrada devem estar contidos no arquivo 'entrada.txt'\n\n");
   printf("Tecle 1 para cifrar e 2 para decifrar: ");
   scanf("%d",&menu);
   printf("Entre com a chave: ");
   scanf("%d",&key);
   fflush(stdin);
   fp = fopen("entrada.txt","a+");   	
   if(!fp)
    {
      printf( "Erro na abertura do arquivo");
      exit(0);
    }   
    while((ch=fgetc(fp)) != EOF){
        string = (char *)realloc(string, (++lenstr) * sizeof(char));
    	string[lenstr - 1] = ch;   
    }
    if(menu==1){   
    cifrar(string, key, lenstr);
	system("cls");
	printf("\n\nArquivo cifrado com sucesso, verifique a saída no arquivo 'cifrado.txt'\n\n");
	}
	else if(menu==2){
    decifrar(string, key, lenstr);
    system("cls");
    printf("\n\nArquivo decifrado com sucesso, verifique a saída no arquivo 'decifrado.txt'\n\n");
	}
   return 0;
}
/*Possíveis bugs: Caso o programa for executado mais de uma vez recomenda-se apagar os arquivos "cifrado.txt" e 
"decifrado.txt", assim evitando acumulos dos dados da saída no editor de texto.

Créditos: Partes do código foram desenvolvidas com ajuda do colega Dalton.*/
