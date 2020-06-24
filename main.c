#include <stdio.h>
 #include <stdlib.h>
 #include <windows.h>
 #include <string.h>
 #include "header.h" //arquivo com as funcoes no jogo

//void menu();

int main()
{
    limpar(); //cls + telatop()
    arquivos(); //verfica se os arquivos existem, se nao cria novos
    char *config = malloc(50*sizeof(char)); //aloca 50 posições para um vetor de char
    char *texto = malloc(100*sizeof(char)); //^^^^^^^^^^^^^
    strcpy(config,"NADA"); //indicar que nao existe config
    int menu = 0; //valor inicial menu
    while(menu != 3){ //3 faz loop encerrar
        limpar(); //cls + tela top
        if(strcmp(config,"NADA") == 0){ //sem config
            strcpy(texto,"Bem vindo(a)!\n1 - jogo rapido em categoria aleatoria\n2 - configurar novo jogo\n3 - sair\nEscolha: "); //texto sem jogar novamente
            menu = 3; //maximo valor valido para menu (pode ser escolhido de 1 ate 3)
        }else{ //ja possui uma config que foi usada
            char *txt = getNomeCategoria(config); //resgata o nome da ultima config utilizada
            strcpy(texto,"Bem vindo(a)!\n1 - Jogar novamente em "); //montando o menu
            strcat(texto,txt); //atribuindo o nome categoria para aparecer no menu
            free(txt); //liberando memoria ja que vetor nao sera mais utilizado
            strcat(texto,"\n2 - jogo rapido em categoria aleatoria\n3 - configurar novo jogo\n4 - sair\nEscolha: "); //termina a montagem do menu
            menu = 4; //define o valor maximo valido para o menu
        }
        printf("%s",texto); //mostra o menu
        menu = verificaNumber(1,menu); //recebe a escolha ja verificando se é um valor valido
        if(menu==-1){ //invalido
            printf("Foi digitado um valor invalido!\n"); //aviso de invalidez
            system("pause"); //confirmacao do aviso
            continue; //vai para o proximo loop
        }
        int validar = strcmp(config,"NADA"); //verifica a existencia de uma config
        if(validar != 0 ){ //existe
            if(menu==1){
                //jogar na mesma categoria
                jogo(config); //inicia o jogo na categoria definida
                menu = 0; //reinicia o menu
                continue; //vai logo para o proximo loop
            }else if(menu == 2 || menu == 3 || menu == 4){ //caso seja um valor valido
                menu--; //adaptando para o menu de 3 opções
            }else{ //algum problema ocorreu
                menu = 0; //reset menu
                continue; //voltando pro loop
            }

        }

        if(menu==1){ //config aleatoria
            limpar(); //cls + telatopo()
            configAleatoria(config); //gerar config baseado em numero aleatorio
            if(strcmp(config,"NADA")!= 0){ //verifica se retornou config valida
                jogo(config); //inicia o jogo na config gerada
            }else{
                printf("Insira palavras ou reinicie o jogo!\n"); //avisa falha na geracao da config
                system("pause"); //confirmacao
            }
             continue; //segue o loop

        }else if(menu==2){ //menu de personalização
            limpar();//cls + telatopo()
            int personalizar; //variavel de sub-menu
            char *ctg = malloc(50*sizeof(char)); //alocando texto

            strcpy(ctg,"animais.txt"); //preparando categoria para geracao do menu
            printf("Primeiramente escolha uma categoria:\n1 - %s\n",getNomeCategoria(ctg)); //adicionando nome da categoria no menu

            strcpy(ctg,"comidas.txt"); //preparando a proxima categoria para geracao do menu
            strcpy(ctg, getNomeCategoria(ctg)); //obtendo o nome da categoria no arquivo
            printf("2 - %s",ctg); //adicionando nome da categoria no menu

            strcpy(ctg,"esportes.txt"); //preparando a proxima categoria para geracao do menu
            strcpy(ctg, getNomeCategoria(ctg)); //adicionando nome da categoria no menu
            printf("\n3 - %s",ctg); //adicionando nome da categoria no menu

            strcpy(ctg,"profissoes.txt"); //preparando a proxima categoria para geracao do menu
            strcpy(ctg, getNomeCategoria(ctg)); //adicionando nome da categoria no menu
            printf("\n4 - %s",ctg); //adicionando nome da categoria no menu

            strcpy(ctg,"capitais.txt"); //preparando a proxima categoria para geracao do menu
            strcpy(ctg, getNomeCategoria(ctg)); //adicionando nome da categoria no menu
            printf("\n5 - %s",ctg); //adicionando nome da categoria no menu
            free(ctg); //removendo o vetor da memoria, esse nao sera mais utilizado
            printf("\n6 - personalizada\n7 - restaurar padroes\n8- voltar\nEscolha: "); //finalizando o menu

            personalizar = verificaNumber(1,8); //obtendo e verificando a entrada de dados do usuario
            if(personalizar == -1){//invalido
                printf("Numero invalido digitado!\n"); //alertando o usuario
                system("pause"); //pedindo confirmacao
                continue; //prosseguindo no loop
            }
            if(personalizar==1){ //arquivo com nome animais.txt
                strcpy(config,"animais.txt"); //preparando a config para o arquivo
                Configurar(config); //indo configurar a categoria escolhida
                continue; //prosseguindo no loop

            }else if(personalizar==2){ //arquivo com nome comidas.txt
                strcpy(config,"comidas.txt"); //preparando a config para o arquivo
                Configurar(config); //indo configurar a categoria escolhida
                continue; //prosseguindo no loop

            }else if(personalizar==3){ //arquivo com nome esportes.txt
                strcpy(config,"esportes.txt"); //preparando a config para o arquivo
                Configurar(config); //indo configurar a categoria escolhida
                continue; //prosseguindo no loop

            }else if(personalizar==4){ //arquivo com nome profissoes.txt
                strcpy(config,"profissoes.txt"); //preparando a config para o arquivo
                Configurar(config); //indo configurar a categoria escolhida
                continue; //prosseguindo no loop

            }else if(personalizar==5){ //arquivo com nome capitais.txt
                strcpy(config,"capitais.txt"); //preparando a config para o arquivo
                Configurar(config); //indo configurar a categoria escolhida
                continue; //prosseguindo no loop

            }else if(personalizar==6){ //arquivo com nome personalizado.txt
                char *nova = novaCategoria(); //configuração especial para a categoria
                if(nova != NULL){ //verificando se é valida
                    strcpy(config,"personalizado.txt"); //salvando a config para o loop
                }
                continue; //prosseguindo no loop

            }else if(personalizar==7){ //reiniciar os arquivos
                int adc = 0; //variavel para if
                limpar(); //cls + telatopo()
                printf("ATENCAO!!!\nTodas as categorias e palavras adicionadas serão perdidas e o jogo retornara as categorias e valores padroes!\n"); //aviso para usuario
                system("pause"); //confirmaçao do aviso
                printf("\nTem certeza que eh isso que deseja?\n1 - sim\n2 - nao\nEscolha: "); //reconfirmar
                adc = verificaNumber(1,2); //recebendo e verificando o retorno do usuario

                if(adc == -1){ //invalido
                   printf("Um valor invalido foi digitado! A operacao de resetar foi cancelada!\n"); //avisando o usuario
                   system("pause"); //confirmação
                   continue; //retornando para o loop
                }

                if(adc==1){ //redefinir
                    limpar(); //cls + telatopo()
                    printf("Redefinindo!\n"); //avisando inicio do processo de restart
                    Sleep(1); //delay para o sistema
                    arquivos(); //evitar removes em arquivos inexistentes

                    char *txt = malloc(50*sizeof(char)); //alocando novo vetor
                    strcpy(txt,"animais.txt"); //configurando primeiro arquivo
                    printf("%s recebeu status: ",getNomeCategoria(txt)); //informando ao user
                    int a = remove("animais.txt"); //removendo o primeiro arquivo

                    strcpy(txt,"comidas.txt"); //configurando o segundo arquivo
                    printf("%d\n%s recebeu o status: ",a,getNomeCategoria(txt)); //informando ao user
                    int co = remove("comidas.txt"); //removendo o segundo arquivo

                    strcpy(txt,"capitais.txt"); //configurando o terceiro arquivo
                    printf("%d\n%s recebeu o status: ",co,getNomeCategoria(txt)); //informando ao user
                    int ca = remove("capitais.txt"); //removendo o terceiro arquivo

                    strcpy(txt,"esportes.txt"); //configurando o quarto arquivo
                    printf("%d\n%s recebeu o status: ",ca,getNomeCategoria(txt)); //informando ao user
                    int e = remove("esportes.txt");//removendo o quarto arquivo

                    strcpy(txt,"profissoes.txt"); //configurando o quinto arquivo
                    printf("%d\n%s recebeu o status: ",e,getNomeCategoria(txt)); //informando ao user
                    int pro = remove("profissoes.txt"); //removendo o quinto arquivo

                    strcpy(txt,"personalizada.txt"); //configurando o arquivo personalizado
                    printf("%d\n%s recebeu o status: ",pro,getNomeCategoria(txt)); //informando ao user
                    int per = remove("personalizada.txt"); //removendo o arquivo personalizado

                    printf("%d\nProcedimento concluido!\n",per); //informando o termino
                    strcpy(config,"NADA"); //reiniciando a configuração
                    arquivos(); //verificando e recriando os arquivos deletados
                    system("pause"); //confirmacao da conclusao
                }
                continue; //seguindo o loop

            }else if(personalizar!=8){ //numero com valor inesperado
                printf("Numero invalido!"); //informando que ocorreu um erro
                system("pause"); //confirmacao
            }
        }
    }
}







