#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "header.h"


//config

int isNumber(char c){ //recebe char e retorna verdadeiro caso seja numero
    int cont; //variavel para loop
    char *numeros = malloc(10*sizeof(char)); //vetor que contem todos os numeros naturais
    strcpy(numeros,"0123456789"); //colocando os numeros naturais no vetor
    for(cont=0;cont<10;cont++){ //1 loop para cada numero
        if(c==numeros[cont]){ //se o char for igual ao numero
            return 1; //retorna que é um numero
        }
    }
    return 0; //retorna que nao eh numero
}

int verificaNumber(int mini, int maxi){ //recebe char e tranforma pra numero = remover crashs quando usuario digita errado
   char *n = malloc(10*sizeof(char)),*numeros = malloc(10*sizeof(char)); //alocando dois vetores de char
   int v,cont,cont2,valido; //v guardara o valor, cont ira ser usado para percorrer o vetor n e cont2 para percorrer vetor numeros
   fflush(stdin); //limpar buff para gets
   gets(n); // ler vetor
   fflush(stdin); //limpar buff pos get
   strcpy(numeros,"0123456789"); //criar vetor com apenas numeros

   if(strlen(n)==0){ //vazio eh valor invalido, logo retorna -1
    return -1;
   }

   for(cont=0;cont<strlen(n);cont++){ //percorrer vetor n
        valido = 0;                   //valido == FALSE
      for(cont2=0;cont2<10;cont2++){  //percorrer vetor numeros
        if(n[cont]==numeros[cont2]){  //a posicao de n deve ser igual a alguma posicao de numeros, assim n щ numero valido
            valido = 1;               //valido == TRUE
            cont2 = 11;               //finaliza for de cont2 imediatamente apos confirmar a posicao de n щ numero
        }
      }
       if(valido == 0 ){              //apos percorrer vetor numero, se nao tiver validado n щ dado como invalido pois aquele caractere nao estс no vetor numeros
         return -1;
       }
   }
   v = atoi(n);                      //com validacao eh possivel trasformar pelo atoi o vetor n para um inteiro
   if( v<= maxi && v >= mini){       //verifica se v esta na faixa desejada
     return v;                       //estando na faixa desejada faz o retorno
   }
   return -1;                        //retorna -1 pois nao esta na faixa que deseja
}

void telaTOPO(){ //mostrar cabecalho
    system("CLS");
    printf("        ### ##### ##### #####    ###  #####    #### ##### ###   ### #####\n");
    printf("          # #   # #     #   #    #  # #   #    #    #   # #  # #    #   #\n");
    printf("          # #   # #  ## #   #    #  # #####    ###  #   # ###  #    #####\n");
    printf("       #  # #   # #   # #   #    #  # #   #    #    #   # #  # #    #   #\n");
    printf("        ### ##### ##### #####    ###  #   #    #    ##### #  #  ### #   #\n");
    printf("                                                                                     Developed by Elias e Neto-IF@2019  \n");
}

void limpar(){ //limpar tela e ja mostrar cabecalho
    system("CLS"); //limpar tela
    telaTOPO(); //chama a funcao telaTOPO()
}

void arquivos(){ //verificar se arquivos existem
    FILE *animais,*comidas,*esportes,*profissoes,*capitais; //ponteiro para cada arquivo

    animais = fopen("animais.txt","r"); //abriando arquivo para leitura
    if(animais == NULL){ //se nao achou o arquivo, deve ser criado
        fclose(animais); //encerrando a interacao de leitura
        animais = fopen("animais.txt","w"); //abrindo arquivo para escrita do zero, como nao existe será criado
        char *texto = malloc(500*sizeof(char)); //alocando vetor para o texto padrao
        strcpy(texto,"ANIMAIS\ntatu\nborboleta\nmorcego\ncamelo\nfrango\ngolfinho\nraposa\nburro\nbode\ncanguru\nalce\npelicano\n"); //colocando as palavras padroes que ja vem no jogo
        fprintf(animais,"%s",texto); //inserindo no arquivo
    }
    fclose(animais); //finalizando a interação com o arquivo

    comidas = fopen("comidas.txt","r"); //abriando arquivo para leitura
    if(comidas == NULL){  //se nao achou o arquivo, deve ser criado
        fclose(comidas); //encerrando a interacao de leitura
        comidas = fopen("comidas.txt","w"); //abrindo arquivo para escrita do zero, como nao existe será criado
        char *texto = malloc(500*sizeof(char)); //alocando vetor para o texto padrao
        strcpy(texto,"COMIDAS\npastel\nfeijoada\nfarofa\nvinagrete\nsopa\npudim\nmaionese\ntapioca\nbeiju\ncuscuz\nestrogonofe\ncoxinha\n"); //colocando as palavras padroes que ja vem no jogo
        fprintf(comidas,"%s",texto); //inserindo no arquivo
    }
    fclose(comidas); //finalizando a interação com o arquivo

    esportes = fopen("esportes.txt","r"); //abriando arquivo para leitura
    if(esportes == NULL){  //se nao achou o arquivo, deve ser criado
        fclose(esportes); //encerrando a interacao de leitura
        esportes = fopen("esportes.txt","w"); //abrindo arquivo para escrita do zero, como nao existe será criado
        char *texto = malloc(500*sizeof(char)); //alocando vetor para o texto padrao
        strcpy(texto,"ESPORTES\ncanoagem\nfutebol\nesgrima\nbasquete\nvolei\nnatacao\nvela\nhandebol\nciclismo\natletismo\nginastica\ngolfe\n"); //colocando as palavras padroes que ja vem no jogo
        fprintf(esportes,"%s",texto); //inserindo no arquivo
    }
    fclose(esportes); //finalizando a interação com o arquivo

    profissoes =fopen("profissoes.txt","r"); //abriando arquivo para leitura
    if(profissoes == NULL){  //se nao achou o arquivo, deve ser criado
        fclose(profissoes); //encerrando a interacao de leitura
        profissoes = fopen("profissoes.txt","w"); //abrindo arquivo para escrita do zero, como nao existe será criado
        char *texto = malloc(500*sizeof(char)); //alocando vetor para o texto padrao
        strcpy(texto,"PROFISSOES\nprofessor\nmedico\nprogramador\ncozinheiro\nnutricionista\nadministrador\nmotorista\ndiarista\nauxiliar\nanalista\nengenheiro\ndesigner\n"); //colocando as palavras padroes que ja vem no jogo
        fprintf(profissoes,"%s",texto); //inserindo no arquivo
    }
    fclose(profissoes); //finalizando a interação com o arquivo

    capitais =fopen("capitais.txt","r"); //abriando arquivo para leitura
    if(capitais == NULL){  //se nao achou o arquivo, deve ser criado
        fclose(capitais); //encerrando a interacao de leitura
        capitais = fopen("capitais.txt","w"); //abrindo arquivo para escrita do zero, como nao existe será criado
        char *texto = malloc(500*sizeof(char));
        strcpy(texto,"CAPITAIS\nmanaus\npalmas\nmacapa\nrecife\nmaceio\nsalvador\nteresina\naracaju\ngoiania\ncuiaba\nbrasilia\nvitoria"); //colocando as palavras padroes que ja vem no jogo
        fprintf(capitais,"%s",texto); //inserindo no arquivo
    }
    fclose(capitais); //finalizando a interação com o arquivo

}

char *getPalavra(int linha, char *arquivo){ //buscar palavra em uma linha de determinado arquivo e a retorna
    FILE *fptr; //ponteiro de arquivo
    char *c = malloc(30*sizeof(char)); //alocando vetor para guarda a palavra a ser retornada
    if ((fptr = fopen(arquivo, "r")) == NULL) //arquivo nao localizado
    {
        fclose(fptr); // fecha o ponteiro
        free(c); //tira a alocação da palavra
        return NULL; //retorna NULL indicando o erro
    }

    int cont = 1; // variavel para verificacao se encontrou a linha
    while(!feof(fptr)){ //verificando enquanto arquivo nao acabar
        fgets(c,30,fptr); //obtendo proxima linha do arquivo
        if(cont==linha){ //verifica se eh a linha desejada
            fclose(fptr); //fecha a interacao com arquivo
            return c; //retorna a palavra
        }
        cont++; //nao eh a linha entao segue o loop

    }
    if(cont<linha){ //se menor eh pq arquivo acaba antes de achar a linha
        printf("Linha nao localizada!\n"); //aviso de falha
    }
    fclose(fptr); //fecha o arquivo
    return NULL; //retorna a string, nao caira nesse return caso tenha sido certo logo retorno sempre sera NULL
}

int getAleatorio(int min, int max){ //gerar numero aleatorio // eh onde o codigo vai buscar a linha da palavra
    srand(time(NULL)); //zerando time para garantir aleatoriedade
    return ((rand() % (max - min)) + min); //gerando numero aleatorio dentre o intervalo passado
}

void configAleatoria(char *arquivo){ //busca uma categoria a partir de numero aleatorio
    int numero = getAleatorio(1,5); //inicia com numero aleatorio
    switch(numero){ //interagindo com o numero
        case 1: //se o numero aleatorio for 1 a categoria deve ser  a de animais.txt
            strcpy(arquivo,"animais.txt");
            if (numeroDeLinhas(arquivo)>1) //caso o arquivo tenha palavras para ser utilizado
              break; //para a interacao
        case 2: //se o numero aleatorio for 2 a categoria deve ser  a de comidas.txt
            strcpy(arquivo,"comidas.txt");
            if (numeroDeLinhas(arquivo)>1)
                break;
        case 3: //se o numero aleatorio for 3 a categoria deve ser  a de esportes.txt
            strcpy(arquivo,"esportes.txt");
            if (numeroDeLinhas(arquivo)>1)
                break;
        case 4: //se o numero aleatorio for 4 a categoria deve ser  a de profissoes.txt
            strcpy(arquivo,"profissoes.txt");
            if (numeroDeLinhas(arquivo)>1)
                break;
        case 5: //se o numero aleatorio for 5 a categoria deve ser  a de capitais.txt
            strcpy(arquivo,"capitais.txt");
            if (numeroDeLinhas(arquivo)>1)
                break;
        default: //se der alguma falha tenta carregar todas + categoria personalizada
            strcpy(arquivo,"animais.txt");
            if (numeroDeLinhas(arquivo)>1) //caso o arquivo tenha palavras para ser utilizado
              break; //finaliza por ser valida
            strcpy(arquivo,"comidas.txt");
            if (numeroDeLinhas(arquivo)>1) //caso o arquivo tenha palavras para ser utilizado
                break; //finaliza por ser valida
            strcpy(arquivo,"esportes.txt");
            if (numeroDeLinhas(arquivo)>1) //caso o arquivo tenha palavras para ser utilizado
                break; //finaliza por ser valida
            strcpy(arquivo,"profissoes.txt");
            if (numeroDeLinhas(arquivo)>1) //caso o arquivo tenha palavras para ser utilizado
                break; //finaliza por ser valida
            strcpy(arquivo,"capitais.txt");
            if (numeroDeLinhas(arquivo)>1) //caso o arquivo tenha palavras para ser utilizado
                break; //finaliza por ser valida
            strcpy(arquivo,"personalizado.txt");
            if (numeroDeLinhas(arquivo)>1) //caso o arquivo tenha palavras para ser utilizado
                break; //finaliza por ser valida
            printf("Nao foi achado nenhuma categoria valida quanto ao numero de palavras!\n"); //todas tentativas falharam
            system("PAUSE"); //confirmacao
            strcpy(arquivo,"NADA"); //retorno de falha
    }
}

char *novaPersonalizada(){ //recriar o arquivo diverso para uma nova categoria
    char *categoria = malloc(50*sizeof(char)); //vetor do nome da categoria
    printf("Digite o nome da nova categoria: "); //interacao com o user
    fflush(stdin); //limpando a memoria
    gets(categoria); //recebendo a string de nome da categoria
    fflush(stdin); //limpando buff que ficou na memoria
    if(strcmp(categoria,"")==0 || categoria[0] == NULL){ //verificando se categoria ficou sem nada
        strcpy(categoria,"INDEFINIDA"); //corrigindo apenas para estetica
    }
    FILE *arquivo; //ponteiro para o arquivo
    arquivo = fopen("personalizado.txt","w"); //abrindo e limpando o arquivo, ou criando do zero caso nao exista
    fprintf(arquivo,"%s\n",categoria); //inserindo o nome da categoria
    fclose(arquivo); //finalizando interação com o arquivo
    return categoria; //retornando a categoria
}

char *getNomeCategoria(char *arquivo){ //obtendo o nome da categoria a partir do endereço de um arquivo
    FILE *f;
    char *c;
    c = malloc(30*sizeof(char));
    strcpy(c,"Nao identificada");
    f = fopen(arquivo, "r");
    if (f == NULL)
    {
        fclose(f);
        return c;
    }
    fgets(c,30,f);
    c[strlen(c)-1] = '\0'; //removendo o /n ja salvo por padrao em cada linha no arquivo
    fclose(f);
    return c;
}

void Configurar(char *arquivo){ //submenu
    limpar();
    int aux;
    printf("CATEGORIA: %s\n1 - Jogar\n2 - Editar categoria\n3 - voltar\nEscolha: ",getNomeCategoria(arquivo));
    aux = verificaNumber(1,3);
    //printf("Aux veio: %d\n",aux);
    if(aux == -1){
        printf("Valor invalido digitado! Personalizacao cancelada!\n");
        system("pause");
        return;
    }
    if(aux==1){
        jogo(arquivo);
    }else if(aux == 2){
        editarCategoria(arquivo);
    }
}

int palavraRepetida(char *palavra, char *nomearquivo){ //busca se a palavra ja existe no arquivo
    char *texto = malloc(50*sizeof(char));
    FILE *arquivo = fopen(nomearquivo,"r");
    while(!feof(arquivo)){ //enquanto nao tiver terminado o arquivo:
        fgets(texto,50,arquivo); //obter prox linha
        if(strcmp(texto,palavra)==0){ //verificar se essa linha tem a palavra desejada
            fclose(arquivo);
            return 1; //existe a palavra
        }
    }
    fclose(arquivo);
    return 0; //a palavra nao foi localizada
}

void adicionarPalavra(char *palavra,char *nomearquivo){ //colocando palavra no arquivo
    int tamanho = strlen(palavra), cont;
    if(palavraRepetida(palavra,nomearquivo)){ //nao pode inserir se palavra ja existir
        printf("Essa palavra ja foi cadastrada!\n");
        return;
    }

    if(palavra[0]==' ' || palavra[0]=='-' || palavra[tamanho-1]=='-'){ //
        printf("Essa palavra eh invalida!\n");
        return;
    }

    for(cont=0;cont<tamanho;cont++){
        if(isNumber(palavra[cont]) || palavra[cont]=='_'){
            printf("Essa palavra eh invalida!\n");
            return;
        }
    }

    FILE *arquivo;
    arquivo = fopen(nomearquivo,"a");
    if(arquivo == NULL){
        printf("Nao foi possivel adicionar! Arquivo da categoria nao localizado!\n");
    }else{
        fprintf(arquivo,"%s\n",palavra);
        printf("Palavra adicionada com sucesso!\n");
    }
    fclose(arquivo);
}

void mostrarPalavras(char *nomearquivo){ //listar as palavras que estao no arquivo
    FILE *arquivo;
    arquivo = fopen(nomearquivo,"r");
    if(arquivo == NULL){
        printf("Arquivo da categoria nao localizado!\n");
    }else{
        char *palavra = malloc(50*sizeof(char));
        fgets(palavra,50,arquivo);
        int cont = 1;
        limpar();
        printf("Palavras: \n");
        while(!feof(arquivo)){
            fgets(palavra,50,arquivo);
            if(!feof(arquivo))
                printf("%d - %s",cont,palavra); //mostrar na tela a palavra e sua numeração baseado na linha em que esta gravada
            cont++;
        }
    }
    fclose(arquivo);

}

int numeroDeLinhas(char *nomearquivo){ //contar quantas linhas gravadas o arquivo possui
    FILE *arquivo;
    arquivo = fopen(nomearquivo,"r");
    int cont = 0;
    if(arquivo == NULL){
        return 0;
    }else{
        char *palavra = malloc(50*sizeof(char));
        while(!feof(arquivo)){
            fgets(palavra,50,arquivo);
            if(!feof(arquivo)){
                cont++;
            }
        }

    }
    fclose(arquivo);
    return cont;
}

void deletarPalavra(char *plv,char *nomearquivo){ //remove uma palavra do arquivo
    FILE *arquivo;
    char *palavra = malloc(50*sizeof(char));
    strcpy(palavra,plv);
    arquivo = fopen(nomearquivo,"r");
    if(arquivo == NULL){
        printf("Arquivo da categoria nao localizado!\n");
    }else{
        int cont = numeroDeLinhas(nomearquivo);
        char texto[cont][50]; //matriz que ira guardar as palavras do arquivo
        int aux = 0;
        while(!feof(arquivo)){
            fgets(texto[aux],50,arquivo);
            aux++;
        }
        fclose(arquivo);

        arquivo = fopen(nomearquivo,"w");
        if(arquivo == NULL){
            printf("Arquivo da categoria nao localizado!\n");
        }else{
            int contador,verificador = 0;
            for(contador=0;contador<cont;contador++){ // loop baseado no numero de palavras do arquivo
               if(strcmp(palavra,texto[contador]) != 0 ){ //salvando enquanto nao for igual a palavra que deseja remover
                 fprintf(arquivo,"%s",texto[contador]);
               }else{
                 verificador++; //significa que achou a palavra que se deseja remover
               }
            }
            if(verificador==1){
                printf("Palavra achada e removida com sucesso!\n");
            }else if(verificador > 1){
                printf("A palavra foi localizada mais de uma vez e todas foram removidas!\n");
            }else{
                printf("A palavra nao foi localizada!\n");
            }
            system("pause");
        }
        fclose(arquivo);
    }
    fclose(arquivo);

}

void editarCategoria(char *arquivo){ //submenu de personalização

    int aux = 0;
    char *nome;

    while(aux != 5){
        limpar();
        nome = getNomeCategoria(arquivo);
        printf("Bem vindo(a)!\nVoce esta editando a categoria %s!\n1 - Adiconar palavra\n2 - Remover palavra\n3 - Editar nome da categoria\n4 - Ver palavras\n5 - Voltar\nEscolher: ",nome);
        aux = verificaNumber(1,5);
        if(aux==-1){
            printf("Foi digitado um valor invalido!\n");
            system("pause");
            continue;
        }
        if(aux==1){
            int adc = 0;
            char *palavra = malloc(50*sizeof(char));
            while(adc != 2){
                limpar();
                printf("CATEGORIA: %s\nDigite a nova palavra: ",nome);
                fflush(stdin);
                gets(palavra);
                fflush(stdin);
                int add = 0;
                if(strcmp(palavra,"")==0 || isspace(palavra[0])){ //palavra vazia ou comecando com espaчo == nao pode adicionar
                    printf("Palavra digitada foi invalida!\n");
                    system("pause");
                    add = 1;
                }
                if(add==1)
                    continue;//volta para o loop por conta da palavra nao ser valida
                adicionarPalavra(palavra,arquivo);
                system("pause");
                printf("1 - adicionar outra palavra\n2 - sair\nEscolher: ");
                adc = verificaNumber(1,2);
                if(adc==-1){
                    adc = 2;
                    printf("Insert de palavras foi cancelada! valor invalido foi digitado na verificacao!\n");
                    system("pause");
                }
            }
            free(palavra);
        }else if(aux==2){
            int adc = numeroDeLinhas(arquivo);
            int remov = 0;
            while(remov != adc){
                adc = numeroDeLinhas(arquivo);
                mostrarPalavras(arquivo);
                if(adc<=1){
                    printf("O arquivo esta vazio!\n");
                    system("pause");
                    remov = adc;
                    continue;
                }
                printf("\n%d - Cancelar remocao\n\nDigite o numero da palavra que deseja remover: ",adc);
                remov = verificaNumber(1,adc);
                if(remov == -1){
                    printf("Foi digitado um valor invalido!\n");
                    system("pause");
                    continue;
                }

                if(remov != adc){
                    char *texto = malloc(50*sizeof(char));
                    texto = getPalavra(remov+1,arquivo);
                    deletarPalavra(texto,arquivo);
                }
            }


        }else if(aux==3){
            //editar nome

            int adc = 0;
            while(adc!=2){
                    limpar();
                printf("A categoria esta com o nome: %s\nDeseja alterar seu nome?\n1 - Sim\n2 - Cancelar edicao\nEscolha :",getNomeCategoria(arquivo));
                adc = verificaNumber(1,2);
                if(adc == -1){
                    printf("Foi digitado um valor invalido!\n");
                    system("pause");
                    continue;
                }

                if(adc == 1){
                    limpar();
                    printf("Digite o nome que deseja dar a categoria: ");
                    char *newc = malloc(50*sizeof(char));;
                    fflush(stdin);
                    gets(newc);
                    fflush(stdin);
                    FILE *arquivoaux = fopen(arquivo,"r");
                    if(arquivoaux == NULL){
                        printf("Arquivo da categoria nao localizado!\n");
                    }else{
                        int cont = numeroDeLinhas(arquivo);
                        char texto[cont][50];
                        int aux = 0;
                        while(!feof(arquivoaux)){
                            fgets(texto[aux],50,arquivoaux);
                            aux++;
                        }
                        fclose(arquivoaux);
                        arquivoaux = fopen(arquivo,"w");
                        if(arquivoaux == NULL){
                            printf("Arquivo da categoria nao localizado!\n");
                        }else{
                            fprintf(arquivoaux,"%s\n",newc);//inserindo o novo
                             int contador;
                             for(contador = 1;contador<cont;contador++){ //comecando de 1 nao faz insert do antigo
                                fprintf(arquivoaux,"%s",texto[contador]);
                            }
                             printf("Nome foi atualizado com sucesso!\n");
                             system("pause");
                        }

                    }
                    fclose(arquivoaux);
                }
            }

        }else if(aux==4){
            //verificar palavras gravadas
            int adc = numeroDeLinhas(arquivo);
            if(adc==1)
                printf("Nenhuma palavra localizada!\n");
            else
                 mostrarPalavras(arquivo);
            system("pause");
        }else if(aux==5){
          return;
      }
  }
}

char *novaCategoria(){ //preparar arquivo de personalizada
    limpar();
    FILE *arquivo;
    arquivo = fopen("personalizado.txt","r");
    if(arquivo == NULL){ //o arquivo ainda nao existe
        fclose(arquivo);
        int aux;
        printf("Nao foi encontrado nenhuma categoria ja pre-definida!\nDeseja criar uma nova?\n1 - sim\n2 - nao\nEscolha: ");
        aux = verificaNumber(1,2);
        if(aux == -1){
            printf("Valor invalido digitado! A criacao foi cancelada!\n");
            system("pause");
            return NULL;
        }
        if(aux == 1){
            char *cat = novaPersonalizada();
            editarCategoria("personalizado.txt");
            return cat;
        }
        return NULL;
    }
    fclose(arquivo);
    int aux;
    printf("Uma configuracao personalizada foi localizada! Categoria: %s\n1 - Criar nova\n2 - Editar\n3 - voltar\nEscolha: ",getNomeCategoria("personalizado.txt"));
    //scanf("%d",&aux);
    aux = verificaNumber(1,3);
    if(aux == -1){
        printf("Valor invalido digitado! Edicao do arquivo cancelada!\n");
        system("pause");
        return NULL;
    }

    if(aux==1){
        return novaPersonalizada();
    }else if(aux==2){
        editarCategoria("personalizado.txt");
        return NULL;
    }
    return NULL;
}

Letra *getFila(char *palavra){ //transformar vetor de char em fila do tipo Letra
    Letra *fila = malloc(sizeof(Letra));
    Letra *filaatual = fila;
    int maximo = strlen(palavra);
    if(maximo == 0){
        printf("Foi passado uma palavra invalida!\n");
        system("Pause");
        return NULL;
    }
    int cont;
    for(cont=0;cont<maximo;cont++){ //loop para percorrer vetor de char //cada char ira virar uma Letra
        if(cont==0){ //primeiro da fila
            fila->letra = palavra[cont];
            fila->acertado = '_'; //valor padrao para nao acertado
            fila->prox = NULL;
        }else{
            filaatual = filaatual->prox = malloc(sizeof(Letra));
            filaatual->letra = palavra[cont];
            filaatual->acertado = '_';
            filaatual->prox = NULL;
        }
        /*if(filaatual->letra==' ')
            filaatual->acertado=' ';
        if(filaatual->letra=='-')
            filaatual->acertado='-';*/
        if(!isalpha(filaatual->letra)) //somente caracteres podem ser chutados, especiais/numeros considera como ja acertado
            filaatual->acertado=filaatual->letra;
    }
    return fila;
}

void MostrarFila(Letra *estrutura){ //mostrar os acertados e as posicoes que faltam
   Letra *fila = estrutura;
   while(fila != NULL){
      printf(" %c",fila->acertado);
      fila = fila->prox;
   }
}

void MostrarFilaP(Letra *estrutura){ //mostrar todas as filas
   Letra *fila = estrutura;
   while(fila != NULL){
      printf("%c",fila->letra);
      fila = fila->prox;
   }
}

int setLetra(char letra, Letra *estrutura){ //setar um caractere em fila->acertado caso seja igual ao valor de fila->letra do mesmo nó
   Letra *fila = estrutura;
   int acerto = 0;
   while(fila != NULL){
      if(toupper(fila->letra) == toupper(letra)){ //toupper é usado para que caracteres nao sejam diferenciados por maiusculo/minusculo
         fila->acertado = letra;
         acerto = 1;
      }
      fila = fila->prox;
   }
   return acerto;
}

int getVitoria(Letra *estrutura){ //busca se ainda falta caracteres a serem acertados
   Letra *fila = estrutura;
   while(fila != NULL){
      if(fila->acertado == '_'){
         return 0;
      }
      fila = fila->prox;
   }
   return 1;
}

char *mostrarChutesAux(Chute *chutes, int tamanho){ //mostra a lista de chutes ja dados pelo jogador
    if(tamanho == 0){
        char *txt = malloc(sizeof(char));
        txt[0] = chutes->Letra;
        return txt;
    }
    char *txt = malloc(tamanho*sizeof(char));
    char *local = mostrarChutesAux(chutes->prox,tamanho-3);
    txt[0] = chutes->Letra;
    strcat(txt,", ");
    strcat(txt, local);
    return txt;
}

char *mostrarChutes(Chute *chutes){ //sub-menu para mostrar os chutes
    int tentativas;
    Chute *local = chutes;
    for(tentativas=0;local->prox != NULL; local = local->prox, tentativas++){
        continue;
    }

    if(tentativas == 0 && chutes->Letra != NULL){
        char *txt = malloc(sizeof(char));
        txt[0] = chutes->Letra;
        return txt;
    }else if(tentativas == 0){
        char *txt = malloc(25*sizeof(char));
        strcpy(txt,"nenhum chute encontrado!");
        return txt;
    }
    char *txt = mostrarChutesAux(chutes,3*tentativas);//1 para o caractere, 1 para, e 1 para o espaço
    return txt;
}

void desenhar(int chances,Letra *fila, Chute *chutes){ //desenha na tela baseado no andamente do jogador
  if(chances != 0)
    printf("\n\n\nVoce tem: %d chances!\nChutes ja tentados: %s\n",chances, mostrarChutes(chutes));
  if(chances == 5){
    printf("       _________                                                                                                        \n");
    printf("      |/        |                                                                                                       \n");
    printf("      |                                                                                                                 \n");
    printf("      |                                                                                                                 \n");
    printf("      |                                                                                                                 \n");
    printf("      |                                                                                                                 \n");
    printf("      |                                                                                                                 \n");
    printf("     _|____         \t");
  }else if(chances==4){
      printf("       _________                                                                                                        \n");
      printf("      |/        |                                                                                                       \n");
      printf("      |        {_}                                                                                                      \n");
      printf("      |                                                                                                                 \n");
      printf("      |                                                                                                                 \n");
      printf("      |                                                                                                                 \n");
      printf("      |                                                                                                                 \n");
      printf("     _|____         \t");
  }else if(chances==3){
      printf("       _________                                                                                                        \n");
      printf("      |/        |                                                                                                       \n");
      printf("      |        {_}                                                                                                      \n");
      printf("      |        \\|/                                                                                                      \n");
      printf("      |                                                                                                                 \n");
      printf("      |                                                                                                                 \n");
      printf("      |                                                                                                                 \n");
      printf("     _|____         \t");
  }else if(chances==2){
      printf("       _________                                                                                                        \n");
      printf("      |/        |                                                                                                       \n");
      printf("      |        {_}                                                                                                      \n");
      printf("      |        \\|/                                                                                                      \n");
      printf("      |         |                                                                                                       \n");
      printf("      |                                                                                                                 \n");
      printf("      |                                                                                                                 \n");
      printf("     _|____         \t");

  }else if(chances==1){
      printf("       _________                                                                                                        \n");
      printf("      |/        |                                                                                                       \n");
      printf("      |        {_}                                                                                                      \n");
      printf("      |        \\|/                                                                                                      \n");
      printf("      |         |                                                                                                       \n");
      printf("      |        / \                                                                                                      \n");
      printf("      |                                                                                                                 \n");
      printf("     _|____         \t");

  }else if(chances==0){
     if(getVitoria(fila)){
        printf("\n\nPARABENS! Voce ganhou! :)\n");
        printf("  ____________\n");Sleep(60);
        printf(" \'._==_==_==_.\'     #     #  #####  ##    #  ##    #  ####  ####   # # #\n");Sleep(60);
        printf("   \\:      /        #  #  #    #    # #   #  # #   #  #     #   #  # # #\n");Sleep(60);
        printf("   |:      |        #  #  #    #    #  #  #  #  #  #  ###   ####   # # #\n");Sleep(60);
        printf("   |:      |        #  #  #    #    #   # #  #   # #  #     #  #\n");Sleep(60);
        printf("    \\_.  ._/         ## ##   #####  #    ##  #    ##  ####  #   #  # # #\n");Sleep(60);
        printf("      ) (\n");Sleep(60);
        printf("   _.\'   \'._\n");Sleep(60);
        printf("  \'---------\'\n");Sleep(60);
        printf("                                                                                                                        \n");

     }else{
        printf("\n\nVoce perdeu! :(\n");
        printf("  ____________________\n");Sleep(60);
        printf(" /                    \\     ####   #### #   # ####     ##### #   # #### ####    # #\n");Sleep(60);
        printf("|   XXXXX     XXXXX    |    #      #  # ## ## #        #   # #   # #    #   #   # #\n");Sleep(60);
        printf("|   XXXXX     XXXXX    |    #  ### #### # # # ###  ### #   # #   # ###  ####    # #\n");Sleep(60);
        printf("|   XXXXX     XXXXX    |    #   #  #  # #   # #        #   #  # #  #    # #\n");Sleep(60);
        printf("|                      |     ###   #  # #   # ####     #####   #   #### #  #    # #\n");Sleep(60);
        printf(" \\_                  _/\n");Sleep(60);
        printf("   \\     XXXXX      /\n");Sleep(60);
        printf("    |    XXXXX     |\n");Sleep(60);
        printf("    |    XXXXX     |\n");Sleep(60);
        printf("     \\____________/\n");Sleep(60);
        printf("\n");
        printf("A palavra era \"");
        MostrarFilaP(fila);
        printf("\"\nVoce tentou as letras: %s\n\n\n\n",mostrarChutes(chutes));
     }
  }

}

int verificaChute(char c, Chute *chute){ //verifica se foi um chute valido e/ou se foi um acerto
    if(chute->prox == NULL && chute->Letra == NULL){
        chute->Letra = c;
        return 1;
    }

    while(chute->prox != NULL){
        if(toupper(chute->Letra) == toupper(c))
            return 0;
        chute = chute->prox;
    }

    if(toupper(chute->Letra) == toupper(c))
        return 0;

    Chute *novo = malloc(sizeof(Chute));
    novo->Letra = c;
    novo->prox = NULL;

    chute->prox = novo;
    return 1;

}

int jogo(char *nomearquivo){ //submenu de jogo
    //printf("O jogo comecou!\n");
    int nl = numeroDeLinhas(nomearquivo);
    if(nl<=1){
      printf("Nenhuma palavra localizada!\n");
      system("pause");
      return 0;
    }
    int aleatorio = getAleatorio(1,nl); //obtendo numero aleatorio de 1 ate o numero de palvras salvas
    if(aleatorio==1) //nao pode ser linha 1, nesta sempre esta o nome da categoria
        aleatorio++;
    char *palavra = getPalavra(aleatorio,nomearquivo); //obtendo a palavra da linha sorteada

    if(palavra == NULL){
        int numeroDeLinhas(nomearquivo);
        if(numeroDeLinhas>=1){
            printf("O arquivo nao щ valido!\n");
            system("pause");
            return;
        }
        int cont;
        for(cont=0;cont<3;cont++){
            palavra = getPalavra(getAleatorio(2,numeroDeLinhas(nomearquivo)),nomearquivo);
            if(palavra!=NULL){
                cont=4;
            }
        }
        if(palavra==NULL){
             printf("Nao foi encontrada uma palavra valida!\n");
            system("pause");
            return;
        }
    }

    int tamanho = strlen(palavra);
    palavra[tamanho-1] = '\0';// removendo o \n
    int chances;
    Letra *estrutura = getFila(palavra);
    Chute *chute = malloc(sizeof(Chute));
    chute->Letra = NULL;
    chute->prox = NULL;
    for(chances = 5; chances >= 1;chances--){ //loop do jogo em si
        limpar();
        printf("Boa sorte! Voce esta jogando em %s!\n",getNomeCategoria(nomearquivo));
        if(getVitoria(estrutura)){ //verifica se venceu
            chances = 0;
            desenhar(chances,estrutura,chute);
            system("pause");
            free(palavra);
            free(estrutura);
            return 0;
        }
        desenhar(chances,estrutura,chute); //atualiza a tela a cada loop
        MostrarFila(estrutura);
        fflush(stdin);
        printf("\n\nDigite uma letra: ");
        char c;
        scanf("%c",&c);
        fflush(stdin);
        if (c=='\n' || c==' '){
            printf("Voce chutou um valor vazio!\n");
            system("pause");
            chances++; //nao gastar chance com valores invalidos
        }
        else if(!isalpha(c) && c != 'ç' && c != 'Ç'){ //considera invalido caracteres especiais e numerericos, tirando o Ç
            printf("Caractere invalido!");
            system("pause");
            chances++; //nao gastar chance com valores invalidos
        }
        else if(verificaChute(c,chute) != 0)
            chances += setLetra(c,estrutura); //como o retorno de setLetra sera 1, ele nao vai gastar chance por ter acertado
        else{
            printf("Valor ja foi digitado!\n");
            system("pause");
            chances++; //nao gastar chance com valores ja tentados anteriormente
        }

    }
    limpar();
    desenhar(chances,estrutura,chute); //apos o jogo diz se perdeu
    system("pause");
    return 0;
}



