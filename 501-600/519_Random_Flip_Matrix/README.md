## 1. Naive Implementation  
Actually use a 2D matrix, in each flip  
(1) use rand() to get the row  
(2) use rand() to get the column  
(3) if it is already 1, repeat (1)(2) until get the 0  

## 2. Expand to 1D  
Calculate the total number of elements, say **n**, and use rand() over **n** to get the id and use  
**n / n_cols** and **n % n_cols** to get actual position.  

## 3. Use only once rand() in each flip  
Exclude the elements that have been flipped and use rand() over the remaining elements. Each time reduce the **remain** by 1.  
**Initial**: an empty hashmap which stores the map from flipped element to the current last element.  
(1) Get the actual position:  
**rand() % remain** to get the id. If the id is in hashmap, i.e, it is flipped, look at which one it maps to as the position. Else the position is the id.  
(2) Update the value in hashmap:  
If the current last element not in hashmap, **hash[id] = remain - 1**. Else, it is already flipped, look at where it maps to, **hash[id] = hash[remain - 1]**.
