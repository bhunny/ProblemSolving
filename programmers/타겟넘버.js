var cnt = 0;
function dfs(arr, depth, target, result){
    if(depth===arr.length)
    {
        if(target ===result){
            cnt++;
        }
            return;
    }
    var plus = result + arr[depth];
    var minus = result - arr[depth];
    dfs(arr, depth+1, target, plus);
    dfs(arr, depth+1, target, minus);
}
function solution(numbers, target) {
    var answer = 0;

    dfs(numbers, 0, target, 0);
    return cnt;
}
