#include<bits/stdc++.h>
using namespace std;
int a[128];
string pw,ms;
void init(){
	for(int i=0;i<128;i++){
		a[i]=i;
	}
	return;
} 
void rndset(){
	for(int i=0;i<128;i++){
		int j=rand()%64;
		if(i+j>127){
			swap(a[i],a[i-j]);
		}else{
			swap(a[i],a[i+j]);
		}
	}
	return;
}
int encode(){
	
	cin>>pw>>ms;
	int sd=1;
	for(int i=0;i<pw.length();i++){
		sd*=pw[i];
	}
	srand(sd>0?sd:-sd);
	/*for(int i=1;i<=256;i++){
		a[i]='a'+rand()%26-1;
	}*/
	for(int i=0;i<ms.length();i++){
		ms[i]=a[(int)ms[i]];
	}
	cout<<ms;
	return 0;
}
void decode(){
	cin>>pw>>ms;
	int sd=1;
	for(int i=0;i<pw.length();i++){
		sd*=pw[i];
	}
	srand(sd>0?sd:-sd);
	/*for(int i=0;i<128;i++){
		a[i]='a'+rand()%26-1;
	}*/
	for(int i=0;i<ms.length();i++){
		bool flag=false;
		for(int j=0;j<128;j++){
			if(a[j]==ms[i]){
				ms[i]=char(j);
				flag=true;
				break;
			}
		}
		if(!flag){
			cout<<"Fuck you!!!";
			exit(0);
		}
	}
	cout<<ms;
}
int main(){
	int op;
	cin>>op;
	init();
	rndset();
	if(op==1){
		decode();
	} else{
		encode();
	}
	cout<<endl;
	main();
	return 0;
}
