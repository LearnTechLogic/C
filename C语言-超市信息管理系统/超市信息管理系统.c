#include<stdio.h>
#include<string.h>
#include<conio.h>
#include <time.h>
#include <stdlib.h>
struct Commodity{
	char name[20];
	int num;
	double money; 
	int type;
	int comtype;
	int overtime;
	char worker[20];
};
struct Workers{
	char name[20];
	char jobnum[10];
	char password[20]; 
	int age;
	int sex; 
	int responsibility;
	char phone[20];
	int department; 
};
struct Users{
	char id[20];
	char password[20];
	char name[20];
	char sex [20]; 
	char phone[20];
	int member;
	double integral;
	int deadline;
};
struct Allmoney{
	char e[20];
	char a[20];
	int x;
	double y;
	int time;
};
void boss(char w[],int t);
int loginaccount();
void manages(char w[],int t);
void custom();
void textmembership(char e[],int t);
void chose(char e[],int t); 
void onlineshopping(char a[],FILE* ap);
int displaytime();
void checkout(char e[],int t);
void membercheckout(char e[],int t);
double allintegral(char e[],double i);
void enterinformation(char e[]);
int atime(int t)//���º� 
{
	int a,b,c,d;
	d=1;
	a=t/10000;
	b=t%100;
	c=t%10000/100;
	if(c>12||c<1)
	{
		d--;
		return d;
	}
	if(t>20240101&&t<20990101)
	{
		if(c==2)
		{
			if ((a% 4 == 0 && a% 100!= 0) || a% 400 == 0)
			{
				if(b>0&&b<30)
				{
					return d;	
				}
				else 
				{
					d--;
					return d;
				 } 
			}
			else
			{
				if(b>0&&b<29)
				{
					return d;	
				}
				else 
				{
					d--;
					return d;
				 } 
			}
		}
		else if(c==1||c==3||c==5||c==7||c==8||c==10||c==12)
		{
			if(b>0&&b<32)
			{
				return d;
			}
			else 
			{
				d--;
				return d;
			 } 	
		}
		else if(c==4||c==6||c==9||c==11)
		{
			if(b>0&&b<31)
			{
				return d;
			}
			else 
			{
				d--;
				return d;
			 } 		
		}
	}
	else
	{
		d--;
		return d;
	}
}
void changes(char e[])//���º� 
{
	struct Users ir;
	char a[20];
	FILE* fp;
	fp=fopen("users.bin","rb");
	if(fp==NULL)
		printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
	FILE* rp;
	rp=fopen("temp.bin","wb");
	if(fp==NULL)
		printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
	while(fread(&ir,sizeof(struct Users),1,fp)==1)
	{
		if(strcmp(ir.id,e)==0)
		{
			printf("�������޸ĺ�����룺");
			scanf("%s",ir.password);
			printf("���ٴ������޸ĺ�����룺");
			scanf("%s",a);
			if(strcmp(ir.password ,a)!=0)
			{
				printf("\033[1;31m�����������벻һ�£�\033[0m\n");
				printf("�����������޸ĺ�����룺");
				scanf("%s",ir.password);
				printf("���ٴ������޸ĺ�����룺");
				scanf("%s",a);
			}
		}
		fwrite(&ir,sizeof(struct Users),1,rp);	
	}
	fclose(fp);
	fclose(rp);
	remove("users.bin"); 
	rename("temp.bin", "users.bin");  
 } 
void commodity(int t,char e[],FILE* ap) //������ 
{
	FILE* rp;
	struct Commodity ir;
	struct Allmoney ar;
	int x,overtime;
	rp=fopen("warehouse.bin","rb");
	if(rp==NULL)
		printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
	while(fread(&ir,sizeof(struct Commodity),1,rp)==1)
	{
		if(t==ir.comtype)
		{
			if(ir.overtime>displaytime())
			{
				printf("��Ʒ���ƣ�%s  ��Ʒ������%d  ��Ʒ���ۣ�%lf  ����ʱ��Ϊ��%ld  ",ir.name,ir.num,ir.money,ir.overtime);
				if(ir.type==1)
					printf("���㷽ʽΪ������  \n");
				else
					printf("���㷽ʽΪ����������  \n");
			}
		}
	}
	fclose(rp);
    printf("���û����Ҫ����Ʒ�밴0������һ��\n���������밴1\n");
    int m=1;   
    scanf("%d",&m);
    while(m!=0&&m!=1)
    {
    	printf("���������⣬���������룺");
    	scanf("%d",&m);
	}
    char a[20];
    int b=0;
    switch (m)
    {
    	case 0:
    		onlineshopping(e,ap);
    		break;
    	case 1:
    		while(1)
    		{
    			if(b==2)
    				printf("��Ʒ������,������ѡ������Ҫ����Ʒ:");
				else if(b==0)
    				printf("��ѡ������Ҫ����Ʒ:");
			    scanf("%s",a);
			    printf("�����빺����Ʒ�Ĺ���ʱ�䣺");
		    	scanf("%d",&overtime);
			    	while(atime(overtime)==0)
				{
					printf("\033[1;31m������������!\n����������:\033[0m");
					scanf("%d",&overtime);
				}
			    FILE* bp;
				bp=fopen("warehouse.bin","rb");
				if(bp==NULL)
					printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
				while(fread(&ir,sizeof(struct Commodity),1,bp)==1)
				{
					if(strcmp(ir.name,a)==0&&ir.comtype==t&&overtime==ir.overtime)
						b=1;
				}
				if(b==1)
				{
					fclose(bp);
					break;
				}
				else
				{
					b=2;
					fclose(bp);
				}
			}
		    printf("�����빺���������");
		    scanf("%d",&x);
		    double y;
		    FILE* bp;
			bp=fopen("warehouse.bin","rb");
			if(bp==NULL)
				printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
			FILE* fp;
			fp=fopen("temp.bin","wb");
			if(fp==NULL)
				printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
		    while(fread(&ir,sizeof(struct Commodity),1,bp)==1)
		    {
		    	if(strcmp(ir.name, a) == 0&&ir.overtime==overtime&&ir.comtype==t)
		    	{
		    		y=ir.money;
		    		if(x>ir.num)
		    		{
		    			b=2;
		    			fwrite(&ir, sizeof(struct Commodity), 1, fp);
					}
					else
					{
						ir.num-=x;
						fwrite(&ir, sizeof(struct Commodity), 1, fp);
		    			b=1;	
					}
				}
				else
				{
					fwrite(&ir, sizeof(struct Commodity), 1, fp);
				}
			}
			fclose(fp);
			fclose(rp);
		    remove("warehouse.bin"); 
			rename("temp.bin", "warehouse.bin");  
			if(b==2)
			{
				printf("���������Ʒ��治�㣡"); 
				commodity(t,e,ap);
			}
			else
			{
				ar.time=displaytime();
				strcpy(ar.e,e);
				strcpy(ar.a,a);
				ar.x=x;
				ar.y=y;
				FILE* qp;
				qp=fopen("allmoney.bin","ab");
				if(qp==NULL)
					printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
				fwrite(&ar, sizeof(struct Allmoney), 1, qp);
				fwrite(&ar, sizeof(struct Allmoney), 1, ap);
				fclose(qp);
				int j;
				printf("1.��������\n");
				printf("2.�������\n");
				printf("��ѡ����һ���Ĳ���:");
				scanf("%d",&j);
				while(j!=1&&j!=2)
				{
					printf("�������,��������\n");	
					scanf("%d",&j);
				}
				system("cls"); 
				int m;
				switch(j)
				{
					case 1:
						onlineshopping(e,ap);
						break;
					case 2:
						printf("�������Ƿ��ǻ�Ա\n");
						printf("1.��Ա\n");
						printf("2.�ǻ�Ա\n");
						printf("��ѡ��");
						scanf("%d",&m);
						while(m!=1&&m!=2)
						{
							printf("\n�����������������\n");
							scanf("%d",&m);
						 } 
						 switch(m)
						 {
						 	case 1:
						 		fclose(ap);
						 		textmembership(e,2);
						 		break;
						 	case 2:
						 		fclose(ap);
						 		chose(e,2);
						 		break;
					      }
						break;
				} 
			}
			break;
	}
}
void removeinformation(char e[],int t) //������ 
{
	struct Users ir;
	FILE* fp;
	fp=fopen("users.bin","rb"); 
	if(fp==NULL)
		printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
	FILE* rp;
	rp=fopen("transition.bin","wb");
	if(rp==NULL)
		printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
	while(fread(&ir,sizeof(struct Users),1,fp)==1)
	{
		if(strcmp(ir.id,e)==0)
		{
			ir.member=ir.deadline=ir.integral=0;
			fwrite(&ir,sizeof(struct Users),1,rp);
		}
		else
			fwrite(&ir,sizeof(struct Users),1,rp);
	}
	fclose(fp);
	fclose(rp);
	remove("users.bin");
	rename("transition.bin","users.bin");
	printf("������ɣ���Ϊ����ת�����˽���...\n");
	checkout(e,t);
}
double allintegral(char e[],double i)//������ 
{
    struct Users ir;
    FILE* fp;
    FILE* rp;
    fp = fopen("users.bin", "rb"); 
    if(fp==NULL)
		printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
    rp = fopen("transition.bin", "wb");
    if(rp==NULL)
		printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
    while (fread(&ir, sizeof(struct Users), 1, fp) == 1) 
	{
        if (strcmp(ir.id, e) == 0) 
		{
            ir.integral = ir.integral + i;
            i=ir.integral;
            fwrite(&ir, sizeof(struct Users), 1, rp);
        } else 
		{
            fwrite(&ir, sizeof(struct Users), 1, rp);
        }
    }
    fclose(fp);
    fclose(rp);
    remove("users.bin");
    rename("transition.bin", "users.bin");
    return i;
}
void enterinformation(char e[]) //������ 
{
	printf("����������Ҫע��Ļ�Աʱ��(��)��"); 
	int m;
	scanf("%d",&m);
	while(m<1)
	{
		printf("��������\n���������룺");
		scanf("%d",&m);
	}
	struct Users sr;
	FILE* fp;
	fp=fopen("users.bin","rb");
	if(fp==NULL)
		printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
	FILE* rp;
	rp=fopen("temp.bin","wb");
	if(rp==NULL)
		printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
	while(fread(&sr,sizeof(struct Users),1,fp)==1)
	{
		if(strcmp(sr.id,e)==0)
		{
			sr.member=1;
			sr.deadline=m*10000+displaytime();
			printf("��Ա����ʱ��Ϊ��%d\n",sr.deadline);
			fwrite(&sr,sizeof(struct Users),1,rp);
		}
		else
			fwrite(&sr,sizeof(struct Users),1,rp);
	}
	fclose(fp);
	fclose(rp);
	remove("users.bin");
	rename("temp.bin","users.bin");
	printf("\033[1;32m������ɣ�\033[0m\n");
}
void logoffmembership(char e[],int t)//������ 
{
	printf("��������ע������\n");
	printf("�Ƿ�ȷ��ע��\n");
	printf("1.��\n");
	printf("2.��\n");
	int x;
	printf("��ѡ��");
	scanf("%d",&x);
	while(x!=1&&x!=2)
	{
		printf("�����������������룺");
		scanf("%d",&x);
	}
	switch(x)
	{
		case 1:
			checkout(e,t);
			break;
		case 2:
			removeinformation(e,t);
			break;
	}
}
void checkout(char e[],int t)//������ 
{
	printf("��ӭ�������˽���\n");
	int a=0; 
	int i=1;
	switch (t)
	{
		case 1:
			printf("������Ҫ�������֣�һ������0.5Ԫ����");
			scanf("%d",&a);
			break;
		case 2:
			printf("1.����ȡ��\n");
			printf("2.�ͻ����ţ�ÿ����ƷһԪ��\n");
			printf("��ѡ�����ȡ����ʽ��");
			scanf("%d",&i);
			while(i!=1&&i!=2)
			{
				printf("����������������룺");
				scanf("%d",&i);
			}
			break;	
	}
	double q=0;
	FILE* fp;
	fp=fopen("amoney.bin","rb");
	if(fp==NULL)
		printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
	struct Allmoney ir;
	while(fread(&ir,sizeof(struct Allmoney),1,fp)==1)
	{
		if(ir.time==displaytime()&&strcmp(e,ir.e)==0)
		{
			printf("��Ʒ����%s ����%d ����%lf\n",ir.a,ir.x,ir.y);
			q=q+ir.x*ir.y+i-1;
		}
	}
	fclose(fp);
	q=q+a*0.5;
	printf("�ܼ�%lf",q);
	q=allintegral(e,q);
	printf(",���˳ɹ�����л����ʹ��,��Ŀǰ����Ϊ%lf\n",q); 
}
void registeredmember(char e[],int t)//������ 
{
	printf("��ӭ����ע���Ա����\n");
	struct Users people;
	struct Users x;
	printf("��Ա��ѣ�150Ԫ\n");
	printf("��ȷ�����Ƿ�Ҫע��\n");
	printf("1.��\n");
	printf("2.��\n");
	int i;
	printf("��ѡ��");
	scanf("%d",&i);
	while(i!=1&&i!=2)
	{
		printf("�����������������룺");
		scanf("%d",&i);
	}
	switch(i)
	{
		case 1:
			checkout(e,t);
			break;
		case 2:
			enterinformation(e);
			printf("ע��ɹ�\n");
			printf("1.��Ա����\n");
			printf("2.�ǻ�Ա����\n");
			int j;
			printf("��ѡ��:");
			scanf("%d",&j);
			while(j!=1&&j!=2)
			{
				printf("����������������룺");
				scanf("%d",&j);
			}
			switch(j)
			{
				case 1:
					membercheckout(e,t);
					break;
				case 2:
					checkout(e,t);
					break;
			}
	}
}
void membershiprenewal(char e[],int t)//������ 
{
	printf("��ӭ������Ա���ѽ���\n");
	printf("��Ա��ѣ�150Ԫ\n"); 
	printf("����������Ҫ���ѵ�ʱ����");
	int n;
	scanf("%d",&n);
	while(n<1)
	{
		printf("�����������������룺");
		scanf("%d",&n);
	}
	struct Users sp;
	FILE* fp;
	fp=fopen("users.bin","rb");
	if(fp==NULL)
		printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
	FILE* rp;
	rp=fopen("transition.bin","wb");
	if(rp==NULL)
		printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
	while(fread(&sp,sizeof(struct Users),1,fp)==1)
	{
		if(strcmp(sp.id,e)==0)
		{
			sp.deadline=n*10000+displaytime();
			fwrite(&sp,sizeof(struct Users),1,rp);
     	}
     	else
     		fwrite(&sp,sizeof(struct Users),1,rp);
	}
	fclose(fp);
	fclose(rp);
	remove("users.bin");
	rename("transition.bin","users.bin");
	printf("���ѳɹ���\n");
	int a;
	printf("1.��Ա����\n");
	printf("2.ֱ�ӽ���\n");
	printf("��ѡ������Ҫ�Ĳ�����");
	scanf("%d",&a);
	while(a!=1&&a!=2)
	{
		printf("�����������������룺");
		scanf("%d",&a);
	}
	system("cls"); 
	switch(a)
	{
		case 1:
			membercheckout(e,t);
			break;
		case 2:
			checkout(e,t); 
			break;
	}
}
void membercheckout(char e[],int t) //������ 
{
	int a=0; 
	int i=1;
	printf("��ӭʹ�û�Ա����\n");
	switch (t)
	{
		case 1:
			printf("������Ҫ�������֣�һ������0.5Ԫ����");
			scanf("%d",&a);
			break;
		case 2:
			printf("1.����ȡ��\n");
			printf("2.�ͻ����ţ�ÿ����ƷһԪ��\n");
			printf("��ѡ�����ȡ����ʽ��");
			scanf("%d",&i);
			while(i!=1&&i!=2)
			{
				printf("����������������룺");
				scanf("%d",&i);
			}
			break;
	}
	double q=0;
	double y;
	long time;
	FILE* fp;
	fp=fopen("amoney.bin","rb");
	if(fp==NULL)
		printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
	struct Allmoney ir;
	while(fread(&ir,sizeof(struct Allmoney),1,fp)==1)
	{
		if(ir.time==displaytime()&&strcmp(e,ir.e)==0)
		{
			printf("��Ʒ����%s ����%d ����%lf\n",ir.a,ir.x,ir.y);
			q=q+ir.x*ir.y+i-1;
		}
	}
	fclose(fp);
	q=q+0.5*a;
	printf("ԭ��%lf�����ۺ�%lf\n",q,q*0.9);
	q=allintegral(e,q*0.9);
	printf("���˳ɹ�����л����ʹ��,��Ŀǰ����Ϊ%lf\n",q); 
}
void manualcheckout(char e[])//������ 
{
	printf("��ӭʹ���˹�����\n");
	struct Users text;
	struct Users real;
	int a=0;
	FILE *fp;
	fp=fopen("users.bin","rb");
	if(fp==NULL)
		printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
	while(fread(&text,sizeof(struct Users),1,fp)==1)
	{
		if(strcmp(e,text.id)==0&&text.member==1&&text.deadline>=displaytime())
		{
			printf("��Ա��֤�ɹ�,Ϊ��ʹ�û�Ա����\n");
			a=1;
			fclose(fp);
		    membercheckout(e,1);
		}
	}
	if(a==0)
	{
		fclose(fp);
		chose(e,1);
	}
}
void automaticcheckout(char e[]) //������ 
{
	printf("��ӭ��������\n");
	int m;
	printf("�������Ƿ��ǻ�Ա\n");
	printf("1.��Ա\n");
	printf("2.�ǻ�Ա\n");
	printf("��ѡ��");
	scanf("%d",&m);
	while(m!=1&&m!=2)
	{
		printf("����������������룺");
		scanf("%d",&m);
	 } 
	 system("cls"); 
	 switch(m)
	 {
	 	case 1:
	 		textmembership(e,1);
	 		break;
	 	case 2:
	 		chose(e,1);
	 		break;
      }
}
void chose(char e[],int t) //������ 
{
	printf("��Ŀǰ���ǻ�Ա��\n");
	printf("1.ע���Ա\n");
	printf("2.ֱ�ӽ���\n");
	int y;
	printf("��ѡ������Ҫ�Ĳ�����");
	scanf("%d",&y);
	while(y!=1&&y!=2)
	{
		printf("����������������룺");
		scanf("%d",&y);
	}
	system("cls"); 
	switch(y)
	{
		case 1:
			registeredmember(e,t);
			break;
		case 2:
			checkout(e,t);
			break;
	}
}
void onlineshopping(char a[],FILE* ap) //������ 
{
	printf("1.������\n");
	printf("2.����\n");
	printf("3.ˮ����\n");
	printf("4.ʳƷ��\n");
	printf("5.������\n");
	printf("��ѡ������Ҫ����Ʒ���ࣺ");
	int x;
	scanf("%d",&x);
	while(x!=1&&x!=2&&x!=3&&x!=4&&x!=5)
	{
		printf("�����������������");
		scanf("%d",&x);
	}
	system("cls"); 
	commodity(x,a,ap);
}
void offlineshopping(char e[],FILE* ap) //������ 
{
	printf("��ӭʹ�����¹��\n");
	printf("��ѡ������Ҫ��ѯ����Ʒ���ࣺ\n");
    printf("��ѡ������Ҫ����Ʒ���ࣺ\n");
	printf("1.������\n");
	printf("2.����\n");
	printf("3.ˮ����\n");
	printf("4.ʳƷ��\n");
	printf("5.������\n");
	int y;
	scanf("%d",&y);
	while(y!=1&&y!=2&&y!=3&&y!=4&&y!=5)
	{
		printf("�����������������\n");
		scanf("%d",&y);
	}
	system("cls"); 
	FILE* lp;
	struct Commodity ir;
	int x;
	lp=fopen("warehouse.bin","rb");
	if(lp==NULL)
		printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
	while(fread(&ir,sizeof(struct Commodity),1,lp)==1)
	{
		if(y==ir.comtype)
		{
			if(ir.overtime>displaytime())
			{
				printf("��Ʒ���ƣ�%s  ��Ʒ������%d  ��Ʒ���ۣ�%lf  ����ʱ��Ϊ��%d  ",ir.name,ir.num,ir.money,ir.overtime);
				if(ir.type==1)
					printf("���㷽ʽΪ������  \n");
				else
					printf("���㷽ʽΪ����������  \n");
			}
		}
	}
	fclose(lp);
    printf("���û����Ҫ����Ʒ�밴0������һ��\n���������밴1\n");
    int m=1;
    int overtime;
    scanf("%d",&m);
    while(m!=0&&m!=1)
    {
    	printf("������������������\n");
    	scanf("%d",&m);
	}
    char a[20];
    int b; 
    switch (m)
    {
    	case 0:
    		offlineshopping(e,ap);
    		break;
    	case 1:
    	r:
		    b=0;
    		while(1)
    		{
    			if(b==2)
    				printf("��Ʒ������,������ѡ������Ҫ����Ʒ:");
				else if(b==0)
    				printf("��ѡ������Ҫ����Ʒ:");
			    scanf("%s",a);
			    printf("�����빺����Ʒ�Ĺ���ʱ�䣺");
			    scanf("%d",&overtime);
			    while(atime(overtime)==0)
				{
					printf("\033[1;31m������������!\n����������:\033[0m");
					scanf("%d",&overtime);
				}
			    FILE* bp;
				bp=fopen("warehouse.bin","rb");
				if(bp==NULL)
					printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
				while(fread(&ir,sizeof(struct Commodity),1,bp)==1)
				{
					if(strcmp(ir.name, a)==0&&ir.comtype==y&&overtime==ir.overtime)
						b=1;
				}
				if(b==1)
				{
					fclose(bp);
					break;
				}
				else
					b=2;
				fclose(bp);
			}
		    printf("�����빺���������");
		    scanf("%d",&x);
		    
		    double y=1;
		    FILE* bp;
			bp=fopen("warehouse.bin","rb");
			if(bp==NULL)
				printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
			FILE* fp;
			fp=fopen("temp.bin","wb");
			if(fp==NULL)
				printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
			while(fread(&ir,sizeof(struct Commodity),1,bp)==1)
		    {
		    	if(strcmp(ir.name, a) == 0&&ir.overtime==overtime&&y==ir.comtype)
		    	{
		    		y=ir.money;
		    		if(x>ir.num)
		    		{
		    			b=2;
		    			fwrite(&ir, sizeof(struct Commodity), 1, fp);
					}
					else
					{
						ir.num-=x;
						fwrite(&ir, sizeof(struct Commodity), 1, fp);
		    			b=1;	
					}
				}
				else
				{
					fwrite(&ir, sizeof(struct Commodity), 1, fp);
				}
			}
			fclose(fp);
			fclose(bp);
		    remove("warehouse.bin"); 
			rename("temp.bin", "warehouse.bin");  
			struct Allmoney ar;
			if(b==2)
			{
				printf("���������Ʒ��治�㣡\n");
				printf("������ѡ����Ʒ\n");
				goto r;
			}
			else
			{
				ar.time=displaytime();
				strcpy(ar.e,e);
				strcpy(ar.a,a);
				ar.x=x;
				ar.y=y;
				FILE* qp;
				qp=fopen("allmoney.bin","ab");
				if(qp==NULL)
					printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
				fwrite(&ar, sizeof(struct Allmoney), 1, qp);
				fwrite(&ar, sizeof(struct Allmoney), 1, ap);
				fclose(qp);
			    printf("��ѡ����һ���Ĳ���\n");
				int q;
				printf("1.��������\n");
				printf("2.�������\n");
				scanf("%d",&q);
				while(q!=1&&q!=2)
				{
					printf("�������!\n����������:");	
					scanf("%d",&q);
				}
				system("cls");
				int m;
				int j;
				switch(q)
				{
					case 1:
						offlineshopping(e,ap);
						break;
					case 2:
						
						printf("1.�˹�����\n");
						printf("2.��������\n");
						printf("��ѡ��"); 
						scanf("%d",&j);
						while(j!=1&&j!=2)
						{
							printf("�������\n����������:");
							scanf("%d",&j);
						}
						switch(j)
						{
							case 1:
								fclose(ap);
								manualcheckout(e); 
								break;
							case 2:
								fclose(ap);
								automaticcheckout(e);
								break;
						}
				} 
			}
	}	
}
void textmembership(char e[],int t)//������ 
{
	struct Users text;
	struct Users real;
	FILE *fp;
	fp=fopen("users.bin","rb");
	if(fp==NULL)
		printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
	while(fread(&text,sizeof(struct Users),1,fp)==1)
	{
		if(strcmp(e,text.id)==0)
		{
			if(text.member==1)
			{
				fclose(fp);
				if(text.deadline>=displaytime())
				{
					printf("��Ա��֤�ɹ�\n");
				    membercheckout(e,t);
				}
				else
				{
				    printf("��Ա��֤ʧ��\n");
				    printf("���Ļ�Ա�ѹ���\n");
					printf("��ѡ����Ҫ�Ĳ�����\n");
					printf("1.��Ա����\n");
					printf("2.������ʹ�û�Ա,ע����Ա\n");
					printf("3.�ǻ�Ա����\n");
					int s;
					scanf("%d",&s);
					while(s!=1&&s!=2&&s!=3)
					{
						printf("�������!\n����������:");
						scanf("%d",&s);
					}
					switch(s)
					{
						case 1:
						    membershiprenewal(e,t);	
						    break;
						case 2:
							logoffmembership(e,t);
							break;
						case 3:
							checkout(e,t); 
							break;
				    }
				}
			}
			else
			{
				printf("�������ǻ�Ա����ע���Ա\n");
				fclose(fp);
				registeredmember(e,t);
			}
		}
    }
}
void shopping(char a[])//������ 
{
	printf("1.���Ϲ���\n");
	printf("2.���¹���\n");
	printf("��ѡ������Ҫ�Ĺ��﷽ʽ��");
	int i;
	scanf("%d",&i);
	FILE* ap;
	ap=fopen("amoney.bin","wb");
	if(ap==NULL)
		printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
	while(i!=1&&i!=2)
	{
		printf("�������!\n����������:");
		scanf("%d",&i);
	 } 
	system("cls"); 
	switch(i)
	{
		case 1:
			printf("��ӭʹ�����Ϲ��\n");
			onlineshopping(a,ap);
			break;
		case 2:
			offlineshopping(a,ap);
			break;
	}
	fclose(ap);
}
void setupanaccount()//������  
{
	char passwords[20];
	struct Users sr;
	struct Users ir;
	FILE* fp;
	FILE* rp;
	fp=fopen("users.bin","rb");
	if(fp==NULL)
		printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
	rp=fopen("users.bin","ab");
	if(rp==NULL)
		printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
	printf("������������");
	scanf("%s",sr.name);
	printf("�������Ա���m;Ůf����");
	scanf("%s",sr.sex);
	while(strcmp(sr.sex,"f")!=0&&strcmp(sr.sex,"m")!=0)
	{
		printf("\033[1;31m�Ա��������\033[0m\n���������룺");
		scanf("%s",sr.sex);
	}
	printf("����������˺�:");
	scanf("%s",sr.id);
	while(fread(&ir,sizeof(struct Users),1,fp)==1)
	{
		if(strcmp(ir.id,sr.id)==0)
		{
			printf("\033[1;31m�˺��Ѵ���\033[0m\n����������:");
			scanf("%s",sr.id);
			rewind(fp);
		}
	}
	printf("������绰���룺");
	scanf("%s",sr.phone);
	rewind(fp);
	while(fread(&ir,sizeof(struct Users),1,fp)==1)
	{
		if(strcmp(ir.phone,sr.phone)==0)
		{
			printf("\033[1;31m�����Ѵ���\033[0m\n����������:");
			scanf("%s",sr.phone);
			rewind(fp);
		}
	}
	printf("���������룺");
	scanf("%s",sr.password);
	printf("���ٴ��������룺");
	scanf("%s",passwords);
	while(strcmp(sr.password,passwords)!=0)
	{
		printf("\033[1;31m�������벻һ��\033[0m\n");
		printf("�������������룺");
		scanf("%s",sr.password);
		printf("���ٴ��������룺");
		scanf("%s",passwords);
	}
	sr.member=0;
	sr.integral=0;
	sr.deadline=0;
	fwrite (&sr,sizeof(struct Users),1,rp);
	printf("ע��ɹ�������\n");
	fclose(fp);
	fclose(rp);
	printf("��ѡ������Ҫ�Ĳ���\n"); 
    printf("1.�˳�����\n");
	printf("2.��¼�˺�\n");
	int f;
	scanf("%d",&f);
	while(f!=1&&f!=2)
	{
		printf("\033[1;31m�������!\033[0m\n���������룡\n");
		scanf("%d",&f);
	}
	getchar();
	int j,y;
	switch(f)
	{
		case 1:
			printf("\n\033[1;32mлл����ʹ�ã�\033[0m\n");
			break;
		case 2:
			custom();
			break;
	}
}
int loginaccount()//���º� 
{
	char ch;
	char a[20],b[20]; 
	int n,x,y,z=0;
	printf("����������˺�:");
	gets(a);
	FILE *fp;
	fp=fopen("users.bin","rb");
	if(fp==NULL)
		printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
	y=2;
	struct Users use;
	while(fread(&use,sizeof(struct Users),1,fp)==1)
	{
		if(strcmp(a,use.id)==0)
		{
			printf("�˺���ȷ\n");
			x=1;
			while(1)
			{
				printf("����������:");
				while(1)
				{
					ch=_getch();
					if(ch==13)
					{
						b[z]='\0';
						break;
					}
					else if(ch==8)
					{
						if(z>0)
						{
							z--;
							printf("\b \b");
						}
					}
					else
					{
						b[z]=ch;
						z++;
						printf("*");
					}
				}
				if(strcmp(b,use.password)==0)
				{
					printf("\n\033[1;32m������ȷ\033[0m\n");
      				y=1;
      				printf("��ӭʹ��\n");
      				fclose(fp);
      				shopping(a);
					break;
				}
				else
				{
					if(x==3)
					{
						printf("\n���벻��ȷ\n");
						printf("1.���µ�¼\n");
						printf("2.�޸�����\n");
						printf("��ѡ��");
						scanf("%d",&n);
						while(n!=1&&n!=2)
						{
							printf("\033[1;31m�������\033[0m\n���������룺");
							scanf("%d",&n);
						}
						if(n==1)
					 	{
					 		y=0;
							break;
						 }
						 else if(n==2)
						 {
						 	fclose(fp);
							changes(a);
							printf("��ӭʹ��\n");
		      				shopping(a);
		      				break;
						 }		
					}
					else 
					{
						printf("\n�������\n�㻹��%d�λ���\n",3-x);
						z=0;
					}
					x++;
				}
			}
		}
	}
    fclose(fp);
    return y;
}
void custom()//���º� 
{
	int i;
	printf("1.���˺�\n");
	printf("2.���˺�\n");
	printf("��ѡ��");
	scanf("%d",&i);
	while(i!=1&&i!=2)
	{
		getchar();
		printf("�������\n");
		printf("���������룺");
		scanf("%d",&i);
	}
	getchar();
	int a,j;
	system("cls"); 
	switch(i)
	{
		case 1:
			a=loginaccount();
			for(j=0;j<2;j++)
			{
				if(a==2)
				{
					printf("�˺Ų�����\n");
					printf("�㻹��%d���������\n",2-j);
					a=loginaccount();
					if(2-j==1&&a==2)
					{
						printf("\033[31m�˺Ų����ڣ�������λ����Ѿ����꣡����\033[0m");
					}
				}
				else if(a==1)
					break;
				else if (a==0)
					custom();
			}
			break;
		case 2:
			setupanaccount();
			break;
	}
}
int dep(char w[])//���º�
{
	struct Workers ir;
	FILE* fp;
	fp=fopen("accountpassword.bin","rb");
	if(fp==NULL)
		printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
	while(fread(&ir,sizeof(struct Workers),1,fp)==1)
	{
		if (strcmp(w, ir.jobnum)==0) 
		break;
	}
	fclose(fp);
	return ir.department;
}
int displaytime() //���º�
{
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
	int t;
	t=1900*10000+timeinfo->tm_year*10000+(timeinfo->tm_mon + 1)*100+timeinfo->tm_mday;
    return t;
}
void disshow()//���º�
{
	char name[20];
	int m;
	double n=0;
	FILE* fp;
	fp=fopen("allmoney.bin","rb");
	if(fp==NULL)
		printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
	struct Allmoney ir;
	printf("1.�鿴������������\n");
	printf("2.�鿴���µ��������\n");
	printf("3.�鿴ĳ����Ʒ���µ��������\n");
	printf("��ѡ��Ҫ�鿴�����ݣ�");
	scanf("%d",&m);
	while(m!=1&&m!=2&&m!=3)
	{
		printf("��������!\n���������룺");
		scanf("%d",&m);
	}
	system("cls"); 
	int a,b;
	a=1;
	b=1;
	switch (m)
	{
		case 1:
			printf("������������:\n");
			while(fread(&ir,sizeof(struct Allmoney),1,fp)==1)
			{
				if(ir.time==displaytime())
				{
					printf("��Ʒ����:%s ����%d ����%lf\n",ir.a,ir.x,ir.y);
					n=n+ir.x*ir.y;
				}
					
			}
			break;
		case 2:
			printf("���µ��������:\n");
			while(fread(&ir,sizeof(struct Allmoney),1,fp)==1)
			{
				if(ir.time/100==displaytime()/100)
				{
					printf("��Ʒ����:%s ����%d ����%lf\n",ir.a,ir.x,ir.y);
					n=n+ir.x*ir.y;
				}
					
			}
			break;
		case 3:
			printf("��������Ʒ�����ƣ�");
			scanf("%s",name);
			while(a)
			{
				while(fread(&ir,sizeof(struct Allmoney),1,fp)==1)
				{
					if(strcmp(name,ir.a)==0)
					{
						a=0;
						break;
					}
				}
				if(a==1)
				{
					b++;
					if(b>3)
					{
						printf("����Ʒ�����ڣ����Ѷ�β�ѯ������Ʒ������\n");
						a=0; 
					}
					else
					{
						printf("����Ʒ�����ڣ�\n���������룺");
						scanf("%s",name);
						rewind(fp);
					}
				}
			 } 
			rewind(fp);
			while(fread(&ir,sizeof(struct Allmoney),1,fp)==1)
			{
				if(ir.time/100==displaytime()/100&&strcmp(name,ir.a)==0)
				{
					printf("��Ʒ����:%s ����%d ����%lf\n",ir.a,ir.x,ir.y);
					n=n+ir.x*ir.y;
				}
			}
			break;		
	}
	printf("\033[1;32m������Ϊ��\033[0m %lf\n",n);
	fclose(fp);
}
void change()//���º�
{
	struct Workers ir;
	struct Workers sr;
	char a[20];
	int i,j,n;
	i=1;
	j=1;
	FILE* fp;
	fp=fopen("accountpassword.bin","rb");
	if(fp==NULL)
		printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
	FILE* rp;
	rp=fopen("temp.bin","wb");
	if(rp==NULL)
		printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
	printf("������Ҫ�޸ĵ�Ա�����ţ�");
	scanf("%s",sr.jobnum);
	while(i)
	{
		while(fread(&ir,sizeof(struct Workers),1,fp)==1)
		{
			if(strcmp(ir.jobnum,sr.jobnum)==0)
			{
				i=0;
				printf("����Ҫ�޸ĵ�Ա����ϢΪ:");
				printf("\033[1;33m������%s  ���ţ�%s  ���䣺%d  �绰���룺%s  ���ڣ�\033[0m",ir.name,ir.jobnum,ir.age,ir.phone);
				switch (ir.department)
				{
					case 1:
						printf("\033[1;33m���߲���\033[0m\n");
						break;
					case 2:
						printf("\033[1;33m���ಿ��\033[0m\n");
						break;
					case 3:
						printf("\033[1;33mˮ������\033[0m\n");
						break;
					case 4:
						printf("\033[1;33mʳƷ����\033[0m\n");
						break;
					case 5:
						printf("\033[1;33m�����\033[0m\n");
						break;
				}
				rewind(fp);
				printf("1.�޸ĵ绰����\n");
				printf("2.�޸����ڲ���\n");
				printf("3.�޸�����\n"); 
				printf("��ѡ��Ҫ�޸ĵ����ݣ�");
				scanf("%d",&n);
				while(n!=1&&n!=2&&n!=3)
				{
					printf("\033[1;31m��������!\033[0m\n����������:");
					scanf("%d",&n);
				}
				switch (n)
				{
					case 1:
						printf("�������޸ĺ�ĵ绰���룺");
						scanf("%s",sr.phone);
						break;
					case 2:
						printf("1.����2.����3.ˮ��4.ʳƷ5.����\n");
						printf("�������޸ĺ�Ĳ��ţ�");
						scanf("%d",&sr.department);
						while(sr.department!=1&&sr.department!=2&&sr.department!=3&&sr.department!=4&&sr.department!=5)
						{
							printf("\033[1;31m��������!\033[0m\n����������:");
							scanf("%d",&sr.department);
						}
								break;
					case 3:
						printf("�������޸ĺ�����룺");
						scanf("%s",sr.password);
						printf("���ٴ������޸ĺ�����룺");
						scanf("%s",a);
						if(strcmp(sr.password ,a)!=0)
						{
							printf("\033[1;31m�����������벻һ�£�\033[0m\n");
							printf("�����������޸ĺ�����룺");
							scanf("%s",sr.password);
							printf("���ٴ������޸ĺ�����룺");
							scanf("%s",a);
						}
						break;
				}
				printf("���ȷ���޸������� 1\n");
				printf("���������޸������� 2\n");
				printf("������һ�������� 0\n");
				printf("��ѡ��");
				scanf("%d",&j);
				while(j!=1&&j!=2&&j!=0)
				{
					printf("\033[1;31m��������!\033[0m\n����������:");
					scanf("%d",&j);
				}
				if(j==2)
				{
					fclose(fp);
					change();
				}
				else if(j==1)
				{
					rewind(fp);
					while(fread(&ir,sizeof(struct Workers),1,fp)==1)
					{
						if (strcmp(ir.jobnum, sr.jobnum) != 0) 
							fwrite(&ir,sizeof(struct Workers),1,rp);
						else
						{
							switch (n)
							{
								case 1:
									strcpy(ir.phone,sr.phone);
									break;
								case 2:
									ir.department=sr.department;
									break;
								case 3:
									strcpy(ir.password,sr.password);
									break;
									
							}
							fwrite(&ir,sizeof(struct Workers),1,rp);
						}
					}
					fclose(fp);
					fclose(rp);
					remove("accountpassword.bin"); 
					rename("temp.bin", "accountpassword.bin");  
				}
				else
				{
					fclose(fp);
						break;
				}
			}
		}
		if(i==1)
		{
			j++;
			if(j>3)
			{
				printf("\033[1;31m�������˴�̫����鿴��������´򿪣�����\033[0m\n");
				break;
			}
			printf("\033[1;31m������������!\033[0m\n����������:");
			scanf("%s",sr.jobnum);
			rewind(fp);
			i=1;
		}
    }
}
void display(int t)//���º�
{
	FILE* fp;
	struct Workers ir;
	fp=fopen("accountpassword.bin","rb");
	if(fp==NULL)
		printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
	while(fread(&ir,sizeof(struct Workers),1,fp)==1)
	{
		if(ir.responsibility==t-1)
		{
			printf("������%s  ���ţ�%s  ���룺%s  ���䣺%d  �Ա�%d  �绰��%s  ",ir.name,ir.jobnum,ir.password,ir.age,ir.sex,ir.phone); 
			switch (ir.responsibility)
			{
				case 2:
					printf("ְλ��Ա��  ");
					break;
				case 3:
					printf("ְλ������  ");
					break;
			}
			switch (ir.department)
			{
				case 1:
					printf("���ţ�����\n");
					break;
				case 2:
					printf("���ţ�����\n");
					break;
				case 3:
					printf("���ţ�ˮ��\n");
					break;
				case 4:
					printf("���ţ�ʳƷ\n");
					break;
				case 5:
					printf("���ţ�����\n");
					break;
			}
		}
	}
	fclose(fp);
}
void addwareh(char w[],int a)//���º�
{
	FILE* fp;
	fp=fopen("wareh.bin","ab");
	if(fp==NULL)
		printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
	struct Commodity sr;
	printf("��������Ʒ�����ƣ�");
	scanf("%s",sr.name);
	printf("��������Ʒ��������");
	scanf("%d",&sr.num);
	printf("��������Ʒ�ļ۸�");
	scanf("%lf",&sr.money);
	printf("��Ʒ�ļ��㷽����\n");
	printf("1.����\n");
	printf("2.����\n");
	printf("��ѡ����㷽����");
	scanf("%d",&sr.type);
	while(sr.type!=1&&sr.type!=2)
	{
		printf("������󣡣�!\n");
		printf("��ѡ����㷽����");
		scanf("%d",&sr.type);
	}
	strcpy(sr.worker,w);
	printf("��������Ʒ�Ĺ������ڣ���(20240101)");
	scanf("%d",&sr.overtime);
	while(atime(sr.overtime)==0)
	{
		printf("\033[1;31m������������!\n����������:\033[0m");
		scanf("%d",&sr.overtime);
	}
	sr.comtype=dep(w);
	fwrite(&sr,sizeof(struct Commodity),1,fp);
	fclose(fp);
	printf("\033[32m�����ɹ�\033[0m\n");
}
void addwarehouse(char w[],int a) //���º�
{
	int c,d;
	FILE* rp;
	FILE* bp;
	rp=fopen("warehouse.bin","rb");
	if(rp==NULL)
		printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
	bp=fopen("wareh.bin","rb");
	if(bp==NULL)
		printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
	struct Commodity sr;
	struct Commodity ir;
	printf("��������Ʒ�����ƣ�");

	scanf("%s",sr.name);
	printf("��������Ʒ�Ĺ���ʱ�䣺");
	scanf("%d",&sr.overtime);
	while(atime(sr.overtime)==0)
	{
		printf("\033[1;31m������������!\n����������:\033[0m");
		scanf("%d",&sr.overtime);
	}
	int b=1;
	while(b==1)
	{
		rewind(bp);
		while(fread(&ir,sizeof(struct Commodity),1,bp)==1)
		{
			if(strcmp(sr.name,ir.name)==0&&sr.overtime==ir.overtime)
			{
				sr.money=ir.money;
				sr.type=ir.type;
				sr.comtype=ir.comtype;
				sr.overtime=ir.overtime;
				printf("����Ʒ�ֿ�����Ϣ:����%d\n������Ҫ�ϼܵ�������",ir.num);
				scanf("%d",&c);
				while(c>ir.num)
				{
					printf("�ֿ��治�㣬���������룺");
					scanf("%d",&c);
				}
				d=ir.num-c;
				b=0; 
				rewind(bp);
				FILE *op = fopen("temp.bin", "wb");
				if(op==NULL)
					printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
				while(fread(&ir,sizeof(struct Commodity),1,bp)==1)
				{
					if (strcmp(sr.name,ir.name) != 0) 
						fwrite(&ir,sizeof(struct Commodity),1,op);
					else
					{
						ir.num=d;
						fwrite(&ir,sizeof(struct Commodity),1,op);
					}
				}
				fclose(bp);
				fclose(op);
				remove("wareh.bin"); 
				rename("temp.bin", "wareh.bin"); 
				break;
			}
		}
		if(b==1)
		{
			printf("�ֿ��ڲ����ڴ���Ʒ�����������룺");
			scanf("%s",sr.name);
			printf("��������Ʒ�Ĺ���ʱ�䣺");
			scanf("%d",&sr.overtime);
		}
	}
	FILE *op = fopen("temp.bin", "wb");
	if(op==NULL)
		printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
	while(fread(&ir,sizeof(struct Commodity),1,rp)==1)
	{
		if(strcmp(sr.name,ir.name)==0&&sr.overtime==ir.overtime)
		{
			b=1;
			ir.num+=c;
			strcpy(ir.worker,w);
			fwrite(&ir,sizeof(struct Commodity),1,op);			
		}
		else
		{
			strcpy(ir.worker,w);
			fwrite(&ir,sizeof(struct Commodity),1,op);
		}
	}
	if(b==0)
	{
		strcpy(sr.worker,w);
		sr.num=c;
		fwrite(&sr,sizeof(struct Commodity),1,op);
	}
	fclose(op);
	fclose(rp);
	remove("warehouse.bin"); 
	rename("temp.bin", "warehouse.bin"); 
	printf("\033[1;32m�ϼܳɹ�\033[0m\n");
}
void delwarehouse(char w[],int a) //���º�
{
	int i=0;
	FILE* rp;
	FILE* fp;
	FILE* bp;
	rp=fopen("warehouse.bin","rb");
	if(rp==NULL)
		printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
	bp=fopen("wareh.bin","rb");
	if(bp==NULL)
		printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
	struct Commodity sr;
	struct Commodity ir;
	printf("������Ҫ�¼ܵ���Ʒ�����ƣ�");
	scanf("%s",sr.name);
	printf("��������Ʒ�Ĺ���ʱ�䣺");
	scanf("%d",&sr.overtime);
	while(atime(sr.overtime)==0)
	{
		printf("\033[1;31m������������!\n����������:\033[0m");
		scanf("%d",&sr.overtime);
	}
	while(fread(&ir,sizeof(struct Commodity),1,rp)==1)
	{
		if(strcmp(sr.name,ir.name)==0&&sr.overtime==ir.overtime&&dep(w)==ir.comtype)
		{
			sr.num=ir.num;
			sr.money=ir.money;
			sr.type=ir.type;
			sr.comtype=ir.comtype;
			sr.overtime=ir.overtime;
			i=1;
			rewind(rp);
			FILE *op = fopen("temp.bin", "wb");
			if(op==NULL)
				printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
			while(fread(&ir,sizeof(struct Commodity),1,rp)==1)
				if (strcmp(sr.name,ir.name) != 0) 
					fwrite(&ir,sizeof(struct Commodity),1,op);
			fclose(op);
			fclose(rp);
			remove("warehouse.bin"); 
			rename("temp.bin", "warehouse.bin"); 
			FILE* cp = fopen("temp.bin", "wb");
			if(cp==NULL)
				printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
			while(fread(&ir,sizeof(struct Commodity),1,bp)==1)
			{
				if(strcmp(sr.name,ir.name)==0&&sr.overtime==ir.overtime)
				{
					i=2;
					ir.num+=sr.num;
				}
				fwrite(&ir,sizeof(struct Commodity),1,cp);	
			}
			fclose(cp);
			fclose(bp);
			remove("wareh.bin"); 
			rename("temp.bin", "wareh.bin"); 
			if(i!=2)
			{
				fp=fopen("wareh.bin","ab");
				if(fp==NULL)
					printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
				strcpy(sr.worker,w);
				fwrite(&sr,sizeof(struct Commodity),1,fp);
				fclose(fp);
			}
			printf("\033[1;32m�¼ܳɹ�\033[0m\n");
			break;
		}
	}
	if(i==0)
		printf("û�������Ʒ���ڣ�����\n");
}
void displayh(char w[],int a) //���º�
{
	FILE* rp;
	struct Commodity ir;
	switch (a)
	{
		case 3:
			rp=fopen("wareh.bin","rb");
			if(rp==NULL)
				printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
			break;
		case 2:
			rp=fopen("warehouse.bin","rb");
			if(rp==NULL)
				printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
			break;
	 } 
	while(fread(&ir,sizeof(struct Commodity),1,rp)==1)
	{	
		if(dep(w)==ir.comtype)
		{
			if(ir.overtime<displaytime())
			{
				printf("\033[31m��Ʒ���ƣ�%s  ��Ʒ������%d  ��Ʒ���ۣ�%lf  ����ʱ��Ϊ��%d  \033[0m",ir.name,ir.num,ir.money,ir.overtime);
				if(ir.type==1)
					printf("\033[31m���㷽ʽΪ������  \033[0m\n");
				else
					printf("\033[31m���㷽ʽΪ����������  \033[0m\n");
			}
			else
			{
				printf("��Ʒ���ƣ�%s  ��Ʒ������%d  ��Ʒ���ۣ�%lf  ����ʱ��Ϊ��%d  ",ir.name,ir.num,ir.money,ir.overtime);
				if(ir.type==1)
					printf("���㷽ʽΪ������  \n");
				else
					printf("���㷽ʽΪ����������  \n");
			}
		}
	}
	fclose(rp);
}
void warehouse(char w[],int a) //���º�
{
	int j,i=1;
	while(i)
	{
		printf("1.�ϼ���Ʒ\n");
		printf("2.�¼���Ʒ\n");
		printf("3.��ʾ����������Ʒ\n");
		printf("4.��ʾ�ֿ�������Ʒ\n");
		printf("0.��������\n");
		printf("��ѡ����Ĳ�����");
		scanf("%d",&i);
		while(i!=1&&i!=2&&i!=3&&i!=4)
		{
			if(i==0)
			{
				printf("\033[1;31m�����Ƴ�ϵͳ������\033[0m\n");
				printf("ȷ���˳��밴0\n");
				printf("���������밴1\n");
				scanf("%d",&j);
				while(j!=0&&j!=1)
				{
					printf("\033[1;31m��������!\033[0m\n����������:");
					scanf("%d",&j);
				}
				if(j==0)
				{
					printf("\033[1;34m��л���ʹ�ã�\033[0m");
					break;
				}
				else
				{
					i=6;
					break;
				}		
			}
			else
			{
				printf("\033[1;32m��������!\033[0m\n����������:");
				scanf("%d",&i);
			}
		}
		system("cls"); 
		switch(i)
		{
			case 1:
				addwarehouse(w,a);
				break;
			case 2:
				delwarehouse(w,a);
				break;
			case 3:
				displayh(w,a);
				break;
			case 4:
				displayh(w,a+1);
				break;
		}
	}
}
void accountpassword(int t)//���º�
{
	int i,j,z=0;
	char ch;
	char a[20],b[20],c[20],d[20];
	ap:printf("��������Ĺ��ţ�");
	gets(a);
	FILE* fp;
	fp=fopen("accountpassword.bin","rb");
	if(fp==NULL)
		printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
	i=0;
	j=0;
	struct Workers ir;
	while(fread(&ir,sizeof(struct Workers),1,fp)==1)
	{ 
		if (strcmp(a, ir.jobnum) == 0 && ir.responsibility==t) 
		{ 
			printf("\033[32m������ȷ\033[0m\n");
			i=1;
			while(1)
			{
				printf("���������룺");
				while (1) 
				{
			        ch = _getch();
			        if (ch == 13)
					{ 
			            b[z] = '\0';
			            break;
			        } 
					else if (ch == 8)
					{ 
			            if (z > 0) 
						{
			                z--;
			                printf("\b \b");
			            }
			        } 
					else 
					{
			            b[z] = ch;
			            z++;
			            printf("*");
			        }
			    }
				if (strcmp(b, ir.password) == 0)
				{
					printf("\n\033[32m������ȷ\033[0m\n");
					j=1;
					fclose(fp); 
					break; 
				}
				else
				{
					if(i==3)
					{
						printf("\n���벻��ȷ\n");
						printf("\033[1;31m����ϵ�ϰ�����޸ģ�����\033[0m");
						j=0;
						break;
					}
					else
					{
						printf("\n�������\n�㻹��%d�λ���\n",3-i);
						z=0;
					}
					i++;
				}
			}
		}	
	} 
	if(i==0)
	{
		fclose(fp);
		printf("\033[1;31m���Ų���ȷ\033[0m\n");
		goto ap;
	}
	fclose(fp);
	if(j==1)
	{
		switch(t)
		{
			case 4:
				boss(ir.jobnum,t);
				break;
			case 3:
				manages(ir.jobnum,t);
				break;
			case 2:
				warehouse(ir.jobnum,t);
				break;
		}
	}
}
void addpeople(char w[],int t)//���º�
{
	char a[20];
	FILE* fp;
	FILE* rp;
	fp=fopen("accountpassword.bin","ab");
	if(fp==NULL)
		printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
	rp=fopen("accountpassword.bin","rb");
	if(rp==NULL)
		printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
	printf("��������Ҫ�����Ա��������");
	struct Workers sr;
	struct Workers ir;
	scanf("%s",sr.name);
	printf("���ţ�");
	scanf("%s",sr.jobnum);
	while(fread(&ir,sizeof(struct Workers),1,rp)==1)
	{
		while (strcmp(sr.jobnum, ir.jobnum) == 0)
		{
			printf("\033[1;31m�����Ѵ���!\033[0m\n����������:");
			scanf("%s",sr.jobnum);
			rewind(rp);
		}
	} 
	printf("���룺");
	scanf("%s",sr.password);
	printf("���ٴ��������룺");
	scanf("%s",a);
	while(strcmp(sr.password,a)!=0)
	{
		printf("\033[1;31m�������벻һ�£�����\033[0m\n��������������:");
		scanf("%s",sr.password);
		printf("���ٴ��������룺");
		scanf("%s",a);
	}
	printf("���䣺");
	scanf("%d",&sr.age);
	printf("�Ա�(��1/Ů0)��");
	scanf("%d",&sr.sex);
	while(sr.sex!=1&&sr.sex!=0)
	{
		printf("\033[1;31m�Ա��������\033[0m\n��������:");
		scanf("%d",&sr.sex);
	}
	sr.responsibility=t-1;
	printf("�绰���룺");
	scanf("%s",sr.phone);
	if(dep(w)==0)
	{
		printf("1.����2.����3.ˮ��4.ʳƷ5.����\n");
		printf("���������ڵĲ��ţ�");
		scanf("%d",&sr.department);
		while(sr.department!=1&&sr.department!=2&&sr.department!=3&&sr.department!=4&&sr.department!=5)
		{
			printf("\033[1;31m�������󣡣���\033[0m\n");
			printf("1.����2.����3.ˮ��4.ʳƷ5.����\n");
			printf("�������������ڵĲ��ţ�");
			scanf("%d",&sr.department);
		}
	}
	else
	 	sr.department=dep(w);
	fwrite(&sr,sizeof(struct Workers),1,fp);
	printf("\033[1;32m��ӳɹ���\033[0m\n");
	fclose(fp);
	fclose(rp);
}
void delpeople(char w[],int t)//���º�
{
	int j,i=1;
	struct Workers ir; 
	FILE* fp;
	fp=fopen("accountpassword.bin","rb");
	if(fp==NULL)
		printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
	printf("��������Ҫ����Ա���Ĺ��ţ�");
	FILE* rp;
	rp=fopen("temp.bin","wb");
	if(rp==NULL)
		printf("\033[1;31m�����������ϵרҵ��Ա������\033[0m\n");
	char jobnum[20];
	scanf("%s",jobnum);
	while(i)
	{
		while(fread(&ir,sizeof(struct Workers),1,fp)==1)
		{
			if(strcmp(ir.jobnum,jobnum)==0 && ir.responsibility==t-1)
			{
				i=0;
				printf("����Ҫɾ����Ա��Ϊ:");
				printf("\033[1;33m����%s  ����%s  ����%d  �绰����%s  ����\033[0m",ir.name,ir.jobnum,ir.age,ir.phone);
				switch (ir.department)
				{
					case 1:
						printf("\033[1;33m���߲���\033[0m\n");
						break;
					case 2:
						printf("\033[1;33m���ಿ��\033[0m\n");
						break;
					case 3:
						printf("\033[1;33mˮ������\033[0m\n");
						break;
					case 4:
						printf("\033[1;33mʳƷ����\033[0m\n");
						break;
					case 5:
						printf("\033[1;33m�����\033[0m\n");
						break;
				}
				rewind(fp);
				break;
			}
		} 
		if(i==1)
		{
			printf("����������������������");
			scanf("%s",jobnum);
			rewind(fp);
			i=1;
		}
	}
	printf("���ȷ��ɾ�������� 1\n");
	printf("������������������ 2\n");
	printf("������һ�������� 0\n");
	scanf("%d",&j);
	if(j==2)
	{
		fclose(fp);
		fclose(rp);
		delpeople(w,t);
	}
	else if(j==1)
	{
		while(fread(&ir,sizeof(struct Workers),1,fp)==1)
		if (strcmp(ir.jobnum, jobnum) != 0) 
			fwrite(&ir,sizeof(struct Workers),1,rp);
		fclose(fp);
		fclose(rp);
		remove("accountpassword.bin"); 
		rename("temp.bin", "accountpassword.bin");  
	}
}
void manages(char w[],int t) //���º�
{
	int j,a=1;
	while(a)
	{
		printf("1.���Ա��\n");
		printf("2.����Ա��\n");
		printf("3.��ʾ����Ա��\n");
		printf("4.��ʾ�ֿ���������Ʒ\n");
		printf("5.�鿴��Ʒ�������\n");
		printf("6.����\n");
		printf("0.��������\n");
		printf("��ѡ����Ĳ�����");
		scanf("%d",&a);
		while(a!=1&&a!=2&&a!=3&&a!=4&&a!=5&&a!=6)
		{
			if(a==0)
			{
				printf("\033[1;31m�����Ƴ�ϵͳ������\033[0m\n");
				printf("ȷ���˳��밴0\n");
				printf("���������밴1\n");
				scanf("%d",&j);
				while(j!=0&&j!=1)
				{
					printf("\033[1;31m��������!\033[0m\n����������:");
					scanf("%d",&j);
				}
				if(j==0)
				{
					printf("\033[1;34m��л���ʹ�ã�\033[0m");
					a=0;
					break;
				}
				else
				{
					a=7;
					break;
				}		
			}
			else
			{
				printf("\033[1;32m��������!\033[0m\n����������:");
				scanf("%d",&a);
			}
		}
		system("cls"); 
		switch (a)
		{
			case 0:
				break;
			case 1:
				addpeople(w,t);
				break;	
			case 2:
				delpeople(w,t);
				break;
			case 3:
				display(t);
				break;	
			case 4:
				displayh(w,t);
				break;
			case 5:
				disshow();
				break;
			case 6:
				addwareh(w,t);
				break;	
		} 
	}
}
void boss(char w[],int t)//���º�
{
	int j,a=1;
	while(a)
	{
		printf("1.��Ӿ���\n");
		printf("2.��������\n");
		printf("3.��ʾ���о���\n");
		printf("4.��ʾ����Ա��\n");
		printf("5.�鿴��Ʒ�������\n");
		printf("6.�޸�Ա����Ϣ\n");
		printf("0.��������\n");
		printf("��ѡ����Ĳ�����");
		scanf("%d",&a);
		while(a!=1&&a!=2&&a!=3&a!=4&&a!=5&&a!=6)
		{
			if(a==0)
			{
				printf("\033[1;31m�����Ƴ�ϵͳ������\033[0m\n");
				printf("ȷ���˳��밴0\n");
				printf("���������밴1\n");
				scanf("%d",&j);
				while(j!=0&&j!=1)
				{
					printf("\033[1;31m��������!\033[0m\n����������:");
					scanf("%d",&j);
				}
				if(j==0)
				{
					printf("\033[1;34m��л���ʹ�ã�\033[0m");
					a=0;
					break;
				}
				else
				{
					a=6;
					break;
				}		
			}
			else
			{
				printf("\033[1;32m��������!\033[0m\n����������:");
				scanf("%d",&a);
			}
		}
		system("cls"); 
		switch (a)
		{
			case 1:
				addpeople(w,t);
				break;	
			case 2:
				delpeople(w,t);
				break;
			case 3:
				display(t);
				break;	
			case 4:
				display(t);
				display(t-1);
				break;
			case 5:
				disshow();
				break;	
			case 6:
				change();
				break;
		} 
	}
}
int main()//���º�
{
	int i;
	printf("1.�ͻ�\n");
	printf("2.Ա��\n");
	printf("3.����\n");
	printf("4.�ϰ�\n");
	printf("��ѡ�������ݣ�");
	scanf("%d",&i);
	getchar();
	while(i!=1&&i!=2&&i!=3&&i!=4)
	{
		printf("\033[31m�������!����������:\033[0m");
		scanf("%d",&i);
		getchar();
	}
	system("cls"); 
	if(i==1)
		custom();
	else 
		accountpassword(i);
	return 0;
}
