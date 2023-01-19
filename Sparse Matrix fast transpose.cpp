#include<iostream>
#include<string>
#include<iomanip>
#include <cstdlib>
#include<cmath>

using namespace std;

int main()
{
    int row,col;

    while(cin >> row >> col)//利用無窮迴圈來輸入
    {

        if(row == 0 && col == 0)//當row和col為0時，就跳出迴圈結束程式
        {
            break;
        }

        int i=0,j=0,v=0,r=0,c=0,cot=0,a=0,y=0,x=0,z=0,w,q=0,cn=0,vc=0,num=0,pov=0;//參數


        int mtx[row][col];

        int r_value[100];

        int c_value[100];

        int v_value[100];

        int trans_c[100];

        int trans_r[100];

        int trans_v[100];

        int trans_table[cot][3];

        int fina_mtx[cot][3];

        int tmp[1][3];

        int term[row];

        int pos[row];


        //建立矩陣
        if( (0 >= row || row >= 21) || (0 >= col || col >= 21))//有效範圍是1~20
        {
            break;
        }

        if( (0 < row && row <= 20) && (0 < col && col <= 20))//輸入一個row*col的矩陣
        {
           for( i=0 ; i < row ; i++)
           {
               for( j=0 ; j < col ; j++)
               {
                   cin >> mtx[i][j];
               }
           }
        }


        //轉置之前的矩陣表
        for( int k=0 ; k < col ; k++)//col為主
        {
            for( int g=0 ; g < row ; g++)
            {
                if(mtx[g][k] != 0)//把不是0的值存入矩陣表裡面
                {
                    v_value[v]=mtx[g][k];
                    v=v+1;

                    r_value[r]=g;
                    r=r+1;

                    c_value[c]=k;
                    c=c+1;

                    cot=cot+1;
                }
            }
        }


        //再把矩陣圖印出來
        cout << "row" << '\t' << "col" << '\t' << "val" << endl;

        while(a < cot)
        {
            cout << r_value[a] << '\t' << c_value[a] << '\t' << v_value[a] << endl;
            a=a+1;
        }
        cout << endl;


         //建立column term
         while(cn < 21)//因為最大為20，所以要檢查到20
         {
             vc=0;

             for(int gk=0 ; gk < cot ; gk++ )
             {
                if( r_value[gk] == cn)//從1比到20有多少次數，存入term裡面
                {
                     vc=vc+1;
                }
             }

             term[num]=vc;

             num=num+1;

             cn=cn+1;
         }


         //印出column term
         cout << "col term :" << '\t';

         for(int fk=0 ; fk < row ; fk++)
         {
              cout << term[fk] << ' ';
         }
         cout << endl ;


         //建立starting pos
         cout << "start pos :" << '\t';

         for(int gj=0 ; gj < row ; gj++)
         {
             pos[gj]=pov;//starting pos的一開始一定為0

             pov=term[gj]+pov;//starting pos的值+column term的值就等於接下來的starting pos的值
         }


         //印出starting pos
         for(int fg=0 ; fg < row ; fg++)
         {
              cout << pos[fg] << ' ';
         }
         cout << endl  << endl;


        //轉置之後的矩陣表

        for(int b=0 ; b < cot ; b++)//row和col互換
        {
            trans_c[b]=r_value[b];

            trans_r[b]=c_value[b];

            trans_v[b]=v_value[b];

        }

        //把轉置之後的矩陣表存成2維矩陣

        for(int x=0 ; x < cot ; x++)
        {
            trans_table[x][y]=trans_r[x];
            y=y+1;

            trans_table[x][y]=trans_c[x];
            y=y+1;

            trans_table[x][y]=trans_v[x];
            y=0;
        }

        //印出轉置後的矩陣
        /*
        for(int d=0 ; d < cot ; d++)
        {
            for(int u=0 ; u < 3 ; u++)
            {
                cout << trans_table[d][u];

                if(u==2)
                {
                    cout << endl;
                }
            }
        }
        */


        //印出轉置後的矩陣的col
        /*
        for(int d=0 ; d < cot ; d++)
        {
            cout << trans_table[d][1] << endl;
        }
        */


        //轉成最後的矩陣表(排序col的大小來存)

        for(int z=0 ; z < cot ; z++)
        {
            for(int w=z+1 ; w < cot ; w++)
            {
                if(trans_table[z][1] > trans_table[w][1])//排序col，當後面的col比前面的col小就互換
                {
                    tmp[0][0]=trans_table[z][0];
                    tmp[0][1]=trans_table[z][1];
                    tmp[0][2]=trans_table[z][2];

                    trans_table[z][0]=trans_table[w][0];
                    trans_table[z][1]=trans_table[w][1];
                    trans_table[z][2]=trans_table[w][2];

                    trans_table[w][0]=tmp[0][0];
                    trans_table[w][1]=tmp[0][1];
                    trans_table[w][2]=tmp[0][2];
                }
            }
        }

        //其他狀況:如果col一樣大，就比row，誰比較小就排前面
        for(int q=0 ; q < cot ; q++)
        {
            for(int f=q+1 ; f < cot ; f++)
            {
                if(trans_table[q][1] == trans_table[f][1])
                {
                    if(trans_table[q][0] > trans_table[f][0])
                    {

                        tmp[0][0]=trans_table[q][0];
                        tmp[0][1]=trans_table[q][1];
                        tmp[0][2]=trans_table[q][2];

                        trans_table[q][0]=trans_table[f][0];
                        trans_table[q][1]=trans_table[f][1];
                        trans_table[q][2]=trans_table[f][2];

                        trans_table[f][0]=tmp[0][0];
                        trans_table[f][1]=tmp[0][1];
                        trans_table[f][2]=tmp[0][2];

                    }
                }
            }
        }

        //印出轉至後的矩陣表

        cout << "row" << '\t' << "col" << '\t' << "val" << endl;

        for(int v=0 ; v < cot ; v++)
        {
            for(int ab=0 ; ab < 3 ; ab++)
            {
                cout << trans_table[v][ab] << '\t';

                if (ab == 2)
                {
                    cout << endl;
                }
            }
        }
        cout << endl;

    }

}


