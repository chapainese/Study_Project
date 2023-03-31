#include<bits/stdc++.h>
//行标和顺序。 
using namespace std;
int row=0;	int col=0;
char mp[6][6]={'0'};//录入大小不可移植 
string p[6][6];

int num=0;
int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};//左上右下 
//devc++调试信息不可以包括stl,否则bug 
void dfs(int y,int x)
{	
	//终止条件 
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
		
	if((nx<0||nx>=col)||(ny<0||ny>=row)||(mp[ny][nx]=='#'))//防止越界或者撞墙 
	{
		continue;//寄了之后未处理 
	}
	//if(mp[ny][nx]=='.')//要加判断条件 
	//把终止条件写外面，此处应包含.和*两种情况，否则会找不到* 
	
	mp[y][x]='#';//记忆 上一次 （用记忆本次也不合适，会让终点变成#） 
	char t[4];
	sprintf(t,"%d%d",nx,ny);
	//将每次都打印的话重复路线未处理 
	p[ny][nx]=p[y][x]+"->"+t;//存储新路径 
	//c++支持字符串拼接 
	dfs(ny,nx);
	mp[y][x]='.';//恢复 
	
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
			//按yhang xlie输入 
			 mp[y][x]=' ';//初始化
			 cin>>mp[y][x];
			// scanf("%c",&mp[i][j]) ;//?
			 if(mp[y][x]=='@')//读起点 
			 {
			 	sx=x;
			 	sy=y;
			 }
			 if(mp[y][x]=='*')//读终点 
			 {
			 	tx=x;
			 	ty=y;
			 }
		}
	}
	
	//printf("from%c%c to%c%c",sx,sy,tx,ty);
	//路径问题 
	cout<<"from"<<sx<<sy<<"to"<<tx<<ty<<"\n";//打印标题（始末位置） 
	char t[4];
	sprintf(t,"%d%d",sx,sy);//将坐标转换为字符串记录初始路径 
	 p[sy][sx]=t;//t是字符串类型，而p原是字符类型:error 
	 dfs(sy,sx);//搜索打印下一个路径 
	printf("%d",num);
	return 0;
}
