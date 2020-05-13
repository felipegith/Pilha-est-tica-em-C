		/// PILHA EST�TICA

#include<stdio.h>
#include<stdlib.h>

#define MAXTAM 100  // Vari�vel global


// 

typedef struct {
	int Item[MAXTAM];  // Vetor com toods os itens que eu vou adicionar e remover da pilha
	int Topo; 			//Vari�vel que vai indicar o topo da pilha
}Tpilha;

// INICAR NOSSA PILHA 

void Tpilha_Inicia (Tpilha *p){   //(Tpilha *p) seria um ponteiro p do TIPO Tpilha. Esse ponteiro possuiu os campos de dados da nossa STRUCT || // *p Vai nos ajudar no programa principal. N�s estamos passar *p como referencia. Ou seja,  todo valor que for alterado dentro desta fun��o ser� retornado l� no nosso programa principal. Por isso a necessidade de se usar um ponteiro.
	p->Topo= -1;  // Isso indica que a nossa pilha est� vazia
	
}
// VERIFICA SE A PILHA EST� VAZIA

int Tpilha_Vazia(Tpilha *p){  // Fun��o para verificar se a pilha esta vazia !
	if(p->Topo == -1 ){   // SE A PILHA ESTIVER VAZIA, A FUN��O IR� RETORNAR O VALOR 1
		return 1;
	}else{
		return 0;                // SE A PILHA N�O ESTIVER VAZIA IR� RETORNAR 0 
	}
}
// VERIFICA SE A PILHA EST� CHEIA

int Tpilha_Cheia (Tpilha *p){   //FUN�AO PARA VERIFICAR SE A PILHA ESTA LOTADA, OU SEJA, ESSA FUN��O VERIFICA SE A PILHA ULTRAPASSA O VALOR M�XIMO DO NOSSO VETOR. EXEMPLO: TEMOS UM VETOR DE 50, ESSA FUN��O VAI VERIFICAR SE A PILHA ESTA ULTRAPASSANDO ESSE VALOR
  if(p->Topo == MAXTAM-1){  // SE P->TOPO FOR IGUAL AO VALOR M�XIMO DO VETOR -1, SIGNIFICA QUE A NOSSA PILHA J� ESTA CHEIA. ENT�O ELE IR� RETORNAR 1 
  		return 1;
  }else{
  		return 0; // CASO CONTRARIO, RETORNAR� 0 
  }
}
  // INSERINDO VALRO NA PILHA!
  
  void Tpilha_Insere (Tpilha *p, int x) {   // int x ser� o valor que n�s iremos inserir na nossa pilha.
  
  									//Para inserir um item na pilha, � preciso saber se espa�o dentro do vetor. Para isso, n�s iremos chamar a fun��o que criamos anteriormente 	
  if(Tpilha_Cheia(p)== 1){ 			// Nesse if, n�s chamamos a  fun��o Tpilha_cheia e passamos como par�metro o nosso ponteiro pilha (p). Se ele for igual a 1, significa que a pilha j� est� cheia
	printf("ERRO: PILHA CHEIA"); 
		 		
  }else{  // Entraremos no else quando a nossa pilha n�o estiver cheia.
  	
	  p->Topo++; // Utilizando esse comando, n�s iremos garantir que o valor X ser� inserido sempre na pr�xima posi��o v�lida do vetor 
  	  
	  p->Item[p->Topo] = x;     // Inserindo um valor dentro dessa posi��o. Como isso ir� funcionar? Usando o p->Item, n�s chamamos o nosso vetor que foi declarado l� na nossa struct. Apos isso, n�s inserimos o valor de X aonde o nosso Topo est�.  p->Item[p->Topo] = x;
  }								
  								//REFOR�ANDO!!!!  O valor x vai ser inserido na posi��o aonde a minha vari�vel de Topo esta indicada.
}

int Tpilha_Retira(Tpilha *p){
	int aux;  // Vari�vel auxiliar 
	if(Tpilha_Vazia(p) == 1 ){     // Antes de tirar um valor da pilha, n�s precisamos verificar se esta pilha VAZIA.
		printf("\n ERROR: PILHA VAZIA!");
	
}else{   // CASO A PILHA N�O ESTEJA VAZIA, N�S ENTRAREMOS NO NOSSO ELSE
	
	aux = p->Item[p->Topo];     // Nessa linha a vari�vel aux recebe o valor que est� dentro do Vetor p->Item e esse p->Item[p->Topo] recebe a POSI��O REFERENTE AO NOSSO TOPO, OU SEJA p->Item[p->Topo]
	
	p->Topo--;      // Na linha 64, n�s removemos um valor. J� na linha 66 o que acontece:  Ap�s remover um valor, o nosso Topo n�o ser� mais a ultima posi��o, mas sim, A POSI��O ANTERIOR  
	
	return aux;
	
}
}
int main(){
	
	Tpilha *p = (Tpilha*)malloc(sizeof(Tpilha));         // Com o comando (Tpilha*)malloc(sizeof(Tpilha)); n�s estamos ALOCANDO ESPA�O SUFICIENTE NA MEM�RIA 
	Tpilha_Inicia(p); //Chamando a nossa fun��o que foi criada anteriormente para INCIAR nossa pilha 
	
	Tpilha_Insere(p, 1);    // INSERINDO OS VALORES.. CHAMAMOS A FUN��O QUE FOI CRIADA ANTERIORMENTE E PASSAMOS COMO PAR�METRO O NOSSO P E UM VALOR INT X , COMO FOI DECLARADO NA FUN�AO DA LINHA 42!!
	Tpilha_Insere(p, 2);
	Tpilha_Insere(p, 3);
	
	int aux;
	
	aux = Tpilha_Retira(p);           // Nossa vari�vel aux vai receber o valor que ser� REMOVIDO.
		printf("\n SAIU: %d", aux);
	aux = Tpilha_Retira(p);           // Nossa vari�vel aux vai receber o valor que ser� REMOVIDO.
		printf("\n SAIU: %d", aux);
	aux = Tpilha_Retira(p);           // Nossa vari�vel aux vai receber o valor que ser� REMOVIDO.
		printf("\n SAIU: %d", aux);
	// Nesses ultimos comandos, basicamente, n�s tiramos os itens da pilha, Se voc� observar, o primeiro item da pilha que ser� removido vai ser o que foi inserido por ulitmo. No nosso exemplo, foi o Tpilha_Insere(p, 3); 
	
	// Se n�s adicionarmos mais um comando  aux = Tpilha_Retira(p); printf("\n SAIU %d", aux);  iremos verificar o comando de erro que foi criado na fun��o acima. Ele simplemente mostrar� o erro porque n�o existe mais nenhum item para ser removido da pihal
		
	return 0;
}

