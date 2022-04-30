function solution(numbers, target) {
    var answer = 0;
    
    dfs(0, 0);
    function dfs(depth, result){
    if(depth===numbers.length)
    {
        if(target ===result){
            answer++;
        }
        return;
    }
    dfs(depth+1, result + numbers[depth]);
    dfs(depth+1, result - numbers[depth]);
}
    return answer;
}