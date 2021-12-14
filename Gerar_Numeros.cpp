#include <iostream>
#include <time.h>
#include <math.h>
#include <vector>

using namespace std;

int main (){
	
	setlocale(LC_ALL,"portuguese");
	srand(time(NULL));
	int qtde,max,dec;
	cout<<"Digite a quantidade de números: ";
	cin>>qtde;
	cout<<"Digite o valor máximo : ";
	cin>>max;
	cout<<"Digite a quantidade de casas decimais: ";
	cin>>dec;
	cout<<"\nProcessando..\n\n";
	cout<<"Tempo estimado: "<<0.000004*qtde<<" segundos\n\n";
	clock_t timer = clock();

	max = max*pow(10,dec);

	if (qtde > max){
		cout<<"Entradas inválidas.";
		return -1;
	}
	vector <bool> array;
	for (int i=0;i<max;i++){
		array.push_back(true);
	}
	FILE* f;	
	f = fopen("ValoresGerados.txt","w");
		
	for (int i=0;i<qtde;i++){	
		
		verify:
		int auxA,auxB,auxP;
		auxP = pow(max,0.5);
		auxA = rand()%auxP;
		auxB = rand()%auxP;
		int pos = auxA*(rand()%auxP) + auxB;		
		double aux = (double) pos/pow(10,dec);	
		
		if (array[pos]){
			array[pos] = false;
			
			char output[100];
			string aux2 = to_string(aux);
			int cont=0;
			
			for (int i=0;i<aux2.length();i++){		
				output[i] = aux2[i];
				cont=i;
			}
			output[cont+1] = '/';
			output[cont+2] = '\0';
			
			fputs(output,f);
		}
		else{
			goto verify;
		}
	}
	fclose(f);	
	timer = clock() - timer; 
	cout<<"Operação concluída em "<<(float)timer/CLOCKS_PER_SEC<<" Segundos \n\n";
	return 0;
}
