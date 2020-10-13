int binary_search(int arr[], int n, int key){
	// Here n is the size of the array
	// key is the element we are trying to search

	int start = 0, end = n - 1, mid;

	while(start <= end){
		//Calculating the mid point
		mid = (start + end) / 2;
		
		//Checking if the middle element is indeed the key
		if (arr[mid] == key){
			return mid; // returning the address we found element
		}

		// Checking if our element is to the LEFT of the mid element
		else if (key < arr[mid]){
			end = mid - 1;
			continue;
		}

		// Checking if our element is to the RIGHT of mid element
		else if (key > arr[mid]){
			start = mid + 1;
			continue;
		}
	}


	// if the while loop is finished and we didnt return anything yet
	// it means the element is not in the array
	return -1; // to signify we didnt find it

}




/* [7, 12, 42, 59, 71, 86, 104, 212]*/





