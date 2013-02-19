# Chapter 1
## Section 1.1
### Your Ride is Here
Analysis里比较简明的写法：  

	int hash(char *s)  
	{
		int i, h;
		h = 1;
		for(i=0; s[i] && isalpha(s[i]); i++)
			h = ((s[i]-'A'+1)*h) % 47;
		return h;
	}
### Greedy Gift Givers
Tips: 1）要注意int型不准确。所以要保证给予的和得到的总和一样。2）要建立顺序，map默认按字母序排列。