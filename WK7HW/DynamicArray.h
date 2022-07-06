#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

class DynamicArray{
public:
    int size;
private:
    int* array;

public:
    // constructors
    // default constructor
    DynamicArray(){
        cout << "default constructor called\n";
        size = 0;
        array = nullptr;
    }

    //defined constructors
    DynamicArray(int n){
        cout << "defined constructor called\n";
        // set n to size
        // allocate size integers worth of memory to array
        // set the value of each integer in array to 0
        size = n;
        array = new int[size];
        for(int i = 0; i < size; i++){
            array[i] = 0;
        }
    }

    DynamicArray(int n, int min, int max){
        // set n to size
        // allocate memeory for size integers worth of memory
        // set the value of ech integer in array to a random integer between min and max, both inclusive
        srand(time(0));
        size = n;
        array = new int[size];
        for(int i = 0; i < size; i++){
            array[i] = GenerateRandom(min, max);
        }
    }

    // destructor
    ~DynamicArray(){
        if(array){
            delete[] array;
            array = nullptr;
        }        
    }
    

    void Show(){
        // display contents of array on a line
        for(int i = 0; i < size; i++){
            cout << array[i] << ", ";
        }
        cout << endl;
    }

private:
// private methods are to be used inside of a class
    int GenerateRandom(int min, int max){
        // returns a random integer between min and max both inclusive
        return min + rand() % (max - min + 1);
    }


//HW Methods
public:
    int* GetArray(){ 
        return array; 
    }

/**
 * @brief Add a designated integer to a certerin index in the array 
 *        and keep all previouselements
 *        
 *        f(n) = 5n + 11
 *        O(n) = O(n) where n is 'size+1' 
 *        Since the only loop controled by this value
 * 
 * @param item the designated integer to add
 * @param index the index to insert an integer
 * @return void
 */
    void Add(int item, int index){
        if(index < 0 || index > size){//3
            cout << "Invalid Index\n";//2
            return;
        }
        
        size ++;//2
        int* newArr = new int[size];//1
            //1         //n + 1     //2n
        for (int i = 0; i < size; i ++) {
            if (i < index) //2n
                newArr[i] = array[i];
            else if (i == index) 
                newArr[i] = item;
            else 
                newArr[i] = array[i-1];
            
        }

        delete[] array;
        array = newArr;//1
    }

/**
 * @brief Add a designated integer to the first of the array 
 *        and keep all previous elements
 *        
 *        f(n) = 5n + 10
 *        O(n) = O(n) where n is 'size+1' 
 *        Since the only loop controled by this value
 * 
 * @param item the designated integer to add
 * @return void
 */
    void AddFirst(int item){ 
        Add(item, 0); 
        
    }



/**
 * @brief Add a designated integer to the end of the array 
 *        and keep all previous elements
 *        
 *        f(n) = 5n+10
 *        O(n) = O(n) where n is 'size+1' 
 *        Since the only loop controled by this value
 * 
 * @param item the designated integer to add
 * @return void
 */
    void AddLast(int item){ 
        Add(item, size); 
    }


/**
 * @brief Add an array of integer to an input index  of the array 
 *        and keep all previous elements
 *        
 *        f(n) = 5n^2 + 15n + 7
 *        O(n^2) = O(n^2) where n is 'size+1' 
 *        Since the only loop controled by this value
 * 
 * @param item the designated integer to add
 * @return void
 */


    void Add(int index, int* newItems, int newItemsSize){
        if(index < 0 || index > size){ // 3
            cout << "Invalid Index\n"; //2
            return;
        }
            //1         //n+1           //2n    //2n
        for(int i = 0; i < newItemsSize; i ++, index ++){
            Add(newItems[i],index);//n(5n+10)
        }
    }

/**
 * @brief Remove an element from an input index of the array and 
 *        decrease the size
 * 
 *        f(n) = 7n + 3
 *        O(n) = O(n) where n is 'size' 
 *        Since the only loop controled by this value
 * 
 * @param index the input index where the element will be removed
 * @return void
 */
    void Remove(int index){
        size --;//1
        int* newArr = new int[size]; //1
        int place = 0;//1
                //1    //n + 1     //2n
        for(int i = 0; i < size; i ++){
            if(i == index) continue;//n
            newArr[place] = array[i];//n-1
            place ++;//2n-1
        }

        delete[] array;
        array = newArr;//1
    }

/**
 * @brief remove the first element from the array and decrease the size
 * 
 * 
 * @return void
 */
    void RemoveFirst(){ 
        Remove(0); 
    }

/**
 * @brief remove the last element from the array and decrease the size
 * 
 * @return void
 */
    void RemoveLast(){ 
        Remove(size-1); 
    }

/**
 * @brief remove element between index1 and index2 and decrease the size corespondingly
 *        f(n) = 9n + 13
 *        O(n) = O(n)
 *        n is the size of the original array
 *        and the loop can run n time at most
 * @param index1 
 * @param index2 
 */
    void Remove(int index1, int index2){
        if(index1 > index2){//1
            cout << "Invalid index inputs\n";//2
            return;
        }

        int* newArr = new int[size-(index2 - index1) + 1];//3
        int place = 0;//1
            //1         //n + 1     //2n
        for(int i = 0; i < size; i ++){
            if(i < index1 || i > index2){//3n
                newArr[place] = array[i];//n
                place ++;//2n
            }
        }

        size -=(index2 - index1) + 1;//4
        delete[] array;
        array = newArr;//1
    }

/**
 * @brief sort elements between index1 and index2 in the array 
 *        and keep the size same
 * 
 *        f(n) = nlogn + 6n + 10
 *        O(n) = O(nlogn) where n is (index2- index1)
 *        because the greatest power of n is nlogn
 * @param index1 
 * @param index2 
 */

    void Sort(int index1, int index2){
        if(index1 > index2){//1
            cout << "Invalid index inputs\n";//2
            return;
        }


        int newSize = index2 - index1 + 1;//3 
        int* newArr = new int[newSize];//1
            // 1      //1         //n + 1     //2n   //2n
        for(int i = 0,j = index1; j  < index2; i ++, j ++){
            newArr[i] = array[j];//n
        }

        //nlogn
        QuickSort(newArr,0,newSize-1);

        //not part of soring but remove the previous and add sorted
        this->Remove(index1,index2);
        this->Add(index1,newArr,newSize);


    }

//Help Methods to sort array
private:
    void Swap(int &a, int &b){
        int t = a;
        a = b;
        b = t;
    }

    //n is high - low
    //(1/2+1/2)logn * n
    void QuickSort(int* arr, int low, int high){
        if(low < high){
            int pivot = Partition(arr, low, high);//n
            QuickSort(arr,low,pivot-1);//1/2logn
            QuickSort(arr,pivot+1,high);//1/2logn
        }
    }

   
    int Partition(int* arr, int low, int high){
        int l = low;
        int h = high;
        int p = arr[low];

        while(l < h){

            while(arr[l] <= p)
                l ++;
            while(arr[h] > p)
                h --;
            if(l < h)
                Swap(arr[l], arr[h]);

        }

        swap(arr[low],arr[h]);

        return h;
    }


};


#endif

