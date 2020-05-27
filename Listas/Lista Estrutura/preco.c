#include <stdio.h>
#include <stdlib.h>
#include "data.c"
#include "listaEst.h"

void limpatela(){
    puts("Pressione Enter para continuar...");
    while(getchar() != 10);
    if(getchar())
        system("clear");
}

void exibeMenu(){
    system("clear");
    puts("-------------------------------------------------");
    puts("|         Sistema de Controle de preços         |");
    puts("-------------------------------------------------");
    puts("| Escolha opção desejada:                       |");
    puts("-------------------------------------------------");
    puts("| 1 - Inserir registro de preço                 |");
    puts("| 2 - Imprimir histórico de preço               |");
    puts("| 3 - Editar preço em uma data específica       |");
    puts("| 4 - Gerar relatório de preços no período      |");
    puts("| 5 - Sair do programa                          |");
    puts("-------------------------------------------------");
    printf("Opção:");
}

DATE lerData(){
    int dia, mes, ano;
    DATE dt;
    int ok=1;
    do{
        puts("Insira a data no formato \"dia mes ano\" separado por espaços:");
        scanf("%d %d %d",&dia,&mes,&ano);
        printf("Data lida: %d/%d/%d ",dia,mes,ano);
        ok = validaData(dia,mes,ano);
        if(!ok){
            puts("Data inválida! Digite Novamente!");
            ok=0;
        }
    }while(!ok);
    puts("Data inserida com sucesso!");
    dt.dia = dia;
    dt.mes = mes;
    dt.ano = ano;
    return dt;
}

float lerPreco(){
    float p;
    puts("Digite o preço do produto da data no fomato \"x.xx\":");
    scanf("%f",&p);
    printf("Preço lido: %.2f\n",p);
    return p;
}

int main(){
    /* INSTRUÇÕES
    //leia a opção
    //crie o menu usando switch-case que...
        1 - Faça uma nova leitura de preço para uma data e insira na lista
            le os dados
            lPreco = insereIni(lPreco, preco, data);
        2 - Imprima o histórico de preços (imprima a lista formatada em PREÇO : DATA)
            lPreco = print..
        3 - Edite o conteúdo de um elemento buscado pela data como chave de busca
            -leia as alterações
            -busque o nó e edite
                -ou, crie uma função que já busque e edite (por sua conta! Decisão de projeto!)
        4 - Gere o relatório de preços no período
            "Menor preço: preçox - datax
             Maior preço: preçoy - datay
             média no período: preçoMédio"
        5 - Sair do programa
    */
    //declare tudo que for necessário, estou apenas sugerindo algumas varáveis
    NODEP* lPreco; //lista de preços
    DATE data;
    float preco; //para armazenar os dados de preço
    //int dia, mes, ano; //para armazenar os inteiros de dia, mês e ano. Para simplificar, considere o usuário bonzinho que vai digitar certo e vc não vai ter que tratar
    lPreco = criaLista();
    int op=1;

    while(op!=5){
        exibeMenu();
        do{
            if(op<1 || op>5)
                puts("Opção inválida!Digite novamente!");
            scanf("%d",&op);
        }while(op<1 || op>5);

        switch(op){
            case 1:
                data = lerData();
                preco = lerPreco();
                lPreco = insereIni(lPreco, preco, data);
                puts("Registro de preço inserido com sucesso!");
                break;

            case 2:
                printLista(lPreco);
                break;

            case 3:
                data = lerData();
                NODEP* edit =buscaElemento(lPreco,data);
                if(!edit)
                    puts("Data não encontrada!\n");
                else{
                    puts("Digite a alteração da data (Se não quiser digite a mesma)");
                    data = lerData();
                    puts("Digite a alteração de preço:");
                    preco = lerPreco();
                    editaElem(edit,preco,data);
                }
                break;

            case 4:
                imprimeRelatorio(lPreco);
                break;
        }
        limpatela();
    }
}
