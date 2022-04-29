function solution(numbers) {
    var answer = 0;
    var checkNumber = Array.from({length:10},()=>0);
    for(n of numbers){
        checkNumber[n] ++;
    }
    checkNumber.forEach((v,i)=>{
        if(v===0)
            answer+=i
        }
    );
    return answer;
}
//console.log(solution([1,2,3,4,6,7,8,0]));
