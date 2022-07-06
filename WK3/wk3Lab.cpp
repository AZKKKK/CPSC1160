#include <iostream>
#include <ctime>

using namespace std;

void makeBook(int***& book,int K, int M, int N);
void fillBookWithRandomValues(int*** book,int K ,int M, int N);
void printBook(int*** book,int K ,int M, int N);
void printPage(int*** book,int pageNum ,int M, int N);
int random5To55();
int getSum(int*** book,int pageNum ,int M, int N);
int* sort(int*** book,int K ,int M, int N);
void clearBook(int***& book,int M, int N);




int main()
{   
    // set up variables
    srand(time(0));
    int K;
    int M;
    int N;
    cout << "Enter K, M, N to create a book" << endl;
    cin >> K >> M >> N;

    //Make book and print it
    int*** book; 
    makeBook(book,K,M,N);
    fillBookWithRandomValues(book,K,M,N);
    printBook(book,K,M,N);
    
    //sort and print
    int* sortedIndex = sort(book,K,M,N);
    
    //print sorted pages
    cout << endl << "After sorting" << endl;
    for (int i = 0; i < K; i ++)
    {
        printPage(book, sortedIndex[i], M, N);
    }

    //deallocation
    delete [] sortedIndex;
    sortedIndex = nullptr;
    clearBook(book,M,N);
    
    return 0;
}

void makeBook(int***& book, int K, int M, int N)
{
    book = new int** [K];
    for (int i = 0; i < K; i++)
    {
        book[i] = new int* [M];
        for (int j = 0; j < M; j++)
        {
            book[i][j] = new int[N];
        }
    }
}

void fillBookWithRandomValues(int*** book, int K, int M, int N)
{
    for (int i = 0; i < K; i ++)
    {
        for (int j = 0; j < M; j ++)
        {
           
            for (int t = 0; t < N; t++)
            {
                book[i][j][t] = random5To55();
            }
        }
    }
    
}

int random5To55()
{
    return 5 + ((double)(rand()%100)*51/100);
}

void printBook(int*** book,int K ,int M,int N)
{
    for (int i = 0; i < K; i ++)
    {
        printPage(book,i ,M,N);
    }
}

void printPage(int*** book,int pageNum ,int M, int N)
{
    cout << "Page " << pageNum << ": " << getSum(book,pageNum,M,N) << endl;// print with sum
        for (int j = 0; j < M; j ++)
        {
            for (int t = 0; t < N; t++)
            {
                cout << book[pageNum][j][t] << " ";
            }
            cout << endl;
        }
        cout << endl;
}

int getSum(int*** book,int pageNum ,int M, int N)
{
    int sum = 0;
    for (int i = 0; i < M; i ++)
    {
        for (int j = 0; j < N; j ++)
        {
            sum += book[pageNum][i][j];
        }
    }

    return sum;
}

int* sort(int*** book,int K ,int M, int N)
{   // array to hold indexes for book 
    int* sortedIndex = new int[K];

    for (int i = 0; i < K; i ++)
    {   
        //assigning page numbers to array
        sortedIndex[i] = i;
    }

    //insertion sort
    for (int i = 0; i < K; i ++){
        int current = sortedIndex[i];

        int j;
        for (j = i - 1; j >= 0 && getSum(book,sortedIndex[j],M,N) > getSum(book,current,M,N)  ; j --)
            sortedIndex[j + 1] = sortedIndex[j];
        

        sortedIndex[j + 1] = current;  
    }

    return sortedIndex;
}

void clearBook(int***& book, int M, int N)
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {   delete [] book[i][j];
            book[i][j] = nullptr;
        }
        delete [] book[i];
        book[i] = nullptr;
    }
    delete [] book;
    book = nullptr;
}



