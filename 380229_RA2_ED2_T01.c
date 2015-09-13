
#include "380229_RA2_ED2_T01.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Partida *criarPartida(char *equipeVermelha, char *equipeAzul, char *mvp, char data[10]){
    Partida *p;
    p = malloc(sizeof(Partida));
    strcpy(p->equipeVermelha, equipeVermelha);
    strcpy(p->equipeAzul, equipeAzul);
    strcpy(p->mvp, mvp);
    setData(p, data);
    setCodigo(p);
    return p;
} 
int dataValida(char data[10]){
    /*int dia = 
    if(strcmp(data[2],"/") && strcmp(data[4],"/")){
        
    }*/
}
//Falta Validar campos
Partida *inserirPartida(){
    Partida *p;
    char data[10];
    
    printf("Nome da equipe Azul:");
    scanf("%s", &p->equipeAzul);
    printf("Nome da equipe Vermelha:");
    scanf("%s", &p->equipeVermelha);
    
        printf("Data da partida:");    
        scanf("%s", &data);
    setData(p, data);
    printf("Duracao da partida:"); 
    scanf("%s", &p->duracao);
    printf("Nome da equipe Vencedora:"); 
    scanf("%s", &p->equipeVencedora);    
    printf("Placar da equipe Azul:"); 
    scanf("%s", &p->placarAzul);    
    printf("Placar da equipe Vermelha:"); 
    scanf("%s", &p->placarVermelho);  
    printf("Nome do MVP:"); 
    scanf("%s", &p->mvp);  
    //Cria PK
    setCodigo(p);
    return p;
}
void setCodigo(Partida *p){    
    int i;
    
    p->codigo[0] = p->equipeAzul[0];
    p->codigo[1] = p->equipeVermelha[0];
    p->codigo[2] = p->mvp[0];
    p->codigo[3] = p->mvp[1];
    p->codigo[4] = p->dia[0];
    p->codigo[5] = p->dia[1];
    p->codigo[6] = p->mes[0];
    p->codigo[7] = p->mes[1];
    p->codigo[8]= '\0';
    for(i = 0; i < 8; i++){
        p->codigo[i] = toupper(p->codigo[i]);
    }
}
char *getCodigo(Partida *p){
    return p->codigo;
}
void setData(Partida *p, char data[10]){
    p->dia[0] = data[0];
    p->dia[1] = data[1];
    p->mes[0] = data[3];
    p->mes[1] = data[4];
    p->ano[0] = data[6];
    p->ano[1] = data[7];
    p->ano[2] = data[8];
    p->ano[3] = data[9];    
}
char *getDia(Partida *p){    
    return p->dia;
}
char *getMes(Partida *p){    
    return p->mes;
}

void menu(){
    char pk[8], novaDuracao[5], mvp[20], equipeVencedora[20];   
    int opcao, opcao2;
    
    printf("Digite a opcao:\n ");
    printf("[1]Inserir Partida\n");
    printf("[2]Remover Partida\n");
    printf("[3]Alterar Duracao\n");
    printf("[4]Buscar Partida\n");
    printf("[5]Listar Partida\n");
    printf("[6]Liberar Espaco\n");
    printf("[0]Sair\n");
    scanf("%d", &opcao);
    while(opcao != 0){
        switch(opcao){
            case 1:
                inserirPartida();
                break;
            case 2:
                printf("Chave da partida a ser removida");
                scanf("%s", &pk);
                removerPartida(pk);
                break;
            case 3:
                printf("Chave da partida a mudar a Duracao");
                scanf("%s", &pk);
                printf("Nova Duracao");
                scanf("%s", &novaDuracao);
                modificarDuracaoPartida(pk, novaDuracao);
                break;    
            case 4:
                printf("[1]Buscar por Codigo\n");
                printf("[2]Buscar por Equipe Vencedora\n");
                printf("[3]Buscar por MVP\n");
                scanf("%%d", &opcao2);
                switch(opcao2){
                    case 1:
                        printf("Chave da Partida\n");
                        scanf("%s", &pk);
                        buscarPartidaCodigo(pk);
                        break;
                    case 2:
                        printf("Equipe vencedora\n");
                        scanf("%s", &equipeVencedora);
                        buscarPartidaEquipeVencedora(equipeVencedora);
                        break;                        
                    case 3:
                        printf("MVP:\n");
                        scanf("%s", &mvp);
                        buscarPartidaMvp(mvp);
                        break;     
                    default:
                        printf("Opcao invalida\n");
                        break;
                }
                break; 
            case 5:
                printf("[1]Listar por Codigo\n");
                printf("[2]Listar por Equipe Vencedora\n");
                printf("[3]Listar por MVP\n");
                scanf("%%d", &opcao2);
                switch(opcao2){
                    case 1:
                        printf("Chave da Partida\n");
                        scanf("%s", &pk);
                        listarPartidaCodigo(pk);
                        break;
                    case 2:
                        printf("Equipe vencedora\n");
                        scanf("%s", &equipeVencedora);
                        listarPartidaEquipeVencedora(equipeVencedora);
                        break;                        
                    case 3:
                        printf("MVP:\n");
                        scanf("%s", &mvp);
                        listarPartidaMvp(mvp);
                        break;     
                    default:
                        printf("Opcao invalida\n");
                        break;
                }
                break;
            case 6:
                liberar();
                break;
        }
    }
}