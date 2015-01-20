Parse a formula string (only contains "+-()", no "*/"), for example,   “
5 + 2x – ( 3y + 2x  - ( 7 – 2x) – 9 ) = 3 + 4y”, parse this string, with
a given float of ‘x’ value, output a float for ‘y’ value.


//Parse a formula string (only contains "+-()", no "*/"), for example,  
//5 + 2x - ( 3y + 2x  - ( 7 + 2x) - 9 ) = 3 + 4y”, parse this string, with
//a given float of ‘x’ value, output a float for ‘y’ value.
double evaluateY(const string &str, double x){
	int sum_num =0, sum_x=0, sum_y=0;
	int sign=1;
	int pos_equal = str.find("=");
	int i=0;
	int start = 0;
	while(i<str.length()){
		while(i<str.length() && str[i]!='+' && str[i]!='-' && str[i]!='='){
			++i;
		}
		int num = 0;
		int j=start;
		for(; j<i;++j){
			if(str[j]>='0' && str[j]<='9'){
				num = num*10+(str[j]-'0');
			}else if(str[j]=='x' || str[j]=='y'){
				break;
			}
		}
		num *= sign;
		if(str[j]=='x'){
			if(start > pos_equal) num *= -1;
			sum_x +=num;
		}else if(str[j]=='y'){
			if(start < pos_equal) num *= -1;
			sum_y += num;
		}else{
			if(start > pos_equal) num *= -1;
			sum_num += num;
		}
		cout<< "num:"<<num<<endl;
		if(i<str.length() && str[i]=='-'){
			sign *= -1;
		}
		start = i+1;
		i=i+1;
	}
	
	return (sum_num+sum_x*x)/sum_y;
	
}
