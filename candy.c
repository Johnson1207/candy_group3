#include "function_header.h"
#include "struct.h"

int **change(int r, int c, int **mat, int **emp, int **fun)
{
    int **a=create_matrix2(r,c);
    int x1=0, y1=0, x2=0, y2=0;
    int xxx=0,yyy=0;
    int b;

    mouse(&x1,&y1);
    mouse(&x2,&y2);

    if( (x1==x2 && (y1-y2==1 || y2-y1==1)) || (y1==y2 && (x1-x2==1 ||x2-x1==1)))
    {
        a[y1][x1] = mat[y1][x1];
        mat[y1][x1] = mat[y2][x2];
        mat[y2][x2] = a[y1][x1];

        a[y1][x1] = fun[y1][x1];
        fun[y1][x1] = fun[y2][x2];
        fun[y2][x2] = a[y1][x1];

        check(r, c, mat, emp, fun);
        b=break_point(r, c, emp);
        initialize_mat2D(emp, r, c);

        if(b==0)
        {
            printf("\nerror\n\n");

            a[y1][x1] = mat[y1][x1];
            mat[y1][x1] = mat[y2][x2];
            mat[y2][x2] = a[y1][x1];

            a[y1][x1] = fun[y1][x1];
            fun[y1][x1] = fun[y2][x2];
            fun[y2][x2] = a[y1][x1];

            change(r, c, mat, emp, fun);
        }
    }
    else
    {
        printf("\nerror\n\n");
        change(r, c, mat, emp, fun);
    }


    return mat;
}

int **check(int r, int c, int **body, int **emp, int **fun)
{
    int j,k;
    int type;
    for(k=0; k<r; k++)
    {
        for(j=0; j<c-2; j++)
        {
            if (  (body[k][j]== body[k][j+1])  &&  (body[k][j+1]==body[k][j+2])  )/*check in row*/
            {
                if(body[k][j+2]==body[k][j+3])
                {
                    if(body[k][j+3]==body[k][j+4])
                    {
                        emp[k][j]=1;
                        emp[k][j+1]=1;
                        emp[k][j+2]=1;
                        emp[k][j+3]=1;
                        emp[k][j+4]=1;
                        fun[k][j+2]=4;
                    }
                    emp[k][j]=1;
                    emp[k][j+1]=1;
                    emp[k][j+2]=1;
                    emp[k][j+3]=1;
                    check_fun(r,c,emp,fun,k,j);
                    check_fun(r,c,emp,fun,k,j+1);
                    check_fun(r,c,emp,fun,k,j+2);
                    check_fun(r,c,emp,fun,k,j+3);
                    fun[k][j+1]=1;
                }
                else
                {
                    emp[k][j]=1;
                    emp[k][j+1]=1;
                    emp[k][j+2]=1;
                    check_fun(r,c,emp,fun,k,j);
                    check_fun(r,c,emp,fun,k,j+1);
                    check_fun(r,c,emp,fun,k,j+2);
                    fun[k][j]=5;
                    fun[k][j+1]=5;
                    fun[k][j+2]=5;
                }

            }

        }

        for(j=0; j<r-2; j++)
        {
            if (  (body[j][k]==body[j+1][k]) && (body[j+1][k]==body[j+2][k])   )
            {
                if(body[j+2][k]==body[j+3][k])
                {
                    emp[j][k]=1;
                    emp[j+1][k]=1;
                    emp[j+2][k]=1;
                    emp[j+3][k]=1;
                    fun[j+1][k]=2;
                }
                else if(fun[j][k]==5)
                {
                    emp[j][k]=1;
                    emp[j+1][k]=1;
                    emp[j+2][k]=1;
                    fun[j][k]=3;
                }
                else if(fun[j+1][k]==5)
                {
                    emp[j][k]=1;
                    emp[j+1][k]=1;
                    emp[j+2][k]=1;
                    fun[j+1][k]=3;
                }
                else if(fun[j+2][k]==5)
                {
                    emp[j][k]=1;
                    emp[j+1][k]=1;
                    emp[j+2][k]=1;
                    fun[j+2][k]=3;
                }
                else
                {
                    emp[j][k]=1;
                    emp[j+1][k]=1;
                    emp[j+2][k]=1;
                }

            }

        }

    }
    return emp;
}

int **check_fun(int r,int c,int **emp,int **fun,int k,int j)
{
    int a,b;
    if(fun[k][j] == 1)/*row_strip*/
    {
        fun[k][j]=0;
        for(a=0; a<r; a++)
        {
            emp[k][a]=1;
            check_fun(r,c,emp,fun,k,a);
        }
    }
    if(fun[k][j] == 2)/*col_strip*/
    {
        fun[k][j]=0;
        for(a=0; a<r; a++)
        {
            emp[a][j]=1;
            check_fun(r,c,emp,fun,a,j);
        }
    }
    if(fun[k][j] == 3)/*wrap*/
    {
        fun[k][j]=0;
        emp[k][j]=1;
        check_fun(r,c,emp,fun,k,j);

        if( (k-1>=0) && (j-1>=0))
        {
            emp[k-1][j-1]=1;
            check_fun(r,c,emp,fun,k-1,j-1);
        }
        if( (k-1>=0) && (j+1<=c))
        {
            emp[k-1][j+1]=1;
            check_fun(r,c,emp,fun,k-1,j-1);
        }
        if( (k+1<=r) && (j+1<=c))
        {
            emp[k+1][j+1]=1;
            check_fun(r,c,emp,fun,k+1,j+1);
        }
        if( (k+1<=r) && (j-1>=0))
        {
            emp[k+1][j-1]=1;
            check_fun(r,c,emp,fun,k+1,j-1);
        }
        if(j-1>=0)
        {
            emp[k][j-1]=1;
            check_fun(r,c,emp,fun,k,j-1);
        }
        if(k-1>=0)
        {
            emp[k-1][j]=1;
            check_fun(r,c,emp,fun,k-1,j);
        }
        if(j+1<=c)
        {
            emp[k][j+1]=1;
            check_fun(r,c,emp,fun,k,j+1);
        }
        if(k+1<=r)
        {
            emp[k+1][j]=1;
            check_fun(r,c,emp,fun,k+1,j);
        }
    }
    return emp;
}

int **clear(int r, int c, int **body, int **emp)
{
    int i,j;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if(emp[i][j]==1)
            {
                body[i][j]=0;
            }
        }
    }
    return body;
}

int **refill(int r, int c, int **body, int **fun)
{
    int i,j;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if(  body[i][j]==0  )
            {
                for(i=i; i>0; i--)
                {
                    body[i][j]=body[i-1][j];
                    fun[i][j]=fun[i-1][j];
                }
                body[i][j]=rand()%4+1;
                fun[i][j]=0;
            }
        }
    }
    return body;
}

int score(int r, int c, int score, int **emp)
{
    int i,j;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if(emp[i][j]==1)
            {
                score+=10;
            }
        }
    }

    return score ;
}

int break_point(int r, int c, int **emp)
{

    int i, j, b=0;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if(emp[i][j]==1)
            {
                b+=1;
            }
        }
    }

    return b ;
}

