typedef struct lligada {
int valor;
struct lligada *prox;
} *LInt;

LInt newLInt (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct lligada));

    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}

#include <stdlib.h>
#include <stdio.h>
//1
int length (LInt l){
    int a;
    if (l == NULL) a = 0;
    else {
        a = 1;
        while (l -> prox != NULL) {
            a++;
            l = l -> prox;
        }
    }
    return a;
}

//3
void imprimeL (LInt head) {
  LInt current = head;
	while (current != NULL){
		printf("%d\n", (*current).valor);
		current = current->prox;
	}
}

//2
void freel (LInt l) {
  LInt tmp;
  while (l -> prox != NULL) {
    tmp = l;
    l = l -> prox;
    free(tmp);
  }
}

//4
LInt reverseL (LInt l){
    LInt a = NULL, x;
    x = l;
    while (l != NULL) {
        x = l;
        l = l -> prox;
        x -> prox = a;
        a = x;
    }
    return a;
}

//5
void insertOrd (LInt *l, int x){
    LInt l1;
    l1 = *l;
    if (l1 == NULL) {
        LInt new = newLInt(x,NULL);
        *l = new;
    }
     else {
        LInt tmp;
        int i = 0;
    while (l1 -> prox != NULL && l1->valor < x) {tmp = l1;l1 = l1 -> prox;i++;}
    if (l1->valor < x) {
    LInt new = newLInt(x,NULL);
        l1 -> prox = new;
    }
     else {
        LInt new = newLInt(x,l1);
        if (i == 0) *l = new;
        else tmp -> prox = new;
    }
    }
}

void insertOrd2 (LInt *l, int x){
    while (*l != 0 && x > (*l)->valor) l = &(*l)->prox;
    *l = newLInt(x,*l);
}
//6
int removeOneOrd (LInt *l, int x){
    LInt tmp,ant;
    int r = 1;
    tmp = *l;
    if (tmp == NULL || (tmp -> prox == NULL && tmp -> valor != x));
    else if (tmp -> prox == NULL) {free(tmp);*l = NULL;r = 0;}
    else {
        tmp = *l;
        while(tmp -> prox != NULL) {
            ant = tmp;
            tmp = tmp -> prox;
            if (tmp -> valor == x) {
                ant -> prox = tmp -> prox;
                free(tmp);
                return 0;
            }
        }
    }
    return r;
}

int removeOneOrd2 (LInt *l, int x){
    while (*l != 0 && x > (*l)->valor) l = &(*l)->prox;
    if (*l != 0 && (*l)->valor == x)
        *l = (*l) -> prox;

    else return 1;
    return 0;
  }

//7
void merge (LInt *r, LInt l1, LInt l2){
    *r = newLInt(4,NULL);
    LInt l= *r;
    int a = 0;
    while (a != 1) {
        if (l2 == NULL) {l -> prox = l1;a = 1;}
        else if (l1 == NULL) {l -> prox = l2;a = 1;}
        else if (l2 -> valor < l1 -> valor) {
            l -> prox = l2;
            l2 = l2 -> prox;
            l = l -> prox;
        }
        else {
            l -> prox = l1;
            l1 = l1 -> prox;
            l = l -> prox;
        }
    }
    l = *r;
    *r = (*r) -> prox;
    free(l);
}
void merge2 (LInt *r, LInt l1, LInt l2){

    while(l1 != 0 && l2 != 0) {
        if(l1 -> valor < l2 -> valor) {
            *r= l1;
            l1 = l1 -> prox;
        }
        else {
            *r = l2;
            l2 = l2 -> prox;
        }
        r = &(*r)->prox;
    }
     if (l1 == 0) *r = l2;
     else *r = l1;
    }

//8
void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    LInt aux,aux2;
    while (l !=  0) {
        if (x > l -> valor) {
            if(*mx == 0) {
                *mx = l;
                aux = *mx;
                l = l -> prox;
                aux -> prox = NULL;
            }
            else {
                aux -> prox = l;
                aux = aux -> prox;
                l = l -> prox;
                aux -> prox = NULL;
            }
        }
        else {
            if(*Mx == 0) {
                *Mx = l;
                aux2 = *Mx;
                l = l -> prox;
                aux2 -> prox = NULL;
            }
            else {
                aux2 -> prox = l;
                aux2 = aux2 -> prox;
                l = l -> prox;
                aux2 -> prox = NULL;
            }
        }
    }
}

//9
LInt parteAmeio (LInt *l){
    int c = 0;
    LInt t = *l, s = *l;
    while (t != NULL) {c++;t = t -> prox;}
    int a = c / 2;
    LInt b = *l;
    if (c == 1) return NULL;
    else {
    while (a != 1) {a--;b = b -> prox;}
    *l = b -> prox;
    b -> prox = NULL;
    }
    return s;

//10
int removeAll (LInt *l, int x){
    LInt t = *l,ant = t;
    int c = 0;
    while ((*l) -> valor == x && t-> prox != NULL) {
        *l = (*l) -> prox;
        t = t -> prox;
        c++;
    }
    if ((*l) -> valor == x) {*l = NULL;}
    while (t != NULL) {
        if (t -> valor == x) {
            ant -> prox = t -> prox;
            t = ant;
            t = t -> prox;
            c++;
        }
        else {ant = t;t = t -> prox;}
    }
    return c;
}

LInt repetido (LInt l,int x) {
    LInt c,a;
    while (l -> valor == x && l -> prox != NULL) l = l -> prox;
    if (l -> valor == x) l = NULL;
    else {
    c = l;
    while (c != NULL) {
        if (c -> valor == x)
            a -> prox = c -> prox;
        else a = c;
        c = c -> prox;
      }
    }
    return l;
}

//11
int removeDups (LInt *l){
    LInt s = *l;
    if (s == NULL || s -> prox == NULL);
    else {
        while (s -> prox != NULL) {
            s -> prox = repetido(s->prox,s -> valor);
            s = s -> prox;
        }
    }
    return *l;

int removeDups2 (LInt *l){
    LInt s = *l, c = *l,c2,ant;
    int r = 0;
    while (c != 0) {
        for(ant = c,c2 = c -> prox;c2 != 0;c2 = c2 -> prox) {
            if (c2 -> valor == c -> valor) {
                ant -> prox = c2 -> prox;
                r++;
                c2 = ant;
            }
            ant = c2;
        }
        c = c -> prox;
    }
    return r;
}

//12
int removeMaiorL (LInt *l){
    LInt c,a;
    c = *l;
    int x = c -> valor;
    while (c != NULL) {
        if (c -> valor > x) x = c-> valor;
        c = c -> prox;
    }
    c = *l;
    if (c -> valor == x) *l = (*l)->prox;
    else {
        while (c -> valor != x) {
            a = c;
            c = c -> prox;
        }
        a -> prox = c -> prox;
    }
    return x;
}

//13
void init (LInt *l){
    LInt c = *l,a;
    if (c -> prox == NULL) {*l = NULL;free(c);}
    else {
    a = c;
    c = c -> prox;
    while (c -> prox != NULL) {
        a = c;
        c = c -> prox;
    }
    a -> prox = NULL;
    free(c);
    }
}

void init2 (LInt *l){
    while((*l)->prox != 0) l = &(*l)->prox;
    *l = NULL;
}

//14
void appendL (LInt *l, int x){
    LInt a = newLInt (x,NULL),c;
    if (*l == NULL) *l = a;
    else {
        c = *l;
    while (c -> prox != NULL)
        c = c -> prox;
    c -> prox = a;
    }
}

void appendL2 (LInt *l, int x){
    while(*l != 0) l = &(*l)->prox;
    *l = newLInt(x,NULL);
}

//15
void concatL (LInt *a, LInt b){
    LInt c = *a;
    if (c == NULL) *a = b;
    else {
        while (c -> prox != NULL) c = c -> prox;
        c -> prox = b;
    }
}

void concatL2 (LInt *a, LInt b){
    while(*a != 0) a = &(*a)->prox;
    *a = b;
}

//16
LInt cloneL (LInt l) {
  LInt clone,a,s;
  a = newLInt(l->valor,NULL);
  clone = a;
  s = clone;
  l = l -> prox;
  while (l != NULL) {
    a = newLInt(l->valor,NULL);
    clone -> prox = a;
    clone = clone -> prox;
    l = l -> prox;
  }
  return s;
}

//17
LInt cloneRev (LInt l){
    LInt clone = NULL;
    while (l != NULL) {
        clone = newLInt(l->valor,clone);
        l = l -> prox;
    }
    return clone;
}

//18
int maximo (LInt l){
    int x = l->valor;
    while (l != NULL) {
        if (l -> valor > x) x = l -> valor;
        l = l -> prox;
    }
    return x;
}

//19
int take (int n, LInt *l){
    int l1 = 0;
    LInt c = *l,a;
    while (n != 0 && c != NULL) {
        n --;
        l1++;
        a = c;
        c = c -> prox;
    }
    if(n == 0) {
    a -> prox = NULL;
    while (c != NULL) {
        a = c;
        c = c -> prox;
        free(a);
    }
    }
    return l1;
}

//20
int drop (int n, LInt *l){
    int ct = 0;
    LInt c = *l;
    while (n != 0 && *l != NULL) {
        n--;
        ct++;
        c = *l;
        *l = (*l) -> prox;
        free(c);
    }
    return ct;
}

//21
LInt NForward (LInt l, int N){
    while (N != 0) {
        l = l -> prox;
        N--;
    }
    return l;
}

//22
int listToArray (LInt l, int v[], int N){
    int i;
    for (i = 0;l != NULL && i < N; i++) {
        v[i] = l -> valor;
        l = l -> prox;
    }
    return i;
}

//23
LInt arrayToList (int v[], int N){
    LInt a = newLInt(4,NULL),c;
    c = a;
    int i;
    if (N == 0) a = NULL;
    else {
        a -> valor = v[0];
        for(i = 1;i < N;i++) {
            c -> prox = newLInt(v[i],NULL);
            c = c -> prox;
        }
    }
    return a;
}
int i = 0;
if(i > 0) {
LInt n = newLInt(v[i],NULL),s = n;
i++;
while(i < N) {
  n -> prox = newLInt(v[i],NULL);
  n = n -> prox;
  i++;
}
}
//24
LInt somasAcL (LInt l) {
    LInt new = NULL,s = new;
    if (l != 0) {
        new = newLInt(l -> valor,new);
        s = new;
        l = l -> prox;
    while (l != 0) {
        new -> prox = newLInt(l -> valor + new -> valor,NULL);
        new = new -> prox;
        l = l -> prox;
    }
    }
    return s;
}

//25
void remreps (LInt l){
    LInt c = l,a;
    if (l == NULL || l -> prox == NULL);
    else {
        a = l;
        c = c -> prox;
        while (c != NULL) {
            if (a -> valor != c -> valor) {
              a -> prox = c;
              a = a -> prox;
            }
              c = c -> prox;
        }
        a -> prox = NULL;
    }
}

//26
LInt rotateL (LInt l){
    if (l == NULL || l -> prox == NULL);
    else {
        LInt a = l,c;
        l = l -> prox;
        a -> prox = NULL;
        c = l;
        while (c -> prox != NULL) c = c -> prox;
        c -> prox = a;
    }
    return l;
}

//27
LInt parte (LInt current) {
  LInt spar = newLInt(4,NULL),simp = newLInt(4,NULL),cpar = spar,cimp = simp;
  int i;
  for (i =0;l != NULL;i++) {
    if(i % 2 == 0) {
      cpar ->prox = current;
      cpar = cpar -> prox;
      current = current -> prox;
      cpar -> prox = NULL;
    }
    else {
      cimp ->prox = current;
      cimp = cimp -> prox;
      current = current -> prox;
      cimp -> prox = NULL;
    }
  }
  LInt tmp = spar;
  spar = spar -> prox;
  free(tmp);

  tmp = simp;
  simp = simp -> prox;
  return simp;
}

//28
int altura (ABin a){
    int alt;
    if (a == NULL) alt = 0;
    else {
        int ea = altura(a -> esq);
        int da = altura(a -> dir);
        if(ea > da) alt = ea + 1;
        else alt = da + 1;
    }
	return alt;
}

//29
ABin cloneAB (ABin a) {
    ABin clone = (ABin) malloc (sizeof (struct nodo));
    if (a == NULL) clone = NULL;
    else {
        clone -> valor = a -> valor;
        clone -> esq = cloneAB (a -> esq);
        clone -> dir = cloneAB (a -> dir);
    }
    return clone;
}

//30
void mirror (ABin *a) {
    ABin s;
    if (*a != NULL) {
    s = (*a) -> esq;
    (*a) -> esq = (*a) -> dir;
    (*a) -> dir = s;
    mirror (&((*a) -> esq));
    mirror (&((*a) -> dir));
    }
}

//31
void inorder (ABin root, LInt *head){
  if(root != NULL) {
    inorder(root->esq,head);
    appendL(head,root->valor);
    inorder(root->dir,head);
  }
}

//32
void preorder (ABin root, LInt *head){
  if(root != NULL) {
    appendL(head,root->valor);
    preorder(root->esq,head);
    preorder(root->dir,head);
  }
}

//33
void posorder (ABin root, LInt *head){
  if(root != NULL) {
    posorder(root->esq,head);
    posorder(root->dir,head);
    appendL(head,root->valor);
  }
}

//34
int depth (ABin a, int x) {
    int d = 0;
    if (a == NULL) return -1;
    if (a -> valor == x) d = 1;
    else {
        int de = depth(a->esq,x);
        int dd = depth(a->dir,x);

    if (de == -1 && dd == -1) d = -1;
    else if (de == -1 ) d = dd + 1;
    else if (dd == -1 ) d = de + 1;
    else {
        if (de < dd) d = de + 1;
        else d = dd + 1;
    }
    }
    return d;
}

//35
int freeAB (ABin a) {
    if (a == NULL) return 0;
    int l = 1 + freeAB(a->esq) + freeAB(a ->dir);
        free(a);
    return l;
}

//36
int pruneAB (ABin *a, int l) {
     //ABin r = *a;
     int n = 0;
     if (*a == NULL) return 0;
     else if (l == 0) {
         n = 1 + pruneAB(&((*a) -> esq),l) + pruneAB(&((*a) -> dir),l);
         free(*a);
         *a = NULL;
     }
     else n = pruneAB(&((*a) -> esq),l-1) + pruneAB(&((*a) -> dir),l-1);
     return n;
 }

//37
int iguaisAB (ABin a, ABin b) {
    int r = 0,re,rd;
    if (a == 0 && b == 0) r = 1;
    else if((a == 0 && b != 0) || (a != 0 && b == 0)) r = 0;
    else if (a -> valor == b -> valor){
        re = iguaisAB(a->esq,b->esq);
        rd = iguaisAB(a->dir,b->dir);
        if(re < rd) r = re;
        else r = rd;
    }
    return r;
}

//38
void nivel (ABin a, int n,LInt *l) {
    if(a == NULL);
    else if (n == 1) {
        LInt new = (LInt) malloc (sizeof (struct lligada));
        new -> valor = a -> valor;
        new -> prox = *l;
        *l = new;
    }
    else {
        nivel(a -> dir,n - 1,l);
        nivel(a -> esq,n - 1,l);
    }
}

LInt nivelL (ABin a, int n) {
    LInt s = NULL;
    nivel(a,n,&s);

    return s;
}

//39
int nivelV (ABin a, int n, int v[]) {
    int c = 0;
    if(a == NULL);
    else if (n == 1) {
        v[0] = a -> valor;
        c++;
    }
    else {
        c = nivelV(a->esq, n-1, v);
    	c += nivelV(a->dir, n-1, v + c);
    }
    return c;
}

//40
int dumpAbin (ABin a, int v[], int N) {
    int c = 0;
    if(a == NULL || N == 0) return 0;
    else {
        c = dumpAbin(a -> esq,v,N-1);
        v[c] = a -> valor;
        c += 1 + dumpAbin(a -> dir,v + c + 1,N - c - 1);
        }
    return c;
}

//41
int soma (ABin a) {
    int s = 0;
    if (a == NULL);
    else s = a -> valor + soma(a -> esq) + soma(a -> dir);

    return s;
}
ABin somasAcA (ABin a) {
    ABin new = (ABin) malloc (sizeof (struct nodo));
    if (a == NULL) new = NULL;
    else {
        new -> valor = soma(a);
        new -> esq = somasAcA(a -> esq);
        new -> dir = somasAcA(a -> dir);
    }
    return new;
}

//42
int contaFolhas (ABin a) {
    int c = 0;
    if (a == NULL);
    else if (a -> esq == NULL && a -> dir == NULL) c = 1;
    else c = contaFolhas(a -> esq) + contaFolhas(a -> dir);

    return c;
}

//43
ABin cloneMirror (ABin a) {
    ABin new = (ABin) malloc (sizeof (struct nodo));
    if (a == NULL) new = NULL;
    else {
        new -> valor = a -> valor;
        new -> dir = cloneMirror(a -> esq);
        new -> esq = cloneMirror(a -> dir);
    }
    return new;
}

//44
int addOrd (ABin *a, int x) {
    if(*a == NULL) {
        ABin new = (ABin) malloc (sizeof (struct nodo));
        new -> valor = x;
        new -> esq = NULL;
        new -> dir = NULL;
        *a = new;
        return 0;
    }
    else if ((*a) -> valor == x) return 1;
    else {
        if (x < (*a) -> valor) return addOrd(&((*a)->esq),x);
        else return addOrd(&((*a)->dir),x);
    }
}

//n recursiva
int addOrd2 (ABin *a, int x) {
  int r;
  while(*a != 0 && (*a)->valor != x) {
    if (x < (*a)->valor) a = &(*a)->esq;
    else a = &(*a)->dir;
  }
  if(*a != 0) r = 1;
  else {
    ABin new = (ABin) malloc(sizeof(ABin));
    new -> valor = x;
    new -> esq = NULL;
    new -> dir = NULL;
    *a = new;
    r = 0;
  }
  return r;
}

//45
int lookupAB (ABin a, int x) {
    int r = 1;
    if (a == NULL) r = 0;
    else if (a -> valor == x);
    else {
        if (x < a -> valor) r = lookupAB (a -> esq,x);
        else r = lookupAB (a -> dir,x);

    }
    return r;
}

//46
int depthOrd2 (ABin a, int x,int p) {
    if (a == NULL) p = -1;
    else if (a -> valor == x);
    else {
        if (a -> valor > x)
            p = depthOrd2(a -> esq,x,p+1);
        else  p = depthOrd2(a -> dir,x,p+1);
    }
    return p;
}

int depthOrd (ABin a, int x) {
    int p = 1;
    p = depthOrd2 (a,x,p);
    return p;
}

int depthOrd3 (ABin a, int x) {
    int n = 1;
    while (a != 0 && a -> valor != x) {
        n++;
        if(x < a -> valor) a = a ->esq;
        else a = a -> dir;
    }
    if(a == 0) n = -1;
    return n;
}

//47
int maiorAB (ABin a) {
    int maior;
    if (a -> dir == NULL) maior = a -> valor;
    else maior = maiorAB(a->dir);
    return maior;
}

//48
void removeMaiorA (ABin *a) {
    ABin s = *a;
   if ((*a) -> dir == 0) *a = (*a) -> esq;
   else removeMaiorA(&((*a)->dir));
}

void removeMaiorA2 (ABin *a) {
    while((*a)->dir != 0) a = &(*a) -> dir;
    *a = (*a) -> esq;
}

//49
int quantosMaiores (ABin a, int x) {
    int c = 0;
    if (a == NULL);
    else {
        if(a -> valor > x) {
            c = 1;
        c += quantosMaiores (a -> esq,x) + quantosMaiores (a -> dir,x);
        }
        else c = quantosMaiores (a -> dir,x);
    }
    return c;
}

//50
int addOrd (ABin *a, int x) {
    if(*a == NULL) {
        ABin new = (ABin) malloc (sizeof (struct nodo));
        new -> valor = x;
        new -> esq = NULL;
        new -> dir = NULL;
        *a = new;
        return 0;
    }
    else if ((*a) -> valor == x) return 1;
    else {
        if (x < (*a) -> valor) return addOrd(&((*a)->esq),x);
        else return addOrd(&((*a)->dir),x);
    }
}

void listToBTree (LInt l, ABin *a) {
    int x;
    while(l != 0) {
        x = addOrd(a,l -> valor);
        l = l -> prox;
    }
}

//51
int min(ABin a) {
    int x;
    if (a -> esq == 0) x = a -> valor;
    else x = min(a->esq);
    return x;
}

int max(ABin a) {
    int x;
    if (a -> dir == 0) x = a -> valor;
    else x = max(a->dir);
    return x;
}

int deProcura (ABin a) {
    int r = 1;
    if (a == 0) return 1;
    if (a -> dir != 0 && a->valor > min(a -> dir)) r = 0;
    else if (a -> esq != 0 && a->valor < max(a -> esq)) r = 0;
    else if (!deProcura(a->esq) || !deProcura(a->dir)) r = 0;
    return r;
}

int main(){
    LInt new1 = newLInt(5, NULL);
    LInt new2 = newLInt(9, new1);
    LInt new3 = newLInt(2, new2);
    LInt new4 = newLInt(0, new3);
    LInt new5 = newLInt(3, new4);
    LInt new6 = newLInt(1, new5);
    imprimeL(new6);
    return 0;
}
