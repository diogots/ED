typedef struct data DATE;
typedef struct nodePreco NODEP;
int validaData(int ano, int mes, int dia);
NODEP* criaLista();
float vazia(NODEP *lista);
NODEP* insereIni(NODEP *lista, float valor, DATE data);
void printLista(NODEP* lista);
void destroiLista(NODEP* lista);
void editaElem(NODEP* edit, float valor, DATE dt);
NODEP* buscaElemento(NODEP* lista, DATE dt);
NODEP* buscaMenor(NODEP* lista);
NODEP* buscaMaior(NODEP* lista);
float mediapreco(NODEP* lista);
void imprimeRelatorio(NODEP* lista);

//se criar mais funções não esqueça de adicioná-las aqui!
