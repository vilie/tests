#include <iostream>
#include <vector>


using namespace std;

typedef struct pachet{
	int from, to, nr_etaje, rutat;
	vector<int> drum;
	vector<int> tip;
}pachet;


int bit_2_XOR_bit_3(int b){
	if( (b & (1 << 1) ) ^ (b & (1 << 2) )  ){
		return 1;
	}
	
	return 0;
}


int bit_pozitie(int b, int pos){
	if( b & ( 1 << pos ) ){
		return 1;
	}
	
	return 0;
}


void do_0(){
	cout << "0 ";
}

void do_1(){
	cout << "1 ";
}

int etaj_1(int from){
	return from/2;
}

int etaj_2(int current, int bit){
	if(current == 0){
		if(bit == 0){
			return 0;
		}else{
			return 2;
		}
	}
	if(current == 1){
		if(bit == 0){
			return 0;
		}else{
			return 2;
		}
	}
	if(current == 2){
		if(bit == 0){
			return 1;
		}else{
			return 3;
		}
	}
	if(current == 3){
		if(bit == 0){
			return 1;
		}else{
			return 3;
		}
	}
}


int etaj_butterfly(int current, int bit){
	if(current == 0){
		if(bit == 0){
			return 0;
		}else{
			return 1;
		}
	}
	if(current == 1){
		if(bit == 0){
			return 0;
		}else{
			return 1;
		}
	}
	if(current == 2){
		if(bit == 0){
			return 2;
		}else{
			return 3;
		}
	}
	if(current == 3){
		if(bit == 0){
			return 2;
		}else{
			return 3;
		}
	}
}


int etaj_ultim(int current, int bit){
	if(current == 0){
		if(bit == 0){
			return 0;
		}else{
			return 1;
		}
	}
	if(current == 1){
		if(bit == 0){
			return 2;
		}else{
			return 3;
		}
	}
	if(current == 2){
		if(bit == 0){
			return 0;
		}else{
			return 1;
		}
	}
	if(current == 3){
		if(bit == 0){
			return 2;
		}else{
			return 3;
		}
	}
}


void compute_route(pachet& a){
	int i;
	//Primul etaj
	int bloc_curent = etaj_1(a.from);
	a.drum.push_back(bloc_curent);
	if(a.from % 2 == 0){
		a.tip.push_back(0);
		bloc_curent =  etaj_2(bloc_curent, 0);
	}else{
		a.tip.push_back(1);
		bloc_curent =  etaj_2(bloc_curent, 1);
	}
	a.drum.push_back(bloc_curent);
	
	//Al 2-lea etaj
	if(bit_2_XOR_bit_3(a.from) == 0){
		a.tip.push_back(0);
		bloc_curent = etaj_butterfly(bloc_curent, 0);
	}else{
		a.tip.push_back(1);
		bloc_curent = etaj_butterfly(bloc_curent, 1);
	}
	a.drum.push_back(bloc_curent);
	//Etajele 3, 4, 5
	for(i = 2; i >= 0; i--){
		if( bit_pozitie(a.to, i) == 0 ){
			a.tip.push_back(0);
			if(i == 2){
				bloc_curent = etaj_butterfly(bloc_curent, 0);
			}
			if(i == 1){
				bloc_curent = etaj_ultim(bloc_curent, 0);
			}
		}else{
			a.tip.push_back(1);
			if(i == 2){
				bloc_curent = etaj_butterfly(bloc_curent, 1);
			}
			if(i == 1){
				bloc_curent = etaj_ultim(bloc_curent, 1);
			}
		}
		if((i == 2) || (i == 1)){
			a.drum.push_back(bloc_curent);
		}
	}
}


void print_transmisie(pachet& p, int i){
	//cout << "Nr. " << i << " - " << p.from << "->" << p.to << ": ";
	for(int j = 0; j < p.tip.size(); j++){
		cout << p.drum[j] << " ";
		if(p.tip[j] == 0){
			cout << "( / ) ";
		}else{
			cout << "( \\ ) ";
		}
		cout << " ";
	}
	cout << "\n";
}


int has_to_route(vector<pachet>& transmisii){
	for(int i = 0; i < transmisii.size(); i++){
		if(transmisii[i].rutat == 0){
			return 1;
		}
	}
	
	return 0;
}



int main(){
	int N = 8;
	int n = 3;
	int i, j, m;
	
	vector<pachet> transmisii;
	
	cout << "Numarul de etape: ";
	cin >> m;
	cout << "\n";
	
	for(i = 0; i < m; i++){
		pachet a;
		cin >> a.from >> a.to;
		a.rutat = 0;
		compute_route(a);
		transmisii.push_back(a);
	}
	
	
	int timp_curent = 0;
	
	vector<int> coliziuni;
	for(i = 0; i < 5; i++){
		coliziuni.push_back(0);
	}
	
	do{
		timp_curent++;
		cout << "Pasul " << timp_curent << "\n";
		
		for(i = 0; i < m; i++){
			if(transmisii[i].rutat == 0){
			
				int ok = 1;
				for(j = 0; j < 5; j++){
									int test = coliziuni[j] & (1 << transmisii[i].drum[j]);
					if(test != 0){
						ok = 0;
					}
				}
				
				if(ok){
					print_transmisie(transmisii[i], i);
					transmisii[i].rutat = 1;
					for(j = 0; j < 5; j++){
						//Pentru fiecare etaj in parte, marcheaza blocul corespunzator.
						coliziuni[j] = coliziuni[j] | (1 << transmisii[i].drum[j]);
					}
				}
			}
		}
		
		for(i = 0; i < 5; i++){
			coliziuni[i] = 0;
		}
	}while(has_to_route(transmisii));
	return 0;
}
