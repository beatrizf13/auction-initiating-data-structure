//utaliza-se uma estrutura do tipo estatica

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PROD 500
#define COMP 100
#define VEND 100
#define TRUE 1
#define FALSE 0

typedef struct{
    int idProd;
    char nome[50];
    int idVend;
    int valorMin;
 }Produto;
 
 typedef struct{
     int idComp;
     char nome[50];
 }Comprador;
 
typedef struct{
    int idVend;
    char nome[50];
}Vendedor;

 typedef struct{
     int qtdProd;
     int qtdComp;
     int qtdVend;
     Produto produto[PROD];
     Comprador comprador[COMP];
     Vendedor vendedor[VEND];
}Lista;

Lista li;

//precisam ser acessadas na funçao lance e no main
int ganhador;
int valorMaior;
char nomeGanhador[50];

//***********************Definiçao funçoes***********************
int cadastrarVend(int ,char[]);//cadastra um vendedor e retorna TRUE se der erto, FALSE se nao tiver memoria ou ocorrer outro erro
int cadastrarProd( int , char[], int, int);//cadastra um produto e retorna TRUE se der erto, FALSE se nao tiver memoria ou ocorrer outro erro
int cadastrarComp ( int, char[]);//cadastra um comprador e retorna TRUE se der certo, FALSE se nao tiver memoria ou ocorrer outro erro
void listarTodos();//imprime todos os produtos na tela, com seus respectivos vendedores, codigos id, e valor minimo
void listarUm(int);//imprime apenas um produto
void lance(int, int , int);//verifica qual o maior lance
int apagar(int);//apaga um produto quando ele for vendido no lance


int cheioProd(); //verifica se a memoria para produto esta cheia
int vazioProd(); //verifica se a memoria para produto esta vazia

int cheioComp(); //verifica se a memoria para comprador esta cheia
int vazioComp(); //verifica se a memoria para comprador esta vazia

int cheioVend(); //verifica se a memoria para vendedor esta cheia
int vazioVend(); //verifica se a memoria para vendedor esta vazia
int verificarInt(char []); //verifica se o valor digitado e do tipo inteiro

//retornam a posiçao do vetor vendedor, produto ou comprador 
int pesquisarIdVend(int);
int pesquisarProd(int);
int pesquisarComp(int);

//verifica se id digitado existe
int testeidVend(int);
int testeidComp(int);
int testeidProd(int);

//imprime um produto
void mostrarEscolha(int );


void main(){
    // as variaveis sao iniciadas com o tipo char, para ser feita a verificaçao se o que foi digitado e inteiro, se for, a funçao atoi converte em inteiro, esta verificaçao ocorre sempre que se espera um dado inteiro
    int escolhaInt, idVendInt, idProdInt, idCompInt, valorMinInt, lanceInt ;
    char idComp[50], idProd[50], idVend[50], lance1[50] , produto[50], comprador[50], vendedor[50], valorMin[50], escolha[50];
    int op, i ; //auxiliares para condiçoes de paradas dos laços de repetiçao
    printf("***Este programa suporta ate %d vendedores, %d compradores, %d produtos***\n", VEND, COMP, PROD);
    
    do{
    
    printf("\nMENU\n");
    printf("\nDigite a opçao escolhida\n\n[1] - Cadastrar Vendedor\n[2] - Cadastrar Produto\n[3] - Cadastrar Comprador\n[4] - Ofertar Lance\n[5] - Listar todos os produtos, vendedor e valor minimo\n[6] - Pesquisar produto\n[0] - Encerar Programa\n"); 
    printf(">>>");
    scanf("%s",escolha);
    verificarInt(escolha);
    while( verificarInt(escolha) == FALSE){
        printf("\nDigite a escolha com numeros naturais positivos\n>>>");
        scanf("%s",escolha);
        verificarInt(escolha);
        }
    escolhaInt = atoi (escolha);
    
    if( escolhaInt == 1 ){
        setbuf(stdin, NULL);
        printf("\nNome do vendedor\n>>>");
        scanf("%[^\n]s",vendedor);
        setbuf(stdin, NULL);
        
        printf("\nCodigo Identificador de vendedor\n>>>");
        scanf("%s",idVend);
        verificarInt(idVend);
        
        while( verificarInt(idVend) == FALSE){
                printf("\nDigite o codigo identificador com numeros naturais positivos\n");
                printf("\nCodigo Identificador\n>>>");
                scanf("%s",idVend);
                verificarInt(idVend);
            }
        idVendInt = atoi (idVend);
        
        testeidVend(idVendInt);
        while (testeidVend(idVendInt) == TRUE ){
                printf("\nCodigo idisponivel!\n");
                printf("\nDigite outro codigo\n>>>");
                scanf("%s",idVend);
                verificarInt(idVend);
         
                while( verificarInt(idVend) == FALSE){
                        printf("\nDigite o codigo identificador com numeros naturais positivos\n");
                        printf("\nCodigo identificador do vendedor\n>>>");
                        scanf("%s",idVend);
                        verificarInt(idVend);
                }
                idVendInt = atoi (idVend);
                testeidVend(idVendInt);
             
         }
        
        
        idVendInt = atoi (idVend);
        cadastrarVend(idVendInt, vendedor);
        system("clear");
    }
        
    else if(escolhaInt == 2){
        if(vazioVend () == FALSE){
            printf("\nCodigo identificador do vendedor\n>>");
            scanf("%s",idVend);
            verificarInt(idVend);
            while( verificarInt(idVend) == FALSE ){
                printf("\nDigite o codigo identificador com numeros naturais positivos\n");
                printf("\nCodigo identificador do vendedor\n>>>");
                scanf("%s",idVend);
                verificarInt(idVend);
                }
            idVendInt = atoi (idVend);
        
            testeidVend(idVendInt);
            while (testeidVend(idVendInt) == FALSE ){
                printf("\nCodigo identificador do vendendor nao cadastrado!\n");
                printf("\nCodigo identificador do vendedor\n>>");
                scanf("%s",idVend);
                verificarInt(idVend);
                while( verificarInt(idVend) == FALSE){
                    printf("\nDigite o codigo identificador com numeros naturais positivos\n");
                    printf("\nCodigo identificador do vendedor\n>>>");
                    scanf("%s",idVend);
                    verificarInt(idVend);
                }
                idVendInt = atoi (idVend);
                testeidVend(idVendInt);
            }
       
            setbuf(stdin, NULL);
            printf("\nNome do produto\n>>>");
            scanf("%[^\n]s",produto);
            setbuf(stdin, NULL);
            printf("\nCodigo identificador do produto\n>>>");
            scanf("%s",idProd);
            verificarInt(idProd);
            while( verificarInt(idProd) == FALSE){
                printf("\nDigite o codigo identificador com numeros naturais positivos\n");
                printf("\nCodigo Identificador\n>>>");
                scanf("%s",idProd);
                verificarInt(idProd);
            }
            idProdInt = atoi (idProd);
            
            testeidProd(idProdInt);
            while (testeidProd(idProdInt) == TRUE ){
                printf("\nCodigo ja cadastrado!\n");
                printf("\nDigite outro codigo\n>>>");
                scanf("%s",idProd);
                verificarInt(idProd);
                while( verificarInt(idProd) == FALSE ){
                    printf("\nDigite o codigo identificador com numeros naturais positivos\n");
                    printf("\nCodigo identificador do vendedor\n>>>");
                    scanf("%s",idVend);
                    verificarInt(idProd);
               }
                idProdInt = atoi (idProd);
                testeidProd(idProdInt);
            }
            printf("\nValor minimo\n>>>R$");
            scanf("%s",valorMin);
            verificarInt(valorMin);
            while( verificarInt(valorMin) == FALSE ){
                printf("\nDigite valor minimo com numeros naturais positivos\n");
                printf("\nValor minimo\n>>>");
                scanf("%s",valorMin);
                verificarInt(valorMin);
            }
            valorMinInt = atoi (valorMin);
            cadastrarProd(idProdInt, produto, valorMinInt, idVendInt);
            system("clear");
        }
        else{
            printf("\nCadastre pelo menos um vendedor!");
            printf("\nDigite qualquer numero para voltar ao menu anterior\n>>>");
            scanf("%d",&i);
            if(i!='a') system("clear");
        }
        
        
    }
      
    else if(escolhaInt == 3){
        setbuf(stdin, NULL);
        printf("\nNome do comprador\n>>>");
        scanf("%[^\n]s",comprador);
        setbuf(stdin, NULL);
        
        printf("\nCodigo identificador\n>>>");
        scanf("%s",idComp);
        setbuf(stdin, NULL);
        verificarInt(idComp);
        
        while( verificarInt(idComp) == FALSE){
            printf("\nDigite o codigo identificador com numeros naturais positivos\n");
            printf("\nCodigo Identificador do comprador\n>>>");
            scanf("%s",idComp);
            verificarInt(idComp);
        }
        idCompInt = atoi (idComp);
        testeidComp(idCompInt);
        
        while (testeidComp(idCompInt) == TRUE ){
            printf("\nCodigo indisponivel!\n");
            printf("\nDigite outro codigo\n>>>");
            scanf("%s",idComp);
            verificarInt(idComp);
            while( verificarInt(idComp) == FALSE){
                printf("\nDigite o codigo identificador com numeros naturais positivos\n");
                printf("\nCodigo identificador do vendedor\n>>>");
                scanf("%s",idComp);
                verificarInt(idComp);
                }
            idCompInt = atoi (idComp);
            testeidComp(idCompInt);
        }
        idCompInt = atoi (idComp);
        cadastrarComp(idCompInt, comprador);
        system("clear");
    }
    
    
    else if(escolhaInt == 4){
        if (vazioProd() == FALSE && vazioComp() == FALSE){
            ganhador=0;
            printf("\nDigite o codigo identificador do produto\n>>>");
            scanf("%s",idProd);
            verificarInt(idProd);
            while( verificarInt(idProd) == FALSE){
                printf("\nDigite o codigo identificador com numeros naturais posisivos\n>>>");
                scanf("%s",idProd);
                verificarInt(idProd);
            }
            idProdInt = atoi(idProd);
        
            testeidProd(idProdInt);
            while( testeidProd(idProdInt) == TRUE){
                printf("\nCodigo nao cadastrado, tente novamente\n");
                printf("\nDigite o codigo identificador do produto\n>>>");
                scanf("%s",idProd);
                verificarInt(idProd);
                while( verificarInt(idProd) == FALSE){
                    printf("\nDigite o codigo identificador com numeros naturais positivos\n>>>");
                    scanf("%s",idProd);
                    verificarInt(idProd);
                    testeidProd(idProdInt);
                }
            }
            idProdInt = atoi (idProd);
            mostrarEscolha(idProdInt);
            printf("\nConfirma produto?\nDigite 1 - sim ou 0 - nao\n>>>");
            scanf("%d",&op);

            do{
            
                printf("\nCodigo identificador do comprador\n>>>");
                scanf("%s",idComp);
                verificarInt(idComp);
                while( verificarInt(idComp) == FALSE){
                    printf("\nDigite o codigo identificador com numeros naturais positivos\n>>>");
                    scanf("%s",idComp);
                    verificarInt(idComp);}
                idCompInt = atoi (idComp);
                testeidComp(idCompInt);
                while( testeidComp(idCompInt) == FALSE){
                    printf("\nCodigo nao cadastrado, tente novamente\n");
                    printf("\nDigite o codigo identificador do comprador\n>>>");
                    scanf("%s",idComp);
                    verificarInt(idComp);
                    while( verificarInt(idComp) == FALSE){
                        printf("\nDigite o codigo identificador com numeros naturais positivos\n>>>");
                        scanf("%s",idComp);
                        verificarInt(idComp);
                    }
                    idCompInt = atoi (idComp);
                    testeidComp(idCompInt);
                }
                
                printf("\nValor do lance\n>>>R$");
                scanf("%s",lance1);
                verificarInt(lance1);
                while( verificarInt(lance1) == FALSE){
                    printf("\nDigite o valor do lance com numeros naturais positivos\n>>>");
                    scanf("%s",lance1);
                    verificarInt(lance1);
                }
                lanceInt = atoi (lance1);
                lance (lanceInt, idProdInt, idCompInt);
                printf("\nAlguem da mais?\nDigite\n1 - sim\n0 - nao\n>>>");
                scanf("%d",&op);
            
            }while(op != 0);
                if (ganhador == 0){
                    printf("\nProduto nao foi vendido!\n");
                    printf("\nDigite qualquer numero para voltar ao menu anterior\n>>>");
                    scanf("%d",&i);
                    if(i!='a') system("clear"); 
               }
            else {
                printf("\nComprador %s com o codigo identificador %d fica com o produto por R$%d\n",nomeGanhador, ganhador,valorMaior);
                apagar(idProdInt);
                printf("\nDigite qualquer numero para voltar ao menu anterior\n>>>");
                scanf("%d",&i);
                if(i!='a') system("clear");
            }
            
        }
        
        else{
            printf("\nCadastre pelo menos um produto e um comprador"); 
            printf("\nDigite qualquer numero para voltar ao menu anterior\n>>>");
            scanf("%d",&i);
            if(i!='a') system("clear");
        }
    }  
    else if(escolhaInt == 5){
        if(vazioProd() == FALSE){
            listarTodos();
            printf("\nDigite qualquer numero para voltar ao menu anterior\n>>");
            scanf("%d",&i);
            if(i!='a') system("clear");
         }
        else{
            printf("\nNenhum produto cadastrado!\n");
            printf("\nDigite qualquer numero para voltar ao menu anterior\n>>>");
            scanf("%d",&i);
            if(i!='a') system("clear");
        }
    }
    
    else if (escolhaInt == 6){
        if(vazioProd() == FALSE){
            printf("\nCodigo identificador do produto\n>>>");scanf("%s",idProd);
            verificarInt(idProd);
            while( verificarInt(idProd) == FALSE){
                printf("\nDigite o codigo identificador com numeros naturais positivos\n>>>"); scanf("%s",idProd);
                verificarInt(idProd);
            }
            idProdInt = atoi(idProd);
            mostrarEscolha(idProdInt);
            printf("\nDigite qualquer numero para voltar ao menu anterior\n>>>");
            scanf("%d",&i);
            if(i!='a') system("clear");
        }
        else{
            printf("\nNenhum produto cadastrado!\n");
            printf("\nDigite qualquer numero para voltar ao menu anterior\n>>>");scanf("%d",&i);
            if(i!='a') system("clear");
        }
    }
        
        else if (escolhaInt !=1 && escolhaInt != 2 && escolhaInt !=3 && escolhaInt !=4 && escolhaInt !=5 && escolhaInt !=6 && escolhaInt !=0){
            printf("\nOpçao invalida\nTente novamente\n\n");
        }
    }while(escolhaInt !=0);
    
}

//Implementaçao das funçoes


int cheioProd(){
  return (li.qtdProd >= PROD);
}

int vazioProd(){
  return (li.qtdProd == 0);
}

int cheioComp(){
  return (li.qtdComp >= COMP);
}

int vazioComp(){
  return (li.qtdComp == 0);
}

int cheioVend(){
    return (li.qtdVend >= VEND);
}

int vazioVend(){
    return (li.qtdVend == 0);
}



int cadastrarVend( int idVend, char nome[]){
    if (cheioVend()){
        printf("\nMemoria para vendedor cheia!\n");
        return FALSE;
    } 
    Vendedor vend;
    vend.idVend =idVend;
    strcpy(vend.nome, nome);
    li.vendedor[li.qtdVend] = vend;
    li.qtdVend++;
}

int verificarInt(char codigo[]){
	int flag,i;
	flag = 1;
	for(i=0; codigo[i]!='\0';i++){
        if (codigo[i] != '0' && codigo[i] != '1' && codigo[i] != '2' && codigo[i] != '3' && codigo[i] != '4' && codigo[i] != '5' &&	codigo[i] != '6' && codigo[i] != '7' && codigo[i] != '8' && codigo[i] != '9') {
            flag = 0;
            return FALSE;
        }
    }
    if(flag == 1) return TRUE;
}

int cadastrarProd( int idProd, char nome[], int valorMin, int idVend ){
    if (cheioProd()){ 
        printf("\nMemoria para produto insulficiente");
        return FALSE;}
    Produto prod;
    prod.idProd = idProd;
    strcpy(prod.nome, nome);
    prod.valorMin = valorMin;
    prod.idVend = idVend;
    li.produto[li.qtdProd]=prod;
    li.qtdProd++;
}

int pesquisarIdVend(int idVend){
    if(vazioVend()) return -1;
    int i;
    for(i=0;i<li.qtdVend; i++)
        if(idVend==li.produto[i].idVend) return i;
    return -1;
}

int testeidVend(int idVend){
    if(vazioVend())
    return FALSE;
    int i;
    for(i=0;i<li.qtdVend; i++){
        if(idVend == li.vendedor[i].idVend) return TRUE;
    }
    return FALSE;
}

int cadastrarComp ( int idComp, char nome[]){
    if (cheioComp()){
        printf("\nMemoria pra comprador insuficiente");
        return FALSE;
    }
    Comprador comp;
    comp.idComp = idComp;
    strcpy(comp.nome, nome);
    li.comprador[li.qtdComp] = comp;
    li.qtdComp++;
}

int testeidComp(int idComp){
    if(vazioComp())
    return FALSE;
    int i;
    for(i=0;i<li.qtdComp; i++){
        if(idComp == li.comprador[i].idComp) return TRUE ;
    }
    return FALSE;
}

void listarTodos(){
    if (vazioProd()){
        printf("\nNenhum produto cadrastrado!\n");    
        return;
    } 
    int i;
    for ( i=0 ; i < li.qtdProd ; i++){
        listarUm(i);
    }
    printf("\nQuantidade de produtos cadastrados\n>>> %d\n",li.qtdProd );
}

void listarUm(int i){
  i = (i < 0)?-i:i;
  if(i >= li.qtdProd)
    return;
    printf("\nCodigo identificador do Produto: %d\n", li.produto[i].idProd);
    printf("Nome do Produto: %s\n", li.produto[i].nome);
    printf("Codigo identificador do vendedor: %d\n", li.produto[i].idVend);
    printf("Valor Minimo:R$ %d\n", li.produto[i].valorMin);
}

int testeidProd(int idProd){
    if(vazioProd())
    return FALSE;
    int i;
    for(i=0;i<li.qtdProd; i++){
        if(idProd == li.produto[i].idProd) return TRUE ;
    }
    return FALSE;
}

int pesquisarProd(int id){
  if(vazioProd()){
      printf("\nNenhum produto cadastrado!");
      return -1;
  }
  int i;
  for(i=0;i<li.qtdProd; i++)
    if(id==li.produto[i].idProd)
      return i;
  
  return -1;
}
void mostrarEscolha(int id){
  	  int i= pesquisarProd(id);
  if(i == -1)
    return;
   int k;
  for (k=i; k<=i;k++){
      printf("\nCodigo identificador do Produto: %d\n", li.produto[k].idProd);
      printf("Nome do Produto: %s\n", li.produto[k].nome);
      printf("Codigo identificador do vendedor: %d\n", li.produto[k].idVend);
      printf("Valor Minimo:R$ %d\n", li.produto[k].valorMin);
  }
}

int pesquisarComp(int idComp){
  if(vazioComp())
    return -1;
  int i;
  for(i=0;i<li.qtdProd; i++)
    if(idComp==li.comprador[i].idComp)
      return i;
  
  return -1;
}

void lance(int lanceInt, int idProd, int idComp){
    
    int i = pesquisarProd(idProd);
    int j = pesquisarComp(idComp);
    
    if ( lanceInt > li.produto[i].valorMin ){
        li.produto[i].valorMin = lanceInt;
        valorMaior = lanceInt;
        ganhador = idComp;
        strcpy(nomeGanhador, li.comprador[j].nome);
    }
    else
        printf("\nValor insuficiente!\n");
}

int apagar (int idProd){
	int i = pesquisarProd(idProd);
	if(i== -1)
		return 0;
	int k;
	for (k=i; k<= li.qtdProd-1; k++){
		li.produto[k] = li.produto[k+1];
	}
	li.qtdProd--;
	return 1;
}