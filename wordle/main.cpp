#include <bits/stdc++.h>

using namespace std;

ifstream fin("list.in");
ofstream fout("list.out");

string lista[5800],s,s2;
int pr[200],i,Max,j,nr,j2,ok,bun[6],x,gresite[200],util[200],nrutil,t,mark[200],nr2,used[200];
map<int,map<int,int>> m;

int main()
{
for(i=1;i<=5757;i++){
    fin>>lista[i];
}
pr['j'] = 1;
pr['q'] = 2;
pr['x'] = 3;
pr['z'] = 4;
pr['v'] = 5;
pr['w'] = 6;
pr['k'] = 7;
pr['f'] = 8;
pr['e'] = 9;
pr['g'] = 10;
pr['m'] = 11;
pr['p'] = 12;
pr['h'] = 13;
pr['d'] = 14;
pr['y'] = 15;
pr['u'] = 16;
pr['c'] = 17;
pr['n'] = 18;
pr['s'] = 19;
pr['i'] = 20;
pr['l'] = 21;
pr['t'] = 22;
pr['o'] = 23;
pr['r'] = 24;
pr['a'] = 25;
pr['e'] = 26;
t = 0;
while(t <= 5){
Max = 0;
s = '0';
for(i=1;i<=5757;i++){
    nr = 0;
    ok = 0;
    nr2 = 0;
    for(j=0;j<5;j++){
        for(j2=j+1;j2<5;j2++){
            if(lista[i][j] == lista[i][j2]){
                ok = 1;
                break;
            }
        }
        if(gresite[lista[i][j]] == 1){
            ok = 1;
            break;
        }
        if(mark[j] != 0 && mark[j] != lista[i][j]){
            ok = 1;
            break;
        }
        if(m[lista[i][j]][j] == 1){
            ok = 1;
            break;
        }
        if(ok == 1){
            break;
        }
        if(util[lista[i][j]] == 1){
            nr2++;
        }
    }
    if(!ok && nr2 == nrutil){
    for(j=0;j<5;j++){
        nr += pr[lista[i][j]];
    }
    if(nr > Max){
        Max = nr;
        s = lista[i];
    }
    }
}
if(s == "0"){
    break;
}
fout << s << endl;
for(j=0;j<5;j++){
    cin>>x;
    if(x == 0)
        gresite[s[j]] = 1;
    if(x == 2)
        mark[j] = s[j];
    if(x == 1){
        if(!util[s[j]]){
        nrutil++;
        util[s[j]] = 1;
        }
        m[s[j]][j] = 1;
    }
}
t++;
}
while(t <= 5){
Max = 0;
s = '0';
for(i=1;i<=5757;i++){
    nr = 0;
    ok = 0;
    nr2 = 0;
    for(j=0;j<5;j++){
        if(gresite[lista[i][j]] == 1){
            ok = 1;
            break;
        }
        if(mark[j] != 0 && mark[j] != lista[i][j]){
            ok = 1;
            break;
        }
        if(m[lista[i][j]][j] == 1){
            ok = 1;
            break;
        }
        if(ok == 1){
            break;
        }
        if(util[lista[i][j]] == 1 && !used[lista[i][j]]){
            nr2++;
            used[lista[i][j]] = 1;
        }
    }
    for(j=0;j<5;j++){
        used[lista[i][j]] = 0;
    }
    if(!ok && nr2 == nrutil){
    for(j=0;j<5;j++){
        nr += pr[lista[i][j]];
    }
    if(nr > Max && lista[i] != s2){
        Max = nr;
        s = lista[i];
    }
    }
}
fout << s << endl;
s2 = s;
for(j=0;j<5;j++){
    used[s[j]]++;
}
for(j=0;j<5;j++){
    cin>>x;
    if(x == 2)
        mark[j] = s[j];
    if(used[s[j]] == 1 && x == 0)
        gresite[s[j]] = 1;
    if(used[s[j]] == 1 && x == 1){
        if(!util[s[j]]){
        nrutil++;
        util[s[j]] = 1;
        }
        m[s[j]][j] = 1;
    }
}
for(j=0;j<5;j++){
    used[s[j]] = 0;
}
    t++;
}
    return 0;
}
