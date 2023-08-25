#include <iostream>
#include <algorithm>

using namespace std;

void noBMIChange(int w0, int i0, int i, int d, int a){
    int w_nd(w0+(i-(i0+a))*d), b_nd(i0);
    if(w_nd<=0 || b_nd<=0){
        cout<<"Danger Diet"<<endl;
    }
    else{
        cout<<w_nd<<' '<<b_nd<<endl;
    }
}

void BMIChange(int w0, int i0, int t, int i, int d, int a){
    string is_yoyo("NO");
    int w(w0), b(i0);

    for(int k = 0; k<d;k++){
        w+=i-(b+a);
        if(-(i-(b+a))>t)
            b+=int((i-(b+a))/2);
        
        if(w<=0 || b<=0){
         is_yoyo = "Danger Diet";
         break;
        }
    }

    if(is_yoyo == "Danger Diet"){
        cout<<is_yoyo<<endl;
    }
    else{
        if(i0>b)
            is_yoyo = "YOYO";
        cout<<w<<' '<<b<<' '<<is_yoyo;
    }
}

int main(){
    int w0(0), i0(0), t(0);
    int d(0), i(0), a(0);
    

    cin>> w0 >>i0>>t;
    cin>>d>>i>>a;

    noBMIChange(w0, i0, i, d, a);
    BMIChange(w0, i0, t, i, d, a);

}