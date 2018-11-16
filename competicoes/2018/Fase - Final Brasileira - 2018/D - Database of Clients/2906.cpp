/********************************************************************************************/
/* AUTOR: Thiago Alexandre Domingues de Souza                                               */
/* PROBLEMA: Database of Clients                                                            */
/********************************************************************************************/
#include <iostream>
#include <set>

#define TRACE(x...) 
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << "\n";)

#define MAX 105

using namespace std;

int main(){
int n, size;
char str[MAX], parsed[MAX];
bool at_sign, plus_sign;
set<string> s;

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%s",str);
        size = 0; 
        at_sign = plus_sign = false;
        for(int i=0; str[i]; i++){
            if(!at_sign && str[i] == '+'){
                plus_sign = true;
                continue;
            }

            if(str[i] == '@')
               at_sign = true;

            if(!at_sign && (plus_sign || str[i] == '.'))
               continue;                

            parsed[size++] = str[i];
        }
        parsed[size] = '\0';
        s.insert(parsed);
    }
    cout <<  s.size() << endl;
}

