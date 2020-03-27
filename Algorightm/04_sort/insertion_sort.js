function insertionSort(arr) {
  var len = arr.length;
  var preIndex, current;
  for (var i = 1; i < len; i++) {
    preIndex = i - 1;
    current = arr[i];
    while (preIndex >= 0 && arr[preIndex] > current) {
      arr[preIndex+1] = arr[preIndex]; // 这一步是覆盖，不是交换
      preIndex--;
    }
    arr[preIndex+1] = current; // 这个需要把插入的数覆盖到正确的位置
  }
  return arr;
}

arr = [2, 7, 9, 4, 5, 1];
console.log("排序之前的数组：", arr);
arr = insertionSort(arr);
console.log("排序之后的数组：", arr);