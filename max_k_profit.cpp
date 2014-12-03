/*
find max profit for at most k transaction, given an array of price
*/

int max_k_profit(const vector<int> &prices, int k){
  if(prices.size() < 2) return 0;
  vector<int> dp(prices.size(),0);
  for(int m=0;m<k;++m){
    vector<int> m_profit(dp);
    int max_profit = 0;
    for(int int i=0;i<prices.size();++i){
       int max_price=prices[i];
       int i_profit = 0;
       for(int j=i-1;j>=0;--j){
         i_profit = max(i_profit, max_price-prices[j]);
         max_prices = max(max_prices,prices[j]);
         max_profit = max(max_profit, i_profit+m_profit[j]);
       }
      m_profit[i]=max_profit;
    }
    dp = m_profit;
  }
  return dp.back();
}
