
//estruturas

typedef struct tipo_letra{
    char letra; //caractere correta para validar o chute
    char acertado; //default: '_', caso possua outro valor significa que o usuario acertou aquele chute
    struct tipo_letra *prox; //endereço da prox letra que forma a palavra, null significa que essa é a ultima letra
}Letra; //estrutura para fazer uma fila formando as palavras

typedef struct tipo_chute{
    char Letra;
    struct tipo_chute *prox;
}Chute; //estrutura para salvar os chutes realizados pelo user

//funcoes de controle de valores
int verificaNumber(int mini, int maxi); //verifica se o valor é um numero valido

//config
void arquivos(); //verifica os arquivos e recria caso necessario
void adicionarPalavra(char *palavra,char *nomearquivo); //passar nomearquivo com extensao ex: "animais.txt"
void telaTOPO(); //desenho do topo do console
void limpar(); //cls + telaTopo()
int getAleatorio(int min, int max); //valor aleatorio com base nos valores passados
void configAleatoria(char *conf); //salvar uma config aleatoria no endereco passado
char *novaCategoria(); //config especial para o arquivo "personalizado.txt"
char *getNomeCategoria(char *arquivo); //passar nomearquivo com extensao ex: "animais.txt"
void mostrarPalavras(char *nomearquivo); //passar nomearquivo com extensao ex: "animais.txt"
void deletarPalavra(char *plv,char *nomearquivo); //passar nomearquivo com extensao ex: "animais.txt"
int numeroDeLinhas(char *nomearquivo); //passar nomearquivo com extensao ex: "animais.txt"
char *getPalavra(int linha, char *arquivo); //verificar se retorno != "FALHOU"
void Configurar(char *arquivo); //personalizar uma categoria

//jogo
int jogo(char *nomearquivo); //realiza o jogo


