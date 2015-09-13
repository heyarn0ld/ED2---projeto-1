/* 
 * File:   380229_RA2_ED2_T01.h
 * Author: usuario
 *
 * Created on 12 de Setembro de 2015, 21:08
 */


typedef struct{
    char codigo[8];
    char equipeVermelha[20];
    char equipeAzul[20];
    char mvp[8];
    char dia[2];
    char mes[2];
    char ano[4];
    char equipeVencedora[20];
    char placarVermelho[2];
    char placarAzul[2];
    char duracao[5];
}Partida;
Partida *criarPartida(char *equipeVermelha, char *equipeAzul, char *mvp, char data[10]);
void setCodigo(Partida *p);
char *getCodigo(Partida *p);
void setData(Partida *p, char data[10]);

Partida *inserirPartida();
//Retorna 0 se nao existe OU 1 se existe e removeu
int removerPartida(char pk[8]);
//Retorna 0 se nao existe OU 1 se existe e removeu
int modificarDuracaoPartida(char pk[8], char novaDuracao[5]);
Partida buscarPartidaCodigo(char pk[8]);
Partida buscarPartidaEquipeVencedora(char *equipeVencedora);
Partida buscarPartidaMvp(char *mvp);
Partida listarPartidaCodigo(char pk[8]);
Partida listarPartidaEquipeVencedora(char *equipeVencedora);
Partida listarPartidaMvp(char *mvp);
void liberar();