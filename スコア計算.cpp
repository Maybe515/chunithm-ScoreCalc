#include<stdio.h>
#include<math.h>
#include<string.h>
int main(void)	//���C���֐�//
{
	int i,jc,jr,Jr,m,N,nr,Nr,re,s,S;
	double a,as,j,js,jrp,ms;
	char rst,jp[5];
	
	printf("�`���E�j�Y�� �X�R�A�v�Z\n");

	do{ //�S�̍ē���//
		
	do{	//���_�l���̍ē���//
		
	do{	//�X�R�A0���̍ē���//
		
	do{	//Error���̃��Z�b�g//
		
	do{	//�X�R�A�ē���//
		re=0;	//���Z�b�g�̏����l����//
	
	printf("�X�R�A:");
	scanf("%d",&S);	
		if(1010000>=S) break;	//���_�l�ȉ��̏ꍇ do�������//
		else if(1010000<S)	//���_�l�𒴂������̏���//
			printf("������x���͂��Ă��������@Enter�L�[�ő��s");
			scanf("%c",&rst);
		}	while(getchar()=='\n');	//���s�ŃX�R�A�݂̂̍ē��͂����s//
		
	do{	//�m�[�c���ē���//
	printf("�m�[�c��:");
	scanf("%d",&N);
		if(N>0) break;
		else if(N<=0)
			printf("������x���͂��Ă��������@Enter�L�[�ő��s");
			scanf("%c",&rst);
		}	while(getchar()=='\n');	//���s�ŃX�R�A�݂̂̍ē��͂����s//
		if(1010000!=S) break;
		else if(1010000==S)	//���_�l���������̏���//
			printf("%d-0-0-0\n",N);
			printf("�ē��͂���ꍇ�́y1�z�����:");	
			scanf("%d",&re);
			printf("\n");
			} while(re==1);	//1�ōē��͂����s//
			if(1010000==S&&re!=1){
		printf("Finished");
		return(0);
	}
		if(0!=S) break;
		else if(0==S)
			printf("0-0-0-%d",N);
			printf("�ē��͂���ꍇ�́y1�z�����:");	
		scanf("%d",&re);
		printf("\n");
	} while(re==1);	//1�ōē��͂����s//
	if(0==S&&re!=1){
		printf("Finished");
		return(0);
	}
	printf("��j�������Z�o���܂����H�yYes/No�z\n");	//��������r������//
	scanf("%s",jp);
		if(strcmp(jp,"Yes")==0){
		for(i=1;i<=10;i++){
		printf("%d�Ȗڂ̐�j��:",i);
		scanf("%d",&Jr);
		printf("���̃m�[�c��:");
		scanf("%d",&Nr);
		jr=Jr+jr;
		nr=Nr+nr;
		}
		if(strcmp(jp,"No")==0){
		break;
		}
	if(Jr==0||Nr==0)	//���͂��Ȃ��������̏��� (�����͂̏ꍇ 25%����)//
		jrp=0.25;
		break;
	}
	if(jr>=1&&nr>=1){
	jrp=jr/nr;	//���v�m�[�c���̐�j�����v�Z//
	}
	//�~�X����//
	printf("�~�X��:");
	scanf("%d",&m);
	s=1010000-S;	//���_�l�Ɠ��̓X�R�A�̍���//	
	ms=1010000/N;	//1�m�[�c�������Miss�����X�R�A//
	if(m>0){
	s=s-(m*ms);	//���̓X�R�A��Miss���̃X�R�A�����Z//
	}
	
	//��j����//
	js=10000/N;	//1�m�[�c������̐�j�����X�R�A//
	j=(s/js)*jrp;	//��j��������ɐ�j���Z�o//
	j=floor(j);	//�����_�؂�̂�//
	s=s-(js*j);

	//�A�^�b�N����//
	as=510000/N;	//1�m�[�c�������ATK�����X�R�A//
	a=s/as;	//atk���Z�o//
	a=floor(a);	//�����_�؂�̂�//
	s=s-(as*a);
	
	if(s>=js){
		j=j+(s/js);
		j=floor(j);
		}
		jc=N-(j+a+m);	//JC���Z�o//
		
		if(j<=0)
			puts("--Error--\n");
		else if(a<=0)
			puts("--Error--\n");
		else if(jc<=0)
			puts("--Error--\n");
		
		printf("���Z�b�g����ꍇ�́y1�z�����:");	//���͒l�̃��Z�b�g//
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
	printf("JUSTICE CRITICAL�@1������̃X�R�A:%.0f\n",ms);
	printf("JUSTICE�@1������̃X�R�A:%.0f\n",js);
	printf("ATTACK�@1������̃X�R�A:%.0f\n",as);
	printf("%d-%.0f-%.0f-%d\n",jc,j,a,m);
	
	printf("�ē��͂���ꍇ�́y1�z�����:");	
	scanf("%d",&re);
	printf("\n");
	} while(re==1);	//1�őS�̃v���O�����̍ē��͂����s//
	
	printf("Finished");
	return(0);
}
