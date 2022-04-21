function check(s,num){
    for(var i in num){
        if(s===num[i]){
            return i;
        }
    }
    return 0;
}

function solution(s) {
    var answer = '';
    var num = ['zero','one','two','three','four','five','six','seven','eight','nine'];
    var line ='';
    for(var i of s){
        //console.log(i);

        if(isNaN(i)){
            line = line.concat(i);
            if(!check(line,num)){
                continue;
            }
            else{
                answer = answer.concat(check(line,num));
                line = '';
                
            }
                }
        else{
            answer = answer.concat(i);
        }
    }
    
    
    return parseInt(answer);
}