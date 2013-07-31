Array.prototype.unique = function(){
    var i,
        arr = this,
        len = arr.length;
    
    for (i = len - 1; i != -1; i--){
        if (arr.indexOf(arr[i]) != i){
            arr.splice(i, 1);
        }
    }
    return arr;
}

