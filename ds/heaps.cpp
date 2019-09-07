
int n;
int arr[10000007];


int getParent(int i){
  if(i & 1) return (i - 1) / 2;
  return (i - 2) / 2;

}
void heapify(int i){
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  int smallest;
  if(left < n && arr[left] < arr[i]) smallest = left;
  else smallest = i;

  if(right < n && arr[right] < arr[smallest]) smallest = right;

  if(smallest != i){
    swap(arr[smallest], arr[i]);
    heapify(smallest);
  }
}
void buildHeap(){
  for(int i = n/2 - 1;i >=0;i--) heapify(i);
}

void increaseVal(int i, int val){
  if(arr[i] < val) return;
  arr[i] = val;
  int j = i;
  while(j > 0 && arr[getParent(j)] > arr[j]){
    swap(arr[getParent(j)], arr[j]);
    j = getParent(j);
  }
}

void push_value(int x){
  n++;
  arr[n-1] = INT_MAX;
  increaseVal(n-1, x);
}
int extractMin(){
  int chota = arr[0];
  arr[0] = arr[n-1];
  n--;
  heapify(0);

  return chota;
}

bool isEmpty(){
  return n==0;
}