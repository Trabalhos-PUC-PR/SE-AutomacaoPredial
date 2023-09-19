#ifndef SM_H
#define SM_H

// ponteiro de nome <pFuncao> que deve receber uma função com um parametro (endereço)
typedef void (*pFuncao)(void *);

// struct que simplifica a criação de uma maquina de estados
// ptr é o ponteiro para o próximo estado a ser executado,
//  e entry é a variavel que identifica se houve uma mudança de estados
typedef struct{
    pFuncao ptr; 
    unsigned char entry;
}StateMachine;

/*
 * BASICAMENTE
 * void (*pFuncao)() é uma ponteiro chamado pFuncao que aponta pra uma função sem paramentros, e que retorna void
 * > o typedef ali só serve pra não ter que ficar declarando o ponteiro toda hora com muito código, reduz tudo p uma palavra
 *
 * como a gente quer que seja possivel que um estado interaja com outro, a função tem que receber parametro, então *
 * void pq pFuncao ainda nn foi declarado naquela parte do código e uma parte dependeria da outra assim, então void foi escolhido
 *
 * os defines basicamente """abreviam""" a linha de código na direita pra um comando simples, podendo mudar alguns parametros
 */

// declaração de função <name> que recebe uma StateMachine _sm_
#define STATE(name)         void name(StateMachine *_sm_)

// setta o próximo estado da stateMachine _sm_ para a função <name>
#define NEXT_STATE(name)    _sm_->ptr = (pFuncao)name

// setta o estado inicial da stateMachine para <name> e
// instancia a variavel que mantém controle se o estado mudou ou não para 1
#define INIT(sm,name)   	{ \
                                sm.ptr = (pFuncao)name;    \
                                sm.entry=1;                \
                            }

// salva o endereço do estado atual da maquina
// roda o estado atual da maquina
// compara o estado atual da maquina com pré execução, e atribui essa comparação à variavel de controle de mudanças
#define EXEC(sm)            { \
                                pFuncao temp=sm.ptr; \
                                sm.ptr(&sm); \
                                sm.entry=(temp != sm.ptr); \
                            }

// devolve se o estado da maquina mudou ou nao
#define ENTRY				(_sm_->entry)

// !!! nenhum dos casts para pFuncao da problema na atribuição para ptr,
// pois ptr é do tipo pFuncao, e pFuncao é um ponteiro para função com um
// parametro, teria erros de compilação caso o numero de parametros fosse
// diferente, ou se ptr não recebesse o endereço de uma funcao

#endif // SM_H
