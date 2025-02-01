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
int atime(int t)//赵新航 
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
void changes(char e[])//赵新航 
{
	struct Users ir;
	char a[20];
	FILE* fp;
	fp=fopen("users.bin","rb");
	if(fp==NULL)
		printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
	FILE* rp;
	rp=fopen("temp.bin","wb");
	if(fp==NULL)
		printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
	while(fread(&ir,sizeof(struct Users),1,fp)==1)
	{
		if(strcmp(ir.id,e)==0)
		{
			printf("请输入修改后的密码：");
			scanf("%s",ir.password);
			printf("请再次输入修改后的密码：");
			scanf("%s",a);
			if(strcmp(ir.password ,a)!=0)
			{
				printf("\033[1;31m两次密码输入不一致！\033[0m\n");
				printf("请重新输入修改后的密码：");
				scanf("%s",ir.password);
				printf("请再次输入修改后的密码：");
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
void commodity(int t,char e[],FILE* ap) //柳心怡 
{
	FILE* rp;
	struct Commodity ir;
	struct Allmoney ar;
	int x,overtime;
	rp=fopen("warehouse.bin","rb");
	if(rp==NULL)
		printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
	while(fread(&ir,sizeof(struct Commodity),1,rp)==1)
	{
		if(t==ir.comtype)
		{
			if(ir.overtime>displaytime())
			{
				printf("商品名称：%s  商品数量：%d  商品单价：%lf  过期时间为：%ld  ",ir.name,ir.num,ir.money,ir.overtime);
				if(ir.type==1)
					printf("计算方式为：称重  \n");
				else
					printf("计算方式为：按个计算  \n");
			}
		}
	}
	fclose(rp);
    printf("如果没有想要的商品请按0返回上一级\n继续购物请按1\n");
    int m=1;   
    scanf("%d",&m);
    while(m!=0&&m!=1)
    {
    	printf("输入有问题，请重新输入：");
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
    				printf("商品不存在,请重新选择你想要的商品:");
				else if(b==0)
    				printf("请选择你想要的商品:");
			    scanf("%s",a);
			    printf("请输入购买商品的过期时间：");
		    	scanf("%d",&overtime);
			    	while(atime(overtime)==0)
				{
					printf("\033[1;31m日期输入有误!\n请重新输入:\033[0m");
					scanf("%d",&overtime);
				}
			    FILE* bp;
				bp=fopen("warehouse.bin","rb");
				if(bp==NULL)
					printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
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
		    printf("请输入购买的数量：");
		    scanf("%d",&x);
		    double y;
		    FILE* bp;
			bp=fopen("warehouse.bin","rb");
			if(bp==NULL)
				printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
			FILE* fp;
			fp=fopen("temp.bin","wb");
			if(fp==NULL)
				printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
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
				printf("您输入的商品库存不足！"); 
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
					printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
				fwrite(&ar, sizeof(struct Allmoney), 1, qp);
				fwrite(&ar, sizeof(struct Allmoney), 1, ap);
				fclose(qp);
				int j;
				printf("1.继续购买\n");
				printf("2.购物完毕\n");
				printf("请选择下一步的操作:");
				scanf("%d",&j);
				while(j!=1&&j!=2)
				{
					printf("输入错误,重新输入\n");	
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
						printf("请问您是否是会员\n");
						printf("1.会员\n");
						printf("2.非会员\n");
						printf("请选择：");
						scanf("%d",&m);
						while(m!=1&&m!=2)
						{
							printf("\n输入错误，请重新输入\n");
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
void removeinformation(char e[],int t) //柳心怡 
{
	struct Users ir;
	FILE* fp;
	fp=fopen("users.bin","rb"); 
	if(fp==NULL)
		printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
	FILE* rp;
	rp=fopen("transition.bin","wb");
	if(rp==NULL)
		printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
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
	printf("操作完成，将为你跳转到结账界面...\n");
	checkout(e,t);
}
double allintegral(char e[],double i)//柳心怡 
{
    struct Users ir;
    FILE* fp;
    FILE* rp;
    fp = fopen("users.bin", "rb"); 
    if(fp==NULL)
		printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
    rp = fopen("transition.bin", "wb");
    if(rp==NULL)
		printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
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
void enterinformation(char e[]) //柳心怡 
{
	printf("请输入你想要注册的会员时长(年)："); 
	int m;
	scanf("%d",&m);
	while(m<1)
	{
		printf("输入有误！\n请重新输入：");
		scanf("%d",&m);
	}
	struct Users sr;
	FILE* fp;
	fp=fopen("users.bin","rb");
	if(fp==NULL)
		printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
	FILE* rp;
	rp=fopen("temp.bin","wb");
	if(rp==NULL)
		printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
	while(fread(&sr,sizeof(struct Users),1,fp)==1)
	{
		if(strcmp(sr.id,e)==0)
		{
			sr.member=1;
			sr.deadline=m*10000+displaytime();
			printf("会员过期时间为：%d\n",sr.deadline);
			fwrite(&sr,sizeof(struct Users),1,rp);
		}
		else
			fwrite(&sr,sizeof(struct Users),1,rp);
	}
	fclose(fp);
	fclose(rp);
	remove("users.bin");
	rename("temp.bin","users.bin");
	printf("\033[1;32m操作完成！\033[0m\n");
}
void logoffmembership(char e[],int t)//柳心怡 
{
	printf("您已来到注销界面\n");
	printf("是否确定注销\n");
	printf("1.否\n");
	printf("2.是\n");
	int x;
	printf("请选择：");
	scanf("%d",&x);
	while(x!=1&&x!=2)
	{
		printf("输入有误！请重新输入：");
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
void checkout(char e[],int t)//柳心怡 
{
	printf("欢迎来到结账界面\n");
	int a=0; 
	int i=1;
	switch (t)
	{
		case 1:
			printf("请问需要几个袋字（一个袋子0.5元）：");
			scanf("%d",&a);
			break;
		case 2:
			printf("1.上门取货\n");
			printf("2.送货上门（每件商品一元）\n");
			printf("请选择你的取货方式：");
			scanf("%d",&i);
			while(i!=1&&i!=2)
			{
				printf("输入错误！请重新输入：");
				scanf("%d",&i);
			}
			break;	
	}
	double q=0;
	FILE* fp;
	fp=fopen("amoney.bin","rb");
	if(fp==NULL)
		printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
	struct Allmoney ir;
	while(fread(&ir,sizeof(struct Allmoney),1,fp)==1)
	{
		if(ir.time==displaytime()&&strcmp(e,ir.e)==0)
		{
			printf("商品名称%s 数量%d 单价%lf\n",ir.a,ir.x,ir.y);
			q=q+ir.x*ir.y+i-1;
		}
	}
	fclose(fp);
	q=q+a*0.5;
	printf("总价%lf",q);
	q=allintegral(e,q);
	printf(",结账成功，感谢您的使用,您目前积分为%lf\n",q); 
}
void registeredmember(char e[],int t)//柳心怡 
{
	printf("欢迎来到注册会员界面\n");
	struct Users people;
	struct Users x;
	printf("会员年费：150元\n");
	printf("请确定你是否要注册\n");
	printf("1.否\n");
	printf("2.是\n");
	int i;
	printf("请选择：");
	scanf("%d",&i);
	while(i!=1&&i!=2)
	{
		printf("输入有误！请重新输入：");
		scanf("%d",&i);
	}
	switch(i)
	{
		case 1:
			checkout(e,t);
			break;
		case 2:
			enterinformation(e);
			printf("注册成功\n");
			printf("1.会员结账\n");
			printf("2.非会员结账\n");
			int j;
			printf("请选择:");
			scanf("%d",&j);
			while(j!=1&&j!=2)
			{
				printf("输入错误！请重新输入：");
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
void membershiprenewal(char e[],int t)//柳心怡 
{
	printf("欢迎来到会员续费界面\n");
	printf("会员年费：150元\n"); 
	printf("请输入你想要续费的时长：");
	int n;
	scanf("%d",&n);
	while(n<1)
	{
		printf("输入有误！请重新输入：");
		scanf("%d",&n);
	}
	struct Users sp;
	FILE* fp;
	fp=fopen("users.bin","rb");
	if(fp==NULL)
		printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
	FILE* rp;
	rp=fopen("transition.bin","wb");
	if(rp==NULL)
		printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
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
	printf("续费成功！\n");
	int a;
	printf("1.会员结账\n");
	printf("2.直接结账\n");
	printf("请选择你想要的操作：");
	scanf("%d",&a);
	while(a!=1&&a!=2)
	{
		printf("输入有误！请重新输入：");
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
void membercheckout(char e[],int t) //柳心怡 
{
	int a=0; 
	int i=1;
	printf("欢迎使用会员结账\n");
	switch (t)
	{
		case 1:
			printf("请问需要几个袋字（一个袋子0.5元）：");
			scanf("%d",&a);
			break;
		case 2:
			printf("1.上门取货\n");
			printf("2.送货上门（每件商品一元）\n");
			printf("请选择你的取货方式：");
			scanf("%d",&i);
			while(i!=1&&i!=2)
			{
				printf("输入错误！请重新输入：");
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
		printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
	struct Allmoney ir;
	while(fread(&ir,sizeof(struct Allmoney),1,fp)==1)
	{
		if(ir.time==displaytime()&&strcmp(e,ir.e)==0)
		{
			printf("商品名称%s 数量%d 单价%lf\n",ir.a,ir.x,ir.y);
			q=q+ir.x*ir.y+i-1;
		}
	}
	fclose(fp);
	q=q+0.5*a;
	printf("原价%lf，打折后%lf\n",q,q*0.9);
	q=allintegral(e,q*0.9);
	printf("结账成功，感谢您的使用,您目前积分为%lf\n",q); 
}
void manualcheckout(char e[])//柳心怡 
{
	printf("欢迎使用人工结账\n");
	struct Users text;
	struct Users real;
	int a=0;
	FILE *fp;
	fp=fopen("users.bin","rb");
	if(fp==NULL)
		printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
	while(fread(&text,sizeof(struct Users),1,fp)==1)
	{
		if(strcmp(e,text.id)==0&&text.member==1&&text.deadline>=displaytime())
		{
			printf("会员验证成功,为您使用会员结算\n");
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
void automaticcheckout(char e[]) //柳心怡 
{
	printf("欢迎自主结账\n");
	int m;
	printf("请问您是否是会员\n");
	printf("1.会员\n");
	printf("2.非会员\n");
	printf("请选择：");
	scanf("%d",&m);
	while(m!=1&&m!=2)
	{
		printf("输入错误！请重新输入：");
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
void chose(char e[],int t) //柳心怡 
{
	printf("您目前不是会员！\n");
	printf("1.注册会员\n");
	printf("2.直接结账\n");
	int y;
	printf("请选择你想要的操作：");
	scanf("%d",&y);
	while(y!=1&&y!=2)
	{
		printf("输入错误！请重新输入：");
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
void onlineshopping(char a[],FILE* ap) //柳心怡 
{
	printf("1.果蔬类\n");
	printf("2.肉类\n");
	printf("3.水产类\n");
	printf("4.食品类\n");
	printf("5.生活类\n");
	printf("请选择你想要的商品种类：");
	int x;
	scanf("%d",&x);
	while(x!=1&&x!=2&&x!=3&&x!=4&&x!=5)
	{
		printf("输入错误，请重新输入");
		scanf("%d",&x);
	}
	system("cls"); 
	commodity(x,a,ap);
}
void offlineshopping(char e[],FILE* ap) //柳心怡 
{
	printf("欢迎使用线下购物！\n");
	printf("请选择你想要查询的商品种类：\n");
    printf("请选择你想要的商品种类：\n");
	printf("1.果蔬类\n");
	printf("2.肉类\n");
	printf("3.水产类\n");
	printf("4.食品类\n");
	printf("5.生活类\n");
	int y;
	scanf("%d",&y);
	while(y!=1&&y!=2&&y!=3&&y!=4&&y!=5)
	{
		printf("输入错误，请重新输入\n");
		scanf("%d",&y);
	}
	system("cls"); 
	FILE* lp;
	struct Commodity ir;
	int x;
	lp=fopen("warehouse.bin","rb");
	if(lp==NULL)
		printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
	while(fread(&ir,sizeof(struct Commodity),1,lp)==1)
	{
		if(y==ir.comtype)
		{
			if(ir.overtime>displaytime())
			{
				printf("商品名称：%s  商品数量：%d  商品单价：%lf  过期时间为：%d  ",ir.name,ir.num,ir.money,ir.overtime);
				if(ir.type==1)
					printf("计算方式为：称重  \n");
				else
					printf("计算方式为：按个计算  \n");
			}
		}
	}
	fclose(lp);
    printf("如果没有想要的商品请按0返回上一级\n继续购物请按1\n");
    int m=1;
    int overtime;
    scanf("%d",&m);
    while(m!=0&&m!=1)
    {
    	printf("输入有误，请重新输入\n");
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
    				printf("商品不存在,请重新选择你想要的商品:");
				else if(b==0)
    				printf("请选择你想要的商品:");
			    scanf("%s",a);
			    printf("请输入购买商品的过期时间：");
			    scanf("%d",&overtime);
			    while(atime(overtime)==0)
				{
					printf("\033[1;31m日期输入有误!\n请重新输入:\033[0m");
					scanf("%d",&overtime);
				}
			    FILE* bp;
				bp=fopen("warehouse.bin","rb");
				if(bp==NULL)
					printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
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
		    printf("请输入购买的数量：");
		    scanf("%d",&x);
		    
		    double y=1;
		    FILE* bp;
			bp=fopen("warehouse.bin","rb");
			if(bp==NULL)
				printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
			FILE* fp;
			fp=fopen("temp.bin","wb");
			if(fp==NULL)
				printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
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
				printf("您输入的商品库存不足！\n");
				printf("请重新选择商品\n");
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
					printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
				fwrite(&ar, sizeof(struct Allmoney), 1, qp);
				fwrite(&ar, sizeof(struct Allmoney), 1, ap);
				fclose(qp);
			    printf("请选择下一步的操作\n");
				int q;
				printf("1.继续购买\n");
				printf("2.购物完毕\n");
				scanf("%d",&q);
				while(q!=1&&q!=2)
				{
					printf("输入错误!\n请重新输入:");	
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
						
						printf("1.人工结账\n");
						printf("2.自主结账\n");
						printf("请选择："); 
						scanf("%d",&j);
						while(j!=1&&j!=2)
						{
							printf("输入错误！\n请重新输入:");
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
void textmembership(char e[],int t)//柳心怡 
{
	struct Users text;
	struct Users real;
	FILE *fp;
	fp=fopen("users.bin","rb");
	if(fp==NULL)
		printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
	while(fread(&text,sizeof(struct Users),1,fp)==1)
	{
		if(strcmp(e,text.id)==0)
		{
			if(text.member==1)
			{
				fclose(fp);
				if(text.deadline>=displaytime())
				{
					printf("会员验证成功\n");
				    membercheckout(e,t);
				}
				else
				{
				    printf("会员验证失败\n");
				    printf("您的会员已过期\n");
					printf("请选择你要的操作：\n");
					printf("1.会员续费\n");
					printf("2.不继续使用会员,注销会员\n");
					printf("3.非会员结账\n");
					int s;
					scanf("%d",&s);
					while(s!=1&&s!=2&&s!=3)
					{
						printf("输入出错!\n请重新输入:");
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
				printf("您还不是会员，请注册会员\n");
				fclose(fp);
				registeredmember(e,t);
			}
		}
    }
}
void shopping(char a[])//柳心怡 
{
	printf("1.线上购物\n");
	printf("2.线下购物\n");
	printf("请选择你想要的购物方式：");
	int i;
	scanf("%d",&i);
	FILE* ap;
	ap=fopen("amoney.bin","wb");
	if(ap==NULL)
		printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
	while(i!=1&&i!=2)
	{
		printf("输入错误!\n请重新输入:");
		scanf("%d",&i);
	 } 
	system("cls"); 
	switch(i)
	{
		case 1:
			printf("欢迎使用线上购物！\n");
			onlineshopping(a,ap);
			break;
		case 2:
			offlineshopping(a,ap);
			break;
	}
	fclose(ap);
}
void setupanaccount()//柳心怡  
{
	char passwords[20];
	struct Users sr;
	struct Users ir;
	FILE* fp;
	FILE* rp;
	fp=fopen("users.bin","rb");
	if(fp==NULL)
		printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
	rp=fopen("users.bin","ab");
	if(rp==NULL)
		printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
	printf("请输入姓名：");
	scanf("%s",sr.name);
	printf("请输入性别（男m;女f）：");
	scanf("%s",sr.sex);
	while(strcmp(sr.sex,"f")!=0&&strcmp(sr.sex,"m")!=0)
	{
		printf("\033[1;31m性别输入错误！\033[0m\n请重新输入：");
		scanf("%s",sr.sex);
	}
	printf("请输入你的账号:");
	scanf("%s",sr.id);
	while(fread(&ir,sizeof(struct Users),1,fp)==1)
	{
		if(strcmp(ir.id,sr.id)==0)
		{
			printf("\033[1;31m账号已存在\033[0m\n请重新输入:");
			scanf("%s",sr.id);
			rewind(fp);
		}
	}
	printf("请输入电话号码：");
	scanf("%s",sr.phone);
	rewind(fp);
	while(fread(&ir,sizeof(struct Users),1,fp)==1)
	{
		if(strcmp(ir.phone,sr.phone)==0)
		{
			printf("\033[1;31m号码已存在\033[0m\n请重新输入:");
			scanf("%s",sr.phone);
			rewind(fp);
		}
	}
	printf("请输入密码：");
	scanf("%s",sr.password);
	printf("请再次输入密码：");
	scanf("%s",passwords);
	while(strcmp(sr.password,passwords)!=0)
	{
		printf("\033[1;31m两次密码不一致\033[0m\n");
		printf("请重新输入密码：");
		scanf("%s",sr.password);
		printf("请再次输入密码：");
		scanf("%s",passwords);
	}
	sr.member=0;
	sr.integral=0;
	sr.deadline=0;
	fwrite (&sr,sizeof(struct Users),1,rp);
	printf("注册成功！！！\n");
	fclose(fp);
	fclose(rp);
	printf("请选择你想要的操作\n"); 
    printf("1.退出界面\n");
	printf("2.登录账号\n");
	int f;
	scanf("%d",&f);
	while(f!=1&&f!=2)
	{
		printf("\033[1;31m输入错误!\033[0m\n请重新输入！\n");
		scanf("%d",&f);
	}
	getchar();
	int j,y;
	switch(f)
	{
		case 1:
			printf("\n\033[1;32m谢谢您的使用！\033[0m\n");
			break;
		case 2:
			custom();
			break;
	}
}
int loginaccount()//赵新航 
{
	char ch;
	char a[20],b[20]; 
	int n,x,y,z=0;
	printf("请输入你的账号:");
	gets(a);
	FILE *fp;
	fp=fopen("users.bin","rb");
	if(fp==NULL)
		printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
	y=2;
	struct Users use;
	while(fread(&use,sizeof(struct Users),1,fp)==1)
	{
		if(strcmp(a,use.id)==0)
		{
			printf("账号正确\n");
			x=1;
			while(1)
			{
				printf("请输入密码:");
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
					printf("\n\033[1;32m密码正确\033[0m\n");
      				y=1;
      				printf("欢迎使用\n");
      				fclose(fp);
      				shopping(a);
					break;
				}
				else
				{
					if(x==3)
					{
						printf("\n密码不正确\n");
						printf("1.重新登录\n");
						printf("2.修改密码\n");
						printf("请选择：");
						scanf("%d",&n);
						while(n!=1&&n!=2)
						{
							printf("\033[1;31m输入错误！\033[0m\n请重新输入：");
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
							printf("欢迎使用\n");
		      				shopping(a);
		      				break;
						 }		
					}
					else 
					{
						printf("\n密码错误\n你还有%d次机会\n",3-x);
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
void custom()//赵新航 
{
	int i;
	printf("1.有账号\n");
	printf("2.无账号\n");
	printf("请选择：");
	scanf("%d",&i);
	while(i!=1&&i!=2)
	{
		getchar();
		printf("输入错误\n");
		printf("请重新输入：");
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
					printf("账号不存在\n");
					printf("你还有%d次输入机会\n",2-j);
					a=loginaccount();
					if(2-j==1&&a==2)
					{
						printf("\033[31m账号不存在，你的三次机会已经用完！！！\033[0m");
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
int dep(char w[])//赵新航
{
	struct Workers ir;
	FILE* fp;
	fp=fopen("accountpassword.bin","rb");
	if(fp==NULL)
		printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
	while(fread(&ir,sizeof(struct Workers),1,fp)==1)
	{
		if (strcmp(w, ir.jobnum)==0) 
		break;
	}
	fclose(fp);
	return ir.department;
}
int displaytime() //赵新航
{
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
	int t;
	t=1900*10000+timeinfo->tm_year*10000+(timeinfo->tm_mon + 1)*100+timeinfo->tm_mday;
    return t;
}
void disshow()//赵新航
{
	char name[20];
	int m;
	double n=0;
	FILE* fp;
	fp=fopen("allmoney.bin","rb");
	if(fp==NULL)
		printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
	struct Allmoney ir;
	printf("1.查看当天的销售情况\n");
	printf("2.查看当月的销售情况\n");
	printf("3.查看某种商品单月的销售情况\n");
	printf("请选择要查看的内容：");
	scanf("%d",&m);
	while(m!=1&&m!=2&&m!=3)
	{
		printf("输入有误!\n请重新输入：");
		scanf("%d",&m);
	}
	system("cls"); 
	int a,b;
	a=1;
	b=1;
	switch (m)
	{
		case 1:
			printf("当天的销售情况:\n");
			while(fread(&ir,sizeof(struct Allmoney),1,fp)==1)
			{
				if(ir.time==displaytime())
				{
					printf("商品名称:%s 数量%d 单价%lf\n",ir.a,ir.x,ir.y);
					n=n+ir.x*ir.y;
				}
					
			}
			break;
		case 2:
			printf("当月的销售情况:\n");
			while(fread(&ir,sizeof(struct Allmoney),1,fp)==1)
			{
				if(ir.time/100==displaytime()/100)
				{
					printf("商品名称:%s 数量%d 单价%lf\n",ir.a,ir.x,ir.y);
					n=n+ir.x*ir.y;
				}
					
			}
			break;
		case 3:
			printf("请输入商品的名称：");
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
						printf("该商品不存在！您已多次查询不到商品！！！\n");
						a=0; 
					}
					else
					{
						printf("该商品不存在！\n请重新输入：");
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
					printf("商品名称:%s 数量%d 单价%lf\n",ir.a,ir.x,ir.y);
					n=n+ir.x*ir.y;
				}
			}
			break;		
	}
	printf("\033[1;32m总收入为：\033[0m %lf\n",n);
	fclose(fp);
}
void change()//赵新航
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
		printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
	FILE* rp;
	rp=fopen("temp.bin","wb");
	if(rp==NULL)
		printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
	printf("请输入要修改的员工工号：");
	scanf("%s",sr.jobnum);
	while(i)
	{
		while(fread(&ir,sizeof(struct Workers),1,fp)==1)
		{
			if(strcmp(ir.jobnum,sr.jobnum)==0)
			{
				i=0;
				printf("您所要修改的员工信息为:");
				printf("\033[1;33m姓名：%s  工号：%s  年龄：%d  电话号码：%s  属于：\033[0m",ir.name,ir.jobnum,ir.age,ir.phone);
				switch (ir.department)
				{
					case 1:
						printf("\033[1;33m果蔬部门\033[0m\n");
						break;
					case 2:
						printf("\033[1;33m肉类部门\033[0m\n");
						break;
					case 3:
						printf("\033[1;33m水产部门\033[0m\n");
						break;
					case 4:
						printf("\033[1;33m食品部门\033[0m\n");
						break;
					case 5:
						printf("\033[1;33m生活部门\033[0m\n");
						break;
				}
				rewind(fp);
				printf("1.修改电话号码\n");
				printf("2.修改属于部门\n");
				printf("3.修改密码\n"); 
				printf("请选择要修改的内容：");
				scanf("%d",&n);
				while(n!=1&&n!=2&&n!=3)
				{
					printf("\033[1;31m输入有误!\033[0m\n请重新输入:");
					scanf("%d",&n);
				}
				switch (n)
				{
					case 1:
						printf("请输入修改后的电话号码：");
						scanf("%s",sr.phone);
						break;
					case 2:
						printf("1.果蔬2.肉类3.水产4.食品5.生活\n");
						printf("请输入修改后的部门：");
						scanf("%d",&sr.department);
						while(sr.department!=1&&sr.department!=2&&sr.department!=3&&sr.department!=4&&sr.department!=5)
						{
							printf("\033[1;31m输入有误!\033[0m\n请重新输入:");
							scanf("%d",&sr.department);
						}
								break;
					case 3:
						printf("请输入修改后的密码：");
						scanf("%s",sr.password);
						printf("请再次输入修改后的密码：");
						scanf("%s",a);
						if(strcmp(sr.password ,a)!=0)
						{
							printf("\033[1;31m两次密码输入不一致！\033[0m\n");
							printf("请重新输入修改后的密码：");
							scanf("%s",sr.password);
							printf("请再次输入修改后的密码：");
							scanf("%s",a);
						}
						break;
				}
				printf("如果确认修改请输入 1\n");
				printf("如需重新修改请输入 2\n");
				printf("返回上一级请输入 0\n");
				printf("请选择：");
				scanf("%d",&j);
				while(j!=1&&j!=2&&j!=0)
				{
					printf("\033[1;31m输入有误!\033[0m\n请重新输入:");
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
				printf("\033[1;31m输入错误此次太多请查看清楚再重新打开！！！\033[0m\n");
				break;
			}
			printf("\033[1;31m工号输入有误!\033[0m\n请重新输入:");
			scanf("%s",sr.jobnum);
			rewind(fp);
			i=1;
		}
    }
}
void display(int t)//赵新航
{
	FILE* fp;
	struct Workers ir;
	fp=fopen("accountpassword.bin","rb");
	if(fp==NULL)
		printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
	while(fread(&ir,sizeof(struct Workers),1,fp)==1)
	{
		if(ir.responsibility==t-1)
		{
			printf("姓名：%s  工号：%s  密码：%s  年龄：%d  性别：%d  电话：%s  ",ir.name,ir.jobnum,ir.password,ir.age,ir.sex,ir.phone); 
			switch (ir.responsibility)
			{
				case 2:
					printf("职位：员工  ");
					break;
				case 3:
					printf("职位：经理  ");
					break;
			}
			switch (ir.department)
			{
				case 1:
					printf("部门：果蔬\n");
					break;
				case 2:
					printf("部门：肉类\n");
					break;
				case 3:
					printf("部门：水产\n");
					break;
				case 4:
					printf("部门：食品\n");
					break;
				case 5:
					printf("部门：生活\n");
					break;
			}
		}
	}
	fclose(fp);
}
void addwareh(char w[],int a)//赵新航
{
	FILE* fp;
	fp=fopen("wareh.bin","ab");
	if(fp==NULL)
		printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
	struct Commodity sr;
	printf("请输入商品的名称：");
	scanf("%s",sr.name);
	printf("请输入商品的数量：");
	scanf("%d",&sr.num);
	printf("请输入商品的价格：");
	scanf("%lf",&sr.money);
	printf("商品的计算方法：\n");
	printf("1.称重\n");
	printf("2.按个\n");
	printf("请选择计算方法：");
	scanf("%d",&sr.type);
	while(sr.type!=1&&sr.type!=2)
	{
		printf("输入错误！！!\n");
		printf("请选择计算方法：");
		scanf("%d",&sr.type);
	}
	strcpy(sr.worker,w);
	printf("请输入商品的过期日期：如(20240101)");
	scanf("%d",&sr.overtime);
	while(atime(sr.overtime)==0)
	{
		printf("\033[1;31m日期输入有误!\n请重新输入:\033[0m");
		scanf("%d",&sr.overtime);
	}
	sr.comtype=dep(w);
	fwrite(&sr,sizeof(struct Commodity),1,fp);
	fclose(fp);
	printf("\033[32m进货成功\033[0m\n");
}
void addwarehouse(char w[],int a) //赵新航
{
	int c,d;
	FILE* rp;
	FILE* bp;
	rp=fopen("warehouse.bin","rb");
	if(rp==NULL)
		printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
	bp=fopen("wareh.bin","rb");
	if(bp==NULL)
		printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
	struct Commodity sr;
	struct Commodity ir;
	printf("请输入商品的名称：");

	scanf("%s",sr.name);
	printf("请输入商品的过期时间：");
	scanf("%d",&sr.overtime);
	while(atime(sr.overtime)==0)
	{
		printf("\033[1;31m日期输入有误!\n请重新输入:\033[0m");
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
				printf("该商品仓库内信息:数量%d\n请输入要上架的数量：",ir.num);
				scanf("%d",&c);
				while(c>ir.num)
				{
					printf("仓库库存不足，请重新输入：");
					scanf("%d",&c);
				}
				d=ir.num-c;
				b=0; 
				rewind(bp);
				FILE *op = fopen("temp.bin", "wb");
				if(op==NULL)
					printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
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
			printf("仓库内不存在此商品，请重新输入：");
			scanf("%s",sr.name);
			printf("请输入商品的过期时间：");
			scanf("%d",&sr.overtime);
		}
	}
	FILE *op = fopen("temp.bin", "wb");
	if(op==NULL)
		printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
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
	printf("\033[1;32m上架成功\033[0m\n");
}
void delwarehouse(char w[],int a) //赵新航
{
	int i=0;
	FILE* rp;
	FILE* fp;
	FILE* bp;
	rp=fopen("warehouse.bin","rb");
	if(rp==NULL)
		printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
	bp=fopen("wareh.bin","rb");
	if(bp==NULL)
		printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
	struct Commodity sr;
	struct Commodity ir;
	printf("请输入要下架的商品的名称：");
	scanf("%s",sr.name);
	printf("请输入商品的过期时间：");
	scanf("%d",&sr.overtime);
	while(atime(sr.overtime)==0)
	{
		printf("\033[1;31m日期输入有误!\n请重新输入:\033[0m");
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
				printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
			while(fread(&ir,sizeof(struct Commodity),1,rp)==1)
				if (strcmp(sr.name,ir.name) != 0) 
					fwrite(&ir,sizeof(struct Commodity),1,op);
			fclose(op);
			fclose(rp);
			remove("warehouse.bin"); 
			rename("temp.bin", "warehouse.bin"); 
			FILE* cp = fopen("temp.bin", "wb");
			if(cp==NULL)
				printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
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
					printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
				strcpy(sr.worker,w);
				fwrite(&sr,sizeof(struct Commodity),1,fp);
				fclose(fp);
			}
			printf("\033[1;32m下架成功\033[0m\n");
			break;
		}
	}
	if(i==0)
		printf("没有这款商品存在！！！\n");
}
void displayh(char w[],int a) //赵新航
{
	FILE* rp;
	struct Commodity ir;
	switch (a)
	{
		case 3:
			rp=fopen("wareh.bin","rb");
			if(rp==NULL)
				printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
			break;
		case 2:
			rp=fopen("warehouse.bin","rb");
			if(rp==NULL)
				printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
			break;
	 } 
	while(fread(&ir,sizeof(struct Commodity),1,rp)==1)
	{	
		if(dep(w)==ir.comtype)
		{
			if(ir.overtime<displaytime())
			{
				printf("\033[31m商品名称：%s  商品数量：%d  商品单价：%lf  过期时间为：%d  \033[0m",ir.name,ir.num,ir.money,ir.overtime);
				if(ir.type==1)
					printf("\033[31m计算方式为：称重  \033[0m\n");
				else
					printf("\033[31m计算方式为：按个计算  \033[0m\n");
			}
			else
			{
				printf("商品名称：%s  商品数量：%d  商品单价：%lf  过期时间为：%d  ",ir.name,ir.num,ir.money,ir.overtime);
				if(ir.type==1)
					printf("计算方式为：称重  \n");
				else
					printf("计算方式为：按个计算  \n");
			}
		}
	}
	fclose(rp);
}
void warehouse(char w[],int a) //赵新航
{
	int j,i=1;
	while(i)
	{
		printf("1.上架商品\n");
		printf("2.下架商品\n");
		printf("3.显示货架所有商品\n");
		printf("4.显示仓库所有商品\n");
		printf("0.结束操作\n");
		printf("请选择你的操作：");
		scanf("%d",&i);
		while(i!=1&&i!=2&&i!=3&&i!=4)
		{
			if(i==0)
			{
				printf("\033[1;31m即将推出系统！！！\033[0m\n");
				printf("确定退出请按0\n");
				printf("继续工作请按1\n");
				scanf("%d",&j);
				while(j!=0&&j!=1)
				{
					printf("\033[1;31m输入有误!\033[0m\n请重新输入:");
					scanf("%d",&j);
				}
				if(j==0)
				{
					printf("\033[1;34m感谢你的使用！\033[0m");
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
				printf("\033[1;32m输入有误!\033[0m\n请重新输入:");
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
void accountpassword(int t)//赵新航
{
	int i,j,z=0;
	char ch;
	char a[20],b[20],c[20],d[20];
	ap:printf("请输入你的工号：");
	gets(a);
	FILE* fp;
	fp=fopen("accountpassword.bin","rb");
	if(fp==NULL)
		printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
	i=0;
	j=0;
	struct Workers ir;
	while(fread(&ir,sizeof(struct Workers),1,fp)==1)
	{ 
		if (strcmp(a, ir.jobnum) == 0 && ir.responsibility==t) 
		{ 
			printf("\033[32m工号正确\033[0m\n");
			i=1;
			while(1)
			{
				printf("请输入密码：");
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
					printf("\n\033[32m密码正确\033[0m\n");
					j=1;
					fclose(fp); 
					break; 
				}
				else
				{
					if(i==3)
					{
						printf("\n密码不正确\n");
						printf("\033[1;31m请联系老板进行修改！！！\033[0m");
						j=0;
						break;
					}
					else
					{
						printf("\n密码错误\n你还有%d次机会\n",3-i);
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
		printf("\033[1;31m工号不正确\033[0m\n");
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
void addpeople(char w[],int t)//赵新航
{
	char a[20];
	FILE* fp;
	FILE* rp;
	fp=fopen("accountpassword.bin","ab");
	if(fp==NULL)
		printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
	rp=fopen("accountpassword.bin","rb");
	if(rp==NULL)
		printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
	printf("请输入所要添加人员的姓名：");
	struct Workers sr;
	struct Workers ir;
	scanf("%s",sr.name);
	printf("工号：");
	scanf("%s",sr.jobnum);
	while(fread(&ir,sizeof(struct Workers),1,rp)==1)
	{
		while (strcmp(sr.jobnum, ir.jobnum) == 0)
		{
			printf("\033[1;31m工号已存在!\033[0m\n请重新输入:");
			scanf("%s",sr.jobnum);
			rewind(rp);
		}
	} 
	printf("密码：");
	scanf("%s",sr.password);
	printf("请再次输入密码：");
	scanf("%s",a);
	while(strcmp(sr.password,a)!=0)
	{
		printf("\033[1;31m两次密码不一致！！！\033[0m\n请重新输入密码:");
		scanf("%s",sr.password);
		printf("请再次输入密码：");
		scanf("%s",a);
	}
	printf("年龄：");
	scanf("%d",&sr.age);
	printf("性别(男1/女0)：");
	scanf("%d",&sr.sex);
	while(sr.sex!=1&&sr.sex!=0)
	{
		printf("\033[1;31m性别输入错误！\033[0m\n重新输入:");
		scanf("%d",&sr.sex);
	}
	sr.responsibility=t-1;
	printf("电话号码：");
	scanf("%s",sr.phone);
	if(dep(w)==0)
	{
		printf("1.果蔬2.肉类3.水产4.食品5.生活\n");
		printf("请输入属于的部门：");
		scanf("%d",&sr.department);
		while(sr.department!=1&&sr.department!=2&&sr.department!=3&&sr.department!=4&&sr.department!=5)
		{
			printf("\033[1;31m输入有误！！！\033[0m\n");
			printf("1.果蔬2.肉类3.水产4.食品5.生活\n");
			printf("请重新输入属于的部门：");
			scanf("%d",&sr.department);
		}
	}
	else
	 	sr.department=dep(w);
	fwrite(&sr,sizeof(struct Workers),1,fp);
	printf("\033[1;32m添加成功！\033[0m\n");
	fclose(fp);
	fclose(rp);
}
void delpeople(char w[],int t)//赵新航
{
	int j,i=1;
	struct Workers ir; 
	FILE* fp;
	fp=fopen("accountpassword.bin","rb");
	if(fp==NULL)
		printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
	printf("请输入所要开除员工的工号：");
	FILE* rp;
	rp=fopen("temp.bin","wb");
	if(rp==NULL)
		printf("\033[1;31m程序错误，请联系专业人员！！！\033[0m\n");
	char jobnum[20];
	scanf("%s",jobnum);
	while(i)
	{
		while(fread(&ir,sizeof(struct Workers),1,fp)==1)
		{
			if(strcmp(ir.jobnum,jobnum)==0 && ir.responsibility==t-1)
			{
				i=0;
				printf("您所要删除的员工为:");
				printf("\033[1;33m姓名%s  工号%s  年龄%d  电话号码%s  属于\033[0m",ir.name,ir.jobnum,ir.age,ir.phone);
				switch (ir.department)
				{
					case 1:
						printf("\033[1;33m果蔬部门\033[0m\n");
						break;
					case 2:
						printf("\033[1;33m肉类部门\033[0m\n");
						break;
					case 3:
						printf("\033[1;33m水产部门\033[0m\n");
						break;
					case 4:
						printf("\033[1;33m食品部门\033[0m\n");
						break;
					case 5:
						printf("\033[1;33m生活部门\033[0m\n");
						break;
				}
				rewind(fp);
				break;
			}
		} 
		if(i==1)
		{
			printf("工号输入有误，请重新输入");
			scanf("%s",jobnum);
			rewind(fp);
			i=1;
		}
	}
	printf("如果确认删除请输入 1\n");
	printf("如需重新输入请输入 2\n");
	printf("返回上一级请输入 0\n");
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
void manages(char w[],int t) //赵新航
{
	int j,a=1;
	while(a)
	{
		printf("1.添加员工\n");
		printf("2.开除员工\n");
		printf("3.显示所有员工\n");
		printf("4.显示仓库内所有商品\n");
		printf("5.查看商品销售情况\n");
		printf("6.进货\n");
		printf("0.操作结束\n");
		printf("请选择你的操作：");
		scanf("%d",&a);
		while(a!=1&&a!=2&&a!=3&&a!=4&&a!=5&&a!=6)
		{
			if(a==0)
			{
				printf("\033[1;31m即将推出系统！！！\033[0m\n");
				printf("确定退出请按0\n");
				printf("继续工作请按1\n");
				scanf("%d",&j);
				while(j!=0&&j!=1)
				{
					printf("\033[1;31m输入有误!\033[0m\n请重新输入:");
					scanf("%d",&j);
				}
				if(j==0)
				{
					printf("\033[1;34m感谢你的使用！\033[0m");
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
				printf("\033[1;32m输入有误!\033[0m\n请重新输入:");
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
void boss(char w[],int t)//赵新航
{
	int j,a=1;
	while(a)
	{
		printf("1.添加经理\n");
		printf("2.开除经理\n");
		printf("3.显示所有经理\n");
		printf("4.显示所有员工\n");
		printf("5.查看商品销售情况\n");
		printf("6.修改员工信息\n");
		printf("0.操作结束\n");
		printf("请选择你的操作：");
		scanf("%d",&a);
		while(a!=1&&a!=2&&a!=3&a!=4&&a!=5&&a!=6)
		{
			if(a==0)
			{
				printf("\033[1;31m即将推出系统！！！\033[0m\n");
				printf("确定退出请按0\n");
				printf("继续工作请按1\n");
				scanf("%d",&j);
				while(j!=0&&j!=1)
				{
					printf("\033[1;31m输入有误!\033[0m\n请重新输入:");
					scanf("%d",&j);
				}
				if(j==0)
				{
					printf("\033[1;34m感谢你的使用！\033[0m");
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
				printf("\033[1;32m输入有误!\033[0m\n请重新输入:");
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
int main()//赵新航
{
	int i;
	printf("1.客户\n");
	printf("2.员工\n");
	printf("3.经理\n");
	printf("4.老板\n");
	printf("请选择你的身份：");
	scanf("%d",&i);
	getchar();
	while(i!=1&&i!=2&&i!=3&&i!=4)
	{
		printf("\033[31m输入错误!请重新输入:\033[0m");
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
