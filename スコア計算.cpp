#include<stdio.h>
#include<math.h>
#include<string.h>
int main(void)	//メイン関数//
{
	int i,jc,jr,Jr,m,N,nr,Nr,re,s,S;
	double a,as,j,js,jrp,ms;
	char rst,jp[5];
	
	printf("チュウニズム スコア計算\n");

	do{ //全体再入力//
		
	do{	//理論値時の再入力//
		
	do{	//スコア0時の再入力//
		
	do{	//Error時のリセット//
		
	do{	//スコア再入力//
		re=0;	//リセットの初期値入力//
	
	printf("スコア:");
	scanf("%d",&S);	
		if(1010000>=S) break;	//理論値以下の場合 do文を回避//
		else if(1010000<S)	//理論値を超えた時の処理//
			printf("もう一度入力してください　Enterキーで続行");
			scanf("%c",&rst);
		}	while(getchar()=='\n');	//改行でスコアのみの再入力を実行//
		
	do{	//ノーツ数再入力//
	printf("ノーツ数:");
	scanf("%d",&N);
		if(N>0) break;
		else if(N<=0)
			printf("もう一度入力してください　Enterキーで続行");
			scanf("%c",&rst);
		}	while(getchar()=='\n');	//改行でスコアのみの再入力を実行//
		if(1010000!=S) break;
		else if(1010000==S)	//理論値だった時の処理//
			printf("%d-0-0-0\n",N);
			printf("再入力する場合は【1】を入力:");	
			scanf("%d",&re);
			printf("\n");
			} while(re==1);	//1で再入力を実行//
			if(1010000==S&&re!=1){
		printf("Finished");
		return(0);
	}
		if(0!=S) break;
		else if(0==S)
			printf("0-0-0-%d",N);
			printf("再入力する場合は【1】を入力:");	
		scanf("%d",&re);
		printf("\n");
	} while(re==1);	//1で再入力を実行//
	if(0==S&&re!=1){
		printf("Finished");
		return(0);
	}
	printf("赤j割合を算出しますか？【Yes/No】\n");	//文字列を比較し分岐//
	scanf("%s",jp);
		if(strcmp(jp,"Yes")==0){
		for(i=1;i<=10;i++){
		printf("%d曲目の赤j数:",i);
		scanf("%d",&Jr);
		printf("そのノーツ数:");
		scanf("%d",&Nr);
		jr=Jr+jr;
		nr=Nr+nr;
		}
		if(strcmp(jp,"No")==0){
		break;
		}
	if(Jr==0||Nr==0)	//入力しなかった時の処理 (未入力の場合 25%を代入)//
		jrp=0.25;
		break;
	}
	if(jr>=1&&nr>=1){
	jrp=jr/nr;	//合計ノーツ数の赤j割合計算//
	}
	//ミス処理//
	printf("ミス数:");
	scanf("%d",&m);
	s=1010000-S;	//理論値と入力スコアの差分//	
	ms=1010000/N;	//1ノーツあたりのMiss減少スコア//
	if(m>0){
	s=s-(m*ms);	//入力スコアとMiss分のスコアを減算//
	}
	
	//赤j処理//
	js=10000/N;	//1ノーツあたりの赤j減少スコア//
	j=(s/js)*jrp;	//赤j割合を基に赤jを算出//
	j=floor(j);	//小数点切り捨て//
	s=s-(js*j);

	//アタック処理//
	as=510000/N;	//1ノーツあたりのATK減少スコア//
	a=s/as;	//atkを算出//
	a=floor(a);	//小数点切り捨て//
	s=s-(as*a);
	
	if(s>=js){
		j=j+(s/js);
		j=floor(j);
		}
		jc=N-(j+a+m);	//JCを算出//
		
		if(j<=0)
			puts("--Error--\n");
		else if(a<=0)
			puts("--Error--\n");
		else if(jc<=0)
			puts("--Error--\n");
		
		printf("リセットする場合は【1】を入力:");	//入力値のリセット//
		scanf("%d",&re);
		printf("\n");
	}	while(re==1);
	if(j<=0||a<=0||jc<=0&&re!=1){
		printf("Finished");
		return(0);
	}
	js=floor(js);
	as=floor(as);
	ms=floor(ms);
	printf("JUSTICE CRITICAL　1あたりのスコア:%.0f\n",ms);
	printf("JUSTICE　1あたりのスコア:%.0f\n",js);
	printf("ATTACK　1あたりのスコア:%.0f\n",as);
	printf("%d-%.0f-%.0f-%d\n",jc,j,a,m);
	
	printf("再入力する場合は【1】を入力:");	
	scanf("%d",&re);
	printf("\n");
	} while(re==1);	//1で全体プログラムの再入力を実行//
	
	printf("Finished");
	return(0);
}
