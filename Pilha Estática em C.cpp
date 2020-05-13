		/// PILHA ESTÁTICA

#include<stdio.h>
#include<stdlib.h>

#define MAXTAM 100  // Variável global


// 

typedef struct {
	int Item[MAXTAM];  // Vetor com toods os itens que eu vou adicionar e remover da pilha
	int Topo; 			//Variável que vai indicar o topo da pilha
}Tpilha;

// INICAR NOSSA PILHA 

void Tpilha_Inicia (Tpilha *p){   //(Tpilha *p) seria um ponteiro p do TIPO Tpilha. Esse ponteiro possuiu os campos de dados da nossa STRUCT || // *p Vai nos ajudar no programa principal. Nós estamos passar *p como referencia. Ou seja,  todo valor que for alterado dentro desta função será retornado lá no nosso programa principal. Por isso a necessidade de se usar um ponteiro.
	p->Topo= -1;  // Isso indica que a nossa pilha está vazia
	
}
// VERIFICA SE A PILHA ESTÁ VAZIA

int Tpilha_Vazia(Tpilha *p){  // Função para verificar se a pilha esta vazia !
	if(p->Topo == -1 ){   // SE A PILHA ESTIVER VAZIA, A FUNÇÃO IRÁ RETORNAR O VALOR 1
		return 1;
	}else{
		return 0;                // SE A PILHA NÃO ESTIVER VAZIA IRÁ RETORNAR 0 
	}
}
// VERIFICA SE A PILHA ESTÁ CHEIA

int Tpilha_Cheia (Tpilha *p){   //FUNÇAO PARA VERIFICAR SE A PILHA ESTA LOTADA, OU SEJA, ESSA FUNÇÃO VERIFICA SE A PILHA ULTRAPASSA O VALOR MÁXIMO DO NOSSO VETOR. EXEMPLO: TEMOS UM VETOR DE 50, ESSA FUNÇÃO VAI VERIFICAR SE A PILHA ESTA ULTRAPASSANDO ESSE VALOR
  if(p->Topo == MAXTAM-1){  // SE P->TOPO FOR IGUAL AO VALOR MÁXIMO DO VETOR -1, SIGNIFICA QUE A NOSSA PILHA JÁ ESTA CHEIA. ENTÃO ELE IRÁ RETORNAR 1 
  		return 1;
  }else{
  		return 0; // CASO CONTRARIO, RETORNARÁ 0 
  }
}
  // INSERINDO VALRO NA PILHA!
  
  void Tpilha_Insere (Tpilha *p, int x) {   // int x será o valor que nós iremos inserir na nossa pilha.
  
  									//Para inserir um item na pilha, é preciso saber se espaço dentro do vetor. Para isso, nós iremos chamar a função que criamos anteriormente 	
  if(Tpilha_Cheia(p)== 1){ 			// Nesse if, nós chamamos a  função Tpilha_cheia e passamos como parâmetro o nosso ponteiro pilha (p). Se ele for igual a 1, significa que a pilha já está cheia
	printf("ERRO: PILHA CHEIA"); 
		 		
  }else{  // Entraremos no else quando a nossa pilha não estiver cheia.
  	
	  p->Topo++; // Utilizando esse comando, nós iremos garantir que o valor X será inserido sempre na próxima posição válida do vetor 
  	  
	  p->Item[p->Topo] = x;     // Inserindo um valor dentro dessa posição. Como isso irá funcionar? Usando o p->Item, nós chamamos o nosso vetor que foi declarado lá na nossa struct. Apos isso, nós inserimos o valor de X aonde o nosso Topo está.  p->Item[p->Topo] = x;
  }								
  								//REFORÇANDO!!!!  O valor x vai ser inserido na posição aonde a minha variável de Topo esta indicada.
}

int Tpilha_Retira(Tpilha *p){
	int aux;  // Variável auxiliar 
	if(Tpilha_Vazia(p) == 1 ){     // Antes de tirar um valor da pilha, nós precisamos verificar se esta pilha VAZIA.
		printf("\n ERROR: PILHA VAZIA!");
	
}else{   // CASO A PILHA NÃO ESTEJA VAZIA, NÓS ENTRAREMOS NO NOSSO ELSE
	
	aux = p->Item[p->Topo];     // Nessa linha a variável aux recebe o valor que está dentro do Vetor p->Item e esse p->Item[p->Topo] recebe a POSIÇÃO REFERENTE AO NOSSO TOPO, OU SEJA p->Item[p->Topo]
	
	p->Topo--;      // Na linha 64, nós removemos um valor. Já na linha 66 o que acontece:  Após remover um valor, o nosso Topo não será mais a ultima posição, mas sim, A POSIÇÃO ANTERIOR  
	
	return aux;
	
}
}
int main(){
	
	Tpilha *p = (Tpilha*)malloc(sizeof(Tpilha));         // Com o comando (Tpilha*)malloc(sizeof(Tpilha)); nós estamos ALOCANDO ESPAÇO SUFICIENTE NA MEMÓRIA 
	Tpilha_Inicia(p); //Chamando a nossa função que foi criada anteriormente para INCIAR nossa pilha 
	
	Tpilha_Insere(p, 1);    // INSERINDO OS VALORES.. CHAMAMOS A FUNÇÃO QUE FOI CRIADA ANTERIORMENTE E PASSAMOS COMO PARÂMETRO O NOSSO P E UM VALOR INT X , COMO FOI DECLARADO NA FUNÇAO DA LINHA 42!!
	Tpilha_Insere(p, 2);
	Tpilha_Insere(p, 3);
	
	int aux;
	
	aux = Tpilha_Retira(p);           // Nossa variável aux vai receber o valor que será REMOVIDO.
		printf("\n SAIU: %d", aux);
	aux = Tpilha_Retira(p);           // Nossa variável aux vai receber o valor que será REMOVIDO.
		printf("\n SAIU: %d", aux);
	aux = Tpilha_Retira(p);           // Nossa variável aux vai receber o valor que será REMOVIDO.
		printf("\n SAIU: %d", aux);
	// Nesses ultimos comandos, basicamente, nós tiramos os itens da pilha, Se você observar, o primeiro item da pilha que será removido vai ser o que foi inserido por ulitmo. No nosso exemplo, foi o Tpilha_Insere(p, 3); 
	
	// Se nós adicionarmos mais um comando  aux = Tpilha_Retira(p); printf("\n SAIU %d", aux);  iremos verificar o comando de erro que foi criado na função acima. Ele simplemente mostrará o erro porque não existe mais nenhum item para ser removido da pihal
		
	return 0;
}

