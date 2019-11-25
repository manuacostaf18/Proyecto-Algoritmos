# HEAP SORT
void heapify(Vec& vector, int n, int i){
  int largest = i;
  int l = 2*i + 1;
  int r = 2*i + 2;

  if (l < n && vector.get(l) > vector.get(largest)) largest = l;

  if (r < n && vector.get(r) > vector.get(largest)) largest = r;

  if (largest != i){
    swap (i, largest, vector);
    heapify(vector, n, largest);
  }
}

void heap_sort(Vec& vector, int n){
  for (int i = n/2-1; i>=0; i--){
    heapify(vector, n, i);
}
  
# COUNTING SORT 
void count_sort(Vec& vector){
  map<int, int> freq;

  for(int i = 0; i < vector.getsize(); i++){
    freq[vector.get(i)]++;
  }
  int i = 0;
  for(auto it: freq){
    while(it.second--){
      vector.set(i++, it.first);
    }
  }
}
    
# SELECTION SORT 
void selection_sort(Vec& vector){
	for(int i = 0; i < vector.getsize()-1; ++i){
		int min_id = i;
		for(int j = i+1; j < vector.getsize(); ++j){
			if(vector.get(j) < vector.get(min_id)){
				min_id = j;
			}
		}
		swap(i, min_id, vector);
	}
}
            
# BUBBLE SORT
void bubble_sort(Vec& vector){
	bool swap_used = true;
	while(swap_used){
		swap_used = false;
		for(int i = 0; i < vector.getsize()-1; ++i){
			if(vector.get(i) > vector.get(i+1)){
				swap(i, i+1, vector);
				swap_used = true;
			}
		}
	}
}
            
# INSERTION SORT
void insertion_sort(Vec& vector){
	for(int i = 1; i < vector.getsize(); ++i){
		int a = i;
		int b = i-1;
		while(vector.get(b) > vector.get(a)){
			swap(a, b, vector);
      			a--;
			    b = a-1;
		}
	}
}
  
# QUICK SORT
int partition(Vec & vector, int low, int high){
	int pivot = vector.get(high);
	int i = (low -1);

	for(int j = low; j <= high - 1; j++){
		if(vector.get(j) < pivot){
			i++;
			swap(i, j, vector);
		}
	}

	swap(i+1, high, vector);
	return (i+1);
}

void quick_sort(Vec & vector, int low, int high){
	if(low < high){
		int pi = partition(vector, low, high);

		quicksort(vector, low, pi - 1);
		quicksort(vector, pi + 1, high);
	}
}
    
# MERGE SORT
void merge_sort(Vec & left, Vec & right, Vec & vector){
	int nL = left.getsize();
	int nR = right.getsize();
	int i = 0, j = 0, k = 0;
	
	while(j < nL && k < nR){
		if(left.get(j) < right.get(k)){
			vector.set(i, left.get(j));
			j++;
		}
		else{
			vector.set(i, right.get(k));
			k++;
		}
		i++;
	}
	while(j < nL){
		vector.set(i, left.get(j));
		j++;
		i++;
	}
	while(k < nR){
		vector.set(i, right.get(k));
		k++;
		i++;
	}
		
}

void sort(Vec & vector){
	if(vector.getsize() <= 1) return;
	
	int mid = vector.getsize()/2;
	Vec left;
	Vec right;
	
	for(size_t j = 0; j < mid; j++){
		left.push_back(vector.get(j));
	}
	for(size_t j = 0; j < (vector.getsize() - mid); j++){
		right.push_back(vector.get(mid+j));
	}
	
	sort(left);
	sort(right);
	mergesort(left, right, vector);
}

# SHELL SORT 
void shell_sort(Vec & vector){
	for(int gapSize = vector.getsize()/2; gapSize > 0; gapSize /= 2){
		for(int currentIndex = gapSize; currentIndex < vector.getsize(); currentIndex++){
			int currentIndexCopy = currentIndex;
			int item = vector.get(currentIndex);
			while(currentIndexCopy >= gapSize && vector.get(currentIndexCopy - gapSize) > item){
				vector.set(currentIndexCopy, vector.get(currentIndexCopy - gapSize));
				currentIndexCopy -= gapSize;
			}
		vector.set(currentIndexCopy, item);
		}
	}
}
            
# GNOME SORT
void gnome_sort(Vec& vector, int sz){
	int index = 0;

  while(index < sz){
    if(index == 0) index++;
    if (vector.get(index) >= vector.get(index-1)) index++;
    else{
      swap(index, index-1, vector);
      index--;
    }
  }
}
    
# COCKTAIL SORT
void cocktail_sort(Vec& vector, int n){
  bool swapped = true;
  int start = 0;
  int end = n-1;

  while(swapped){
    swapped = false;

    for (int i = start; i < end; i++){
      if(vector.get(i) > vector.get(i+1)){
        swap(i, i+1, vector);
        swapped = true;
      }
    }

    if (!swapped) break;
    swapped = false;
    end--;

    for(int i = end-1; i >= start; i--){
      if(vector.get(i) > vector.get(i+1)){
        swap(i, i+1, vector);
        swapped = true;
      }
    }
    start++;
  }
}
