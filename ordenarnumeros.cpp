#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int **(mx(int **nums,int c, int **res)){
	for (int p=0;p<c;p++){
		res[p]=(int *)malloc(sizeof(int));
		*(*(res+p))=*(*(nums+p));
	}
	return res;
}
int **(mpares(int **nums,int c, int **res,int len)){
	int cont=0;
	int rep=0;
	for (int p=0;p<c;p++){
		res[p]=(int *)malloc(sizeof(int));
	}
	while (cont<c){
	    if ((*(*(nums+rep)))%2==0){
		    *(*(res+cont))=*(*(nums+rep));
		    cont=cont+1;
	    }
	    rep=rep+1;
	    if ((rep==len)&&(cont<c)){
	        for (cont;cont<c;cont++){
	           *(*(res+cont))=(-1);
	        }
	    }
	}
	return res;
}
int media(int **nums, int c){
    int res=0;
    for (int p=0;p<c;p++){
		res=res+*(*(nums+p));
	}
	res=res/c;
	return res;
}

int main(){
	int i=10;
	int *n_plh[i];
	int stn;
	int n1;
	
	for (int ct=0;ct<i;ct++){
		cout<<"Introduce el numero entero "<<(ct+1)<<": ";
		cin>>n1;
		n_plh[ct]=(int *)malloc(sizeof(int));
		*(*(n_plh+ct))=n1;
	}
	
	for (int cont=0;cont<i;cont++){
		for (int t=0;t<(i-1);t++){
			if (*(*(n_plh+t))<*(*(n_plh+t+1))){
				stn=*(*(n_plh+t));
				*(*(n_plh+t))=*(*(n_plh+t+1));
				*(*(n_plh+t+1))=stn;
			}
		}	
	}
	for(int aa=0;aa<i;aa++){
		cout<<"Numero "<<aa+1<<": "<<*(*(n_plh+aa))<<endl;
	}
	int m=3;
	
	int **list3;
	int *emp[m];//Para poder devolver un puntero de una función, hace falta entregarle una variable para que use,
    list3=(mx(n_plh,m,emp));//porque no puede devolver variables locales.
    for (int suu=0;suu<m;suu++){
        cout<<suu<<": "<<*(*(list3+suu))<<endl;
    }
    
    cout<<"Media de los "<<m<<" mayores: "<<media(n_plh, m);
    
    int **list4;
	int *ee[m];/
    list4=(mpares(n_plh, m, ee, i));
    for (int pe=0;pe<m;pe++){
        cout<<pe<<" (par): "<<*(*(list4+pe))<<endl;
    }
    cout<<"-(Cada '-1' indica un numero par que faltaba)"<<endl;
	
	return 0;
}
