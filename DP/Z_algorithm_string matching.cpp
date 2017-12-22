int z[MAX];
void Z_algo(string s)
{
	int L, R , i, k, n;
	L = R = 0;
	n = s.length();
	for(i=1; i<n ; i++)
	{
		if(i > R)
		{
			L = R = i;
			while( R < n && s[R-L] == s[R])R++;
			z[i] = R -L;
			R--;
		}
		else
		{
			k = i - L;
			if(z[k] < R-i+1) z[i] = z[k];
			else
			{
				L = i;
				while( R<n && s[R-L] == s[R])R++;
				z[i] = R - L;
				R--;
			}
		}
	}
}
int main()
{
    //READ("input.txt");
	string str;
	int i, n, _max, flag;
    mem(z);
    cin >> str;
    Z_algo(str);
    flag = 0;
    _max = -100;
    n = str.length();
    FOR(i, n)
    {
		if(z[i] == n - i && _max >= n-i)
		{
			flag = n-i;
			break;
		}
		_max = max(_max, z[i]);
	}
	if(flag == 0)cout << "Just a legend" << endl;
	else cout << str.substr(0, flag) << endl;
    return 0;
}