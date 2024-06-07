#include<iostream>

using namespace std;

void multiply(int** a, int** b, const int &na, const int &ma, const int &nb, const int &mb)
{
    int** c = new int*[na];
    for(int i = 0 ; i < mb ; i++)
    {
        c[i] = new int[mb];
    }
    int sum = 0;
    for(int k = 0 ; k < na ; k++)
    {
        for(int i = 0 ; i < mb ; i++)
        {
            sum = 0;
            for(int j = 0 ; j < ma ; j++)
            {
                sum += (a[k][j]) * (b[j][i]);
            }
            c[k][i] = sum;
        }
    }

    for(int i = 0 ; i < na ; i++)
    {
        for(int j = 0 ; j < mb ; j++)
        {
            cout<<c[i][j]<<"  ";
        }
        cout<<endl;
    }

    for(int i = 0 ; i < na ; i++)
    {
        delete[] c[i];
    }
    delete[] c;
}

int main()
{
    int n1, m1, n2, m2;
    while(1)
    {
        cout<<"enter dim of mat A: ";
        cin>>n1>>m1;
        cout<<"enter dim of mat B: ";
        cin>>n2>>m2;
        if(m1 != n2)
        {
            cout<<"Product doesn't exist, enter again\n";
        }
        else
        {
            break;
        }
    }

    const int na = n1; const int nb = n2; const int ma = m1; const int mb = m2;

    int **a = new int*[na]; int **b = new int*[nb];
    for(int i = 0 ; i < na ; i++)
    {
        a[i] = new int[ma];
    }

    for(int i = 0 ; i < nb ; i++)
    {
        b[i] = new int[mb];
    }

    cout << "Enter elements of matrix A:\n";
    for (int i = 0; i < na; i++) {
        for (int j = 0; j < ma; j++) {
            cin >> a[i][j];
        }
    }
    cout << "Enter elements of matrix B:\n";
    for (int i = 0; i < nb; i++) {
        for (int j = 0; j < mb; j++) {
            cin >> b[i][j];
        }
    }
    multiply(a, b, na, ma, nb, mb);
    for(int i = 0 ; i < na ; i++)
    {
        delete[] a[i];
    }
    delete[] a;

    for(int i = 0 ; i < nb ; i++)
    {
        delete[] b[i];
    }
    delete[] b;
}
