/*
Given random() that can return 0 or 1 uniformly, implement random_new()
that can return 0 with 90%, and 1 with 10%.
*/

int random_new(){
  while(true){
    int res = 0;
    for(int i=0;i<10;++i) res |= random()<<i;
    if(res<=99) return 1;
    else if(res<=999) return 0;
  }
}
