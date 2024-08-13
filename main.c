#include <stdio.h>
#include <stdlib.h>
#include "tarefas.h"

void menuPrincipal(Tarefa tarefas[], int *total) {
    int opcao;

    while (1) {
        limparTela();
        printf("Gerenciador de Tarefas\n");
        printf("1. Adicionar Tarefa\n");
        printf("2. Listar Tarefas\n");
        printf("3. Marcar Tarefa como Concluida\n");
        printf("4. Remover Tarefa\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao) {
            case 1:
                adicionarTarefa(tarefas, total);
                break;
            case 2:
                listarTarefas(tarefas, *total);
                break;
            case 3:
                marcarTarefaConcluida(tarefas, *total);
                break;
            case 4:
                removerTarefa(tarefas, total);
                break;
            case 5:
                limparTela();
                printf("Saindo...\n");
                exit(0);
            default:
                printf("Opcao invalida! Tente novamente.\n");
                getchar();
                break;
        }
    }
}

int main() {
    Tarefa tarefas[MAX_TAREFAS];
    int total = 0;

    menuPrincipal(tarefas, &total);
    return 0;
}
