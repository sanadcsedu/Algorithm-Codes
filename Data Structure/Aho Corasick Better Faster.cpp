#include<bits/stdc++.h>

#define MAX 4000000
#define ch 63
using namespace std;

int AC[MAX][ch], fuck[MAX], freq[MAX], cnt, root;
char big_one[500005], str[50005];
int Book[5005], out[MAX], _hash[505];
queue<int> Q;

int Node()
{
    cnt++;
    for(int i=0 ; i < ch; i++) AC[cnt][i] = 0;
    fuck[cnt] = freq[cnt] = 0;
    return cnt;
}

void get_hash()
{
    int i;
    for(i=0;i<26;i++) _hash[i+'a']= i;
    for(i=0;i<26;i++) _hash[i+'A']= 26+i;
    for(i=0;i<10;i++) _hash[i+'0']= 52+i;
    _hash['-']= 62;
}
void init()
{
    get_hash();
    out[0] = 0;
    cnt = 0;
    root = Node();
}

int _insert()
{
    int j, c, i;
    j = root;
    for(i=0; str[i]; i++)
    {
        c = _hash[str[i]];
        if(!AC[j][c]) AC[j][c] = Node();
        j=AC[j][c];
    }
    return j;
}

void BFS()
{
    int i, j;
    while(!Q.empty()) Q.pop();
    Q.push(root);
    while(!Q.empty())
    {
        j=Q.front();
        Q.pop();
        for(i=0; i<63; i++)
        {
            if(AC[j][i])
            {
                if(j == root) fuck[AC[j][i]] = root;
                else fuck[AC[j][i]] = AC[fuck[j]][i];
                Q.push ( AC[j][i] );
                out[++out[0]] = AC[j][i];
            }
            else
            {
                if(j == root) AC[j][i] = root;
                else AC[j][i] = AC[fuck[j]][i];
            }
        }
    }
}

void Aho_Corasick()
{
    int i, j, c;
    j = root;
    for(i=0; big_one[i] ; i++)
    {
        c = _hash[big_one[i]];
        ++freq[j = AC[j][c]];
    }
}

void count_freq()
{
    for(int i=out[0]; i>0; i--)
    {
        freq[fuck[out[i]]] += freq[out[i]];
    }
}

int main()
{
    int words , n, i;
    scanf("%d", &words);
    init();
    for(i=1; i<=words; i++)
    {
        scanf("%s", str);
        Book[i]=_insert();
    }
    BFS();
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%s", big_one);
        Aho_Corasick();
    }
    count_freq();

    for(i=1; i<= words; i++) printf("%d\n", freq[Book[i]]);

    return 0;
}
