/******************************************************************************************************/
/* AUTOR: Thiago Alexandre Domingues de Souza                                                         */
/* PROBLEMA: Looking for the Risk Factor                                                              */
/* SOLUÇÃO: A dificuldade deste problema é consultar até 5*10^4 vezes um vetor com 10^5 elementos.    */
/* Portanto, não é possível fazer as consultas em O(n), então a busca é feita usando uma segment tree */
/* em O(log n).                                                                                       */
/* A ideia da solução é ler as consultas e ordená-las de forma decrescente em função do valor K,      */
/* então remover da segment tree todos os primos entre [0,n] que sejam maiores que K. Assim,          */
/* evidentemente, todos os elementos restantes serão menores que K. Em outras palavras, cada elemento */
/* restante na segment tree terá apenas elementos cujo maior divisor primo é menor que K.             */
/* Então, basta calcular a soma de elementos na segment tree.                                         */
/******************************************************************************************************/

#include <iostream>


#define MAXN 100005
#define MAXQ 50005

#define FOR(i,v,n) for(int i=v,_n=n;i<_n;++i)
#define REP(i,n) FOR(i,0,n)
#define TRACE(x...) 
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << "\n";)

using namespace std;

typedef struct {
int n, k, index;
} t_query;

int primes[MAXN], size_primes;
int tree[3*MAXN], v[MAXN];

int cmp(const void *a, const void *b){
t_query *x, *y;

    x = (t_query*)a;
    y = (t_query*)b;
    return y->k - x->k;
}

void sieve(int N_MAX) {
bool isPrime[N_MAX];

    for(int i=0; i<N_MAX; i++)
        isPrime[i] = true;

    isPrime[0] = isPrime[1] = false;

    size_primes = 0;

    for(int i=2; i<N_MAX; i++){
        if(isPrime[i]){
            for(int j=i*2; j<N_MAX; j+= i)
                isPrime[j] = false;
            primes[size_primes++] = i;
        }
    }
}

void buildSegmentTree(int node, int start, int end){
    if(start == end)
        tree[node] = v[start];
    else {
        int mid = (start + end)/2;
        buildSegmentTree(2*node + 1, start, mid);
        buildSegmentTree(2*node + 2, mid + 1, end);
        tree[node] = tree[2*node + 1] + tree[2*node + 2];
    }
}

void updateSegmentTree(int node, int start, int end, int index, int value){
    if(start == end){
        tree[node] = value;
    } else {
        int mid = (start + end)/2;
        if(index <= mid)
            updateSegmentTree(2*node + 1, start, mid, index, value);
        else
            updateSegmentTree(2*node + 2, mid + 1, end, index, value);
        tree[node] = tree[2*node + 1] + tree[2*node + 2];
    }
}

int rangeSum(int node, int start, int end, int i, int j){
    if(start > j || end < i)
       return 0;

    if(i <= start && j >= end)
       return tree[node];

    int mid = (start + end)/2;
    return rangeSum(2*node + 1, start, mid, i, j) +
           rangeSum(2*node + 2, mid + 1, end, i, j);
}


int main(){
int Q, N, K, N_MAX;
t_query query[MAXQ];

    scanf("%d", &Q); 
    N_MAX = 0;
    for(int i=0; i<Q; i++){
        scanf("%d %d", &N, &K);
        query[i].n = N;
        query[i].k = K;
        query[i].index = i;
        if(N > N_MAX)
           N_MAX = N;
    }

    qsort(query, Q, sizeof(t_query), cmp);

    sieve(N_MAX+1);

    for(int i=2; i<=N_MAX; i++)
        v[i] = 1;

    buildSegmentTree(0, 0, N_MAX+1);

    int ans[Q];
    for(int i=0; i<Q; i++){
        while(size_primes > 0 && primes[size_primes-1] > query[i].k){
            for(int ii=primes[size_primes-1]; ii<=N_MAX; ii+=primes[size_primes-1]){
                if(v[ii]){
                    v[ii] = 0;
                    updateSegmentTree(0,0,N_MAX+1, ii, 0);
                }
            }
            size_primes--;
        }
        ans[query[i].index] = rangeSum(0, 0, N_MAX+1, 2, query[i].n);
    }

    for(int i=0; i<Q; i++)
        printf("%d\n", ans[i]);
}

