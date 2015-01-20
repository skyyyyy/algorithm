//Parse a formula string (only contains "+-()", no "*/"), for example,
//5 + 2x - ( 3y + 2x  - ( 7 + 2x) - 9 ) = 3 + 4y”, parse this string, with
//a given float of ‘x’ value, output a float for ‘y’ value.
double evaluateY(const string &str, double x){
	int sum_num =0, sum_x=0, sum_y=0;
	int sign=1;
	int pos_equal = str.find("=");
    stack<int> s;
    s.push(1);
	for(int i=0;i<str.length();++i){
        char c=str[i];
        if(c>='0' && c<='9'){
            int num = 0;
            while(i<str.length() && str[i]>='0' && str[i]<='9'){
                num = num*10 +(str[i]-'0');
                ++i;
            }
            num *= sign * s.top();
            num *= (i<pos_equal?1:-1);
            //cout<< "num:"<<num<<endl;
            if(i<str.length() && (str[i]=='x' || str[i]=='y')){
                if(str[i]=='x'){
                    sum_x += num;
                }else{
                    sum_y += num;
                }
            }else{
                sum_num += num;
            }
        }else if(c=='x'){ //for signle 'x' such as x+y=3
            sum_x += sign * s.top()*(i<pos_equal?1:-1);
        }else if(c=='y'){
            sum_y += sign * s.top()*(i<pos_equal?1:-1);
        }else if(c=='+'){
            sign = 1;
        }else if(c=='-'){
            sign = -1;
        }else if(c=='('){
            s.push(sign*s.top());
            sign = 1;
        }else if(c==')'){
            s.pop();
        }else if(c=='='){
            sign = 1;
            s.push(1);
        }
	}
	
	return (sum_num+sum_x*x)/-sum_y;
	
}

int main(int argc, const char * argv[])
{
    cout << evaluateY("5 + 2x - ( 3y + 2x  - ( 7 + 2x) - 9 ) = 3 + 4y", 2.5) << endl; //3.28571
    cout << evaluateY("x - (y - (5 + 3y)) = 3y + 2x - 1", 2) << endl; //4
    cout << evaluateY("5 + 2x - ( 3y + 2x - ( 7 - 2x) - 9 ) = 3 + 4y", 2) << endl; //2
    cout << evaluateY("2y-(y+5)=3y+6", 2) << endl; //-5.5
    cout << evaluateY("10x + y = 2y - 10", 2) << endl; //30
    cout << evaluateY("x + 5 + y = 2y - 3x - 10", 2) << endl; //23
}


