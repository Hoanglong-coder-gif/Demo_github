-#include<iostream>
#include<fstream>
using namespace std;
void swap(int &a, int &b) {
    int tg=a;
    a=b;
    b=tg;
}
void sapxep(int *a, int n) {
    bool ktra;
    for(int i=0;i<n-1;i++)
        if(a[i]<a[i+1]) ktra=true;
        else {
            ktra=false;
            break;
        }
    if(ktra==true) {
        cout<<"\nMang da duoc sap xep.\n";
        return;
    }
    else {
        for(int i=0;i<n-1;i++)
            for(int j=i;j<n;j++)
                if(a[i]>a[j]) swap(a[i],a[j]);
        cout<<"\nMang sau khi sap xep la :";
        for(int i=0;i<n;i++) cout<<" "<<a[i];
    }
}
void chen(int *a,int &n, int x,int k) {
    for(int i=n;i>k;i--) a[i]=a[i-1];
    a[k]=x;
    n++;
}
void chenx(int *a,int &n,int &x) {
    bool ktra=false;
    cout<<"\nNhap x : ";cin>>x;
    for(int i=0;i<n;i++)
    if(a[i]%2==0) {
        chen(a,n,x,i);
        ktra=true;
        break;
    }
    if(ktra) {
    cout<<"Mang sau khi chen la :";
    for(int i=0;i<n;i++) cout<<" "<<a[i];
    }
    else cout<<"Khong co gia tri chan.";
}
void dichuyenchan(int *a, int n) {
    int k=n-1;
    for(int i=0;i<k;i++)
        if(a[i]%2==0) {
            swap(a[i],a[k]);
            k--;
    }
    cout<<"\nMang sau khi di chuyen la :";
    for(int i=0;i<n;i++) cout<<" "<<a[i];
}
int main() {
    ofstream output;
    int n,x;
    cout<<"Nhap n : ";cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++) {
        cout<<"a["<<i<<"] = ";cin>>*(a+i);
    }
    output.open("ABC2011.txt");
    cout<<"Mang vua nhap la :";
    for(int i=0;i<n;i++) {
        cout<<" "<<a[i];
        output<<" "<<a[i];
    }
    output.close();
    sapxep(a,n);
    int *resize = a;
    a=new int[n+1];
    for (int i = 0; i < n; i++) {
        a[i] = resize[i];
    }
    delete[] resize;
    chenx(a,n,x);
    dichuyenchan(a,n);
    delete[] a;
}
