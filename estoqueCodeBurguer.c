#include <stdio.h>
#include <strings.h>
#include <locale.h>

/* FACULDADE DOM BOSCO DE PORTO ALEGRE
* Sistemas de Informação & Análise e Desenvolvimento de Sistemas
* Algoritmos
*
* Programa SegundoT2:
* -------------------------
* Objetivo do Programa: Sistema de gerenciamento da hamburgueria C0DE Burguer. 
* O programa deve ser capaz de realizar as funcionalidades elencadas de 1 à 8.
* 1 - Cadastrar Nomes | 2 - Ver Produtos Cadastrados | 3 - Cadastrar Estoque | 4 - Ver Informações de Estoque
* 5 - Retirar Produtos Do Estoque | 6 - Mostrar Produtos Com Baixa Quantidade | 7 - Mostrar Valor Do Estoque | 8 - Finalizar
* Autor: Vitor Teixeira
* Data da entrega do arquivo fonte: 28/06/2023
*/

int main(void){
	setlocale(LC_ALL, "Portuguese");
	
	const int qp = 6; // quantidadeProdutos;
	
	int funcionalidadeEscolhida, i, opcaoFuncTres, j, retiradaEscolhida = -1, quantiaRetirar;
	float tabelaQuantiaPreco[qp][3], valorEstoque = 0; // coluna 0 -> quantia existente | coluna 1 -> quantia mínima | coluna 2 - > preço unitário. 
	char rodarOpcoes[7] = "ficar";
	char nomeProdutos[qp][20], retirarNome[20];
	int nomesDeterminados = 0, minimoDeterminados = 0; // para utilizar no lugar de uma variável booleana
	
	for(rodarOpcoes; strcasecmp(rodarOpcoes, "sair");){
		
		printf("[ SISTEMA HAMBURGUERIA - C0DE BURGUER ]\n\n");
		
		printf("Digite [ 1 ] para - Cadastrar nome dos produtos.\n");
		printf("Digite [ 2 ] para - Ver produtos cadastrados\n");
		printf("Digite [ 3 ] para - Cadastrar informações de estoque\n");
		printf("Digite [ 4 ] para - Ver informações de estoque\n");
		printf("Digite [ 5 ] para - Retirar produtos do estoque\n");
		printf("Digite [ 6 ] para - Mostrar produtos com baixa quantidade\n");
		printf("Digite [ 7 ] para - Mostrar o valor total do estoque atual\n");
		printf("Digite [ 8 ] para - Finalizar\n\n");
		scanf("%d", &funcionalidadeEscolhida);
		
		if(funcionalidadeEscolhida == 1){
			system("cls"); 
			nomesDeterminados = 1;
			printf("[ NOMEAR PRODUTOS ]\n\n");
			for(i = 0; i < qp; i++){
				printf("Digite o nome do %do produto: ", i + 1);
				fflush(stdin);
				gets(nomeProdutos[i]);
			}
			
			system("cls");
		}
		
		if(funcionalidadeEscolhida == 2){
			system("cls");
			if(nomesDeterminados){
			printf("[ Produtos Cadastrados ]\n\n");
			for(i = 0; i < qp; i++){
				fflush(stdin);
				printf("%d - ", i + 1);
				puts(nomeProdutos[i]);
			}
			printf("\nDigite [ 0 ] para - Voltar");
			printf("\nDigite [ 8 ] para - Finalizar\n");
			fflush(stdin);
			scanf("%d", &funcionalidadeEscolhida);
			}else{
				printf("[ALERTA] Nome dos produtos não cadastrados [ALERTA]\n");
				printf("\nDigite [ 0 ] para - Voltar");
				printf("\nDigite [ 8 ] para - Finalizar\n");
				fflush(stdin);
				scanf("%d", &funcionalidadeEscolhida);
			}
		}
		
		if(funcionalidadeEscolhida == 3){
			for(opcaoFuncTres = 5; opcaoFuncTres != 0 && opcaoFuncTres != 8;){
				if(nomesDeterminados){
					system("cls");
					printf("[ Atualizando Estoque ]\n\n");
					printf("Digite [ 1 ] para - Digitar a quantia em estoque de cada produto\n");
					printf("Digite [ 2 ] para - Digitar a quantia mínima de cada produto\n");
					printf("Digite [ 3 ] para - Digitar o valor unitário de cada produto\n");
					printf("Digite [ 0 ] para - Voltar ao menu inicial\n");
					printf("Digite [ 8 ] para - Finalizar \n");
					fflush(stdin);
					scanf("%d", &opcaoFuncTres);
					
					if(opcaoFuncTres == 1){
						
						if(minimoDeterminados){
							printf("\n[ QUANTIA EM ESTOQUE ]\n");
							for(i = 0; i < qp; i++){
								printf("Digite quantos do %dº produto (%s) há em estoque: ", i + 1, nomeProdutos[i]);
								scanf("%f", &tabelaQuantiaPreco[i][0]);
								
								if(tabelaQuantiaPreco[i][0] < tabelaQuantiaPreco[i][1]){
									printf("\n[ VALOR INVÁLIDO - TENTATIVA NÃO CONTABILIZADA]\n\n");
									i--;
								}
								
								if(i == qp-1){
									system("cls");
									printf("[ TODOS VALORES FORAM COMPUTADOS - ESCOLHA O QUE DESEJA FAZER A SEGUIR ]\n");
									printf("\nDigite [ 0 ] para - Voltar ao menu inicial");
									printf("\nDigite [ 1 ] para - Continuar atualizando estoque");
									printf("\nDigite [ 8 ] para - Finalizar\n");
									scanf("%d", &opcaoFuncTres);
								}	
							}
						}else{
							system("cls");
							printf("[ALERTA] Informe a quantidade mínima primeiro [ALERTA]\n");
							printf("\nDigite [ 0 ] para - Voltar ao menu inicial");
							printf("\nDigite [ 1 ] para - Continuar atualizando estoque");
							printf("\nDigite [ 8 ] para - Finalizar\n");
							scanf("%d", &opcaoFuncTres);
						}
					}else if(opcaoFuncTres == 2){
						printf("\n[ QUANTIA MINÍMA PARA ESTOQUE ]\n");
						for(i = 0; i < qp; i++){
							minimoDeterminados = 1;
							printf("Digite a quantia mínima do %dº produto exigida para o produto (%s): ", i + 1, nomeProdutos[i]);
							scanf("%f", &tabelaQuantiaPreco[i][1]);
							
							if(i == qp-1){
								system("cls");
								printf("[ TODOS VALORES FORAM COMPUTADOS - ESCOLHA O QUE DESEJA FAZER A SEGUIR ]\n");
								printf("\nDigite [ 0 ] para - Voltar ao menu inicial");
								printf("\nDigite [ 1 ] para - Continuar atualizando estoque");
								printf("\nDigite [ 8 ] para - Finalizar\n");
								scanf("%d", &opcaoFuncTres);
							}
						}
					}else if(opcaoFuncTres == 3){
						printf("\n[ VALORES DE CADA PRODUTO ]\n");
						for(i = 0; i < qp; i++){
							printf("Digite o valor unitário do %dº produto (%s): ", i + 1, nomeProdutos[i]);
							scanf("%f", &tabelaQuantiaPreco[i][2]);
							
							if(tabelaQuantiaPreco[i][2] <= 0){
								printf("\n[ VALOR INVÁLIDO - TENTATIVA NÃO CONTABILIZADA]\n\n");
								i--;
							}
							
							if(i == qp-1){
								system("cls");
								printf("[ TODOS VALORES FORAM COMPUTADOS - ESCOLHA O QUE DESEJA FAZER A SEGUIR ]\n");
								printf("\nDigite [ 0 ] para - Voltar ao menu inicial");
								printf("\nDigite [ 1 ] para - Continuar atualizando estoque");
								printf("\nDigite [ 8 ] para - Finalizar\n");
								scanf("%d", &opcaoFuncTres);
							}	
						}
						
					}
					
					
				}else{
					system("cls");
					printf("[ALERTA] Nome dos produtos não cadastrados [ALERTA]\n\n");
					printf("\nDigite [ 0 ] para - Voltar");
					printf("\nDigite [ 8 ] para - Finalizar\n");
					fflush(stdin);
					scanf("%d", &opcaoFuncTres);
				}
			}
			if(opcaoFuncTres == 8){
				funcionalidadeEscolhida = 8;
			}
		}
		
		if(funcionalidadeEscolhida == 4){
			system("cls");
			if(nomesDeterminados && minimoDeterminados){
				printf("[ Informações de Estoque ]\n\n");
				printf("      Produto       | Quantia | Mínimo | Valor\n");
				for(i = 0; i < qp; i++){
					for(j = 0; j < 3; j++){
						if(j == 0){
							printf("%-*s", 19, nomeProdutos[i]);
							printf(" |    %.0f   |", tabelaQuantiaPreco[i][j]);
						}else if(j == 1){
							printf("   %.0f   |", tabelaQuantiaPreco[i][j]);
						}else{
							printf("R$%.2f", tabelaQuantiaPreco[i][j]);
						}
						
					}
					printf("\n");
				}
				printf("\nDigite [ 0 ] para - Voltar");
				printf("\nDigite [ 8 ] para - Finalizar\n");
				fflush(stdin);
				scanf("%d", &funcionalidadeEscolhida);
			}else{
				printf("[ALERTA] Nome ou quantias dos produtos não cadastrados [ALERTA]\n");
				printf("\nDigite [ 0 ] para - Voltar");
				printf("\nDigite [ 8 ] para - Finalizar\n");
				fflush(stdin);
				scanf("%d", &funcionalidadeEscolhida);
			}
		}
		
		if(funcionalidadeEscolhida == 5){
			system("cls");
			if(nomesDeterminados && minimoDeterminados){
				if(nomesDeterminados && minimoDeterminados){
					printf("[ RETIRAR PRODUTOS ]\n\n");
					printf("Digite o nome do produto que desejas retirar quantidades: ");
					fflush(stdin);
					scanf("%s", &retirarNome);
					printf("%s", retirarNome);
					
					for(i = 0; i != -1;i++){
						if(strcasecmp(retirarNome, nomeProdutos[i]) == 0){
							retiradaEscolhida = i;
							i = -2;
						}else if(i >= 6){
							printf("igualou");
							retiradaEscolhida = -1;
							i = -2;
						}
					}
					
				if(retiradaEscolhida == -1){
						system("cls");
						printf("[ NOME DIGITADO INVÁLIDO ]\n");
						printf("\nDigite [ 0 ] para - Voltar");
						printf("\nDigite [ 8 ] para - Finalizar\n");
						fflush(stdin);
						scanf("%d", &funcionalidadeEscolhida);
					}else{
						system("cls");
						printf("[ PRODUTO DETECTADO ]\n\n");
						printf("Digite a quantidade que deseja remover do produto %s:", nomeProdutos[retiradaEscolhida]);
						scanf("%d", &quantiaRetirar);
						
						if(quantiaRetirar > tabelaQuantiaPreco[retiradaEscolhida][0]){
							system("cls");
							printf("[ ALERTA ] Tentativa de retirada inválida [ ALERTA ]\n\n");
							printf("Quantidade em estoque: %.0f\n", tabelaQuantiaPreco[retiradaEscolhida][0]);
							printf("Quantidade solicitada para retirada: %d\n", quantiaRetirar);
							printf("\nDigite [ 0 ] para - Voltar");
							printf("\nDigite [ 8 ] para - Finalizar\n");
							fflush(stdin);
							scanf("%d", &funcionalidadeEscolhida);
						}else{
							tabelaQuantiaPreco[retiradaEscolhida][0] -= quantiaRetirar;
							system("cls");
							printf("[ RETIRADO COM SUCESSO ]\n");
							printf("\nDigite [ 0 ] para - Voltar");
							printf("\nDigite [ 8 ] para - Finalizar\n");
							scanf("%d", &funcionalidadeEscolhida);
						}
					}
				}
			}
			else{
				printf("[ALERTA] Nome ou quantias dos produtos não cadastrados [ALERTA]\n");
				printf("\nDigite [ 0 ] para - Voltar");
				printf("\nDigite [ 8 ] para - Finalizar\n");
				fflush(stdin);
				scanf("%d", &funcionalidadeEscolhida);
			}
		}
		
		if(funcionalidadeEscolhida == 6){
			system("cls");
			if(nomesDeterminados && minimoDeterminados){
				printf("[ PRODUTOS COM BAIXA QUANTIDADE ]\n\n");
				
				for(i = 0; i < qp; i++){
					if(tabelaQuantiaPreco[i][0] < tabelaQuantiaPreco[i][1]){
						printf("Produto: %s | Mínimo: %.0f | Quantia: %.0f\n", nomeProdutos[i], tabelaQuantiaPreco[i][1], tabelaQuantiaPreco[i][0]);
					}
				}
				printf("\nDigite [ 0 ] para - Voltar");
				printf("\nDigite [ 8 ] para - Finalizar\n");
				scanf("%d", &funcionalidadeEscolhida);
			}else{
				printf("[ALERTA] Nome ou quantias dos produtos não cadastrados [ALERTA]\n");
				printf("\nDigite [ 0 ] para - Voltar");
				printf("\nDigite [ 8 ] para - Finalizar\n");
				fflush(stdin);
				scanf("%d", &funcionalidadeEscolhida);
			}
		}
		
		if(funcionalidadeEscolhida == 7){
			system("cls");
			valorEstoque = 0;
			if(nomesDeterminados && minimoDeterminados){
				printf("[ VALOR TOTAL EM ESTOQUE ]\n\n");
				
				for(i = 0; i < qp; i++){
					valorEstoque += tabelaQuantiaPreco[i][0] * tabelaQuantiaPreco[i][2];
				}
				
				printf("O valor atual do estoque é R$%.2f", valorEstoque);
				
				printf("\n\nDigite [ 0 ] para - Voltar");
				printf("\nDigite [ 8 ] para - Finalizar\n");
				fflush(stdin);
				scanf("%d", &funcionalidadeEscolhida);
				
			}else{
				printf("[ALERTA] Nome ou quantias dos produtos não cadastrados [ALERTA]\n");
				printf("\nDigite [ 0 ] para - Voltar");
				printf("\nDigite [ 8 ] para - Finalizar\n");
				fflush(stdin);
				scanf("%d", &funcionalidadeEscolhida);
			}
		}
		
		if(funcionalidadeEscolhida == 8){
			system("cls");
			printf("[ PROCESSO DE FINALIZAÇÃO ]\n\n");
			printf("Digite [ VOLTAR ] - se deseja voltar\n");
			printf("Digite [ SAIR ] - se deseja finalizar\n\n");
			fflush(stdin);	
			gets(rodarOpcoes);
		}
		
		system("cls"); //limpar a tela
	}

	
	return 0;
}
