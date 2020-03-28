function shellSort(arr) {
  var len = arr.length;
  var gap = 1;
  var temp;

  while (gap < len / 3) // 动态定义间隔序列
    gap = gap * 3 + 1;

  for (gap; gap > 0; gap = Math.floor(gap / 3)) {
    for (var i = gap; i < len; i++) {
      tem = arr[i];
      for (var j = i - gap; j >= 0 && arr[j] > temp; j-=gap) 
        arr[j+gap] = arr[j];
      arr[j+gap] = temp;
    }
  }
  return arr;
}

arr = [2, 7, 9, 4, 5, 1];
console.log("排序之前的数组：", arr);
arr = shellSort(arr);
console.log("排序之后的数组：", arr);