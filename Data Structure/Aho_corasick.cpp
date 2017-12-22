#include<bits/stdc++.h>

using namespace std;

#define ch 26
#define MAX 500005

vector<int> E[500005];

int freq[MAX];
char ss[1000010];
char st[MAX];
int hash[MAX];

struct data
{
    int link[ch];
    int fail, f;
    void Set()
    {
        memset(link , 0, sizeof(link));
        fail = f = 0;
    }
};
data trie[500005];
int cnt,root;
int _hash[300];

void get_hash()
{
    for(int i=0;i<26;i++) _hash[i+'a']= i;
}

void init()
{
    //get_hash();
    cnt=1;
    root=cnt++;
    trie[0].Set();
    trie[1].Set();
    for(int i=0 ;i<ch; i++)
    {
        trie[0].link[i] = root;
    }
}
void _insert(char in[], int k)
{
    int i, now = root;
    for(i = 0 ; in[i] ; i++)
    {
        //int id = _hash[in[i]];
        int id = in[i] - 'a';
        if(!trie[now].link[id])
        {
            trie[cnt].Set();
            trie[now].link[id]=cnt++;
        }
        now=trie[now].link[id];
    }
    hash[k] = now;
}

void build()
{
    queue<int> q;
    q.push(root);
    int aa, t, bb;
    while( !q.empty() )
    {
        t = q.front();
        q.pop();
        for(int i=0; i<ch; i++)
        {
            aa = trie[t].link[i];
            bb = trie[t].fail;

            if(trie[t].link[i])
            {
                trie[aa].fail = trie[bb].link[i];
                q.push(aa);
            }
            else
            {
                trie[t].link[i] = trie[bb].link[i];
            }
        }
    }
}
void Aho_Corasick(char *str)
{
    int id, i , cur = root;
    for(i = 0; str[i] ; i++)
    {
        //id = _hash[str[i]];
        id = str[i] - 'a';
        cur=trie[cur].link[id];
        trie[cur].f++;
    }
}
void dfs(int u)
{
    freq[u] = trie[u].f;
    int i, v;
    for(i=0; i< E[u].size() ; i++)
    {
        v= E[u][i];
        dfs(v);
        freq[u] += freq[v];
    }
}
int main()
{
    int t, tcase, i, j;
    int n;
    scanf("%d", &tcase);
    for(t=1; t<=tcase; t++)
    {
        init();
        for(i=0; i< 500005; i++) E[i].clear();

        scanf("%d", &n);
        scanf("%s", ss);

        for(i=0 ;i<n; i++)
        {
            scanf("%s", st);
            _insert(st,i);
        }
        build();
        for(i=1; i<cnt; ++i)
        {
            int f = trie[i].fail;
            E[f].push_back(i);
        }

        memset(freq, 0, sizeof(freq));

        Aho_Corasick(ss);
        dfs(root);

        printf("Case %d:\n", t);
        for(i=0; i<n; i++)
            printf("%d\n", freq[hash[i]]);

    }
    return 0;
}
#include<bits/stdc++.h>

using namespace std;

#define ch 26
#define MAX 500005

vector<int> E[500005];

int freq[MAX];
char ss[1000010];
char st[MAX];
int hash[MAX];

struct data
{
    int link[ch];
    int fail, f;
    void Set()
    {
        memset(link , 0, sizeof(link));
        fail = f = 0;
    }
};
data trie[500005];
int cnt,root;
int _hash[300];

void get_hash()
{
    for(int i=0;i<26;i++) _hash[i+'a']= i;
}

void init()
{
    //get_hash();
    cnt=1;
    root=cnt++;
    trie[0].Set();
    trie[1].Set();
    for(int i=0 ;i<ch; i++)
    {
        trie[0].link[i] = root;
    }
}
void _insert(char in[], int k)
{
    int i, now = root;
    for(i = 0 ; in[i] ; i++)
    {
        //int id = _hash[in[i]];
        int id = in[i] - 'a';
        if(!trie[now].link[id])
        {
            trie[cnt].Set();
            trie[now].link[id]=cnt++;
        }
        now=trie[now].link[id];
    }
    hash[k] = now;
}

void build()
{
    queue<int> q;
    q.push(root);
    int aa, t, bb;
    while( !q.empty() )
    {
        t = q.front();
        q.pop();
        for(int i=0; i<ch; i++)
        {
            aa = trie[t].link[i];
            bb = trie[t].fail;

            if(trie[t].link[i])
            {
                trie[aa].fail = trie[bb].link[i];
                q.push(aa);
            }
            else
            {
                trie[t].link[i] = trie[bb].link[i];
            }
        }
    }
}
void Aho_Corasick(char *str)
{
    int id, i , cur = root;
    for(i = 0; str[i] ; i++)
    {
        //id = _hash[str[i]];
        id = str[i] - 'a';
        cur=trie[cur].link[id];
        trie[cur].f++;
    }
}
void dfs(int u)
{
    freq[u] = trie[u].f;
    int i, v;
    for(i=0; i< E[u].size() ; i++)
    {
        v= E[u][i];
        dfs(v);
        freq[u] += freq[v];
    }
}
int main()
{
    int t, tcase, i, j;
    int n;
    scanf("%d", &tcase);
    for(t=1; t<=tcase; t++)
    {
        init();
        for(i=0; i< 500005; i++) E[i].clear();

        scanf("%d", &n);
        scanf("%s", ss);

        for(i=0 ;i<n; i++)
        {
            scanf("%s", st);
            _insert(st,i);
        }
        build();
        for(i=1; i<cnt; ++i)
        {
            int f = trie[i].fail;
            E[f].push_back(i);
        }

        memset(freq, 0, sizeof(freq));

        Aho_Corasick(ss);
        dfs(root);

        printf("Case %d:\n", t);
        for(i=0; i<n; i++)
            printf("%d\n", freq[hash[i]]);

    }
    return 0;
}
