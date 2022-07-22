#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

void p1() {
  int x, y = 0;

  scanf ("%d",&x);

  while (x != 0){
    scanf ("%d",&x);
    if (x > y)
      y = x;
  }
  printf("Maior = %d \n",y);
}

void p2(){
 int x, n, soma;
 float media;

 scanf ("%d",&x);
 soma = x;
 n = 1;

 while (x != 0) {
   scanf ("%d",&x);
   soma = soma +x;
   n = n + 1;
 }
 media = (float) soma / (float) n;
 printf("Média = %f \n",media);
}

void p3() {
 int x, m1, m2;

 scanf ("%d",&x);
 m1 = x;

 scanf("%d", &x);

 if (m1 < x) {m2 = m1; m1 = x;}
 else m2 = x;

 while (x != 0){
   scanf ("%d",&x);
   if (m1 <= x) {m2 = m1; m1 = x;}
   else {if (m2 < x) m2 = x;}
 }

 printf("Segundo maior = %d \n",m2);
}

int bitsUm (unsigned int x){
    int r=0, a = 0;
    while (pow(2,a) < x) a++;
    for (a; x > 0;a--) {
        if (x >= pow(2,a)) {x -= pow(2,a); r++;}
    }
    return r;
}

int bitsUm2 (unsigned int x){
    int  r = 0;
    while(x != 0) {
        if (x % 2 != 0) r++;
            x /= 2;
    }
    return r;
}

int trailingZ (unsigned int n) {
  int  r = 0;
  while(n % 2== 0) {
      r++;
      n /= 2;
  }
  return r;
}

int qDig (unsigned int n) {
  int r = 1;
  while (n > 10) {
    r ++;
    n /= 10;
  }
  printf ("digitos em decimal %d\n",r);
  return r;
}

char *mystrcat2(char s1[], char s2[]) {
    int i, a = strlen(s1);
    for (i=0;s2[i] != '\0';i++) {
        s1[a + i] = s2[i];
    }
    s1[a +i] = '\0';
    return s1;
}
char *mystrcat (char s1[], char s2[]) {
  int a = 0,b = 0;
  while (s1 [a] != '\0') a++;
  while (s2 [b] != '\0') {
    s1 [a + b] = s2 [b];
    b ++;
  }
  s1 [a + b] = '\0';
  //printf("%s\n", s1);
  return s1;
}

 char *mystrcpy (char *dest, char source[]) {
  int i;
  for (i = 0; source [i] != '\0'; i++) dest [i] = source [i];
  dest [i] = '\0';
  return dest;
}

int mystrcmp(char s1[], char s2[]) {
    int r = 0,i =0;
    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0') i ++;
    if (s1[i] > s2[i]) r = 1;
    else r = -1;
    return r;
}
//10
char *mystrstr (char s1[], char s2[]) {
    int i = 0;
    if (s2[0] == '\0') return s1;
    while (s1[i] != s2[0]) i ++;
    int a = 0,i2 = i;
    while (s2[a] != '\0' && s1[i] != '\0') {
        if(s1[i] == s2[a]) {
            i++;
            a++;
        }
        else {a = 0;i2++;i = i2;}
    }
    if (s1[i] == '\0' && s2[a] != '\0') return NULL;
    return s1 + i2;
}

char *mystrstr2 (char s1[], char s2[]) {
   int i, i2 = 0, r = -1;
   for (i = 0;s1[i] != '\0' && r == -1;i++) {
        for(i2 = 0;s1[i + i2] == s2[i2] && r == -1;i2++) {
            if (s2[i2] == '\0') r = i;
        }
   }
    //if (r == -1) return NULL;
    return s1 + i - 1;
}


void mystrrev (char s[]) {
    char s2 [strlen(s)];
    strcpy (s2,s);
    int i,b;
    for (i = strlen (s) -1, b = 0; i >= 0; i --, b ++)
        s [b] = s2 [i];
    s [b] = '\0';
    return;
}

void mystrnoV (char t[]){
    // ... completar
    char t2 [strlen(t)];
    strcpy (t2,t);
    int a, b;
    for (a = 0, b = 0; t2[a] != '\0'; a++) {
        if (toupper(t2[a]) != 'A' && toupper(t2[a]) != 'E' && toupper(t2[a]) != 'I' && toupper(t2[a]) != 'O' && toupper(t2[a]) != 'U') {
        t [b] = t2 [a];
        b ++;
        }
    }
    t [b] = '\0';
}

void mytruncW (char t[], int n){
    int x = n,i = 0,i2 = 0;
    while (t[i] != '\0') {
    if(t[i] == ' ') {
        x = n;
        t[i2] = t[i];
        i2++;
    }
    else if (x != 0) {
        x--;
        t[i2] = t[i];
        i2++;
    }
    i++;
    }
    t[i2] = '\0';
}

char charMaisfreq (char s[]) {
    int i, count = 0, max = 0, z;
    char max2;
    if (*s == '\0') return 0;
    for (i = 0; s[i] != '\0'; i ++) {
        for (z = 0; s [z] != '\0'; z ++) {
            if (s[z] == s [i]) ++count;
        }
        if ( count > max) {
            max = count;
            max2 = s [i];
        }
        count = 0;
    }
    return (max2);
}

int iguaisConsecutivos (char s[]) {
    int c = 0, i, max = 0;
    for (i = 0; s[i] != '\0'; i++) {
        if (i == 0 || s[i - 1] != s[i]) c = 1;
        else c++;
        if (c > max) max = c;
    }
    return max;
}
int diferentes (char *s) {
   int i,res = 0, z;
   for (i = 0; s[i] != '\0' && res == 0; i ++) {
       for (z = 0; s[z] != '\0'; z++)
       if (s[i] == s[z] && i != z) res = 1;
   }
   return res;
}

int difConsecutivos(char s[])
{
 int i, a, c = 0, c2 = 1, max = 0;
 for (i = 1; s [i] != '\0'; i ++,c2++) {
     c = c2;
     for (a = i - 1; c - 1 > 0 && s[i] != s[a]; c --, a --);
     c2 -= c-1;
     if (c2 > max) max = c2;
 }
 if (s[0] == '\0') max = 0;
 if (strlen(s) == 1) max = 1;
 return max;
}

int maiorPrefixo (char s1 [], char s2 []) {
    int c = 0, i;
    for (i = 0; s1[i] == s2[i]; i++,c++);
    return c;
}

int maiorSufixo (char s1 [], char s2 []) {
    int c = 0, i,j;
    for (i= strlen(s1)-1, j = strlen (s2)-1; s1[i] == s2[j]; i--,j--,c++);
    return c;
}

int maiorSufixo2 (char s1 [], char s2 []) {
    int i = 0,i2 = 0,c = 0;
    while (s1[i] != '\0') i++;
    while (s2[i2] != '\0') i2++;
    i--;
    i2--;
    while (i >= 0 && i2 >= 0 && s1[i] == s2[i2]) {
        c++;
        i--;
        i2--;
    }
    return c;
}

int sufPref (char s1[], char s2[]) {
    int a,b;
    for (a = 0,b = 0; s1[a] != '\0'; a ++) {
        if (s2 [b] == s1[a]) b ++;
        else b = 0;
    }
    return b;
}

int contaPal (char s[]) {
    int i, c = 0;
    char ultimo = ' ';

    for (i = 0; s[i] != '\0'; i ++) {
        if (isspace(ultimo) && !(isspace (s[i]))) c ++;
        ultimo = s[i];
    }
    return c;
}

int contaVogais (char s[]) {
    int i, c = 0;
    for (i = 0; s[i] != '\0'; i ++) {
        if (toupper (s[i]) == 'A' || toupper (s[i]) == 'E' || toupper (s[i]) == 'I' || toupper (s[i]) == 'O' || toupper (s[i]) == 'U')
        c ++;
    }
    return c;
}
int mycontida (char a[], char b[]) {
    int i, x = 0, res = 1;
    for (x=0;a[x] != '\0' && res == 1;x++) {
        for (i = 0; b[i] != '\0' && b[i] != a[x]; i++);
        if (b[i] == '\0') res = 0;
    }
    return res;
}
int contida (char a[], char b[]) {
    int x, y, res = 1, c = 0;

    if (*a == '\0' || *b == '\0') return 0;

    for (x = 0; a[x] != '\0' && res == 1; x ++) {
        for (y = 0; c == 0 && a[x] != b[y]; y ++) {
            if (b[y] == '\0') c = 1;
        }
        if (c == 1) res = 0;
    }
    return res;
}

int palindroma2 (char s[]) {
    int i,x,res = 1;
    for (i=0, x = strlen(s) - 1; x != i && i != x && s[i] == s[x];i++, x--);
    if (s[i] != s[x]) res = 0;
    if (*s == '\0') res = 1;
    return res;
}
int palindroma (char s[]) {
    int i = 0,i2 = 0,r = 0;
    while (s[i] != '\0') i++;
    i--;
    while (i > i2 && s[i2] == s[i]) {
        i--;
        i2++;
    }
    if (i == -1 || s[i2] == s[i]) r = 1;
    return r;
}

int remRep (char texto []) {
    int a,b = 0;
    if(texto[0] == '\0');
    else {
    for (a = 1, b = 1; texto [a] != '\0'; a ++) {
        if (texto[a] != texto[b-1]) { texto[b] = texto [a]; b ++;}
    }
    texto[b] = '\0';
}
    return b;
}

int limpaEspacos (char texto[]) {
    int r=0,a,b;
    char ultimo = *texto;
    for (a =  1, b = 1; texto[a] != '\0'; a++) {
        if (ultimo == ' ' && texto[a] == ' ');
        else {texto[b] = texto[a];
              b++;
        }
        ultimo = texto[b-1];
    }
    texto[b] = '\0';
    r = strlen(texto);
    return r;
}

void insere (int s[], int N, int x){
       int i = N - 1;
    while (i >= 0 && s[i] > x) {
        s[i+1] = s[i];
        i--;
    }
    s[i + 1] = x;
   }

void merge (int r [], int a[], int b[], int na, int nb){
       int x,y,i;
       for (x = 0, y = 0, i = 0; i < na + nb; i++) {
           if (x < na && a[x] < b[y] || y == nb) {
               r[i] = a[x];
               x++;
           }
           else if (y < nb && a[x] >= b[y] || x == na){
               r[i] = b[y];
               y++;
           }
       }
   }


int crescente (int a[], int i, int j){
       int r=1;
       for (i; i < j && r == 1; i++) {
           if (a[i] > a[i+1]) r = 0;
       }
       return r;
}

int retiraNeg (int v[], int N){
       int r = 0,i;
       for (i = 0; i < N; i++) {
           if (v[i]>=0) {v[r] = v[i]; r++;}
       }
       return r;
}

int menosFreq (int v[], int N){
       int i,c= 1,min= 100,min2 = v[i];
       for (i = 1; i <= N; i++) {
           if (v[i] == v[i-1]) c++;
           else {if (c < min) {
                 min = c;
                 min2 = v[i-1];}
                 c = 1;

                }
       }
       return min2;
   }

int maisFreq (int v[], int N){
       int n = v[0],i = 1,c = 1,max = 1;
       if (N == 1) n = v[0];
       else {
           while (i < N) {
               if(v[i] == v[i-1]) c++;
               else c = 1;
               if (c > max) {
                   max = c;
                   n = v[i];
               }
               i++;
       }
       }
       return n;
   }

int maxCresc (int v[], int N) {
       int i,c=1,max=0;
       for (i = 1; i <= N; i ++) {
           if (v[i] >= v[i-1]) c++;
           else {if (c > max) max = c;
                 c = 1;}
       }
       return max;
   }

int elimRep (int v[], int N) {
       int i = 0,i2 = 0,in = 1;
       for (i = 1; i < N;i++) {
            for (i2 = 0;i2 < i - 1 && v[i] != v[i2];i2++);
            if(v[i] != v[i2]){
                v[in] = v[i];
                in++;
            }
       }
       return in;
   }

int elimRepOrd (int v[], int N) {
       int a, b = 1, u;
       u = *v;
       for (a = 1; a < N ; a++) {
           if (v[a]!=u) {
               v[b] = v[a];
               b++;
           }
           u = v[a];
       }

       return b;
   }

int comunsOrd (int a[], int na, int b[], int nb){
       int ia= 0,ib = 0, c = 0;
       while (ia < na && ib < nb) {
           if (a[ia] == b[ib]) {
               c++;
               ia++;
               ib++;
           }
           else if (a[ia] > b[ib]) ib++;
           else ia++;
       }
       return c;
   }

int comuns (int a[], int na, int b[], int nb){
      int ia, ib, c = 0;
      for (ia = 0;ia < na;ia++) {
          for (ib = 0; ib < nb && a[ia] != b[ib];ib++);
          if (ib < nb && a[ia] == b[ib]) c++;
      }
      return c;
   }

int minInd (int v[], int n) {
   int i, min = 0;
   for (i=1;i<n; i++) {
       if (v[i]<v[min]) min = i;

   }
   if(n == 1) min = 0;
   return min;
}

void somasAc (int v[], int Ac [], int N){
   int i, i2 = 0;
   Ac[0] = v[0];
   for (i = 1; i < N; i++)
       Ac[i] = Ac[i-1] + v[i];
}

int triSup (int N, int m [N][N]) {
    int x,y,res = 1;
    for (x = 0; x<N && res == 1; x++) {
        for(y=0;y<x && res == 1;y++){
            if(m[x][y]!=0) res = 0;
        }
    }
    return res;
}

void transposta (int N, float m [N][N]) {
    int x,y;
    float a;
    for(x=0;x<N;x++) {
        for(y = 0; y<x; y++) {
            a = m[x][y];
            m[x][y] = m[y][x];
            m[y][x] = a;
        }
    }
    return;
}

void addTo(int N, int M, int a [N][M], int b[N][M]) {
    int x,y;
    for (x = 0; x < N;x++) {
        for (y = 0; y < M;y++) {
            a [x][y] += b[x][y];
        }
    }
    return;
}

int unionSet (int N, int v1[N], int v2[N], int r[N]){
       int c;
       for (c = 0;c < N;c++) {
           if(v1[c] || v2[c]) r[c] = 1;
           else r[c] = 0;
       }
       return c;
   }

int intersectSet (int N, int v1[N], int v2[N], int r[N]){
       int c;
       for (c = 0;c < N;c++) {
           if(v1[c] && v2[c]) r[c] = 1;
           else r[c] = 0;
       }
       return c;
   }

int intersectMSet (int N, int v1[N], int v2[N], int r[N]){
       int c;
       for (c = 0;c < N;c++) {
           if(v1[c] < v2[c]) r[c] = v1[c];
           else r[c] = v2[c];
       }
       return c;
   }

int unionMSet (int N, int v1[N], int v2[N], int r[N]){
       int c;
       for (c = 0;c < N;c++) r[c] = v1[c] + v2[c];
       return c;
   }

int cardinalMSet (int N, int v[N]){
   	  int c=0,i;
   	  for (i=0; i < N;i++) {
   	      if(v[i]) c += v[i];
   	  }

   	  return c;
   }
typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
typedef struct posicao {
int x, y;
} Posicao;

Posicao posFinal (Posicao inicial, Movimento mov[], int N){
    int i;
    for (i=0;i < N;i++) {
        if (mov[i] == Norte) inicial.y += 1;
        else if (mov[i] == Sul) inicial.y -= 1;
        else if (mov[i] == Este) inicial.x += 1;
        else inicial.x -= 1;
    }
    return inicial;
}

int caminho (Posicao inicial, Posicao final, Movimento mov[], int N){
    int i;
    for (i=0;i < N && (inicial.x != final.x || inicial.y != final.y);i++) {
        if (inicial.y < final.y) {mov[i] = Norte; inicial.y++;}
        else if (inicial.y > final.y) {mov[i] = Sul; inicial.y--;}
        else if (inicial.x < final.x) {mov[i] = Este; inicial.x++;}
        else if (inicial.x > final.x) {mov[i] = Oeste; inicial.x--;}
    }
    if (inicial.x != final.x || inicial.y != final.y) return -1;
    return i;
}


int vizinhos (Posicao p, Posicao pos[], int N) {
    int i,c = 0;
    for(i = 0;i < N; i++) {
        if ((pos[i].x == p.x && (pos[i].y+1 == p.y || pos[i].y-1 == p.y)) || (pos[i].y == p.y && (pos[i].x+1 == p.x || pos[i].x-1 == p.x))) c++;
    }

    return c;
}

int maiscentral (Posicao pos[], int N) {
    int i,min = 0;
    for (i = 0; i < N; i++) {
        if (((pos[i].x)*(pos[i].x)+(pos[i].y)*(pos[i].y)) < ((pos[min].x)*(pos[min].x)+(pos[min].y)*(pos[min].y))) min = i;
    }
    return min;
}

int main(int argc, char const *argv[]) {
  int i = atoi(argv[1]);
  unsigned int n;
  char s1 [10], s2 [256];
  switch (i) {
    case 1:p1();
    case 2:p2();
    case 3:p3();
    case 4:{ scanf("%d", &n);
             printf("%d\n",bitsUm2(n));
             break;}
    case 5:{ scanf("%d", &n);
             trailingZ(n);
             break;}
    case 6:{ scanf("%d", &n);
             qDig(n);
             break;}
    case 7:{ scanf("%s", s1);
             scanf("%s", s2);
             printf("%s\n",mystrcat(s1,s2));
             break;}
    case 8:{ scanf("%s", s1);
             scanf("%s", s2);
             printf("%s\n",mystrcpy(s1,s2));
             break;}
    case 11 :{//scanf("%s", s1);
              //fgets (s1,256,stdin);
              char j[] = "abcde";
              mystrrev (j);
              printf ("%s\n",j);
              break;}
    case 12 :{//scanf("%s", s1);
              //fgets (s1,256,stdin);
              char j[] = "adAeEmiImOoUus";
              mystrnoV (j);
              printf ("%s\n",j);
              break;
            }
    case 13 :{//scanf("%s", s1);
              //fgets (s1,256,stdin);
              char j[] = "a    iImevr   usev";
              mytruncW (j,0);
              printf ("%s\n",j);
              break;
            }
    case 14 :{//scanf("%s", s1);
              //fgets (s1,256,stdin
              char j[] = "a    iImevr   usev";
              //charMaisfreq (j);
              printf ("%c\n",charMaisfreq (j));
              break;
            }
    case 15 :{//scanf("%s", s1);
              //fgets (s1,256,stdin);
              char j[] = "a    iImevr   usev";
              //charMaisfreq (j);
              printf ("%d\n",iguaisConsecutivos (j));
              break;
            }
    case 16:{ fgets (s1,256,stdin);
              printf ("%d\n", difConsecutivos(s1));
              break;
           }
    case 17:{ //scanf("%s", n);
             fgets (s1,256,stdin);
             fgets (s2,256,stdin);
             printf ("%d\n", maiorPrefixo(s1,s2));
             break;
           }
    case 18:{ //scanf("%s", n);
             fgets (s1,256,stdin);
             fgets (s2,256,stdin);
             printf ("%d\n", maiorSufixo(s1,s2));
             break;
           }
    case 19:{ //scanf("%s", n);
             //fgets (s1,256,stdin);
             //fgets (s2,256,stdin);
             printf ("%d\n", maisFreq({5,12,13,14,15},5);
             break;
           }
    case 20:{ //scanf("%s", n);
             fgets (s1,256,stdin);
             printf ("%d\n", contaPal(s1));
             break;
           }
    case 21:{ //scanf("%s", n);
             fgets (s1,256,stdin);
             printf ("%d\n", contaVogais(s1));
             break;
           }
    case 22:{ //scanf("%s", n);
             fgets (s1,256,stdin);
             fgets (s2,256,stdin);
             printf ("%d\n", contida(s1,s2));
             break;
           }
    case 23:{fgets (s1,256,stdin);
             printf ("%d\n", palindroma(s1));
             break;
           }
    case 24:{fgets (s1,256,stdin);
             printf ("%d\n", remRep(s1));
             break;
           }
    case 25:{fgets (s1,256,stdin);
             printf ("%d\n", limpaEspacos(s1));
             break;
           }
    case 26:{int s3[] = {1,4,6,32,54};
             insere(s3,10,15);
             break;
           }
    default:;
  }
  return 0;
}
