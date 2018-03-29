int _next[MAXNUMBER] = { 0 };


//s主串，p匹配串
int search(string s,string p)
{
    int i = 0;
    int j = 0;
    _next[0] = -1;
    int sLen = s.length();
    int pLen = p.length();
    int k = -1;
    while (j < pLen - 1){
    	if (k == -1 || p[j] == p[k])
            ++k, ++j, _next[j] = k;
        else
            k = _next[k];
    }
        
    j = 0;
    while (i < sLen && j < pLen)
    {   
        if (j == -1 || s[i] == p[j])
            i++,j++;
        else    
            j = _next[j];
    }
    if (j == pLen)
        return i - j;
    else
        return -1;
}