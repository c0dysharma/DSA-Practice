#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// returns vectors of int with duplicates removed in ordered form
std::vector<int> removeDuplicates(int *arr, int size) {
  std::unordered_map<int, bool> seen;
  std::vector<int> items;

  for (int i = 0; i < size; i++) {
    // if exists nothing to do
    if (seen.count(arr[i]) > 0)
      continue;
    // if not add to map and vector
    seen[arr[i]] = true;
    items.push_back(arr[i]);
  }

  return items;
}

// return int which appears maximum number of times
int returnMaximum(int *arr, int size) {
  std::unordered_map<int, int> freq;
  int maxValue = 0;
  // add/increments every items frequency
  for (int i = 0; i < size; i++) {
    freq[arr[i]]++;
    maxValue = std::max(maxValue, freq[arr[i]]);
  }
  // tranverse throught the list and find maximum's key
  int key;
  for (int i = 0; i < size; i++) {
    if (maxValue == freq[arr[i]])
      key = arr[i];
    break;
  }
  return key;
}

// prints intersection between two array elements
void printIntersection(int *arr1, int size1, int *arr2, int size2) {
  std::unordered_map<int, int> mp;
  // create map of any of the array
  for (int i = 0; i < size1; i++) {
    mp[arr1[i]]++;
  };
  // now check if another arrays element is in map or not
  for (int i = 0; i < size2; i++) {
    if (mp[arr2[i]] > 0)
      std::cout << arr2[i] << ' ';
    // and decrement the frequency to allow same items pair
    mp[arr2[i]]--;
  }
}

// return number of pairs that sum to 0
int returnPairSum(int *arr, int size) {
  // create map
  std::unordered_map<int, int> mp;
  for (int i = 0; i < size; i++) {
    mp[arr[i]]++;
  }
  // search if opposite of each element exists or not(to make it 0)
  int pair = 0;
  for (int i = 0; i < size; i++) {
    if (mp[-(arr[i])] > 0) {
      // increment pair count
      pair++;
      // and decresase both value coz they are used once
      mp[arr[i]]--;
      mp[-(arr[i])]--;
    }
  }
  return pair;
}

// return distinct character string
std::string returnDistanctCharacters(std::string str) {
  // creating map for storing freq
  std::unordered_map<char, int> mp;
  std::string newStr = "";

  for (char a : str) {
    // its already there skip the character
    if (mp.count(a) > 0)
      continue;
    // its not here add to newStr and increase frequency
    mp[a]++;
    newStr += a;
  }

  return newStr;
}

// void print longest sequence range [x y]
void printLongestSequence(int *arr, int size) {
  // create a map for all values as key and bool as value
  // with False if we haven't considered for sequence True if we did
  std::unordered_map<int, bool> mp;
  for (int i = 0; i < size; i++) {
    mp[arr[i]] = false;
  }

  // now starting from first value we will seek sequence forward and backword
  int maxLength = 1;
  int start = arr[0];
  int end = arr[0];

  for (int i = 0; i < size; i++) {
    // if we already considered skip
    if (mp[arr[i]] == true)
      continue;

    mp[arr[i]] = true;
    int currLength = 1;

    // move forword till we don't find end of sequence
    int currEnd = arr[i] + 1;
    while (mp.count(currEnd) > 0) {
      mp[currEnd] = true;
      currLength++;
      currEnd++;
    }
    // move backword as well
    int currStart = arr[i] - 1;
    while (mp.count(currStart) > 0) {
      mp[currStart] = true;
      currLength++;
      currStart--;
    }
    // incrementing start coz we reduced 1 further
    currStart++;
    // same for the end
    currEnd--;

    // update the value of final vars if we gets maximum length
    if (currLength > maxLength) {
      maxLength = currLength;
      start = currStart;
      end = currEnd;
    }
    // totally optional
    // also update if lenghth is same iff this range starts with curr value
    if (currLength == maxLength && currStart == arr[i]) {
      start = currStart;
      end = currEnd;
    }
  }

  std::cout << start << " " << end << std::endl;
}

// return # of pair difference to k
int returnDiffrenceKPair(int *arr, int size, int K) {
  // creating map for O(1) access later
  std::unordered_map<int, int> mp;
  for (int i = 0; i < size; i++) {
    mp[arr[i]]++;
  }
  // find possible pair and increment pair counts
  int pairCount = 0;
  for (int i = 0; i < size; i++) {
    int currVal = mp[arr[i]];
    if(currVal == 0)
      continue;

    pairCount += currVal * mp[arr[i] + K];
    mp[arr[i] + K] = 0;
    pairCount += currVal * mp[arr[i] - K];
    mp[arr[i] - K] = 0;

    mp[arr[i]] = 0;   
  }
  return pairCount;
}

// largest subarray count sum to 0
int returnCountLargestSubaraySum0(int*arr, int size){
  // contains sum till now and their index
  std::unordered_map<int,int> mp;
  int maxLength = 0;
  // starting with sum 0 and index -1
  int sum = 0;
  int i = -1;
  mp[sum] = i;
  // traverse whole array
  while(i<size-1){
    i++;
    sum+=arr[i]; 
    // unique sum add to map
    if(mp.count(sum) == 0)
      mp[sum] = i;
    else{
      // till we find a sum that already exist
      int len = i - mp[sum];
      // if we get same sum it means value between them added to be 0
      // we can get # of elements by subtracting elements
      maxLength = std::max(maxLength, len);
    }
  }

  return maxLength;
}

int main(void) {
  int len;
  std::cin >> len;
  int arr[len];
  for (int i = 0; i < len; i++) {
    std::cin >> arr[i];
  }

  std::cout << returnCountLargestSubaraySum0(arr,len) << std::endl;
  return 0;
}