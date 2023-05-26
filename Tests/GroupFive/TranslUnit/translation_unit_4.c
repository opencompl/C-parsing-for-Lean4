typedef struct Node Node;
typedef struct HashTable HashTable;
typedef struct ProbingHashTable ProbingHashTable;
typedef long ll;

struct Node
{
    int Element;
    Node *pNext;
};

struct HashTable
{
    int n;
    Node **table;
    Node **ending;
};

struct ProbingHashTable
{
    int n;
    int *table;
};

HashTable *CreateHashTable(int n);
ProbingHashTable *CreateProbingHashTable(int n);

void InsertSeparateChaining(HashTable *myHT, int x);
void InsertLinearProbing(ProbingHashTable *myHT, int x);
void InsertQuadraticProbing(ProbingHashTable *myHT, int x);

int SearchSeparateChaining(HashTable *myHT, int x);
int SearchLinearProbing(ProbingHashTable *myHT, int x);
int SearchQuadraticProbing(ProbingHashTable *myHT, int x);

ll getHash(ll x, int n) 
{ 
    return x % n; 
}

Node *createEntryChaining(int n)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->Element = n;
    temp->pNext = NULL;
    return temp;
}

HashTable *CreateHashTable(int n)
{
    int i;
    HashTable *hashTable = (HashTable *)malloc(sizeof(HashTable));
    hashTable->n = n;
    hashTable->table = (Node **)malloc(hashTable->n * sizeof(Node *));
    hashTable->ending = (Node **)malloc(hashTable->n * sizeof(Node *));

    for (i = 0; i < hashTable->n; i++)
    {
        hashTable->table[i] = (Node *)malloc(sizeof(Node));
        hashTable->table[i]->pNext = NULL;
        hashTable->ending[i] = hashTable->table[i];
    }

    return hashTable;
}

void InsertSeparateChaining(HashTable *myHT, int x)
{
    int hashValue = getHash(x, myHT->n);
    Node *node = createEntryChaining(x);
    Node *rear = myHT->ending[hashValue];
    rear->pNext = node;
    myHT->ending[hashValue] = node;
}

int SearchSeparateChaining(HashTable *myHT, int x)
{
    int hashValue = getHash(x, myHT->n);
    Node *head = myHT->table[hashValue]->pNext;
    int index = 0;

    while (head != NULL)
    {
        if (x == head->Element)
            return index;
        head = head->pNext;
        index++;
    }

    return -1;
}

ProbingHashTable *CreateProbingHashTable(int n)
{
    ProbingHashTable *myHT = (ProbingHashTable *)malloc(sizeof(ProbingHashTable));
    myHT->n = n;
    myHT->table = (int *)calloc(myHT->n, sizeof(int));
    return myHT;
}

void InsertLinearProbing(ProbingHashTable *myHT, int x)
{
    int hashValue = getHash(x, myHT->n);
    int traversal = hashValue;
    while (myHT->table[traversal] != 0)
        traversal = (traversal + 1) % myHT->n;

    myHT->table[traversal] = x;
}

int SearchLinearProbing(ProbingHashTable *myHT, int x)
{
    int hashValue = getHash(x, myHT->n);
    int traversal = hashValue;
    while (myHT->table[traversal] != x && myHT->table[traversal] != 0)
        traversal = (traversal + 1) % myHT->n;

    if (myHT->table[traversal] == x)
        return traversal;
    else
        return -1;
}

void InsertQuadraticProbing(ProbingHashTable *myHT, int x)
{
    int hashValue = getHash(x, myHT->n);
    int traversal = hashValue;
    int incrementer = 1;
    while (myHT->table[traversal] != 0)
    {
        traversal = (traversal + incrementer) % myHT->n;
        incrementer = (incrementer + 2) % myHT->n;
    }
    myHT->table[traversal] = x;
}

int SearchQuadraticProbing(ProbingHashTable *myHT, int x)
{
    int hashValue = getHash(x, myHT->n);
    int traversal = hashValue;
    int incrementer = 1;
    while (myHT->table[traversal] != x && myHT->table[traversal] != 0)
    {
        traversal = (traversal + incrementer) % myHT->n;
        incrementer = (incrementer + 2) % myHT->n;
    }

    if (myHT->table[traversal] == x)
        return traversal;
    else
        return -1;
}

int main()
{
    char *validInputs[3] = {"linear-probing", "quadratic-probing", "separate-chaining"};
    char str[30];
    int pos = -1;
    int tSize;  
    int numQ;
    int i;
    char c;
    int x;
    HashTable *ht1;
    ProbingHashTable *ht2;

    scanf("%s", str);


    for (pos = 0; pos < 4; pos++)
    {
        if (pos == 3)
        {
            printf("Error\n");
        }
        if (!strcmp(str, validInputs[pos]))
            break;
    }

    scanf("%d", &tSize);

    scanf("%d", &numQ);

    switch (pos)
    {
    case 0:
        ht2 = CreateProbingHashTable(tSize);
        for(i=0; i<numQ; i++)
        {
            scanf(" %c", &c);
            scanf("%d", &x);

            if(c == 43)
                InsertLinearProbing(ht2, x);

            else if(c ==63)
            {
                printf("%d\n", SearchLinearProbing(ht2, x));
            }
            else
            {
                printf("Error\n");
            }
        }
        break;
    
    case 1:
        ht2 = CreateProbingHashTable(tSize);
        for(i=0; i<numQ; i++)
        {
            scanf(" %c", &c);
            scanf("%d", &x);
            if(c ==43)
                InsertQuadraticProbing(ht2, x);

            else if(c ==63)
            {
                printf("%d\n", SearchQuadraticProbing(ht2, x));
            }
            else
            {
                printf("Error\n");
            }
        }
        break;

    case 2:
        ht1 = CreateHashTable(tSize);
        for(i=0; i<numQ; i++)
        {
            scanf(" %c", &c);
            scanf("%d", &x);
            if(c == 43)
                InsertSeparateChaining(ht1, x);

            else if(c ==63)
            {
                printf("%d\n", SearchSeparateChaining(ht1, x));
            }
            else
            {
                printf("Error\n");
            }
        }
        break;

    default:
        break;
    }

    return 0;
}
