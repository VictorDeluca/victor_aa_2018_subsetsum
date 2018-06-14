//Complexidade: O(n*sum), i.e. pseudo-polinomial. Melhor que exponencial.
//Devido ao tamanho da nossa dp, devemos ter n<=1000 e sum <=1000. Algumas maquinas
//possuem problemas em alocar blocos de memoria contiguos muito maiores que isto. Uma 
//solucao utilizando um map<pair<int,int>,int> permite limites maiores, ao custo de uma 
//complexidade um pouco pior devido ao custo adicional de acessar o map.

#include <bits/stdc++.h>
using namespace std;

int vetor[1000],dp[1001][1001];

int main(){
	memset(dp,0,sizeof(dp));
	int sum,n,i,j;
	cin >> sum >> n;
	for(i=0;i<n;i++){
		cin >> vetor[i];
	}

	//Solucao iterativa. Uma solucao recursiva seria possivel e mais simples de enxergar,
	//porem a complexidade e mais intuitiva de se observar na versao iterativa (Embora
	//seja a mesma em ambos os casos). 
	//Alem disso, e possivel otimizar espaco reescrevendo a dp de forma a armazenar apenas 
	//dp[j], ignorando o i. Afinal, dp[i+1] depende apenas de dp[i]. Mas nao precisamos 
	//fazer isso aqui. O problema "Cards" necessita de uma otimizacao parecida.
	dp[0][0] = 1;
	for(i=1;i<=n;i++){
		for(j=sum;j>=0;j--){
			if(dp[i-1][j]==1){
				dp[i][j] = 1;
				if(j + vetor[i-1] <= sum) dp[i][j+vetor[i-1]] = 1;
			}
		}
	}
	//Em cada passo, descobrimos os valores que podemos obter utilizando os elementos do
	//conjunto ate "i". Para cada soma possivel no intervalo [1,i-1], podemos acrescentar
	//vetor[i] ou nao.

	if(dp[n][sum]==1) printf("E possivel obter esta soma com este conjunto\n");
	else printf("Nao e possivel obter essa soma com este conjunto\n");

	return 0;
}
