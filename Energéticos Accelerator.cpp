#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int opt, elementos;
main()
{
	struct func
	{
		char nome_empresa[100];
		int quant;
		float valor_compra;
		float ICMS, IPI, PIS, COFINS;
		float valor_total;
		float total_soma_impostos, total_soma_mercadorias, total_soma_geral;
		int n;
		float desconto, novo_valor, novo_valor_total;
	};
	func registro[100];
	int i;
	float aux_ICMS, aux_IPI, aux_PIS, aux_COFINS;
	float aux_compra, aux_total, aux_quant;
	float maior_venda;
	printf("*==================INFORME OS DADOS ABAIXOS==================*\n");
	for (i = 0; i < 100; i++)
	{
		printf("Nome da empresa:");
		scanf("%s", registro[i].nome_empresa);
		printf("\nQuantidade de energetico:");
		scanf("%d", &registro[i].quant);
		aux_quant = aux_quant + registro[i].quant;

        elementos++;

		registro[i].valor_compra = registro[i].quant * 4.50;
		registro[i].ICMS = registro[i].valor_compra * 0.18;
		registro[i].IPI = registro[i].valor_compra * 0.04;
		registro[i].PIS = registro[i].valor_compra * 0.0186;
		registro[i].COFINS = registro[i].valor_compra * 0.0854;
		registro[i].valor_total = registro[i].valor_compra + registro[i].ICMS + registro[i].IPI + registro[i].PIS + registro[i].COFINS;

		aux_ICMS = aux_ICMS + registro[i].ICMS;
		aux_IPI = aux_IPI + registro[i].IPI;
		aux_PIS = aux_PIS + registro[i].PIS;
		aux_COFINS = aux_COFINS + registro[i].COFINS;
		registro[i].total_soma_impostos = aux_ICMS + aux_IPI + aux_PIS + aux_COFINS;

		aux_compra = aux_compra + registro[i].valor_compra;
		registro[i].total_soma_mercadorias = aux_compra;

		aux_total = aux_total + registro[i].valor_compra + registro[i].ICMS + registro[i].IPI + registro[i].PIS + registro[i].COFINS;
		registro[i].total_soma_geral = aux_total;

		printf("\nCliente: %s;\tQuantidade: %d\n", registro[i].nome_empresa, registro[i].quant);
		printf("Valor compra: R$%.2f\n", registro[i].valor_compra);
		printf("ICMS: R$%.2f\n", registro[i].ICMS);
		printf("IPI: R$%.2f\n", registro[i].IPI);
		printf("PIS: R$%.2f\n", registro[i].PIS);
		printf("COFINS: R$%.2f\n", registro[i].COFINS);
		printf("Valor total: R$%.2f\n", registro[i].valor_total);
		printf("Se deseja encerrar, digite 1, se deseja continuar, digite 2: ");
		scanf("%d", &opt);

		switch (opt)
		{
		case 1:
			printf("\n*=============== TOTAL ===============*\n");
			printf("Total Impostos: R$%.2f\n", registro[i].total_soma_impostos);
			printf("Total Mercadorias: R$%.2f\n", registro[i].total_soma_mercadorias);
			printf("Total Geral: R$%.2f\n", registro[i].total_soma_geral);
			for (int j = 0; j < elementos; j++)
			{

				if (registro[j].quant > 500)
				{
					
					if ((registro[j].quant >= 600) && (registro[j].quant <= 699))
					{
						registro[j].desconto = registro[j].valor_compra * 0.20; 
						registro[j].novo_valor = registro[j].valor_compra - registro[j].desconto;
						registro[j].novo_valor_total = registro[j].novo_valor + registro[j].ICMS + registro[j].IPI + registro[j].PIS + registro[j].COFINS;
						printf("\n*=============== DESCONTO ===============*\n");
						printf("\nCliente: %s;\tQuantidade: %d\n", registro[j].nome_empresa, registro[j].quant);
						printf("Valor compra: R$%.2f\n", registro[j].valor_compra);
						printf("Valor do desconto: R$%.2f\n", registro[j].desconto);
						printf("Novo valor de compra: R$%.2f\n", registro[j].novo_valor);
						printf("Novo valor total: R$%.2f\n", registro[j].novo_valor_total);
					}
					if (registro[j].quant >= 700)
					{
						registro[j].desconto = registro[j].valor_compra * 0.30;
						registro[j].novo_valor = registro[j].valor_compra - registro[j].desconto;
						registro[j].novo_valor_total = registro[j].novo_valor + registro[j].ICMS + registro[j].IPI + registro[j].PIS + registro[j].COFINS;
						printf("\n*=============== DESCONTO ===============*\n");
						printf("\nCliente: %s;\tQuantidade: %d\n", registro[j].nome_empresa, registro[j].quant);
						printf("Valor compra: R$%.2f\n", registro[j].valor_compra);
						printf("Valor do desconto: R$%.2f\n", registro[j].desconto);
						printf("Novo valor de compra: R$%.2f\n", registro[j].novo_valor);
						printf("Valor total: R$%.2f\n", registro[j].valor_total);
						printf("Novo valor total: R$%.2f\n", registro[j].novo_valor_total);
					}
				}
			}
			exit(1);
			break;

		case 2:
			continue;
			break;
		}
	}
}
