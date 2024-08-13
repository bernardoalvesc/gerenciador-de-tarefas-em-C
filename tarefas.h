#ifndef TAREFAS_H
#define TAREFAS_H

#define MAX_TAREFAS 100
#define TAM_DESC 255

typedef struct {
    char descricao[TAM_DESC];
    int concluida;
} Tarefa;

void limparTela();
void adicionarTarefa(Tarefa tarefas[], int *total);
void listarTarefas(const Tarefa tarefas[], int total);
void marcarTarefaConcluida(Tarefa tarefas[], int total);
void removerTarefa(Tarefa tarefas[], int *total);

#endif
