#include<bits/stdc++.h>
//�б��˳�� 
using namespace std;
int row=0;	int col=0;
char mp[6][6]={'0'};//¼���С������ֲ 
string p[6][6];

int num=0;
int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};//�������� 
//devc++������Ϣ�����԰���stl,����bug 
void dfs(int y,int x)
{	
	//��ֹ���� 
	if(mp[y][x]=='*')
	{	
		char t[4];
		sprintf(t,"%d%d",x,y);
		cout<<p[y][x];
		printf("\n");
		num++;
		return;//
		
	}
	int nx,ny;
	for(int i=0;i<4;i++)
	{
		nx=x+dir[i][0];ny=y+dir[i][1];// move
		
	if((nx<0||nx>=col)||(ny<0||ny>=row)||(mp[ny][nx]=='#'))//��ֹԽ�����ײǽ 
	{
		continue;//����֮��δ���� 
	}
	//if(mp[ny][nx]=='.')//Ҫ���ж����� 
	//����ֹ����д���棬�˴�Ӧ����.��*���������������Ҳ���* 
	
	mp[y][x]='#';//���� ��һ�� ���ü��䱾��Ҳ�����ʣ������յ���#�� 
	char t[4];
	sprintf(t,"%d%d",nx,ny);
	//��ÿ�ζ���ӡ�Ļ��ظ�·��δ���� 
	p[ny][nx]=p[y][x]+"->"+t;//�洢��·�� 
	//c++֧���ַ���ƴ�� 
	dfs(ny,nx);
	mp[y][x]='.';//�ָ� 
	
}
}
int main()
{

	int sx=0;
	int sy=0;
	int tx=0;
	int ty=0;
	scanf("%d",&row);
	scanf("%d",&col);
	for(int y=0;y<row;y++)
	{
		for(int x=0;x<col;x++)
		{
			//��yhang xlie���� 
			 mp[y][x]=' ';//��ʼ��
			 cin>>mp[y][x];
			// scanf("%c",&mp[i][j]) ;//?
			 if(mp[y][x]=='@')//����� 
			 {
			 	sx=x;
			 	sy=y;
			 }
			 if(mp[y][x]=='*')//���յ� 
			 {
			 	tx=x;
			 	ty=y;
			 }
		}
	}
	
	//printf("from%c%c to%c%c",sx,sy,tx,ty);
	//·������ 
	cout<<"from"<<sx<<sy<<"to"<<tx<<ty<<"\n";//��ӡ���⣨ʼĩλ�ã� 
	char t[4];
	sprintf(t,"%d%d",sx,sy);//������ת��Ϊ�ַ�����¼��ʼ·�� 
	 p[sy][sx]=t;//t���ַ������ͣ���pԭ���ַ�����:error 
	 dfs(sy,sx);//������ӡ��һ��·�� 
	printf("%d",num);
	return 0;
}
