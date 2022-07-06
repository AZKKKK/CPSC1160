// 20 points

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int GenerateRandomValue(int min, int max){
	return min + (rand() % (max - min + 1));
}

int** GenerateRandom2DArray(int rows, int cols, int min, int max){
	int** arr2D = new int*[rows];
	for(int i = 0; i < rows; i++){
		arr2D[i] = new int[cols];
	}

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			arr2D[i][j] = GenerateRandomValue(min, max);
		}
	}

	return arr2D;
}

void Display2DArray(int** arr, int rows, int cols) {
	cout << "--------------\n";
	cout << "--------------\n";
	
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

	cout << "--------------\n";
	cout << "--------------\n";
}

/**
 * @brief This function will removes the integers located between 
 * indices start and end (both inclusive) on each row of the 2D array
 * named arr which has dimensions rows x cols and returns a new 2D array
 * with dimensions rows x (cols - (end - start + 1)).
 * Function must validate start and end, start must be less or equal
 * to end as well both start and end must be between 0 and 
 * cols - 1 (both inclusive).
 * 
 * 
 * See sample output after main for examples.
 * 
 * @param arr, 2D array of integers with dimensions rows x cols
 * @param rows, int, number of rows in arr 
 * @param cols, int, number of cols in arr
 * @param start, int, starting index of slice to reverse
 * @param end, int, ending index of slice to reverse
 * @return 
 */

int** RemoveTheSlices(int** arr, int rows, int cols, int start, int end){
	const int newCols = cols - (end +start) + 1;
	int** newArr2D = new int*[rows];
	for(int i = 0; i < rows; i++){
		newArr2D[i] = new int[newCols];
	}

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(j < start){
				newArr2D[i][j] = arr[i][j];
			}else if(j > end){
				newArr2D[i][j-end] = arr[i][j];
			}
		}
	}

	return newArr2D;
}

/**
 * @brief Deallocate memory for arr2D
 * @param arr2D, 2D array of integers with dimensions rows x some number of columns per row
 * @param rows, int, number of rows in arr 
 */
void FreeMemory(int** &arr2D, int** &newArr2D, int rows){

	for(int i = 0; i < rows; i++){
		if(arr2D[i]){
			delete[] arr2D[i];
			arr2D[i] = nullptr;
		}

		if(newArr2D[i]){
			delete[] newArr2D[i];
			newArr2D[i] = nullptr;
		}
	}

	if(arr2D){
		delete[] arr2D;
		arr2D = nullptr;
	}

	if(newArr2D){
		delete[] newArr2D;
		newArr2D = nullptr;
	}
}

int main(){
	srand(time(0));
    int rows = 5, cols = 6;
    int** arr2D = GenerateRandom2DArray(rows, cols, 10, 200);

	int sliceStart = 1, sliceEnd = 4;
    
	cout << "The 2D array with " << rows << " rows and " << cols << " columns:\n";
    Display2DArray(arr2D, rows, cols);

	int** newArr2D = RemoveTheSlices(arr2D, rows, cols, sliceStart, sliceEnd);

	cout << "The 2D array with " << rows << " rows and " << cols - (sliceEnd - sliceStart + 1) << " columns after removing the slice between indices " << sliceStart << " and " << sliceEnd << " for each row in the array above\n";
    Display2DArray(newArr2D, rows, cols - (sliceEnd - sliceStart + 1));

	FreeMemory(arr2D, newArr2D, rows);
    return 0;
}

/* // Sample Output

The 2D array with 5 rows and 6 columns:
--------------
--------------
146     109     11      73      149     80
41      154     72      110     66      51
198     153     110     166     165     153
61      177     63      153     174     148
145     169     27      58      19      117
--------------
--------------
The 2D array with 5 rows and 2 columns after removing the slice between indices 1 and 4 for each row in the array above
--------------
--------------
146     80
41      51
198     153
61      148
145     117
--------------
--------------

*/