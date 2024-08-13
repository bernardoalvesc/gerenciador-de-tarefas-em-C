#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tarefas.h"

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void adicionarTarefa(Tarefa tarefas[], int *total) {
    if (*total >= MAX_TAREFAS) {
        printf("Lista de tarefas cheia!\n");
        return;
    }

    limparTela();
    printf("Adicionar Tarefa\n");
    printf("Descricao: ");
    fgets(tarefas[*total].descricao, TAM_DESC, stdin);
    strtok(tarefas[*total].descricao, "\n");

    tarefas[*total].concluida = 0;
    (*total)++;
    printf("Tarefa adicionada com sucesso!\n");
    getchar();
}

void listarTarefas(const Tarefa tarefas[], int total) {
    limparTela();
    printf("Listar Tarefas\n");
    for (int i = 0; i < total; i++) {
        printf("Tarefa %d: %s [%s]\n", i + 1, tarefas[i].descricao, tarefas[i].concluida ? "Concluida" : "Pendente");
    }
    getchar();
}

void marcarTarefaConcluida(Tarefa tarefas[], int total) {
    int indice;
    limparTela();
    printf("Marcar Tarefa Concluida\n");
    listarTarefas(tarefas, total);
    printf("Digite o numero da tarefa a ser marcada como concluida: ");
    scanf("%d", &indice);
    getchar();

    if (indice < 1 || indice > total) {
        printf("Tarefa invalida!\n");
        return;
    }

    tarefas[indice - 1].concluida = 1;
    printf("Tarefa marcada como concluida!\n");
    getchar();
}

void removerTarefa(Tarefa tarefas[], int *total) {
    int indice;
    limparTela();
    printf("Remover Tarefa\n");
    listarTarefas(tarefas, *total);
    printf("Digite o numero da tarefa a ser removida: ");
    scanf("%d", &indice);
    getchar();

    if (indice < 1 || indice > *total) {
        printf("Tarefa invalida!\n");
        return;
    }

    for (int i = indice - 1; i < *total - 1; i++) {
        tarefas[i] = tarefas[i + 1];
    }

    (*total)--;
    printf("Tarefa removida com sucesso!\n");
    getchar();
}
