#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Código da Ilha – Edição Free Fire
// Nível: Mestre
// Este programa simula o gerenciamento avançado de uma mochila com componentes coletados durante a fuga de uma ilha.
// Ele introduz ordenação com critérios e busca binária para otimizar a gestão dos recursos.

#define MAX_STR_LEN 50
#define TAM_MAX 10

typedef struct {
    char itens [TAM_MAX][MAX_STR_LEN];
    int numitens;
} inventario;

void inicializar_mochila(inventario *slot);
void inserir_item (inventario *slot, const char* novoitem);
void remover_item (inventario *slot, const char* novoitem);
void listar_item (const inventario *slot);

int main() {
    // Menu principal com opções:
    // 1. Adicionar um item
    // 2. Remover um item
    // 3. Listar todos os itens
    // 4. Ordenar os itens por critério (nome, tipo, prioridade)
    // 5. Realizar busca binária por nome
    // 0. Sair

    int opcao;

    inventario mochila;
    char item_nome[MAX_STR_LEN];
    inicializar_mochila(&mochila);

    printf ("INVENTÁRIO\n\n");

    do
    {
        printf ("1. Adicionar um item\n");
        printf ("2. Remover um item\n");
        printf ("3. Listar todos os itens\n");
        printf ("0. Sair\n");
        scanf ("%d", &opcao);

    // A estrutura switch trata cada opção chamando a função correspondente.
    // A ordenação e busca binária exigem que os dados estejam bem organizados.
    
        switch (opcao)
        {
        case 1:
            printf("Digite o nome do item para adicionar: ");
            scanf(" %[^\n]", item_nome);
            inserir_item(&mochila, item_nome);
            break;
        case 2:
            printf("Digite o nome do item para remover: ");
            scanf(" %[^\n]", item_nome);
            remover_item(&mochila, item_nome);
            break;
        case 3:
            listar_item(&mochila);
            break;
        case 0:
            printf("Saindo...\n");
            break;
        
        default:
        
        printf("Opção inválida!\n");
        
            break;
        }

    } while (opcao != 0);
    



    return 0;
}




// Struct Item:
// Representa um componente com nome, tipo, quantidade e prioridade (1 a 5).
// A prioridade indica a importância do item na montagem do plano de fuga.

// Enum CriterioOrdenacao:
// Define os critérios possíveis para a ordenação dos itens (nome, tipo ou prioridade).

// Vetor mochila:
// Armazena até 10 itens coletados.
// Variáveis de controle: numItens (quantidade atual), comparacoes (análise de desempenho), ordenadaPorNome (para controle da busca binária).

void inicializar_mochila(inventario *slot) {
    slot -> numitens = 0;
}

// limparTela():
// Simula a limpeza da tela imprimindo várias linhas em branco.

// exibirMenu():
// Apresenta o menu principal ao jogador, com destaque para status da ordenação.

// inserirItem():
// Adiciona um novo componente à mochila se houver espaço.
// Solicita nome, tipo, quantidade e prioridade.
// Após inserir, marca a mochila como "não ordenada por nome".
void inserir_item (inventario *slot, const char* novoitem){
    if (slot->numitens==TAM_MAX){
        printf("ERRO: Lista cheia, não é possível inserir.\n");
        return;
    }

    strcpy (slot->itens[slot->numitens], novoitem);
    slot->numitens ++;
    printf ("Item \"%s\" inserido com sucesso.\n", novoitem);
}
// removerItem():
// Permite remover um componente da mochila pelo nome.
// Se encontrado, reorganiza o vetor para preencher a lacuna.
void remover_item (inventario *slot, const char* novoitem){
    int i, pos = -1;
    for (i = 0; i < slot->numitens; i++){
        if (strcmp(slot -> itens[i], novoitem) == 0){
        pos = i;
        break;
        }
    }
    if (pos == -1){
        printf ("Erro: item \"%s\" não encontrado.\n", novoitem);
        return;
    }
    for (i = pos; i < slot->numitens -1; i++){
        strcpy (slot->itens[i], slot ->itens[i+1]);
    }
    slot->numitens--;
    printf("Item \"%s\" removido com sucesso.\n", novoitem);
}

// listarItens():
// Exibe uma tabela formatada com todos os componentes presentes na mochila.

void listar_item (const inventario *slot){
    if (slot -> numitens == 0){
        printf("O inventário está vazio.\n");
        return;
    }
    printf ("===========================================\n");
    printf ("\nINVENTÁRIO\n\n");
    for(int i = 0; i < slot -> numitens; i++){
        printf("%s\n", slot ->itens[i]);
    }
    printf("\n");
}

// menuDeOrdenacao():
// Permite ao jogador escolher como deseja ordenar os itens.
// Utiliza a função insertionSort() com o critério selecionado.
// Exibe a quantidade de comparações feitas (análise de desempenho).

// insertionSort():
// Implementação do algoritmo de ordenação por inserção.
// Funciona com diferentes critérios de ordenação:
// - Por nome (ordem alfabética)
// - Por tipo (ordem alfabética)
// - Por prioridade (da mais alta para a mais baixa)

// buscaBinariaPorNome():
// Realiza busca binária por nome, desde que a mochila esteja ordenada por nome.
// Se encontrar, exibe os dados do item buscado.
// Caso contrário, informa que não encontrou o item.
