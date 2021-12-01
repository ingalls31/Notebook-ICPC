
                   
 
        

  Team Notebook	
Contents:



1.DP BITMASK………………………………………………………….2
2.Số học…………………………………………………………………..2
3.Matrix…………………………………………………………………..2
4.Fenwick Tree…………………………………………………………3
5.DSU………………………………………………………………………3
6.Stack…………………………………………………………………….4
7.Big Number…………………………………………………………..4
8.Dijkstra…………………………………………………………………5
9.Floyd…………………………………………………………………….5
10.Hash…………………………………………………………………..6
11.Một số bài quy hoạch động………………………………..6
 


DP BITMASK
const int N=2000000;
int n;
int a[25][25];
int F[N];
void solve(){
    int last=(1<<n)-1;
    memset(F,0,sizeof(F));
    for(int s=0;s<=last;s++){
        int cnt=0;
        for(int i=1;i<=n;i++)if(s>>(i-1)&1)cnt++;
        for(int i=1;i<=n;i++){
            if(s>>(i-1)&1){
                int p=s xor (1<<(i-1));
                F[s]=max(F[s],F[p]+a[cnt][i]);
            }
        }
    }
    cout<<F[last]<<endl;
}
//hanhtrinhdulich
void solve(){
    reset();
    queue<ii>q;
    q.push({0,0});
    check[0][0]=1;
    dp[0][0]=0;
    while(!q.empty()){
        ii u=q.front(); q.pop();
        for(int i=1;i<=n;i++){
            int k=1<<(i-1);
            if((u.fi&k)==0){
                x=u.fi^k;
                dp[x][i]=min(dp[x][i],dp[u.fi][u.se]+a[u.se][i]);
                if(check[x][i]==0){
                    check[x][i]=1;
                    q.push({x,i});
                }
            }
        }
    }
    int ans =*min_element(dp[last]+1,dp[last]+n+1);
    cout<<ans<<endl;
}










SỐ HỌC :
//Sang era
vector<bool> a(1e6+5,1);
v e;
void era(){
    for(int i=2;i<=1000000;i++){
        if(a[i]){
            e.push_back(i);
            for(int j=i*i;j<=1000000;j+=i)a[j]=0;
        }
    }
}
//tong uoc cua n
 


// dinhli Euler
 
 
 FENWICK TREE:
const int N=1e5+5;
int bit[N];
void update(int i,int k){
    for(;i<N;i+=i&-i)bit[i]+=k;
}
int get(int i){
    int ans=0;
    for(;i;i-=i&-i)ans+=bit[i];
    return ans;
}

 

//bo ba so thu tu nguoc
//đếm số bộ ba a[i]>a[j]>ak] với i < j < k.
int solve(int a[]){
    int right[n+1];
    int left[n+1];
    for(int i=n-1;i>=0;i--){
        right[i]=get(a[i]-1);
        update(a[i]);
    }
    for(int i=0;i<=n;i++)bit[i]=0;
    for(int i=0;i<n;i++){
        left[i]=i-get(a[i]);
        update(a[i]);
    }
    int res=0;

    for(int i=0;i<n;i++){
        res+=left[i]*right[i];
    }
    return res;
}
  
  

STACK: 

// trung to - hau to 
int degree(char c){
    if(c=='^')return 5;
    if(c=='*'||c=='/')return 4;
    if(c=='+'||c=='-')return 3;
    return 2;
}
bool check(char c){
    return ((c>='a'&&c<='z')||(c>='A'&&c<='Z'));
}
string convert(string s){
    string res="";
    stack<char> st;
    for(int i=0;i<s.size();i++){
        if(check(s[i]))res+=s[i];
        else if(s[i]=='(')st.push(s[i]);
        else if(s[i]==')'){
            while(!st.empty()&&st.top()!='('){
                res+=st.top();
                st.pop();
            }
            st.pop();
        }
        else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^'){
            while(!st.empty()&&degree(st.top())>=degree(s[i])){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        if(st.top()!='(')res+=st.top();
        st.pop();
    }
    return res;
}
 




Dijkstra:
int n,m,start;
vector<ii> a[1005];
int d[1005];
bool check[1005];
struct cmp{
    bool operator()(ii x,ii y){
        return x.fi>=y.fi;
    }
};
void dijkstra(int u){
    for(int i=1;i<=n;i++)d[i]=1e9;
    d[u]=0;
    priority_queue<ii,vector<ii>,cmp>q;
    q.push({0,u});
    while(!q.empty()){
        int k=q.top().se; q.pop();
        for(auto x:a[k]){
            int s=x.se;
            int d_k_s=x.fi;
            if(d[k]+d_k_s<d[s]){
                d[s]=d[k]+d_k_s;
                q.push({d[s],s});
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<d[i]<<" ";
    cout<<endl;
}
 



Floyd:

int a[105][105];
int n,m,q;
void floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i][j]>a[i][k]+a[k][j]){
                    a[i][j]=a[i][k]+a[k][j];
                }
            }
        }
    }
}
 

Hash:
//Cho xâu A và xâu B chỉ gồm các chữ cái thường.Hãy tìm tất cả các vị trí mà A xuất hiện trong B.
const int N=1000111;
const int p=1000000003;
string T,P;
int Pow[N],Hash[N];
int n,m;
void set_pow(){
    Pow[0]=1;
    for(int i=1;i<=m;i++)
        Pow[i]=(Pow[i-1]*26)%p;
}
void set_hash(){
    for(int i=1;i<=m;i++)
        Hash[i]=(Hash[i-1]*26+ T[i]-'a')%p;
}
int get_hash(int i,int j){
    return (Hash[j]-Hash[i-1]*Pow[j-i+1]+p*p)%p;
}
void solution(){
    cin>>T>>P;
    m=T.size(),n=P.size();
    T=" "+T;  P=" "+P;
    set_pow();    set_hash();
    int hash_p=0;
    for(int i=1;i<=n;i++)
        hash_p=(hash_p*26+ P[i]-'a')%p;
    for(int i=1;i<=m-n+1;i++){
        if(hash_p==get_hash(i,i+n-1))cout<<i<<" ";
    }
}
	MATRIX:
const int p=1e9+7;
struct matrix{
    int d[3][3];
};
matrix tich(matrix a,matrix b){
    matrix ans;
    for(int i=1;i<3;i++){
        for(int j=1;j<3;j++){
            int s=0;
            for(int k=1;k<3;k++){
                s=(s%p+a.d[i][k]*b.d[k][j]%p)%p;
            }
            ans.d[i][j]=s;
        }
    }
    return ans;
}
matrix pow(matrix a,int p){
    if(p==1)return a;
    matrix ans=pow(a,p/2);
    ans=tich(ans,ans);
    if(p%2==1)ans=tich(ans,a);
    return ans;
}
const int p=1e9+7;
struct matrix{
    int d[3][3];
};
//fibonanci

 
//luỵthuamatran
 





matrix luythua(matrix a,int k){
    if(k==1)return a;
    matrix a1=dv(a,k/2);
    matrix a2=luythua(a,k/2);
    matrix ans=tich(a1,a2);
    if(k%2==1){
        matrix b=pow(a,k);
        ans=tong(ans,b);
    }
    return ans;
}
//Tribonanci
 
  
  
  
  
DSU:

const int N=1e5+5;
int parent[N] ,rank[N];
int find(int i){
    if(parent[i]==-1)return i;
    parent[i]=find(parent[i]);
    return parent[i];
}
void Union(int x,int y){
    int p_x=find(x);
    int p_y=find(y);
    if(p_x!=p_y)parent[p_x]=p_y;
}
 


//Union vs rank
void Union(int u,int v){
    u=find(u);
    v=find(v);
    if(u==v)return ;
    if(rank[u]==rank[v])rank[u]++;
    if(rank[u]>rank[v])parent[v]=u;
    else parent[u]=v;
}
  
 
Big Number:
struct Big{
    int neg=0;
    vector<int> num;
    Big(){
        neg=0;
        num.push_back(0);
    }
    Big(string x){
        if(x[0]=='-'){
            neg=1;
            x.erase(x.begin());
        }
        else neg=0;
        num.assign(x.size(),0);
        for(int i=0;i<x.size();i++)num[i]=x[x.size()-1-i]-'0';
    }
    void fix(){
        num.push_back(0);
        num.push_back(0);
        for(int i=0;i<num.size()-1;i++)
        {
            num[i+1]+=num[i]/10;
            num[i]%=10;
            if(num[i]<0)
            {
                num[i]+=10;
                num[i+1]-=1;
            }
        }
        while(num.size()>1&&num.back()==0)num.pop_back();
    }
    bool operator > ( Big a){
        this->fix();
        a.fix();
        if(this->num.size()==a.num.size()){
            for(int i=num.size()-1;i>=0;i--)if(num[i]!=a.num[i])return num[i]>a.num[i];
            return false;
        }
        return this->num.size()>a.num.size();
 
    }
    bool operator ==(const Big &a){
        return (a.num==num);
    }
    Big operator + (const Big &a){
        Big kq;
        kq.num.assign(max(this->num.size(),a.num.size()),0);
        for(int i=0;i<kq.num.size();i++){
            if(i<this->num.size())kq.num[i]+=this->num[i];
            if(i<a.num.size())kq.num[i]+=a.num[i];
        }
        kq.fix();
        return kq;
    }
    Big operator - (const Big &a){
        Big kq;
        kq.num.assign(max(this->num.size(),a.num.size())+5,0);
        if(this->neg!=a.neg){
            kq=*this+a;
            kq.neg=this->neg;
            return kq;
        }
        if(this->neg){
            if(*this>a){
 
                kq.neg=1;
                for(int i=0;i<kq.num.size();i++){
                    if(i<this->num.size())kq.num[i]+=this->num[i];
                    if(i<a.num.size())kq.num[i]-=a.num[i];
                }
                kq.fix();
                return kq;
            }
            else
            {
                for(int i=0;i<kq.num.size();i++){
                    if(i<this->num.size())kq.num[i]-=this->num[i];
                    if(i<a.num.size())kq.num[i]+=a.num[i];
                }
                kq.fix();
                return kq;
            }
        }
        else{
            if(*this>a){
                for(int i=0;i<kq.num.size();i++){
                    if(i<this->num.size())kq.num[i]+=this->num[i];
                    if(i<a.num.size())kq.num[i]-=a.num[i];
                }
                kq.fix();
                return kq;
            }
            else
            {
                // 2-4
                kq.neg=1;
                for(int i=0;i<kq.num.size();i++){
                    if(i<this->num.size())kq.num[i]-=this->num[i];
                    if(i<a.num.size())kq.num[i]+=a.num[i];
                }
                kq.fix();
                return kq;
            }
        }
    }
    Big operator * (const Big a){
        Big kq;
        kq.num.assign(a.num.size()*this->num.size(),0);
        for(int i=0;i<num.size();i++){
            for(int j=0;j<a.num.size();j++){
                kq.num[i+j]+=num[i]*a.num[j];
            }
        }
        kq.fix();
        return kq;
    }
    void print(){
        for(int i=num.size()-1;i>=0;i--)cout<<num[i];cout<<endl;
    }
    Big operator / ( Big a){
        int negva=(this->neg!=a.neg);
        if(a>*this){
            return Big();
        }
        string res="";
        Big cur("0");
        cur.num.clear();
        for(int i=num.size()-1;i>=0;i--){
            cur.neg=0;
            cur.num.insert(cur.num.begin(),num[i]);
            int tmp=1;
            for(int k=1;k<=10;k++){
                if(a*Big(to_string(k))>cur){
 
                    tmp=k;
                    break;
                }
            }
            tmp-=1;
 
            cur=cur-a*Big(to_string(tmp));
            res=res+char(tmp+'0');
        }
        Big kq=Big(res);
        kq.fix();
        kq.neg=negva;
        return kq;
    }
 
};

Một số bài quy hoạch động:
//hinh vuong lon nhat
int n,m;
int a[n+1][m+1],dp[n+1][m+1];
int solve(){
    int ans=0;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j],dp[i][j]=a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==0)continue;
            if(a[i][j]==a[i-1][j-1]&&a[i][j]==a[i-1][j]&&a[i][j]==a[i][j-1]){
                dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
            }
            ans=max(ans,dp[i][j]);
        } 
    }
    return ans;
}
//C(n,k)
int nCr[1003][1003] = {0};
void preprocess(){
    int k;
    for(int i=0;i<1003;i++){
        nCr[i][0] = nCr[i][i] = 1;
        k = i >> 1;
        for(int j=1;j<=k;j++){
            nCr[i][j] = nCr[i][i-j] = (nCr[i - 1][j] + nCr[i - 1][j - 1]) % MOD;
        }
    }
}
// xau con chung dai nhat
int dp[1001][1001];
int solve(string a,string b){
    int n=a.size(),m=b.size();
    for(int i=0;i<=n;i++)dp[i][0]=0;
    for(int i=0;i<=m;i++)dp[0][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else 
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}

//Truy vet xau con chung
string xcc(string a,string b){
    string res="";
    int n=a.size(),m=b.size();
    bool check[n];
    memset(check,0,sizeof(check));
    int i=n, j = m;
    while (i > 0 && j > 0){
        if (a[i - 1] == b[j - 1]){
            check[i - 1] = 1;
            i--;  j--;
        }
        else{
            if (dp[i][j] == dp[i - 1][j])i--;
            else j--;
        }
    }
    //
    for (int i = 0; i < n; i++){
        if (check[i] == 1)res+=a[i];
    }
    return res;
}
//Tìm số N nhỏ nhất thỏa mãn: A là tổng các chữ số của N, B là tổng bình phương các chữ số của N. 
int dp[101][10001];
int mind(int a,int b){
    if(a<0||b<0||a>100||b>10001)return -1;
    if(a==0&&b==0)return 0;
    if(dp[a][b]!=-1)return dp[a][b];
    int ans=101;
    for(int i=9;i>=1;i--){
        int k=mind(a-i,b-i*i);
        if(k!=-1)ans=min(ans,k+1);
    }
    return dp[a][b]=ans;
}
void print(int a,int b){
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    int k=mind(a,b);
    if(k==-1||k>100)cout<<-1;
    else {
        while(a>0&&b>0){
            for(int i=1;i<=9;i++){
                if(a>=i&&b>=i*i&&dp[a][b]==dp[a-i][b-i*i]+1){
                    cout<<i;
                    a-=i;
                    b-=i*i;
                    break;
                }
            }
        }
    }
}
//cai tui ban kho
const int N=1e5+5;
int dp[N];
int w[101],v[101];
int n,W;
int solve(){
    for(int i=0;i<N;i++)dp[i]=1e18;
    dp[0]=0;
    for(int i=0;i<n;i++){
        for(int j=N-1;j>=0;j--){
            if(dp[j]+w[i]<=W){
                dp[j+v[i]]=min(dp[j+v[i]],dp[j]+w[i]);
            }
        }
    }
    for(int i=N-1;i>=0;i--){
        if(dp[i]!=1e18)return i;
    }
    return 0;
}
//Loại bỏ phần tử đầu tiên hoặc cuối cùng của dãy . Người chơi đó sẽ kiếm được  điểm, với  là phần tử bị loại bỏ.
//Cho x và y lần lượt là số điểm của Taro và Jiro sau khi trò chơi kết thúc. Taro muốn x-y lớn nhất có thể, trong Jiro lại muốn làm x-y bé nhất có thể.
int dp[1000][1000];
int solve(v a){
    for(int i=0;i<n;i++)dp[i][i]=a[i];
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++){
            dp[i][j]=max( a[i]-dp[i+1][j] , a[j]-dp[i][j-1] );
        }
    }
    return dp[0][n-1];
}


